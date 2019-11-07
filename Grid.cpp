#include"Grid.h"

typedef struct {
	D3DXVECTOR3 vtx;  //頂点座標
	D3DXVECTOR3 nor;  //法線ベクトル
	D3DCOLOR diffuse;  //反射光
	D3DXVECTOR2 tex;  //テクスチャ座座標
}VERTEX_3D;

//3Dポリゴンフォーマット
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)



void Grid::Draw() {
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;

	//3Dポリゴン用頂点の準備
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();

	//オブジェクトの頂点バッファを生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 72,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pD3DVtxBuff,
		NULL);

	//頂点バッファの中身を埋める
	VERTEX_3D *pVtx;

	//頂点バッファの範囲をロックし、頂点バッファへのポインタを取得
	g_pD3DVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//グリッド用頂点の準備
	{
		//頂点座標の設定
		{
			for (int i = 0; i < 36; i += 2) {
				pVtx[i].vtx = D3DXVECTOR3(0-4, 0, (float)i/2-8);
				pVtx[i+1].vtx = D3DXVECTOR3((float)10-4, 0, (float)i/2-8);
			}
			for (int i = 36; i < 57; i += 2) {
				pVtx[i].vtx = D3DXVECTOR3((float)(i-36)/2-4, 0, (float)36/2-1-8);
				pVtx[i+1].vtx = D3DXVECTOR3((float)(i-36)/2-4, 0, 0-8);
			}
	
		}
		//法線ベクトルの設定
		{
			for (int i = 0; i < 72; i++) {
				pVtx[i].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
			}
		}
		//反射光の設定
		{
			for (int i = 0; i < 72; i++) {
				pVtx[i].diffuse = D3DXCOLOR(1,1,1,1);
			}
		}
	}

	g_pD3DVtxBuff->Unlock();



	//ポリゴンのワールド行列の作成
	D3DXMATRIX mtxScl;
	D3DXMATRIX mtxRot;
	D3DXMATRIX mtxTrs;

	g_pos = position;
	g_rot = rotation;
	g_scl = scale;

	//ワールド行列を単位行列へ初期化
	D3DXMatrixIdentity(&g_mtxWorld);

	//スケール行列を作成＆ワールド行列へ合成
	D3DXMatrixScaling(&mtxScl, g_scl.x, g_scl.y, g_scl.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

	//回転行列を作成＆ワールド行列へ合成
	D3DXMatrixRotationYawPitchRoll(&mtxRot, g_rot.y, g_rot.x, g_rot.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, g_pos.x, g_pos.y, g_pos.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);

	//ワールドマトリクスを設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);


	//描画したいポリゴン頂点バッファをデータストリームにセット
	pDevice->SetStreamSource(0, g_pD3DVtxBuff, 0, sizeof(VERTEX_3D));

	//ポリゴンの描画
	pDevice->SetFVF(FVF_VERTEX_3D);

	//ポリゴンの描画
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	pDevice->DrawPrimitive(D3DPT_LINELIST, 0, 50);
}
