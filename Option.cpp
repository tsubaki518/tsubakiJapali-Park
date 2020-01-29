#include"Option.h"
#include"sprite.h"
#include"common.h"
#include"input.h"
#include"XInput.h"
#include"main.h"
#include"debug_font.h"
#include"mydirect3d.h"
#include"sound.h"

static float optionposX = SCREEN_WIDTH - SCREEN_HEIGHT;
static float optionposY = 0;
static float optionposX1 = SCREEN_WIDTH - (SCREEN_HEIGHT * 2);
static float optionposY1 = 0;
static float optionposX2 = SCREEN_WIDTH - (SCREEN_HEIGHT * 3);
static float optionposY2 = 0;

void OptionInit() {

}
void OptionUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}

	optionposX += 4;
	optionposY -= 2;
	optionposX1 += 4;
	optionposY1 -= 2;
	optionposX2 += 4;
	optionposY2 -= 2;
	if (optionposX >= SCREEN_WIDTH) {
		optionposX = SCREEN_WIDTH - (SCREEN_HEIGHT * 3);
		optionposY = 0;
	}
	if (optionposX1 >= SCREEN_WIDTH) {
		optionposX1 = SCREEN_WIDTH - (SCREEN_HEIGHT * 3);
		optionposY1 = 0;
	}
	if (optionposX2 >= SCREEN_WIDTH) {
		optionposX2 = SCREEN_WIDTH - (SCREEN_HEIGHT * 3);
		optionposY2 = 0;
	}
}
void OptionDraw() {
	//”wŒi
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_TITLE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//“®•¨Šç
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX, optionposY, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX, optionposY + SCREEN_HEIGHT, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX, optionposY + SCREEN_HEIGHT * 2, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);

	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX1, optionposY1, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX1, optionposY1 + SCREEN_HEIGHT, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX1, optionposY1 + SCREEN_HEIGHT * 2, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);;

	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX2, optionposY2, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX2, optionposY2 + SCREEN_HEIGHT, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_FACE, optionposX2, optionposY2 + SCREEN_HEIGHT * 2, 0, 0, SCREEN_HEIGHT, SCREEN_HEIGHT);

	Sprite_Draw(TEXTURE_INDEX_STAFF, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void OptionUnInit() {

}