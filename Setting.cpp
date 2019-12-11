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
//プレイヤーを探していますの表示からOKが出るまで
void SettingSearchUpdate();
void SettingSearchDraw();

//体重を測定中のリングが回っているとこキャラの決定
void SettingSetWeightUpdate();
void SettingSetWeightDraw();

//決定したキャラを表示する
void SettingSetWeightEndUpdate();
void SettingSetWeightEndDraw();


//ボブスレーのモデルの行列
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

	//背景の描画
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


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, 25, 25, 25);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, -1.6f, -0.5f, 0);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
}
D3DXVECTOR3 GetForward() {
	D3DXMATRIX matrixWorld;    //ワールド行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 GetUp() {
	D3DXMATRIX matrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}


void SettingSearchUpdate() {
	alpha += alphaAdd;
	if (alpha >= 1 || alpha <= 0) {
		alphaAdd *= -1;
	}

	//各プレイヤーの認識をする
	if (Keyboard_IsPress(DIK_UP)) {
		isNext[0] = true;
	}
	if (Keyboard_IsPress(DIK_W)) {
		isNext[1] = true;
	}

	//2人のプレイヤーを認識した
	if (isNext[0] == true && isNext[1] == true) {
		nextIntervalCount++;
		if (nextIntervalCount == NEXT_INTERVAL) {
			for (int i = 0; i < 2; i++) {
				isNext[i] = false;
			}
			alpha = 1;
			nextIntervalCount = 0;

			//体重測定へ
			settingState = SETTING_SET_WEIGHT;

		}
	}

}
void SettingSearchDraw() {
	//プレイヤーエントリーの表示
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//立ち絵の表示
	UI[1]->position = D3DXVECTOR3(-1.8f, -0.1f, 0);
	UI[1]->scale = D3DXVECTOR3(1.7f, 2, 0);
	UI[1]->Draw(TEXTURE_INDEX_TATIE);

	//情報アイコンを表示
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_ZYOUHOUAIKONN);

	if (isNext[0] == false || isNext[1] == false) {
		//アイコンの隣のボードの上に乗ってくださいを表示
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	} else {
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SANKAPUREIYAWONINSIKI);
	}

	if (isNext[0] == false) {
		//1Pのプレイヤーを探していますを表示
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[4]->Draw(TEXTURE_INDEX_PUREIYAWOSAGASITERU, D3DXCOLOR(1, 1, 1, alpha));
	} else {
		UI[4]->position = D3DXVECTOR3(2.0f, 0.7f, 0);
		UI[4]->scale = D3DXVECTOR3(1.2f, 0.5f, 0);
		UI[4]->Draw(TEXTURE_INDEX_OK, D3DXCOLOR(1, 1, 1, 1));
	}

	if (isNext[1] == false) {
		//2Pのプレイヤーを探していますを表示
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
		//1Pの体重
		if (Keyboard_IsPress(DIK_N)) {
			//ランダムで60kg以上のキャラクターの体重を入れる
			int n=rand() % 2;
			if (n == 1) {
				settingPlayer.weight[0] = 75;
				settingPlayer.character[0] = new Bear();
			} else {
				settingPlayer.weight[0] = 65;
				settingPlayer.character[0] = new Dog();
			}
		} else {
			//ランダムで59kg以上のキャラクターの体重を入れる
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[0] = 55;
				settingPlayer.character[0] = new Rabbit();
			} else {
				settingPlayer.weight[0] = 45;
				settingPlayer.character[0] = new Hamster();
			}
		}

		//2Pの体重
		if (Keyboard_IsPress(DIK_M)) {
			//ランダムで60kg以上のキャラクターの体重を入れる
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[1] = 75;
				settingPlayer.character[1] = new Bear();
			} else {
				settingPlayer.weight[1] = 75;
				settingPlayer.character[1] = new Dog();
			}
		} else {
			//ランダムで59kg以上のキャラクターの体重を入れる
			int n = rand() % 2;
			if (n == 1) {
				settingPlayer.weight[1] = 55;
				settingPlayer.character[1] = new Rabbit();
			} else {
				settingPlayer.weight[1] = 45;
				settingPlayer.character[1] = new Hamster();
			}
		}
		//ボブスレーの色を変えるために一旦削除
		settingPlayer.soriModel.UnInit();

		//モデルのの再読み込み
		settingPlayer.soriModel.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv2.jpg");
		settingPlayer.character[0]->Init();
		settingPlayer.character[1]->Init();
		settingPlayer.character[0]->scale *= 0.5f;
		settingPlayer.character[1]->scale *= 0.5f;
		//セッティングシーン内の切り替え
		settingState = SETTING_SET_WEIGHT_END;

		nextIntervalCount = 0;
	}
}
void SettingSetWeightDraw() {
	//プレイヤーエントリーの表示
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//ボブスレーを障子
	SetMatrix();
	settingPlayer.soriModel.Draw();

	//立ち絵を表示
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_TATIE);

	if (isNext[0] == false || isNext[1] == false) {
		//アイコンの隣のそのままボードの上に乗ってくださいを表示
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	}

	if (isNext[0] == false) {
		//1Pの体重測定中のリングを表示
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[4]->rotation.z += 0.05f;
		UI[4]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	} 

	if (isNext[1] == false) {
		//2Pの体重測定中のリングを表示
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
	//プレイヤーエントリーの表示
	UI[0]->position = D3DXVECTOR3(2, 1.5f, 0);
	UI[0]->scale = D3DXVECTOR3(3, 0.5f, 0);
	UI[0]->Draw(TEXTURE_INDEX_PUREIYAENTORI);

	//ボブスレーを障子
	SetMatrix();
	settingPlayer.soriModel.Draw();
	//キャラクターの描画
	for (int i = 0; i < 2; i++) {
		settingPlayer.character[i]->position = GetUp()*1.75f + D3DXVECTOR3(-1.6f, -1.5f, 0);
		settingPlayer.character[i]->position += GetForward()*(float)i*0.6f - GetForward()*0.7f - GetForward()*0.5f;
		settingPlayer.character[i]->rotation = rotation;
		settingPlayer.character[i]->rotation.x -= 0.45f;
		settingPlayer.character[i]->Draw();
	}

	//立ち絵を表示
	UI[2]->position = D3DXVECTOR3(0.3f, -1.3f, 0);
	UI[2]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
	UI[2]->Draw(TEXTURE_INDEX_TATIE);

	if (nextIntervalCount < NEXT_INTERVAL) {
		//アイコンの隣のそのままボードの上に乗ってくださいを表示
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_SONOMAMABODO);
	} else {
		//アイコンの隣のそのままボードの上に乗ってくださいを表示
		UI[3]->position = D3DXVECTOR3(1.7f, -1.3f, 0);
		UI[3]->scale = D3DXVECTOR3(2, 0.5f, 0);
		UI[3]->Draw(TEXTURE_INDEX_DOTIRAKAZYANPU);
	}

	if (isNext[0] == false) {
		//1Pの体重測定中のリングを表示
		UI[4]->position = D3DXVECTOR3(2.0f, 0.65f, 0);
		UI[4]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[4]->rotation.z += 0.05f;
		UI[4]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	}

	if (isNext[1] == false) {
		//2Pの体重測定中のリングを表示
		UI[5]->position = D3DXVECTOR3(2.0f, -0.3f, 0);
		UI[5]->scale = D3DXVECTOR3(0.5f, 0.5f, 0);
		UI[5]->rotation.z += 0.05f;
		UI[5]->Draw(TEXTURE_INDEX_RING, D3DXCOLOR(1, 1, 1, 1));
	}
}
