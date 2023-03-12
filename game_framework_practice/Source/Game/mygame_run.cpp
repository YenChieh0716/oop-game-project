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
		
		//bool dir;����Ȭ۴�
		if (x <= 70) {
			isMovingLeft = false;
			isMovingRight = true;
		}
		else if(x>=680) {
			isMovingLeft = true;
			isMovingRight = false;
		}
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingLeft = false;
				isMovingRight = true;
			}
			if (x <= 70) {
				isMovingLeft = false;
				isMovingRight = true;
			}
			else if (x >= 680) {
				isMovingLeft = true;
				isMovingRight = false;
			}
		}
		if (dir2) {
			if (!dir2_f) {
				dir2_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
			if (y <= 100) {
				isMovingUp = false;
				isMovingDown = true;
			}
			else if (y >= 465) {
				isMovingUp = true;
				isMovingDown = false;
			}
		}
		
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
void  CGameStateRun::onCloudsMove() {
	const int STEP_SIZE = 3;
	int x = cloud.Left();
	int x1 = cloud_1.Left();
	int y = cloud.Top();
	int y1 = cloud_1.Top();
		x -= STEP_SIZE;
		x1 -= STEP_SIZE;
		if (x <= -300) {
			cloud.SetTopLeft(830, y);
		}
		else {
			cloud.SetTopLeft(x, y);
		}
		if (x1 <= -300) {
			cloud_1.SetTopLeft(830, y1);
		}
		else {
			cloud_1.SetTopLeft(x1, y1);
		}
	cloud.ShowBitmap();
	cloud_1.ShowBitmap();
}

bool CGameStateRun::bitmapOverlap(CMovingBitmap a, CMovingBitmap b,int offsetX,int offsetY) {
	int X1 = a.Left() - offsetX;
	int Y1 = a.Top() + offsetY;
	int X2 = X1 + a.Width() - offsetX;
	int Y2 = Y1 + a.Height() + offsetY;
	int X1_b = b.Left();
	int Y1_b = b.Top() - 5;
	int X2_b = X1_b + b.Width();
	int Y2_b = Y1_b + b.Height() - 5;
	if ((Y2 >= Y1_b) && (Y2_b >= Y1) && (X2 >= X1_b) && (X1 <= X2_b)) {	
		return true;
	}
	else {
		return false;
	}
}

void CGameStateRun::OnMove()							// ���ʹC������
{
	if (!dir1) {
		dir1 = bitmapOverlap(character, direction_1, 55,80);
	}
	if (!dir2) {
		dir2 = bitmapOverlap(character, direction_2, 55,80);
	}
	if (!pass) {
		pass = bitmapOverlap(character, exit, 30,70); // ��F�X�f
		if (pass)
			isCharacterMove = false;
	}
	if (!clock1)
		clock1 = bitmapOverlap(character, clock, 55, 80);
	if (!clock2)
		clock2 = bitmapOverlap(character, clock_1, 55, 80);
	if (!clock3)
		clock3 = bitmapOverlap(character, clock_2, 55, 80);
	if (isCharacterMove)
		onCharacterMove();
	/*
	if (dir1) {
		isMovingRight = true;
		isMovingDown = false;
		isMovingUp = false;
		isMovingLeft = false;
	}
	if (dir2) {
		isMovingRight = false;
		isMovingDown = false;
		isMovingUp = true;
		isMovingLeft = false;
	}*/
		
	//�ˬd���|character,chest_and_key
	/*
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
	*/
	
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
	/*background.LoadBitmapByString({ 
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
	});*/
	background_stars.LoadBitmap("resources/runState/backgroundStars.bmp");
	background_stars.SetTopLeft(0, -605);
	background.LoadBitmapByString({ "resources/runState/bg2_1.bmp" }, RGB(1, 1, 1));
	background.SetTopLeft(0, 100);
	//background_filter.LoadBitmap("resources/runState/bg2_2.bmp", RGB(254, 254, 254));
	//background_filter.SetTopLeft(100, 100);
	//bg4.LoadBitmapByString({ "resources/runState/bg4.bmp" }, RGB(1, 1, 1));
	//bg4.SetTopLeft(0, 100);

	character.LoadBitmapByString({ "resources/runState/flower_1.bmp", "resources/runState/flower_2.bmp", "resources/runState/flower_3.bmp" }, RGB(1, 1, 1));
	//character.LoadBitmapByString({  "resources/runState/flower_1.bmp" }, RGB(1, 1, 1));
	character.SetTopLeft(185, 403);
	//character.SetAnimation(300, false);
	
	cloud.LoadBitmap("resources/runState/clouds_1.bmp", RGB(1, 1, 1)); //1,1,1
	cloud_1.LoadBitmap("resources/runState/clouds_2.bmp", RGB(0, 0, 0));
	cloud.SetTopLeft(700, 20);
	cloud_1.SetTopLeft(1000, 130);

	clock.LoadBitmap("resources/runState/clock.bmp", RGB(1, 1, 1)); //1,1,1
	clock_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock.SetTopLeft(380, 305);
	clock_shelf.SetTopLeft(375, 350);

	clock_1.LoadBitmap("resources/runState/clock.bmp", RGB(1, 1, 1)); //1,1,1
	clock_1_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock_1.SetTopLeft(500, 193);
	clock_1_shelf.SetTopLeft(495, 238);

	clock_2.LoadBitmap("resources/runState/clock.bmp", RGB(1, 1, 1)); //1,1,1
	clock_2_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock_2.SetTopLeft(620, 193);
	clock_2_shelf.SetTopLeft(615, 238);

	stage.LoadBitmap("resources/runState/stage.bmp", RGB(1, 1, 1));
	stage_num.LoadBitmap("resources/runState/stage_num.bmp", RGB(1, 1, 1));
	stage.SetTopLeft(310, 20);
	stage_num.SetTopLeft(490, 20);

	level.LoadBitmap("resources/runState/Levels.bmp", RGB(1, 1, 1));
	level_1.LoadBitmap("resources/runState/Levels_2.bmp", RGB(1, 1, 1));
	level.SetTopLeft(10, 10);
	level_1.SetTopLeft(10, 12);

	start.LoadBitmap("resources/runState/start_1.bmp", RGB(1, 1, 1));
	start_1.LoadBitmap("resources/runState/start_2.bmp", RGB(1, 1, 1));
	start.SetTopLeft(697, 12);
	start_1.SetTopLeft(702, 12);
	restart_1.LoadBitmap("resources/runState/restart_1.bmp", RGB(1, 1, 1));
	restart_2.LoadBitmap("resources/runState/restart_2.bmp", RGB(1, 1, 1));
	restart_1.SetTopLeft(697, 12);
	restart_2.SetTopLeft(700, 19);

	direction_1.LoadBitmap("resources/runState/direction_1_1.bmp", RGB(1, 1, 1));
	direction_2.LoadBitmap("resources/runState/direction_2.bmp", RGB(1, 1, 1));
	direction_1.SetTopLeft(180, 173);
	direction_2.SetTopLeft(358, 415);

	exit.LoadBitmap("resources/runState/door_1.bmp", RGB(0, 0, 0));
	exit.SetTopLeft(713,193);

	clock_get.LoadBitmap("resources/runState/clock_1.bmp", RGB(1, 1, 1));
	clock_1_get.LoadBitmap("resources/runState/clock_1.bmp", RGB(1, 1, 1));
	clock_2_get.LoadBitmap("resources/runState/clock_1.bmp", RGB(1, 1, 1));
	clock_get.SetTopLeft(310, 20);
	clock_1_get.SetTopLeft(370, 20);
	clock_2_get.SetTopLeft(430, 20);

	chest_and_key.LoadBitmapByString({ "resources/chest.bmp", "resources/chest_ignore.bmp" }, RGB(255, 255, 255));
	chest_and_key.SetTopLeft(150, 430);

	bee.LoadBitmapByString({ "resources/bee_1.bmp", "resources/bee_2.bmp" });
	bee.SetTopLeft(462, 265);
	bee.SetAnimation(2, false);
	ball.LoadBitmapByString({ "resources/ball-3.bmp", "resources/ball-2.bmp", "resources/ball-1.bmp", "resources/ball-ok.bmp" });
	ball.SetTopLeft(150, 430);
	ball.SetAnimation(1000, true);
	ball.ToggleAnimation();
	
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
	}
	//������L���ʵ���
	/*else if (nChar == VK_UP) {
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
	}*/
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*if (nChar == VK_UP) {
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
	}*/
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
	if (point.x > 697 + 25 && point.x <= 697 + start.Width() - 25) {
		if (point.y > 12 + 15 && point.y <= 12 + start.Height() - 20) {
			if (!isStart) {
				isCharacterMove = true;
				isStart = true;
			}
			else if (isStart) { //�b�������s�}�l(bool �^���l��)
				isRestart = true;
				isCharacterMove = false;
				isStart = false;
				character.SetTopLeft(185,403);
				dir1 = false;
				dir2 = false;
				isMovingLeft = false;
				isMovingRight = true;
				isMovingUp = false;
				isMovingDown = false;
				isDirectionMove = false;
				//bool isRestart = false;
				dir1_f = false; //�Ω�]�w��l��V
				dir2_f = false;
				clock1 = false;
				clock2 = false;
				clock3 = false;
			}
		}
	}
	//�]�w�I��dir1�N�i��dir1��۷ƹ���m����
	if(!isStart){
		if (point.x > direction_1.Left() + 25 && point.x <= direction_1.Left() + direction_1.Width() - 25) {
			if (point.y > direction_1.Top() + 15 && point.y <= direction_1.Top() + direction_1.Height() - 20) {
				isDirectionMove = true;
			}
		}
		if (isDirectionMove) {
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		}
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	if (isDirectionMove && !isStart) {
		isDirectionMove = false;
		direction_1.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
	if (isDirectionMove) {
		direction_1.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
	if (!pass) {
		if (!isStart) { //���ҩέ�}�l
			if (isRestart) {
				isRestart = false;
				clock.SetTopLeft(380, 305);
				clock_1.SetTopLeft(500, 193);
				clock_2.SetTopLeft(620, 193);
			}
			background_stars.ShowBitmap();
			onCloudsMove();
			stage.ShowBitmap();
			stage_num.ShowBitmap();
			show_image_by_phase();
			level_1.ShowBitmap(0.7);
			level.ShowBitmap(0.7);
			start_1.ShowBitmap(0.7);
			start.ShowBitmap(0.7);
			//character.ShowBitmap(0.5);

			
			clock.ShowBitmap(0.3);
			clock_shelf.ShowBitmap();
			clock_1.ShowBitmap(0.3);
			clock_1_shelf.ShowBitmap();
			clock_2.ShowBitmap(0.3);
			clock_2_shelf.ShowBitmap();
			direction_1.ShowBitmap();
			direction_2.ShowBitmap();
			exit.ShowBitmap();
			character.ShowBitmap(0.7);
			character.SetAnimation(300, false);
			show_text_by_phase();
		}
		else if (isStart) {
			background_stars.ShowBitmap();
			onCloudsMove();
			show_image_by_phase();
			level_1.ShowBitmap(0.7);
			level.ShowBitmap(0.7);
			restart_2.ShowBitmap(0.7);
			restart_1.ShowBitmap(0.7);
			clock_get.ShowBitmap(0.7);
			clock_1_get.ShowBitmap(0.7);
			clock_2_get.ShowBitmap(0.7);
			//character.ShowBitmap(0.5);
			if (clock1) {
				clock.SetTopLeft(320, 20);
			}
			else {
				clock_shelf.ShowBitmap();
			}
			if (clock2) {
				clock_1.SetTopLeft(380, 20);
			}
			else {
				clock_1_shelf.ShowBitmap();
			}
			if (clock3) {
				clock_2.SetTopLeft(440, 20);
			}
			else {
				clock_2_shelf.ShowBitmap();
			}
			clock.ShowBitmap(0.3);
			clock_1.ShowBitmap(0.3);
			clock_2.ShowBitmap(0.3);

			direction_1.ShowBitmap();
			direction_2.ShowBitmap();
			exit.ShowBitmap();
			character.ShowBitmap(0.7);
			character.SetAnimation(300, false);
			show_text_by_phase();
		}
	}
	//��ܹL���e��(������)
	if (pass) { 

	}
	
}

void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		background.ShowBitmap();
		//background_filter.ShowBitmap();
		//bg4.ShowBitmap(1.2);
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
	/*CDC *pDC = CDDraw::GetBackCDC();
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

	CDDraw::ReleaseBackCDC();*/
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