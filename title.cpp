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
static float titleposX = SCREEN_WIDTH / 2;
static float titleposY = 0;
static float titleposX1 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 8;
static float titleposY1 = 250;
static float titleposX2 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 4;
static float titleposY2 = 500;
static float titleposX3 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 2;
static float titleposY3 = 750;
static float titleposX4 = SCREEN_WIDTH / 2 + SCREEN_WIDTH;
static float titleposY4 = 1000;


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

	titleposX += 3;
	titleposY += 1;
	titleposX1 += 3;
	titleposY1 += 1;
	titleposX2 += 3;
	titleposY2 += 1;
	titleposX3 += 3;
	titleposY3 += 1;
	titleposX4 += 3;
	titleposY4 += 1;
	if (titleposY >= SCREEN_HEIGHT) {
		titleposX = SCREEN_WIDTH / 2;
		titleposY = SCREEN_HEIGHT / -5;
	}
	if (titleposY1 >= SCREEN_HEIGHT) {
		titleposX1 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 8;
		titleposY1 = SCREEN_HEIGHT / -5;
	}
	if (titleposY2 >= SCREEN_HEIGHT) {
		titleposX2 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 4;
		titleposY2 = SCREEN_HEIGHT / -5;
	}
	if (titleposY3 >= SCREEN_HEIGHT) {
		titleposX3 = SCREEN_WIDTH / 2 + SCREEN_WIDTH / 2;
		titleposY3 = SCREEN_HEIGHT / -5;
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
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH / -2 - SCREEN_WIDTH / 40, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH * -1 - SCREEN_WIDTH / 20, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH / -2 * 3 - SCREEN_WIDTH / 10, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH / -2 * 4 - SCREEN_WIDTH / 9, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH / -2 * 5 - SCREEN_WIDTH / 8, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX + SCREEN_WIDTH / -2 * 6 - SCREEN_WIDTH / 7, titleposY, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);

	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH / -2 - SCREEN_WIDTH / 40, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH * -1 - SCREEN_WIDTH / 20, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH / -2 * 3 - SCREEN_WIDTH / 10, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH / -2 * 4 - SCREEN_WIDTH / 9, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH / -2 * 5 - SCREEN_WIDTH / 8, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX1 + SCREEN_WIDTH / -2 * 6 - SCREEN_WIDTH / 7, titleposY1, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);


	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH / -2 - SCREEN_WIDTH / 40, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH * -1 - SCREEN_WIDTH / 20, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH / -2 * 3 - SCREEN_WIDTH / 10, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH / -2 * 4 - SCREEN_WIDTH / 9, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH / -2 * 5 - SCREEN_WIDTH / 8, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX2 + SCREEN_WIDTH / -2 * 6 - SCREEN_WIDTH / 7, titleposY2, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);


	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH / -2 - SCREEN_WIDTH / 40, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH * -1 - SCREEN_WIDTH / 20, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH / -2 * 3 - SCREEN_WIDTH / 10, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH / -2 * 4 - SCREEN_WIDTH / 9, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH / -2 * 5 - SCREEN_WIDTH / 8, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX3 + SCREEN_WIDTH / -2 * 6 - SCREEN_WIDTH / 7, titleposY3, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);


	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH / -2 - SCREEN_WIDTH / 40, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH * -1 - SCREEN_WIDTH / 20, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH / -2 * 3 - SCREEN_WIDTH / 10, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH / -2 * 4 - SCREEN_WIDTH / 9, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH / -2 * 5 - SCREEN_WIDTH / 8, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);
	Sprite_Draw(TEXTURE_INDEX_FACE, titleposX4 + SCREEN_WIDTH / -2 * 6 - SCREEN_WIDTH / 7, titleposY4, 0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5);


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