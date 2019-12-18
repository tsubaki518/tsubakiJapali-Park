#include"Result.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Timer.h"
#include"input.h"
#include"main.h"
#include"sprite.h"
#include"ImageNumber.h"

static float score1;
static float score2;

void ResultInit() {
	score2 = GetRating();
}
void ResultUpdate() {
	if (Keyboard_IsPress(DIK_RETURN)) {
		SetScene(RANKING);
	}
}

void ResultDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_RESULTSCORE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	Sprite_SetColor(D3DCOLOR_RGBA(0, 255, 0, 255));
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 3 / 100 * 94, SCREEN_HEIGHT), D3DXVECTOR2(0.5f, 0.5f), score2 / 10);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 100 * 96, SCREEN_HEIGHT), D3DXVECTOR2(0.5f, 0.5f), (int)score2 % 10);

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	TimerDraw(SCREEN_WIDTH / 2 - 2, SCREEN_HEIGHT / 2 +25);
}

void ResultUnInit() {

}