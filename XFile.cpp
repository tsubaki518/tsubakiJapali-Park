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
	//3Dポリゴン用頂点の準備
	LPDIRECT3DDEVICE9 g_pd3dDevice = MyDirect3D_GetDevice();	//モデルの描画

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


