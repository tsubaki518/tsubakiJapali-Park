#include"Setting.h"
#include"input.h"
#include"Camera.h"
#include"Figure.h"
#include"texture.h"
#include<time.h>
#include"main.h"
#include<stdlib.h>
#define NEXT_INTERVAL 100

enum {
	SETTING_SEARCH,
	SETTING_SET_WEIGHT,
	SETTING_SET_WEIGHT_END,
	SETTING_JUMP
};
//�v���C���[��T���Ă��܂��̕\������OK���o��܂�
void SettingSearchUpdate();
void SettingSearchDraw();

//�̏d�𑪒蒆�̃����O������Ă���Ƃ��L�����̌���
void SettingSetWeightUpdate();
void SettingSetWeightDraw();

//���肵���L������\������
void SettingSetWeightEndUpdate();
void SettingSetWeightEndDraw();


//�{�u�X���[�̃��f���̍s��
void SetMatrix();

SettingPlayer settingPlayer;
Cube *UI[6];
int settingState;
static float alpha;
static float alphaAdd = 0.04f;
static bool isNext[2];
static int nextIntervalCount = 0;
static D3DXVECTOR3 rotation;


void SettingInit() {
	settingState = SETTING_SEARCH;
	for (int i = 0; i < 6; i++) {
		UI[i] = new Cube();
	}
	for (int i = 0; i < 2; i++) {
		isNext[i] = false;
	}
	alpha = 1;
	nextIntervalCount = 0;
	settingPlayer.soriModel.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv022.jpg");
	rotation = D3DXVECTOR3(0.5f, 3.61f, 0);
}
void SettingUpdate() {
	switch (settingState) {
		case SETTING_SEARCH:
			SettingSearchUpdate();
			break;

		case SETTING_SET_WEIGHT:
			SettingSetWeightUpdate();
			break;

		case SETTING_SET_WEIGHT_END:
			SettingSetWeightEndUpdate();
			break;

	}
}
void SettingDraw() {
	SettingCamera camera;
	Cube backGround;

	camera.SetCamera();

	//�w�i�̕`��
	backGround.position = D3DXVECTOR3(0, 0.4f, 7);
	backGround.scale = D3DXVECTOR3(17.9f, 9.85f, 0);
	backGround.Draw(TEXTURE_INDEX_KYOUTUUHAIKEI);

	switch (settingState) {
	case SETTING_SEARCH:
		SettingSearchDraw();
		break;

	case SETTING_SET_WEIGHT:
		SettingSetWeightDraw();
		break;

	case SETTING_SET_WEIGHT_END:
		SettingSetWeightEndDraw();
		break;

	}
}
void SettingUnInit() {
	for (int i = 0; i < 6; i++) {
		delete UI[i];
	}
	for (int i = 0; i < 2; i++) {
		settingPlayer.character[i]->UnInit();
		delete settingPlayer.character[i];
	}
	settingPlayer.soriModel.UnInit();
}
SettingPlayer GetSettingPlayer() {
	return settingPlayer;
}
void SetMatrix() {
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX spinMtxRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ���[���h�ϊ�
	//���[���h�s���P�ʍs��֏�����
	D3DXMatrixIdentity(&g_mtxWorld);

	//�X�P�[���s����쐬�����[���h�s��֍���
	D3DXMatrixScaling(&mtxScl, 25, 25, 25);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//��]�s����쐬�����[���h�s��֍���
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//���s�s��
	D3DXMatrixTranslation(&mtxTrs, -1.6f, -0.5f, 0);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//���[���h�}�g���N�X��ݒ�
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
}
D3DXVECTOR3 GetForward() {
	D3DXMATRIX matrixWorld;    //���[���h�s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 GetUp() {
	D3DXMATRIX matrixWorld;    //���_�̍s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}


void SettingSearchUpdate() {
	alpha += alphaAdd;
	if (alpha >= 1 || alpha <= 0) {
		alphaAdd *= -1;
	}

	//�e�v���C���[�̔F��������
	if (Keyboard_IsPress(DIK_UP)) {
		isNext[0] = true;
	}
	if (Keyboard_IsPress(DIK_W)) {
		isNext[1] = true;
	}

	//2�l�̃v���C���[��F������
	if (isNext[0] == true && isNext[1] == true) {
		nextIntervalCount++;
		if (nextIntervalCount == NEXT_INTERVAL) {
			for (int i = 0; i < 2; i++) {
				isNext[i] = false;
			}
			alpha = 1;
			nextIntervalCount = 0;

			//�̏d�����
			settingState = SETTING_SET_WEIGHT;

		}
	}

}
void SettingSearchDraw() {
	//�v���C���[�G���g���[�̕\��
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//�����G�̕\��
	UI[1]->position = D3DXVECTOR3(-1.8f, -0.1f, 0);
	UI[1]->scale = D3DXVECTOR3(1.7f, 2, 0);
	UI[1]->Draw(TEXTURE_INDEX_TATIE);

	//���A�C�R����\��
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_ZYOUHOUAIKONN);

	if (isNext[0] == false || isNext[1] == false) {
		//�A�C�R���ׂ̗̃{�[�h�̏�ɏ���Ă���������\��
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	} else {
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SANKAPUREIYAWONINSIKI);
	}

	if (isNext[0] == false) {
		//1P�̃v���C���[��T���Ă��܂���\��
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[4]->Draw(TEXTURE_INDEX_PUREIYAWOSAGASITERU, D3DXCOLOR(1, 1, 1, alpha));
	} else {
		UI[4]->position = D3DXVECTOR3(2.0f, 0.7f, 0);
		UI[4]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[4]->Draw(TEXTURE_INDEX_OK, D3DXCOLOR(1, 1, 1, 1));
	}

	if (isNext[1] == false) {
		//2P�̃v���C���[��T���Ă��܂���\��
		UI[5]->position = D3DXVECTOR3(2.0f, -0.3f, 0);
		UI[5]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[5]->Draw(TEXTURE_INDEX_PUREIYAWOSAGASITERU, D3DXCOLOR(1, 1, 1, alpha));
	} else {
		UI[5]->position = D3DXVECTOR3(2.0f, -0.3f, 0);
		UI[5]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[5]->Draw(TEXTURE_INDEX_OK, D3DXCOLOR(1, 1, 1, 1));
	}
}


