#include"sprite.h"
#include"texture.h"
#include"Animation.h"
#include"common.h"
#include"mydirect3d.h"
#include"sound.h"
#include"Rating.h"
#include"ImageNumber.h"

void StartAnimation::Init() {
	start = clock();
	isSoundOnece = false;
}
bool StartAnimation::Draw() {
	const int ANIMATION_TIME = 100;
	end = clock();
	int time = (end - start) / (int)CLOCKS_PER_SEC;

	//スタートの表示
	if (time > 7) {
		//タイムが5以上になったら表示しない
	} else if (time>=6) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_START, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 /2, 0, 0, 500, 200);

	} else if (time >= 5) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN1, SCREEN_WIDTH / 2-500/2, SCREEN_HEIGHT / 2/2, 0, 0, 500, 100);
		
	} else if (time >= 4) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN2, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 100);

	} else if (time >= 3) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_COUNT_DOWN3, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 100);

	} else if (time >= 2) {

		if (isSoundOnece == false) {
			PlaySound(SOUND_LABEL_SE_START_COUNT_DOWN);
		}
	}

	//7秒になったらアニメーション終了
	if (time >= 7) {
		return false;
	}
	return true;
}

void GoalAnimation::Init() {
	endCount = 0;
}
bool GoalAnimation::Draw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_GOAL, SCREEN_WIDTH / 2 - 500 / 2, SCREEN_HEIGHT / 2 / 2, 0, 0, 500, 200);

	endCount++;
	if (endCount > 350) {
		return true;
	}
	return false;
}

void TezukaLine::Init(int n) {
	drawCount = n;
}
void TezukaLine::Draw() {
	if (drawCount > 0) {
		const int TEXTURE_CUT_SIZE_X = SCREEN_WIDTH;
		const int TEXTURE_ANIMATION_INTERVAL = 3;
		const int TEXTURE_LAPSE_NUM = 2;

		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		Sprite_Draw(TEXTURE_INDEX_TEZUKA_LINE, 0, 0, TEXTURE_CUT_SIZE_X*count, 0, TEXTURE_CUT_SIZE_X, SCREEN_HEIGHT);

		interval++;
		if (interval == TEXTURE_ANIMATION_INTERVAL) {
			interval = 0;
			count++;
			if (count == TEXTURE_LAPSE_NUM) {
				count = 0;
			}
		}
	}

	drawCount--;
}

/*
void RatingAnimation::Init() {
	stopCount = 0;
	isUp = false;
	position = D3DXVECTOR2(
		SCREEN_HEIGHT / 2 -
		717 / 2,
		SCREEN_HEIGHT);
}
void RatingAnimation::Update() {
	const float ALPHA_ADD = 255;
	const float MOVER_ADD = 0;

	//画像を下に移動
	if (position.y<SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 2 &&
		isUp == false) {
		stopCount++;
		alpha += ALPHA_ADD;

	}
	if (position.y>SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 2
		&& isUp == false) {
		position.y += MOVER_ADD;
	}

	//上に上がるか判定する
	if (stopCount > 180.0f) {
		isUp = true;
	}
	if (isUp) {
		position.y -= MOVER_ADD;
		alpha -= ALPHA_ADD;
	}
}
void RatingAnimation::Draw() {
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, alpha));
	Sprite_Draw(TEXTURE_INDEX_SCOR_MESSAGE,
		position.x,
		position.y,
		0,
		0,
		717,
		65);

	ImageNumberDraw(
		D3DXVECTOR2(SCREEN_HEIGHT / 2 -717 / 2,													//x座標
					position.y -SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 2),		//y座標
		D3DXVECTOR2(1,
			        1),
					GetRating());

}
void RatingAnimation::UnInit() {

}
*/