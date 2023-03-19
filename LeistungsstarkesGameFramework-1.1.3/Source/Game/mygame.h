/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// 定義各種音效的編號
		/*AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2*/
		AUDIO_START_BGM //0
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		void load_background();
		void draw_text();
		CMovingBitmap background;
		CMovingBitmap background_stars;
		CMovingBitmap background_title;
		CMovingBitmap background_musicButton_play;
		CMovingBitmap background_musicButton_unplay;
		CMovingBitmap startButton_play;
		CMovingBitmap startButton_play_1;
		CMovingBitmap startButton_unplay;
		CMovingBitmap fence_right_bottom;
		CMovingBitmap fence_left_bottom;
		CMovingBitmap Mailbox;
		CMovingBitmap Mailbox_logo;
		CMovingBitmap Mailbox_flag;
		CMovingBitmap cloud;
		CMovingBitmap cloud_1;
		CMovingBitmap sleep_1;
		CMovingBitmap sleep_2;
		CMovingBitmap sleep_3;
		bool isMoving = true;
		void onCloudsMove();
		void onSleepMove(CMovingBitmap &sleep, int ori_x, int ori_y);					// csie的logo
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int phase = 1;
		int sub_phase = 1;
		int times = 0;
		CMovingBitmap background;
		CMovingBitmap background_filter;
		CMovingBitmap background_stars;
		CMovingBitmap bg4;
		CMovingBitmap character;
		CMovingBitmap character2;
		CMovingBitmap cloud;
		CMovingBitmap cloud_1;
		CMovingBitmap stage;
		CMovingBitmap stage_num;
		CMovingBitmap level;
		CMovingBitmap level_1;
		CMovingBitmap start;
		CMovingBitmap start_1;
		CMovingBitmap restart_1;
		CMovingBitmap restart_2;
		CMovingBitmap clock;
		CMovingBitmap clock_shelf;
		CMovingBitmap clock_get;
		CMovingBitmap clock_1;
		CMovingBitmap clock_1_shelf;
		CMovingBitmap clock_1_get;
		CMovingBitmap clock_2;
		CMovingBitmap clock_2_shelf;
		CMovingBitmap clock_2_get;
		CMovingBitmap direction_1;
		CMovingBitmap direction_2;
		CMovingBitmap direction_3;
		CMovingBitmap exit;
		CMovingBitmap musicButton_play;
		CMovingBitmap musicButton_play_1;
		CMovingBitmap bubble;
		CMovingBitmap bubble_fly;
		CMovingBitmap flower;
		CMovingBitmap flower_fly;
		CMovingBitmap meow;
		CMovingBitmap meow_fly;

		CMovingBitmap chest_and_key;
		CMovingBitmap bee;
		CMovingBitmap ball;
		CMovingBitmap door[3];
		void show_image_by_phase();
		void show_image_unpass();
		void show_image_pass();
		void show_text_by_phase();
		bool validate_phase_1();
		bool validate_phase_2();
		bool validate_phase_3();
		bool validate_phase_4();
		bool validate_phase_5();
		bool validate_phase_6();
		//因腳色沒有碰到方向只會左右移動
		bool isMovingLeft = false;
		bool isMovingRight = true;
		bool isMovingUp = false;
		bool isMovingDown = false;
		bool isCharacterMove = false;
		bool isDirectionMove = false;
		bool isStart = false;
		bool isRestart = false;
		bool dir1 = false;
		bool dir2 = false;
		bool dir1_f = false; //用於設定初始方向
		bool dir2_f = false;
		bool pass = false;
		bool clock1 = false;
		bool clock2 = false;
		bool clock3 = false;
		void onCharacterMove();
		void onCloudsMove();
		void onPassCharacterMove();
		bool bitmapOverlap(CMovingBitmap a, CMovingBitmap b, int offsetX, int offsetY);
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnKeyDown(UINT, UINT, UINT);
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap background;
		void load_background();
	};

}