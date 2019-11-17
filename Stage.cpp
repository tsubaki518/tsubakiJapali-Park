#include"figure.h"
#include"Stage.h"


const int CUBE_NUM = 50;	//最大設置数


Cube cube[CUBE_NUM];


void StageInit() {			//座標とサイズと角度を入れる

  //床
	cube[0].position = D3DXVECTOR3(0,0,0);
	cube[0].rotation = D3DXVECTOR3(0.17f, 0, 0);
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

  //右壁
	cube[20].position = D3DXVECTOR3(7.5f, 0, 0);
	cube[20].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[20].scale = D3DXVECTOR3(10, 0, 10);

	cube[21].position = D3DXVECTOR3(7.5f, -1.7f, 9.63f);
	cube[21].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[21].scale = D3DXVECTOR3(10, 0, 10);

	cube[22].position = D3DXVECTOR3(7.5f, -3.38f, 19.13f);
	cube[22].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[22].scale = D3DXVECTOR3(10, 0, 10);

	cube[23].position = D3DXVECTOR3(7.5f, -5.06f, 28.71f);
	cube[23].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[23].scale = D3DXVECTOR3(10, 0, 10);

	cube[24].position = D3DXVECTOR3(7.5f, -6.73f, 38.21f);
	cube[24].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[24].scale = D3DXVECTOR3(10, 0, 10);

	cube[25].position = D3DXVECTOR3(7.5f, -8.39f, 47.6f);
	cube[25].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[25].scale = D3DXVECTOR3(10, 0, 10);

	cube[26].position = D3DXVECTOR3(7.5f, -10.06f, 57.1f);
	cube[26].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[26].scale = D3DXVECTOR3(10, 0, 10);

	cube[27].position = D3DXVECTOR3(7.5f, -11.64f, 66.05f);
	cube[27].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[27].scale = D3DXVECTOR3(10, 0, 10);

	cube[28].position = D3DXVECTOR3(7.5f, -13.26f, 75.26f);
	cube[28].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[28].scale = D3DXVECTOR3(10, 0, 10);

	cube[29].position = D3DXVECTOR3(7.5f, -14.88f, 84.44f);
	cube[29].rotation = D3DXVECTOR3(0.17f, 0, 1.57f);
	cube[29].scale = D3DXVECTOR3(10, 0, 10);

  //左下床
	cube[30].position = D3DXVECTOR3(-5, 0, 0);
	cube[30].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[30].scale = D3DXVECTOR3(10, 0, 10);

	cube[31].position = D3DXVECTOR3(-5, -1.7f, 9.63f);
	cube[31].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[31].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[32].position = D3DXVECTOR3(-5, -3.38f, 19.13f);
	cube[32].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[32].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[33].position = D3DXVECTOR3(-5, -5.06f, 28.71f);
	cube[33].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[33].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[34].position = D3DXVECTOR3(-5, -6.73f, 38.21f);
	cube[34].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[34].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[35].position = D3DXVECTOR3(-5, -8.39f, 47.6f);
	cube[35].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[35].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[36].position = D3DXVECTOR3(-5, -10.06f, 57.1f);
	cube[36].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[36].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[37].position = D3DXVECTOR3(-5, -11.64f, 66.05f);
	cube[37].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[37].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[38].position = D3DXVECTOR3(-5, -13.26f, 75.26f);
	cube[38].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[38].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[39].position = D3DXVECTOR3(-5, -14.88f, 84.44f);
	cube[39].rotation = D3DXVECTOR3(0.17f, 0, -0.69f);
	cube[39].scale = D3DXVECTOR3(10, 0, 10);

  //左壁
	cube[40].position = D3DXVECTOR3(-7.5f, 0, 0);
	cube[40].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[40].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[41].position = D3DXVECTOR3(-7.5f, -1.7f, 9.63f);
	cube[41].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[41].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[42].position = D3DXVECTOR3(-7.5f, -3.38f, 19.13f);
	cube[42].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[42].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[43].position = D3DXVECTOR3(-7.5f, -5.06f, 28.71f);
	cube[43].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[43].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[44].position = D3DXVECTOR3(-7.5f, -6.73f, 38.21f);
	cube[44].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[44].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[45].position = D3DXVECTOR3(-7.5f, -8.39f, 47.6f);
	cube[45].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[45].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[46].position = D3DXVECTOR3(-7.5f, -10.06f, 57.1f);
	cube[46].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[46].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[47].position = D3DXVECTOR3(-7.5f, -11.64f, 66.05f);
	cube[47].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[47].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[48].position = D3DXVECTOR3(-7.5f, -13.26f, 75.26f);
	cube[48].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[48].scale = D3DXVECTOR3(10, 0, 10);
		 
	cube[49].position = D3DXVECTOR3(-7.5f, -14.88f, 84.44f);
	cube[49].rotation = D3DXVECTOR3(0.17f, 0, -1.57f);
	cube[49].scale = D3DXVECTOR3(10, 0, 10);

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