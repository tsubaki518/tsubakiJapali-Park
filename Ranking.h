#pragma once

typedef struct {
	float Scoretime;
	int Scorerating;
	bool isClear;
}SCORE;

void RankingInit();
void RankingUpdate();
void RankingDraw();
void RankingUnInit();

void LoadSave(void);
void WriteSave(void);
void SetRank(float score);
int GetScore(int n);
bool GetClear(void);