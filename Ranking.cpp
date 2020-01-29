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
#include"Setting.h"
#include"ImageNumber.h"
#include"sound.h"

SettingPlayer pPC;
SCORE Score[22];
SCORE pScore[22];

static int cnt = sizeof(Score) / sizeof(SCORE);

static bool SR;
static float posadd_y;
static int rankanime_x = 0;
static int rankanime_y = 0;
static int add;

static float juni;//����

static float RankposX1;//�J�b�g�C��(��)�̈ړ�
static float RankposX2;//�J�b�g�C��(��)�̈ړ�
static bool isRankingin;//Result->Ranking=false....Title->Ranking=true
static bool isRankcutin;//�J�b�g�C���J�n
static bool isRankanime;//�X�R�A�A�j���[�V����
static bool isChangeAl;//�A���t�@�l�ω�

void RankingInit() {
	//�f�o�b�O�p�����L���O������
	//Score[0].Scoretime = 0.00f;

	if (Score[0].Scoretime == 0.00f) {
		for (int i = 0; i < 21; i++) {
			Score[i].Scoretime = 599.00f;
			Score[i].Scorerating = 9999.00f;
			Score[i].Player1 = 3;
			Score[i].Player2 = 2;
		}
	}

	//�����L���O�X�R�A�ړ�
	posadd_y = SCREEN_HEIGHT * 2.2 * -1;
	//�����N�C���J�b�g�C�������ʒu
	RankposX1 = SCREEN_WIDTH * 3 * -1;
	RankposX2 = SCREEN_WIDTH * 3;
	//WriteSave();

	isRankcutin = false;
	isRankanime = false;
	isChangeAl = false;
	isRankingin = ChangeScene_Title();
	juni = 21;

	//���U���g�������L���O
	if (isRankingin == false) {

		pPC.weight[0] = GetSettingPlayer().weight[0];
		pPC.weight[1] = GetSettingPlayer().weight[1];

		//1P�̑̏d�ɂ���ĕ\������L�����N�^�[��ς���
		if (pPC.weight[0] == 75) {
			//�N�}
			Score[21].Player1 = 1;
		}
		else if (pPC.weight[0] == 65) {
			//�C�k
			Score[21].Player1 = 2;
		}
		else if (pPC.weight[0] == 55) {
			//�E�T�M
			Score[21].Player1 = 3;
		}
		else if (pPC.weight[0] == 45) {
			//�n���X�^�[
			Score[21].Player1 = 4;
		}


		//2P�̑̏d�ɂ���ĕ\������L�����N�^�[��ς���
		if (pPC.weight[1] == 75) {
			//�N�}
			Score[21].Player2 = 1;
		}
		else if (pPC.weight[1] == 65) {
			//�C�k
			Score[21].Player2 = 2;
		}
		else if (pPC.weight[1] == 55) {
			//�E�T�M
			Score[21].Player2 = 3;
		}
		else if (pPC.weight[1] == 45) {
			//�n���X�^�[
			Score[21].Player2 = 4;
		}

		SetRank(GetTime(), GetRating());

		//���ʂ𔻒肷��
		for (int i = 0; i < 21; i++) {
			if (GetTime() < Score[i].Scoretime) {
				juni = i - 1;
				break;
			}

		}
	}

}
void RankingUpdate() {
	add += 1;

	if (isRankingin == false) {
		isRankanime = true;
	}
	else {
		//�X�R�A�X���C�h
		if (Keyboard_IsPress(DIK_UP)) {
			posadd_y -= SCREEN_HEIGHT * 0.01;
		}
		if (Keyboard_IsPress(DIK_DOWN)) {
			posadd_y += SCREEN_HEIGHT * 0.01;
		}
	}

	if (Keyboard_IsTrigger(DIK_RETURN)) {
		SetScene(TITLE);
	}




	//�h�b�g�G�A�j���[�V����
	if (add >= 5) {
		rankanime_x += 1;
		add = 0;
	}
	if (rankanime_x >= 9) {
		rankanime_x = 0;
		rankanime_y += 1;
	}
	if (rankanime_y >= 2) {
		rankanime_y = 0;
	}

	//�����N�C���X�R�A�A�j���[�V����
	if (isRankanime == true) {

		if ((juni + 1)*SCREEN_HEIGHT * 3 / 19 + posadd_y >= SCREEN_HEIGHT / 2) {
			isRankcutin = true;
		}
		else {
			posadd_y += SCREEN_HEIGHT * 0.01;
		}
	}
	else {
		if (posadd_y > SCREEN_HEIGHT * 0.21) {
			posadd_y = SCREEN_HEIGHT * 0.21;
		}
		if (posadd_y < SCREEN_HEIGHT * 2.2 * -1) {
			posadd_y = SCREEN_HEIGHT * 2.2 * -1;
		}
	}

	//�����N�C���J�b�g�C���A�j���[�V����
	if (isRankcutin == true) {
		if (RankposX1 >= 0) {
			RankposX1 = 0;
		}
		else {
			RankposX1 += 60;
		}	 
		if (RankposX2 <= 0) {
			RankposX2 = 0;
		}	 
		else{ 
			RankposX2 -= 60;
			isChangeAl = true;
		}
	}

	//LoadSave();
}
void RankingDraw() {
	Sprite_Draw(TEXTURE_INDEX_RANKING, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//�X�R�A�\��
	for (int i = 0; i < 20; i++) {
		//���g
		if (isChangeAl == true) {
			if (i == juni) {
				Sprite_Draw2(TEXTURE_INDEX_RANKING_WAKU, SCREEN_WIDTH*0.09, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 3 / 20, 255);
			}
			else {
				Sprite_Draw2(TEXTURE_INDEX_RANKING_WAKU, SCREEN_WIDTH*0.09, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 3 / 20, 200);
			}
		}
		else {
			Sprite_Draw(TEXTURE_INDEX_RANKING_WAKU, SCREEN_WIDTH*0.09, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT * 3 / 20);
		}

		//������
		Sprite_SetColor(D3DCOLOR_RGBA(0, 0, 0, 255));
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 100 * 92.5, (SCREEN_HEIGHT * 5 * 15.80 / 100)*i + SCREEN_HEIGHT * 5 / 100 * 6.0 + posadd_y * 5), D3DXVECTOR2(0.2f, 0.2f), Score[i].Scorerating / 10);
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 100 * 94.9, (SCREEN_HEIGHT * 5 * 15.80 / 100)*i + SCREEN_HEIGHT * 5 / 100 * 6.0 + posadd_y * 5), D3DXVECTOR2(0.2f, 0.2f), (int)Score[i].Scorerating % 10);

		//�^�C��
		//��
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 54.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), Score[i].Scoretime / 60);
		//�b
		if ((int)Score[i].Scoretime % 60 < 10) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 60.2, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), 0);
		}
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 63.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), (int)Score[i].Scoretime % 60);
		//�R���}
		if ((int)Score[i].Scoretime % 100 < 10) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 68.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), 0);
		}
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 72.7, (SCREEN_HEIGHT * 2.5 * 15.8 / 100)*i + SCREEN_HEIGHT * 2.5 / 100 * 4.0 + posadd_y * 2.5), D3DXVECTOR2(0.4f, 0.4f), (int)Score[i].Scoretime % 100);

		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));

		//1P�̑̏d�ɂ���ĕ\������L�����N�^�[��ς���
		if (Score[i].Player1 == 1) {
			Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH * 0.25, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player1 == 2) {
			Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH * 0.25, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player1 == 3) {
			Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH * 0.25, i*SCREEN_HEIGHT * 3 / 19 - SCREEN_HEIGHT * 0.01 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player1 == 4) {
			Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH * 0.25, i*SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, 150, 150);
		}

		//2P�̑̏d�ɂ���ĕ\������L�����N�^�[��ς���
		if (Score[i].Player2 == 1) {
			Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH * 0.35, i*SCREEN_HEIGHT * 3 / 19.1 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player2 == 2) {
			Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH * 0.35, i*SCREEN_HEIGHT * 3 / 19.1 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player2 == 3) {
			Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH * 0.35, i*SCREEN_HEIGHT * 3 / 19.1 - SCREEN_HEIGHT * 0.01 + posadd_y, 0, 0, 150, 150);
		}
		else if (Score[i].Player2 == 4) {
			Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH * 0.35, i*SCREEN_HEIGHT * 3 / 19.1 + posadd_y, 0, 0, 150, 150);
		}
	}

	//���ʕ\��
	Sprite_Draw(TEXTURE_INDEX_RANKING_GOLD, SCREEN_WIDTH*0.15, posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	Sprite_Draw(TEXTURE_INDEX_RANKING_SILVER, SCREEN_WIDTH*0.15, SCREEN_HEIGHT * 3 / 19 + posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	Sprite_Draw(TEXTURE_INDEX_RANKING_COPPER, SCREEN_WIDTH*0.15, SCREEN_HEIGHT * 3 / 19 * 2 + posadd_y, 0, 0, SCREEN_HEIGHT * 3 / 20, SCREEN_HEIGHT * 3 / 20);
	for (int j = 0; j < 17; j++) {
		Sprite_SetColor(D3DCOLOR_RGBA(181, 151, 31, 255));
		if (j < 6) {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 100 * 17.7, (SCREEN_HEIGHT * 2 * 15.8 / 100)*(j + 3) + SCREEN_HEIGHT * 2 / 100 * 4.0 + posadd_y * 2), D3DXVECTOR2(0.5f, 0.5f), j + 4);
		}
		else {
			ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2 / 100 * 18.7, (SCREEN_HEIGHT * 2 * 15.8 / 100)*(j + 3) + SCREEN_HEIGHT * 2 / 100 * 4.0 + posadd_y * 2), D3DXVECTOR2(0.5f, 0.5f), j + 4);
		}
		Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	}

	//���o��
	if (isRankingin == true) {
		Sprite_Draw(TEXTURE_INDEX_RANKING2, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	//�����N�C���J�b�g�C��
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_RESULT_CUTIN_UP, RankposX1, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_RESULT_CUTIN_DOWN, RankposX2, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);


	//�����A�j��
	Sprite_Draw(TEXTURE_INDEX_RANKING_ANIME, SCREEN_WIDTH*0.01, SCREEN_HEIGHT * 0.8, SCREEN_WIDTH / 10 * rankanime_x, SCREEN_HEIGHT / 4.5 * rankanime_y, SCREEN_WIDTH / 10, SCREEN_HEIGHT / 4.5, 1, 1);

}
void RankingUnInit() {
	StopSound();
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

	//���ʂ𔻒肷��
	for (int i = 0; i < 21; i++) {
		if (Score[21].Scoretime < Score[i].Scoretime) {
			rank = i;
			isSetRank = true;
			break;
		}
		
	}

	//work�ɑO�̏��ʂ�����
	for (int i = 0; i < 22; i++) {
		pScore[i] = Score[i];
	}

	//�X�R�A��30�ʈȓ��ɓ����Ă����珇�ʂ����炷
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
