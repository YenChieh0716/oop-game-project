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
	//isBGMPlay = BGMPlay;
	fill(getClock_arr,getClock_arr + 30, 0);
	phase = 10;
}

void CGameStateRun::onCharacterMove() {
	const int STEP_SIZE = 5;
	int x, y,x2,y2,x3,y3;
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
	else if (phase == 4) {
		x = c1_flower.GetLeft();
		y = c1_flower.GetTop();
		x2 = c2_bubble.GetLeft();
		y2 = c2_bubble.GetTop();
	}
	else if (phase == 5) {
		x = character3.GetLeft();
		y = character3.GetTop();
	}
	else if (phase == 6) {
		x = ch1_flower.GetLeft();
		y = ch1_flower.GetTop();
		x2 = ch2_bubble.GetLeft();
		y2 = ch2_bubble.GetTop();
		x3 = ch3_meow.GetLeft();
		y3 = ch3_meow.GetTop();
	}
	else if (phase == 7) {
		x = cha1_flower.GetLeft();
		y = cha1_flower.GetTop();
		x2 = cha2_bubble.GetLeft();
		y2 = cha2_bubble.GetTop();
		x3 = cha3_meow.GetLeft();
		y3 = cha3_meow.GetTop();
	}
	else if (phase == 8) {
		x = ch2_bubble.GetLeft();
		y = ch2_bubble.GetTop();
	}
	else if (phase == 9) {
		x = character.GetLeft();
		y = character.GetTop();
	}
	else if (phase == 10) {
		x = ch1_flower.GetLeft();
		y = ch1_flower.GetTop();
		x2 = ch2_bubble.GetLeft();
		y2 = ch2_bubble.GetTop();
		x3 = ch3_meow.GetLeft();
		y3 = ch3_meow.GetTop();
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
	if (y <= 100) {
		isMovingUp = false;
		isMovingDown = true;
		//isMovingDown_b = true;
	}
	else if (y >= 481) {
		isMovingUp = true;
		isMovingDown = false;
	}
	if(phase<10){
	if (x2 <= 65) {
		isMovingLeft_b = false;
		isMovingRight_b = true;
	}
	else if (x2 >= 680) {
		isMovingLeft_b = true;
		isMovingRight_b = false;
	}
	if (y2 <= 100) {
		isMovingUp_b = false;
		isMovingDown_b = true;
	}
	//465
	else if (y2 >= 481) {
		isMovingUp_b = true;
		isMovingDown_b = false;
	}
	
	if (y2 <= 100) {
		isMovingUp_b = false;
		isMovingDown_b = true;
	}
	//465
	else if (y2 >= 465) {
		isMovingUp_b = true;
		isMovingDown_b = false;
	}
	if (x3 <= 70) {
		isMovingLeft_meow = false;
		isMovingRight_meow = true;
	}
	else if (x3 >= 680) {
		isMovingLeft_meow = true;
		isMovingRight_meow = false;
	}
	if (y3 <= 100) {
		isMovingUp_meow = false;
		isMovingDown_meow = true;
	}
	else if (y3 >= 465) {
		isMovingUp_meow = true;
		isMovingDown_meow = false;
	}
	}
	if (phase == 10) {
		if (x2 <= 65) {
			isMovingLeft_b = false;
			isMovingRight_b = true;
		}
		else if (x2 >= 680) {
			isMovingLeft_b = true;
			isMovingRight_b = false;
		}
		if (y2 <= 100) {
			isMovingUp_b = false;
			isMovingDown_b = true;
		}
		else if (y2 >= 481) {
			isMovingUp_b = true;
			isMovingDown_b = false;
		}
		if (x3 <= 70) {
			isMovingLeft_meow = false;
			isMovingRight_meow = true;
		}
		else if (x3 >= 675) {
			isMovingLeft_meow = true;
			isMovingRight_meow = false;
		}
		if (y3 <= 100) {
			isMovingUp_meow = false;
			isMovingDown_meow = true;
		}
		else if (y3 >= 481) {
			isMovingUp_meow = true;
			isMovingDown_meow = false;
		}
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
	if (phase == 4) {
		//dir1~dir3 for flower overlap
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
				isMovingRight = true;
				isMovingLeft = false;
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
		if (dir1_b) {
			if (!dir1_b_f) {
				dir1_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
			if (y2 <= 100) {
				isMovingUp_b = false;
				isMovingDown_b = true;
			}
			//因在碰到左方向時也觸發了到達地圖底部，會有往左上方向移動的bug，加 && !dir2_b_f解決
			else if (y2 >= 465 && !dir2_b_f) {
				isMovingUp_b = true;
				isMovingDown_b = false;
			}
		}
		if (dir2_b) {
			if (!dir2_b_f) {
				dir2_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = true;
			}
			if (x2 <= 70) {
				isMovingLeft_b = false;
				isMovingRight_b = true;
			}
			else if (x2 >= 680) {
				isMovingLeft_b = true;
				isMovingRight_b = false;
			}
		}
		if (dir3_b) {
			if (!dir3_b_f) {
				dir3_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
			if (y2 <= 100) {
				isMovingUp_b = false;
				isMovingDown_b = true;
			}
			else if (y2 >= 465) {
				isMovingUp_b = true;
				isMovingDown_b = false;
			}
		}
		
	}
	if (phase == 5) {
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
			else if (y >= 475) {
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
				isMovingUp = false;
				isMovingDown = true;
				isMovingRight = false;
				isMovingLeft = false;
			}
			if (y <= 100) {
				isMovingUp = false;
				isMovingDown = true;
			}
			else if (y >= 475) {
				isMovingUp = true;
				isMovingDown = false;
			}
		}
		if (dir4) {
			if (!dir4_f) {
				dir4_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
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
	if (phase == 6) {
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = true;
			}
		}
		if (dir1_b) {
			if (!dir1_b_f) {
				dir1_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = true;
			}
		}
		if (dir1_m) {
			if (!dir1_m_f) {
				dir1_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = true;
			}
		}
		
		

	}
	if (phase == 7) {
		//dir1~dir3 for flower overlap
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
			}
		}
		if (dir1_b) {
			if (!dir1_b_f) {
				dir1_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir1_m) {
			if (!dir1_m_f) {
				dir1_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = true;
				isMovingLeft_meow = false;
			}
		}
		if (dir2) {
			if (!dir2_f) {
				dir2_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
			}
		}
		if (dir2_b) {
			if (!dir2_b_f) {
				dir2_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir2_m) {
			if (!dir2_m_f) {
				dir2_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = true;
				isMovingLeft_meow = false;
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
		}
		if (dir3_b) {
			if (!dir3_b_f) {
				dir3_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir3_m) {
			if (!dir3_m_f) {
				dir3_m_f = true;
				isMovingUp_meow = true;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
			}
		}
		if (dir4) {
			if (!dir4_f) {
				dir4_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
		if (dir4_b) {
			if (!dir4_b_f) {
				dir4_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir4_m) {
			if (!dir4_m_f) {
				dir4_m_f = true;
				isMovingUp_meow = true;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
			}
		}
		if (dir5) {
			if (!dir5_f) {
				dir5_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
		if (dir5_b) {
			if (!dir5_b_f) {
				dir5_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir5_m) {
			if (!dir5_m_f) {
				dir5_m_f = true;
				isMovingUp_meow = true;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
			}
		}

	}
	if (phase == 8) {
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
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
		}
		if (dir3) {
			if (!dir3_f) {
				dir3_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
		if (dir4) {
			if (!dir4_f) {
				dir4_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = true;
			}
		}
	}
	if (phase == 9) {
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
		if (dir2) {
			if (!dir2_f) {
				dir2_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
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
		}
		if (dir4) {
			if (!dir4_f) {
				dir4_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = true;
			}
		}
		if (dir5) {
			if (!dir5_f) {
				dir5_f = true;
				isMovingUp = true;
				isMovingDown = false;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
	}
	if (phase == 10) {
		if (dir1) {
			if (!dir1_f) {
				dir1_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
			}
		}
		if (dir1_b) {
			if (!dir1_b_f) {
				dir1_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir1_m) {
			if (!dir1_m_f) {
				dir1_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = true;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
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
		}
		if (dir2_b) {
			if (!dir2_b_f) {
				dir2_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir2_m) {
			if (!dir2_m_f) {
				dir2_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = true;
				isMovingLeft_meow = false;
			}
		}
		if (dir3) {
			if (!dir3_f) {
				dir3_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
			}
		}
		if (dir3_b) {
			if (!dir3_b_f) {
				dir3_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir3_m) {
			if (!dir3_m_f) {
				dir3_m_f = true;
				isMovingUp_meow = true;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
			}
		}
		if (dir4) {
			if (!dir4_f) {
				dir4_f = true;
				isMovingUp = false;
				isMovingDown = true;
				isMovingRight = false;
				isMovingLeft = false;
			}
		}
		if (dir4_b) {
			if (!dir4_b_f) {
				dir4_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = true;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir4_m) {
			if (!dir4_m_f) {
				dir4_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = true;
				isMovingLeft_meow = false;
			}
		}
		if (dir5) {
			if (!dir5_f) {
				dir5_f = true;
				isMovingUp = false;
				isMovingDown = false;
				isMovingRight = true;
				isMovingLeft = false;
			}
		}
		if (dir5_b) {
			if (!dir5_b_f) {
				dir5_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir6_b) {
			if (!dir6_b_f) {
				dir6_b_f = true;
				isMovingUp_b = true;
				isMovingDown_b = false;
				isMovingRight_b = false;
				isMovingLeft_b = false;
			}
		}
		if (dir7_b) {
			if (!dir7_b_f) {
				dir7_b_f = true;
				isMovingUp_b = false;
				isMovingDown_b = false;
				isMovingRight_b = true;
				isMovingLeft_b = false;
			}
		}
		if (dir5_m) {
			if (!dir5_m_f) {
				dir5_m_f = true;
				isMovingUp_meow = true;
				isMovingDown_meow = false;
				isMovingRight_meow = false;
				isMovingLeft_meow = false;
			}
		}
		if (dir6_m) {
			if (!dir6_m_f) {
				dir6_m_f = true;
				isMovingUp_meow = false;
				isMovingDown_meow = false;
				isMovingRight_meow = true;
				isMovingLeft_meow = false;
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

	if (isMovingLeft_b)
		x2 -= STEP_SIZE;
	if (isMovingRight_b)
		x2 += STEP_SIZE;
	if (isMovingUp_b)
		y2 -= STEP_SIZE;
	if (isMovingDown_b)
		y2 += STEP_SIZE;

	if (isMovingLeft_meow)
		x3 -= STEP_SIZE;
	if (isMovingRight_meow)
		x3 += STEP_SIZE;
	if (isMovingUp_meow)
		y3 -= STEP_SIZE;
	if (isMovingDown_meow)
		y3 += STEP_SIZE;

	if (phase == 1)
		character.SetTopLeft(x, y);
	else if (phase == 2)
		character2.SetTopLeft(x, y);
	else if (phase == 3)
		character3.SetTopLeft(x, y);
	else if (phase == 4) {
		if (isCharacterMove)
			c1_flower.SetTopLeft(x, y);
		if (isCharacterMove_b)
			c2_bubble.SetTopLeft(x2, y2);
	}
	else if (phase == 5)
		character3.SetTopLeft(x, y);
	else if (phase == 6) {
		if (isCharacterMove)
			ch1_flower.SetTopLeft(x, y);
		if (isCharacterMove_b)
			ch2_bubble.SetTopLeft(x2, y2);
		if(isCharacterMove_meow)
			ch3_meow.SetTopLeft(x3, y3);
	}
	else if (phase == 7) {
		if (isCharacterMove)
			cha1_flower.SetTopLeft(x, y);
		if (isCharacterMove_b)
			cha2_bubble.SetTopLeft(x2, y2);
		if (isCharacterMove_meow)
			cha3_meow.SetTopLeft(x3, y3);
	}
	else if (phase == 8) {
		if (isCharacterMove)
			ch2_bubble.SetTopLeft(x, y);
	}
	else if (phase == 9) {
		if (isCharacterMove)
			character.SetTopLeft(x, y);
	}
	else if (phase == 10) {
		if (isCharacterMove)
			ch1_flower.SetTopLeft(x, y);
		if (isCharacterMove_b)
			ch2_bubble.SetTopLeft(x2, y2);
		if (isCharacterMove_meow)
			ch3_meow.SetTopLeft(x3, y3);
	}
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
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS);
				}
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
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); //切換到關卡開始畫面撥放另一音樂
				}
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
			dir1 = bitmapOverlap(character3, direction_1, 50, -50);
			//dir1 = character2.IsOverlap(character2, direction_1);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character3, direction_2, 50, -50);
		}
		if (!pass) {
			pass = bitmapOverlap(character3, exit, 0, 0); // 抵達出口
			if (pass) {
				isCharacterMove = false;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}
		}
		if (!clock1)
			//clock1 = false;
			clock1 = bitmapOverlap(character3, clock, 0, 0);
		if (!clock2)
			clock2 = bitmapOverlap(character3, clock_1, 0, 0);
		if (!clock3)
			clock3 = bitmapOverlap(character3, clock_2, 0, 0);
		if (isCharacterMove)
			onCharacterMove();
	}
	//第四關
	if (phase == 4 && !pass) {
		if (!dir1) {
			int X1 = c1_flower.GetLeft() + 50;
			int X2 = X1 + c1_flower.GetWidth() ;
			int X1_b = dir_f1.GetLeft();
			int X2_b = X1_b + dir_f1.GetWidth();
			if ((X2 >= X1_b) && (X1 <= X2_b)) {
				if(c1_flower.IsOverlap(c1_flower, dir_f1))
					dir1 = true;
			}
			dir1 = (bitmapOverlap(c1_flower, dir_f1, -75, -50) && c1_flower.IsOverlap(c1_flower, dir_f1));
		}
		if (!dir2) {
			if (bitmapOverlap(c1_flower, dir_f2, 50, -50) && c1_flower.IsOverlap(c1_flower, dir_f2))
				dir2 = true;
			//dir2 = bitmapOverlap(c1_flower, dir_f2, 50, -50);
		}
		if (!dir3) {
			dir3 = bitmapOverlap(c1_flower, dir_f3, 50, -50);
		}
		if (!dir1_b) {
			/*
			int X1 = c2_bubble.GetLeft()- 65;
			int Y1 = c2_bubble.GetTop() - 50;
			int X2 = X1 + c2_bubble.GetWidth()- 60 ;
			int Y2 = Y1 + c2_bubble.GetHeight() - 50;
			int X1_b = dir_b1.GetLeft();
			int Y1_b = dir_b1.GetTop() - 5;
			int X2_b = X1_b + dir_b1.GetWidth();
			int Y2_b = Y1_b + dir_b1.GetHeight() - 5;

			if ((X2 >= X1_b) && (X1 <= X2_b)) {
				//if(c2_bubble.IsOverlap(c2_bubble, dir_b1))
					dir1_b = true;
			}
			*/
			dir1_b = (bitmapOverlap(c2_bubble, dir_b1, 70, -50) && c2_bubble.IsOverlap(c2_bubble,dir_b1)); //65,-50 bitmapOverlap(c2_bubble, dir_b1, 65, -50) && 
		}
		if (!dir2_b) {

			/*
			int X1 = c2_bubble.GetLeft() - 65;
			int X2 = X1 + c2_bubble.GetWidth() - 65;
			int X1_b = dir_b2.GetLeft();
			int X2_b = X1_b + dir_b2.GetWidth();

			if ((X2 >= X1_b) && (X1 <= X2_b) && (X2 <= X2_b) && (X1 >= X1_b)) {
				dir2_b = true;
			}*/

			dir2_b = bitmapOverlap(c2_bubble, dir_b2, 55, -40) && c2_bubble.IsOverlap(c2_bubble, dir_b2);//bitmapOverlap(c2_bubble, dir_b2, 65, -40);
		}
		if (!dir3_b) {
			dir3_b = bitmapOverlap(dir_b3,c2_bubble, 40, 0);
		}
		if (!pass) {
			 //= pass;
			//pass = bitmapOverlap(exit2,c1_flower, 20, -10);
			//pass = bitmapOverlap(exit1, c2_bubble, 20, -10);
			if (!f_pass&& isStart) {
				f_pass = bitmapOverlap(exit2, c1_flower, 20, -10); //花先抵達出口
				if(f_pass)
					isCharacterMove = false;
				//if (f_pass) 
					//passNum += 1;
			}
			if (!b_pass&& isStart) {
				b_pass = bitmapOverlap(exit1, c2_bubble, 60, -10); //泡泡
				if(b_pass)
					isCharacterMove_b = false;
				//if (b_pass)
					//passNum += 1;
			}
			if (f_pass && b_pass && isStart) {
				pass = true;
				//isCharacterMove = false;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}
			
		}
		if (!clock1) {
			clock1 = bitmapOverlap(c1_flower, clock, 0, 0);
			if(!clock1)
				clock1 = bitmapOverlap(c2_bubble, clock, 0, 0);
		}
			//clock1 = false;
			
		if (!clock2) {
			clock2 = bitmapOverlap(c1_flower, clock_1, 0, 0);
			if (!clock2)
				clock2 = bitmapOverlap(c2_bubble, clock_1, 50, 20);
		}
		if (!clock3) {
			clock3 = bitmapOverlap(c1_flower, clock_2, 0, 0);
			if (!clock3)
				clock3 = bitmapOverlap(c2_bubble, clock_2, -100, 0);
		}
			
			onCharacterMove();
	}
	//第五關
	if (phase == 5 && !pass) {
		if (!dir1) {
			dir1 = bitmapOverlap(character3, direction_1, 50, -50);
			//dir1 = character2.IsOverlap(character2, direction_1);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character3, direction_2, 30, 60);
		}
		if (!dir3) {
			dir3 = bitmapOverlap(character3, direction_3, -80, -40);
		}
		if (!dir4) {
			//dir4 = bitmapOverlap(character3, direction_4, 50, 0);
			int X1 = direction_4.GetLeft() + 50;
			int Y1 = direction_4.GetTop() -100 ;
			int X2 = X1 + direction_4.GetWidth() + 50;
			int Y2 = Y1 + direction_4.GetHeight() -100;
			int X1_b = character3.GetLeft();
			int Y1_b = character3.GetTop() - 150;
			int X2_b = X1_b + character3.GetWidth();
			int Y2_b = Y1_b + character3.GetHeight() -60;
			if ((Y2 >= Y1_b) && (Y2_b >= Y1) && (X2 >= X1_b) && (X1 <= X2_b)) {
				dir4 =  true;
			}
			/*if (dir4)
				isCharacterMove = false;*/
					/*if (character3.GetTop() >= (direction_4.GetTop()-character3.GetHeight())) {
						//dir4 = true;
						if (character3.GetTop() <= (direction_4.GetTop()-direction_4.GetHeight()))
							dir4 = true;
					}*/
				//dir4 = true;
				/*if (character3.GetLeft() + character3.GetWidth() > direction_4.GetLeft()) {
				if (character3.GetLeft() < (direction_4.GetLeft() + direction_4.GetWidth()))*/
		//}
		//dir4 = bitmapOverlap(direction_4, character3, -50, -50);
			//}
		}
		if (!pass) {
			pass = bitmapOverlap(character3, exit, 0, 0); // 抵達出口
			if (pass) {
				isCharacterMove = false;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}
		}
		if (!clock1)
			//clock1 = false;
			clock1 = bitmapOverlap(character3, clock, -80, 0);
		if (!clock2)
			clock2 = bitmapOverlap(character3, clock_1, 0, 0);
		if (!clock3)
			clock3 = bitmapOverlap(character3, clock_2, 0, 80);
		if (isCharacterMove)
			onCharacterMove();
	}
	//第六關
	if (phase == 6 && !pass) {
		if (!ch_colli) {
			ch_colli = bitmapOverlap(ch1_flower, ch2_bubble, -50, 0);
			if (ch_colli) {
				isMovingDown = true;
				isMovingUp = false;
				isMovingLeft_b = true;
				isMovingRight_b = false;
				ch_colli = false;
			}
		}
		if (!dir1_f) {
			if(!dir1_b && !dir1_m)
				dir1 = bitmapOverlap(ch1_flower, direction_1, 0, 80);
		}
		if (!dir1_b_f) {
			if (!dir1 && !dir1_m)
				dir1_b = bitmapOverlap(ch2_bubble, direction_1, 60, -50);
			//if (dir1_b)
				//isCharacterMove_b = false;
		}
		if (!dir1_m_f) {
			if (!dir1 && !dir1_b)
				dir1_m = bitmapOverlap(ch3_meow, direction_1, 0, 80);
		}
			
		if (!pass) {
			if (!f_pass&& isStart) {
				f_pass = bitmapOverlap(exit2, ch1_flower, 20, -10); //花先抵達出口
				if (f_pass)
					isCharacterMove = false;
			}
			if (!b_pass&& isStart) {
				b_pass = bitmapOverlap(exit1, ch2_bubble, -50, -10); //泡泡
				if (b_pass)
					isCharacterMove_b = false;
			}
			if (!m_pass&& isStart) {
				m_pass = bitmapOverlap(exit3, ch3_meow, 20, -10); //毛毛
				if (m_pass)
					isCharacterMove_meow = false;
			}
			if (f_pass && b_pass && m_pass && isStart) {
				pass = true;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}

		}
		if (!clock1) {
			clock1 = bitmapOverlap(ch1_flower, clock, 0, 150);
			if (!clock1)
				clock1 = bitmapOverlap(ch2_bubble, clock, 50, 50);
				if (!clock1)
					clock1 = bitmapOverlap(ch3_meow, clock, 0, 0);
		}

		if (!clock2) {
			clock2 = bitmapOverlap(ch1_flower, clock_1, 0, 0);
			if (!clock2)
				clock2 = bitmapOverlap(ch2_bubble, clock_1, 50, 20);
				if (!clock2)
					clock2 = bitmapOverlap(ch3_meow, clock_1, 0, 150);
		}
		if (!clock3) {
			clock3 = bitmapOverlap(ch1_flower, clock_2, 0, 0);
			if (!clock3)
				clock3 = bitmapOverlap(ch2_bubble, clock_2, 50, 0);
				if (!clock3)
					clock3 = bitmapOverlap(ch3_meow, clock_2, 0, 0);
		}

		onCharacterMove();
	}
	//第七關
	if (phase == 7 && !pass) {
		/*if (!ch_colli) {
			ch_colli = bitmapOverlap(cha1_flower, cha2_bubble, -100, 90);
			if (ch_colli) {
				isMovingDown = true;
				isMovingUp = false;
				isMovingLeft_b = true;
				isMovingRight_b = false;
				//ch_colli = false;
			}
		}*/
		if (!dir1_f) {
			if (!dir1_b && !dir1_m)
				dir1 = bitmapOverlap(cha1_flower, dir_f1, -60, -40);
			//if (dir1)
				//isCharacterMove = false;
		}
		if (!dir1_b_f) {
			if (!dir1 && !dir1_m)
				dir1_b = bitmapOverlap(cha2_bubble, dir_f1, -80, 50);
			//if (dir1_b)
				//isCharacterMove_b = false;
		}
		if (!dir1_m_f) {
			if (!dir1 && !dir1_b)
				dir1_m = bitmapOverlap(cha3_meow, dir_f1, -60, 20);
			//if (dir1_m)
				//isCharacterMove_meow = false;
		}

		if (!dir2_f) {
			if (!dir2_b && !dir2_m)
				dir2 = bitmapOverlap(cha1_flower, dir_f2, -60, -40);
			//if (dir2)
				//isCharacterMove = false;
		}
		if (!dir2_b) {
			if (!dir2 && !dir2_m)
				dir2_b = bitmapOverlap(cha2_bubble, dir_f2, -80, 50);
			//if (dir2_b)
				//isCharacterMove_b = false;
		}
		if (!dir2_m_f) {
			if (!dir2 && !dir2_b)
				dir2_m = bitmapOverlap(cha3_meow, dir_f2, -60, 20);
			//if (dir2_m)
				//isCharacterMove_meow = false;
		}
		if (!dir3_f) {
			if (!dir3_b && !dir3_m)
				dir3 = bitmapOverlap(cha1_flower, dir_f3, -60, -40);
			//if (dir3)
				//isCharacterMove = false;
		}
		if (!dir3_b_f) {
			if (!dir3 && !dir3_m)
				dir3_b = bitmapOverlap(cha2_bubble, dir_f3, -80, 50);
			//if (dir3_b)
				//isCharacterMove_b = false;
		}
		if (!dir3_m_f) {
			if (!dir3 && !dir3_b)
				dir3_m = bitmapOverlap(cha3_meow, dir_f3, -60, 20);
			//if (dir3_m)
				//isCharacterMove_meow = false;
		}
		if (!dir4_f) {
			if (!dir4_b && !dir4_m)
			//isCharacterMove = false;
				dir4 = bitmapOverlap(cha1_flower, dir_b1, -60, -40);
			//if (dir4)
				//isCharacterMove = false;
		}
		if (!dir4_b_f) {
			if (!dir4 && !dir4_m)
				dir4_b = bitmapOverlap(cha2_bubble, dir_b1, -80, 50);
			//if (dir4_b)
				//isCharacterMove_b = false;
		}
		if (!dir4_m_f) {
			if (!dir4 && !dir4_b)
				dir4_m = bitmapOverlap(cha3_meow, dir_b1, -60, 20);
			//if (dir4_m)
				//isCharacterMove_meow = false;
		}
		if (!dir5_f) {
			if (!dir5_b && !dir5_m)
			//isCharacterMove = false;
				dir5 = bitmapOverlap(cha1_flower, dir_b2, -60, -40);
			//if (dir5)
				//isCharacterMove = false;
		}
		if (!dir5_b_f) {
			if (!dir5 && !dir5_m)
				dir5_b = bitmapOverlap(cha2_bubble, dir_b2, -80, 50);
			//if (dir5_b)
				//isCharacterMove_b = false;
		}
		if (!dir5_m_f) {
			if (!dir5 && !dir5_b)
				dir5_m = bitmapOverlap(cha3_meow, dir_b2, -60, 20);
			//if (dir5_m)
				//isCharacterMove_meow = false;
		}
		if (!pass) {
			if (!f_pass&& isStart) {
				//isCharacterMove = false;
				f_pass = bitmapOverlap(exit2, cha1_flower, -10, -10); //花先抵達出口
				//if (f_pass)
					//isCharacterMove = false;
			}
			if (!b_pass&& isStart) {
				b_pass = bitmapOverlap(exit1, cha2_bubble, 0, -10); //泡泡
				//if (b_pass)
					//isCharacterMove_b = false;
			}
			if (!m_pass&& isStart) {
				//isCharacterMove_meow = false;
				m_pass = bitmapOverlap(exit3,cha3_meow, 10, 0); //毛毛
				//if (m_pass)
					//isCharacterMove_meow = false;
			}
			if (f_pass && b_pass && m_pass && isStart) {
				pass = true;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}

		}
		if (!clock1) {
			clock1 = bitmapOverlap(cha1_flower, clock, 0, 150);
			if (!clock1)
				clock1 = bitmapOverlap(cha2_bubble, clock, 50, 50);
			if (!clock1)
				clock1 = bitmapOverlap(cha3_meow, clock, 0, 150);
			
		}

		if (!clock2) {
			clock2 = bitmapOverlap(cha1_flower, clock_1, 0, 0);
			//if (clock2)
				//3isCharacterMove = false;
			if (!clock2)
				clock2 = bitmapOverlap(cha2_bubble, clock_1, 50, 20);
			if (!clock2)
				clock2 = bitmapOverlap(cha3_meow, clock_1, -100, 150);
			
		}
		if (!clock3) {
			clock3 = bitmapOverlap(cha1_flower, clock_2, 0, 0);
			if (!clock3)
				clock3 = bitmapOverlap(cha2_bubble, clock_2, -100, 0);
			//if (clock3)
				//isCharacterMove_b = false;
			if (!clock3)
				clock3 = bitmapOverlap(cha3_meow, clock_2, -100, 150);
			
		}

		onCharacterMove();
	}
	//第八關
	if (phase == 8 && !pass) {
		if (!dir1) {
			dir1 = bitmapOverlap(ch2_bubble, direction_1, 60, -40);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(ch2_bubble, direction_2, -60, -50);
		}
		if (!dir3) {
			dir3 = bitmapOverlap(ch2_bubble, direction_3, 60, -40);
		}
		if (!dir4) {
			dir4 = bitmapOverlap(ch2_bubble, direction_4, -60,  70);
		}
		if (!pass) {
			if (!pass&& isStart) {
				pass = bitmapOverlap(exit, ch2_bubble, 0, -10); //泡泡
			}
			if (pass && isStart) {
				pass = true;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}

		}
		if (!clock1) {
			clock1 = bitmapOverlap(ch2_bubble, clock, -80, -40);
		}
		if (!clock2) {
			clock2 = bitmapOverlap(ch2_bubble, clock_1, 0, -80);
		}
		if (!clock3) {
			clock3 = bitmapOverlap(ch2_bubble, clock_2, 20, 50);
		}
		onCharacterMove();
	}
	//第九關
	if (phase == 9 && !pass) {
		
		if (!dir1) {
			dir1 = bitmapOverlap(character, direction_1, 50, -40);
		}
		if (!dir2) {
			dir2 = bitmapOverlap(character, direction_2, -60, 80);
		}
		if (!dir3) {
			dir3 = bitmapOverlap(character, dir_f1, 50, -40);
		}
		if (!dir4) {
			dir4 = bitmapOverlap(character, dir_f2, -60, 70);
		}
		if (!dir5) {
			dir5 = bitmapOverlap(character, dir_f3,-70, -40);
		}


		if (!pass) {
			if (!pass&& isStart) {
				pass = bitmapOverlap(exit, character, 25,-18); //泡泡
			}
			if (pass && isStart) {
				pass = true;
				CAudio::Instance()->Pause();
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
				}
			}
		}
		
		if (!clock1) {
			clock1 = bitmapOverlap(character, clock,  30,  60);
		}
		
		if (!clock2) {
			clock2 = bitmapOverlap(character, clock_1,-90,80);
		}
		if (!clock3) {
			clock3 = bitmapOverlap(character, clock_2, 20, 50);
		}
		/**/
		onCharacterMove();
	}
	//第十關
	if (phase == 10 && !pass) {

		if (!dir1) {
			dir1 = bitmapOverlap(ch1_flower, direction_1, 0, 70);
		}if (!dir1_b) {
			dir1_b = bitmapOverlap(ch2_bubble, dir_b1, 10, 60);
		}if (!dir1_m) {
			dir1_m = bitmapOverlap(ch3_meow, dir_m1, 55, 0);
		}

		if (!dir2) {
			dir2 = bitmapOverlap(ch1_flower, direction_2, 50, 0);
		}if (!dir2_b) {
			dir2_b = bitmapOverlap(ch2_bubble, dir_b2, 60, 0);
		}if (!dir2_m) {
			if (ch3_meow.GetLeft() >= 177 && ch3_meow.GetTop() >= 473)
				dir2_m = true;
		}

		if (!dir3) {
			dir3 = bitmapOverlap(ch1_flower, dir_f1, 0, 70);
		}if (!dir3_b) {
			dir3_b = bitmapOverlap(ch2_bubble, dir_b3, 0, 60);
		}if (!dir3_m) {
			dir3_m = bitmapOverlap(ch3_meow, dir_m3, 60, 0);
			//m_pass = true;
		}
		

		if (!dir4) {
			dir4 = bitmapOverlap(ch1_flower, dir_f2, 50, 0);
		}if (!dir4_b) {
			dir4_b = bitmapOverlap(ch2_bubble, dir_b4, 60, 0);
		}if (!dir4_m) {
			dir4_m = bitmapOverlap(ch3_meow, dir_m4, 0, 60);
			//m_pass = true;
		}
		/*
		if (!dir1_b) {
			dir1 = bitmapOverlap(ch1_flower, direction_1, 0, 70);
		}

		if (!dir1_m) {
			dir1 = bitmapOverlap(ch1_flower, direction_1, 0, 70);
		}
		*/
		if (!dir5) {
			dir5 = bitmapOverlap(ch1_flower, dir_f3, 0, -60);
		}if (!dir5_b) {
			dir5_b = bitmapOverlap(ch2_bubble, dir_b5, -10, -55);
		}if (!dir5_m) {
			dir5_m = bitmapOverlap(ch3_meow, dir_m5, 55, 0);
			//m_pass = true;
		}
		
		if (!dir6_b) {
			if (ch2_bubble.GetLeft() >= 659 && ch2_bubble.GetTop() >= 471)
				dir6_b = true;
		}if (!dir6_m) {
			//dir6_m = bitmapOverlap(ch3_meow, dir_m6, 10, 60);//60, 356
			if (ch3_meow.GetLeft() >= 657 && ch3_meow.GetTop() <= 306)
				dir6_m = true;
		}
		
		if (!dir7_b) {
			if (ch2_bubble.GetLeft() >= 659 && ch2_bubble.GetTop() <= 413)
				dir7_b = true;
		}
	
		if (!f_pass) {
			f_pass = bitmapOverlap(ch1_flower, exit2, 25, 0);
			if (f_pass && !f_add) {
				pass_num += 1;
				f_add = true;
			}
				
		}if (!b_pass) {
			b_pass = bitmapOverlap(ch2_bubble, exit1, 32, 50);
			if (b_pass && !b_add) {
				pass_num += 1;
				b_add = true;
			}
		}if (!m_pass) {
			m_pass = bitmapOverlap(ch3_meow, exit3, 25, 0);
			if (m_pass && !m_add) {
				pass_num += 1;
				m_add = true;
			}
		}
		
		
		if (!pass) {
			if (pass_num == 3) {
						pass = true;
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_PASS); // 切換到關卡開始畫面撥放另一音樂
						}
			}
		}
		if (!clock1) {
			clock1 = bitmapOverlap(ch1_flower, clock, 50, 0);
		}
		if (!clock2) {
			clock2 = bitmapOverlap(ch2_bubble, clock_1, -90, 80);
		}
		if (!clock3) {
			clock3 = bitmapOverlap(ch3_meow, clock_2, 20, 50);
		}
		//onCharacterMove();
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

	clock.LoadBitmapByString({ "resources/runState/clock.bmp","resources/runState/stage10/clock_flower.bmp" }, RGB(1, 1, 1)); //1,1,1
	clock_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock.SetTopLeft(380, 305);
	clock_shelf.SetTopLeft(375, 350);

	clock_1.LoadBitmapByString({ "resources/runState/clock.bmp","resources/runState/stage10/clock_bubble.bmp" }, RGB(1, 1, 1)); //1,1,1
	clock_1_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock_1.SetTopLeft(500, 193);
	clock_1_shelf.SetTopLeft(495, 238);

	clock_2.LoadBitmapByString({ "resources/runState/clock.bmp","resources/runState/stage10/clock_meow.bmp" }, RGB(1, 1, 1)); //1,1,1
	clock_2_shelf.LoadBitmap("resources/runState/clockShelf_1.bmp", RGB(1, 1, 1));
	clock_2.SetTopLeft(620, 193);
	clock_2_shelf.SetTopLeft(615, 238);

	stage.LoadBitmap("resources/runState/stage.bmp", RGB(1, 1, 1));
	stage_num.LoadBitmapByString(
		{ "resources/runState/stage_num.bmp", "resources/runState/stage2/stage_num.bmp", "resources/runState/stage3/stage_num.bmp",
		"resources/runState/stage4/stage_num.bmp","resources/runState/stage5/stage_num.bmp","resources/runState/stage6/stage_num.bmp",
		"resources/runState/stage7/stage_num.bmp","resources/runState/stage8/stage_num.bmp","resources/runState/stage9/stage_num.bmp",
		"resources/runState/stage10/stage_num.bmp"
		}, RGB(1, 1, 1));
	//stage_num_6.LoadBitmapByString({ 

	//	 });
	stage.SetTopLeft(310, 20);
	stage_num.SetTopLeft(490, 20);
	//stage_num_6.SetTopLeft(490, 20);

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

	direction_1.LoadBitmapByString({ "resources/runState/direction_1_1.bmp", "resources/runState/stage2/dir1.bmp", 
									"resources/runState/stage3/dir1.bmp","resources/runState/stage5/dir1.bmp",
									"resources/runState/stage6/dir1.bmp","resources/runState/stage8/dir1.bmp",
									"resources/runState/stage9/dir1.bmp","resources/runState/stage10/dir1_flower.bmp" }, RGB(1, 1, 1));
	direction_2.LoadBitmapByString({ "resources/runState/direction_2.bmp", "resources/runState/stage2/dir2.bmp", 
									 "resources/runState/stage3/dir2.bmp","resources/runState/stage5/dir2.bmp",
									 "resources/runState/stage8/dir2.bmp","resources/runState/stage9/dir2.bmp",
									 "resources/runState/stage10/dir2_flower.bmp" }, RGB(1, 1, 1));
	direction_3.LoadBitmapByString({ "resources/runState/stage2/dir3.bmp","resources/runState/stage5/dir3.bmp","resources/runState/stage8/dir3.bmp" }, RGB(1, 1, 1));
	direction_4.LoadBitmapByString({ "resources/runState/stage5/dir4.bmp","resources/runState/stage8/dir4.bmp" }, RGB(1, 1, 1));
	direction_1.SetTopLeft(180, 173);
	direction_2.SetTopLeft(358, 415);

	exit.LoadBitmapByString({ "resources/runState/door_1.bmp", "resources/runState/stage2/door_1.bmp",
							  "resources/runState/stage3/exit.bmp","resources/runState/stage5/exit.bmp",
							  "resources/runState/stage8/door_1.bmp","resources/runState/stage9/door.bmp" }, RGB(0, 0, 0));
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
		Levels[i].LoadBitmapByString({ "resources/level_bg/level_lock.bmp", "resources/level_bg/level_unlock.bmp" }, RGB(1, 1, 1));
		Levels_bg[i].LoadBitmapByString({ "resources/level_bg/level_bg.bmp" }, RGB(1, 1, 1));
		if (i >= 15) {
			Levels[i].SetTopLeft(120 + (110 * ((i - 15) % 5)), 115 + 120 * int((i - 15) / 5));
			Levels_bg[i].SetTopLeft(116 + (110 * ((i - 15) % 5)), 145 + 120 * int((i - 15) / 5));
		}
		else {
			Levels[i].SetTopLeft(120 + (110 * (i % 5)), 115 + 120 * int(i / 5));
			Levels_bg[i].SetTopLeft(116 + (110 * (i % 5)), 145 + 120 * int(i / 5));
		}
		// i+1<=phase
		if (i + 1 <= 10) {
			string temp = "resources/level_bg/" + std::to_string(i + 1) + ".bmp";
			Levels_num[i].LoadBitmapByString({ temp }, RGB(1, 1, 1));
			Levels_num[i].SetTopLeft(163 + (107 * (i % 5)), 125 + 120 * int(i / 5));
			Levels_clock1[i].LoadBitmapByString({ "resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp" }, RGB(1, 1, 1));
			Levels_clock1[i].SetTopLeft(129 + (110 * (i % 5)), 170 + 120 * int(i / 5));
			Levels_clock2[i].LoadBitmapByString({ "resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp" }, RGB(1, 1, 1));
			Levels_clock2[i].SetTopLeft(154 + (110 * (i % 5)), 170 + 120 * int(i / 5));
			Levels_clock3[i].LoadBitmapByString({ "resources/level_bg/greenClock.bmp","resources/level_bg/whiteClock.bmp" }, RGB(1, 1, 1));
			Levels_clock3[i].SetTopLeft(179 + (110 * (i % 5)), 170 + 120 * int(i / 5));
		}
	}
	//第三、五關障礙物
	block.LoadBitmapByString({ "resources/runState/stage3/block.bmp","resources/runState/stage5/block.bmp" }, RGB(1, 1, 1));
	//第四,九關(dir_f1~f3)
	exit1.LoadBitmapByString({ "resources/runState/stage4/door_1.bmp", "resources/runState/stage6/door_1.bmp",
							   "resources/runState/stage7/door_1.bmp","resources/runState/stage10/door_1.bmp"
								}, RGB(1, 1, 1));
	exit2.LoadBitmapByString({ "resources/runState/stage4/door_2.bmp","resources/runState/stage7/door_2.bmp",
								"resources/runState/stage10/door_2.bmp" }, RGB(1, 1, 1));
	c1_flower.LoadBitmapByString({ "resources/runState/stage4/flower_1.bmp","resources/runState/stage4/flower_2.bmp","resources/runState/stage4/flower_3.bmp" }, RGB(1, 1, 1));
	c2_bubble.LoadBitmapByString({ "resources/runState/stage4/bubble.bmp","resources/runState/stage4/bubble_1.bmp","resources/runState/stage4/bubble_2.bmp" }, RGB(254, 254, 254));
	dir_f1.LoadBitmapByString({ "resources/runState/stage4/direction_1.bmp", "resources/runState/stage7/dir1.bmp", 
								"resources/runState/stage9/dir3.bmp","resources/runState/stage10/dir3_flower.bmp" }, RGB(1, 1, 1));
	dir_f2.LoadBitmapByString({ "resources/runState/stage4/direction_2.bmp", "resources/runState/stage7/dir2.bmp",
								"resources/runState/stage9/dir4.bmp","resources/runState/stage10/dir4_flower.bmp" }, RGB(1, 1, 1));
	dir_f3.LoadBitmapByString({ "resources/runState/stage4/direction_3.bmp", "resources/runState/stage7/dir3.bmp",
								"resources/runState/stage9/dir5.bmp","resources/runState/stage10/dir5_flower.bmp" }, RGB(1, 1, 1));
	dir_b1.LoadBitmapByString({ "resources/runState/stage4/dir1.bmp", "resources/runState/stage7/dir4.bmp",
								"resources/runState/stage10/dir1_bubble.bmp" }, RGB(1, 1, 1));
	dir_b2.LoadBitmapByString({ "resources/runState/stage4/dir2.bmp","resources/runState/stage7/dir5.bmp",
								"resources/runState/stage10/dir2_bubble.bmp" }, RGB(1, 1, 1));
	dir_b3.LoadBitmapByString({ "resources/runState/stage4/dir3.bmp" , "resources/runState/stage10/dir3_bubble.bmp" }, RGB(1, 1, 1));
	block1.LoadBitmapByString({ "resources/runState/stage4/block1.bmp", "resources/runState/stage6/block1.bmp" ,
								"resources/runState/stage8/block2.bmp", "resources/runState/stage9/block1.bmp" });
	block2.LoadBitmapByString({ "resources/runState/stage4/block2.bmp", "resources/runState/stage6/block2.bmp",
								"resources/runState/stage9/block2.bmp" });
	block3.LoadBitmapByString({"resources/runState/stage4/block3.bmp","resources/runState/stage6/block3.bmp",
							   "resources/runState/stage9/block3.bmp" });
	//第六關
	ch1_flower.LoadBitmapByString({ "resources/runState/stage6/flower_1.bmp","resources/runState/stage6/flower_2.bmp","resources/runState/stage6/flower_3.bmp" }, RGB(1, 1, 1));
	ch2_bubble.LoadBitmapByString({ "resources/runState/stage6/bubble.bmp","resources/runState/stage6/bubble_1.bmp","resources/runState/stage6/bubble_2.bmp" }, RGB(254, 254, 254));
	ch3_meow.LoadBitmapByString({ "resources/runState/stage6/meow.bmp","resources/runState/stage6/meow_1.bmp","resources/runState/stage6/meow_2.bmp" }, RGB(254, 254, 254));
	block4.LoadBitmapByString({ "resources/runState/stage6/block4.bmp" });
	block5.LoadBitmapByString({ "resources/runState/stage6/block5.bmp" });
	block6.LoadBitmapByString({ "resources/runState/stage6/block6.bmp" });
	exit3.LoadBitmapByString({ "resources/runState/stage6/exit.bmp", "resources/runState/stage10/exit.bmp" });
	//第七關
	cha1_flower.LoadBitmapByString({ "resources/runState/stage7/flower_1.bmp","resources/runState/stage7/flower_2.bmp","resources/runState/stage7/flower_3.bmp" }, RGB(1, 1, 1));
	cha2_bubble.LoadBitmapByString({ "resources/runState/stage7/bubble.bmp","resources/runState/stage7/bubble_1.bmp","resources/runState/stage7/bubble_2.bmp" }, RGB(254, 254, 254));
	cha3_meow.LoadBitmapByString({ "resources/runState/stage7/meow.bmp","resources/runState/stage7/meow_1.bmp","resources/runState/stage7/meow_2.bmp" }, RGB(254, 254, 254));
	//第十關
	for (int i = 0; i < 15; i++) {
		string temp = "resources/runState/stage10/block" + std::to_string(i + 1) + ".bmp";
		blocks[i].LoadBitmapByString({ temp });
	}
	dir_b4.LoadBitmapByString({ "resources/runState/stage10/dir4_bubble.bmp" }, RGB(1, 1, 1));
	dir_b5.LoadBitmapByString({ "resources/runState/stage10/dir5_bubble.bmp" }, RGB(1, 1, 1));
	dir_b6.LoadBitmapByString({ "resources/runState/stage10/dir6_bubble.bmp" }, RGB(1, 1, 1));
	dir_b7.LoadBitmapByString({ "resources/runState/stage10/dir7_bubble.bmp" }, RGB(1, 1, 1));
	dir_m1.LoadBitmapByString({ "resources/runState/stage10/dir1_meow.bmp" }, RGB(1, 1, 1));
	dir_m2.LoadBitmapByString({ "resources/runState/stage10/dir2_meow.bmp" }, RGB(1, 1, 1));
	dir_m3.LoadBitmapByString({ "resources/runState/stage10/dir3_meow.bmp" }, RGB(1, 1, 1));
	dir_m4.LoadBitmapByString({ "resources/runState/stage10/dir4_meow.bmp" }, RGB(1, 1, 1));
	dir_m5.LoadBitmapByString({ "resources/runState/stage10/dir5_meow.bmp" }, RGB(1, 1, 1));
	dir_m6.LoadBitmapByString({ "resources/runState/stage10/dir6_meow.bmp" }, RGB(1, 1, 1));
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
		for (int i = 0; i < 10; i++) {
			if (point.x > Levels[i].GetLeft() && point.x <= Levels[i].GetLeft() + Levels[i].GetWidth() - 20) {
				if (point.y > Levels[i].GetTop() + 15 && point.y <= Levels[i].GetTop() + Levels[i].GetHeight() - 20) {
					isChoose = true;
					phase = i + 1;
					//把狀態還原到選擇的關卡
					isRestart = true;
					isCharacterMove = false;
					isStart = false;
					if (phase == 1) {
						Level1_init();
					}
					else if (phase == 2) {
						Level2_init();
					}
					/*第三關點擊*/
					else if (phase == 3) {
						Level3_init();
					}
					else if (phase == 4) {
						Level4_init();
						isCharacterMove = false;
						isCharacterMove_b = false;
					}
					/*第5關點擊*/
					else if (phase == 5) {
						Level5_init();
					}
					else if (phase == 6) {
						Level6_init();
					}
					else if (phase == 7) {
						Level7_init();
					}
					else if (phase == 8) {
						Level8_init();
					}
					else if (phase == 9) {
						Level9_init();
					}
					else if (phase == 10) {
						isMovingUp_b = true;
						isMovingDown_b = false;
						isMovingLeft_b = false;
						isMovingRight_b = false;
						Level10_init();
					}
					//要把start位置調整回去,音樂按鈕選擇調回去，音樂切換到開始
					start.SetTopLeft(697, 12);
					start_1.SetTopLeft(702, 12);
					musicButton_play.SetFrameIndexOfBitmap(0);
					CAudio::Instance()->Stop(AUDIO_START_BGM);
					if (isBGMPlay) {
						//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM);
					}
					//CAudio::Instance()->Play(AUDIO_BUTTON);
				}
			}
		}
	
		// 關卡選擇音樂按鈕切換
		if (point.x > musicButton_play.GetLeft() + 25 && point.x <= musicButton_play.GetLeft() + musicButton_play.GetWidth() - 25) {
			if (point.y > musicButton_play.GetTop() + 15 && point.y <= musicButton_play.GetTop() + musicButton_play.GetHeight() - 20) {
				if (!isBGMPlay) {
					CAudio::Instance()->Resume();
					// CAudio::Instance()->Play(AUDIO_BUTTON);
					isBGMPlay = true;
				}
				else {
					//CAudio::Instance()->Play(AUDIO_BUTTON);
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
				if (isBGMPlay) {
					CAudio::Instance()->Play(AUDIO_BUTTON);
					CAudio::Instance()->Play(AUDIO_START_BGM);
				}
			}
		}
		// 點擊重新開始或開始
		if (point.x > 697 + 25 && point.x <= 697 + start.GetWidth() - 25) {
			if (point.y > 12 + 15 && point.y <= 12 + start.GetHeight() - 20) {
				if (!isStart && !pass) {
					isCharacterMove = true;
					if (phase == 4)
					{
						isCharacterMove = true;
						isCharacterMove_b = true;
					}
					if (phase == 6)
					{
						isCharacterMove = true;
						isCharacterMove_b = true;
						isCharacterMove_meow = true;
					}
					if (phase == 7)
					{
						isCharacterMove = true;
						isCharacterMove_b = true;
						isCharacterMove_meow = true;
					}
					if (phase == 8) {
						isCharacterMove = true;
					}
					if (phase == 10)
					{
						isCharacterMove = true;
						isCharacterMove_b = true;
						isCharacterMove_meow = true;
					}
					isStart = true;
				}
				else if (isStart && !pass) { //在該關重新開始(bool 回到初始值)
					isRestart = true;
					isCharacterMove = false;
					isStart = false;
					if (phase == 1)
						Level1_init();
					else if (phase == 2)
						Level2_init();
					else if (phase == 3)
						Level3_init();
					else if (phase == 4)
						Level4_init();
					else if (phase == 5)
						Level5_init();
					else if (phase == 6)
						Level6_init();
					else if (phase == 7)
						Level7_init();
					else if (phase == 8)
						Level8_init();
					else if (phase == 9)
						Level9_init();
					else if (phase == 10)
						Level10_init();
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
		//設定第三關點擊dir1,dir2就可讓dir1,dir2跟著滑鼠位置移動
		if (!isStart && !pass && phase == 3) {
			if (point.x > direction_1.GetLeft() && point.x <= direction_1.GetLeft() + direction_1.GetWidth()) {
				if (point.y > direction_1.GetTop() && point.y <= direction_1.GetTop() + direction_1.GetHeight()) {
					dir1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > direction_2.GetLeft() && point.x <= direction_2.GetLeft() + direction_2.GetWidth()) {
				if (point.y > direction_2.GetTop() && point.y <= direction_2.GetTop() + direction_2.GetHeight()) {
					dir2_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dir1_click) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定第四關點擊dirf1,dirf3,dirb1,dirb3就可讓dir跟著滑鼠位置移動
		if (!isStart && !pass && phase == 4) {
			if (point.x > dir_f1.GetLeft() && point.x <= dir_f1.GetLeft() + dir_f1.GetWidth()) {
				if (point.y > dir_f1.GetTop() && point.y <= dir_f1.GetTop() + dir_f1.GetHeight()) {
					dirf1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_f3.GetLeft() && point.x <= dir_f3.GetLeft() + dir_f3.GetWidth()) {
				if (point.y > dir_f3.GetTop() && point.y <= dir_f3.GetTop() + dir_f3.GetHeight()) {
					dirf3_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_b1.GetLeft() && point.x <= dir_b1.GetLeft() + dir_b1.GetWidth()) {
				if (point.y > dir_b1.GetTop() && point.y <= dir_b1.GetTop() + dir_b1.GetHeight()) {
					dirb1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_b3.GetLeft() && point.x <= dir_b3.GetLeft() + dir_b3.GetWidth()) {
				if (point.y > dir_b3.GetTop() && point.y <= dir_b3.GetTop() + dir_b3.GetHeight()) {
					dirb3_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dirf1_click) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirf3_click) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirb1_click) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirb3_click) {
				dir_b3.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//設定第五關點擊dir2就可讓dir2跟著滑鼠位置移動
		if (!isStart && !pass && phase == 5) {
			if (point.x > direction_2.GetLeft() && point.x <= direction_2.GetLeft() + direction_2.GetWidth()) {
				if (point.y > direction_2.GetTop() && point.y <= direction_2.GetTop() + direction_2.GetHeight()) {
					dir2_click = true;
					isDirectionMove = true;
				}
			}
			else if (isDirectionMove && dir1_click) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		// 設定第六關點擊dirf1,dirf3,dirb1,dirb3就可讓dir跟著滑鼠位置移動
		if (!isStart && !pass && phase == 6) {
			if (point.x > direction_1.GetLeft() && point.x <= direction_1.GetLeft() + direction_1.GetWidth()) {
				if (point.y > direction_1.GetTop() && point.y <= direction_1.GetTop() + direction_1.GetHeight()) {
					dir1_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		// 設定第七關點擊dirf1,dirf3,dirb1,dirb3就可讓dir跟著滑鼠位置移動
		if (!isStart && !pass && phase == 7) {
			if (point.x > dir_f1.GetLeft() && point.x <= dir_f1.GetLeft() + dir_f1.GetWidth()) {
				if (point.y > dir_f1.GetTop() && point.y <= dir_f1.GetTop() + dir_f1.GetHeight()) {
					dirf1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_f2.GetLeft() && point.x <= dir_f2.GetLeft() + dir_f2.GetWidth()) {
				if (point.y > dir_f2.GetTop() && point.y <= dir_f2.GetTop() + dir_f2.GetHeight()) {
					dirf2_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dirf1_click) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
			}
			if (isDirectionMove && dirf2_click) {
				dir_f2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//第八
		if (!isStart && !pass && phase == 8) {
			if (point.x > direction_1.GetLeft() + 25 && point.x <= direction_1.GetLeft() + direction_1.GetWidth() - 25) {
				if (point.y > direction_1.GetTop() + 15 && point.y <= direction_1.GetTop() + direction_1.GetHeight() - 20) {
					isDirectionMove = true;
				}
			}
			if (isDirectionMove) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//第九關
		if (!isStart && !pass && phase == 9) {
			if (point.x > direction_1.GetLeft() && point.x <= direction_1.GetLeft() + direction_1.GetWidth()) {
				if (point.y > direction_1.GetTop() && point.y <= direction_1.GetTop() + direction_1.GetHeight()) {
					dir1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_f1.GetLeft() && point.x <= dir_f1.GetLeft() + dir_f1.GetWidth()) {
				if (point.y > dir_f1.GetTop() && point.y <= dir_f1.GetTop() + dir_f1.GetHeight()) {
					dirf1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_f3.GetLeft() && point.x <= dir_f3.GetLeft() + dir_f3.GetWidth()) {
				if (point.y > dir_f3.GetTop() && point.y <= dir_f3.GetTop() + dir_f3.GetHeight()) {
					dirf3_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirf1_click) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirf3_click) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		//第十關
		if (!isStart && !pass && phase == 10) {
			if (point.x > direction_1.GetLeft() && point.x <= direction_1.GetLeft() + direction_1.GetWidth()) {
				if (point.y > direction_1.GetTop() && point.y <= direction_1.GetTop() + direction_1.GetHeight()) {
					dir1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_b1.GetLeft() && point.x <= dir_b1.GetLeft() + dir_b1.GetWidth()) {
				if (point.y > dir_b1.GetTop() && point.y <= dir_b1.GetTop() + dir_b1.GetHeight()) {
					dirb1_click = true;
					isDirectionMove = true;
				}
			}
			if (point.x > dir_m6.GetLeft() && point.x <= dir_m6.GetLeft() + dir_m6.GetWidth()) {
				if (point.y > dir_m6.GetTop() && point.y <= dir_m6.GetTop() + dir_m6.GetHeight()) {
					dirm6_click = true;
					isDirectionMove = true;
				}
			}
			if (isDirectionMove && dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirb1_click) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (isDirectionMove && dirm6_click) {
				dir_m6.SetTopLeft(point.x - 25, point.y - 15);
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
						Level1_init();
					}
					else if (phase == 2) {
						Level2_init();
					}
					else if (phase == 3) {
						Level3_init();
					}
					else if (phase == 4) {
						Level4_init();
					}
					else if (phase == 5) {
						Level5_init();
					}
					else if (phase == 6) {
						Level6_init();
					}
					else if (phase == 7) {
						Level7_init();
					}
					if (isBGMPlay) {
						CAudio::Instance()->Play(AUDIO_BUTTON);
						//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //關卡重新開始並撥放音樂
					}
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
						Level2_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					else if (phase == 3) {
						Level3_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					else if (phase == 4) {
						Level4_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					else if (phase == 5) {
						Level5_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					else if (phase == 6) {
						Level6_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					else if (phase == 7) {
						Level7_init();
						CAudio::Instance()->Pause();
						if (isBGMPlay) {
							CAudio::Instance()->Play(AUDIO_BUTTON);
							//CAudio::Instance()->Play(AUDIO_RUNSTATE_BGM); //切換到關卡開始畫面撥放另一音樂
						}
					}
					
				}
			}
			//切換音樂(音樂還未做)
			if (point.x > musicButton_play.GetLeft() + 25 && point.x <= musicButton_play.GetLeft() + musicButton_play.GetWidth() - 25) {
				if (point.y > musicButton_play.GetTop() + 15 && point.y <= musicButton_play.GetTop() + musicButton_play.GetHeight() - 20) {
					if (!isBGMPlay) {
						//CAudio::Instance()->Stop(AUDIO_RUNSTATE_BGM);
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
		else if (phase == 3) {
			// 要知道點擊了哪個dir
			if (dir1_click == true) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				dir1_click = false;
			}
			else if (dir2_click == true) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
				dir2_click = false;
			}
		}
		else if (phase == 4) {
			// 要知道點擊了哪個dir
			if (dirf1_click == true) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
				dirf1_click = false;
			}
			else if (dirf3_click == true) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
				dirf3_click = false;
			}
			else if (dirb1_click == true) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
				dirb1_click = false;
			}
			else if (dirb3_click == true) {
				dir_b3.SetTopLeft(point.x - 25, point.y - 15);
				dirb3_click = false;
			}
		}
		else if (phase == 5) {
			// 要知道點擊了哪個dir
			if (dir2_click == true) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
				dir2_click = false;
			}
		}
		else if (phase == 6) {
			// 要知道點擊了哪個dir
			if (dir1_click == true) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				dir1_click = false;
			}
		}
		else if (phase == 7) {
			// 要知道點擊了哪個dir
			if (dirf1_click == true) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
				dirf1_click = false;
			}
			else if (dirf2_click == true) {
				dir_f2.SetTopLeft(point.x - 25, point.y - 15);
				dirf2_click = false;
			}
		}
		else if (phase == 8) {
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		}
		else if (phase == 9) {
			if (dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				dir1_click = false;
			}
			else if (dirf1_click) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
				dirf1_click = false;
			}
			else if (dirf3_click) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
				dirf3_click = false;
			}
		}
		else if (phase == 10) {
			if (dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				dir1_click = false;
			}
			else if (dirb1_click) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
				dirb1_click = false;
			}
			else if (dirm6_click) {
				dir_m6.SetTopLeft(point.x - 25, point.y - 15);
				dirm6_click = false;
			}
		}
	}
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	if (isDirectionMove) {
		if (phase == 1)
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		else if (phase == 2)
			direction_2.SetTopLeft(point.x - 25, point.y - 15);
		else if (phase == 3) {
			// 要知道點擊了哪個dir
			if (dir1_click == true) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				//dir1_click = false;
			}
			else if (dir2_click == true) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
				//dir2_click = false;
			}
		}
		else if (phase == 4) {
			// 要知道點擊了哪個dir
			if (dirf1_click == true) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
				//dir1_click = false;
			}
			else if (dirf3_click == true) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
				//dir2_click = false;
			}
			else if (dirb1_click == true) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
				//dir1_click = false;
			}
			else if (dirb3_click == true) {
				dir_b3.SetTopLeft(point.x - 25, point.y - 15);
				//dir2_click = false;
			}
		}
		else if (phase == 5) {
			if (dir2_click == true) {
				direction_2.SetTopLeft(point.x - 25, point.y - 15);
				//dir2_click = false;
			}
		}
		else if (phase == 6) {
			if (dir1_click == true) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
				//dir1_click = false;
			}
		}
		else if (phase == 7) {
			if (dirf1_click == true) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (dirf2_click == true) {
				dir_f2.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		else if (phase == 8)
			direction_1.SetTopLeft(point.x - 25, point.y - 15);
		else if (phase == 9) {
			if (dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (dirf1_click) {
				dir_f1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (dirf3_click) {
				dir_f3.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		else if (phase == 10) {
			if (dir1_click) {
				direction_1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (dirb1_click) {
				dir_b1.SetTopLeft(point.x - 25, point.y - 15);
			}
			else if (dirm6_click) {
				dir_m6.SetTopLeft(point.x - 25, point.y - 15);
			}
		}
		
	}
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::Level1_init() {
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
void CGameStateRun::Level2_init() {
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

	direction_1.SetFrameIndexOfBitmap(1);
	direction_2.SetFrameIndexOfBitmap(1);
	stage_num.SetFrameIndexOfBitmap(1);
	exit.SetFrameIndexOfBitmap(1);

	direction_1.SetTopLeft(180, 173);
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
	character2.SetAnimation(300, false);
	times = 0;
	pass = false;
}
void CGameStateRun::Level3_init() {
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
	direction_1.SetFrameIndexOfBitmap(2);
	direction_2.SetFrameIndexOfBitmap(2);
	character3.SetAnimation(300, false);
	direction_1.SetTopLeft(657, 237);
	direction_2.SetTopLeft(657, 358);

	clock.SetTopLeft(380, 193);
	clock_1.SetTopLeft(380, 428);
	clock_2.SetTopLeft(622, 305);
	clock_shelf.SetTopLeft(375, 243);
	clock_1_shelf.SetTopLeft(375, 478);
	clock_2_shelf.SetTopLeft(617, 355);
	exit.SetTopLeft(30, 418);
	block.SetTopLeft(62, 290);
	stage_num.SetFrameIndexOfBitmap(2);
	exit.SetFrameIndexOfBitmap(2);
	times = 0;
	pass = false;
}
void CGameStateRun::Level4_init() {
	exit1.SetTopLeft(430, 90);
	exit2.SetTopLeft(310, 90);
	c1_flower.SetTopLeft(310, 160);
	c1_flower.SetAnimation(300, false);
	c2_bubble.SetTopLeft(430, 170);
	c2_bubble.SetAnimation(300, false);
	
	dir_f1.SetTopLeft(600, 175);//60, 175
	dir_f2.SetTopLeft(60, 473);
	dir_f3.SetTopLeft(420, 305); // 300, 473
	dir_b1.SetTopLeft(122, 175);//660, 175
	dir_b2.SetTopLeft(657, 473);
	dir_b3.SetTopLeft(300, 305);//420, 470
	block1.SetTopLeft(192, 255);
	block2.SetTopLeft(372, 255);
	block3.SetTopLeft(492, 255);

	clock.SetTopLeft(80, 305);
	clock_1.SetTopLeft(680, 125);
	clock_2.SetTopLeft(502, 485);
	clock_shelf.SetTopLeft(75, 355);
	clock_1_shelf.SetTopLeft(675, 175);
	clock_2_shelf.SetTopLeft(497, 535);

	dir1 = false;
	dir2 = false;
	dir3 = false;
	isMovingLeft = true;//花花初始為往左走
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
	// phase4 character initial direction(for bubble)
	isMovingLeft_b = false;
	isMovingRight_b = true;
	isMovingUp_b = false;
	isMovingDown_b = false;
	isCharacterMove_b = false;
	//	phase4 character pass
	f_pass = false; // flower pass
	b_pass = false; // bubble pass

	//	phase4 dir click
	dirf1_click = false;
	dirf3_click = false;
	dirb1_click = false;
	dirb3_click = false;

	dir1_b = false;
	dir2_b = false;
	dir3_b = false;
	dir1_b_f = false; //用於設定初始方向
	dir2_b_f = false;
	dir3_b_f = false;
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
	direction_1.SetFrameIndexOfBitmap(2);
	direction_2.SetFrameIndexOfBitmap(2);
	character3.SetAnimation(300, false);
	direction_1.SetTopLeft(657, 237);
	direction_2.SetTopLeft(657, 358);

	
	exit.SetTopLeft(30, 418);
	stage_num.SetFrameIndexOfBitmap(3);
	exit.SetFrameIndexOfBitmap(2);
	times = 0;
	pass = false;
}
void CGameStateRun::Level5_init() {
	character3.SetTopLeft(130, 480);//dir3 130, 185
	//character.ShowBitmap();
	dir1 = false;
	dir2 = false;
	dir3 = false;
	dir4 = false;
	isMovingLeft = false;//初始為往右走
	isMovingRight = true;
	isMovingUp = false;
	isMovingDown = false;
	isDirectionMove = false;
	//bool isRestart = false;
	dir1_f = false; //用於設定初始方向
	dir2_f = false;
	dir3_f = false;
	dir4_f = false;
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
	direction_1.SetFrameIndexOfBitmap(3);
	direction_2.SetFrameIndexOfBitmap(3);
	direction_3.SetFrameIndexOfBitmap(1);
	character3.SetAnimation(300, false);
	direction_1.SetTopLeft(597, 475);
	direction_2.SetTopLeft(657, 173);
	direction_3.SetTopLeft(120, 173);
	direction_4.SetTopLeft(120, 415);
	clock.SetTopLeft(380, 183);
	clock_1.SetTopLeft(130, 305);
	clock_2.SetTopLeft(622, 305);
	clock_shelf.SetTopLeft(375, 233);
	clock_1_shelf.SetTopLeft(125, 355);
	clock_2_shelf.SetTopLeft(617, 355);
	exit.SetTopLeft(717, 418);
	block.SetFrameIndexOfBitmap(1);
	block.SetTopLeft(318, 245);
	stage_num.SetFrameIndexOfBitmap(4);
	exit.SetFrameIndexOfBitmap(3);
	times = 0;
	pass = false;
}
void CGameStateRun::Level6_init() {
	isCharacterMove = false;
	isCharacterMove_b = false;
	isCharacterMove_meow = false;
	//重設各角色移動方向
	isMovingUp = true;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;

	isMovingUp_b = false;
	isMovingDown_b = false;
	isMovingLeft_b = false;
	isMovingRight_b = true;

	isMovingUp_meow = true;
	isMovingDown_meow = false;
	isMovingLeft_meow = false;
	isMovingRight_meow = false;

	exit1.SetTopLeft(720, 305);
	exit1.SetFrameIndexOfBitmap(1);
	exit2.SetFrameIndexOfBitmap(0);
	exit2.SetTopLeft(260, 90);
	exit3.SetTopLeft(485, 90);

	ch1_flower.SetTopLeft(260, 453);
	ch1_flower.SetAnimation(300, false);
	ch2_bubble.SetTopLeft(70, 300);
	ch2_bubble.SetAnimation(300, false);
	ch3_meow.SetTopLeft(500, 473);
	ch3_meow.SetAnimation(300, false);
	direction_1.SetFrameIndexOfBitmap(4);
	direction_1.SetTopLeft(360, 175);
	block1.SetFrameIndexOfBitmap(1);
	block2.SetFrameIndexOfBitmap(1);
	block3.SetFrameIndexOfBitmap(1);
	block1.SetTopLeft(192, 245);
	block2.SetTopLeft(322, 245);
	block3.SetTopLeft(552, 245);
	block4.SetTopLeft(192, 365);
	block5.SetTopLeft(322, 365);
	block6.SetTopLeft(552, 365);

	clock.SetTopLeft(260, 185);
	clock_1.SetTopLeft(500, 185);
	clock_2.SetTopLeft(620, 305);
	clock_shelf.SetTopLeft(255, 235);
	clock_1_shelf.SetTopLeft(495, 235);
	clock_2_shelf.SetTopLeft(615, 355);

	dir1 = false;
	dir1_b = false;
	dir1_m = false;
	dir1_f = false;
	dir1_b_f = false;
	dir1_m_f = false;
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
	character3.SetAnimation(300, false);


	//exit.SetTopLeft(30, 418);
	stage_num.SetFrameIndexOfBitmap(5);
	exit.SetFrameIndexOfBitmap(2);
	times = 0;
	pass = false;
	f_pass = false;
	m_pass = false;
	b_pass = false;
}
void CGameStateRun::Level7_init() {
	isCharacterMove = false;
	isCharacterMove_b = false;
	isCharacterMove_meow = false;
	//重設各角色移動方向
	isMovingUp = false;
	isMovingDown = false;
	isMovingLeft = true;
	isMovingRight = false;

	isMovingUp_b = false;
	isMovingDown_b = false;
	isMovingLeft_b = true;
	isMovingRight_b = false;

	isMovingUp_meow = false;
	isMovingDown_meow = false;
	isMovingLeft_meow = true;
	isMovingRight_meow = false;

	exit1.SetTopLeft(39, 300);
	exit1.SetFrameIndexOfBitmap(2);
	exit2.SetFrameIndexOfBitmap(1);
	exit2.SetTopLeft(39, 238);
	exit3.SetTopLeft(180, 90);

	cha1_flower.SetTopLeft(610, 210);
	cha1_flower.SetAnimation(300, false);
	cha2_bubble.SetTopLeft(595, 290);
	cha2_bubble.SetAnimation(300, false);
	cha3_meow.SetTopLeft(605, 360);
	cha3_meow.SetAnimation(300, false);
	dir_f1.SetFrameIndexOfBitmap(1);
	dir_f1.SetTopLeft(355, 175);
	dir_f2.SetFrameIndexOfBitmap(1);
	dir_f2.SetTopLeft(415, 175);
	dir_f3.SetFrameIndexOfBitmap(1);
	dir_f3.SetTopLeft(181, 235);
	dir_b1.SetFrameIndexOfBitmap(1);
	dir_b1.SetTopLeft(181, 295);
	dir_b2.SetFrameIndexOfBitmap(1);
	dir_b2.SetTopLeft(181, 355);

	clock.SetTopLeft(201, 185);
	clock_1.SetTopLeft(141, 245);
	clock_2.SetTopLeft(141, 310);
	clock_shelf.SetTopLeft(196, 235);
	clock_1_shelf.SetTopLeft(136, 295);
	clock_2_shelf.SetTopLeft(136, 360);

	dir1 = false;
	dir1_b = false;
	dir1_m = false;
	dir1_f = false;
	dir1_b_f = false;
	dir1_m_f = false;

	dir2 = false;
	dir2_b = false;
	dir2_m = false;
	dir2_f = false;
	dir2_b_f = false;
	dir2_m_f = false;

	dir3 = false;
	dir3_b = false;
	dir3_m = false;
	dir3_f = false;
	dir3_b_f = false;
	dir3_m_f = false;

	dir4 = false;
	dir4_b = false;
	dir4_m = false;
	dir4_f = false;
	dir4_b_f = false;
	dir4_m_f = false;

	dir5 = false;
	dir5_b = false;
	dir5_m = false;
	dir5_f = false;
	dir5_b_f = false;
	dir5_m_f = false;

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
	character3.SetAnimation(300, false);


	//exit.SetTopLeft(30, 418);
	stage_num.SetFrameIndexOfBitmap(6);
	exit.SetFrameIndexOfBitmap(2);
	times = 0;
	pass = false;
	f_pass = false;
	m_pass = false;
	b_pass = false;
}
void CGameStateRun::Level8_init() {
	pass = false;
	isMovingRight = true;
	isMovingLeft = false;
	isMovingUp = false;
	isMovingDown = false;
	ch2_bubble.SetTopLeft(120, 418);
	ch2_bubble.SetAnimation(300, false);
	block.SetFrameIndexOfBitmap(1);
	block.SetTopLeft(195, 245);
	block1.SetFrameIndexOfBitmap(2);
	block1.SetTopLeft(436, 245);
	direction_1.SetTopLeft(362, 293); //597 475
	direction_1.SetFrameIndexOfBitmap(5);
	direction_2.SetTopLeft(360, 473);
	direction_2.SetFrameIndexOfBitmap(4);
	direction_3.SetTopLeft(660, 470);
	direction_3.SetFrameIndexOfBitmap(2);
	direction_4.SetTopLeft(658, 170);
	direction_4.SetFrameIndexOfBitmap(1);
	//character2.SetTopLeft(350, 418);
	//character.ShowBitmap();
	dir1 = false;
	dir2 = false;
	dir3 = false;
	dir4 = false;
	isMovingLeft = true;//初始為往左走
	isMovingRight = false;
	isMovingUp = false;
	isMovingDown = false;
	isDirectionMove = false;
	//bool isRestart = false;
	dir1_f = false; //用於設定初始方向
	dir2_f = false;
	dir3_f = false;
	dir4_f = false;
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

	stage_num.SetFrameIndexOfBitmap(7);
	exit.SetFrameIndexOfBitmap(4);

	clock_shelf.SetTopLeft(75, 533);
	clock_1_shelf.SetTopLeft(375, 175);
	clock_2_shelf.SetTopLeft(675, 355);
	clock.SetTopLeft(80, 483);
	clock_1.SetTopLeft(380, 125);
	clock_2.SetTopLeft(680, 305);
	exit.SetTopLeft(40, 180);
	//character2.SetAnimation(300, false);
	times = 0;
	pass = false;
}
void CGameStateRun::Level9_init() {
	clock.SetTopLeft(378, 425);
	clock_1.SetTopLeft(383, 125);
	clock_2.SetTopLeft(620, 243);
	character.SetTopLeft(125, 470);

	block1.SetFrameIndexOfBitmap(3);
	block1.SetTopLeft(73, 365);
	block2.SetFrameIndexOfBitmap(2);
	block2.SetTopLeft(313, 187);
	block3.SetFrameIndexOfBitmap(2);
	block3.SetTopLeft(490, 365);

	dir1 = false;
	dir2 = false;
	dir3 = false;
	dir4 = false;
	dir5 = false;
	dir1_f = false; //用於設定初始方向
	dir2_f = false;
	dir3_f = false;
	dir4_f = false;
	dir5_f = false;

	isMovingLeft = false;
	isMovingRight = true;
	isMovingUp = false;
	isMovingDown = false;
	isDirectionMove = false;
	//bool isRestart = false;
	
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
	clock_shelf.SetTopLeft(372, 475);
	clock_1_shelf.SetTopLeft(378, 175);
	clock_2_shelf.SetTopLeft(615, 293);
	start.SetTopLeft(697, 12);
	start_1.SetTopLeft(702, 12);
	restart_1.SetTopLeft(697, 12);
	restart_2.SetTopLeft(700, 19);
	background_stars.SetFrameIndexOfBitmap(0);
	background_stars.SetTopLeft(0, -605);
	background_stars.ShowBitmap();
	
	exit.SetFrameIndexOfBitmap(5);
	exit.SetTopLeft(135, 93);

	direction_1.SetFrameIndexOfBitmap(6);
	direction_1.SetTopLeft(540, 472);
	direction_2.SetFrameIndexOfBitmap(5);
	direction_2.SetTopLeft(358, 295);
	dir_f1.SetFrameIndexOfBitmap(2);
	dir_f1.SetTopLeft(655, 290);//60, 175
	dir_f2.SetFrameIndexOfBitmap(2);
	dir_f2.SetTopLeft(600, 115);
	dir_f3.SetFrameIndexOfBitmap(2);
	dir_f3.SetTopLeft(62, 175); // 300, 473

	stage_num.SetFrameIndexOfBitmap(8);
	times = 0;
	pass = false;
}
void CGameStateRun::Level10_init() {
	isCharacterMove = false;
	isCharacterMove_b = false;
	isCharacterMove_meow = false;
	//重設各角色移動方向
	isMovingUp = true;
	isMovingDown = false;
	isMovingLeft = false;
	isMovingRight = false;

	isMovingUp_b = true;
	isMovingDown_b = false;
	isMovingLeft_b = false;
	isMovingRight_b = false;

	isMovingUp_meow = false;
	isMovingDown_meow = false;
	isMovingLeft_meow = false;
	isMovingRight_meow = true;

	exit1.SetTopLeft(729, 420);
	exit1.SetFrameIndexOfBitmap(3);
	exit2.SetFrameIndexOfBitmap(2);
	exit2.SetTopLeft(727, 182);
	exit3.SetFrameIndexOfBitmap(1);
	exit3.SetTopLeft(723, 300);

	ch1_flower.SetTopLeft(300, 455);
	ch1_flower.SetAnimation(300, false);
	ch2_bubble.SetTopLeft(70, 470);
	ch2_bubble.SetAnimation(300, false);
	ch3_meow.SetTopLeft(70, 120);
	ch3_meow.SetAnimation(300, false);
	direction_1.SetFrameIndexOfBitmap(7);
	direction_1.SetTopLeft(60, 294);
	direction_2.SetFrameIndexOfBitmap(6);
	direction_2.SetTopLeft(418, 235);
	dir_f1.SetFrameIndexOfBitmap(3);
	dir_f1.SetTopLeft(419, 115);
	dir_f2.SetFrameIndexOfBitmap(3);
	dir_f2.SetTopLeft(661, 115);
	dir_f3.SetFrameIndexOfBitmap(3);
	dir_f3.SetTopLeft(658, 175);

	dir_b1.SetFrameIndexOfBitmap(2);
	dir_b1.SetTopLeft(60, 234);
	dir_b2.SetFrameIndexOfBitmap(2);
	dir_b2.SetTopLeft(302, 350);
	dir_b3.SetFrameIndexOfBitmap(1);
	dir_b3.SetTopLeft(299, 117);
	dir_b4.SetTopLeft(542, 112);
	dir_b5.SetTopLeft(539, 474);
	dir_b6.SetTopLeft(659, 471);
	dir_b7.SetTopLeft(656, 413);

	//dir_m6.SetTopLeft(160, 356);
	dir_m1.SetTopLeft(177, 115);
	dir_m2.SetTopLeft(177, 473);
	dir_m3.SetTopLeft(416, 473);
	dir_m4.SetTopLeft(416, 350);
	dir_m5.SetTopLeft(657, 350);
	dir_m6.SetTopLeft(60, 356);
	clock.SetFrameIndexOfBitmap(1);
	clock.SetTopLeft(377, 245);
	clock_1.SetFrameIndexOfBitmap(1);
	clock_1.SetTopLeft(560, 185);
	clock_2.SetFrameIndexOfBitmap(1);
	clock_2.SetTopLeft(498, 365);
	clock_shelf.SetTopLeft(377, 295);
	clock_1_shelf.SetTopLeft(555, 235);
	clock_2_shelf.SetTopLeft(496, 415);

	dir1 = false;
	dir1_b = false;
	dir1_m = false;
	dir1_f = false;
	dir1_b_f = false;
	dir1_m_f = false;

	dir2 = false;
	dir2_b = false;
	dir2_m = false;
	dir2_f = false;
	dir2_b_f = false;
	dir2_m_f = false;

	dir3 = false;
	dir3_b = false;
	dir3_m = false;
	dir3_f = false;
	dir3_b_f = false;
	dir3_m_f = false;

	dir4 = false;
	dir4_b = false;
	dir4_m = false;
	dir4_f = false;
	dir4_b_f = false;
	dir4_m_f = false;

	dir5 = false;
	dir5_b = false;
	dir5_m = false;
	dir5_f = false;
	dir5_b_f = false;
	dir5_m_f = false;

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
	character3.SetAnimation(300, false);


	//exit.SetTopLeft(30, 418);
	stage_num.SetFrameIndexOfBitmap(9);
	exit.SetFrameIndexOfBitmap(3);
	times = 0;
	pass = false;
	pass_num = 0;
	f_add = false;
	b_add = false;
	m_add = false;
	f_pass = false;
	m_pass = false;
	b_pass = false;
	for (int i = 0; i < 15; i++) {
		blocks[i].SetTopLeft(130 + (120 * (i % 5)), 185 + 120 * int(i / 5));
	}
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
			
			/*background_stars.SetFrameIndexOfBitmap(0);
			background_stars.SetTopLeft(0, -605);
			background_stars.ShowBitmap();
			direction_1.SetFrameIndexOfBitmap(1);
			direction_2.SetFrameIndexOfBitmap(1);*/
			//character2.SetAnimation(300, false);
			background_stars.ShowBitmap();
			onCloudsMove();
			stage.ShowBitmap();
			//stage_num.SetFrameIndexOfBitmap(1);
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
			//exit.SetFrameIndexOfBitmap(1);

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
			//character2.SetAnimation(300, false);
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
		//direction_3.ShowBitmap();
		

		exit.ShowBitmap();
		block.ShowBitmap();
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
		block.ShowBitmap();
		character3.SetAnimation(300, false);
		character3.ShowBitmap(0.7);
		//character.ShowBitmap(0.7);
		//character.SetAnimation(300, false);
		show_text_by_phase();
	}
	}
	else if (phase == 4) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
			//clock.SetTopLeft(380, 193);
			//clock_1.SetTopLeft(380, 428);
			//clock_2.SetTopLeft(622, 305);
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
		block1.ShowBitmap(0.7);
		block2.ShowBitmap(0.7);
		block3.ShowBitmap(0.7);
		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();
		dir_b3.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		c1_flower.ShowBitmap(0.7);
		c2_bubble.ShowBitmap(0.7);
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

		block1.ShowBitmap(0.7);
		block2.ShowBitmap(0.7);
		block3.ShowBitmap(0.7);
		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();
		dir_b3.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		
		if (!f_pass)
			c1_flower.ShowBitmap(0.7);
		if (!b_pass)
			c2_bubble.ShowBitmap(0.7);
		show_text_by_phase();
	}
	}
	else if (phase == 5) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
			//clock.SetTopLeft(380, 193);
			//clock_1.SetTopLeft(380, 428);
			//clock_2.SetTopLeft(622, 305);
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
		direction_3.ShowBitmap();
		direction_4.ShowBitmap();


		exit.ShowBitmap();
		block.ShowBitmap();
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
		direction_3.ShowBitmap();
		direction_4.ShowBitmap();
		//direction_3.ShowBitmap();
		exit.ShowBitmap();
		block.ShowBitmap();
		character3.SetAnimation(300, false);
		character3.ShowBitmap(0.7);
		//character.ShowBitmap(0.7);
		//character.SetAnimation(300, false);
		show_text_by_phase();
	}
	}
	else if (phase == 6) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
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
		block1.ShowBitmap();
		block2.ShowBitmap(0.7);
		block3.ShowBitmap();
		block4.ShowBitmap();
		block5.ShowBitmap(0.7);
		block6.ShowBitmap();

		direction_1.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);

		ch1_flower.ShowBitmap(0.7);
		ch2_bubble.ShowBitmap(0.7);
		ch3_meow.ShowBitmap(0.7);
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

		block1.ShowBitmap();
		block2.ShowBitmap(0.7);
		block3.ShowBitmap();
		block4.ShowBitmap();
		block5.ShowBitmap(0.7);
		block6.ShowBitmap();

		direction_1.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);
		if(!f_pass)
			ch1_flower.ShowBitmap(0.7);
		if(!b_pass)
			ch2_bubble.ShowBitmap(0.7);
		if(!m_pass)
			ch3_meow.ShowBitmap(0.7);
	}
	}
	else if (phase == 7) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
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

		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);

		cha1_flower.ShowBitmap(0.7);
		cha2_bubble.ShowBitmap(0.7);
		cha3_meow.ShowBitmap(0.7);
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

		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);
		if (!f_pass)
			cha1_flower.ShowBitmap(0.7);
		if (!b_pass)
			cha2_bubble.ShowBitmap(0.7);
		if (!m_pass)
			cha3_meow.ShowBitmap(0.7);
	}
	}
	else if (phase == 8) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
			//clock.SetTopLeft(200, 428);
			//clock_1.SetTopLeft(380, 125);
			//clock_2.SetTopLeft(560, 305);
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
		direction_3.ShowBitmap();
		direction_4.ShowBitmap();
		//exit.SetFrameIndexOfBitmap(1);

		exit.ShowBitmap();
		block.ShowBitmap();
		block1.ShowBitmap();
		//character.SetTopLeft(185, 403);
		ch2_bubble.ShowBitmap(0.7);
	
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
		direction_4.ShowBitmap();

		block.ShowBitmap();
		block1.ShowBitmap();
		exit.ShowBitmap();
		ch2_bubble.ShowBitmap(0.7);
		//character2.SetAnimation(300, false);
		//character.ShowBitmap(0.7);
		//character.SetAnimation(300, false);
		show_text_by_phase();
	}
	}
	else if (phase == 9) {
		if (!isStart) { //重啟或剛開始
			if (isRestart) {
				isRestart = false;
				//clock.SetTopLeft(358, 415);
				//clock_1.SetTopLeft(500, 193);
				//clock_2.SetTopLeft(620, 193);
				//direction_1.SetFrameIndexOfBitmap(0);
				//direction_2.SetFrameIndexOfBitmap(0);
				//stage_num.SetFrameIndexOfBitmap(0);
				//exit.SetFrameIndexOfBitmap(0);
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
			block1.ShowBitmap();
			block2.ShowBitmap();
			block3.ShowBitmap();
			direction_1.ShowBitmap();
			direction_2.ShowBitmap();
			dir_f1.ShowBitmap();
			dir_f2.ShowBitmap();
			dir_f3.ShowBitmap();
			exit.ShowBitmap();
			character.ShowBitmap(0.6);
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
			block1.ShowBitmap();
			block2.ShowBitmap();
			block3.ShowBitmap();
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
			dir_f1.ShowBitmap();
			dir_f2.ShowBitmap();
			dir_f3.ShowBitmap();
			exit.ShowBitmap();
			character.ShowBitmap(0.6);
			character.SetAnimation(300, false);
			show_text_by_phase();
		}
	}
	else if (phase == 10) {
	if (!isStart) { //重啟或剛開始；角色開始移動前畫面
		if (isRestart) {
			isRestart = false;
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

		clock.ShowBitmap(0.8);
		clock_shelf.ShowBitmap();
		clock_1.ShowBitmap(0.8);
		clock_1_shelf.ShowBitmap();
		clock_2.ShowBitmap(0.8);
		clock_2_shelf.ShowBitmap();

		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);
		//第十關
		for (int i = 0; i < 15; i++) {
			blocks[i].ShowBitmap();
		}
		direction_1.ShowBitmap();
		direction_2.ShowBitmap();
		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();
		dir_b3.ShowBitmap();
		dir_b4.ShowBitmap();
		dir_b5.ShowBitmap();
		dir_b6.ShowBitmap();
		dir_b7.ShowBitmap();

		dir_m1.ShowBitmap();
		dir_m2.ShowBitmap();
		dir_m3.ShowBitmap();
		dir_m4.ShowBitmap();
		dir_m5.ShowBitmap();
		dir_m6.ShowBitmap();

		ch1_flower.ShowBitmap(0.6);
		ch2_bubble.ShowBitmap(0.6);
		ch3_meow.ShowBitmap(0.6);
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
		clock.ShowBitmap(0.8);
		clock_1.ShowBitmap(0.8);
		clock_2.ShowBitmap(0.8);
		exit1.ShowBitmap(1.1);
		exit2.ShowBitmap(1.2);
		exit3.ShowBitmap(1.1);
		//第十關
		for (int i = 0; i < 15; i++) {
			blocks[i].ShowBitmap();
		}
		direction_1.ShowBitmap();
		direction_2.ShowBitmap();
		dir_f1.ShowBitmap();
		dir_f2.ShowBitmap();
		dir_f3.ShowBitmap();
		dir_b1.ShowBitmap();
		dir_b2.ShowBitmap();
		dir_b3.ShowBitmap();
		dir_b4.ShowBitmap();
		dir_b5.ShowBitmap();
		dir_b6.ShowBitmap();
		dir_b7.ShowBitmap();

		dir_m1.ShowBitmap();
		dir_m2.ShowBitmap();
		dir_m3.ShowBitmap();
		dir_m4.ShowBitmap();
		dir_m5.ShowBitmap();
		dir_m6.ShowBitmap();

		if (!f_pass)
			ch1_flower.ShowBitmap(0.6);
		if (!b_pass)
			ch2_bubble.ShowBitmap(0.6);
		if (!m_pass)
			ch3_meow.ShowBitmap(0.6);
		onCharacterMove();
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
			if (i + 1 <= 10) {
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
	//phase = 3;
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
			//顯示過關畫面
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 3) {
			//times = 0;
			if (!pass)
				show_image_unpass();
			//顯示過關畫面
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 4) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 5) {
			//times = 0;
			if (!pass)
				show_image_unpass();
			//顯示過關畫面
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 6) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 7) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 8) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 9) {
			if (!pass)
				show_image_unpass();
			//顯示過關畫面(未完成)
			else if (pass) {
				show_image_pass();
			}
		}
		else if (phase == 10) {
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
	if (phase <= 10) {
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
	//return character.GetImageFileName() == "resources/giraffe.bmp";
	return false;
}

bool CGameStateRun::validate_phase_2() {
	return false;
	//return character.GetTop() > 204 && character.GetTop() < 325 && character.GetLeft() > 339 && character.GetLeft() < 459;
}

bool CGameStateRun::validate_phase_3() {
	return false;
	/*return (
		character.GetTop() + character.GetHeight() >= chest_and_key.GetTop()
		&& character.GetLeft() + character.GetWidth() >= chest_and_key.GetLeft()
		&& chest_and_key.GetFrameIndexOfBitmap() == 1
		&& chest_and_key.GetFilterColor() == RGB(255, 255, 255)
		);*/
}

bool CGameStateRun::validate_phase_4() {
	return false;
	//return bee.IsAnimation() && bee.GetFrameSizeOfBitmap() == 2;
}

bool CGameStateRun::validate_phase_5() {
	return false;
	/*bool check_all_door_is_open = true;
	for (int i = 0; i < 3; i++) {
		check_all_door_is_open &= (door[i].GetFrameIndexOfBitmap() == 1);
	}
	return check_all_door_is_open;*/
}

bool CGameStateRun::validate_phase_6() {
	return false;
	//return ball.IsAnimationDone() && !ball.IsAnimation();
}