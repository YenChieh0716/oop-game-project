#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
}
void CGameStateRun::onCharacterMove() {
		const int STEP_SIZE = 5;
		int x = character.Left();
		int y = character.Top();
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		if (isMovingUp)
			y -= STEP_SIZE;
		if (isMovingDown)
			y += STEP_SIZE;
		character.SetTopLeft(x, y);
}
void CGameStateRun::OnMove()							// ���ʹC������
{
	onCharacterMove();
	//�ˬd���|character,chest_and_key
	int characterX1 = character.Left() - 5;
	int characterY1 = character.Top() - 5;
	int characterX2 = characterX1 + character.Width() - 5;
	int characterY2 = characterY1 + character.Height() - 5;
	int chest_and_keyX1 = chest_and_key.Left() - 5;
	int chest_and_keyY1 = chest_and_key.Top() - 5;
	int chest_and_keyX2 = chest_and_keyX1 + chest_and_key.Width() - 5;
	int chest_and_keyY2 = chest_and_keyY1 + chest_and_key.Height() - 5;
	//up, down, left, right
	if ((characterY2 >= chest_and_keyY1) && (chest_and_keyY2 >= characterY1) && (characterX2 >= chest_and_keyX1) && (characterX1 <= chest_and_keyX2)) {
		chest_and_key.SelectShowBitmap(1);
		chest_and_key.ShowBitmap();
	}
	//�ˬd���|character,door�A��ӵo�{�e�����B�J�����
	if (phase == 5) {
		int first_doorX1 = door[0].Left() - 5;
		int first_doorY1 = door[0].Top() - 5;
		int first_doorX2 = first_doorX1 + door[0].Width() - 5;
		int first_doorY2 = first_doorY1 + door[0].Height() - 5;

		int second_doorX1 = door[1].Left() - 5;
		int second_doorY1 = door[1].Top() - 5;
		int second_doorX2 = second_doorX1 + door[1].Width() - 5;
		int second_doorY2 = second_doorY1 + door[1].Height() - 5;

		int third_doorX1 = door[2].Left() - 5;
		int third_doorY1 = door[2].Top() - 5;
		int third_doorX2 = third_doorX1 + door[2].Width() - 5;
		int third_doorY2 = third_doorY1 + door[2].Height() - 5;
		//up, down, left, right(door 0~2)
		if ((characterY2 >= first_doorY1) && (first_doorY2 >= characterY1) && (characterX2 >= first_doorX1) && (characterX1 <= first_doorX2)) {
			door[0].SelectShowBitmap(1);
			door[0].ShowBitmap();
		}
		if ((characterY2 >= second_doorY1) && (second_doorY2 >= characterY1) && (characterX2 >= second_doorX1) && (characterX1 <= second_doorX2)) {
			door[1].SelectShowBitmap(1);
			door[1].ShowBitmap();
		}

		if ((characterY2 >= third_doorY1) && (third_doorY2 >= characterY1) && (characterX2 >= third_doorX1) && (characterX1 <= third_doorX2)) {
			door[2].SelectShowBitmap(1);
			door[2].ShowBitmap();
		}
	}
	
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	background.LoadBitmapByString({ 
		"resources/phase11_background.bmp", 
		"resources/phase12_background.bmp", 
		"resources/phase21_background.bmp", 
		"resources/phase22_background.bmp", 
		"resources/phase31_background.bmp", 
		"resources/phase32_background.bmp",
		"resources/phase41_background.bmp",
		"resources/phase42_background.bmp",
		"resources/phase51_background.bmp",
		"resources/phase52_background.bmp",
		"resources/phase61_background.bmp",
		"resources/phase62_background.bmp",
	});
	background.SetTopLeft(0, 0);

	character.LoadBitmapByString({ "resources/giraffe.bmp" }, RGB(255, 255, 255));
	character.SetTopLeft(150, 265);

	chest_and_key.LoadBitmapByString({ "resources/chest.bmp", "resources/chest_ignore.bmp" }, RGB(255, 255, 255));
	chest_and_key.SetTopLeft(150, 430);

	bee.LoadBitmapByString({ "resources/bee_1.bmp", "resources/bee_2.bmp" });
	bee.SetTopLeft(462, 265);
	bee.SetAnimation(2, false);
	ball.LoadBitmapByString({ "resources/ball-3.bmp", "resources/ball-2.bmp", "resources/ball-1.bmp", "resources/ball-ok.bmp" });
	ball.SetTopLeft(150, 430);
	ball.SetAnimation(1000, true);
	ball.ToggleAnimation();

	for (int i = 0; i < 3; i++) {
		door[i].LoadBitmapByString({ "resources/door_close.bmp", "resources/door_open.bmp" }, RGB(255, 255, 255));
		door[i].SetTopLeft(462 - 100 * i, 265);
		door[i].SelectShowBitmap(0);
	}
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	int left = character.Left();
	int top = character.Top();
	//phase = 5;
	if (nChar == VK_RETURN) {
		if (phase == 1) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_1();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		} else if (phase == 2) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_2();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 3) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_3();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 4) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_4();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 5) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_5();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}else if (phase == 6) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_6();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
				GotoGameState(GAME_STATE_OVER);
			}
		}
	}else if (nChar == VK_UP) {
		//character.isMovingUp = true;
		isMovingUp = true;
	}else if (nChar == VK_DOWN) {
		//character.isMovingDown = true;
		isMovingDown = true;
	}else if (nChar == VK_LEFT) {
		isMovingLeft = true;
		//character.isMovingLeft = true;
	}else if (nChar == VK_RIGHT) {
		isMovingRight = true;
		//character.isMovingRight = true;
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_UP) {
		isMovingUp = false;
		//character.isMovingUp = false;
	}
	else if (nChar == VK_DOWN) {
		isMovingDown = false;
		//character.isMovingDown = false;
	}
	else if (nChar == VK_LEFT) {
		isMovingLeft = false;
		//character.isMovingLeft = false;
	}
	else if (nChar == VK_RIGHT) {
		isMovingRight = false;
		//character.isMovingRight = false;
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
	show_image_by_phase();
	show_text_by_phase();
}

