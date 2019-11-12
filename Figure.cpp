#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Figure.h"


//===============================================
//ここを追加　3D用追加コード
typedef struct {
	D3DXVECTOR3 vtx;  //頂点座標
	D3DXVECTOR3 nor;  //法線ベクトル
	D3DCOLOR diffuse;  //反射光
	D3DXVECTOR2 tex;  //テクスチャ座座標
}VERTEX_3D;

//3Dポリゴンフォーマット
#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)
static LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuff;    //頂点バッファ	
static bool isOnece = false;

void Cube::Draw(TextureIndex textureIndex, D3DXCOLOR color) {
	const float sizeX = 0.5f;
	const float sizeY = 0.5f;
	const float sizeZ = 0.5f;
	collider.position = position;
	collider.size = scale;
	collider.rotation = rotation;
	//3Dポリゴン用頂点の準備
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	if (isOnece == false) {


		//オブジェクトの頂点バッファを生成
		pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 36,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&g_pD3DVtxBuff,
			NULL);

		//頂点バッファの中身を埋める
		VERTEX_3D *pVtx;

		//頂点バッファの範囲をロックし、頂点バッファへのポインタを取得
		g_pD3DVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

		//3Dポリゴン用頂点の準備
		{
			//頂点座標の設定
			{
				pVtx[0].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);  //1
				pVtx[1].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);   //2
				pVtx[2].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);  //3

				pVtx[3].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);
				pVtx[4].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				pVtx[5].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				/////////////////////////////////////
				pVtx[6].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[7].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				pVtx[8].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);

				pVtx[9].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[10].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				pVtx[11].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				///////////////////////////////////////////
				pVtx[12].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[14].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				pVtx[13].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);

				pVtx[15].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[17].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[16].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);
				///////////////////////////////////////

				pVtx[18].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);  //1
				pVtx[19].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);  //3
				pVtx[20].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);   //2

				pVtx[21].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[22].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[23].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				/////////////////////////////////////

				pVtx[24].vtx = D3DXVECTOR3(-sizeX, sizeY, -sizeZ);  //1
				pVtx[25].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);  //3
				pVtx[26].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);   //2

				pVtx[27].vtx = D3DXVECTOR3(-sizeX, sizeY, sizeZ);
				pVtx[28].vtx = D3DXVECTOR3(sizeX, sizeY, sizeZ);
				pVtx[29].vtx = D3DXVECTOR3(sizeX, sizeY, -sizeZ);
				/////////////////////////////////////
				pVtx[30].vtx = D3DXVECTOR3(-sizeX, -sizeY, -sizeZ);  //1
				pVtx[32].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);  //3
				pVtx[31].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);   //2

				pVtx[33].vtx = D3DXVECTOR3(-sizeX, -sizeY, sizeZ);
				pVtx[35].vtx = D3DXVECTOR3(sizeX, -sizeY, sizeZ);
				pVtx[34].vtx = D3DXVECTOR3(sizeX, -sizeY, -sizeZ);
				/////////////////////////////////////
			}
			//法線ベクトルの設定
			{
				for (int i = 0; i < 6; i++) {
					pVtx[i].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 6].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 12].nor = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 18].nor = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 24].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
				}

				for (int i = 0; i < 6; i++) {
					pVtx[i + 30].nor = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
				}
			}
			//反射光の設定
			{
				for (int i = 0; i < 36; i++) {
					pVtx[i].diffuse = color;
				}
			}
			////テクスチャの設定
			{
				pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[3].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[4].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[5].tex = D3DXVECTOR2(0.0f, 1.0f);
				/////////////////////////////////////////////////////

				pVtx[6].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[7].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[8].tex = D3DXVECTOR2(0.0f, 0.0f);

				pVtx[9].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[10].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[11].tex = D3DXVECTOR2(0.0f, 1.0f);
				//////////////////////////////////////////////////////////

				pVtx[12].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[13].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[14].tex = D3DXVECTOR2(1.0f, 1.0f);

				pVtx[15].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[16].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[17].tex = D3DXVECTOR2(1.0f, 0.0f);
				////////////////////////////////////////////////////////

				pVtx[18].tex = D3DXVECTOR2(0.0f, 0.0f);
				pVtx[19].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[20].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[21].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[22].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[23].tex = D3DXVECTOR2(1.0f, 1.0f);
				////////////////////////////////////////////////

				pVtx[24].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[25].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[26].tex = D3DXVECTOR2(1.0f, 0.0f);

				pVtx[27].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[28].tex = D3DXVECTOR2(0.0f, 0.0f);

				pVtx[29].tex = D3DXVECTOR2(1.0f, 0.0f);
				////////////////////////////////////////////////////////

				pVtx[30].tex = D3DXVECTOR2(1.0f, 1.0f);
				pVtx[31].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[32].tex = D3DXVECTOR2(0.0f, 1.0f);

				pVtx[33].tex = D3DXVECTOR2(0.0f, 1.0f);
				pVtx[34].tex = D3DXVECTOR2(1.0f, 0.0f);
				pVtx[35].tex = D3DXVECTOR2(0.0f, 0.0f);
			}
		}

		g_pD3DVtxBuff->Unlock();
		isOnece = true;
	}

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
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetTexture(0, Texture_GetTexture(textureIndex));
	pDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 12);

}
D3DXVECTOR3 Cube::GetForward() {
	D3DXVECTOR3 forward;//正面
	forward.x = sinf(rotation.y);
	forward.z = cosf(rotation.y);
	forward.y = -sinf(rotation.x);

	return forward;
}
D3DXVECTOR3 Cube::GetRight() {
	D3DXVECTOR3 right;
	right.x = cosf(rotation.y);
	right.y = sinf(rotation.z);
	right.z = -sinf(rotation.y);
	return right;
}
D3DXVECTOR3 Cube::GetUp() {
	D3DXVECTOR3 up;
	up.x = -sinf(rotation.z);
	up.y = cosf(rotation.x);
	up.z = sinf(rotation.x);
	return up;
}
