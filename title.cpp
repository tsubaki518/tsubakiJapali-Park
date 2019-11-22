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

void TitleInit() {
	
}

void TitleUpdate() {
	//ÉJÅ[É\ÉãÇÃà⁄ìÆ
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
	Sprite_Draw(TEXTURE_INDEX_TITLE1, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (cursorPos == PosGame) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}
	if (cursorPos == PosOption) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}
	if (cursorPos == PosDate) {
		Sprite_Draw(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 2 + 200, SCREEN_HEIGHT / 2 + 160, 0, 0, 200, 50);
	}

	Sprite_Draw(TEXTURE_INDEX_SELECT, 180, SCREEN_HEIGHT / 2 + 160, 0, 0, 640, 33);

}

void TitleUnInit() {
}