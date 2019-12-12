#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Ranking.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Timer.h"
#include"input.h"
#include"main.h"

SCORE Score[31];
static float timescore;


void RankingInit() {
	//WriteSave();
	SetRank(GetTime());
}
void RankingUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}

	DebugFont_Draw(SCREEN_WIDTH / 5, 50 +   40, "%d位:%lf",  1, Score[0].Scoretime);
	DebugFont_Draw(SCREEN_WIDTH / 5, 50 + 40, "%d位:%lf", 1, Score[1].Scoretime);
	//LoadSave();
}
void RankingDraw() {

	for (int i = 0; i < 15; i++) {
		DebugFont_Draw(SCREEN_WIDTH / 5, 50 + i * 40, "%d位:%0.2lf", i + 1, Score[i].Scoretime);
	}
	for (int i = 15; i < 30; i++) {
		DebugFont_Draw(SCREEN_WIDTH - 250, 50 + (i-15) * 40, "%d位:%0.2lf", i + 1, Score[i].Scoretime);
	}
}
void RankingUnInit() {

}



void WriteSave(void) {
	FILE *fp;

	fp = fopen("SaveData.txt", "wb");

	for (int i = 0; i < 31; i++) {
		fwrite(&Score[i].Scoretime, sizeof(float), 1, fp);
	}

	fclose(fp);
}
void LoadSave(void) {
	FILE *fp;

	fp = fopen("SaveData.txt", "rb");

	for (int i = 0; i < 31; i++) {
		fread(&Score[i].Scoretime, sizeof(float), 1, fp);
	}

	fclose(fp);
}

void SetRank(float score) {
	Score[31].Scoretime = score;
	float work[31];
	int rank;
	int cnt2;
	bool isSetRank = false;
	bool isSetRank1 = false;

	//順位を判定する
	for (int i = 0; i < 31; i++) {
		if (Score[i].Scoretime == 0.00f) {
			isSetRank1 = true;
			break;
		}
		if (Score[31].Scoretime <= Score[i].Scoretime) {
			rank = i;
			isSetRank = true;
			break;
		}
		
	}

	//workに前の順位を入れる
	for (int i = 0; i < 31; i++) {
		work[i] = Score[i].Scoretime;
	}

	//スコアが30位以内に入っていたら順位をずらす
	if (isSetRank == true) {
		Score[rank] = Score[31];
		for (int i = rank; i < 31; i++) {
			Score[i + 1].Scoretime = work[i];
		}
	}
	else if (isSetRank1 == true) {
		Score[0] = Score[31];
		for (int i = 0; i < 31; i++) {
			Score[i + 1].Scoretime = work[i];
		}
	}
	Score[31].Scoretime = score;
}

int GetScore(int n) {
	return Score[n].Scoretime;
}
bool GetClear(void) {
	return Score->isClear;
}
