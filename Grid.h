#pragma once
#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>

class Grid {
private:
	//サンプルポリゴンの表示自体に関するパラメータ
	D3DXVECTOR3 g_pos;		                      //地面の位置
	D3DXVECTOR3 g_rot;	                         //地面の向き
	D3DXVECTOR3 g_scl;                          //地面の大きさ
	D3DXMATRIX g_mtxWorld;                     //ワールドマトリクス
	LPDIRECT3DVERTEXBUFFER9 g_pD3DVtxBuff;    //頂点バッファ
public:
	D3DXVECTOR3 position{ 0,0,0 };
	D3DXVECTOR3 rotation{ 0,0,0 };
	D3DXVECTOR3 scale{ 1,1,1 };

	void Draw();
};