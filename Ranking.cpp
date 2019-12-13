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
static float timescore;


void RankingInit() {
	if (Score[0].Scoretime == 0.00f) {
		for (int i = 0; i < 31; i++) {
			Score[i].Scoretime = 10000.00f;
		}
	}
	//WriteSave();
	SetRank(GetTime());
}
void RankingUpdate() {
	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}

	DebugFont_Draw(SCREEN_WIDTH / 5, 50 +   40, "%d��:%lf",  1, Score[0].Scoretime);
	DebugFont_Draw(SCREEN_WIDTH / 5, 50 + 40, "%d��:%lf", 1, Score[1].Scoretime);
	//LoadSave();
}
void RankingDraw() {

	for (int i = 0; i < 15; i++) {
		DebugFont_Draw(SCREEN_WIDTH / 5, 50 + i * 40, "%d��:%0.2lf", i + 1, Score[i].Scoretime);
	}
	for (int i = 15; i < 30; i++) {
		DebugFont_Draw(SCREEN_WIDTH - 250, 50 + (i-15) * 40, "%d��:%0.2lf", i + 1, Score[i].Scoretime);
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
	int rank;
	bool isSetRank = false;

	//���ʂ𔻒肷��
	for (int i = 0; i < 31; i++) {
		if (Score[31].Scoretime < Score[i].Scoretime) {
			rank = i;
			isSetRank = true;
			break;
		}
		
	}

	//work�ɑO�̏��ʂ�����
	for (int i = 0; i < 32; i++) {
		pScore[i].Scoretime = Score[i].Scoretime;
	}

	//�X�R�A��30�ʈȓ��ɓ����Ă����珇�ʂ����炷
	if (isSetRank == true) {
		Score[rank].Scoretime = Score[31].Scoretime;
		for (int i = rank; i < 31; i++) {
			Score[i + 1].Scoretime = pScore[i].Scoretime;
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
