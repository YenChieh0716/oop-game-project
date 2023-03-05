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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
	
}

void CGameStateInit::OnInit()
{
	//
	// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
	//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
	//
	ShowInitProgress(0, "Start Initialize...");	// �@�}�l��loading�i�׬�0%
	Sleep(200);

	load_background();

	ShowInitProgress(66, "Initialize...");
	Sleep(200);
	//
	// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
	//
}

void CGameStateInit::OnBeginState()
{
	
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
}

void CGameStateInit::OnShow()
{
	background_stars.ShowBitmap();
	background.ShowBitmap();
	onSleepMove(sleep_1,450,220);
	onSleepMove(sleep_2,400,220);
	onSleepMove(sleep_3,350,220);
	onCloudsMove();
	background_title.ShowBitmap();
	background_musicButton_play.ShowBitmap(0.7);
	fence_right_bottom.ShowBitmap();
	startButton_play.ShowBitmap();
	fence_left_bottom.ShowBitmap();
	Mailbox.ShowBitmap();
	Mailbox_logo.ShowBitmap();
	Mailbox_flag.ShowBitmap();
	draw_text();
	
}

void CGameStateInit::load_background() {
	background.LoadBitmapByString({ "resources/mainMenu/background.bmp" }, RGB(255, 255, 255));
	background_stars.LoadBitmap("resources/mainMenu/backgroundStars.bmp");
	background_title.LoadBitmapByString({ "resources/mainMenu/title.bmp" }, RGB(255, 255, 255));
	background_musicButton_play.LoadBitmapByString({ "resources/mainMenu/music_button_1.bmp" }, RGB(255, 255, 255));
	background_musicButton_unplay.LoadBitmapByString({ "resources/mainMenu/music_button_5.bmp" }, RGB(255, 255, 255));
	startButton_play.LoadBitmapByString({ "resources/mainMenu/start_1.bmp" }, RGB(255, 255, 255));
	startButton_unplay.LoadBitmapByString({ "resources/mainMenu/start_2.bmp" }, RGB(255, 255, 255));
	fence_right_bottom.LoadBitmap("resources/mainMenu/fence_2.bmp", RGB(255, 255, 255));
	fence_left_bottom.LoadBitmap("resources/mainMenu/fence.bmp", RGB(255, 255, 255));
	Mailbox.LoadBitmap("resources/mainMenu/mailbox.bmp", RGB(255, 255, 255));
	Mailbox_logo.LoadBitmap("resources/mainMenu/mailbox_logo.bmp", RGB(255, 255, 255));
	Mailbox_flag.LoadBitmap("resources/mainMenu/flag.bmp", RGB(255, 255, 255));
	cloud.LoadBitmap("resources/mainMenu/clouds_1.bmp", RGB(255, 255, 255));
	cloud_1.LoadBitmap("resources/mainMenu/clouds_2.bmp", RGB(255, 255, 255));
	sleep_1.LoadBitmap("resources/mainMenu/sleep_1.bmp", RGB(255, 255, 255));
	sleep_2.LoadBitmap("resources/mainMenu/sleep_2.bmp", RGB(255, 255, 255));
	sleep_3.LoadBitmap("resources/mainMenu/sleep_3.bmp", RGB(255, 255, 255));

	background.SetTopLeft(0, 200);
	background_stars.SetTopLeft(0, -600);
	background_title.SetTopLeft(20, 20);
	background_musicButton_play.SetTopLeft(680, 10);
	startButton_play.SetTopLeft(640, 460);
	fence_right_bottom.SetTopLeft(545, 485);
	fence_left_bottom.SetTopLeft(-40,515);
	Mailbox.SetTopLeft(50, 455);
	Mailbox_logo.SetTopLeft(100, 490);
	Mailbox_flag.SetTopLeft(88, 446);
	cloud.SetTopLeft(700, 10);
	cloud_1.SetTopLeft(1000, 130);
	sleep_1.SetTopLeft(450,195);
	sleep_2.SetTopLeft(400,185);
	sleep_3.SetTopLeft(350,210);
}

void CGameStateInit::draw_text() {
	/*
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	// Print title
	CTextDraw::ChangeFontLog(pDC, fp, 36, "�L�n������", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	// Print info
	CTextDraw::ChangeFontLog(pDC, fp, 24, "�L�n������", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC(); 
	*/
}
void CGameStateInit::onCloudsMove() {
	const int STEP_SIZE = 3;
	int x = cloud.Left();
	int x1 = cloud_1.Left();
	int y = cloud.Top();
	int y1 = cloud_1.Top();
	if (isMoving) {
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
	}
	cloud.ShowBitmap();
	cloud_1.ShowBitmap();
}
void  CGameStateInit::onSleepMove(CMovingBitmap &sleep,int ori_x,int ori_y) {
	int x = sleep.Left();
	int y = sleep.Top();
	y += ((-1)*((x/100)));
	//x -= ((-1)*((x / 100)));
	//x = x - (((-1)*((x / 100) ^ 2))+2);
	x += 3;
	//y -= 2;
	if (y <= -100) {
		sleep.SetTopLeft(ori_x, ori_y);
		x = ori_x;
		y = ori_y;
	}
	else {
		sleep.SetTopLeft(x, y);
	}
	sleep.ShowBitmap(0.7);
}