void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		background.ShowBitmap();
		character.ShowBitmap();
		if (phase == 3 && sub_phase == 1) {
			chest_and_key.ShowBitmap();
		}
		if (phase == 4 && sub_phase == 1) {
			bee.ShowBitmap();
		}
		if (phase == 5 && sub_phase == 1) {
			for (int i = 0; i < 3; i++) {
				door[i].ShowBitmap();
			}
		}
		if (phase == 6 && sub_phase == 1) {
			ball.ShowBitmap();
		}
	}
}

void CGameStateRun::show_text_by_phase() {
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	CTextDraw::ChangeFontLog(pDC, fp, 21, "�L�n������", RGB(0, 0, 0), 800);

	if (phase == 1 && sub_phase == 1) {
		CTextDraw::Print(pDC, 237, 128, "�ק�A���D���I");
		CTextDraw::Print(pDC, 55, 163, "�N�Ǧ��洫�� resources ���� giraffe.bmp �ϼˡI");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (phase == 2 && sub_phase == 1) {
		CTextDraw::Print(pDC, 26, 128, "�U�@�Ӷ��q�A�����V������z�L�W�U���k���ʨ�o�Ӧ�m�I");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (phase == 3 && sub_phase == 1) {
		CTextDraw::Print(pDC, 205, 128, "���A�ǳƤF�@���_�c");
		CTextDraw::Print(pDC, 68, 162, "�]�p�{�������V���N���_�c��A�N�_�c�����I");
		CTextDraw::Print(pDC, 68, 196, "�O�o�_�c�n�h�I�A�ϥ� RGB(255, 255, 255)");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (phase == 4 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "���A�ǳƤF�@�ӻe���n�B��");
		CTextDraw::Print(pDC, 89, 162, "�w�g�������F��V���ʵe�A�����i�H�W�U����");
		CTextDraw::Print(pDC, 110, 196, "�g�ӵ{�������A���e���n�B�;֦��ʵe�I");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (phase == 5 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "���A�ǳƤF�T����");
		CTextDraw::Print(pDC, 89, 162, "�]�p�{�������V���N�������A���|���}");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (phase == 6 && sub_phase == 1) {
		CTextDraw::Print(pDC, 173, 128, "���A�ǳƤF�@���|�˼ƪ��y");
		CTextDraw::Print(pDC, 89, 162, "�]�p�{�����y�˼ơA�M����� OK �ᰱ��ʵe");
		CTextDraw::Print(pDC, 373, 537, "���U Enter �������");
	} else if (sub_phase == 2) {
		CTextDraw::Print(pDC, 268, 128, "�����I");
	}

	CDDraw::ReleaseBackCDC();
}

bool CGameStateRun::validate_phase_1() {
	return character.GetImageFilename() == "resources/giraffe.bmp";
}

bool CGameStateRun::validate_phase_2() {
	return character.Top() > 204 && character.Top() < 325 && character.Left() > 339 && character.Left() < 459;
}

bool CGameStateRun::validate_phase_3() {
	return (
		character.Top() + character.Height() >= chest_and_key.Top()
		&& character.Left() + character.Width() >= chest_and_key.Left()
		&& chest_and_key.GetSelectShowBitmap() == 1
		&& chest_and_key.GetFilterColor() == RGB(255, 255, 255)
	);
}

bool CGameStateRun::validate_phase_4() {
	return bee.IsAnimation() && bee.GetMovingBitmapFrame() == 2;
}

bool CGameStateRun::validate_phase_5() {
	bool check_all_door_is_open = true;
	for (int i = 0; i < 3; i++) {
		check_all_door_is_open &= (door[i].GetSelectShowBitmap() == 1);
	}
	return check_all_door_is_open;
}

bool CGameStateRun::validate_phase_6() {
	return ball.IsAnimationDone() && !ball.IsAnimation();
}