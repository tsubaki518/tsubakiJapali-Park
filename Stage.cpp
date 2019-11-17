#include"figure.h"
#include"Stage.h"

const int CUBE_NUM = 10;

Cube cube[CUBE_NUM];

void StageInit() {			

	//座標とサイズと角度を入れる
	//床
	cube[0].position = D3DXVECTOR3(0,0,0);
	cube[0].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[0].scale = D3DXVECTOR3(10, 0, 10);

	cube[1].position = D3DXVECTOR3(0, -1.7, 9.6);
	cube[1].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[1].scale = D3DXVECTOR3(10, 0, 10);

	cube[2].position = D3DXVECTOR3(0, -3.3, 19.1);
	cube[2].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[2].scale = D3DXVECTOR3(10, 0, 10);

	cube[3].position = D3DXVECTOR3(0, -5.0, 28.7);
	cube[3].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[3].scale = D3DXVECTOR3(10, 0, 10);

	cube[4].position = D3DXVECTOR3(0, -6.7, 38.2);
	cube[4].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[4].scale = D3DXVECTOR3(10, 0, 10);

	cube[5].position = D3DXVECTOR3(0, -8.3, 47.6);
	cube[5].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[5].scale = D3DXVECTOR3(10, 0, 10);

	cube[6].position = D3DXVECTOR3(0, -10.0, 57.1);
	cube[6].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[6].scale = D3DXVECTOR3(10, 0, 10);

	cube[7].position = D3DXVECTOR3(0, -11.6, 66.0);
	cube[7].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[7].scale = D3DXVECTOR3(10, 0, 10);

	cube[8].position = D3DXVECTOR3(0, -13.2, 75.2);
	cube[8].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[8].scale = D3DXVECTOR3(10, 0, 10);

	cube[9].position = D3DXVECTOR3(0, -14.8, 84.4);
	cube[9].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[9].scale = D3DXVECTOR3(10, 0, 10);
	
	
	//右下床
	cube[10].position = D3DXVECTOR3(5.0, 15.3, -54.9);	//←何故か表示されない
	cube[10].rotation = D3DXVECTOR3(0.17, 0, 0.69);
	cube[10].scale = D3DXVECTOR3(10, 0, 10);
	/*
	cube[11].position = D3DXVECTOR3(0, 0, 0);
	cube[11].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[11].scale = D3DXVECTOR3(10, 0, 10);

	cube[12].position = D3DXVECTOR3(0, 0, 0);
	cube[12].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[12].scale = D3DXVECTOR3(10, 0, 10);

	cube[13].position = D3DXVECTOR3(0, 0, 0);
	cube[13].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[13].scale = D3DXVECTOR3(10, 0, 10);

	cube[14].position = D3DXVECTOR3(0, 0, 0);
	cube[14].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[14].scale = D3DXVECTOR3(10, 0, 10);

	cube[15].position = D3DXVECTOR3(0, 0, 0);
	cube[15].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[15].scale = D3DXVECTOR3(10, 0, 10);

	cube[16].position = D3DXVECTOR3(0, 0, 0);
	cube[16].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[16].scale = D3DXVECTOR3(10, 0, 10);

	cube[17].position = D3DXVECTOR3(0, 0, 0);
	cube[17].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[17].scale = D3DXVECTOR3(10, 0, 10);

	cube[18].position = D3DXVECTOR3(0, 0, 0);
	cube[18].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[18].scale = D3DXVECTOR3(10, 0, 10);

	cube[19].position = D3DXVECTOR3(0, 0, 0);
	cube[19].rotation = D3DXVECTOR3(0.17, 0, 0);
	cube[19].scale = D3DXVECTOR3(10, 0, 10);
	*/

}

void StageDraw() {
	//Cubeの描画
	for (int i = 0; i < CUBE_NUM; i++) {
		cube[i].Draw(TEXTURE_INDEX_ICE);
	}
}

Cube GetCube(int n) {
	return cube[n];
}

int GetCubeNum() {
	return CUBE_NUM;
}