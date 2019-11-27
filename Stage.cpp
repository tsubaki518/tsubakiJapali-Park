#include"figure.h"
#include"Stage.h"


//最大設置数
const int CUBE_NUM = 330;
const int RIGHT_WALL_NUM = 110;
const int LEFT_WALL_NUM = 110;


//rotationのx,zは1.4ｆまで
Cube cube[CUBE_NUM];			//床
Cube rightWall[RIGHT_WALL_NUM];	//右側の壁
Cube leftWall[LEFT_WALL_NUM];	//左側の壁
Cube goalCube;					//ゴール_床



void StageInit() {			//座標とサイズと角度を入れる
	//α_Stage
	cube[0].position = D3DXVECTOR3(0.36f, -144.81f, 796.55f);
	cube[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[0].scale = D3DXVECTOR3(10, 1, 10);

	cube[1].position = D3DXVECTOR3(0.36f, -146.51f, 806.18f);
	cube[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[1].scale = D3DXVECTOR3(10, 1, 10);

	cube[2].position = D3DXVECTOR3(0.36f, -148.19f, 815.68f);
	cube[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[2].scale = D3DXVECTOR3(10, 1, 10);

	cube[3].position = D3DXVECTOR3(0.36f, -149.87f, 825.26f);
	cube[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[3].scale = D3DXVECTOR3(10, 1, 10);

	cube[4].position = D3DXVECTOR3(0.36f, -151.54f, 834.76f);
	cube[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[4].scale = D3DXVECTOR3(10, 1, 10);

	cube[5].position = D3DXVECTOR3(0.36f, -153.20f, 844.15f);
	cube[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[5].scale = D3DXVECTOR3(10, 1, 10);

	cube[6].position = D3DXVECTOR3(0.36f, -154.87f, 853.65f);
	cube[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[6].scale = D3DXVECTOR3(10, 1, 10);

	cube[7].position = D3DXVECTOR3(0.36f, -156.45f, 862.60f);
	cube[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[7].scale = D3DXVECTOR3(10, 1, 10);

	cube[8].position = D3DXVECTOR3(0.36f, -158.07f, 871.81f);
	cube[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[8].scale = D3DXVECTOR3(10, 1, 10);

	cube[9].position = D3DXVECTOR3(0.36f, -159.69f, 880.99f);
	cube[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[9].scale = D3DXVECTOR3(10, 1, 10);

	cube[10].position = D3DXVECTOR3(4.25f, -145.51f, 796.43f);
	cube[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[10].scale = D3DXVECTOR3(10, 1, 10);

	cube[11].position = D3DXVECTOR3(4.26f, -147.22f, 806.14f);
	cube[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[11].scale = D3DXVECTOR3(10, 1, 10);

	cube[12].position = D3DXVECTOR3(4.26f, -148.91f, 815.76f);
	cube[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[12].scale = D3DXVECTOR3(10, 1, 10);

	cube[13].position = D3DXVECTOR3(4.26f, -150.58f, 825.25f);
	cube[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[13].scale = D3DXVECTOR3(10, 1, 10);

	cube[14].position = D3DXVECTOR3(4.26f, -152.20f, 834.43f);
	cube[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[14].scale = D3DXVECTOR3(10, 1, 10);

	cube[15].position = D3DXVECTOR3(4.26f, -153.82f, 843.64f);
	cube[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[15].scale = D3DXVECTOR3(10, 1, 10);

	cube[16].position = D3DXVECTOR3(4.26f, -155.49f, 853.12f);
	cube[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[16].scale = D3DXVECTOR3(10, 1, 10);

	cube[17].position = D3DXVECTOR3(4.26f, -157.16f, 862.59f);
	cube[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[17].scale = D3DXVECTOR3(10, 1, 10);

	cube[18].position = D3DXVECTOR3(4.26f, -158.85f, 872.15f);
	cube[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[18].scale = D3DXVECTOR3(10, 1, 10);

	cube[19].position = D3DXVECTOR3(4.26f, -160.40f, 880.92f);
	cube[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[19].scale = D3DXVECTOR3(10, 1, 10);

	cube[20].position = D3DXVECTOR3(-3.80f, -145.42f, 796.45f);
	cube[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[20].scale = D3DXVECTOR3(10, 1, 10);

	cube[21].position = D3DXVECTOR3(-3.80f, -147.11f, 806.03f);
	cube[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[21].scale = D3DXVECTOR3(10, 1, 10);

	cube[22].position = D3DXVECTOR3(-3.80f, -148.40f, 813.39f);
	cube[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[22].scale = D3DXVECTOR3(10, 1, 10);

	cube[23].position = D3DXVECTOR3(-3.80f, -150.11f, 823.06f);
	cube[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[23].scale = D3DXVECTOR3(10, 1, 10);

	cube[24].position = D3DXVECTOR3(-3.80f, -151.80f, 832.65f);
	cube[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[24].scale = D3DXVECTOR3(10, 1, 10);

	cube[25].position = D3DXVECTOR3(-3.80f, -153.51f, 842.32f);
	cube[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[25].scale = D3DXVECTOR3(10, 1, 10);

	cube[26].position = D3DXVECTOR3(-3.80f, -155.22f, 852.01f);
	cube[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[26].scale = D3DXVECTOR3(10, 1, 10);

	cube[27].position = D3DXVECTOR3(-3.80f, -156.92f, 861.64f);
	cube[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[27].scale = D3DXVECTOR3(10, 1, 10);

	cube[28].position = D3DXVECTOR3(-3.80f, -158.64f, 871.38f);
	cube[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[28].scale = D3DXVECTOR3(10, 1, 10);

	cube[29].position = D3DXVECTOR3(-3.80f, -160.32f, 880.89f);
	cube[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[29].scale = D3DXVECTOR3(10, 1, 10);

	cube[30].position = D3DXVECTOR3(0.36f, -83.51f, 449.85f);
	cube[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[30].scale = D3DXVECTOR3(10, 1, 10);

	cube[31].position = D3DXVECTOR3(0.36f, -85.21f, 459.48f);
	cube[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[31].scale = D3DXVECTOR3(10, 1, 10);

	cube[32].position = D3DXVECTOR3(0.36f, -86.89f, 468.98f);
	cube[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[32].scale = D3DXVECTOR3(10, 1, 10);

	cube[33].position = D3DXVECTOR3(0.36f, -88.57f, 478.56f);
	cube[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[33].scale = D3DXVECTOR3(10, 1, 10);

	cube[34].position = D3DXVECTOR3(0.36f, -90.24f, 488.06f);
	cube[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[34].scale = D3DXVECTOR3(10, 1, 10);

	cube[35].position = D3DXVECTOR3(0.36f, -91.90f, 497.45f);
	cube[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[35].scale = D3DXVECTOR3(10, 1, 10);

	cube[36].position = D3DXVECTOR3(0.36f, -93.57f, 506.95f);
	cube[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[36].scale = D3DXVECTOR3(10, 1, 10);

	cube[37].position = D3DXVECTOR3(0.36f, -95.15f, 515.90f);
	cube[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[37].scale = D3DXVECTOR3(10, 1, 10);

	cube[38].position = D3DXVECTOR3(0.36f, -96.77f, 525.11f);
	cube[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[38].scale = D3DXVECTOR3(10, 1, 10);

	cube[39].position = D3DXVECTOR3(0.36f, -98.39f, 534.29f);
	cube[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[39].scale = D3DXVECTOR3(10, 1, 10);

	cube[40].position = D3DXVECTOR3(4.25f, -84.21f, 449.73f);
	cube[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[40].scale = D3DXVECTOR3(10, 1, 10);

	cube[41].position = D3DXVECTOR3(4.26f, -85.92f, 459.44f);
	cube[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[41].scale = D3DXVECTOR3(10, 1, 10);

	cube[42].position = D3DXVECTOR3(4.26f, -87.61f, 469.06f);
	cube[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[42].scale = D3DXVECTOR3(10, 1, 10);

	cube[43].position = D3DXVECTOR3(4.26f, -89.28f, 478.55f);
	cube[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[43].scale = D3DXVECTOR3(10, 1, 10);

	cube[44].position = D3DXVECTOR3(4.26f, -90.90f, 487.73f);
	cube[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[44].scale = D3DXVECTOR3(10, 1, 10);

	cube[45].position = D3DXVECTOR3(4.26f, -92.52f, 496.94f);
	cube[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[45].scale = D3DXVECTOR3(10, 1, 10);

	cube[46].position = D3DXVECTOR3(4.26f, -94.19f, 506.42f);
	cube[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[46].scale = D3DXVECTOR3(10, 1, 10);

	cube[47].position = D3DXVECTOR3(4.26f, -95.86f, 515.89f);
	cube[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[47].scale = D3DXVECTOR3(10, 1, 10);

	cube[48].position = D3DXVECTOR3(4.26f, -97.55f, 525.45f);
	cube[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[48].scale = D3DXVECTOR3(10, 1, 10);

	cube[49].position = D3DXVECTOR3(4.26f, -99.10f, 534.22f);
	cube[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[49].scale = D3DXVECTOR3(10, 1, 10);

	cube[50].position = D3DXVECTOR3(-3.80f, -84.12f, 449.75f);
	cube[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[50].scale = D3DXVECTOR3(10, 1, 10);

	cube[51].position = D3DXVECTOR3(-3.80f, -85.81f, 459.33f);
	cube[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[51].scale = D3DXVECTOR3(10, 1, 10);

	cube[52].position = D3DXVECTOR3(-3.80f, -87.10f, 466.69f);
	cube[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[52].scale = D3DXVECTOR3(10, 1, 10);

	cube[53].position = D3DXVECTOR3(-3.80f, -88.81f, 476.36f);
	cube[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[53].scale = D3DXVECTOR3(10, 1, 10);

	cube[54].position = D3DXVECTOR3(-3.80f, -90.50f, 485.95f);
	cube[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[54].scale = D3DXVECTOR3(10, 1, 10);

	cube[55].position = D3DXVECTOR3(-3.80f, -92.21f, 495.62f);
	cube[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[55].scale = D3DXVECTOR3(10, 1, 10);

	cube[56].position = D3DXVECTOR3(-3.80f, -93.92f, 505.31f);
	cube[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[56].scale = D3DXVECTOR3(10, 1, 10);

	cube[57].position = D3DXVECTOR3(-3.80f, -95.62f, 514.94f);
	cube[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[57].scale = D3DXVECTOR3(10, 1, 10);

	cube[58].position = D3DXVECTOR3(-3.80f, -97.34f, 524.68f);
	cube[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[58].scale = D3DXVECTOR3(10, 1, 10);

	cube[59].position = D3DXVECTOR3(-3.80f, -99.02f, 534.19f);
	cube[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[59].scale = D3DXVECTOR3(10, 1, 10);

	cube[60].position = D3DXVECTOR3(0.36f, -3.61f, -0.35f);
	cube[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[60].scale = D3DXVECTOR3(10, 1, 10);

	cube[61].position = D3DXVECTOR3(0.36f, -5.31f, 9.28f);
	cube[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[61].scale = D3DXVECTOR3(10, 1, 10);

	cube[62].position = D3DXVECTOR3(0.36f, -6.99f, 18.78f);
	cube[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[62].scale = D3DXVECTOR3(10, 1, 10);

	cube[63].position = D3DXVECTOR3(0.36f, -8.67f, 28.36f);
	cube[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[63].scale = D3DXVECTOR3(10, 1, 10);

	cube[64].position = D3DXVECTOR3(0.36f, -10.34f, 37.86f);
	cube[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[64].scale = D3DXVECTOR3(10, 1, 10);

	cube[65].position = D3DXVECTOR3(0.36f, -12.00f, 47.25f);
	cube[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[65].scale = D3DXVECTOR3(10, 1, 10);

	cube[66].position = D3DXVECTOR3(0.36f, -13.67f, 56.75f);
	cube[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[66].scale = D3DXVECTOR3(10, 1, 10);

	cube[67].position = D3DXVECTOR3(0.36f, -15.25f, 65.70f);
	cube[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[67].scale = D3DXVECTOR3(10, 1, 10);

	cube[68].position = D3DXVECTOR3(0.36f, -16.87f, 74.91f);
	cube[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[68].scale = D3DXVECTOR3(10, 1, 10);

	cube[69].position = D3DXVECTOR3(0.36f, -18.49f, 84.09f);
	cube[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[69].scale = D3DXVECTOR3(10, 1, 10);

	cube[70].position = D3DXVECTOR3(4.25f, -4.31f, -0.47f);
	cube[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[70].scale = D3DXVECTOR3(10, 1, 10);

	cube[71].position = D3DXVECTOR3(4.26f, -6.02f, 9.24f);
	cube[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[71].scale = D3DXVECTOR3(10, 1, 10);

	cube[72].position = D3DXVECTOR3(4.26f, -7.71f, 18.86f);
	cube[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[72].scale = D3DXVECTOR3(10, 1, 10);

	cube[73].position = D3DXVECTOR3(4.26f, -9.38f, 28.35f);
	cube[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[73].scale = D3DXVECTOR3(10, 1, 10);

	cube[74].position = D3DXVECTOR3(4.26f, -11.00f, 37.53f);
	cube[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[74].scale = D3DXVECTOR3(10, 1, 10);

	cube[75].position = D3DXVECTOR3(4.26f, -12.62f, 46.74f);
	cube[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[75].scale = D3DXVECTOR3(10, 1, 10);

	cube[76].position = D3DXVECTOR3(4.26f, -14.29f, 56.22f);
	cube[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[76].scale = D3DXVECTOR3(10, 1, 10);

	cube[77].position = D3DXVECTOR3(4.26f, -15.96f, 65.69f);
	cube[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[77].scale = D3DXVECTOR3(10, 1, 10);

	cube[78].position = D3DXVECTOR3(4.26f, -17.65f, 75.25f);
	cube[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[78].scale = D3DXVECTOR3(10, 1, 10);

	cube[79].position = D3DXVECTOR3(4.26f, -19.20f, 84.02f);
	cube[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[79].scale = D3DXVECTOR3(10, 1, 10);

	cube[80].position = D3DXVECTOR3(-3.80f, -4.22f, -0.45f);
	cube[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[80].scale = D3DXVECTOR3(10, 1, 10);

	cube[81].position = D3DXVECTOR3(-3.80f, -5.91f, 9.13f);
	cube[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[81].scale = D3DXVECTOR3(10, 1, 10);

	cube[82].position = D3DXVECTOR3(-3.80f, -7.20f, 16.49f);
	cube[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[82].scale = D3DXVECTOR3(10, 1, 10);

	cube[83].position = D3DXVECTOR3(-3.80f, -8.91f, 26.16f);
	cube[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[83].scale = D3DXVECTOR3(10, 1, 10);

	cube[84].position = D3DXVECTOR3(-3.80f, -10.60f, 35.75f);
	cube[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[84].scale = D3DXVECTOR3(10, 1, 10);

	cube[85].position = D3DXVECTOR3(-3.80f, -12.31f, 45.42f);
	cube[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[85].scale = D3DXVECTOR3(10, 1, 10);

	cube[86].position = D3DXVECTOR3(-3.80f, -14.02f, 55.11f);
	cube[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[86].scale = D3DXVECTOR3(10, 1, 10);

	cube[87].position = D3DXVECTOR3(-3.80f, -15.72f, 64.74f);
	cube[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[87].scale = D3DXVECTOR3(10, 1, 10);

	cube[88].position = D3DXVECTOR3(-3.80f, -17.44f, 74.48f);
	cube[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[88].scale = D3DXVECTOR3(10, 1, 10);

	cube[89].position = D3DXVECTOR3(-3.80f, -19.12f, 83.99f);
	cube[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[89].scale = D3DXVECTOR3(10, 1, 10);

	cube[90].position = D3DXVECTOR3(0.36f, -161.01f, 888.05f);
	cube[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[90].scale = D3DXVECTOR3(10, 1, 10);

	cube[91].position = D3DXVECTOR3(0.36f, -162.71f, 897.68f);
	cube[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[91].scale = D3DXVECTOR3(10, 1, 10);

	cube[92].position = D3DXVECTOR3(0.36f, -164.39f, 907.18f);
	cube[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[92].scale = D3DXVECTOR3(10, 1, 10);

	cube[93].position = D3DXVECTOR3(0.36f, -166.07f, 916.76f);
	cube[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[93].scale = D3DXVECTOR3(10, 1, 10);

	cube[94].position = D3DXVECTOR3(0.36f, -167.74f, 926.26f);
	cube[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[94].scale = D3DXVECTOR3(10, 1, 10);

	cube[95].position = D3DXVECTOR3(0.36f, -169.40f, 935.65f);
	cube[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[95].scale = D3DXVECTOR3(10, 1, 10);

	cube[96].position = D3DXVECTOR3(0.36f, -171.07f, 945.15f);
	cube[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[96].scale = D3DXVECTOR3(10, 1, 10);

	cube[97].position = D3DXVECTOR3(0.36f, -172.65f, 954.10f);
	cube[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[97].scale = D3DXVECTOR3(10, 1, 10);

	cube[98].position = D3DXVECTOR3(0.36f, -174.27f, 963.31f);
	cube[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[98].scale = D3DXVECTOR3(10, 1, 10);

	cube[99].position = D3DXVECTOR3(0.36f, -175.89f, 972.49f);
	cube[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[99].scale = D3DXVECTOR3(10, 1, 10);

	cube[100].position = D3DXVECTOR3(4.25f, -161.71f, 887.93f);
	cube[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[100].scale = D3DXVECTOR3(10, 1, 10);

	cube[101].position = D3DXVECTOR3(4.26f, -163.42f, 897.64f);
	cube[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[101].scale = D3DXVECTOR3(10, 1, 10);

	cube[102].position = D3DXVECTOR3(4.26f, -165.11f, 907.26f);
	cube[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[102].scale = D3DXVECTOR3(10, 1, 10);

	cube[103].position = D3DXVECTOR3(4.26f, -166.78f, 916.75f);
	cube[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[103].scale = D3DXVECTOR3(10, 1, 10);

	cube[104].position = D3DXVECTOR3(4.26f, -168.40f, 925.93f);
	cube[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[104].scale = D3DXVECTOR3(10, 1, 10);

	cube[105].position = D3DXVECTOR3(4.26f, -170.02f, 935.14f);
	cube[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[105].scale = D3DXVECTOR3(10, 1, 10);

	cube[106].position = D3DXVECTOR3(4.26f, -171.69f, 944.62f);
	cube[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[106].scale = D3DXVECTOR3(10, 1, 10);

	cube[107].position = D3DXVECTOR3(4.26f, -173.36f, 954.09f);
	cube[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[107].scale = D3DXVECTOR3(10, 1, 10);

	cube[108].position = D3DXVECTOR3(4.26f, -175.05f, 963.65f);
	cube[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[108].scale = D3DXVECTOR3(10, 1, 10);

	cube[109].position = D3DXVECTOR3(4.26f, -176.60f, 972.42f);
	cube[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[109].scale = D3DXVECTOR3(10, 1, 10);

	cube[110].position = D3DXVECTOR3(-3.80f, -161.62f, 887.95f);
	cube[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[110].scale = D3DXVECTOR3(10, 1, 10);

	cube[111].position = D3DXVECTOR3(-3.80f, -163.31f, 897.53f);
	cube[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[111].scale = D3DXVECTOR3(10, 1, 10);

	cube[112].position = D3DXVECTOR3(-3.80f, -164.60f, 904.89f);
	cube[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[112].scale = D3DXVECTOR3(10, 1, 10);

	cube[113].position = D3DXVECTOR3(-3.80f, -166.31f, 914.56f);
	cube[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[113].scale = D3DXVECTOR3(10, 1, 10);

	cube[114].position = D3DXVECTOR3(-3.80f, -168.00f, 924.15f);
	cube[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[114].scale = D3DXVECTOR3(10, 1, 10);

	cube[115].position = D3DXVECTOR3(-3.80f, -169.71f, 933.82f);
	cube[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[115].scale = D3DXVECTOR3(10, 1, 10);

	cube[116].position = D3DXVECTOR3(-3.80f, -171.42f, 943.51f);
	cube[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[116].scale = D3DXVECTOR3(10, 1, 10);

	cube[117].position = D3DXVECTOR3(-3.80f, -173.12f, 953.14f);
	cube[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[117].scale = D3DXVECTOR3(10, 1, 10);

	cube[118].position = D3DXVECTOR3(-3.80f, -174.84f, 962.88f);
	cube[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[118].scale = D3DXVECTOR3(10, 1, 10);

	cube[119].position = D3DXVECTOR3(-3.80f, -176.52f, 972.39f);
	cube[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[119].scale = D3DXVECTOR3(10, 1, 10);

	cube[120].position = D3DXVECTOR3(0.36f, -99.31f, 539.05f);
	cube[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[120].scale = D3DXVECTOR3(10, 1, 10);

	cube[121].position = D3DXVECTOR3(0.36f, -101.01f, 548.68f);
	cube[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[121].scale = D3DXVECTOR3(10, 1, 10);

	cube[122].position = D3DXVECTOR3(0.36f, -102.69f, 558.18f);
	cube[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[122].scale = D3DXVECTOR3(10, 1, 10);

	cube[123].position = D3DXVECTOR3(0.36f, -104.37f, 567.76f);
	cube[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[123].scale = D3DXVECTOR3(10, 1, 10);

	cube[124].position = D3DXVECTOR3(0.36f, -106.04f, 577.26f);
	cube[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[124].scale = D3DXVECTOR3(10, 1, 10);

	cube[125].position = D3DXVECTOR3(0.36f, -107.70f, 586.65f);
	cube[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[125].scale = D3DXVECTOR3(10, 1, 10);

	cube[126].position = D3DXVECTOR3(0.36f, -109.37f, 596.15f);
	cube[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[126].scale = D3DXVECTOR3(10, 1, 10);

	cube[127].position = D3DXVECTOR3(0.36f, -110.95f, 605.10f);
	cube[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[127].scale = D3DXVECTOR3(10, 1, 10);

	cube[128].position = D3DXVECTOR3(0.36f, -112.57f, 614.31f);
	cube[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[128].scale = D3DXVECTOR3(10, 1, 10);

	cube[129].position = D3DXVECTOR3(0.36f, -114.19f, 623.49f);
	cube[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[129].scale = D3DXVECTOR3(10, 1, 10);

	cube[130].position = D3DXVECTOR3(4.25f, -100.01f, 538.93f);
	cube[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[130].scale = D3DXVECTOR3(10, 1, 10);

	cube[131].position = D3DXVECTOR3(4.26f, -101.72f, 548.64f);
	cube[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[131].scale = D3DXVECTOR3(10, 1, 10);

	cube[132].position = D3DXVECTOR3(4.26f, -103.41f, 558.26f);
	cube[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[132].scale = D3DXVECTOR3(10, 1, 10);

	cube[133].position = D3DXVECTOR3(4.26f, -105.08f, 567.75f);
	cube[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[133].scale = D3DXVECTOR3(10, 1, 10);

	cube[134].position = D3DXVECTOR3(4.26f, -106.70f, 576.93f);
	cube[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[134].scale = D3DXVECTOR3(10, 1, 10);

	cube[135].position = D3DXVECTOR3(4.26f, -108.32f, 586.14f);
	cube[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[135].scale = D3DXVECTOR3(10, 1, 10);

	cube[136].position = D3DXVECTOR3(4.26f, -109.99f, 595.62f);
	cube[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[136].scale = D3DXVECTOR3(10, 1, 10);

	cube[137].position = D3DXVECTOR3(4.26f, -111.66f, 605.09f);
	cube[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[137].scale = D3DXVECTOR3(10, 1, 10);

	cube[138].position = D3DXVECTOR3(4.26f, -113.35f, 614.65f);
	cube[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[138].scale = D3DXVECTOR3(10, 1, 10);

	cube[139].position = D3DXVECTOR3(4.26f, -114.90f, 623.42f);
	cube[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[139].scale = D3DXVECTOR3(10, 1, 10);

	cube[140].position = D3DXVECTOR3(-3.80f, -99.92f, 538.95f);
	cube[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[140].scale = D3DXVECTOR3(10, 1, 10);

	cube[141].position = D3DXVECTOR3(-3.80f, -101.61f, 548.53f);
	cube[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[141].scale = D3DXVECTOR3(10, 1, 10);

	cube[142].position = D3DXVECTOR3(-3.80f, -102.90f, 555.89f);
	cube[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[142].scale = D3DXVECTOR3(10, 1, 10);

	cube[143].position = D3DXVECTOR3(-3.80f, -104.61f, 565.56f);
	cube[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[143].scale = D3DXVECTOR3(10, 1, 10);

	cube[144].position = D3DXVECTOR3(-3.80f, -106.30f, 575.15f);
	cube[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[144].scale = D3DXVECTOR3(10, 1, 10);

	cube[145].position = D3DXVECTOR3(-3.80f, -108.01f, 584.82f);
	cube[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[145].scale = D3DXVECTOR3(10, 1, 10);

	cube[146].position = D3DXVECTOR3(-3.80f, -109.72f, 594.51f);
	cube[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[146].scale = D3DXVECTOR3(10, 1, 10);

	cube[147].position = D3DXVECTOR3(-3.80f, -111.42f, 604.14f);
	cube[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[147].scale = D3DXVECTOR3(10, 1, 10);

	cube[148].position = D3DXVECTOR3(-3.80f, -113.14f, 613.88f);
	cube[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[148].scale = D3DXVECTOR3(10, 1, 10);

	cube[149].position = D3DXVECTOR3(-3.80f, -114.82f, 623.39f);
	cube[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[149].scale = D3DXVECTOR3(10, 1, 10);

	cube[150].position = D3DXVECTOR3(0.36f, -114.01f, 622.05f);
	cube[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[150].scale = D3DXVECTOR3(10, 1, 10);

	cube[151].position = D3DXVECTOR3(0.36f, -115.71f, 631.68f);
	cube[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[151].scale = D3DXVECTOR3(10, 1, 10);

	cube[152].position = D3DXVECTOR3(0.36f, -117.39f, 641.18f);
	cube[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[152].scale = D3DXVECTOR3(10, 1, 10);

	cube[153].position = D3DXVECTOR3(0.36f, -119.07f, 650.76f);
	cube[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[153].scale = D3DXVECTOR3(10, 1, 10);

	cube[154].position = D3DXVECTOR3(0.36f, -120.74f, 660.26f);
	cube[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[154].scale = D3DXVECTOR3(10, 1, 10);

	cube[155].position = D3DXVECTOR3(0.36f, -122.40f, 669.65f);
	cube[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[155].scale = D3DXVECTOR3(10, 1, 10);

	cube[156].position = D3DXVECTOR3(0.36f, -124.07f, 679.15f);
	cube[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[156].scale = D3DXVECTOR3(10, 1, 10);

	cube[157].position = D3DXVECTOR3(0.36f, -125.65f, 688.10f);
	cube[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[157].scale = D3DXVECTOR3(10, 1, 10);

	cube[158].position = D3DXVECTOR3(0.36f, -127.27f, 697.31f);
	cube[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[158].scale = D3DXVECTOR3(10, 1, 10);

	cube[159].position = D3DXVECTOR3(0.36f, -128.89f, 706.49f);
	cube[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[159].scale = D3DXVECTOR3(10, 1, 10);

	cube[160].position = D3DXVECTOR3(4.25f, -114.71f, 621.93f);
	cube[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[160].scale = D3DXVECTOR3(10, 1, 10);

	cube[161].position = D3DXVECTOR3(4.26f, -116.42f, 631.64f);
	cube[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[161].scale = D3DXVECTOR3(10, 1, 10);

	cube[162].position = D3DXVECTOR3(4.26f, -118.11f, 641.26f);
	cube[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[162].scale = D3DXVECTOR3(10, 1, 10);

	cube[163].position = D3DXVECTOR3(4.26f, -119.78f, 650.75f);
	cube[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[163].scale = D3DXVECTOR3(10, 1, 10);

	cube[164].position = D3DXVECTOR3(4.26f, -121.40f, 659.93f);
	cube[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[164].scale = D3DXVECTOR3(10, 1, 10);

	cube[165].position = D3DXVECTOR3(4.26f, -123.02f, 669.14f);
	cube[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[165].scale = D3DXVECTOR3(10, 1, 10);

	cube[166].position = D3DXVECTOR3(4.26f, -124.69f, 678.62f);
	cube[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[166].scale = D3DXVECTOR3(10, 1, 10);

	cube[167].position = D3DXVECTOR3(4.26f, -126.36f, 688.09f);
	cube[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[167].scale = D3DXVECTOR3(10, 1, 10);

	cube[168].position = D3DXVECTOR3(4.26f, -128.05f, 697.65f);
	cube[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[168].scale = D3DXVECTOR3(10, 1, 10);

	cube[169].position = D3DXVECTOR3(4.26f, -129.60f, 706.42f);
	cube[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[169].scale = D3DXVECTOR3(10, 1, 10);

	cube[170].position = D3DXVECTOR3(-3.80f, -114.62f, 621.95f);
	cube[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[170].scale = D3DXVECTOR3(10, 1, 10);

	cube[171].position = D3DXVECTOR3(-3.80f, -116.31f, 631.53f);
	cube[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[171].scale = D3DXVECTOR3(10, 1, 10);

	cube[172].position = D3DXVECTOR3(-3.80f, -117.60f, 638.89f);
	cube[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[172].scale = D3DXVECTOR3(10, 1, 10);

	cube[173].position = D3DXVECTOR3(-3.80f, -119.31f, 648.56f);
	cube[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[173].scale = D3DXVECTOR3(10, 1, 10);

	cube[174].position = D3DXVECTOR3(-3.80f, -121.00f, 658.15f);
	cube[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[174].scale = D3DXVECTOR3(10, 1, 10);

	cube[175].position = D3DXVECTOR3(-3.80f, -122.71f, 667.82f);
	cube[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[175].scale = D3DXVECTOR3(10, 1, 10);

	cube[176].position = D3DXVECTOR3(-3.80f, -124.42f, 677.51f);
	cube[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[176].scale = D3DXVECTOR3(10, 1, 10);

	cube[177].position = D3DXVECTOR3(-3.80f, -126.12f, 687.14f);
	cube[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[177].scale = D3DXVECTOR3(10, 1, 10);

	cube[178].position = D3DXVECTOR3(-3.80f, -127.84f, 696.88f);
	cube[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[178].scale = D3DXVECTOR3(10, 1, 10);

	cube[179].position = D3DXVECTOR3(-3.80f, -129.52f, 706.39f);
	cube[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[179].scale = D3DXVECTOR3(10, 1, 10);

	cube[180].position = D3DXVECTOR3(0.36f, -68.33f, 364.05f);
	cube[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[180].scale = D3DXVECTOR3(10, 1, 10);

	cube[181].position = D3DXVECTOR3(0.36f, -70.03f, 373.68f);
	cube[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[181].scale = D3DXVECTOR3(10, 1, 10);

	cube[182].position = D3DXVECTOR3(0.36f, -71.71f, 383.18f);
	cube[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[182].scale = D3DXVECTOR3(10, 1, 10);

	cube[183].position = D3DXVECTOR3(0.36f, -73.39f, 392.76f);
	cube[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[183].scale = D3DXVECTOR3(10, 1, 10);

	cube[184].position = D3DXVECTOR3(0.36f, -75.06f, 402.26f);
	cube[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[184].scale = D3DXVECTOR3(10, 1, 10);

	cube[185].position = D3DXVECTOR3(0.36f, -76.72f, 411.65f);
	cube[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[185].scale = D3DXVECTOR3(10, 1, 10);

	cube[186].position = D3DXVECTOR3(0.36f, -78.39f, 421.15f);
	cube[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[186].scale = D3DXVECTOR3(10, 1, 10);

	cube[187].position = D3DXVECTOR3(0.36f, -79.97f, 430.10f);
	cube[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[187].scale = D3DXVECTOR3(10, 1, 10);

	cube[188].position = D3DXVECTOR3(0.36f, -81.59f, 439.31f);
	cube[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[188].scale = D3DXVECTOR3(10, 1, 10);

	cube[189].position = D3DXVECTOR3(0.36f, -83.21f, 448.49f);
	cube[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[189].scale = D3DXVECTOR3(10, 1, 10);

	cube[190].position = D3DXVECTOR3(4.25f, -69.03f, 363.93f);
	cube[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[190].scale = D3DXVECTOR3(10, 1, 10);

	cube[191].position = D3DXVECTOR3(4.26f, -70.74f, 373.64f);
	cube[191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[191].scale = D3DXVECTOR3(10, 1, 10);

	cube[192].position = D3DXVECTOR3(4.26f, -72.43f, 383.26f);
	cube[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[192].scale = D3DXVECTOR3(10, 1, 10);

	cube[193].position = D3DXVECTOR3(4.26f, -74.10f, 392.75f);
	cube[193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[193].scale = D3DXVECTOR3(10, 1, 10);

	cube[194].position = D3DXVECTOR3(4.26f, -75.72f, 401.93f);
	cube[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[194].scale = D3DXVECTOR3(10, 1, 10);

	cube[195].position = D3DXVECTOR3(4.26f, -77.34f, 411.14f);
	cube[195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[195].scale = D3DXVECTOR3(10, 1, 10);

	cube[196].position = D3DXVECTOR3(4.26f, -79.01f, 420.62f);
	cube[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[196].scale = D3DXVECTOR3(10, 1, 10);

	cube[197].position = D3DXVECTOR3(4.26f, -80.68f, 430.09f);
	cube[197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[197].scale = D3DXVECTOR3(10, 1, 10);

	cube[198].position = D3DXVECTOR3(4.26f, -82.37f, 439.65f);
	cube[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[198].scale = D3DXVECTOR3(10, 1, 10);

	cube[199].position = D3DXVECTOR3(4.26f, -83.92f, 448.42f);
	cube[199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[199].scale = D3DXVECTOR3(10, 1, 10);

	cube[200].position = D3DXVECTOR3(-3.80f, -68.94f, 363.95f);
	cube[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[200].scale = D3DXVECTOR3(10, 1, 10);

	cube[201].position = D3DXVECTOR3(-3.80f, -70.63f, 373.53f);
	cube[201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[201].scale = D3DXVECTOR3(10, 1, 10);

	cube[202].position = D3DXVECTOR3(-3.80f, -71.92f, 380.89f);
	cube[202].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[202].scale = D3DXVECTOR3(10, 1, 10);

	cube[203].position = D3DXVECTOR3(-3.80f, -73.63f, 390.56f);
	cube[203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[203].scale = D3DXVECTOR3(10, 1, 10);

	cube[204].position = D3DXVECTOR3(-3.80f, -75.32f, 400.15f);
	cube[204].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[204].scale = D3DXVECTOR3(10, 1, 10);

	cube[205].position = D3DXVECTOR3(-3.80f, -77.03f, 409.82f);
	cube[205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[205].scale = D3DXVECTOR3(10, 1, 10);

	cube[206].position = D3DXVECTOR3(-3.80f, -78.74f, 419.51f);
	cube[206].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[206].scale = D3DXVECTOR3(10, 1, 10);

	cube[207].position = D3DXVECTOR3(-3.80f, -80.44f, 429.14f);
	cube[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[207].scale = D3DXVECTOR3(10, 1, 10);

	cube[208].position = D3DXVECTOR3(-3.80f, -82.16f, 438.88f);
	cube[208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[208].scale = D3DXVECTOR3(10, 1, 10);

	cube[209].position = D3DXVECTOR3(-3.80f, -83.84f, 448.39f);
	cube[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[209].scale = D3DXVECTOR3(10, 1, 10);

	cube[210].position = D3DXVECTOR3(0.36f, -52.81f, 276.15f);
	cube[210].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[210].scale = D3DXVECTOR3(10, 1, 10);

	cube[211].position = D3DXVECTOR3(0.36f, -54.51f, 285.78f);
	cube[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[211].scale = D3DXVECTOR3(10, 1, 10);

	cube[212].position = D3DXVECTOR3(0.36f, -56.19f, 295.28f);
	cube[212].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[212].scale = D3DXVECTOR3(10, 1, 10);

	cube[213].position = D3DXVECTOR3(0.36f, -57.87f, 304.86f);
	cube[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[213].scale = D3DXVECTOR3(10, 1, 10);

	cube[214].position = D3DXVECTOR3(0.36f, -59.54f, 314.36f);
	cube[214].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[214].scale = D3DXVECTOR3(10, 1, 10);

	cube[215].position = D3DXVECTOR3(0.36f, -61.20f, 323.75f);
	cube[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[215].scale = D3DXVECTOR3(10, 1, 10);

	cube[216].position = D3DXVECTOR3(0.36f, -62.87f, 333.25f);
	cube[216].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[216].scale = D3DXVECTOR3(10, 1, 10);

	cube[217].position = D3DXVECTOR3(0.36f, -64.45f, 342.20f);
	cube[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[217].scale = D3DXVECTOR3(10, 1, 10);

	cube[218].position = D3DXVECTOR3(0.36f, -66.07f, 351.41f);
	cube[218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[218].scale = D3DXVECTOR3(10, 1, 10);

	cube[219].position = D3DXVECTOR3(0.36f, -67.69f, 360.59f);
	cube[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[219].scale = D3DXVECTOR3(10, 1, 10);

	cube[220].position = D3DXVECTOR3(4.25f, -53.51f, 276.03f);
	cube[220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[220].scale = D3DXVECTOR3(10, 1, 10);

	cube[221].position = D3DXVECTOR3(4.26f, -55.22f, 285.74f);
	cube[221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[221].scale = D3DXVECTOR3(10, 1, 10);

	cube[222].position = D3DXVECTOR3(4.26f, -56.91f, 295.36f);
	cube[222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[222].scale = D3DXVECTOR3(10, 1, 10);

	cube[223].position = D3DXVECTOR3(4.26f, -58.58f, 304.85f);
	cube[223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[223].scale = D3DXVECTOR3(10, 1, 10);

	cube[224].position = D3DXVECTOR3(4.26f, -60.20f, 314.03f);
	cube[224].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[224].scale = D3DXVECTOR3(10, 1, 10);

	cube[225].position = D3DXVECTOR3(4.26f, -61.82f, 323.24f);
	cube[225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[225].scale = D3DXVECTOR3(10, 1, 10);

	cube[226].position = D3DXVECTOR3(4.26f, -63.49f, 332.72f);
	cube[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[226].scale = D3DXVECTOR3(10, 1, 10);

	cube[227].position = D3DXVECTOR3(4.26f, -65.16f, 342.19f);
	cube[227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[227].scale = D3DXVECTOR3(10, 1, 10);

	cube[228].position = D3DXVECTOR3(4.26f, -66.85f, 351.75f);
	cube[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[228].scale = D3DXVECTOR3(10, 1, 10);

	cube[229].position = D3DXVECTOR3(4.26f, -68.40f, 360.52f);
	cube[229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[229].scale = D3DXVECTOR3(10, 1, 10);

	cube[230].position = D3DXVECTOR3(-3.80f, -53.42f, 276.05f);
	cube[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[230].scale = D3DXVECTOR3(10, 1, 10);

	cube[231].position = D3DXVECTOR3(-3.80f, -55.11f, 285.63f);
	cube[231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[231].scale = D3DXVECTOR3(10, 1, 10);

	cube[232].position = D3DXVECTOR3(-3.80f, -56.40f, 292.99f);
	cube[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[232].scale = D3DXVECTOR3(10, 1, 10);

	cube[233].position = D3DXVECTOR3(-3.80f, -58.11f, 302.66f);
	cube[233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[233].scale = D3DXVECTOR3(10, 1, 10);

	cube[234].position = D3DXVECTOR3(-3.80f, -59.80f, 312.25f);
	cube[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[234].scale = D3DXVECTOR3(10, 1, 10);

	cube[235].position = D3DXVECTOR3(-3.80f, -61.51f, 321.92f);
	cube[235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[235].scale = D3DXVECTOR3(10, 1, 10);

	cube[236].position = D3DXVECTOR3(-3.80f, -63.22f, 331.61f);
	cube[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[236].scale = D3DXVECTOR3(10, 1, 10);

	cube[237].position = D3DXVECTOR3(-3.80f, -64.92f, 341.24f);
	cube[237].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[237].scale = D3DXVECTOR3(10, 1, 10);

	cube[238].position = D3DXVECTOR3(-3.80f, -66.64f, 350.98f);
	cube[238].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[238].scale = D3DXVECTOR3(10, 1, 10);

	cube[239].position = D3DXVECTOR3(-3.80f, -68.32f, 360.49f);
	cube[239].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[239].scale = D3DXVECTOR3(10, 1, 10);

	cube[240].position = D3DXVECTOR3(0.36f, -36.01f, 182.95f);
	cube[240].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[240].scale = D3DXVECTOR3(10, 1, 10);

	cube[241].position = D3DXVECTOR3(0.36f, -37.71f, 192.58f);
	cube[241].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[241].scale = D3DXVECTOR3(10, 1, 10);

	cube[242].position = D3DXVECTOR3(0.36f, -39.39f, 202.08f);
	cube[242].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[242].scale = D3DXVECTOR3(10, 1, 10);

	cube[243].position = D3DXVECTOR3(0.36f, -41.07f, 211.66f);
	cube[243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[243].scale = D3DXVECTOR3(10, 1, 10);

	cube[244].position = D3DXVECTOR3(0.36f, -42.74f, 221.16f);
	cube[244].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[244].scale = D3DXVECTOR3(10, 1, 10);

	cube[245].position = D3DXVECTOR3(0.36f, -44.40f, 230.55f);
	cube[245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[245].scale = D3DXVECTOR3(10, 1, 10);

	cube[246].position = D3DXVECTOR3(0.36f, -46.07f, 240.05f);
	cube[246].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[246].scale = D3DXVECTOR3(10, 1, 10);

	cube[247].position = D3DXVECTOR3(0.36f, -47.65f, 249.00f);
	cube[247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[247].scale = D3DXVECTOR3(10, 1, 10);

	cube[248].position = D3DXVECTOR3(0.36f, -49.27f, 258.21f);
	cube[248].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[248].scale = D3DXVECTOR3(10, 1, 10);

	cube[249].position = D3DXVECTOR3(0.36f, -50.89f, 267.39f);
	cube[249].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[249].scale = D3DXVECTOR3(10, 1, 10);

	cube[250].position = D3DXVECTOR3(4.25f, -36.71f, 182.83f);
	cube[250].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[250].scale = D3DXVECTOR3(10, 1, 10);

	cube[251].position = D3DXVECTOR3(4.26f, -38.42f, 192.54f);
	cube[251].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[251].scale = D3DXVECTOR3(10, 1, 10);

	cube[252].position = D3DXVECTOR3(4.26f, -40.11f, 202.16f);
	cube[252].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[252].scale = D3DXVECTOR3(10, 1, 10);

	cube[253].position = D3DXVECTOR3(4.26f, -41.78f, 211.65f);
	cube[253].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[253].scale = D3DXVECTOR3(10, 1, 10);

	cube[254].position = D3DXVECTOR3(4.26f, -43.40f, 220.83f);
	cube[254].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[254].scale = D3DXVECTOR3(10, 1, 10);

	cube[255].position = D3DXVECTOR3(4.26f, -45.02f, 230.04f);
	cube[255].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[255].scale = D3DXVECTOR3(10, 1, 10);

	cube[256].position = D3DXVECTOR3(4.26f, -46.69f, 239.52f);
	cube[256].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[256].scale = D3DXVECTOR3(10, 1, 10);

	cube[257].position = D3DXVECTOR3(4.26f, -48.36f, 248.99f);
	cube[257].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[257].scale = D3DXVECTOR3(10, 1, 10);

	cube[258].position = D3DXVECTOR3(4.26f, -50.05f, 258.55f);
	cube[258].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[258].scale = D3DXVECTOR3(10, 1, 10);

	cube[259].position = D3DXVECTOR3(4.26f, -51.60f, 267.32f);
	cube[259].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[259].scale = D3DXVECTOR3(10, 1, 10);

	cube[260].position = D3DXVECTOR3(-3.80f, -36.62f, 182.85f);
	cube[260].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[260].scale = D3DXVECTOR3(10, 1, 10);

	cube[261].position = D3DXVECTOR3(-3.80f, -38.31f, 192.43f);
	cube[261].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[261].scale = D3DXVECTOR3(10, 1, 10);

	cube[262].position = D3DXVECTOR3(-3.80f, -39.60f, 199.79f);
	cube[262].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[262].scale = D3DXVECTOR3(10, 1, 10);

	cube[263].position = D3DXVECTOR3(-3.80f, -41.31f, 209.46f);
	cube[263].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[263].scale = D3DXVECTOR3(10, 1, 10);

	cube[264].position = D3DXVECTOR3(-3.80f, -43.00f, 219.05f);
	cube[264].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[264].scale = D3DXVECTOR3(10, 1, 10);

	cube[265].position = D3DXVECTOR3(-3.80f, -44.71f, 228.72f);
	cube[265].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[265].scale = D3DXVECTOR3(10, 1, 10);

	cube[266].position = D3DXVECTOR3(-3.80f, -46.42f, 238.41f);
	cube[266].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[266].scale = D3DXVECTOR3(10, 1, 10);

	cube[267].position = D3DXVECTOR3(-3.80f, -48.12f, 248.04f);
	cube[267].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[267].scale = D3DXVECTOR3(10, 1, 10);

	cube[268].position = D3DXVECTOR3(-3.80f, -49.84f, 257.78f);
	cube[268].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[268].scale = D3DXVECTOR3(10, 1, 10);

	cube[269].position = D3DXVECTOR3(-3.80f, -51.52f, 267.29f);
	cube[269].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[269].scale = D3DXVECTOR3(10, 1, 10);

	cube[270].position = D3DXVECTOR3(0.36f, -129.11f, 708.05f);
	cube[270].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[270].scale = D3DXVECTOR3(10, 1, 10);

	cube[271].position = D3DXVECTOR3(0.36f, -130.81f, 717.68f);
	cube[271].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[271].scale = D3DXVECTOR3(10, 1, 10);

	cube[272].position = D3DXVECTOR3(0.36f, -132.49f, 727.18f);
	cube[272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[272].scale = D3DXVECTOR3(10, 1, 10);

	cube[273].position = D3DXVECTOR3(0.36f, -134.17f, 736.76f);
	cube[273].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[273].scale = D3DXVECTOR3(10, 1, 10);

	cube[274].position = D3DXVECTOR3(0.36f, -135.84f, 746.26f);
	cube[274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[274].scale = D3DXVECTOR3(10, 1, 10);

	cube[275].position = D3DXVECTOR3(0.36f, -137.50f, 755.65f);
	cube[275].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[275].scale = D3DXVECTOR3(10, 1, 10);

	cube[276].position = D3DXVECTOR3(0.36f, -139.17f, 765.15f);
	cube[276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[276].scale = D3DXVECTOR3(10, 1, 10);

	cube[277].position = D3DXVECTOR3(0.36f, -140.75f, 774.10f);
	cube[277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[277].scale = D3DXVECTOR3(10, 1, 10);

	cube[278].position = D3DXVECTOR3(0.36f, -142.37f, 783.31f);
	cube[278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[278].scale = D3DXVECTOR3(10, 1, 10);

	cube[279].position = D3DXVECTOR3(0.36f, -143.99f, 792.49f);
	cube[279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[279].scale = D3DXVECTOR3(10, 1, 10);

	cube[280].position = D3DXVECTOR3(4.25f, -129.81f, 707.93f);
	cube[280].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[280].scale = D3DXVECTOR3(10, 1, 10);

	cube[281].position = D3DXVECTOR3(4.26f, -131.52f, 717.64f);
	cube[281].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[281].scale = D3DXVECTOR3(10, 1, 10);

	cube[282].position = D3DXVECTOR3(4.26f, -133.21f, 727.26f);
	cube[282].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[282].scale = D3DXVECTOR3(10, 1, 10);

	cube[283].position = D3DXVECTOR3(4.26f, -134.88f, 736.75f);
	cube[283].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[283].scale = D3DXVECTOR3(10, 1, 10);

	cube[284].position = D3DXVECTOR3(4.26f, -136.50f, 745.93f);
	cube[284].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[284].scale = D3DXVECTOR3(10, 1, 10);

	cube[285].position = D3DXVECTOR3(4.26f, -138.12f, 755.14f);
	cube[285].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[285].scale = D3DXVECTOR3(10, 1, 10);

	cube[286].position = D3DXVECTOR3(4.26f, -139.79f, 764.62f);
	cube[286].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[286].scale = D3DXVECTOR3(10, 1, 10);

	cube[287].position = D3DXVECTOR3(4.26f, -141.46f, 774.09f);
	cube[287].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[287].scale = D3DXVECTOR3(10, 1, 10);

	cube[288].position = D3DXVECTOR3(4.26f, -143.15f, 783.65f);
	cube[288].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[288].scale = D3DXVECTOR3(10, 1, 10);

	cube[289].position = D3DXVECTOR3(4.26f, -144.70f, 792.42f);
	cube[289].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[289].scale = D3DXVECTOR3(10, 1, 10);

	cube[290].position = D3DXVECTOR3(-3.80f, -129.72f, 707.95f);
	cube[290].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[290].scale = D3DXVECTOR3(10, 1, 10);

	cube[291].position = D3DXVECTOR3(-3.80f, -131.41f, 717.53f);
	cube[291].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[291].scale = D3DXVECTOR3(10, 1, 10);

	cube[292].position = D3DXVECTOR3(-3.80f, -132.70f, 724.89f);
	cube[292].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[292].scale = D3DXVECTOR3(10, 1, 10);

	cube[293].position = D3DXVECTOR3(-3.80f, -134.41f, 734.56f);
	cube[293].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[293].scale = D3DXVECTOR3(10, 1, 10);

	cube[294].position = D3DXVECTOR3(-3.80f, -136.10f, 744.15f);
	cube[294].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[294].scale = D3DXVECTOR3(10, 1, 10);

	cube[295].position = D3DXVECTOR3(-3.80f, -137.81f, 753.82f);
	cube[295].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[295].scale = D3DXVECTOR3(10, 1, 10);

	cube[296].position = D3DXVECTOR3(-3.80f, -139.52f, 763.51f);
	cube[296].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[296].scale = D3DXVECTOR3(10, 1, 10);

	cube[297].position = D3DXVECTOR3(-3.80f, -141.22f, 773.14f);
	cube[297].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[297].scale = D3DXVECTOR3(10, 1, 10);

	cube[298].position = D3DXVECTOR3(-3.80f, -142.94f, 782.88f);
	cube[298].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[298].scale = D3DXVECTOR3(10, 1, 10);

	cube[299].position = D3DXVECTOR3(-3.80f, -144.62f, 792.39f);
	cube[299].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[299].scale = D3DXVECTOR3(10, 1, 10);

	cube[300].position = D3DXVECTOR3(0.36f, -20.01f, 92.65f);
	cube[300].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[300].scale = D3DXVECTOR3(10, 1, 10);

	cube[301].position = D3DXVECTOR3(0.36f, -21.71f, 102.28f);
	cube[301].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[301].scale = D3DXVECTOR3(10, 1, 10);

	cube[302].position = D3DXVECTOR3(0.36f, -23.39f, 111.78f);
	cube[302].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[302].scale = D3DXVECTOR3(10, 1, 10);

	cube[303].position = D3DXVECTOR3(0.36f, -25.07f, 121.36f);
	cube[303].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[303].scale = D3DXVECTOR3(10, 1, 10);

	cube[304].position = D3DXVECTOR3(0.36f, -26.74f, 130.86f);
	cube[304].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[304].scale = D3DXVECTOR3(10, 1, 10);

	cube[305].position = D3DXVECTOR3(0.36f, -28.40f, 140.25f);
	cube[305].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[305].scale = D3DXVECTOR3(10, 1, 10);

	cube[306].position = D3DXVECTOR3(0.36f, -30.07f, 149.75f);
	cube[306].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[306].scale = D3DXVECTOR3(10, 1, 10);

	cube[307].position = D3DXVECTOR3(0.36f, -31.65f, 158.70f);
	cube[307].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[307].scale = D3DXVECTOR3(10, 1, 10);

	cube[308].position = D3DXVECTOR3(0.36f, -33.27f, 167.91f);
	cube[308].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[308].scale = D3DXVECTOR3(10, 1, 10);

	cube[309].position = D3DXVECTOR3(0.36f, -34.89f, 177.09f);
	cube[309].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[309].scale = D3DXVECTOR3(10, 1, 10);

	cube[310].position = D3DXVECTOR3(4.25f, -20.71f, 92.53f);
	cube[310].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[310].scale = D3DXVECTOR3(10, 1, 10);

	cube[311].position = D3DXVECTOR3(4.26f, -22.42f, 102.24f);
	cube[311].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[311].scale = D3DXVECTOR3(10, 1, 10);

	cube[312].position = D3DXVECTOR3(4.26f, -24.11f, 111.86f);
	cube[312].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[312].scale = D3DXVECTOR3(10, 1, 10);

	cube[313].position = D3DXVECTOR3(4.26f, -25.78f, 121.35f);
	cube[313].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[313].scale = D3DXVECTOR3(10, 1, 10);

	cube[314].position = D3DXVECTOR3(4.26f, -27.40f, 130.53f);
	cube[314].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[314].scale = D3DXVECTOR3(10, 1, 10);

	cube[315].position = D3DXVECTOR3(4.26f, -29.02f, 139.74f);
	cube[315].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[315].scale = D3DXVECTOR3(10, 1, 10);

	cube[316].position = D3DXVECTOR3(4.26f, -30.69f, 149.22f);
	cube[316].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[316].scale = D3DXVECTOR3(10, 1, 10);

	cube[317].position = D3DXVECTOR3(4.26f, -32.36f, 158.69f);
	cube[317].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[317].scale = D3DXVECTOR3(10, 1, 10);

	cube[318].position = D3DXVECTOR3(4.26f, -34.05f, 168.25f);
	cube[318].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[318].scale = D3DXVECTOR3(10, 1, 10);

	cube[319].position = D3DXVECTOR3(4.26f, -35.60f, 177.02f);
	cube[319].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[319].scale = D3DXVECTOR3(10, 1, 10);

	cube[320].position = D3DXVECTOR3(-3.80f, -20.62f, 92.55f);
	cube[320].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[320].scale = D3DXVECTOR3(10, 1, 10);

	cube[321].position = D3DXVECTOR3(-3.80f, -22.31f, 102.13f);
	cube[321].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[321].scale = D3DXVECTOR3(10, 1, 10);

	cube[322].position = D3DXVECTOR3(-3.80f, -23.60f, 109.49f);
	cube[322].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[322].scale = D3DXVECTOR3(10, 1, 10);

	cube[323].position = D3DXVECTOR3(-3.80f, -25.31f, 119.16f);
	cube[323].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[323].scale = D3DXVECTOR3(10, 1, 10);

	cube[324].position = D3DXVECTOR3(-3.80f, -27.00f, 128.75f);
	cube[324].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[324].scale = D3DXVECTOR3(10, 1, 10);

	cube[325].position = D3DXVECTOR3(-3.80f, -28.71f, 138.42f);
	cube[325].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[325].scale = D3DXVECTOR3(10, 1, 10);

	cube[326].position = D3DXVECTOR3(-3.80f, -30.42f, 148.11f);
	cube[326].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[326].scale = D3DXVECTOR3(10, 1, 10);

	cube[327].position = D3DXVECTOR3(-3.80f, -32.12f, 157.74f);
	cube[327].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[327].scale = D3DXVECTOR3(10, 1, 10);

	cube[328].position = D3DXVECTOR3(-3.80f, -33.84f, 167.48f);
	cube[328].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[328].scale = D3DXVECTOR3(10, 1, 10);

	cube[329].position = D3DXVECTOR3(-3.80f, -35.52f, 176.99f);
	cube[329].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[329].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[0].position = D3DXVECTOR3(8.06f, -143.97f, 796.70f);
	rightWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[0].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[1].position = D3DXVECTOR3(8.06f, -145.68f, 806.40f);
	rightWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[1].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[2].position = D3DXVECTOR3(8.06f, -147.34f, 815.81f);
	rightWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[2].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[3].position = D3DXVECTOR3(8.06f, -149.02f, 825.33f);
	rightWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[3].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[4].position = D3DXVECTOR3(8.06f, -150.73f, 835.03f);
	rightWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[4].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[5].position = D3DXVECTOR3(8.06f, -152.43f, 844.65f);
	rightWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[5].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[6].position = D3DXVECTOR3(8.06f, -154.12f, 854.22f);
	rightWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[6].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[7].position = D3DXVECTOR3(8.06f, -155.82f, 863.83f);
	rightWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[7].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[8].position = D3DXVECTOR3(8.06f, -157.52f, 873.45f);
	rightWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[8].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[9].position = D3DXVECTOR3(8.06f, -158.89f, 881.23f);
	rightWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[9].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[10].position = D3DXVECTOR3(8.06f, -82.67f, 450.00f);
	rightWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[10].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[11].position = D3DXVECTOR3(8.06f, -84.38f, 459.70f);
	rightWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[11].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[12].position = D3DXVECTOR3(8.06f, -86.04f, 469.11f);
	rightWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[12].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[13].position = D3DXVECTOR3(8.06f, -87.72f, 478.63f);
	rightWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[13].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[14].position = D3DXVECTOR3(8.06f, -89.43f, 488.33f);
	rightWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[14].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[15].position = D3DXVECTOR3(8.06f, -91.13f, 497.95f);
	rightWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[15].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[16].position = D3DXVECTOR3(8.06f, -92.82f, 507.52f);
	rightWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[16].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[17].position = D3DXVECTOR3(8.06f, -94.52f, 517.13f);
	rightWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[17].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[18].position = D3DXVECTOR3(8.06f, -96.22f, 526.75f);
	rightWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[18].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[19].position = D3DXVECTOR3(8.06f, -97.59f, 534.53f);
	rightWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[19].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[20].position = D3DXVECTOR3(8.06f, -2.77f, -0.20f);
	rightWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[20].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[21].position = D3DXVECTOR3(8.06f, -4.48f, 9.50f);
	rightWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[21].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[22].position = D3DXVECTOR3(8.06f, -6.14f, 18.91f);
	rightWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[22].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[23].position = D3DXVECTOR3(8.06f, -7.82f, 28.43f);
	rightWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[23].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[24].position = D3DXVECTOR3(8.06f, -9.53f, 38.13f);
	rightWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[24].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[25].position = D3DXVECTOR3(8.06f, -11.23f, 47.75f);
	rightWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[25].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[26].position = D3DXVECTOR3(8.06f, -12.92f, 57.32f);
	rightWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[26].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[27].position = D3DXVECTOR3(8.06f, -14.62f, 66.93f);
	rightWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[27].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[28].position = D3DXVECTOR3(8.06f, -16.32f, 76.55f);
	rightWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[28].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[29].position = D3DXVECTOR3(8.06f, -17.69f, 84.33f);
	rightWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[29].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[30].position = D3DXVECTOR3(8.06f, -160.17f, 888.20f);
	rightWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[30].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[31].position = D3DXVECTOR3(8.06f, -161.88f, 897.90f);
	rightWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[31].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[32].position = D3DXVECTOR3(8.06f, -163.54f, 907.31f);
	rightWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[32].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[33].position = D3DXVECTOR3(8.06f, -165.22f, 916.83f);
	rightWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[33].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[34].position = D3DXVECTOR3(8.06f, -166.93f, 926.53f);
	rightWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[34].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[35].position = D3DXVECTOR3(8.06f, -168.63f, 936.15f);
	rightWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[35].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[36].position = D3DXVECTOR3(8.06f, -170.32f, 945.72f);
	rightWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[36].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[37].position = D3DXVECTOR3(8.06f, -172.02f, 955.33f);
	rightWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[37].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[38].position = D3DXVECTOR3(8.06f, -173.72f, 964.95f);
	rightWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[38].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[39].position = D3DXVECTOR3(8.06f, -175.09f, 972.73f);
	rightWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[39].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[40].position = D3DXVECTOR3(8.06f, -98.47f, 539.20f);
	rightWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[40].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[41].position = D3DXVECTOR3(8.06f, -100.18f, 548.90f);
	rightWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[41].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[42].position = D3DXVECTOR3(8.06f, -101.84f, 558.31f);
	rightWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[42].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[43].position = D3DXVECTOR3(8.06f, -103.52f, 567.83f);
	rightWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[43].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[44].position = D3DXVECTOR3(8.06f, -105.23f, 577.53f);
	rightWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[44].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[45].position = D3DXVECTOR3(8.06f, -106.93f, 587.15f);
	rightWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[45].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[46].position = D3DXVECTOR3(8.06f, -108.62f, 596.72f);
	rightWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[46].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[47].position = D3DXVECTOR3(8.06f, -110.32f, 606.33f);
	rightWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[47].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[48].position = D3DXVECTOR3(8.06f, -112.02f, 615.95f);
	rightWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[48].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[49].position = D3DXVECTOR3(8.06f, -113.39f, 623.73f);
	rightWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[49].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[50].position = D3DXVECTOR3(8.06f, -113.17f, 622.20f);
	rightWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[50].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[51].position = D3DXVECTOR3(8.06f, -114.88f, 631.90f);
	rightWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[51].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[52].position = D3DXVECTOR3(8.06f, -116.54f, 641.31f);
	rightWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[52].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[53].position = D3DXVECTOR3(8.06f, -118.22f, 650.83f);
	rightWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[53].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[54].position = D3DXVECTOR3(8.06f, -119.93f, 660.53f);
	rightWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[54].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[55].position = D3DXVECTOR3(8.06f, -121.63f, 670.15f);
	rightWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[55].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[56].position = D3DXVECTOR3(8.06f, -123.32f, 679.72f);
	rightWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[56].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[57].position = D3DXVECTOR3(8.06f, -125.02f, 689.33f);
	rightWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[57].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[58].position = D3DXVECTOR3(8.06f, -126.72f, 698.95f);
	rightWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[58].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[59].position = D3DXVECTOR3(8.06f, -128.09f, 706.73f);
	rightWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[59].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[60].position = D3DXVECTOR3(8.06f, -67.49f, 364.20f);
	rightWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[60].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[61].position = D3DXVECTOR3(8.06f, -69.20f, 373.90f);
	rightWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[61].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[62].position = D3DXVECTOR3(8.06f, -70.86f, 383.31f);
	rightWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[62].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[63].position = D3DXVECTOR3(8.06f, -72.54f, 392.83f);
	rightWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[63].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[64].position = D3DXVECTOR3(8.06f, -74.25f, 402.53f);
	rightWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[64].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[65].position = D3DXVECTOR3(8.06f, -75.95f, 412.15f);
	rightWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[65].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[66].position = D3DXVECTOR3(8.06f, -77.64f, 421.72f);
	rightWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[66].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[67].position = D3DXVECTOR3(8.06f, -79.34f, 431.33f);
	rightWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[67].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[68].position = D3DXVECTOR3(8.06f, -81.04f, 440.95f);
	rightWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[68].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[69].position = D3DXVECTOR3(8.06f, -82.41f, 448.73f);
	rightWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[69].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[70].position = D3DXVECTOR3(8.06f, -51.97f, 276.30f);
	rightWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[70].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[71].position = D3DXVECTOR3(8.06f, -53.68f, 286.00f);
	rightWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[71].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[72].position = D3DXVECTOR3(8.06f, -55.34f, 295.41f);
	rightWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[72].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[73].position = D3DXVECTOR3(8.06f, -57.02f, 304.93f);
	rightWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[73].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[74].position = D3DXVECTOR3(8.06f, -58.73f, 314.63f);
	rightWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[74].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[75].position = D3DXVECTOR3(8.06f, -60.43f, 324.25f);
	rightWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[75].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[76].position = D3DXVECTOR3(8.06f, -62.12f, 333.82f);
	rightWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[76].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[77].position = D3DXVECTOR3(8.06f, -63.82f, 343.43f);
	rightWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[77].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[78].position = D3DXVECTOR3(8.06f, -65.52f, 353.05f);
	rightWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[78].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[79].position = D3DXVECTOR3(8.06f, -66.89f, 360.83f);
	rightWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[79].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[80].position = D3DXVECTOR3(8.06f, -35.17f, 183.10f);
	rightWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[80].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[81].position = D3DXVECTOR3(8.06f, -36.88f, 192.80f);
	rightWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[81].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[82].position = D3DXVECTOR3(8.06f, -38.54f, 202.21f);
	rightWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[82].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[83].position = D3DXVECTOR3(8.06f, -40.22f, 211.73f);
	rightWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[83].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[84].position = D3DXVECTOR3(8.06f, -41.93f, 221.43f);
	rightWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[84].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[85].position = D3DXVECTOR3(8.06f, -43.63f, 231.05f);
	rightWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[85].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[86].position = D3DXVECTOR3(8.06f, -45.32f, 240.62f);
	rightWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[86].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[87].position = D3DXVECTOR3(8.06f, -47.02f, 250.23f);
	rightWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[87].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[88].position = D3DXVECTOR3(8.06f, -48.72f, 259.85f);
	rightWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[88].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[89].position = D3DXVECTOR3(8.06f, -50.09f, 267.63f);
	rightWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[89].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[90].position = D3DXVECTOR3(8.06f, -128.27f, 708.20f);
	rightWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[90].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[91].position = D3DXVECTOR3(8.06f, -129.98f, 717.90f);
	rightWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[91].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[92].position = D3DXVECTOR3(8.06f, -131.64f, 727.31f);
	rightWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[92].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[93].position = D3DXVECTOR3(8.06f, -133.32f, 736.83f);
	rightWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[93].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[94].position = D3DXVECTOR3(8.06f, -135.03f, 746.53f);
	rightWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[94].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[95].position = D3DXVECTOR3(8.06f, -136.73f, 756.15f);
	rightWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[95].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[96].position = D3DXVECTOR3(8.06f, -138.42f, 765.72f);
	rightWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[96].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[97].position = D3DXVECTOR3(8.06f, -140.12f, 775.33f);
	rightWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[97].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[98].position = D3DXVECTOR3(8.06f, -141.82f, 784.95f);
	rightWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[98].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[99].position = D3DXVECTOR3(8.06f, -143.19f, 792.73f);
	rightWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[99].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[100].position = D3DXVECTOR3(8.06f, -19.17f, 92.80f);
	rightWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[100].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[101].position = D3DXVECTOR3(8.06f, -20.88f, 102.50f);
	rightWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[101].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[102].position = D3DXVECTOR3(8.06f, -22.54f, 111.91f);
	rightWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[102].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[103].position = D3DXVECTOR3(8.06f, -24.22f, 121.43f);
	rightWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[103].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[104].position = D3DXVECTOR3(8.06f, -25.93f, 131.13f);
	rightWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[104].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[105].position = D3DXVECTOR3(8.06f, -27.63f, 140.75f);
	rightWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[105].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[106].position = D3DXVECTOR3(8.06f, -29.32f, 150.32f);
	rightWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[106].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[107].position = D3DXVECTOR3(8.06f, -31.02f, 159.93f);
	rightWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[107].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[108].position = D3DXVECTOR3(8.06f, -32.72f, 169.55f);
	rightWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[108].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[109].position = D3DXVECTOR3(8.06f, -34.09f, 177.33f);
	rightWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[109].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[0].position = D3DXVECTOR3(-7.51f, -144.05f, 796.69f);
	leftWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[0].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[1].position = D3DXVECTOR3(-7.51f, -145.72f, 806.16f);
	leftWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[1].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[2].position = D3DXVECTOR3(-7.51f, -147.38f, 815.56f);
	leftWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[2].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[3].position = D3DXVECTOR3(-7.51f, -149.09f, 825.27f);
	leftWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[3].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[4].position = D3DXVECTOR3(-7.51f, -150.73f, 834.57f);
	leftWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[4].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[5].position = D3DXVECTOR3(-7.51f, -152.38f, 843.92f);
	leftWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[5].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[6].position = D3DXVECTOR3(-7.51f, -154.03f, 853.30f);
	leftWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[6].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[7].position = D3DXVECTOR3(-7.51f, -155.70f, 862.78f);
	leftWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[7].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[8].position = D3DXVECTOR3(-7.51f, -157.37f, 872.23f);
	leftWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[8].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[9].position = D3DXVECTOR3(-7.51f, -158.94f, 881.13f);
	leftWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[9].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[10].position = D3DXVECTOR3(-7.51f, -82.75f, 449.99f);
	leftWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[10].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[11].position = D3DXVECTOR3(-7.51f, -84.42f, 459.46f);
	leftWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[11].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[12].position = D3DXVECTOR3(-7.51f, -86.08f, 468.86f);
	leftWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[12].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[13].position = D3DXVECTOR3(-7.51f, -87.79f, 478.57f);
	leftWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[13].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[14].position = D3DXVECTOR3(-7.51f, -89.43f, 487.87f);
	leftWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[14].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[15].position = D3DXVECTOR3(-7.51f, -91.08f, 497.22f);
	leftWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[15].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[16].position = D3DXVECTOR3(-7.51f, -92.73f, 506.60f);
	leftWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[16].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[17].position = D3DXVECTOR3(-7.51f, -94.40f, 516.08f);
	leftWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[17].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[18].position = D3DXVECTOR3(-7.51f, -96.07f, 525.53f);
	leftWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[18].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[19].position = D3DXVECTOR3(-7.51f, -97.64f, 534.43f);
	leftWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[19].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[20].position = D3DXVECTOR3(-7.51f, -2.85f, -0.21f);
	leftWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[20].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[21].position = D3DXVECTOR3(-7.51f, -4.52f, 9.26f);
	leftWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[21].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[22].position = D3DXVECTOR3(-7.51f, -6.18f, 18.66f);
	leftWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[22].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[23].position = D3DXVECTOR3(-7.51f, -7.89f, 28.37f);
	leftWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[23].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[24].position = D3DXVECTOR3(-7.51f, -9.53f, 37.67f);
	leftWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[24].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[25].position = D3DXVECTOR3(-7.51f, -11.18f, 47.02f);
	leftWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[25].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[26].position = D3DXVECTOR3(-7.51f, -12.83f, 56.40f);
	leftWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[26].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[27].position = D3DXVECTOR3(-7.51f, -14.50f, 65.88f);
	leftWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[27].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[28].position = D3DXVECTOR3(-7.51f, -16.17f, 75.33f);
	leftWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[28].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[29].position = D3DXVECTOR3(-7.51f, -17.74f, 84.23f);
	leftWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[29].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[30].position = D3DXVECTOR3(-7.51f, -160.25f, 888.19f);
	leftWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[30].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[31].position = D3DXVECTOR3(-7.51f, -161.92f, 897.66f);
	leftWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[31].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[32].position = D3DXVECTOR3(-7.51f, -163.58f, 907.06f);
	leftWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[32].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[33].position = D3DXVECTOR3(-7.51f, -165.29f, 916.77f);
	leftWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[33].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[34].position = D3DXVECTOR3(-7.51f, -166.93f, 926.07f);
	leftWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[34].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[35].position = D3DXVECTOR3(-7.51f, -168.58f, 935.42f);
	leftWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[35].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[36].position = D3DXVECTOR3(-7.51f, -170.23f, 944.80f);
	leftWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[36].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[37].position = D3DXVECTOR3(-7.51f, -171.90f, 954.28f);
	leftWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[37].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[38].position = D3DXVECTOR3(-7.51f, -173.57f, 963.73f);
	leftWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[38].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[39].position = D3DXVECTOR3(-7.51f, -175.14f, 972.63f);
	leftWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[39].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[40].position = D3DXVECTOR3(-7.51f, -98.55f, 539.19f);
	leftWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[40].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[41].position = D3DXVECTOR3(-7.51f, -100.22f, 548.66f);
	leftWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[41].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[42].position = D3DXVECTOR3(-7.51f, -101.88f, 558.06f);
	leftWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[42].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[43].position = D3DXVECTOR3(-7.51f, -103.59f, 567.77f);
	leftWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[43].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[44].position = D3DXVECTOR3(-7.51f, -105.23f, 577.07f);
	leftWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[44].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[45].position = D3DXVECTOR3(-7.51f, -106.88f, 586.42f);
	leftWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[45].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[46].position = D3DXVECTOR3(-7.51f, -108.53f, 595.80f);
	leftWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[46].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[47].position = D3DXVECTOR3(-7.51f, -110.20f, 605.28f);
	leftWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[47].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[48].position = D3DXVECTOR3(-7.51f, -111.87f, 614.73f);
	leftWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[48].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[49].position = D3DXVECTOR3(-7.51f, -113.44f, 623.63f);
	leftWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[49].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[50].position = D3DXVECTOR3(-7.51f, -113.25f, 622.19f);
	leftWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[50].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[51].position = D3DXVECTOR3(-7.51f, -114.92f, 631.66f);
	leftWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[51].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[52].position = D3DXVECTOR3(-7.51f, -116.58f, 641.06f);
	leftWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[52].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[53].position = D3DXVECTOR3(-7.51f, -118.29f, 650.77f);
	leftWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[53].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[54].position = D3DXVECTOR3(-7.51f, -119.93f, 660.07f);
	leftWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[54].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[55].position = D3DXVECTOR3(-7.51f, -121.58f, 669.42f);
	leftWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[55].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[56].position = D3DXVECTOR3(-7.51f, -123.23f, 678.80f);
	leftWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[56].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[57].position = D3DXVECTOR3(-7.51f, -124.90f, 688.28f);
	leftWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[57].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[58].position = D3DXVECTOR3(-7.51f, -126.57f, 697.73f);
	leftWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[58].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[59].position = D3DXVECTOR3(-7.51f, -128.14f, 706.63f);
	leftWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[59].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[60].position = D3DXVECTOR3(-7.51f, -67.57f, 364.19f);
	leftWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[60].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[61].position = D3DXVECTOR3(-7.51f, -69.24f, 373.66f);
	leftWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[61].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[62].position = D3DXVECTOR3(-7.51f, -70.90f, 383.06f);
	leftWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[62].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[63].position = D3DXVECTOR3(-7.51f, -72.61f, 392.77f);
	leftWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[63].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[64].position = D3DXVECTOR3(-7.51f, -74.25f, 402.07f);
	leftWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[64].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[65].position = D3DXVECTOR3(-7.51f, -75.90f, 411.42f);
	leftWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[65].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[66].position = D3DXVECTOR3(-7.51f, -77.55f, 420.80f);
	leftWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[66].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[67].position = D3DXVECTOR3(-7.51f, -79.22f, 430.28f);
	leftWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[67].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[68].position = D3DXVECTOR3(-7.51f, -80.89f, 439.73f);
	leftWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[68].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[69].position = D3DXVECTOR3(-7.51f, -82.46f, 448.63f);
	leftWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[69].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[70].position = D3DXVECTOR3(-7.51f, -52.05f, 276.29f);
	leftWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[70].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[71].position = D3DXVECTOR3(-7.51f, -53.72f, 285.76f);
	leftWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[71].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[72].position = D3DXVECTOR3(-7.51f, -55.38f, 295.16f);
	leftWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[72].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[73].position = D3DXVECTOR3(-7.51f, -57.09f, 304.87f);
	leftWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[73].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[74].position = D3DXVECTOR3(-7.51f, -58.73f, 314.17f);
	leftWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[74].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[75].position = D3DXVECTOR3(-7.51f, -60.38f, 323.52f);
	leftWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[75].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[76].position = D3DXVECTOR3(-7.51f, -62.03f, 332.90f);
	leftWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[76].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[77].position = D3DXVECTOR3(-7.51f, -63.70f, 342.38f);
	leftWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[77].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[78].position = D3DXVECTOR3(-7.51f, -65.37f, 351.83f);
	leftWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[78].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[79].position = D3DXVECTOR3(-7.51f, -66.94f, 360.73f);
	leftWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[79].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[80].position = D3DXVECTOR3(-7.51f, -35.25f, 183.09f);
	leftWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[80].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[81].position = D3DXVECTOR3(-7.51f, -36.92f, 192.56f);
	leftWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[81].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[82].position = D3DXVECTOR3(-7.51f, -38.58f, 201.96f);
	leftWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[82].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[83].position = D3DXVECTOR3(-7.51f, -40.29f, 211.67f);
	leftWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[83].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[84].position = D3DXVECTOR3(-7.51f, -41.93f, 220.97f);
	leftWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[84].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[85].position = D3DXVECTOR3(-7.51f, -43.58f, 230.32f);
	leftWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[85].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[86].position = D3DXVECTOR3(-7.51f, -45.23f, 239.70f);
	leftWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[86].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[87].position = D3DXVECTOR3(-7.51f, -46.90f, 249.18f);
	leftWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[87].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[88].position = D3DXVECTOR3(-7.51f, -48.57f, 258.63f);
	leftWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[88].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[89].position = D3DXVECTOR3(-7.51f, -50.14f, 267.53f);
	leftWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[89].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[90].position = D3DXVECTOR3(-7.51f, -128.35f, 708.19f);
	leftWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[90].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[91].position = D3DXVECTOR3(-7.51f, -130.02f, 717.66f);
	leftWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[91].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[92].position = D3DXVECTOR3(-7.51f, -131.68f, 727.06f);
	leftWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[92].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[93].position = D3DXVECTOR3(-7.51f, -133.39f, 736.77f);
	leftWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[93].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[94].position = D3DXVECTOR3(-7.51f, -135.03f, 746.07f);
	leftWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[94].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[95].position = D3DXVECTOR3(-7.51f, -136.68f, 755.42f);
	leftWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[95].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[96].position = D3DXVECTOR3(-7.51f, -138.33f, 764.80f);
	leftWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[96].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[97].position = D3DXVECTOR3(-7.51f, -140.00f, 774.28f);
	leftWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[97].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[98].position = D3DXVECTOR3(-7.51f, -141.67f, 783.73f);
	leftWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[98].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[99].position = D3DXVECTOR3(-7.51f, -143.24f, 792.63f);
	leftWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[99].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[100].position = D3DXVECTOR3(-7.51f, -19.25f, 92.79f);
	leftWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[100].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[101].position = D3DXVECTOR3(-7.51f, -20.92f, 102.26f);
	leftWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[101].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[102].position = D3DXVECTOR3(-7.51f, -22.58f, 111.66f);
	leftWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[102].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[103].position = D3DXVECTOR3(-7.51f, -24.29f, 121.37f);
	leftWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[103].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[104].position = D3DXVECTOR3(-7.51f, -25.93f, 130.67f);
	leftWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[104].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[105].position = D3DXVECTOR3(-7.51f, -27.58f, 140.02f);
	leftWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[105].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[106].position = D3DXVECTOR3(-7.51f, -29.23f, 149.40f);
	leftWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[106].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[107].position = D3DXVECTOR3(-7.51f, -30.90f, 158.88f);
	leftWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[107].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[108].position = D3DXVECTOR3(-7.51f, -32.57f, 168.33f);
	leftWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[108].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[109].position = D3DXVECTOR3(-7.51f, -34.14f, 177.23f);
	leftWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[109].scale = D3DXVECTOR3(10, 1, 10);

	//GoalZone_Area
	goalCube.position = D3DXVECTOR3(0.36f, -177.09f, 979.49f);
	goalCube.rotation = D3DXVECTOR3(0.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	goalCube.scale = D3DXVECTOR3(20, 1, 20);

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
	goalCube.Draw(TEXTURE_INDEX_ICE);
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
Cube GoalCube() {
	return goalCube;
}

int GetCubeNum() {
	return CUBE_NUM;
}
int GetRightWallNum() {
	return RIGHT_WALL_NUM;
}
int GetLeftWallNum() {
	return LEFT_WALL_NUM;
}