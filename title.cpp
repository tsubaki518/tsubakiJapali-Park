#include"title.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"XInput.h"
#include"main.h"
#include"debug_font.h"

static float cursorPos = PosGame;
float t = 0;
float posX = 0;
float posY = 0;

void TitleInit() {
	
}

void TitleUpdate() {

	//ÉJÅ[É\ÉãÇÃà⁄ìÆ
	bool XinputRightJoystickDown(int direction);
	if (Keyboard_IsTrigger(DIK_A) || Keyboard_IsTrigger(DIK_LEFTARROW) || XinputPressButtonDown(LEFT_BUTTON)) {
		if (cursorPos == PosGame) {
			cursorPos = PosDate;

		}
		else {
			cursorPos--;
		}
	}
	else if (Keyboard_IsTrigger(DIK_D) || Keyboard_IsTrigger(DIK_RIGHTARROW) || XinputPressButtonDown(RIGHT_BUTTON)) {
		if (cursorPos == PosDate) {
			cursorPos = PosGame;

		}
		else {
			cursorPos++;
		}
	}

	//EnterKeyÇâüÇµÇΩéûÇÃîªíË
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
	DebugFont_Draw(SCREEN_WIDTH / 2 -50, SCREEN_HEIGHT / 2 + 120, "START");
	DebugFont_Draw(SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2 + 120, "OPTIONS");
	DebugFont_Draw(SCREEN_WIDTH / 2 + 200, SCREEN_HEIGHT / 2 + 120, "DATEBASE");

}

void TitleUnInit() {

}