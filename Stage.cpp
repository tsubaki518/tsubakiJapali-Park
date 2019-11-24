#include"figure.h"
#include"Stage.h"


const int CUBE_NUM = 30;	//最大設置数
const int RIGHT_WALL_NUM = 10;
const int LEFT_WALL_NUM = 10;

//rotationのx,zは1.4ｆまで
Cube cube[CUBE_NUM];			//床
Cube rightWall[RIGHT_WALL_NUM];//右側の壁
Cube leftWall[LEFT_WALL_NUM];  //左側の壁


void StageInit() {			//座標とサイズと角度を入れる

  //床
	cube[0].position = D3DXVECTOR3(0,0,0);
	cube[0].rotation = D3DXVECTOR3(0.17f, 1, 0);
	cube[0].scale = D3DXVECTOR3(10, 0, 10);
	
	cube[1].position = D3DXVECTOR3(0, -1.7f, 9.63f);
	cube[1].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[1].scale = D3DXVECTOR3(10, 0, 10);

	cube[2].position = D3DXVECTOR3(0, -3.38f, 19.13f);
	cube[2].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[2].scale = D3DXVECTOR3(10, 0, 10);

	cube[3].position = D3DXVECTOR3(0, -5.06f, 28.71f);
	cube[3].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[3].scale = D3DXVECTOR3(10, 0, 10);

	cube[4].position = D3DXVECTOR3(0, -6.73f, 38.21f);
	cube[4].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[4].scale = D3DXVECTOR3(10, 0, 10);

	cube[5].position = D3DXVECTOR3(0, -8.39f, 47.6f);
	cube[5].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[5].scale = D3DXVECTOR3(10, 0, 10);

	cube[6].position = D3DXVECTOR3(0, -10.06f, 57.1f);
	cube[6].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[6].scale = D3DXVECTOR3(10, 0, 10);

	cube[7].position = D3DXVECTOR3(0, -11.64f, 66.05f);
	cube[7].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[7].scale = D3DXVECTOR3(10, 0, 10);

	cube[8].position = D3DXVECTOR3(0, -13.26f, 75.26f);
	cube[8].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[8].scale = D3DXVECTOR3(10, 0, 10);

	cube[9].position = D3DXVECTOR3(0, -14.88f, 84.44f);
	cube[9].rotation = D3DXVECTOR3(0.17f, 0, 0);
	cube[9].scale = D3DXVECTOR3(10, 0, 10);

  //右下床
	cube[10].position = D3DXVECTOR3(5, 0, 0);
	cube[10].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[10].scale = D3DXVECTOR3(10, 0, 10);
	
	cube[11].position = D3DXVECTOR3(5, -1.7f, 9.63f);
	cube[11].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[11].scale = D3DXVECTOR3(10, 0, 10);
	
	cube[12].position = D3DXVECTOR3(5, -3.38f, 19.13f);
	cube[12].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[12].scale = D3DXVECTOR3(10, 0, 10);

	cube[13].position = D3DXVECTOR3(5, -5.06f, 28.71f);
	cube[13].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[13].scale = D3DXVECTOR3(10, 0, 10);

	cube[14].position = D3DXVECTOR3(5, -6.73f, 38.21f);
	cube[14].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[14].scale = D3DXVECTOR3(10, 0, 10);

	cube[15].position = D3DXVECTOR3(5, -8.39f, 47.6f);
	cube[15].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[15].scale = D3DXVECTOR3(10, 0, 10);

	cube[16].position = D3DXVECTOR3(5, -10.06f, 57.1f);
	cube[16].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[16].scale = D3DXVECTOR3(10, 0, 10);

	cube[17].position = D3DXVECTOR3(5, -11.64f, 66.05f);
	cube[17].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[17].scale = D3DXVECTOR3(10, 0, 10);

	cube[18].position = D3DXVECTOR3(5, -13.26f, 75.26f);
	cube[18].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[18].scale = D3DXVECTOR3(10, 0, 10);

	cube[19].position = D3DXVECTOR3(5, -14.88f, 84.44f);
	cube[19].rotation = D3DXVECTOR3(0.17f, 0, 0.69f);
	cube[19].scale = D3DXVECTOR3(10, 0, 10);


  //左下床
	cube[20].position = D3DXVECTOR3(-5, 0, 0);
	cube[20].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[20].scale = D3DXVECTOR3(10, 0, 10);

	cube[21].position = D3DXVECTOR3(-5, -1.7f, 9.63f);
	cube[21].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[21].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[22].position = D3DXVECTOR3(-5, -3.38f, 19.13f);
	cube[22].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[22].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[23].position = D3DXVECTOR3(-5, -5.06f, 28.71f);
	cube[23].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[23].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[24].position = D3DXVECTOR3(-5, -6.73f, 38.21f);
	cube[24].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[24].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[25].position = D3DXVECTOR3(-5, -8.39f, 47.6f);
	cube[25].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[25].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[26].position = D3DXVECTOR3(-5, -10.06f, 57.1f);
	cube[26].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[26].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[27].position = D3DXVECTOR3(-5, -11.64f, 66.05f);
	cube[27].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[27].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[28].position = D3DXVECTOR3(-5, -13.26f, 75.26f);
	cube[28].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[28].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[29].position = D3DXVECTOR3(-5, -14.88f, 84.44f);
	cube[29].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[29].scale = D3DXVECTOR3(10, 0, 10);


	//右壁
	rightWall[0].position = D3DXVECTOR3(7.5f, 0, 0);
	rightWall[0].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[0].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[1].position = D3DXVECTOR3(7.5f, -1.7f, 9.63f);
	rightWall[1].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[1].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[2].position = D3DXVECTOR3(7.5f, -3.38f, 19.13f);
	rightWall[2].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[2].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[3].position = D3DXVECTOR3(7.5f, -5.06f, 28.71f);
	rightWall[3].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[3].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[4].position = D3DXVECTOR3(7.5f, -6.73f, 38.21f);
	rightWall[4].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[4].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[5].position = D3DXVECTOR3(7.5f, -8.39f, 47.6f);
	rightWall[5].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[5].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[6].position = D3DXVECTOR3(7.5f, -10.06f, 57.1f);
	rightWall[6].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[6].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[7].position = D3DXVECTOR3(7.5f, -11.64f, 66.05f);
	rightWall[7].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[7].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[8].position = D3DXVECTOR3(7.5f, -13.26f, 75.26f);
	rightWall[8].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[8].scale = D3DXVECTOR3(10, 0, 10);

	rightWall[9].position = D3DXVECTOR3(7.5f, -14.88f, 84.44f);
	rightWall[9].rotation = D3DXVECTOR3(0.17f, 0, 1.4f);
	rightWall[9].scale = D3DXVECTOR3(10, 0, 10);



  //左壁
	leftWall[0].position = D3DXVECTOR3(-7.5f, 0, 0);
	leftWall[0].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[0].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[1].position = D3DXVECTOR3(-7.5f, -1.7f, 9.63f);
	leftWall[1].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[1].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[2].position = D3DXVECTOR3(-7.5f, -3.38f, 19.13f);
	leftWall[2].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[2].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[3].position = D3DXVECTOR3(-7.5f, -5.06f, 28.71f);
	leftWall[3].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[3].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[4].position = D3DXVECTOR3(-7.5f, -6.73f, 38.21f);
	leftWall[4].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[4].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[5].position = D3DXVECTOR3(-7.5f, -8.39f, 47.6f);
	leftWall[5].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[5].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[6].position = D3DXVECTOR3(-7.5f, -10.06f, 57.1f);
	leftWall[6].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[6].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[7].position = D3DXVECTOR3(-7.5f, -11.64f, 66.05f);
	leftWall[7].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[7].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[8].position = D3DXVECTOR3(-7.5f, -13.26f, 75.26f);
	leftWall[8].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[8].scale = D3DXVECTOR3(10, 0, 10);
		 
	leftWall[9].position = D3DXVECTOR3(-7.5f, -14.88f, 84.44f);
	leftWall[9].rotation = D3DXVECTOR3(0.17f, 0, -1.4f);
	leftWall[9].scale = D3DXVECTOR3(10, 0, 10);

}


void StageDraw() {
	//Cubeの描画
	for (int i = 0; i < CUBE_NUM; i++) {
		cube[i].Draw(TEXTURE_INDEX_ICE);
	}
	for (int i = 0; i < RIGHT_WALL_NUM; i++) {
		rightWall[i].Draw(TEXTURE_INDEX_ICE);
	}
	for (int i = 0; i < LEFT_WALL_NUM; i++) {
		leftWall[i].Draw(TEXTURE_INDEX_ICE);
	}
}


Cube GetCube(int n) {
	return cube[n];
}
Cube GetRightWall(int n) {
	return rightWall[n];
}
Cube GetLeftWall(int n) {
	return leftWall[n];
}

int GetCubeNum() {
	return CUBE_NUM;
}
int GetRightWallNum() {
	return RIGHT_WALL_NUM;
}
int GetLeftWallNum(){
	return LEFT_WALL_NUM;
}