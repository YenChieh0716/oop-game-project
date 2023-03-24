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
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g) : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	
	ShowInitProgress(0, "Start Initialize...");	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	load_background();

	ShowInitProgress(66, "Initialize...");
	Sleep(200);									// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{

}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (point.x > 640 + 25 && point.x <= 640 + startButton_play.GetWidth() - 25) {
		if (point.y > 460 + 15 && point.y <= 460 + startButton_play.GetHeight() - 20) {
			GotoGameState(GAME_STATE_RUN);
			CAudio::Instance()->Stop(AUDIO_START_BGM);
		}
	}
	if (point.x > 680 + 25 && point.x <= 680 + background_musicButton_play_1.GetWidth() - 25) {
		if (point.y > 10 + 15 && point.y <= 10 + startButton_play.GetHeight() - 20) {
			//GotoGameState(GAME_STATE_RUN);
			CAudio::Instance()->Play(AUDIO_BUTTON);//有延遲
			CAudio::Instance()->Stop(AUDIO_START_BGM);
		}
	}
	//GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	background_stars.ShowBitmap();
	background.ShowBitmap();
	onSleepMove(sleep_1, 450, 220);
	onSleepMove(sleep_2, 400, 220);
	onSleepMove(sleep_3, 350, 220);
	onCloudsMove();
	background_title.ShowBitmap();
	background_musicButton_play_2.ShowBitmap(0.7);
	background_musicButton_play_1.ShowBitmap(0.7);
	fence_right_bottom.ShowBitmap();
	startButton_play_1.ShowBitmap();
	startButton_play.ShowBitmap();
	fence_left_bottom.ShowBitmap();
	Mailbox.ShowBitmap();
	Mailbox_logo.ShowBitmap();
	Mailbox_flag.ShowBitmap();
	//draw_text();
}
void CGameStateInit::load_background() {
	CAudio::Instance()->Load(AUDIO_START_BGM, "resources/music/music_ingame01.mp3");
	CAudio::Instance()->Load(AUDIO_BUTTON, "resources/music/btn_click.mp3");
	//Load進音樂後馬上播放
	CAudio::Instance()->Play(AUDIO_START_BGM);
	//background.LoadBitmapByString({ "resources/mainMenu/background.bmp" }, RGB(255, 255, 255));
	background.LoadBitmapByString({ "resources/mainMenu/background.bmp" }, RGB(0, 0, 0));
	background_stars.LoadBitmap("resources/mainMenu/backgroundStars.bmp");
	//background_title.LoadBitmapByString({ "resources/mainMenu/title.bmp" }, RGB(255, 255, 255));
	background_title.LoadBitmapByString({ "resources/mainMenu/title.bmp" }, RGB(1, 1, 1));
	background_musicButton_play_1.LoadBitmapByString({ "resources/mainMenu/music_button_1.bmp" }, RGB(1, 1, 1));
	background_musicButton_play_2.LoadBitmapByString({ "resources/mainMenu/music_2.bmp" }, RGB(1, 1, 1));
	background_musicButton_unplay.LoadBitmapByString({ "resources/mainMenu/music_button_5.bmp" }, RGB(255, 255, 255));
	startButton_play.LoadBitmapByString({ "resources/mainMenu/start_1.bmp" }, RGB(1, 1, 1));
	startButton_play_1.LoadBitmapByString({ "resources/mainMenu/start_2.bmp" }, RGB(1, 1, 1));
	fence_right_bottom.LoadBitmap("resources/mainMenu/fence_2.bmp", RGB(1, 1, 1));
	fence_left_bottom.LoadBitmap("resources/mainMenu/fence.bmp", RGB(1, 1, 1));
	Mailbox.LoadBitmap("resources/mainMenu/mailbox.bmp", RGB(1, 1, 1));
	Mailbox_logo.LoadBitmap("resources/mainMenu/mailbox_logo.bmp", RGB(1, 1, 1));
	Mailbox_flag.LoadBitmap("resources/mainMenu/flag.bmp", RGB(1, 1, 1));
	//cloud.LoadBitmap("resources/mainMenu/clouds_1.bmp", RGB(255, 255, 255));
	//cloud_1.LoadBitmap("resources/mainMenu/clouds_2.bmp", RGB(255, 255, 255));
	cloud.LoadBitmap("resources/mainMenu/clouds_1.bmp", RGB(1, 1, 1)); //1,1,1
	cloud_1.LoadBitmap("resources/mainMenu/clouds_2.bmp", RGB(0, 0, 0));
	sleep_1.LoadBitmap("resources/mainMenu/sleep_1.bmp", RGB(255, 255, 255));
	sleep_2.LoadBitmap("resources/mainMenu/sleep_2.bmp", RGB(255, 255, 255));
	sleep_3.LoadBitmap("resources/mainMenu/sleep_3.bmp", RGB(255, 255, 255));

	//CAudio::Instance()->Load(AUDIO_START_BGM, "resources/music/music_ingame01.mp3");
	background.SetTopLeft(0, 200);
	background_stars.SetTopLeft(0, -600);
	background_title.SetTopLeft(20, 20);
	background_musicButton_play_1.SetTopLeft(680, 10);
	background_musicButton_play_2.SetTopLeft(697, 23);
	startButton_play.SetTopLeft(640, 460);
	startButton_play_1.SetTopLeft(646, 460);
	fence_right_bottom.SetTopLeft(545, 485);
	fence_left_bottom.SetTopLeft(-40, 515);
	Mailbox.SetTopLeft(50, 455);
	Mailbox_logo.SetTopLeft(100, 490);
	Mailbox_flag.SetTopLeft(88, 446);
	cloud.SetTopLeft(700, 10);
	cloud_1.SetTopLeft(1000, 130);
	sleep_1.SetTopLeft(450, 195);
	sleep_2.SetTopLeft(400, 185);
	sleep_3.SetTopLeft(350, 210);
}

void CGameStateInit::draw_text() {
	/*
	CDC *pDC = CDDraw::GetBackCDC();
	CFont* fp;

	// Print title
	CTextDraw::ChangeFontLog(pDC, fp, 36, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 79, 228, "Game Framework Practice");

	// Print info
	CTextDraw::ChangeFontLog(pDC, fp, 24, "微軟正黑體", RGB(255, 255, 255));
	CTextDraw::Print(pDC, 182, 431, "Press any key to start");

	CDDraw::ReleaseBackCDC();
	*/
}

void CGameStateInit::onCloudsMove() {
	const int STEP_SIZE = 3;
	int x = cloud.GetLeft();
	int x1 = cloud_1.GetLeft();
	int y = cloud.GetTop();
	int y1 = cloud_1.GetTop();
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

void  CGameStateInit::onSleepMove(CMovingBitmap &sleep, int ori_x, int ori_y) {
	int x = sleep.GetLeft();
	int y = sleep.GetTop();
	y += ((-1)*((x / 100)));
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