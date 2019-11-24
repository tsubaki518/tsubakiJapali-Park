#include"character.h"
#include"input.h"


//各キャラクターの初期化
void Character::Init(){
	inputRotZ = 0;
}
void Elephant::Init() {
	inputRotZ = 0;
}
void Bear::Init() {
	model = new XFile();
	model->Init("asset/model/Bear/bear.x", "asset/model/Bear/bearuv.jpg");
	scale.x = 30;
	scale.y = 30;
	scale.z = 30;
	inputRotZ = 0;
}
void Dog::Init() {
	inputRotZ = 0;
}
void Rabbit::Init() {
	inputRotZ = 0;
}
void Hamster::Init() {
	inputRotZ = 0;
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
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);



	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	model->Draw();

}
void Dog::Draw() {

}
void Rabbit::Draw() {

}
void Hamster::Draw() {

}


//各キャラクターの終了処理
void Character::UnInit() {
}
void Elephant::UnInit() {

}
void Bear::UnInit() {
	model->UnInit();
	delete model;
}
void Dog::UnInit() {

}
void Rabbit::UnInit() {

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