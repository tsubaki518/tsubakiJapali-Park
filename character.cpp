#include"character.h"
#include"input.h"


//各キャラクターの初期化
void Character::Init(){
	inputRotZ = 0;
}
void Elephant::Init() {
	inputRotZ = 0;
	inputRotX = 0;
}
void Bear::Init() {
	model.Init("asset/model/Bear/bear.x", "asset/model/Bear/bearuv2.jpg");
	scale.x = 30;
	scale.y = 35;
	scale.z = 30;
	inputRotZ = 0;
	inputRotX = 0;
}
void Dog::Init() {
	model.Init("asset/model/イッヌ/dogcustomVV.x", "asset/model/イッヌ/dogtexture2.png");
	scale.x = 1;
	scale.y = 1;
	scale.z = 1;
	inputRotZ = 0;
	inputRotX = 0;
	scale *= 0.65f;
}
void Rabbit::Init() {
	model.Init("asset/model/Rabbit/usagi.x", "asset/model/Rabbit/texture2.jpg");
	scale.x = 15;
	scale.y = 15;
	scale.z = 15;
	inputRotZ = 0;
	inputRotX = 0;
}
void Hamster::Init() {
	model.Init("asset/model/ham/Hamster.x", "asset/model/ham/ham1.jpg");
	scale.x = 42;
	scale.y = 42;
	scale.z = 42;
	inputRotZ = 0;
	inputRotX = 0;
}


//各キャラクターの描画処理
void Character::Draw() {

}
void Elephant::Draw() {

}
void Bear::Draw() {

	//ポリゴンのワールド行列の作成
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxInputRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);


	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f+ inputRotX , rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);



	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model.Draw();

}
void Dog::Draw() {
	//ポリゴンのワールド行列の作成
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxInputRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, 0, 0.35f, 0);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f + inputRotX, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model.Draw();
}
void Rabbit::Draw() {
	//ポリゴンのワールド行列の作成
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxInputRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);


	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f+ inputRotX , rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);



	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model.Draw();
}
void Hamster::Draw() {
	//ポリゴンのワールド行列の作成
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxInputRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);


	

	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f + inputRotX, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model.Draw();
}


//各キャラクターの終了処理
void Character::UnInit() {
	model.UnInit();
}
void Elephant::UnInit() {

}
void Bear::UnInit() {
	model.UnInit();
}
void Dog::UnInit() {
	model.UnInit();
}
void Rabbit::UnInit() {
	model.UnInit();
}
void Hamster::UnInit() {

}





//最高速維持でｼﾁｮｳﾘﾂ（スコア）を加点
float Character::GetMaxSpeed() {
	return maxSpeed;
}

float Elephant::GetMaxSpeed() {
	return maxSpeed;
}

float Bear::GetMaxSpeed() {
	return maxSpeed;
}

float Dog::GetMaxSpeed() {
	return maxSpeed;
}

float Rabbit::GetMaxSpeed() {
	return maxSpeed;
}

float Hamster::GetMaxSpeed() {
	return maxSpeed;
}