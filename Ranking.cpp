#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Ranking.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Timer.h"
#include"input.h"
#include"main.h"

SCORE Score[32];
SCORE pScore[32];

static int cnt = sizeof(Score) / sizeof(SCORE);

void RankingInit() {
	if (Score[0].Scoretime == 0.00f) {
		for (int i = 0; i < 31; i++) {
			Score[i].Scoretime = 10000.00f;
			Score[i].Scorerating = 9999.00f;
		}
	}
	//WriteSave();
	SetRank(GetTime(), GetRating());
}
void RankingUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}

	//DebugFont_Draw(SCREEN_WIDTH / 5, 50 +   40, "%d位:%lf",  1, Score[0].Scoretime);
	//DebugFont_Draw(SCREEN_WIDTH / 5, 50 + 40, "%d位:%lf", 1, Score[1].Scoretime);
	//LoadSave();
}
void RankingDraw() {

	for (int i = 0; i < 15; i++) {
		DebugFont_Draw(SCREEN_WIDTH / 5, 50 + i * 40, "%d位:%0.2lf", i + 1, Score[i].Scoretime);
		DebugFont_Draw(SCREEN_WIDTH / 5 + 200, 50 + i * 40, "視聴率:%0.1lf％", Score[i].Scorerating/10);
	}
	for (int i = 15; i < 30; i++) {
		DebugFont_Draw(SCREEN_WIDTH / 2, 50 + (i - 15) * 40, "%d位:%0.2lf", i + 1, Score[i].Scoretime);
		DebugFont_Draw(SCREEN_WIDTH / 2 + 200, 50 + (i - 15) * 40, "視聴率:%0.1lf％", Score[i].Scorerating / 10);
	}
}
void RankingUnInit() {

}



void WriteSave(void) {
	FILE *fp;

	fp = fopen("SaveData.Score.dat", "wb");

	for (int i = 0; i < 31; i++) {
		fwrite(&Score[i], sizeof(SCORE), cnt, fp);
	}

	fclose(fp);
}
void LoadSave(void) {
	FILE *fp;

	fp = fopen("SaveData.Score.dat", "rb");

	for (int i = 0; i < 31; i++) {
		fread(&Score[i], sizeof(SCORE), cnt, fp);
	}

	fclose(fp);
}

void SetRank(float time, float rating) {
	Score[31].Scoretime = time;
	Score[31].Scorerating = rating;
	int rank;
	bool isSetRank = false;

	//順位を判定する
	for (int i = 0; i < 31; i++) {
		if (Score[31].Scoretime < Score[i].Scoretime) {
			rank = i;
			isSetRank = true;
			break;
		}
		
	}

	//workに前の順位を入れる
	for (int i = 0; i < 32; i++) {
		pScore[i] = Score[i];
	}

	//スコアが30位以内に入っていたら順位をずらす
	if (isSetRank == true) {
		Score[rank] = Score[31];
		for (int i = rank; i < 31; i++) {
			Score[i + 1] = pScore[i];
		}
	}
	Score[31].Scoretime = time;
	Score[31].Scorerating = rating;
}

float GetScore(int n) {
	return Score[n].Scoretime;
}
bool GetClear(void) {
	return Score->isClear;
}
