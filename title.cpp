#include"title.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"XInput.h"
#include"main.h"
#include"debug_font.h"

static float cursorPos = PosGame;
static float t = 0;
static float posX = 0;
static float posY = 0;
static int i = 0;
static int add = 1;
static int cnt = 0;


void TitleInit() {
	
}

void TitleUpdate() {
	cnt += 1;
	if (cnt >= 30) {
		cnt = 0;
		if (i >= 255 || i <= 0) {
		add *= -1;
	    }
		i += add;
	}
	
	

	//ƒJ[ƒ\ƒ‹‚ÌˆÚ“®
	bool XinputRightJoystickDown(int direction);
	if (Keyboard_IsTrigger(DIK_D) || Keyboard_IsTrigger(DIK_RIGHTARROW) || XinputPressButtonDown(RIGHT_BUTTON)) {
		if (cursorPos == PosGame) {
			cursorPos = PosDate;

		}
		else {
			cursorPos--;
		}
	}
	else if (Keyboard_IsTrigger(DIK_A) || Keyboard_IsTrigger(DIK_LEFTARROW) || XinputPressButtonDown(LEFT_BUTTON)) {
		if (cursorPos == PosDate) {
			cursorPos = PosGame;

		}
		else {
			cursorPos++;
		}
	}

	//EnterKey‚ð‰Ÿ‚µ‚½Žž‚Ì”»’è
	if (Keyboard_IsTrigger(DIK_RETURN) || XinputPressButtonDown(B_BUTTON)) {
		switch ((int)cursorPos) {
		case PosGame:
			SetScene(GAME);
			break;

		case PosOption:
			//SetScene(OPTION);
			break;

		case PosDate:
			//SetScene(Exsit);
			break;
		}
	}

}

void TitleDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_TITLE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_TITLE1, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, i));
	if (cursorPos == PosGame) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}
	if (cursorPos == PosOption) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 - 360, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}
	if (cursorPos == PosDate) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 + 120, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_SELECT, 180, SCREEN_HEIGHT / 2 + 160, 0, 0, 640, 33);

}

void TitleUnInit() {
}