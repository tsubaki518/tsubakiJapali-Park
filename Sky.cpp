#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"Sky.h"


Sky::Sky() {

}
void Sky::Draw() {
	MyDirect3D_GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);				// Zバッファーの書き込みをしない

	const int PLANE_NUM = 4;
	const float PLANE_SIZE = 10000;
	const D3DXVECTOR3 SKY_POSITION = D3DXVECTOR3(0, 0, -20);
	Cube sky[PLANE_NUM];

	//スタート地点から見て左右前後に壁を設置して空を作る
	//後ろの壁
	sky[0].scale = D3DXVECTOR3(PLANE_SIZE, PLANE_SIZE, 0);
	sky[0].position = D3DXVECTOR3(0, 0, 0);
	sky[0].rotation = D3DXVECTOR3(0, 0, 0);

	//右
	sky[1].scale = D3DXVECTOR3(0, PLANE_SIZE, PLANE_SIZE);
	sky[1].position = D3DXVECTOR3(PLANE_SIZE/2, 0, PLANE_SIZE/2);
	sky[1].rotation = D3DXVECTOR3(0, 0, 0);

	//左
	sky[2].scale = D3DXVECTOR3(0, PLANE_SIZE, PLANE_SIZE);
	sky[2].position = D3DXVECTOR3(-PLANE_SIZE / 2, 0, PLANE_SIZE / 2);
	sky[2].rotation = D3DXVECTOR3(0, 0, 0);

	//前
	sky[3].scale = D3DXVECTOR3(PLANE_SIZE, PLANE_SIZE, 0);
	sky[3].position = D3DXVECTOR3(0, 0, PLANE_SIZE);
	sky[3].rotation = D3DXVECTOR3(0, 0, 0);

	for (int i = 0; i < PLANE_NUM; i++) {
		sky[i].position += SKY_POSITION;
		sky[i].Draw(TEXTURE_INDEX_SKY);
	}
	MyDirect3D_GetDevice()->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);				// Zバッファーの書き込みをしない

}
Sky::~Sky() {

}