#pragma once
#include"Collision.h"
#include"texture.h"

class Cube {
private:
	//サンプルポリゴンの表示自体に関するパラメータ
	D3DXVECTOR3 g_pos;		                      //地面の位置
	D3DXVECTOR3 g_rot;	                         //地面の向き
	D3DXVECTOR3 g_scl;                          //地面の大きさ
	D3DXMATRIX g_mtxWorld;                     //ワールドマトリクス

public:
	D3DXVECTOR3 position{0,0,0};
	D3DXVECTOR3 rotation{0,0,0};
	D3DXVECTOR3 scale{1,1,1};
	Collider3D collider;

	Cube(){}
	Cube(D3DXVECTOR3 pos) {
		position = pos;
	}
	void Draw(TextureIndex textureIndex, D3DXCOLOR color={1,1,1,1});

	D3DXVECTOR3 GetForward(); //正面を取得
	D3DXVECTOR3 GetRight();  //右側取得
	D3DXVECTOR3 GetUp();    //上取得
};

