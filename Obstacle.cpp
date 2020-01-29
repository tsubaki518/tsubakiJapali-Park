#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"
#include"NPC.h"

void Obstacle::Init() {
	collider.size= D3DXVECTOR3(1.2f, 3.0f, 1.2f);
	frameCount = 0;
	isBrokenPlayer = false;
	isBrokenNPC = false;
	model.Init("asset/model/yukidaruma/雪ダルマ.x", "asset/model/yukidaruma/yukidaruma.png");
}
void Obstacle::Update() {
	BoxCollider boxCollider;
	collider.position = position;
	

	//衝突判定
	bool isHitPlayer = boxCollider.Collider(collider, GetPlayer()->objCollider);
	bool isHitNPC = boxCollider.Collider(collider, GetNPC()->objCollider);

	//ゲーム開始時に最初のフレームだけpositionがバグるので1フレーム目だけ処理しない
	if (frameCount > 3) {
		//プレイヤーに衝突した場合
		if (isHitPlayer == true) {
			isBrokenPlayer = true;

			//スピン中は減速しない
			if (GetPlayer()->isSpin == false) {
				GetPlayer()->speed *= 0.5f;
				GetPlayer()->speedAccel *= 0.5f;
				GetPlayer()->slidCount *= 0.5f;
			}
		}

		//NPCに衝突した場合
		if (isHitNPC == true) {
			isBrokenNPC = true;

			//スピン中は減速しない
			if (GetNPC()->isSpin == false) {
				GetNPC()->speed *= 0.5f;
				GetNPC()->speedAccel *= 0.5f;
				GetNPC()->slidCount *= 0.5f;
			}
		}
	}

	//吹っ飛び処理
	//プレイヤーが当たった場合の吹っ飛び処理
	if (isBrokenPlayer == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetPlayer()->position - position);
		position += moveDirection *2;

	}

	//NPCが当たった場合の吹っ飛び処理
	if (isBrokenNPC == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetNPC()->position - position);
		position += moveDirection * 2;

	}

	frameCount++;
}
void Obstacle::Draw() {
	ModelDraw();

}
void Obstacle::UnInit() {
	model.UnInit();
}

void Obstacle::ModelDraw() {
	D3DXMATRIX g_mtxWorld;
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;
	LPDIRECT3DDEVICE9	g_pd3dDevice;
	g_pd3dDevice = MyDirect3D_GetDevice();
	const float SCALE = 65;


	// ワールド変換
	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, SCALE, SCALE, SCALE);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y-1.3f, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

	model.Draw();
}