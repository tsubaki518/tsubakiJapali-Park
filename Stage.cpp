#include"figure.h"
#include"Stage.h"

const int CUBE_NUM = 10;

Cube cube[CUBE_NUM];

void StageInit() {
	//座標とサイズと角度を入れる
	cube[0].position = D3DXVECTOR3(0,0,0);
	cube[0].rotation = D3DXVECTOR3(0, 0, 0);
	cube[0].scale = D3DXVECTOR3(10, 0, 10);

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