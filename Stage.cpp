#include"figure.h"
#include"Stage.h"


//最大設置数
const int CUBE_NUM = 74;
const int ACCEL_SPEED_NUM = 1;
const int RIGHT_WALL_NUM = 28;
const int LEFT_WALL_NUM = 20;


//rotationのx,zは1.4ｆまで
Cube cube[CUBE_NUM];				//床
Cube accelSpeed[ACCEL_SPEED_NUM];	//加速床
Cube rightWall[RIGHT_WALL_NUM];		//右側の壁
Cube leftWall[LEFT_WALL_NUM];		//左側の壁
Cube goalCube;						//ゴール_床


void StageInit() {			//座標とサイズと角度を入れる

	cube[0].position = D3DXVECTOR3(-0.04f, -10.51f, 3.65f);
	cube[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[0].scale = D3DXVECTOR3(10, 1, 10);

	cube[1].position = D3DXVECTOR3(-0.04f, -12.21f, 13.28f);
	cube[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[1].scale = D3DXVECTOR3(10, 1, 10);

	cube[2].position = D3DXVECTOR3(-0.04f, -13.89f, 22.78f);
	cube[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[2].scale = D3DXVECTOR3(10, 1, 10);

	cube[3].position = D3DXVECTOR3(-0.04f, -15.57f, 32.36f);
	cube[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[3].scale = D3DXVECTOR3(10, 1, 10);

	cube[4].position = D3DXVECTOR3(-0.04f, -17.24f, 41.86f);
	cube[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[4].scale = D3DXVECTOR3(10, 1, 10);

	cube[5].position = D3DXVECTOR3(-0.04f, -18.90f, 51.25f);
	cube[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[5].scale = D3DXVECTOR3(10, 1, 10);

	cube[6].position = D3DXVECTOR3(-0.04f, -20.57f, 60.75f);
	cube[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[6].scale = D3DXVECTOR3(10, 1, 10);

	cube[7].position = D3DXVECTOR3(-0.04f, -22.15f, 69.70f);
	cube[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[7].scale = D3DXVECTOR3(10, 1, 10);

	cube[8].position = D3DXVECTOR3(-0.04f, -23.77f, 78.91f);
	cube[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[8].scale = D3DXVECTOR3(10, 1, 10);

	cube[9].position = D3DXVECTOR3(-0.04f, -25.39f, 88.09f);
	cube[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[9].scale = D3DXVECTOR3(10, 1, 10);

	cube[10].position = D3DXVECTOR3(0.03f, -27.18f, 93.51f);
	cube[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[10].scale = D3DXVECTOR3(10, 1, 10);


	cube[11].position = D3DXVECTOR3(-1.62f, -28.89f, 100.84f);
	cube[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (335.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[11].scale = D3DXVECTOR3(10, 1, 10);

	cube[12].position = D3DXVECTOR3(-6.09f, -30.56f, 106.72f);
	cube[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[12].scale = D3DXVECTOR3(10, 1, 10);

	cube[13].position = D3DXVECTOR3(-12.62f, -32.27f, 110.14f);
	cube[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (285.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[13].scale = D3DXVECTOR3(10, 1, 10);

	cube[14].position = D3DXVECTOR3(-20.93f, -33.98f, 111.14f);
	cube[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[14].scale = D3DXVECTOR3(10, 1, 10);

	cube[15].position = D3DXVECTOR3(-28.45f, -35.48f, 111.41f);
	cube[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[15].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[16].position = D3DXVECTOR3(-38.08f, -37.18f, 111.41f);
	cube[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[16].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[17].position = D3DXVECTOR3(-47.58f, -38.86f, 111.41f);
	cube[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[17].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[18].position = D3DXVECTOR3(-57.16f, -40.54f, 111.41f);
	cube[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[18].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[19].position = D3DXVECTOR3(-66.66f, -42.21f, 111.41f);
	cube[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[19].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[20].position = D3DXVECTOR3(-76.05f, -43.87f, 111.41f);
	cube[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[20].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[21].position = D3DXVECTOR3(-85.55f, -45.54f, 111.41f);
	cube[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[21].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[22].position = D3DXVECTOR3(-94.50f, -47.12f, 111.41f);
	cube[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[22].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[23].position = D3DXVECTOR3(-103.71f, -48.74f, 111.41f);
	cube[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[23].scale = D3DXVECTOR3(10, 1, 10.00003);

	cube[24].position = D3DXVECTOR3(-112.89f, -50.36f, 111.41f);
	cube[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[24].scale = D3DXVECTOR3(10, 1, 10.00003);


	cube[25].position = D3DXVECTOR3(3.85f, -11.21f, 3.53f);
	cube[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[25].scale = D3DXVECTOR3(10, 1, 10);

	cube[26].position = D3DXVECTOR3(3.86f, -12.92f, 13.24f);
	cube[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[26].scale = D3DXVECTOR3(10, 1, 10);

	cube[27].position = D3DXVECTOR3(3.86f, -14.61f, 22.86f);
	cube[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[27].scale = D3DXVECTOR3(10, 1, 10);

	cube[28].position = D3DXVECTOR3(3.86f, -16.28f, 32.35f);
	cube[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[28].scale = D3DXVECTOR3(10, 1, 10);

	cube[29].position = D3DXVECTOR3(3.86f, -17.90f, 41.53f);
	cube[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[29].scale = D3DXVECTOR3(10, 1, 10);

	cube[30].position = D3DXVECTOR3(3.86f, -19.52f, 50.74f);
	cube[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[30].scale = D3DXVECTOR3(10, 1, 10);

	cube[31].position = D3DXVECTOR3(3.86f, -21.19f, 60.22f);
	cube[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[31].scale = D3DXVECTOR3(10, 1, 10);

	cube[32].position = D3DXVECTOR3(3.86f, -22.86f, 69.69f);
	cube[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[32].scale = D3DXVECTOR3(10, 1, 10);

	cube[33].position = D3DXVECTOR3(3.86f, -24.55f, 79.25f);
	cube[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[33].scale = D3DXVECTOR3(10, 1, 10);

	cube[34].position = D3DXVECTOR3(3.86f, -26.10f, 88.02f);
	cube[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[34].scale = D3DXVECTOR3(10, 1, 10);

	cube[35].position = D3DXVECTOR3(4.91f, -26.96f, 93.43f);
	cube[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[35].scale = D3DXVECTOR3(10, 1, 10);


	cube[36].position = D3DXVECTOR3(3.74f, -28.40f, 100.63f);
	cube[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (335.00f - 360)*3.141592f/ 180, 40.00f*3.141592f / 180);
	cube[36].scale = D3DXVECTOR3(10, 1, 10);

	cube[37].position = D3DXVECTOR3(2.64f, -28.86f, 102.99f);
	cube[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (335.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[37].scale = D3DXVECTOR3(10, 1, 10);

	cube[38].position = D3DXVECTOR3(-0.78f, -30.23f, 108.25f);
	cube[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[38].scale = D3DXVECTOR3(10, 1, 10);

	cube[39].position = D3DXVECTOR3(-3.19f, -30.78f, 110.27f);
	cube[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[39].scale = D3DXVECTOR3(10, 1, 10);

	cube[40].position = D3DXVECTOR3(-9.64f, -32.22f, 114.15f);
	cube[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (285.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[40].scale = D3DXVECTOR3(10, 1, 10);

	cube[41].position = D3DXVECTOR3(-11.41f, -32.54f, 114.62f);
	cube[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (285.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[41].scale = D3DXVECTOR3(10, 1, 10);

	cube[42].position = D3DXVECTOR3(-19.06f, -34.04f, 115.80f);
	cube[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[42].scale = D3DXVECTOR3(10, 1, 10);

	cube[43].position = D3DXVECTOR3(-20.96f, -34.38f, 115.80f);
	cube[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[43].scale = D3DXVECTOR3(10, 1, 10);

	cube[44].position = D3DXVECTOR3(-28.33f, -36.18f, 115.30f);
	cube[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[44].scale = D3DXVECTOR3(10, 1, 10);

	cube[45].position = D3DXVECTOR3(-38.04f, -37.89f, 115.31f);
	cube[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[45].scale = D3DXVECTOR3(10, 1, 10); 

	cube[46].position = D3DXVECTOR3(-47.66f, -39.58f, 115.31f);
	cube[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[46].scale = D3DXVECTOR3(10, 1, 10);

	cube[47].position = D3DXVECTOR3(-57.15f, -41.25f, 115.31f);
	cube[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[47].scale = D3DXVECTOR3(10, 1, 10);

	cube[48].position = D3DXVECTOR3(-66.33f, -42.87f, 115.31f);
	cube[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[48].scale = D3DXVECTOR3(10, 1, 10);

	cube[49].position = D3DXVECTOR3(-75.54f, -44.49f, 115.31f);
	cube[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[49].scale = D3DXVECTOR3(10, 1, 10);

	cube[50].position = D3DXVECTOR3(-85.02f, -46.16f, 115.31f);
	cube[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[50].scale = D3DXVECTOR3(10, 1, 10);

	cube[51].position = D3DXVECTOR3(-94.49f, -47.83f, 115.31f);
	cube[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[51].scale = D3DXVECTOR3(10, 1, 10);

	cube[52].position = D3DXVECTOR3(-104.05f, -49.52f, 115.31f);
	cube[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[52].scale = D3DXVECTOR3(10, 1, 10);

	cube[53].position = D3DXVECTOR3(-112.82f, -51.07f, 115.31f);
	cube[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[53].scale = D3DXVECTOR3(10, 1, 10);


	cube[54].position = D3DXVECTOR3(-4.20f, -11.12f, 3.55f);
	cube[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[54].scale = D3DXVECTOR3(10, 1, 10);

	cube[55].position = D3DXVECTOR3(-4.20f, -12.81f, 13.13f);
	cube[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[55].scale = D3DXVECTOR3(10, 1, 10);

	cube[56].position = D3DXVECTOR3(-4.20f, -14.10f, 20.49f);
	cube[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[56].scale = D3DXVECTOR3(10, 1, 10);

	cube[57].position = D3DXVECTOR3(-4.20f, -15.81f, 30.16f);
	cube[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[57].scale = D3DXVECTOR3(10, 1, 10);

	cube[58].position = D3DXVECTOR3(-4.20f, -17.50f, 39.75f);
	cube[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[58].scale = D3DXVECTOR3(10, 1, 10);

	cube[59].position = D3DXVECTOR3(-4.20f, -19.21f, 49.42f);
	cube[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[59].scale = D3DXVECTOR3(10, 1, 10);

	cube[60].position = D3DXVECTOR3(-4.20f, -20.92f, 59.11f);
	cube[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[60].scale = D3DXVECTOR3(10, 1, 10);

	cube[61].position = D3DXVECTOR3(-4.20f, -22.62f, 68.74f);
	cube[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[61].scale = D3DXVECTOR3(10, 1, 10);

	cube[62].position = D3DXVECTOR3(-4.20f, -24.34f, 78.48f);
	cube[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[62].scale = D3DXVECTOR3(10, 1, 10);

	cube[63].position = D3DXVECTOR3(-4.20f, -26.02f, 87.99f);
	cube[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[63].scale = D3DXVECTOR3(10, 1, 10);


	cube[64].position = D3DXVECTOR3(-28.35f, -36.09f, 107.25f);
	cube[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[64].scale = D3DXVECTOR3(10, 1, 10);

	cube[65].position = D3DXVECTOR3(-37.93f, -37.78f, 107.25f);
	cube[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[65].scale = D3DXVECTOR3(10, 1, 10);

	cube[66].position = D3DXVECTOR3(-45.29f, -39.07f, 107.25f);
	cube[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[66].scale = D3DXVECTOR3(10, 1, 10);

	cube[67].position = D3DXVECTOR3(-54.96f, -40.78f, 107.25f);
	cube[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[67].scale = D3DXVECTOR3(10, 1, 10);

	cube[68].position = D3DXVECTOR3(-64.55f, -42.47f, 107.25f);
	cube[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[68].scale = D3DXVECTOR3(10, 1, 10);

	cube[69].position = D3DXVECTOR3(-74.22f, -44.18f, 107.25f);
	cube[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[69].scale = D3DXVECTOR3(10, 1, 10);

	cube[70].position = D3DXVECTOR3(-83.91f, -45.89f, 107.25f);
	cube[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[70].scale = D3DXVECTOR3(10, 1, 10);

	cube[71].position = D3DXVECTOR3(-93.54f, -47.59f, 107.25f);
	cube[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[71].scale = D3DXVECTOR3(10, 1, 10);

	cube[72].position = D3DXVECTOR3(-103.28f, -49.31f, 107.25f);
	cube[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[72].scale = D3DXVECTOR3(10, 1, 10);

	cube[73].position = D3DXVECTOR3(-112.79f, -50.99f, 107.25f);
	cube[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[73].scale = D3DXVECTOR3(10, 1, 10);


	rightWall[0].position = D3DXVECTOR3(7.36f, -9.67f, 3.80f);
	rightWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[0].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[1].position = D3DXVECTOR3(7.36f, -11.38f, 13.50f);
	rightWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[1].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[2].position = D3DXVECTOR3(7.36f, -13.04f, 22.91f);
	rightWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[2].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[3].position = D3DXVECTOR3(7.36f, -14.72f, 32.43f);
	rightWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[3].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[4].position = D3DXVECTOR3(7.36f, -16.43f, 42.13f);
	rightWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[4].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[5].position = D3DXVECTOR3(7.36f, -18.13f, 51.75f);
	rightWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[5].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[6].position = D3DXVECTOR3(7.36f, -19.82f, 61.32f);
	rightWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[6].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[7].position = D3DXVECTOR3(7.36f, -21.52f, 70.93f);
	rightWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[7].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[8].position = D3DXVECTOR3(7.36f, -23.22f, 80.55f);
	rightWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[8].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[9].position = D3DXVECTOR3(7.36f, -24.59f, 88.33f);
	rightWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[9].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[10].position = D3DXVECTOR3(7.52f, -26.91f, 93.11f);
	rightWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[10].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[11].position = D3DXVECTOR3(6.82f, -28.45f, 100.84f);
	rightWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 335.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[11].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[12].position = D3DXVECTOR3(5.72f, -28.91f, 103.20f);
	rightWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 335.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[12].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[13].position = D3DXVECTOR3(2.56f, -30.33f, 109.10f);
	rightWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[13].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[14].position = D3DXVECTOR3(-4.20f, -31.88f, 114.77f);
	rightWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[14].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[15].position = D3DXVECTOR3(-9.49f, -33.07f, 117.80f);
	rightWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 285.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[15].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[16].position = D3DXVECTOR3(-16.40f, -34.30f, 118.82f);
	rightWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[16].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[17].position = D3DXVECTOR3(-20.88f, -35.09f, 118.80f);
	rightWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[17].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[18].position = D3DXVECTOR3(-28.60f, -34.64f, 118.81f);
	rightWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[18].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[19].position = D3DXVECTOR3(-38.30f, -36.35f, 118.81f);
	rightWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[19].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[20].position = D3DXVECTOR3(-47.71f, -38.01f, 118.81f);
	rightWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[20].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[21].position = D3DXVECTOR3(-57.23f, -39.69f, 118.81f);
	rightWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[21].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[22].position = D3DXVECTOR3(-66.93f, -41.40f, 118.81f);
	rightWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[22].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[23].position = D3DXVECTOR3(-76.55f, -43.10f, 118.81f);
	rightWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[23].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[24].position = D3DXVECTOR3(-86.12f, -44.79f, 118.81f);
	rightWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[24].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[25].position = D3DXVECTOR3(-95.73f, -46.49f, 118.81f);
	rightWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[25].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[26].position = D3DXVECTOR3(-105.35f, -48.19f, 118.81f);
	rightWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[26].scale = D3DXVECTOR3(10, 1, 10);

	rightWall[27].position = D3DXVECTOR3(-113.13f, -49.56f, 118.81f);
	rightWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[27].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[0].position = D3DXVECTOR3(-7.97f, -9.75f, 3.79f);
	leftWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[0].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[1].position = D3DXVECTOR3(-7.97f, -11.42f, 13.26f);
	leftWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[1].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[2].position = D3DXVECTOR3(-7.97f, -13.08f, 22.66f);
	leftWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[2].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[3].position = D3DXVECTOR3(-7.97f, -14.79f, 32.37f);
	leftWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[3].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[4].position = D3DXVECTOR3(-7.97f, -16.43f, 41.67f);
	leftWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[4].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[5].position = D3DXVECTOR3(-7.97f, -18.08f, 51.02f);
	leftWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[5].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[6].position = D3DXVECTOR3(-7.97f, -19.73f, 60.40f);
	leftWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[6].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[7].position = D3DXVECTOR3(-7.97f, -21.40f, 69.88f);
	leftWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[7].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[8].position = D3DXVECTOR3(-7.97f, -23.07f, 79.33f);
	leftWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[8].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[9].position = D3DXVECTOR3(-7.97f, -24.64f, 88.23f);
	leftWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[9].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[10].position = D3DXVECTOR3(-28.59f, -34.72f, 103.48f);
	leftWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[10].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[11].position = D3DXVECTOR3(-38.06f, -36.39f, 103.48f);
	leftWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[11].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[12].position = D3DXVECTOR3(-47.46f, -38.05f, 103.48f);
	leftWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[12].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[13].position = D3DXVECTOR3(-57.17f, -39.76f, 103.48f);
	leftWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[13].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[14].position = D3DXVECTOR3(-66.47f, -41.40f, 103.48f);
	leftWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[14].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[15].position = D3DXVECTOR3(-75.82f, -43.05f, 103.48f);
	leftWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[15].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[16].position = D3DXVECTOR3(-85.20f, -44.70f, 103.48f);
	leftWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[16].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[17].position = D3DXVECTOR3(-94.68f, -46.37f, 103.48f);
	leftWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[17].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[18].position = D3DXVECTOR3(-104.13f, -48.04f, 103.48f);
	leftWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[18].scale = D3DXVECTOR3(10, 1, 10);

	leftWall[19].position = D3DXVECTOR3(-113.03f, -49.61f, 103.48f);
	leftWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[19].scale = D3DXVECTOR3(10, 1, 10);

	//加速床
	accelSpeed[0].position= D3DXVECTOR3(-0.04f, -20.57f, 60.75f);
	accelSpeed[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[0].scale = D3DXVECTOR3(2, 1.5 ,1);

	//ゴール床
	goalCube.position = D3DXVECTOR3(-120.00f, -51.00f, 111.41f);
	goalCube.rotation = D3DXVECTOR3(0.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	goalCube.scale = D3DXVECTOR3(20,0,20);

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

	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		accelSpeed[i].Draw(TEXTURE_INDEX_MAX, D3DXCOLOR(1, 0 , 0 , 1));
	}
}


Cube GetCube(int n) {
	return cube[n];
}
Cube GetAccelSpeedCube(int n) {
	return accelSpeed[n];
}
Cube GetRightWall(int n) {
	return rightWall[n];
}
Cube GetLeftWall(int n) {
	return leftWall[n];
}
Cube GetGoalCube() {
	return goalCube;
}


int GetCubeNum() {
	return CUBE_NUM;
}
int GetAccelSpeedNum() {
	return ACCEL_SPEED_NUM;
}
int GetRightWallNum() {
	return RIGHT_WALL_NUM;
}
int GetLeftWallNum() {
	return LEFT_WALL_NUM;
}