void SettingSetWeightUpdate() {
	rotation.y -= 0.02f;
	nextIntervalCount++;
	if (nextIntervalCount > NEXT_INTERVAL) {
		//1P�̑̏d
		if (Keyboard_IsPress(DIK_N)) {
			//�����_����60kg�ȏ�̃L�����N�^�[�̑̏d������
			int n=rand() % 2;
			if (n == 1) {
				settingPlayer.weight[0] = 75;
				settingPlayer.character[0] = new Bear();
			} else {
				settingPlayer.weight[0] = 65;
				settingPlayer.character[0] = new Dog();
			}
		} else {
			//�����_����59kg�ȏ�̃L�����N�^�[�̑̏d������
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[0] = 55;
				settingPlayer.character[0] = new Rabbit();
			} else {
				settingPlayer.weight[0] = 45;
				settingPlayer.character[0] = new Hamster();
			}
		}

		//2P�̑̏d
		if (Keyboard_IsPress(DIK_M)) {
			//�����_����60kg�ȏ�̃L�����N�^�[�̑̏d������
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[1] = 75;
				settingPlayer.character[1] = new Bear();
			} else {
				settingPlayer.weight[1] = 75;
				settingPlayer.character[1] = new Dog();
			}
		} else {
			//�����_����59kg�ȏ�̃L�����N�^�[�̑̏d������
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[1] = 55;
				settingPlayer.character[1] = new Rabbit();
			} else {
				settingPlayer.weight[1] = 45;
				settingPlayer.character[1] = new Hamster();
			}
		}
		//�{�u�X���[�̐F��ς��邽�߂Ɉ�U�폜
		settingPlayer.soriModel.UnInit();

		//���f���̂̍ēǂݍ���
		settingPlayer.soriModel.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv2.jpg");
		settingPlayer.character[0]->Init();
		settingPlayer.character[1]->Init();
		settingPlayer.character[0]->scale *= 0.5f;
		settingPlayer.character[1]->scale *= 0.5f;
		//�Z�b�e�B���O�V�[�����̐؂�ւ�
		settingState = SETTING_SET_WEIGHT_END;

		nextIntervalCount = 0;
	}
}
void SettingSetWeightDraw() {
	//�v���C���[�G���g���[�̕\��
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//�{�u�X���[����q
	SetMatrix();
	settingPlayer.soriModel.Draw();

	//�����G��\��
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_TATIE);

	if (isNext[0] == false || isNext[1] == false) {
		//�A�C�R���ׂ̗̂��̂܂܃{�[�h�̏�ɏ���Ă���������\��
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	}

	if (isNext[0] == false) {
		//1P�̑̏d���蒆�̃����O��\��
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[4]->rotation.z += 0.05f;
		UI[4]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	} 

	if (isNext[1] == false) {
		//2P�̑̏d���蒆�̃����O��\��
		UI[5]->position = D3DXVECTOR3(2.0f, -0.3f, 0);
		UI[5]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[5]->rotation.z += 0.05f;
		UI[5]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	} 
}


void SettingSetWeightEndUpdate() {
	rotation.y -= 0.02f;
	nextIntervalCount++;
	if (nextIntervalCount > NEXT_INTERVAL) {
		if (Keyboard_IsPress(DIK_B)) {
			SetScene(GAME);
		}
	}
}
void SettingSetWeightEndDraw() {
	//�v���C���[�G���g���[�̕\��
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//�{�u�X���[����q
	SetMatrix();
	settingPlayer.soriModel.Draw();
	//�L�����N�^�[�̕`��
	for (int i = 0; i < 2; i++) {
		settingPlayer.character[i]->position = GetUp()*1.75f + D3DXVECTOR3(-1.6f, -1.5f, 0);
		settingPlayer.character[i]->position += GetForward()*(float)i*0.6f - GetForward()*0.7f - GetForward()*0.5f;
		settingPlayer.character[i]->rotation = rotation;
		settingPlayer.character[i]->rotation.x -= 0.45f;
		settingPlayer.character[i]->Draw();
	}

	//�����G��\��
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_TATIE);

	if (nextIntervalCount < NEXT_INTERVAL) {
		//�A�C�R���ׂ̗̂��̂܂܃{�[�h�̏�ɏ���Ă���������\��
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	} else {
		//�A�C�R���ׂ̗̂��̂܂܃{�[�h�̏�ɏ���Ă���������\��
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_DOTIRAKAZYANPU);
	}

	if (isNext[0] == false) {
		//1P�̑̏d���蒆�̃����O��\��
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[4]->rotation.z += 0.05f;
		UI[4]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	}

	if (isNext[1] == false) {
		//2P�̑̏d���蒆�̃����O��\��
		UI[5]->position = D3DXVECTOR3(2.0f, -0.3f, 0);
		UI[5]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[5]->rotation.z += 0.05f;
		UI[5]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	}
}
