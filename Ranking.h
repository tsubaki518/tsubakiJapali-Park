#pragma once

typedef struct {
	float Scoretime;
	float Scorerating;
	int Player1;
	int Player2;
	bool isClear;
}SCORE;

void RankingInit();
void RankingUpdate();
void RankingDraw();
void RankingUnInit();

void LoadSave(void);
void WriteSave(void);
void SetRank(float time, float rating);
float GetScore(int n);
bool GetClear(void);
