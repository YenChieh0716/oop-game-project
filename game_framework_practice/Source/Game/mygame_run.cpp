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
}
void CGameStateRun::onCharacterMove() {
		const int STEP_SIZE = 5;
		int x = character.Left();
		int y = character.Top();
		
		//bool dir;絕對值相減
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

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if (!dir1) {
		dir1 = bitmapOverlap(character, direction_1, 55,80);
	}
	if (!dir2) {
		dir2 = bitmapOverlap(character, direction_2, 55,80);
	}
	if (!pass) {
		pass = bitmapOverlap(character, exit, 30,70); // 抵達出口
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
		
	//檢查重疊character,chest_and_key
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
	//檢查重疊character,door，後來發現前面的步驟更改到門
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

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	background_stars.LoadBitmapByString({ "resources/runState/backgroundStars.bmp", "resources/runState/pass/bg1.bmp" });
	background_stars.SetTopLeft(0, -605);
	background.LoadBitmapByString({ "resources/runState/bg2_1.bmp", "resources/runState/pass/bg2.bmp"}, RGB(1, 1, 1));
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

	clock_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp"}, RGB(1, 1, 1));
	clock_1_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp" }, RGB(1, 1, 1));
	clock_2_get.LoadBitmapByString({ "resources/runState/clock_1.bmp" ,"resources/runState/pass/clock_1.bmp" }, RGB(1, 1, 1));
	clock_get.SetTopLeft(310, 20);
	clock_1_get.SetTopLeft(370, 20);
	clock_2_get.SetTopLeft(430, 20);

	musicButton_play.LoadBitmap("resources/runState/pass/music_1.bmp", RGB(1, 1, 1));
	musicButton_play_1.LoadBitmap("resources/runState/pass/music_2.bmp", RGB(1, 1, 1));

	bubble.LoadBitmapByString({ "resources/runState/pass/bubble.bmp" }, RGB(254, 254, 254));
	bubble.SetTopLeft(110, 170);
	bubble_fly.LoadBitmapByString({ "resources/runState/pass/bubble_flypath_1.bmp",
	"resources/runState/pass/bubble_flypath_2.bmp" ,"resources/runState/pass/bubble_flypath_3.bmp" }, RGB(254,254,254));
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
	if (point.x > 697 + 25 && point.x <= 697 + start.Width() - 25) {
		if (point.y > 12 + 15 && point.y <= 12 + start.Height() - 20) {
			if (!isStart) {
				isCharacterMove = true;
				isStart = true;
			}
			else if (isStart) { //在該關重新開始(bool 回到初始值)
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
				dir1_f = false; //用於設定初始方向
				dir2_f = false;
				clock1 = false;
				clock2 = false;
				clock3 = false;
			}
		}
	}
	//設定點擊dir1就可讓dir1跟著滑鼠位置移動
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

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (isDirectionMove && !isStart) {
		isDirectionMove = false;
		direction_1.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (isDirectionMove) {
		direction_1.SetTopLeft(point.x - 25, point.y - 15);
	}
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::show_image_unpass() {
	if (!isStart) { //重啟或剛開始
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
void CGameStateRun::show_image_pass() {
	if (phase == 1)
		phase += 1;
	//pass = false;
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
	}
}
void CGameStateRun::OnShow()
{
	if (!pass && phase == 1) {
		show_image_unpass();
	}
	//顯示過關畫面(未完成)
	else if (pass) {
		show_image_pass();
	}
	
}

void CGameStateRun::show_image_by_phase() {
	if (phase <= 6) {
		//background.SelectShowBitmap((phase - 1) * 2 + (sub_phase - 1));
		if (pass) {
			background.SelectShowBitmap(1);
			background.SetTopLeft(-5, -7);
			clock_get.SelectShowBitmap(1);
			clock_1_get.SelectShowBitmap(1);
			clock_2_get.SelectShowBitmap(1);
			clock_get.SetTopLeft(210, 33);
			clock_1_get.SetTopLeft(350, 10);
			clock_2_get.SetTopLeft(490, 33);
			start.SetTopLeft(350, 441);
			start_1.SetTopLeft(357, 443);
			restart_1.SetTopLeft(210, 441);
			restart_2.SetTopLeft(213, 453);
			musicButton_play.SetTopLeft(490, 441);
			musicButton_play_1.SetTopLeft(493, 456);
			background_stars.SelectShowBitmap(1);
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