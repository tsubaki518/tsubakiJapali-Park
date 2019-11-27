#include"sprite.h"
#include"texture.h"
#include"Animation.h"
#include"common.h"
#include"mydirect3d.h"

void StartAnimation::Init() {
	start = clock();
}
bool StartAnimation::Draw() {
	const int ANIMATION_TIME = 100;
	end = clock();
	int time = (end - start) / (int)CLOCKS_PER_SEC;

	//スタートの表示
	if (time > 5) {
		//タイムが5以上になったら表示しない
	} else if (time>=4) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_START, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 /2, 0, 0, 500, 200);

	} else if (time >= 3) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN1, SCREEN_WIDTH / 2-500/2, SCREEN_HEIGHT / 2/2, 0, 0, 500, 100);
		
	} else if (time >= 2) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN2, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 100);

	} else if (time >= 1) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN3, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 100);
	}

	//500フレームの間スタートを表示する
	if (time >= 5) {
		return false;
	}
	return true;
}

void GoalAnimation::Draw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_GOAL, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 200);
}