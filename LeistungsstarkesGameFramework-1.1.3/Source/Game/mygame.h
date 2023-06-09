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
		AUDIO_START_BGM,		//0
		AUDIO_BUTTON,			//1
		AUDIO_RUNSTATE_BGM,		//2
		AUDIO_PASS				//3
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
		CMovingBitmap background_musicButton_play_1;
		CMovingBitmap background_musicButton_play_2;
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
		CMovingBitmap loading_bg;
		CMovingBitmap loading_1;
		CMovingBitmap loading_2;
		CMovingBitmap loading_3;
		bool isMoving = true;
		bool isBGMPlay = true;
		bool isInitialed = false; //是否顯示進度條
		int times = 0; //計時
		int times_1 = 0;
		int times_2 = 0;
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
		int phase = 1; //Demo改回1
		int sub_phase = 1;
		int times = 0;
		int getClock_arr[30];
		int level_page = 1;
		CMovingBitmap Levels[30], Levels_bg[30], Levels_num[30], Levels_clock1[30], Levels_clock2[30], Levels_clock3[30];
		CMovingBitmap background, background_filter, background_stars, bg4;
		CMovingBitmap character, character2, character3;
		CMovingBitmap cloud, cloud_1;
		CMovingBitmap stage, stage_num, stage_num_6;
		CMovingBitmap level, level_1;
		CMovingBitmap start, start_1;
		CMovingBitmap restart_1, restart_2;
		CMovingBitmap clock, clock_shelf, clock_get, clock_1, clock_1_shelf, clock_1_get, clock_2, clock_2_shelf, clock_2_get;
		CMovingBitmap direction_1, direction_2, direction_3, direction_4;
		CMovingBitmap exit;
		CMovingBitmap musicButton_play, musicButton_play_1, musicButton_unplay;
		CMovingBitmap bubble, bubble_fly;
		CMovingBitmap flower, flower_fly;
		CMovingBitmap meow, meow_fly;
		CMovingBitmap block;
		void show_image_by_phase();
		void show_image_unpass();
		void show_image_pass();
		void show_text_by_phase();
		bool validate_phase_1(), validate_phase_2(), validate_phase_3(), validate_phase_4(), validate_phase_5(), validate_phase_6();
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
		bool dir3 = false;
		bool dir4 = false;//phase5增加
		bool dir1_f = false; //用於設定初始方向
		bool dir2_f = false;
		bool dir3_f = false;
		bool dir4_f = false;//phase5增加
		bool pass = false;
		bool clock1 = false;
		bool clock2 = false;
		bool clock3 = false;
		bool isBGMPlay = true;
		bool isChoose = false;
		void onCharacterMove();
		void onCloudsMove();
		void onPassCharacterMove();
		void show_level_choose();
		bool bitmapOverlap(CMovingBitmap a, CMovingBitmap b, int offsetX, int offsetY);
		bool dir1_click = false; //判斷第三關哪個dir被點擊中
		bool dir2_click = true;
		void Level1_init(), Level2_init(), Level3_init(),
			 Level4_init(), Level5_init(), Level6_init(),
			 Level7_init(), Level8_init(), Level9_init(),
			 Level10_init();
		//phase4
		CMovingBitmap exit1, exit2; // phase4
		CMovingBitmap c1_flower, c2_bubble; //phase4 character
		CMovingBitmap dir_f1, dir_f2, dir_f3, dir_b1, dir_b2, dir_b3;//phase4 dir button img
		CMovingBitmap block1, block2, block3; //phase4 block img
		//phase4 dir button overlap
		bool dir1_b = false;
		bool dir2_b = false;
		bool dir3_b = false;
		bool dir1_b_f = false; //用於設定初始方向
		bool dir2_b_f = false;
		bool dir3_b_f = false;
		// phase4 character initial direction(for bubble)
		bool isMovingLeft_b = false;
		bool isMovingRight_b = true;
		bool isMovingUp_b = false;
		bool isMovingDown_b = false;
		bool isCharacterMove_b = false;
		//	phase4 character pass
		bool f_pass = false; // flower pass
		bool b_pass = false; // bubble pass

		//	phase4 dir click
		bool dirf1_click = false;
		bool dirf3_click = false;
		bool dirb1_click = false;
		bool dirb3_click = false;

		// phase6
		CMovingBitmap exit3;
		CMovingBitmap ch1_flower, ch2_bubble, ch3_meow; // character
		CMovingBitmap block4, block5, block6; // block img
		bool isCharacterMove_meow = false;
		bool isMovingLeft_meow = false;
		bool isMovingRight_meow = false;
		bool isMovingUp_meow = true;
		bool isMovingDown_meow = false;
		bool dir1_m = false; //判斷哪個角色跟方向產生碰撞事件
		bool dir1_m_f = false;
		bool m_pass = false; //毛毛是否以抵達出口
		bool ch_colli = false;
		// phase7
		CMovingBitmap cha1_flower, cha2_bubble, cha3_meow; // character
		bool dirf2_click = false; //方向鍵
		bool dir2_m = false; //判斷哪個角色跟方向產生碰撞事件
		bool dir2_m_f = false;
		//bool dirf3_click = false; //方向鍵
		bool dir3_m = false; //判斷哪個角色跟方向產生碰撞事件
		bool dir3_m_f = false;
		//bool dirf4_click = false; //方向鍵
		bool dir4_m = false; //判斷哪個角色跟方向產生碰撞事件
		bool dir4_m_f = false;
		bool dir4_b = false;
		bool dir4_b_f = false;
		//bool dirf5_click = false; //方向鍵
		bool dir5_m = false; //判斷哪個角色跟方向產生碰撞事件
		bool dir5_m_f = false;
		bool dir5 = false;
		bool dir5_b = false;
		bool dir5_f = false;
		bool dir5_b_f = false;
		//CMovingBitmap test;
		//第十關
		CMovingBitmap blocks[15];
		CMovingBitmap dir_b4, dir_b5, dir_b6, dir_b7;
		CMovingBitmap dir_m1, dir_m2, dir_m3, dir_m4, dir_m5, dir_m6;
		//bool dirb1_click = false;
		bool dirm6_click = false;
		bool dir6_b = false;
		bool dir6_b_f = false;
		bool dir7_b = false;
		bool dir7_b_f = false;
		bool dir6_m = false;
		bool dir6_m_f = false;
		int pass_num = 0;
		bool f_add = false;
		bool b_add = false;
		bool m_add = false;
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
		CMovingBitmap loading_bg;
		CMovingBitmap loading_1;
		CMovingBitmap loading_2;
		CMovingBitmap loading_3;
		void load_background();
	};

}
