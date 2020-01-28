#include"Result.h"
#include"debug_font.h"
#include"common.h"
#include"Rating.h"
#include"Timer.h"
#include"input.h"
#include"main.h"
#include"sprite.h"
#include"ImageNumber.h"
#include"Setting.h"
#include"Camera.h"
#include"Ranking.h"
#include"Sky.h"

//ボブスレーのモデルの行列
void SetMatrix2();

static float score1;//タイム(整数)
static float score2;//視聴率
static float score3;//タイム(少数)
static float score4;//ランキングタイム30位
static float ResultposX1;//カットイン(上)の移動
static float ResultposX2;//カットイン(下)の移動

SettingPlayer SP;
static D3DXVECTOR3 rotation;

static D3DXVECTOR3 GetUp2();
static D3DXVECTOR3 GetForward2();
static D3DXVECTOR3 GetRight2();

static bool isRankin;//ランクイン判定

void ResultInit() {
	//タイム(整数)を収納
	score1 = GetTime();
	//視聴率を収納
	score2 = GetRating();
	//タイム(少数)を収納
	score3 = Getsyousuu();
	//ランキングタイム30位を取得
	score4 = GetScore(19);

	//ランクイン判定初期化
	isRankin = false;

	//ランクインカットイン初期位置
	ResultposX1 = SCREEN_WIDTH * 3 * -1;
	ResultposX2 = SCREEN_WIDTH * 3;

	//ソリモデルの取得
	SP.soriModel.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv022.jpg");
	rotation = D3DXVECTOR3(0.5f, 3.33f, 0);
	SP.weight[0] = GetSettingPlayer().weight[0];
	SP.weight[1] = GetSettingPlayer().weight[1];

	//1Pの体重によって表示するキャラクターを変える
	if (SP.weight[0] == 75) {
		SP.character[0] = new Bear();
	}
	else if (SP.weight[0] == 65) {
		SP.character[0] = new Dog();
	}
	else if (SP.weight[0] == 55) {
		SP.character[0] = new Rabbit();
	}
	else if (SP.weight[0] == 45) {
		SP.character[0] = new Hamster();
	}


	//2Pの体重によって表示するキャラクターを変える
	if (SP.weight[1] == 75) {
		SP.character[1] = new Bear();

	}
	else if (SP.weight[1] == 65) {
		SP.character[1] = new Dog();
	}
	else if (SP.weight[1] == 55) {
		SP.character[1] = new Rabbit();
	}
	else if (SP.weight[1] == 45) {
		SP.character[1] = new Hamster();
	}
	SP.character[0]->Init();
	SP.character[1]->Init();
	for (int i = 0; i < 2; i++) {
		SP.character[i]->scale *= 0.5f;
	}
}

void ResultUpdate() {
	if (score1 < score4) {
		isRankin = true;
	}

	//ランクインカットインアニメーション
	if (isRankin == true) {
		if (ResultposX1 >= 0) {
			ResultposX1 = 0;
		}
		else {
			ResultposX1 += 60;
		}
		if (ResultposX2 <= 0) {
			ResultposX2 = 0;
		}
		else {
			ResultposX2 -= 60;
		}
	}

	if (Keyboard_IsPress(DIK_RETURN)) {
		SetScene(RANKING);
	}
}

void ResultDraw() {
	Cube sky;
	SettingCamera camera;
	Cube backGround;

	sky.position = D3DXVECTOR3(1, 1, 1);
	sky.rotation = D3DXVECTOR3(0, 0, 0);
	sky.scale = D3DXVECTOR3(10, 10, 1);
	sky.Draw(TEXTURE_INDEX_SKY);

	camera.SetCamera();

	//背景の描画
	//backGround.position = D3DXVECTOR3(0, 0.4f, -10);
	//backGround.scale = D3DXVECTOR3(100.9f, 100.85f, 0);
	//backGround.Draw(TEXTURE_INDEX_ICE);


	//ボブスレーを表示
	SetMatrix2();
	SP.soriModel.Draw();
	//キャラクターの描画
	for (int i = 0; i < 2; i++) {
		SP.character[i]->position = GetUp2()*1.85f + D3DXVECTOR3(-1.6f, -1.5f, 0);
		SP.character[i]->position += GetRight2()*0.2f+GetForward2()*0.1f;
		SP.character[i]->position -= GetForward2()*(float)i*0.6f + GetForward2()*0.3f + GetForward2()*0.2f;
		SP.character[i]->rotation = rotation;
		SP.character[i]->rotation.x -= 0.45f;
		SP.character[i]->Draw();
	}

	//スコアの下地
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_RESULTSCORE, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//視聴率
	Sprite_SetColor(D3DCOLOR_RGBA(0, 0, 0, 255));
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 80, SCREEN_HEIGHT*1.25 / 50 * 51), D3DXVECTOR2(0.4f, 0.4f), score2 / 10);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 10 / 3 / 100 * 84, SCREEN_HEIGHT / 3 * 5 / 50 * 54), D3DXVECTOR2(0.3f, 0.3f), (int)score2 % 10);

	//タイム
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 60, SCREEN_HEIGHT*1.25 / 50 * 39), D3DXVECTOR2(0.4f, 0.4f), score1 / 60);
	if ((int)score1 % 60 < 10) {
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 66, SCREEN_HEIGHT*1.25 / 50 * 39), D3DXVECTOR2(0.4f, 0.4f), 0);
	}
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 69, SCREEN_HEIGHT*1.25 / 50 * 39), D3DXVECTOR2(0.4f, 0.4f), (int)score1 % 60);
	if ((int)score3 % 100 < 10) {
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 75, SCREEN_HEIGHT*1.25 / 50 * 39), D3DXVECTOR2(0.4f, 0.4f), 0);
	}
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 2.5 / 100 * 78, SCREEN_HEIGHT*1.25 / 50 * 39), D3DXVECTOR2(0.4f, 0.4f), (int)score3 % 100);

	//ランクインカットイン
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_RESULT_CUTIN_UP, ResultposX1, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	Sprite_Draw(TEXTURE_INDEX_RESULT_CUTIN_DOWN, ResultposX2, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);


	//プレイヤーキャラクター表示
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	//1Pの体重によって表示するキャラクターを変える
	if (SP.weight[0] == 75) {
		Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH / 5 * 2.4, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[0] == 65) {
		Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH / 5 * 2.4, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[0] == 55) {
		Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH / 5 * 2.4, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[0] == 45) {
		Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH / 5 * 2.4, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}

	//2Pの体重によって表示するキャラクターを変える
	if (SP.weight[1] == 75) {
		Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH / 5 * 2.8, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[1] == 65) {
		Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH / 5 * 2.8, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[1] == 55) {
		Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH / 5 * 2.8, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
	else if (SP.weight[1] == 45) {
		Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH / 5 * 2.8, SCREEN_HEIGHT / 3 * 1.35, 0, 0, 150, 150);
	}
}

void ResultUnInit() {
	for (int i = 0; i < 2; i++) {
		SP.character[i]->UnInit();
		delete SP.character[i];
	}
	SP.soriModel.UnInit();
}

void SetMatrix2() {
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
	D3DXMatrixTranslation(&mtxTrs, -2.0f, -0.5f, 0);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
}
D3DXVECTOR3 GetForward2() {
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
D3DXVECTOR3 GetUp2() {
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
D3DXVECTOR3 GetRight2() {
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
		direction = D3DXVECTOR3(matrixWorld._11, matrixWorld._12, matrixWorld._13);
	}
	return direction;
}

