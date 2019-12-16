#pragma once

typedef struct {
	float Scoretime;
	float Scorerating;
	bool isClear;
}SCORE;

void RankingInit();
void RankingUpdate();
void RankingDraw();
void RankingUnInit();

void LoadSave(void);
void WriteSave(void);
void SetRank(float time, float rating);
int GetScore(int n);
bool GetClear(void);