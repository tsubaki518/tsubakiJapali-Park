#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Ranking.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Result.h"
#include"Timer.h"
#include"input.h"
#include"main.h"
#include"sprite.h"
#include"ImageNumber.h"

SCORE Score[22];
SCORE pScore[22];

static int cnt = sizeof(Score) / sizeof(SCORE);

static bool SR;
static float posadd_y;

void RankingInit() {
	if (Score[0].Scoretime == 0.00f) {
		for (int i = 0; i < 21; i++) {
			Score[i].Scoretime = 599.00f;
			Score[i].Scorerating = 9999.00f;
		}
	}
	if (ChangeScene_Title() == false) {
		SetRank(GetTime(), GetRating());
	}

	//WriteSave();

	posadd_y = 0;
}
void RankingUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}

	if (Keyboard_IsPress(DIK_UP)) {
		posadd_y -= SCREEN_HEIGHT * 0.01;
	}
	if (Keyboard_IsPress(DIK_DOWN)) {
		posadd_y += SCREEN_HEIGHT * 0.01;
	}

	//DebugFont_Draw(SCREEN_WIDTH / 5, 50 +   40, "%d位:%lf",  1, Score[0].Scoretime);
	//DebugFont_Draw(SCREEN_WIDTH / 5, 50 + 40, "%d位:%lf", 1, Score[1].Scoretime);
	//LoadSave();
}
void RankingDraw() {
	Sprite_Draw(TEXTURE_INDEX_RANKING, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//スコア表示
	for (int i = 0; i < 20; i++) {
		//白枠
		Sprite_Draw(TEXTURE_INDEX_RANKING_WAKU, SCREEN_WIDTH*0.09, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 3 / 20);
		//視聴率
		Sprite_SetColor(D3DCOLOR_RGBA(0, 0, 0, 255));
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 100 * 92.5, (SCREEN_HEIGHT * 5 * 15.80 / 100)*i + SCREEN_HEIGHT * 5 / 100 * 6.0 + posadd_y * 5), D3DXVECTOR2(0.2f, 0.2f), Score[i].Scorerating / 10);
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 100 * 94.9, (SCREEN_HEIGHT * 5 * 15.80 / 100)*i + SCREEN_HEIGHT * 5 / 100 * 6.0 + posadd_y * 5), D3DXVECTOR2(0.2f, 0.2f), (int)Score[i].Scorerating % 10);

		//タイム
		//分
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 54.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), Score[i].Scoretime / 60);
		//秒
		if ((int)Score[i].Scoretime % 60 < 10) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 60.2, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), 0);
		}
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 63.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), (int)Score[i].Scoretime % 60);
		//コンマ
		if ((int)Score[i].Scoretime % 100 < 10) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 68.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), 0);
		}
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 72.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), (int)Score[i].Scoretime % 100);
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	}

	//順位表示
	Sprite_Draw(TEXTURE_INDEX_RANKING_GOLD, SCREEN_WIDTH*0.09, posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	Sprite_Draw(TEXTURE_INDEX_RANKING_SILVER, SCREEN_WIDTH*0.09, SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	Sprite_Draw(TEXTURE_INDEX_RANKING_COPPER, SCREEN_WIDTH*0.09, SCREEN_HEIGHT * 3 / 19 * 2 + posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	for (int j = 0; j < 17; j++) {
		Sprite_SetColor(D3DCOLOR_RGBA(255, 0, 255, 255));
		if (j < 6) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 100 * 9.7, (SCREEN_HEIGHT * 2 * 15.8 / 100)*(j + 3) + SCREEN_HEIGHT * 2 / 100 * 4.0 + posadd_y * 2), D3DXVECTOR2(0.5f, 0.5f), j + 4);
		}
		else {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 100 * 14.7, (SCREEN_HEIGHT * 2 * 15.8 / 100)*(j + 3) + SCREEN_HEIGHT * 2 / 100 * 4.0 + posadd_y * 2), D3DXVECTOR2(0.5f, 0.5f), j + 4);
		}
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	}

	Sprite_Draw(TEXTURE_INDEX_RANKING_ANIME, SCREEN_WIDTH*0.1, SCREEN_HEIGHT * 2 * 0.8 / 3, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 1.5);
	
}
void RankingUnInit() {

}



void WriteSave(void) {
	FILE *fp;

	fp = fopen("SaveData.Score.dat", "wb");

	for (int i = 0; i < 21; i++) {
		fwrite(&Score[i], sizeof(SCORE), cnt, fp);
	}

	fclose(fp);
}
void LoadSave(void) {
	FILE *fp;

	fp = fopen("SaveData.Score.dat", "rb");

	for (int i = 0; i < 21; i++) {
		fread(&Score[i], sizeof(SCORE), cnt, fp);
	}

	fclose(fp);
}

void SetRank(float time, float rating) {
	Score[21].Scoretime = time;
	Score[21].Scorerating = rating;
	int rank;
	bool isSetRank = false;

	//順位を判定する
	for (int i = 0; i < 21; i++) {
		if (Score[21].Scoretime < Score[i].Scoretime) {
			rank = i;
			isSetRank = true;
			break;
		}
		
	}

	//workに前の順位を入れる
	for (int i = 0; i < 22; i++) {
		pScore[i] = Score[i];
	}

	//スコアが30位以内に入っていたら順位をずらす
	if (isSetRank == true) {
		Score[rank] = Score[21];
		for (int i = rank; i < 21; i++) {
			Score[i + 1] = pScore[i];
		}
	}
	Score[21].Scoretime = time;
	Score[21].Scorerating = rating;
}

float GetScore(int n) {
	return Score[n].Scoretime;
}
bool GetClear(void) {
	return Score->isClear;
}
