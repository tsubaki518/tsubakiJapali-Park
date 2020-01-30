#include"SpeedAccel.h"

void SpeedAccel::Init() {
	model.Init("asset/model/アイスクリーム・・・かな/iceC.x", "asset/model/アイスクリーム・・・かな/iceC22.png");
	scale = D3DXVECTOR3(1, 1, 1)*0.7f;
	isHit = false;
}
void SpeedAccel::Draw() {
	if (isHit == false) {
		collider.position = position;
		collider.rotation = rotation;
		collider.size = D3DXVECTOR3(3, 3, 3);
		rotation.y += 0.1f;

		D3DXMATRIX g_mtxWorld;
		D3DXMATRIX mtxScl;
		D3DXMATRIX mtxRot;
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, 0, 0, 3.541592f);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);
		//回転行列を作成＆ワールド行列へ合成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

		//平行行列
		D3DXMatrixTranslation(&mtxTrs, position.x, position.y + 1.3f, position.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

		//ワールドマトリクスを設定
		g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);

		model.Draw();
	}
}
void SpeedAccel::UnInit() {
	model.UnInit();
}