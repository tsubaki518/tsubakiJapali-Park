#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"XFile.h"
#include<string>


#define FVF_VERTEX_3D (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)

// メッシュの読み込み
BOOL XFile::Init(const char* fileName, const char* textureName)
{
	LPDIRECT3DDEVICE9	pDev;
	pDev = MyDirect3D_GetDevice();
	LPD3DXBUFFER lpD3DXBuffer = NULL;	// 一時的なメモリエリア

	// Ｘファイルの読み込み
	D3DXLoadMeshFromX(
		fileName,
		D3DXMESH_MANAGED,
		pDev,
		NULL,
		&lpD3DXBuffer,
		NULL,
		&(model.NumMaterial),
		&(model.lpMesh)
	);

	// lpD3DXBuffer が NULL なら読み込みの失敗
	if (lpD3DXBuffer == NULL)	return FALSE;


	// マテリアル数文の配列を確保する
	model.Mat = new D3DMATERIAL9[model.NumMaterial];
	model.Tex = new LPDIRECT3DTEXTURE9[model.NumMaterial];

	D3DXMATERIAL* D3DXMat = (D3DXMATERIAL*)lpD3DXBuffer->GetBufferPointer();

	for (DWORD i = 0; i < model.NumMaterial; i++)
	{
		model.Mat[i] = D3DXMat[i].MatD3D;
		model.Mat[i].Ambient = model.Mat[i].Diffuse;

		// テクスチャの読み込み
		if (FAILED(D3DXCreateTextureFromFile(pDev, textureName, &(model.Tex[i]))))
		{
			model.Tex[i] = NULL;
		}
	}

	lpD3DXBuffer->Release();

	return TRUE;
}


void XFile::Draw()
{
	//ポリゴンのワールド行列の作成
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
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y+3.1415f, rotation.x-0.1f, rotation.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

	//平行行列
	D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
	D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


	//ワールドマトリクスを設定
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);



	for (DWORD i = 0; i < model.NumMaterial; i++)
	{
		g_pd3dDevice->SetMaterial(&model.Mat[i]);	// マテリアル
		g_pd3dDevice->SetTexture(0, model.Tex[i]);	// テクスチャ
		model.lpMesh->DrawSubset(i);				// メッシュ
	}

}
void XFile::UnInit()
{
	// マテリアル
	if (model.Mat != NULL)	delete[]	model.Mat;

	// テクスチャ
	if (model.Tex != NULL)
	{
		for (DWORD i = 0; i < model.NumMaterial; i++)
		{
			if (model.Tex[i])	model.Tex[i]->Release();
		}
	}

}

D3DXVECTOR3 XFile::GetForward() {
	D3DXMATRIX matrixWorld;    //ワールド行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y , rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 XFile::GetRight() {
	D3DXMATRIX matrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;
	D3DXVECTOR3 direction;
	direction.x = 1;
	direction.y = 0;
	direction.z = 0;

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
	direction.y *= -1;
	return direction;
}
D3DXVECTOR3 XFile::GetUp() {
	D3DXMATRIX matrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 1;
	direction.z = 0;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y , rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}