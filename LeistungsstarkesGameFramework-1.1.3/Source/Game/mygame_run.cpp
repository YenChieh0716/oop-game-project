#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include <string>

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}

void CGameStateRun::OnBeginState()
{
	//CAudio::Instance()->Play(AUDIO_START_BGM);
	//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
	fill(getClock_arr,getClock_arr + 30, 0);
}

void CGameStateRun::onCharacterMove() {
	const int STEP_SIZE = 5;
	int x, y;
	if (phase == 1) {
		x = character.GetLeft();
		y = character.GetTop();
	}
	else if (phase == 2) {
		x = character2.GetLeft();
		y = character2.GetTop();
	}
	else if (phase == 3) {
		x = character3.GetLeft();
		y = character3.GetTop();
	}

	//bool dir;絕對值相減
	if (x <= 70) {
		isMovingLeft = false;
		isMovingRight = true;
	}
	else if (x >= 680) {
		isMovingLeft = true;
		isMovingRight = false;
	}
	if (phase == 1) {
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
	}
	if (phase == 2) {
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
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
		if (dir2) {
			if (!dir2_f) {
				dir2_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = true;
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
		if (dir3) {
			if (!dir3_f) {
				dir3_f = true;
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
	}
	if (phase == 3) {
		if (dir2) {
			if (!dir2_f) {
				dir2_f = true;
				isMovingUp = false;
				isMovingDown = true;
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
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = true;
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
	}
	if (isMovingLeft)
		x -= STEP_SIZE;
	if (isMovingRight)
		x += STEP_SIZE;
	if (isMovingUp)
		y -= STEP_SIZE;
	if (isMovingDown)
		y += STEP_SIZE;
	if(phase == 1)
		character.SetTopLeft(x, y);
	else if(phase == 2)
		character2.SetTopLeft(x, y);
	else if (phase == 3)
		character3.SetTopLeft(x, y);
}

void  CGameStateRun::onCloudsMove() {
	const int STEP_SIZE = 3;
	int x = cloud.GetLeft();
	int x1 = cloud_1.GetLeft();
	int y = cloud.GetTop();
	int y1 = cloud_1.GetTop();
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

bool CGameStateRun::bitmapOverlap(CMovingBitmap a, CMovingBitmap b, int offsetX, int offsetY) {
	int X1 = a.GetLeft() - offsetX;
	int Y1 = a.GetTop() + offsetY;
	int X2 = X1 + a.GetWidth() - offsetX;
	int Y2 = Y1 + a.GetHeight() + offsetY;
	int X1_b = b.GetLeft();
	int Y1_b = b.GetTop() - 5;
	int X2_b = X1_b + b.GetWidth();
	int Y2_b = Y1_b + b.GetHeight() - 5;
	if ((Y2 >= Y1_b) && (Y2_b >= Y1) && (X2 >= X1_b) && (X1 <= X2_b)) {
		return true;
	}
	else {
		return false;
	}
}
void CGameStateRun::OnMove()							// 移動遊戲元素
{
	//第一關碰撞物體判斷
	if (phase == 1 && !pass) {
		int getClock = 0;
		if (!dir1) {
			dir1 = bitmapOverlap(character, direction_1, -50, 80);
			//dir1 = character.IsOverlap(character, direction_1);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character, direction_2, 55, 60);
		}
		if (!pass) {
			pass = bitmapOverlap(character, exit, 30, 0); // 抵達出口
			if (pass) {
				isCharacterMove = false;
				getClock_arr[0] = getClock;
				CAudio::Instance()->Pause();
				CAudio::Instance()->Play(AUDIO_PASS);
			}
		}
		if (!clock1) {
			clock1 = bitmapOverlap(character, clock, 35, 120);
			if(clock1)
				getClock++;
		}
			
		if (!clock2) {
			clock2 = bitmapOverlap(character, clock_1, 35, 120);
			if (clock2)
				getClock++;
		}
			
		if (!clock3) {
			clock3 = bitmapOverlap(character, clock_2, 35, 120);
			if (clock3)
				getClock++;
		}
		//getClock_arr[phase - 1] = getClock;
		if (isCharacterMove)
			onCharacterMove();
	}
	//第二關
	if (phase == 2 && !pass) {
		if (!dir1) {
			dir1 = bitmapOverlap(character2, direction_1, -85, 0);
			//dir1 = character2.IsOverlap(character2, direction_1);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character2, direction_2, 55, 60);
		}
		if (!dir3) {
			dir3 = bitmapOverlap(character2, direction_3, 65, 0);
		}
		if (!pass) {
			pass = bitmapOverlap(character2, exit, 0, 0); // 抵達出口
			if (pass) {
				isCharacterMove = false;
				CAudio::Instance()->Pause();
				CAudio::Instance()->Play(AUDIO_PASS); //切換到關卡開始畫面撥放另一音樂
			}
		}
		if (!clock1)
			clock1 = bitmapOverlap(character2, clock, -110, 80);
		if (!clock2)
			clock2 = bitmapOverlap(character2, clock_1, -110, 80);
		if (!clock3)
			clock3 = bitmapOverlap(character2, clock_2, -110, 80);
		if (isCharacterMove)
			onCharacterMove();
	}
	//第三關
	if (phase == 3 && !pass) {
		if (!dir1) {
			dir1 = bitmapOverlap(character3, direction_1, -85, 0);
			//dir1 = character2.IsOverlap(character2, direction_1);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character3, direction_2, 55, 60);
		}
		if (!pass) {
			pass = bitmapOverlap(character3, exit, 0, 0); // 抵達出口
			if (pass) {
				isCharacterMove = false;
				CAudio::Instance()->Pause();
				CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
			}
		}
		if (!clock1)
			clock1 = bitmapOverlap(character3, clock, -110, 80);
		if (!clock2)
			clock2 = bitmapOverlap(character3, clock_1, -110, 80);
		if (!clock3)
			clock3 = bitmapOverlap(character3, clock_2, -110, 80);
		if (isCharacterMove)
			onCharacterMove();
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	CAudio::Instance()->Load(AUDIO_RUNSTATE_BGM, "resources/music/music_ingame02.mp3");
	CAudio::Instance()->Load(AUDIO_PASS, "resources/music/win.mp3");
	
	background_stars.LoadBitmapByString({ "resources/runState/backgroundStars.bmp", "resources/runState/pass/bg1.bmp" });
	background_stars.SetTopLeft(0, -605);
	background.LoadBitmapByString({ "resources/runState/bg2_1.bmp", "resources/runState/pass/bg2.bmp" }, RGB(1, 1, 1));
	background.SetTopLeft(0, 100);
	//background_filter.LoadBitmap("resources/runState/bg2_2.bmp", RGB(254, 254, 254));
	//background_filter.SetTopLeft(100, 100);
	//bg4.LoadBitmapByString({ "resources/runState/bg4.bmp" }, RGB(1, 1, 1));
	//bg4.SetTopLeft(0, 100);

	character.LoadBitmapByString({ "resources/runState/flower_1.bmp", "resources/runState/flower_2.bmp", "resources/runState/flower_3.bmp" }, RGB(1, 1, 1));//花花
	character2.LoadBitmapByString({ "resources/runState/stage2/bubble.bmp", "resources/runState/stage2/bubble_1.bmp", "resources/runState/stage2/bubble_2.bmp" }, RGB(254, 254, 254));//泡泡
	character3.LoadBitmapByString({ "resources/runState/stage3/meow.bmp", "resources/runState/stage3/meow_1.bmp", "resources/runState/stage3/meow_2.bmp" }, RGB(254, 254, 254));//毛毛
	//character.LoadBitmapByString({  "resources/runState/flower_1.bmp" }, RGB(1, 1, 1));
	character.SetTopLeft(185, 403);
	character2.SetTopLeft(300, 300);
	//character3.SetTopLeft(185, 185);
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
	stage_num.LoadBitmapByString({ "resources/runState/stage_num.bmp", "resources/runState/stage2/stage_num.bmp", "resources/runState/stage3/stage_num.bmp" }, RGB(1, 1, 1));
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

	direction_1.LoadBitmapByString({ "resources/runState/direction_1_1.bmp", "resources/runState/stage2/dir1.bmp", "resources/runState/stage3/dir1.bmp" }, RGB(1, 1, 1));
	direction_2.LoadBitmapByString({ "resources/runState/direction_2.bmp", "resources/runState/stage2/dir2.bmp", "resources/runState/stage3/dir2.bmp" }, RGB(1, 1, 1));
	direction_3.LoadBitmapByString({ "resources/runState/stage2/dir3.bmp" }, RGB(1, 1, 1));
	direction_1.SetTopLeft(180, 173);
	direction_2.SetTopLeft(358, 415);

	exit.LoadBitmapByString({ "resources/runState/door_1.bmp", "resources/runState/stage2/door_1.bmp","resources/runState/stage3/exit.bmp" }, RGB(0, 0, 0));
	exit.SetTopLeft(713, 193);

	clock_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp" }, RGB(1, 1, 1));
	clock_1_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp" }, RGB(1, 1, 1));
	clock_2_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp" }, RGB(1, 1, 1));
	clock_get.SetTopLeft(310, 20);
	clock_1_get.SetTopLeft(370, 20);
	clock_2_get.SetTopLeft(430, 20);

	musicButton_play.LoadBitmapByString({ "resources/runState/pass/music_1.bmp", "resources/level_bg/music_button_1.bmp" }, RGB(1, 1, 1));
	musicButton_play_1.LoadBitmap("resources/runState/pass/music_2.bmp", RGB(1, 1, 1));
	musicButton_unplay.LoadBitmapByString({ "resources/mainMenu/music_button_5.bmp" }, RGB(255, 255, 255));
	bubble.LoadBitmapByString({ "resources/runState/pass/bubble.bmp" }, RGB(254, 254, 254));
	bubble.SetTopLeft(110, 170);
	bubble_fly.LoadBitmapByString({ "resources/runState/pass/bubble_flypath_1.bmp",
	"resources/runState/pass/bubble_flypath_2.bmp" ,"resources/runState/pass/bubble_flypath_3.bmp" }, RGB(254, 254, 254));
	bubble_fly.SetTopLeft(-130, 190);
	bubble_fly.SetAnimation(330, true);

	flower.LoadBitmap("resources/runState/pass/flower.bmp", RGB(254, 254, 254));
	flower.SetTopLeft(310, 130);
	flower_fly.LoadBitmapByString({ "resources/runState/pass/flower_flypath_1.bmp",
	"resources/runState/pass/flower_flypath_2.bmp" ,"resources/runState/pass/flower_flypath_3.bmp" }, RGB(1, 1, 1));
	flower_fly.SetTopLeft(255, 300);
	flower_fly.SetAnimation(330, true);

	meow.LoadBitmap("resources/runState/pass/meow.bmp", RGB(254, 254, 254));
	meow.SetTopLeft(480, 170);
	meow_fly.LoadBitmapByString({ "resources/runState/pass/meow_flypath_1.bmp",
	"resources/runState/pass/meow_flypath_2.bmp" ,"resources/runState/pass/meow_flypath_3.bmp" }, RGB(1, 1, 1));
	meow_fly.SetTopLeft(525, 250);
	meow_fly.SetAnimation(330, true);
	// 關卡
	for (int i = 0; i < 30; i++) {
		Levels[i].LoadBitmapByString({"resources/level_bg/level_lock.bmp", "resources/level_bg/level_unlock.bmp" }, RGB(1, 1, 1));
		Levels_bg[i].LoadBitmapByString({ "resources/level_bg/level_bg.bmp" }, RGB(1, 1, 1));
		if (i >= 15) {
			Levels[i].SetTopLeft(120 + (110 * ((i-15) % 5)), 115 + 120 * int((i - 15) / 5));
			Levels_bg[i].SetTopLeft(116 + (110 * ((i - 15) % 5)), 145 + 120 * int((i - 15) / 5));
		}
		else {
			Levels[i].SetTopLeft(120 + (110 * (i % 5)), 115 + 120 * int(i / 5));
			Levels_bg[i].SetTopLeft(116 + (110 * (i % 5)), 145 + 120 * int(i / 5));
		}
		if (i + 1 <= phase) {
			string temp = "resources/level_bg/" + std::to_string(i + 1) + ".bmp";
			Levels_num[i].LoadBitmapByString({ temp }, RGB(1, 1, 1));
			Levels_num[i].SetTopLeft(163 + (100 * (i % 5)), 125 + 120 * int(i / 5) );
			Levels_clock1[i].LoadBitmapByString({"resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp"}, RGB(1, 1, 1));
			Levels_clock1[i].SetTopLeft(129 + (110 * (i % 5)), 170 + 120 * int(i / 5));
			Levels_clock2[i].LoadBitmapByString({ "resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp" }, RGB(1, 1, 1));
			Levels_clock2[i].SetTopLeft(154 + (110 * (i % 5)), 170 + 120 * int(i / 5));
			Levels_clock3[i].LoadBitmapByString({ "resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp" }, RGB(1, 1, 1));
			Levels_clock3[i].SetTopLeft(179 + (110 * (i % 5)), 170 + 120 * int(i / 5));
		}	
	}

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
	int left = character.GetLeft();
	int top = character.GetTop();
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
		}
		else if (phase == 2) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_2();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}
		else if (phase == 3) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_3();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}
		else if (phase == 4) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_4();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}
		else if (phase == 5) {
			if (sub_phase == 1) {
				sub_phase += validate_phase_5();
			}
			else if (sub_phase == 2) {
				sub_phase = 1;
				phase += 1;
			}
		}
		else if (phase == 6) {
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
	//先把鍵盤移動註解
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

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	//選擇關卡點擊事件
	if (!isChoose) {
		for (int i = 0; i < phase; i++) {
			if (point.x > Levels[i].GetLeft() && point.x <= Levels[i].GetLeft() + Levels[i].GetWidth() - 20) {
				if (point.y > Levels[i].GetTop() + 15 && point.y <= Levels[i].GetTop() + Levels[i].GetHeight() - 20) {
					isChoose = true;
					phase = i + 1;
					//把狀態還原到選擇的關卡
					isRestart = true;
					isCharacterMove = false;
					isStart = false;
					if (phase == 1) {
						character.SetTopLeft(185, 403);
						dir1 = false;
						dir2 = false;
						isMovingLeft = false;
						isMovingRight = true;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						//bool isRestart = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						clock_shelf.SetTopLeft(375, 350);
						clock_1_shelf.SetTopLeft(495, 238);
						clock_2_shelf.SetTopLeft(615, 238);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						exit.SetTopLeft(713, 193);
						direction_2.SetTopLeft(358, 415);
						times = 0;
						pass = false;
					}
					else if (phase == 2) {
						character2.SetTopLeft(350, 418);
						//character.ShowBitmap();
						dir1 = false;
						dir2 = false;
						dir3 = false;
						isMovingLeft = true;//初始為往左走
						isMovingRight = false;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						//bool isRestart = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						dir3_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						/*clock.SetTopLeft(185, 403);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(520, 305);*/
						clock_shelf.SetTopLeft(195, 478);
						clock_1_shelf.SetTopLeft(375, 243);
						clock_2_shelf.SetTopLeft(555, 355);
						direction_1.SetTopLeft(180, 173);
						direction_2.SetTopLeft(357, 295);
						direction_3.SetTopLeft(540, 418);
						clock.SetTopLeft(200, 428);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(560, 305);
						exit.SetTopLeft(180, 80);
						times = 0;
						pass = false;
					}
					/*第三關點擊*/
					else if (phase == 3) {
						character3.SetTopLeft(130, 185);
						//character.ShowBitmap();
						dir1 = false;
						dir2 = false;
						dir3 = false;
						isMovingLeft = false;//初始為往右走
						isMovingRight = true;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						//bool isRestart = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						dir3_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();

						direction_1.SetTopLeft(657, 237);
						direction_2.SetTopLeft(657, 358);

						clock.SetTopLeft(380, 193);
						clock_1.SetTopLeft(380, 428);
						clock_2.SetTopLeft(622, 305);
						clock_shelf.SetTopLeft(375, 243);
						clock_1_shelf.SetTopLeft(375, 478);
						clock_2_shelf.SetTopLeft(617, 355);
						exit.SetTopLeft(30, 418);
						times = 0;
						pass = false;

					}
					
					//要把start位置調整回去,音樂按鈕選擇調回去，音樂切換到開始
					start.SetTopLeft(697, 12);
					start_1.SetTopLeft(702, 12);
					musicButton_play.SetFrameIndexOfBitmap(0);
					CAudio::Instance()->Stop(AUDIO_START_BGM);
					CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM);
					CAudio::Instance()->Play(AUDIO_BUTTON);
				}
			}
		}
	
		// 關卡選擇音樂按鈕切換
		if (point.x > musicButton_play.GetLeft() + 25 && point.x <= musicButton_play.GetLeft() + musicButton_play.GetWidth() - 25) {
			if (point.y > musicButton_play.GetTop() + 15 && point.y <= musicButton_play.GetTop() + musicButton_play.GetHeight() - 20) {
				if (!isBGMPlay) {
					CAudio::Instance()->Resume();
					CAudio::Instance()->Play(AUDIO_BUTTON);
					isBGMPlay = true;
				}
				else {
					CAudio::Instance()->Play(AUDIO_BUTTON);
					CAudio::Instance()->Pause();
					isBGMPlay = false;
				}
			}
		}
		// 關卡選擇切換第一,二頁
		if (point.x > start.GetLeft() + 25 && point.x <= start.GetLeft() + start.GetWidth() - 25) {
			if (point.y > start.GetTop() + 15 && point.y <= start.GetTop() + start.GetHeight() - 20) {
				if (level_page == 1)
					level_page = 2;
				else if (level_page == 2)
					level_page = 1;
			}
		}
	}
	else {
		// 在遊戲開始前或中點擊查看關卡按鈕，切換到關卡選擇頁面
		if (point.x > level.GetLeft() && point.x <= level.GetLeft() + level.GetWidth() - 25) {
			if (point.y > level.GetTop() + 15 && point.y <= level.GetTop() + level.GetHeight() - 20) {
				isChoose = false;
				CAudio::Instance()->Stop(AUDIO_RUNSTATE_BGM);
				CAudio::Instance()->Play(AUDIO_BUTTON);
				CAudio::Instance()->Play(AUDIO_START_BGM);
			}
		}
		// 點擊重新開始或開始
		if (point.x > 697 + 25 && point.x <= 697 + start.GetWidth() - 25) {
			if (point.y > 12 + 15 && point.y <= 12 + start.GetHeight() - 20) {
				if (!isStart && !pass) {
					isCharacterMove = true;
					isStart = true;
				}
				else if (isStart && !pass) { //在該關重新開始(bool 回到初始值)
					isRestart = true;
					isCharacterMove = false;
					isStart = false;
					character.SetTopLeft(185, 403);
					dir1 = false;
					dir2 = false;
					isMovingLeft = false;
					isMovingRight = true;
					isMovingUp = false;
					isMovingDown = false;
					isDirectionMove = false;
					//bool isRestart = false;
					dir1_f = false; //用於設定初始方向
					dir2_f = false;
					clock1 = false;
					clock2 = false;
					clock3 = false;
				}
			}
		}
		//設定點擊dir1就可讓dir1跟著滑鼠位置移動
		if (!isStart && !pass && phase == 1) {
			if (point.x > direction_1.GetLeft() + 25 && point.x <= direction_1.GetLeft() + direction_1.GetWidth() - 25) {
				if (point.y > direction_1.GetTop() + 15 && point.y <= direction_1.GetTop() + direction_1.GetHeight() - 20) {
					isDirectionMove = true;
				}
			}
			if (isDirectionMove) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定點擊dir2就可讓dir2跟著滑鼠位置移動
		if (!isStart && !pass && phase == 2) {
			if (point.x > direction_2.GetLeft() + 25 && point.x <= direction_2.GetLeft() + direction_2.GetWidth() - 25) {
				if (point.y > direction_2.GetTop() + 15 && point.y <= direction_2.GetTop() + direction_2.GetHeight() - 20) {
					isDirectionMove = true;
				}
			}
			if (isDirectionMove) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定點擊dir1就可讓dir1跟著滑鼠位置移動
		if (!isStart && !pass && phase == 3) {
			if (point.x > direction_1.GetLeft() + 25 && point.x <= direction_1.GetLeft() + direction_1.GetWidth() - 25) {
				if (point.y > direction_1.GetTop() + 15 && point.y <= direction_1.GetTop() + direction_1.GetHeight() - 20) {
					isDirectionMove = true;
				}
			}
			if (isDirectionMove) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定點擊dir2就可讓dir2跟著滑鼠位置移動
		if (!isStart && !pass && phase == 3) {
			if (point.x > direction_2.GetLeft() + 25 && point.x <= direction_2.GetLeft() + direction_2.GetWidth() - 25) {
				if (point.y > direction_2.GetTop() + 15 && point.y <= direction_2.GetTop() + direction_2.GetHeight() - 20) {
					isDirectionMove = true;
				}
			}
			if (isDirectionMove) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定過關後點擊重新開始
		if (pass) {
			if (point.x > restart_1.GetLeft() + 25 && point.x <= restart_1.GetLeft() + restart_1.GetWidth() - 25) {
				if (point.y > restart_1.GetTop() + 15 && point.y <= restart_1.GetTop() + restart_1.GetHeight() - 20) {
					isRestart = true;
					isCharacterMove = false;
					isStart = false;
					if (phase == 1) {
						character.SetTopLeft(185, 403);
						dir1 = false;
						dir2 = false;
						isMovingLeft = false;
						isMovingRight = true;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						//bool isRestart = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						times = 0;
						pass = false;
					}
					else if (phase == 2) {
						character2.SetTopLeft(350, 418);
						dir1 = false;
						dir2 = false;
						dir3 = false;
						isMovingLeft = true;//初始為往左走
						isMovingRight = false;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						//bool isRestart = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						dir3_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						clock.SetTopLeft(185, 403);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(520, 305);
						clock_shelf.SetTopLeft(195, 478);
						clock_1_shelf.SetTopLeft(375, 243);
						clock_2_shelf.SetTopLeft(555, 355);
						direction_1.SetTopLeft(180, 173);
						direction_2.SetTopLeft(357, 295);
						direction_3.SetTopLeft(540, 418);
						clock.SetTopLeft(200, 428);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(560, 305);
						exit.SetTopLeft(180, 80);
						times = 0;
						pass = false;
					}
					CAudio::Instance()->Play(AUDIO_BUTTON);
					CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //關卡重新開始並撥放音樂
				}
			}
			//進入下一關
			if (point.x > start.GetLeft() + 25 && point.x <= start.GetLeft() + start.GetWidth() - 25) {
				if (point.y > start.GetTop() + 15 && point.y <= start.GetTop() + start.GetHeight() - 20) {
					phase += 1;
					times = 0;
					pass = false;
					isRestart = false;
					isCharacterMove = false;
					isStart = false;
					if (phase == 2) {
						//character.SetTopLeft(185, 403);
						dir1 = false;
						dir2 = false;
						isMovingLeft = true;//初始為往左走
						isMovingRight = false;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(430, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						//clock.SetTopLeft(380, 305);
						clock.SetTopLeft(185, 403);
						//clock_1.SetTopLeft(500, 193);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(520, 305);
						//加入
						clock_shelf.SetTopLeft(195, 478);
						clock_1_shelf.SetTopLeft(375, 243);
						clock_2_shelf.SetTopLeft(555, 355);
						direction_1.SetTopLeft(180, 173);
						direction_2.SetTopLeft(357, 295);
						//direction_2.SetTopLeft(540, 173);用成通關要放的位置
						direction_3.SetTopLeft(540, 418);
						character2.SetTopLeft(350, 418);
						clock.SetTopLeft(200, 428);
						clock_1.SetTopLeft(380, 193);
						clock_2.SetTopLeft(560, 305);
						exit.SetTopLeft(180, 80);
						CAudio::Instance()->Pause();
						CAudio::Instance()->Play(AUDIO_BUTTON);
						CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
					}
					else if (phase == 3) {
						//character.SetTopLeft(185, 403);
						dir1 = false;
						dir2 = false;
						isMovingLeft = true;//初始為往左走
						isMovingRight = false;
						isMovingUp = false;
						isMovingDown = false;
						isDirectionMove = false;
						dir1_f = false; //用於設定初始方向
						dir2_f = false;
						clock1 = false;
						clock2 = false;
						clock3 = false;
						//以下是過關改動的畫面(已改動)
						background.SetFrameIndexOfBitmap(0);
						background.SetTopLeft(0, 100);
						clock_get.SetFrameIndexOfBitmap(0);
						clock_1_get.SetFrameIndexOfBitmap(0);
						clock_2_get.SetFrameIndexOfBitmap(0);
						clock_get.SetTopLeft(310, 20);
						clock_1_get.SetTopLeft(370, 20);
						clock_2_get.SetTopLeft(460, 20);
						start.SetTopLeft(697, 12);
						start_1.SetTopLeft(702, 12);
						restart_1.SetTopLeft(697, 12);
						restart_2.SetTopLeft(700, 19);
						background_stars.SetFrameIndexOfBitmap(0);
						background_stars.SetTopLeft(0, -605);
						background_stars.ShowBitmap();
						direction_1.SetTopLeft(180, 173);
						//clock.SetTopLeft(380, 305);
						//clock.SetTopLeft(185, 403);
						//clock_1.SetTopLeft(500, 193);
						//clock_1.SetTopLeft(380, 193);
						//clock_2.SetTopLeft(520, 305);
						//加入
						//clock_shelf.SetTopLeft(195, 478);
						//clock_1_shelf.SetTopLeft(375, 243);
						//clock_2_shelf.SetTopLeft(555, 355);
						//direction_1.SetTopLeft(180, 173);
						//direction_2.SetTopLeft(357, 295);
						//direction_2.SetTopLeft(540, 173);用成通關要放的位置
						//direction_3.SetTopLeft(540, 418);
						//character2.SetTopLeft(350, 418);
						//clock.SetTopLeft(200, 428);
						//clock_1.SetTopLeft(380, 193);
						//clock_2.SetTopLeft(560, 305);
						//exit.SetTopLeft(180, 80);
						CAudio::Instance()->Pause();
						CAudio::Instance()->Play(AUDIO_BUTTON);
						CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂

						direction_1.SetTopLeft(690, 253);
						direction_2.SetTopLeft(357, 295);
						//direction_3.SetTopLeft(540, 418);

						clock.SetTopLeft(380, 193);
						//clock.SetTopLeft(200, 428);
						//clock_1.SetTopLeft(380, 193);
						clock_1.SetTopLeft(590, 305);
						clock_2.SetTopLeft(380, 428);
						//clock_2.SetTopLeft(560, 305);
						clock_shelf.SetTopLeft(375, 243);
						clock_1_shelf.SetTopLeft(585, 355);
						clock_2_shelf.SetTopLeft(375, 478);
						exit.SetTopLeft(180, 428);
					}
					
				}
			}
			//切換音樂(音樂還未做)
			if (point.x > musicButton_play.GetLeft() + 25 && point.x <= musicButton_play.GetLeft() + musicButton_play.GetWidth() - 25) {
				if (point.y > musicButton_play.GetTop() + 15 && point.y <= musicButton_play.GetTop() + musicButton_play.GetHeight() - 20) {
					if (!isBGMPlay) {
						CAudio::Instance()->Stop(AUDIO_RUNSTATE_BGM);
						CAudio::Instance()->Resume();
						CAudio::Instance()->Play(AUDIO_BUTTON);//有延遲
						isBGMPlay = true;
					}
					else {
						CAudio::Instance()->Play(AUDIO_BUTTON);//有延遲
						CAudio::Instance()->Pause();
						isBGMPlay = false;
					}
				}
			}
		}
	}
	
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (isDirectionMove && !isStart) {
		isDirectionMove = false;
		if (phase == 1)
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		else if (phase == 2)
			direction_2.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (isDirectionMove) {
		if (phase == 1)
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		else if (phase == 2)
			direction_2.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::show_image_unpass() {
	//第一關畫面
	if (phase == 1) {
		if (!isStart) { //重啟或剛開始
			if (isRestart) {
				isRestart = false;
				clock.SetTopLeft(380, 305);
				clock_1.SetTopLeft(500, 193);
				clock_2.SetTopLeft(620, 193);
				direction_1.SetFrameIndexOfBitmap(0);
				direction_2.SetFrameIndexOfBitmap(0);
				stage_num.SetFrameIndexOfBitmap(0);
				exit.SetFrameIndexOfBitmap(0);
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
	else if (phase == 2) {
		if (!isStart) { //重啟或剛開始；角色開始移動前畫面
			if (isRestart) {
				isRestart = false;
				clock.SetTopLeft(200, 428);
				clock_1.SetTopLeft(380, 193);
				clock_2.SetTopLeft(560, 305);
			}
			
			background_stars.SetFrameIndexOfBitmap(0);
			background_stars.SetTopLeft(0, -605);
			background_stars.ShowBitmap();
			direction_1.SetFrameIndexOfBitmap(1);
			direction_2.SetFrameIndexOfBitmap(1);
			character2.SetAnimation(300, false);
			background_stars.ShowBitmap();
			onCloudsMove();
			stage.ShowBitmap();
			stage_num.SetFrameIndexOfBitmap(1);
			stage_num.ShowBitmap();
			show_image_by_phase();
			level_1.ShowBitmap(0.7);
			level.ShowBitmap(0.7);
			start_1.ShowBitmap(0.7);
			start.ShowBitmap(0.7);

			clock.ShowBitmap(0.3);
			clock_shelf.ShowBitmap();
			clock_1.ShowBitmap(0.3);
			clock_1_shelf.ShowBitmap();
			clock_2.ShowBitmap(0.3);
			clock_2_shelf.ShowBitmap();
			direction_1.ShowBitmap();
			direction_2.ShowBitmap();
			direction_3.ShowBitmap();
			exit.SetFrameIndexOfBitmap(1);

			exit.ShowBitmap();
			//character.SetTopLeft(185, 403);
			character2.ShowBitmap(0.7);
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
			direction_3.ShowBitmap();
			exit.ShowBitmap();
			character2.ShowBitmap(0.7);
			character2.SetAnimation(300, false);
			//character.ShowBitmap(0.7);
			//character.SetAnimation(300, false);
			show_text_by_phase();
		}
	}
	else if (phase == 3) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
			clock.SetTopLeft(380, 193);
			clock_1.SetTopLeft(380, 428);
			clock_2.SetTopLeft(622, 305);
		}

		background_stars.SetFrameIndexOfBitmap(0);
		background_stars.SetTopLeft(0, -605);
		background_stars.ShowBitmap();
		direction_1.SetFrameIndexOfBitmap(2);
		direction_2.SetFrameIndexOfBitmap(2);
		character3.SetAnimation(300, false);
		background_stars.ShowBitmap();
		onCloudsMove();
		stage.ShowBitmap();
		stage_num.SetFrameIndexOfBitmap(2);
		stage_num.ShowBitmap();
		show_image_by_phase();
		level_1.ShowBitmap(0.7);
		level.ShowBitmap(0.7);
		start_1.ShowBitmap(0.7);
		start.ShowBitmap(0.7);

		clock.ShowBitmap(0.3);
		clock_shelf.ShowBitmap();
		clock_1.ShowBitmap(0.3);
		clock_1_shelf.ShowBitmap();
		clock_2.ShowBitmap(0.3);
		clock_2_shelf.ShowBitmap();
		direction_1.ShowBitmap();
		direction_2.ShowBitmap();
		//direction_3.ShowBitmap();
		exit.SetFrameIndexOfBitmap(2);

		exit.ShowBitmap();
		//character.SetTopLeft(185, 403);
		character3.ShowBitmap(0.7);
		//show_text_by_phase();
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
		//direction_3.ShowBitmap();
		exit.ShowBitmap();
		character3.SetAnimation(300, false);
		character3.ShowBitmap(0.7);
		//character.ShowBitmap(0.7);
		//character.SetAnimation(300, false);
		show_text_by_phase();
	}
	}

}
void CGameStateRun::show_image_pass() {
	show_image_by_phase();
	clock_get.ShowBitmap(0.57);
	clock_1_get.ShowBitmap(0.57);
	clock_2_get.ShowBitmap(0.57);
	if (clock1) {
		clock.SetTopLeft(219, 40);
		clock.ShowBitmap(0.6);
	}
	if (clock2) {
		clock_1.SetTopLeft(359, 17);
		clock_1.ShowBitmap(0.6);
	}
	if (clock3) {
		clock_2.SetTopLeft(499, 40);
		clock_2.ShowBitmap(0.6);
	}
	bubble_fly.ShowBitmap();
	flower_fly.ShowBitmap();
	meow_fly.ShowBitmap();
	if (times > 18)
	{
		bubble.ShowBitmap(0.9);
		flower.ShowBitmap(0.9);
		meow.ShowBitmap(0.9);
		start_1.ShowBitmap();
		start.ShowBitmap();
		restart_2.ShowBitmap();
		restart_1.ShowBitmap();
		musicButton_play_1.ShowBitmap();
		musicButton_play.ShowBitmap();
		//重新設定不過關，進入下一關
		/*if (pass) {
			pass = false;
		}*/
	}
}
void CGameStateRun::show_level_choose() {
	background_stars.SetTopLeft(0,0);
	background_stars.ShowBitmap();
	musicButton_play.SetFrameIndexOfBitmap(1);
	musicButton_play_1.SetTopLeft(692, 15);
	musicButton_play.SetTopLeft(675, 0);
	musicButton_play_1.ShowBitmap(0.7);
	musicButton_play.ShowBitmap(0.7);
	start.SetTopLeft(673,238);
	start_1.SetTopLeft(680,240);
	start_1.ShowBitmap(0.8);
	start.ShowBitmap(0.8);
	
	if (level_page == 1) {
		for (int i = 0; i < 15; i++) {
			Levels_bg[i].ShowBitmap(0.8);
			if (i + 1 <= phase) {
				Levels[i].SetFrameIndexOfBitmap(1);
				Levels[i].ShowBitmap(0.8);
				Levels_num[i].ShowBitmap(0.9);
				int getClock = getClock_arr[phase - 1];
				//應用陣列紀錄各個clock是否被拿(未做)
				if (getClock == 3)
				{
					Levels_clock1[i].SetFrameIndexOfBitmap(1);
					Levels_clock2[i].SetFrameIndexOfBitmap(1);
					Levels_clock3[i].SetFrameIndexOfBitmap(1);
				}

				Levels_clock1[i].ShowBitmap(0.4);
				Levels_clock2[i].ShowBitmap(0.4);
				Levels_clock3[i].ShowBitmap(0.4);
			}
			else {
				Levels[i].SetFrameIndexOfBitmap(0);
				Levels[i].ShowBitmap(0.8);
			}
				
			
		}
	}
	else {
		for (int i = 15; i < 30; i++) {
			Levels_bg[i].ShowBitmap(0.8);
			if (i + 1 <= phase) {
				Levels[i].SetFrameIndexOfBitmap(1);
				Levels[i].ShowBitmap(0.8);
				Levels_num[i].ShowBitmap(0.9);
				Levels_clock1[i].ShowBitmap(0.4);
				Levels_clock2[i].ShowBitmap(0.4);
				Levels_clock3[i].ShowBitmap(0.4);
			}
			else {
				Levels[i].SetFrameIndexOfBitmap(0);
				Levels[i].ShowBitmap(0.8);
			}
		}
	}
	//Sleep(1000);
	//isChoose = true;
}
void CGameStateRun::OnShow()
{
	//下兩行直接切換到第三關(demo需註解)
	phase = 3;
	//isChoose = true;
	//進入關卡選擇畫面
	if (!isChoose) {
		show_level_choose();
	}
	else{
		//phase = 2;(要改掉)
		if (phase == 1) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
		//第二關(phase += 1;)
		else if (phase == 2) {
			//times = 0;
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 3) {
			//times = 0;
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
	}
	
}
void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		//background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		if (pass) {
			background.SetFrameIndexOfBitmap(1);
			background.SetTopLeft(-5, -7);
			clock_get.SetFrameIndexOfBitmap(1);
			clock_1_get.SetFrameIndexOfBitmap(1);
			clock_2_get.SetFrameIndexOfBitmap(1);
			clock_get.SetTopLeft(210, 33);
			clock_1_get.SetTopLeft(350, 10);
			clock_2_get.SetTopLeft(490, 33);
			start.SetTopLeft(350, 441);
			start_1.SetTopLeft(357, 443);
			restart_1.SetTopLeft(210, 441);
			restart_2.SetTopLeft(213, 453);
			musicButton_play.SetTopLeft(490, 441);
			musicButton_play_1.SetTopLeft(493, 456);
			background_stars.SetFrameIndexOfBitmap(1);
			background_stars.SetTopLeft(270, 210);
			background_stars.ShowBitmap();
			if (times == 0) {
				bubble_fly.ToggleAnimation();
				flower_fly.ToggleAnimation();
				meow_fly.ToggleAnimation();
			}
			times++;
		}
		background.ShowBitmap();
		//background_filter.ShowBitmap();
		//bg4.ShowBitmap(1.2);
	}
}
void CGameStateRun::show_text_by_phase() {

}

bool CGameStateRun::validate_phase_1() {
	return character.GetImageFileName() == "resources/giraffe.bmp";
}

bool CGameStateRun::validate_phase_2() {
	return character.GetTop() > 204 && character.GetTop() < 325 && character.GetLeft() > 339 && character.GetLeft() < 459;
}

bool CGameStateRun::validate_phase_3() {
	return (
		character.GetTop() + character.GetHeight() >= chest_and_key.GetTop()
		&& character.GetLeft() + character.GetWidth() >= chest_and_key.GetLeft()
		&& chest_and_key.GetFrameIndexOfBitmap() == 1
		&& chest_and_key.GetFilterColor() == RGB(255, 255, 255)
		);
}

bool CGameStateRun::validate_phase_4() {
	return bee.IsAnimation() && bee.GetFrameSizeOfBitmap() == 2;
}

bool CGameStateRun::validate_phase_5() {
	bool check_all_door_is_open = true;
	for (int i = 0; i < 3; i++) {
		check_all_door_is_open &= (door[i].GetFrameIndexOfBitmap() == 1);
	}
	return check_all_door_is_open;
}

bool CGameStateRun::validate_phase_6() {
	return ball.IsAnimationDone() && !ball.IsAnimation();
}