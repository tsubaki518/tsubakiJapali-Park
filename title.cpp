#include"title.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"XInput.h"
#include"main.h"
#include"debug_font.h"
#include"mydirect3d.h"

static float cursorPos = PosGame;
static float t = 0;
static float posX = 0;
static float posY = 0;
static int i = 0;
static int add = 7;


void TitleInit() {
	
}

void TitleUpdate() {
	i += add;
	if (i > 255)
	{
		i = 255;
		add *= -1;
	}
	if (i < 0) {
		i = 0;
		add *= -1;
	}

	

	//カーソルの移動
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

	//EnterKeyを押した時の判定
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
	//背景
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_TITLE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//動物顔
	Sprite_Draw(TEXTURE_INDEX_FACE, 0, 0, 0, 0, 750, 250);

	//タイトル
	Sprite_Draw(TEXTURE_INDEX_TITLE1, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//選択バー明滅
	if (cursorPos == PosGame) {
		Sprite_Draw2(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 5 * 2, SCREEN_HEIGHT / 50 * 39, 0, 0, SCREEN_WIDTH / 5.5, SCREEN_HEIGHT / 25 * 2, i);
	}
	if (cursorPos == PosOption) {
		Sprite_Draw2(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 50 * 9, SCREEN_HEIGHT / 50 * 39, 0, 0, SCREEN_WIDTH / 5.5, SCREEN_HEIGHT / 25 * 2, i);
	}
	if (cursorPos == PosDate) {
		Sprite_Draw2(TEXTURE_INDEX_BAR, SCREEN_WIDTH / 102 * 63, SCREEN_HEIGHT / 50 * 39, 0, 0, SCREEN_WIDTH / 5.5, SCREEN_HEIGHT / 25 * 2, i);
	}

	//選択肢
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_SELECT, SCREEN_WIDTH / 5, SCREEN_HEIGHT / 50 * 39, 0, 0, SCREEN_WIDTH / 1.7, SCREEN_HEIGHT / 15);

}

void TitleUnInit() {
}