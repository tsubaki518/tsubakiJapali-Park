#include"figure.h"
#include"Stage.h"
#include"Game.h"

//最大設置数
const int CUBE_NUM = 600;
const int ACCEL_SPEED_NUM = 1;
const int RIGHT_WALL_NUM = 150;
const int LEFT_WALL_NUM = 150;


//rotationのx,zは1.4ｆまで
Plane cube[CUBE_NUM];				//床
Cube accelSpeed[ACCEL_SPEED_NUM];	//加速床
Cube rightWall[RIGHT_WALL_NUM];		//右側の壁
Cube leftWall[LEFT_WALL_NUM];		//左側の壁
Cube goalCube;						//ゴール_床


void StageInit() {			//座標とサイズと角度を入れる
	//ステージ座標
	cube[0].position = D3DXVECTOR3(-0.30f, -11.48f, 0.41f);
	cube[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[0].scale = D3DXVECTOR3(10, 1, 10);

	cube[1].position = D3DXVECTOR3(-0.30f, -13.24f, 10.08f);
	cube[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[1].scale = D3DXVECTOR3(10, 1, 10);

	cube[2].position = D3DXVECTOR3(-0.30f, -14.91f, 19.09f);
	cube[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[2].scale = D3DXVECTOR3(10, 1, 10);

	cube[3].position = D3DXVECTOR3(-0.22f, -16.53f, 28.09f);
	cube[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[3].scale = D3DXVECTOR3(10, 1, 10);

	cube[4].position = D3DXVECTOR3(-0.22f, -18.19f, 35.69f);
	cube[4].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[4].scale = D3DXVECTOR3(14, 1, 6);

	cube[5].position = D3DXVECTOR3(-0.52f, -18.18f, 34.96f);
	cube[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[5].scale = D3DXVECTOR3(10, 1, 10);

	cube[6].position = D3DXVECTOR3(-1.78f, -19.79f, 42.15f);
	cube[6].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[6].scale = D3DXVECTOR3(14, 1, 5);

	cube[7].position = D3DXVECTOR3(-2.12f, -19.79f, 41.75f);
	cube[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[7].scale = D3DXVECTOR3(10, 1, 10);

	cube[8].position = D3DXVECTOR3(-4.72f, -21.46f, 48.88f);
	cube[8].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[8].scale = D3DXVECTOR3(15, 1, 6);

	cube[9].position = D3DXVECTOR3(-4.93f, -21.49f, 48.29f);
	cube[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[9].scale = D3DXVECTOR3(10, 1, 10);

	cube[10].position = D3DXVECTOR3(-8.47f, -23.07f, 54.68f);
	cube[10].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[10].scale = D3DXVECTOR3(15, 1, 5.5);

	cube[11].position = D3DXVECTOR3(-8.43f, -22.97f, 53.74f);
	cube[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[11].scale = D3DXVECTOR3(10, 1, 10);

	cube[12].position = D3DXVECTOR3(-13.24f, -24.59f, 59.47f);
	cube[12].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[12].scale = D3DXVECTOR3(15, 1, 6.2);

	cube[13].position = D3DXVECTOR3(-13.07f, -24.59f, 58.74f);
	cube[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[13].scale = D3DXVECTOR3(10, 1, 10);

	cube[14].position = D3DXVECTOR3(-18.65f, -26.13f, 63.43f);
	cube[14].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[14].scale = D3DXVECTOR3(15, 1, 5.5);

	cube[15].position = D3DXVECTOR3(-18.04f, -26.05f, 62.59f);
	cube[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[15].scale = D3DXVECTOR3(10, 1, 10);

	cube[16].position = D3DXVECTOR3(-24.64f, -27.70f, 66.39f);
	cube[16].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[16].scale = D3DXVECTOR3(15, 1, 6);

	cube[17].position = D3DXVECTOR3(-24.22f, -27.70f, 65.71f);
	cube[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[17].scale = D3DXVECTOR3(10, 1, 10);

	cube[18].position = D3DXVECTOR3(-31.26f, -29.31f, 68.27f);
	cube[18].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[18].scale = D3DXVECTOR3(16, 1, 6);

	cube[19].position = D3DXVECTOR3(-31.80f, -29.44f, 67.88f);
	cube[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[19].scale = D3DXVECTOR3(10, 1, 10);

	cube[20].position = D3DXVECTOR3(-39.73f, -31.08f, 69.28f);
	cube[20].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[20].scale = D3DXVECTOR3(15, 1, 7);

	cube[21].position = D3DXVECTOR3(-39.59f, -31.12f, 68.73f);
	cube[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[21].scale = D3DXVECTOR3(10, 1, 10);

	cube[22].position = D3DXVECTOR3(-46.06f, -32.45f, 68.84f);
	cube[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[22].scale = D3DXVECTOR3(10, 1, 10);

	cube[23].position = D3DXVECTOR3(-53.66f, -34.10f, 68.84f);
	cube[23].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[23].scale = D3DXVECTOR3(14.00001, 1, 6);

	cube[24].position = D3DXVECTOR3(-52.93f, -34.10f, 68.54f);
	cube[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[24].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[25].position = D3DXVECTOR3(-60.12f, -35.70f, 67.28f);
	cube[25].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[25].scale = D3DXVECTOR3(14, 1, 5);

	cube[26].position = D3DXVECTOR3(-59.72f, -35.71f, 66.94f);
	cube[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[26].scale = D3DXVECTOR3(10, 1, 10);

	cube[27].position = D3DXVECTOR3(-66.85f, -37.37f, 64.34f);
	cube[27].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[27].scale = D3DXVECTOR3(15.00001, 1, 6);

	cube[28].position = D3DXVECTOR3(-66.26f, -37.41f, 64.13f);
	cube[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[28].scale = D3DXVECTOR3(10, 1, 10);

	cube[29].position = D3DXVECTOR3(-72.65f, -38.98f, 60.59f);
	cube[29].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[29].scale = D3DXVECTOR3(15.00001, 1, 5.500003);

	cube[30].position = D3DXVECTOR3(-71.71f, -38.89f, 60.63f);
	cube[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[30].scale = D3DXVECTOR3(10, 1, 10);

	cube[31].position = D3DXVECTOR3(-77.44f, -40.50f, 55.82f);
	cube[31].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[31].scale = D3DXVECTOR3(15.00001, 1, 6.200005);

	cube[32].position = D3DXVECTOR3(-76.72f, -40.51f, 55.99f);
	cube[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[32].scale = D3DXVECTOR3(10, 1, 10);

	cube[33].position = D3DXVECTOR3(-81.40f, -42.04f, 50.41f);
	cube[33].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[33].scale = D3DXVECTOR3(15.00001, 1, 5.500005);

	cube[34].position = D3DXVECTOR3(-80.56f, -41.97f, 51.02f);
	cube[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[34].scale = D3DXVECTOR3(10.00002, 1, 10.00002);

	cube[35].position = D3DXVECTOR3(-84.36f, -43.61f, 44.42f);
	cube[35].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[35].scale = D3DXVECTOR3(15.00002, 1, 6);

	cube[36].position = D3DXVECTOR3(-83.68f, -43.62f, 44.84f);
	cube[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[36].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[37].position = D3DXVECTOR3(-86.24f, -45.22f, 37.80f);
	cube[37].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[37].scale = D3DXVECTOR3(16.00003, 1, 6);

	cube[38].position = D3DXVECTOR3(-85.85f, -45.36f, 37.26f);
	cube[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[38].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[39].position = D3DXVECTOR3(-87.25f, -46.99f, 29.33f);
	cube[39].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[39].scale = D3DXVECTOR3(15.00002, 1, 7.000011);

	cube[40].position = D3DXVECTOR3(-86.70f, -47.04f, 29.47f);
	cube[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[40].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[41].position = D3DXVECTOR3(-86.68f, -48.77f, 19.91f);
	cube[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[41].scale = D3DXVECTOR3(10, 1, 10);

	cube[42].position = D3DXVECTOR3(-86.68f, -50.52f, 10.35f);
	cube[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[42].scale = D3DXVECTOR3(10, 1, 10);

	cube[43].position = D3DXVECTOR3(-86.68f, -52.30f, 0.79f);
	cube[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[43].scale = D3DXVECTOR3(10, 1, 10);

	cube[44].position = D3DXVECTOR3(-86.68f, -54.08f, -8.86f);
	cube[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[44].scale = D3DXVECTOR3(10, 1, 10);

	cube[45].position = D3DXVECTOR3(-86.68f, -55.79f, -18.25f);
	cube[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[45].scale = D3DXVECTOR3(10, 1, 10);

	cube[46].position = D3DXVECTOR3(-86.70f, -57.26f, -26.69f);
	cube[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[46].scale = D3DXVECTOR3(10, 1, 10);

	cube[47].position = D3DXVECTOR3(-86.70f, -58.98f, -36.39f);
	cube[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[47].scale = D3DXVECTOR3(10, 1, 10);

	cube[48].position = D3DXVECTOR3(-86.68f, -60.73f, -45.69f);
	cube[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[48].scale = D3DXVECTOR3(10, 1, 10);

	cube[49].position = D3DXVECTOR3(-86.68f, -62.51f, -55.06f);
	cube[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[49].scale = D3DXVECTOR3(10, 1, 10);

	cube[50].position = D3DXVECTOR3(-86.68f, -64.26f, -64.57f);
	cube[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[50].scale = D3DXVECTOR3(10, 1, 10);

	cube[51].position = D3DXVECTOR3(-86.68f, -65.98f, -73.60f);
	cube[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[51].scale = D3DXVECTOR3(10, 1, 10);

	cube[52].position = D3DXVECTOR3(-86.68f, -67.70f, -83.67f);
	cube[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[52].scale = D3DXVECTOR3(10, 1, 10);

	cube[53].position = D3DXVECTOR3(-86.68f, -69.13f, -90.96f);
	cube[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[53].scale = D3DXVECTOR3(10, 1, 10);

	cube[54].position = D3DXVECTOR3(-86.68f, -70.78f, -98.56f);
	cube[54].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[54].scale = D3DXVECTOR3(14.00001, 1, 6);

	cube[55].position = D3DXVECTOR3(-86.38f, -70.78f, -97.83f);
	cube[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[55].scale = D3DXVECTOR3(10, 1, 10);

	cube[56].position = D3DXVECTOR3(-85.12f, -72.38f, -105.02f);
	cube[56].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[56].scale = D3DXVECTOR3(14, 1, 5);

	cube[57].position = D3DXVECTOR3(-84.78f, -72.39f, -104.62f);
	cube[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[57].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[58].position = D3DXVECTOR3(-82.18f, -74.05f, -111.75f);
	cube[58].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[58].scale = D3DXVECTOR3(15.00001, 1, 6);

	cube[59].position = D3DXVECTOR3(-81.97f, -74.09f, -111.16f);
	cube[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[59].scale = D3DXVECTOR3(10, 1, 10);

	cube[60].position = D3DXVECTOR3(-78.43f, -75.66f, -117.55f);
	cube[60].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[60].scale = D3DXVECTOR3(15, 1, 5.5);

	cube[61].position = D3DXVECTOR3(-78.47f, -75.57f, -116.61f);
	cube[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[61].scale = D3DXVECTOR3(10, 1, 10);

	cube[62].position = D3DXVECTOR3(-73.66f, -77.18f, -122.34f);
	cube[62].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[62].scale = D3DXVECTOR3(15, 1, 6.200002);

	cube[63].position = D3DXVECTOR3(-73.83f, -77.19f, -121.62f);
	cube[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[63].scale = D3DXVECTOR3(10, 1, 10);

	cube[64].position = D3DXVECTOR3(-68.25f, -78.72f, -126.30f);
	cube[64].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[64].scale = D3DXVECTOR3(15, 1, 5.499999);

	cube[65].position = D3DXVECTOR3(-68.86f, -78.65f, -125.46f);
	cube[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[65].scale = D3DXVECTOR3(10, 1, 10);

	cube[66].position = D3DXVECTOR3(-62.26f, -80.29f, -129.26f);
	cube[66].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[66].scale = D3DXVECTOR3(15, 1, 6);

	cube[67].position = D3DXVECTOR3(-62.68f, -80.30f, -128.58f);
	cube[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[67].scale = D3DXVECTOR3(10, 1, 10);

	cube[68].position = D3DXVECTOR3(-55.64f, -81.90f, -131.14f);
	cube[68].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[68].scale = D3DXVECTOR3(16, 1, 6);

	cube[69].position = D3DXVECTOR3(-55.10f, -82.04f, -130.75f);
	cube[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[69].scale = D3DXVECTOR3(10, 1, 10);

	cube[70].position = D3DXVECTOR3(-47.17f, -83.67f, -132.15f);
	cube[70].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[70].scale = D3DXVECTOR3(15, 1, 7);

	cube[71].position = D3DXVECTOR3(-47.31f, -83.72f, -131.60f);
	cube[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[71].scale = D3DXVECTOR3(10, 1, 10);

	cube[72].position = D3DXVECTOR3(-38.10f, -85.43f, -131.62f);
	cube[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[72].scale = D3DXVECTOR3(10, 1, 10);

	cube[73].position = D3DXVECTOR3(-30.50f, -87.08f, -131.62f);
	cube[73].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[73].scale = D3DXVECTOR3(14.00001, 1, 6);

	cube[74].position = D3DXVECTOR3(-31.23f, -87.08f, -131.32f);
	cube[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[74].scale = D3DXVECTOR3(10, 1, 10);

	cube[75].position = D3DXVECTOR3(-24.04f, -88.68f, -130.06f);
	cube[75].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[75].scale = D3DXVECTOR3(14, 1, 5);

	cube[76].position = D3DXVECTOR3(-24.44f, -88.69f, -129.72f);
	cube[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[76].scale = D3DXVECTOR3(10, 1, 10);

	cube[77].position = D3DXVECTOR3(-17.31f, -90.35f, -127.12f);
	cube[77].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[77].scale = D3DXVECTOR3(15, 1, 6);

	cube[78].position = D3DXVECTOR3(-17.90f, -90.39f, -126.91f);
	cube[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[78].scale = D3DXVECTOR3(10, 1, 10);

	cube[79].position = D3DXVECTOR3(-11.51f, -91.96f, -123.37f);
	cube[79].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[79].scale = D3DXVECTOR3(15, 1, 5.500002);

	cube[80].position = D3DXVECTOR3(-12.45f, -91.87f, -123.41f);
	cube[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[80].scale = D3DXVECTOR3(10, 1, 10);

	cube[81].position = D3DXVECTOR3(-6.72f, -93.48f, -118.60f);
	cube[81].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[81].scale = D3DXVECTOR3(15, 1, 6.200002);

	cube[82].position = D3DXVECTOR3(-7.44f, -93.49f, -118.77f);
	cube[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[82].scale = D3DXVECTOR3(10, 1, 10);

	cube[83].position = D3DXVECTOR3(-2.76f, -95.02f, -113.19f);
	cube[83].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[83].scale = D3DXVECTOR3(15, 1, 5.500001);

	cube[84].position = D3DXVECTOR3(-3.60f, -94.95f, -113.80f);
	cube[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[84].scale = D3DXVECTOR3(10, 1, 10);

	cube[85].position = D3DXVECTOR3(0.20f, -96.59f, -107.20f);
	cube[85].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[85].scale = D3DXVECTOR3(15, 1, 6);

	cube[86].position = D3DXVECTOR3(-0.48f, -96.60f, -107.62f);
	cube[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[86].scale = D3DXVECTOR3(10, 1, 10);

	cube[87].position = D3DXVECTOR3(2.08f, -98.20f, -100.58f);
	cube[87].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[87].scale = D3DXVECTOR3(16, 1, 6);

	cube[88].position = D3DXVECTOR3(1.69f, -98.34f, -100.04f);
	cube[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[88].scale = D3DXVECTOR3(10, 1, 10);

	cube[89].position = D3DXVECTOR3(3.09f, -99.97f, -92.11f);
	cube[89].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[89].scale = D3DXVECTOR3(15, 1, 7);

	cube[90].position = D3DXVECTOR3(2.54f, -100.02f, -92.25f);
	cube[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[90].scale = D3DXVECTOR3(10, 1, 10);

	cube[91].position = D3DXVECTOR3(2.48f, -101.67f, -83.21f);
	cube[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[91].scale = D3DXVECTOR3(10, 1, 10);

	cube[92].position = D3DXVECTOR3(2.48f, -103.41f, -73.71f);
	cube[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[92].scale = D3DXVECTOR3(10, 1, 10);

	cube[93].position = D3DXVECTOR3(2.48f, -105.14f, -64.51f);
	cube[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[93].scale = D3DXVECTOR3(10, 1, 10);

	cube[94].position = D3DXVECTOR3(4.51f, -11.49f, 0.41f);
	cube[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[94].scale = D3DXVECTOR3(3, 1, 10);

	cube[95].position = D3DXVECTOR3(7.08f, -10.43f, 0.62f);
	cube[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[95].scale = D3DXVECTOR3(3, 1, 10);

	cube[96].position = D3DXVECTOR3(9.40f, -8.83f, 0.90f);
	cube[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[96].scale = D3DXVECTOR3(3, 1, 10);

	cube[97].position = D3DXVECTOR3(4.51f, -13.25f, 10.08f);
	cube[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[97].scale = D3DXVECTOR3(3, 1, 10);

	cube[98].position = D3DXVECTOR3(7.08f, -12.19f, 10.29f);
	cube[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[98].scale = D3DXVECTOR3(3, 1, 10);

	cube[99].position = D3DXVECTOR3(9.40f, -10.59f, 10.57f);
	cube[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[99].scale = D3DXVECTOR3(3, 1, 10);

	cube[100].position = D3DXVECTOR3(4.51f, -14.92f, 19.09f);
	cube[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[100].scale = D3DXVECTOR3(3, 1, 10);

	cube[101].position = D3DXVECTOR3(7.08f, -13.86f, 19.30f);
	cube[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[101].scale = D3DXVECTOR3(3, 1, 10);

	cube[102].position = D3DXVECTOR3(9.40f, -12.26f, 19.58f);
	cube[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[102].scale = D3DXVECTOR3(3, 1, 10);

	cube[103].position = D3DXVECTOR3(4.59f, -16.54f, 28.08f);
	cube[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[103].scale = D3DXVECTOR3(3, 1, 10);

	cube[104].position = D3DXVECTOR3(7.16f, -15.48f, 28.29f);
	cube[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[104].scale = D3DXVECTOR3(3, 1, 10);

	cube[105].position = D3DXVECTOR3(9.48f, -13.88f, 28.57f);
	cube[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[105].scale = D3DXVECTOR3(3, 1, 10);

	cube[106].position = D3DXVECTOR3(4.22f, -18.19f, 35.79f);
	cube[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[106].scale = D3DXVECTOR3(3, 1, 10);

	cube[107].position = D3DXVECTOR3(6.71f, -17.13f, 36.44f);
	cube[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[107].scale = D3DXVECTOR3(3, 1, 10);

	cube[108].position = D3DXVECTOR3(8.95f, -15.53f, 37.12f);
	cube[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[108].scale = D3DXVECTOR3(3, 1, 10);

	cube[109].position = D3DXVECTOR3(2.39f, -19.80f, 43.39f);
	cube[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[109].scale = D3DXVECTOR3(3, 1, 10);

	cube[110].position = D3DXVECTOR3(4.74f, -18.74f, 44.46f);
	cube[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[110].scale = D3DXVECTOR3(3, 1, 10);

	cube[111].position = D3DXVECTOR3(6.82f, -17.14f, 45.52f);
	cube[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[111].scale = D3DXVECTOR3(3, 1, 10);

	cube[112].position = D3DXVECTOR3(-0.76f, -21.50f, 50.69f);
	cube[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[112].scale = D3DXVECTOR3(3, 1, 10);

	cube[113].position = D3DXVECTOR3(1.36f, -20.44f, 52.15f);
	cube[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[113].scale = D3DXVECTOR3(3, 1, 10);

	cube[114].position = D3DXVECTOR3(3.23f, -18.84f, 53.55f);
	cube[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[114].scale = D3DXVECTOR3(3, 1, 10);

	cube[115].position = D3DXVECTOR3(-4.74f, -22.98f, 56.83f);
	cube[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[115].scale = D3DXVECTOR3(3, 1, 10);

	cube[116].position = D3DXVECTOR3(-2.91f, -21.92f, 58.64f);
	cube[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[116].scale = D3DXVECTOR3(3, 1, 10);

	cube[117].position = D3DXVECTOR3(-1.31f, -20.32f, 60.34f);
	cube[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[117].scale = D3DXVECTOR3(3, 1, 10);

	cube[118].position = D3DXVECTOR3(-9.97f, -24.60f, 62.42f);
	cube[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[118].scale = D3DXVECTOR3(3, 1, 10);

	cube[119].position = D3DXVECTOR3(-8.48f, -23.54f, 64.53f);
	cube[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[119].scale = D3DXVECTOR3(3, 1, 10);

	cube[120].position = D3DXVECTOR3(-7.21f, -21.94f, 66.48f);
	cube[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[120].scale = D3DXVECTOR3(3, 1, 10);

	cube[121].position = D3DXVECTOR3(-15.63f, -26.06f, 66.75f);
	cube[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[121].scale = D3DXVECTOR3(3, 1, 10);

	cube[122].position = D3DXVECTOR3(-14.53f, -25.00f, 69.08f);
	cube[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[122].scale = D3DXVECTOR3(3, 1, 10);

	cube[123].position = D3DXVECTOR3(-13.61f, -23.40f, 71.23f);
	cube[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[123].scale = D3DXVECTOR3(3, 1, 10);

	cube[124].position = D3DXVECTOR3(-22.57f, -27.71f, 70.22f);
	cube[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[124].scale = D3DXVECTOR3(3, 1, 10);

	cube[125].position = D3DXVECTOR3(-21.89f, -26.65f, 72.71f);
	cube[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[125].scale = D3DXVECTOR3(3, 1, 10);

	cube[126].position = D3DXVECTOR3(-21.36f, -25.05f, 74.98f);
	cube[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[126].scale = D3DXVECTOR3(3, 1, 10);

	cube[127].position = D3DXVECTOR3(-30.96f, -29.45f, 72.61f);
	cube[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[127].scale = D3DXVECTOR3(3, 1, 10);

	cube[128].position = D3DXVECTOR3(-30.72f, -28.39f, 75.18f);
	cube[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[128].scale = D3DXVECTOR3(3, 1, 10);

	cube[129].position = D3DXVECTOR3(-30.60f, -26.79f, 77.51f);
	cube[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[129].scale = D3DXVECTOR3(3, 1, 10);

	cube[130].position = D3DXVECTOR3(-39.59f, -31.13f, 73.53f);
	cube[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[130].scale = D3DXVECTOR3(3, 1, 10);

	cube[131].position = D3DXVECTOR3(-39.80f, -30.07f, 76.11f);
	cube[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[131].scale = D3DXVECTOR3(3, 1, 10);

	cube[132].position = D3DXVECTOR3(-40.08f, -28.47f, 78.42f);
	cube[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[132].scale = D3DXVECTOR3(3, 1, 10);

	cube[133].position = D3DXVECTOR3(-46.05f, -32.45f, 73.65f);
	cube[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[133].scale = D3DXVECTOR3(3, 1, 10);

	cube[134].position = D3DXVECTOR3(-46.26f, -31.39f, 76.22f);
	cube[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[134].scale = D3DXVECTOR3(3, 1, 10);

	cube[135].position = D3DXVECTOR3(-46.54f, -29.79f, 78.54f);
	cube[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[135].scale = D3DXVECTOR3(3, 1, 10);

	cube[136].position = D3DXVECTOR3(-53.76f, -34.10f, 73.28f);
	cube[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[136].scale = D3DXVECTOR3(3, 1, 10);

	cube[137].position = D3DXVECTOR3(-54.41f, -33.04f, 75.77f);
	cube[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[137].scale = D3DXVECTOR3(3, 1, 10);

	cube[138].position = D3DXVECTOR3(-55.09f, -31.44f, 78.01f);
	cube[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[138].scale = D3DXVECTOR3(3, 1, 10);

	cube[139].position = D3DXVECTOR3(-61.36f, -35.71f, 71.45f);
	cube[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[139].scale = D3DXVECTOR3(3, 1, 10);

	cube[140].position = D3DXVECTOR3(-62.44f, -34.65f, 73.80f);
	cube[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[140].scale = D3DXVECTOR3(3, 1, 10);

	cube[141].position = D3DXVECTOR3(-63.49f, -33.05f, 75.88f);
	cube[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[141].scale = D3DXVECTOR3(3, 1, 10);

	cube[142].position = D3DXVECTOR3(-68.66f, -37.41f, 68.30f);
	cube[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[142].scale = D3DXVECTOR3(3, 1, 10);

	cube[143].position = D3DXVECTOR3(-70.13f, -36.35f, 70.42f);
	cube[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[143].scale = D3DXVECTOR3(3, 1, 10);

	cube[144].position = D3DXVECTOR3(-71.53f, -34.75f, 72.29f);
	cube[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[144].scale = D3DXVECTOR3(3, 1, 10);

	cube[145].position = D3DXVECTOR3(-74.80f, -38.89f, 64.32f);
	cube[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[145].scale = D3DXVECTOR3(3, 1, 10);

	cube[146].position = D3DXVECTOR3(-76.61f, -37.83f, 66.15f);
	cube[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[146].scale = D3DXVECTOR3(3, 1, 10);

	cube[147].position = D3DXVECTOR3(-78.32f, -36.23f, 67.75f);
	cube[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[147].scale = D3DXVECTOR3(3, 1, 10);

	cube[148].position = D3DXVECTOR3(-80.39f, -40.51f, 59.09f);
	cube[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[148].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[149].position = D3DXVECTOR3(-82.50f, -39.45f, 60.58f);
	cube[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[149].scale = D3DXVECTOR3(3, 1, 10);

	cube[150].position = D3DXVECTOR3(-84.45f, -37.85f, 61.85f);
	cube[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[150].scale = D3DXVECTOR3(3, 1, 10);

	cube[151].position = D3DXVECTOR3(-84.72f, -41.97f, 53.43f);
	cube[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[151].scale = D3DXVECTOR3(3, 1, 10);

	cube[152].position = D3DXVECTOR3(-87.05f, -40.91f, 54.53f);
	cube[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[152].scale = D3DXVECTOR3(3, 1, 10);

	cube[153].position = D3DXVECTOR3(-89.20f, -39.31f, 55.45f);
	cube[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[153].scale = D3DXVECTOR3(3, 1, 10);

	cube[154].position = D3DXVECTOR3(-88.19f, -43.62f, 46.49f);
	cube[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[154].scale = D3DXVECTOR3(3, 1, 10);

	cube[155].position = D3DXVECTOR3(-90.68f, -42.56f, 47.17f);
	cube[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[155].scale = D3DXVECTOR3(3, 1, 10);

	cube[156].position = D3DXVECTOR3(-92.96f, -40.96f, 47.70f);
	cube[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[156].scale = D3DXVECTOR3(3, 1, 10);

	cube[157].position = D3DXVECTOR3(-90.58f, -45.36f, 38.10f);
	cube[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[157].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[158].position = D3DXVECTOR3(-93.16f, -44.30f, 38.34f);
	cube[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[158].scale = D3DXVECTOR3(3, 1, 10);

	cube[159].position = D3DXVECTOR3(-95.48f, -42.70f, 38.46f);
	cube[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[159].scale = D3DXVECTOR3(3, 1, 10);

	cube[160].position = D3DXVECTOR3(-91.51f, -47.04f, 29.47f);
	cube[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[160].scale = D3DXVECTOR3(3, 1, 10);

	cube[161].position = D3DXVECTOR3(-94.08f, -45.98f, 29.26f);
	cube[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[161].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[162].position = D3DXVECTOR3(-96.39f, -44.38f, 28.98f);
	cube[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[162].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[163].position = D3DXVECTOR3(-91.49f, -48.78f, 19.91f);
	cube[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[163].scale = D3DXVECTOR3(3, 1, 10);

	cube[164].position = D3DXVECTOR3(-94.06f, -47.72f, 19.70f);
	cube[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[164].scale = D3DXVECTOR3(3, 1, 10);

	cube[165].position = D3DXVECTOR3(-96.38f, -46.12f, 19.42f);
	cube[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[165].scale = D3DXVECTOR3(3, 1, 10);

	cube[166].position = D3DXVECTOR3(-91.49f, -50.53f, 10.35f);
	cube[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[166].scale = D3DXVECTOR3(3, 1, 10);

	cube[167].position = D3DXVECTOR3(-94.06f, -49.47f, 10.14f);
	cube[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[167].scale = D3DXVECTOR3(3, 1, 10);

	cube[168].position = D3DXVECTOR3(-96.38f, -47.87f, 9.86f);
	cube[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[168].scale = D3DXVECTOR3(3, 1, 10);

	cube[169].position = D3DXVECTOR3(-91.49f, -52.31f, 0.79f);
	cube[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[169].scale = D3DXVECTOR3(3, 1, 10);

	cube[170].position = D3DXVECTOR3(-94.06f, -51.25f, 0.58f);
	cube[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[170].scale = D3DXVECTOR3(3, 1, 10);

	cube[171].position = D3DXVECTOR3(-96.38f, -49.65f, 0.30f);
	cube[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[171].scale = D3DXVECTOR3(3, 1, 10);

	cube[172].position = D3DXVECTOR3(-91.49f, -54.09f, -8.86f);
	cube[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[172].scale = D3DXVECTOR3(3, 1, 10);

	cube[173].position = D3DXVECTOR3(-94.06f, -53.03f, -9.07f);
	cube[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[173].scale = D3DXVECTOR3(3, 1, 10);

	cube[174].position = D3DXVECTOR3(-96.38f, -51.43f, -9.35f);
	cube[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[174].scale = D3DXVECTOR3(3, 1, 10);

	cube[175].position = D3DXVECTOR3(-91.49f, -55.80f, -18.25f);
	cube[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[175].scale = D3DXVECTOR3(3, 1, 10);

	cube[176].position = D3DXVECTOR3(-94.06f, -54.74f, -18.46f);
	cube[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[176].scale = D3DXVECTOR3(3, 1, 10);

	cube[177].position = D3DXVECTOR3(-96.38f, -53.14f, -18.74f);
	cube[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[177].scale = D3DXVECTOR3(3, 1, 10);

	cube[178].position = D3DXVECTOR3(-91.51f, -57.27f, -26.69f);
	cube[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[178].scale = D3DXVECTOR3(3, 1, 10);

	cube[179].position = D3DXVECTOR3(-94.08f, -56.21f, -26.90f);
	cube[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[179].scale = D3DXVECTOR3(3, 1, 10);

	cube[180].position = D3DXVECTOR3(-96.40f, -54.61f, -27.18f);
	cube[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[180].scale = D3DXVECTOR3(3, 1, 10);

	cube[181].position = D3DXVECTOR3(-91.51f, -58.99f, -36.39f);
	cube[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[181].scale = D3DXVECTOR3(3, 1, 10);

	cube[182].position = D3DXVECTOR3(-94.08f, -57.93f, -36.60f);
	cube[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[182].scale = D3DXVECTOR3(3, 1, 10);

	cube[183].position = D3DXVECTOR3(-96.40f, -56.33f, -36.88f);
	cube[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[183].scale = D3DXVECTOR3(3, 1, 10);

	cube[184].position = D3DXVECTOR3(-91.49f, -60.74f, -45.69f);
	cube[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[184].scale = D3DXVECTOR3(3, 1, 10);

	cube[185].position = D3DXVECTOR3(-94.06f, -59.68f, -45.90f);
	cube[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[185].scale = D3DXVECTOR3(3, 1, 10);

	cube[186].position = D3DXVECTOR3(-96.38f, -58.08f, -46.18f);
	cube[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[186].scale = D3DXVECTOR3(3, 1, 10);

	cube[187].position = D3DXVECTOR3(-91.49f, -62.52f, -55.06f);
	cube[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[187].scale = D3DXVECTOR3(3, 1, 10);

	cube[188].position = D3DXVECTOR3(-94.06f, -61.46f, -55.27f);
	cube[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[188].scale = D3DXVECTOR3(3, 1, 10);

	cube[189].position = D3DXVECTOR3(-96.38f, -59.86f, -55.55f);
	cube[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[189].scale = D3DXVECTOR3(3, 1, 10);

	cube[190].position = D3DXVECTOR3(-91.49f, -64.27f, -64.57f);
	cube[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[190].scale = D3DXVECTOR3(3, 1, 10);

	cube[191].position = D3DXVECTOR3(-94.06f, -63.21f, -64.78f);
	cube[191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[191].scale = D3DXVECTOR3(3, 1, 10);

	cube[192].position = D3DXVECTOR3(-96.38f, -61.61f, -65.06f);
	cube[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[192].scale = D3DXVECTOR3(3, 1, 10);

	cube[193].position = D3DXVECTOR3(-91.49f, -65.99f, -73.60f);
	cube[193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[193].scale = D3DXVECTOR3(3, 1, 10);

	cube[194].position = D3DXVECTOR3(-94.06f, -64.93f, -73.81f);
	cube[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[194].scale = D3DXVECTOR3(3, 1, 10);

	cube[195].position = D3DXVECTOR3(-96.38f, -63.33f, -74.09f);
	cube[195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[195].scale = D3DXVECTOR3(3, 1, 10);

	cube[196].position = D3DXVECTOR3(-91.49f, -67.71f, -83.66f);
	cube[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[196].scale = D3DXVECTOR3(3, 1, 10);

	cube[197].position = D3DXVECTOR3(-94.06f, -66.65f, -83.87f);
	cube[197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[197].scale = D3DXVECTOR3(3, 1, 10);

	cube[198].position = D3DXVECTOR3(-96.38f, -65.05f, -84.15f);
	cube[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[198].scale = D3DXVECTOR3(3, 1, 10);

	cube[199].position = D3DXVECTOR3(-91.49f, -69.13f, -90.95f);
	cube[199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[199].scale = D3DXVECTOR3(3, 1, 10);

	cube[200].position = D3DXVECTOR3(-94.06f, -68.07f, -91.16f);
	cube[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[200].scale = D3DXVECTOR3(3, 1, 10);

	cube[201].position = D3DXVECTOR3(-96.38f, -66.47f, -91.44f);
	cube[201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[201].scale = D3DXVECTOR3(3, 1, 10);

	cube[202].position = D3DXVECTOR3(-91.12f, -70.78f, -98.66f);
	cube[202].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[202].scale = D3DXVECTOR3(3, 1, 10);

	cube[203].position = D3DXVECTOR3(-93.61f, -69.72f, -99.31f);
	cube[203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[203].scale = D3DXVECTOR3(3, 1, 10);

	cube[204].position = D3DXVECTOR3(-95.85f, -68.12f, -99.99f);
	cube[204].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[204].scale = D3DXVECTOR3(3, 1, 10);

	cube[205].position = D3DXVECTOR3(-89.29f, -72.39f, -106.26f);
	cube[205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[205].scale = D3DXVECTOR3(3, 1, 10);

	cube[206].position = D3DXVECTOR3(-91.64f, -71.33f, -107.34f);
	cube[206].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[206].scale = D3DXVECTOR3(3, 1, 10);

	cube[207].position = D3DXVECTOR3(-93.72f, -69.73f, -108.39f);
	cube[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[207].scale = D3DXVECTOR3(3, 1, 10);

	cube[208].position = D3DXVECTOR3(-86.14f, -74.09f, -113.56f);
	cube[208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[208].scale = D3DXVECTOR3(3, 1, 10);

	cube[209].position = D3DXVECTOR3(-88.26f, -73.03f, -115.03f);
	cube[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[209].scale = D3DXVECTOR3(3, 1, 10);

	cube[210].position = D3DXVECTOR3(-90.13f, -71.43f, -116.43f);
	cube[210].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[210].scale = D3DXVECTOR3(3, 1, 10);

	cube[211].position = D3DXVECTOR3(-82.16f, -75.57f, -119.70f);
	cube[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[211].scale = D3DXVECTOR3(3, 1, 10);

	cube[212].position = D3DXVECTOR3(-83.99f, -74.51f, -121.51f);
	cube[212].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[212].scale = D3DXVECTOR3(3, 1, 10);

	cube[213].position = D3DXVECTOR3(-85.59f, -72.91f, -123.22f);
	cube[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[213].scale = D3DXVECTOR3(3, 1, 10);

	cube[214].position = D3DXVECTOR3(-76.93f, -77.19f, -125.29f);
	cube[214].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[214].scale = D3DXVECTOR3(3, 1, 10);

	cube[215].position = D3DXVECTOR3(-78.42f, -76.13f, -127.40f);
	cube[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[215].scale = D3DXVECTOR3(3, 1, 10);

	cube[216].position = D3DXVECTOR3(-79.69f, -74.53f, -129.35f);
	cube[216].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[216].scale = D3DXVECTOR3(3, 1, 10);

	cube[217].position = D3DXVECTOR3(-71.27f, -78.65f, -129.62f);
	cube[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[217].scale = D3DXVECTOR3(3, 1, 10);

	cube[218].position = D3DXVECTOR3(-72.37f, -77.59f, -131.95f);
	cube[218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[218].scale = D3DXVECTOR3(3, 1, 10);

	cube[219].position = D3DXVECTOR3(-73.29f, -75.99f, -134.10f);
	cube[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[219].scale = D3DXVECTOR3(3, 1, 10);

	cube[220].position = D3DXVECTOR3(-64.33f, -80.30f, -133.09f);
	cube[220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[220].scale = D3DXVECTOR3(3, 1, 10);

	cube[221].position = D3DXVECTOR3(-65.01f, -79.24f, -135.58f);
	cube[221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[221].scale = D3DXVECTOR3(3, 1, 10);

	cube[222].position = D3DXVECTOR3(-65.54f, -77.64f, -137.86f);
	cube[222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[222].scale = D3DXVECTOR3(3, 1, 10);

	cube[223].position = D3DXVECTOR3(-55.94f, -82.04f, -135.49f);
	cube[223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[223].scale = D3DXVECTOR3(3, 1, 10);

	cube[224].position = D3DXVECTOR3(-56.18f, -80.98f, -138.06f);
	cube[224].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[224].scale = D3DXVECTOR3(3, 1, 10);

	cube[225].position = D3DXVECTOR3(-56.30f, -79.38f, -140.38f);
	cube[225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[225].scale = D3DXVECTOR3(3, 1, 10);

	cube[226].position = D3DXVECTOR3(-47.31f, -83.72f, -136.41f);
	cube[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[226].scale = D3DXVECTOR3(3, 1, 10);

	cube[227].position = D3DXVECTOR3(-47.10f, -82.66f, -138.98f);
	cube[227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[227].scale = D3DXVECTOR3(3, 1, 10);

	cube[228].position = D3DXVECTOR3(-46.82f, -81.06f, -141.29f);
	cube[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[228].scale = D3DXVECTOR3(3, 1, 10);

	cube[229].position = D3DXVECTOR3(-38.11f, -85.43f, -136.43f);
	cube[229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[229].scale = D3DXVECTOR3(3, 1, 10);

	cube[230].position = D3DXVECTOR3(-37.90f, -84.37f, -139.00f);
	cube[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[230].scale = D3DXVECTOR3(3, 1, 10);

	cube[231].position = D3DXVECTOR3(-37.62f, -82.77f, -141.32f);
	cube[231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[231].scale = D3DXVECTOR3(3, 1, 10);

	cube[232].position = D3DXVECTOR3(-30.40f, -87.08f, -136.06f);
	cube[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[232].scale = D3DXVECTOR3(3, 1, 10);

	cube[233].position = D3DXVECTOR3(-29.75f, -86.02f, -138.55f);
	cube[233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[233].scale = D3DXVECTOR3(3, 1, 10);

	cube[234].position = D3DXVECTOR3(-29.07f, -84.42f, -140.79f);
	cube[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[234].scale = D3DXVECTOR3(3, 1, 10);

	cube[235].position = D3DXVECTOR3(-22.80f, -88.69f, -134.23f);
	cube[235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[235].scale = D3DXVECTOR3(3, 1, 10);

	cube[236].position = D3DXVECTOR3(-21.72f, -87.63f, -136.58f);
	cube[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[236].scale = D3DXVECTOR3(3, 1, 10);

	cube[237].position = D3DXVECTOR3(-20.67f, -86.03f, -138.66f);
	cube[237].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[237].scale = D3DXVECTOR3(3, 1, 10);

	cube[238].position = D3DXVECTOR3(-15.50f, -90.39f, -131.08f);
	cube[238].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[238].scale = D3DXVECTOR3(3, 1, 10);

	cube[239].position = D3DXVECTOR3(-14.03f, -89.33f, -133.20f);
	cube[239].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[239].scale = D3DXVECTOR3(3, 1, 10);

	cube[240].position = D3DXVECTOR3(-12.63f, -87.73f, -135.07f);
	cube[240].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[240].scale = D3DXVECTOR3(3, 1, 10);

	cube[241].position = D3DXVECTOR3(-9.36f, -91.87f, -127.10f);
	cube[241].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[241].scale = D3DXVECTOR3(3, 1, 10);

	cube[242].position = D3DXVECTOR3(-7.55f, -90.81f, -128.93f);
	cube[242].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[242].scale = D3DXVECTOR3(3, 1, 10);

	cube[243].position = D3DXVECTOR3(-5.84f, -89.21f, -130.53f);
	cube[243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[243].scale = D3DXVECTOR3(3, 1, 10);

	cube[244].position = D3DXVECTOR3(-3.77f, -93.49f, -121.87f);
	cube[244].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[244].scale = D3DXVECTOR3(3, 1, 10);

	cube[245].position = D3DXVECTOR3(-1.66f, -92.43f, -123.36f);
	cube[245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[245].scale = D3DXVECTOR3(3, 1, 10);

	cube[246].position = D3DXVECTOR3(0.29f, -90.83f, -124.63f);
	cube[246].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[246].scale = D3DXVECTOR3(3, 1, 10);

	cube[247].position = D3DXVECTOR3(0.56f, -94.95f, -116.21f);
	cube[247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[247].scale = D3DXVECTOR3(3, 1, 10);

	cube[248].position = D3DXVECTOR3(2.89f, -93.89f, -117.31f);
	cube[248].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[248].scale = D3DXVECTOR3(3, 1, 10);

	cube[249].position = D3DXVECTOR3(5.04f, -92.29f, -118.23f);
	cube[249].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[249].scale = D3DXVECTOR3(3, 1, 10);

	cube[250].position = D3DXVECTOR3(4.03f, -96.60f, -109.27f);
	cube[250].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[250].scale = D3DXVECTOR3(3, 1, 10);

	cube[251].position = D3DXVECTOR3(6.52f, -95.54f, -109.95f);
	cube[251].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[251].scale = D3DXVECTOR3(3, 1, 10);

	cube[252].position = D3DXVECTOR3(8.80f, -93.94f, -110.48f);
	cube[252].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[252].scale = D3DXVECTOR3(3, 1, 10);

	cube[253].position = D3DXVECTOR3(6.42f, -98.34f, -100.88f);
	cube[253].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[253].scale = D3DXVECTOR3(3, 1, 10);

	cube[254].position = D3DXVECTOR3(9.00f, -97.28f, -101.12f);
	cube[254].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[254].scale = D3DXVECTOR3(3, 1, 10);

	cube[255].position = D3DXVECTOR3(11.32f, -95.68f, -101.24f);
	cube[255].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[255].scale = D3DXVECTOR3(3, 1, 10);

	cube[256].position = D3DXVECTOR3(7.35f, -100.02f, -92.25f);
	cube[256].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[256].scale = D3DXVECTOR3(3, 1, 10);

	cube[257].position = D3DXVECTOR3(9.92f, -98.96f, -92.04f);
	cube[257].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[257].scale = D3DXVECTOR3(3, 1, 10);

	cube[258].position = D3DXVECTOR3(12.23f, -97.36f, -91.76f);
	cube[258].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[258].scale = D3DXVECTOR3(3, 1, 10);

	cube[259].position = D3DXVECTOR3(7.29f, -101.68f, -83.21f);
	cube[259].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[259].scale = D3DXVECTOR3(3, 1, 10);

	cube[260].position = D3DXVECTOR3(9.86f, -100.62f, -83.00f);
	cube[260].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[260].scale = D3DXVECTOR3(3, 1, 10);

	cube[261].position = D3DXVECTOR3(12.18f, -99.02f, -82.72f);
	cube[261].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[261].scale = D3DXVECTOR3(3, 1, 10);

	cube[262].position = D3DXVECTOR3(7.29f, -103.42f, -73.71f);
	cube[262].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[262].scale = D3DXVECTOR3(3, 1, 10);

	cube[263].position = D3DXVECTOR3(9.86f, -102.36f, -73.50f);
	cube[263].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[263].scale = D3DXVECTOR3(3, 1, 10);

	cube[264].position = D3DXVECTOR3(12.18f, -100.76f, -73.22f);
	cube[264].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[264].scale = D3DXVECTOR3(3, 1, 10);

	cube[265].position = D3DXVECTOR3(7.29f, -105.15f, -64.51f);
	cube[265].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 15.00f*3.141592f / 180);
	cube[265].scale = D3DXVECTOR3(3, 1, 10);

	cube[266].position = D3DXVECTOR3(9.86f, -104.09f, -64.30f);
	cube[266].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[266].scale = D3DXVECTOR3(3, 1, 10);

	cube[267].position = D3DXVECTOR3(12.18f, -102.49f, -64.02f);
	cube[267].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 40.00f*3.141592f / 180);
	cube[267].scale = D3DXVECTOR3(3, 1, 10);

	cube[268].position = D3DXVECTOR3(-4.94f, -11.50f, 0.40f);
	cube[268].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[268].scale = D3DXVECTOR3(3, 1, 10);

	cube[269].position = D3DXVECTOR3(-7.56f, -10.44f, 0.58f);
	cube[269].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[269].scale = D3DXVECTOR3(3, 1, 10);

	cube[270].position = D3DXVECTOR3(-10.01f, -8.72f, 0.88f);
	cube[270].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[270].scale = D3DXVECTOR3(3, 1, 10);

	cube[271].position = D3DXVECTOR3(-4.94f, -13.26f, 10.07f);
	cube[271].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[271].scale = D3DXVECTOR3(3, 1, 10);

	cube[272].position = D3DXVECTOR3(-7.56f, -12.20f, 10.25f);
	cube[272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[272].scale = D3DXVECTOR3(3, 1, 10);

	cube[273].position = D3DXVECTOR3(-10.01f, -10.48f, 10.55f);
	cube[273].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[273].scale = D3DXVECTOR3(3, 1, 10);

	cube[274].position = D3DXVECTOR3(-4.94f, -14.93f, 19.08f);
	cube[274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[274].scale = D3DXVECTOR3(3, 1, 10);

	cube[275].position = D3DXVECTOR3(-7.56f, -13.87f, 19.26f);
	cube[275].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[275].scale = D3DXVECTOR3(3, 1, 10);

	cube[276].position = D3DXVECTOR3(-10.01f, -12.15f, 19.56f);
	cube[276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[276].scale = D3DXVECTOR3(3, 1, 10);

	cube[277].position = D3DXVECTOR3(-4.86f, -16.55f, 28.07f);
	cube[277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[277].scale = D3DXVECTOR3(3, 1, 10);

	cube[278].position = D3DXVECTOR3(-7.48f, -15.48f, 28.26f);
	cube[278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[278].scale = D3DXVECTOR3(3, 1, 10);

	cube[279].position = D3DXVECTOR3(-9.93f, -13.77f, 28.55f);
	cube[279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[279].scale = D3DXVECTOR3(3, 1, 10);

	cube[280].position = D3DXVECTOR3(-6.07f, -17.99f, 35.73f);
	cube[280].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[280].scale = D3DXVECTOR3(3, 1, 6);

	cube[281].position = D3DXVECTOR3(-5.06f, -18.17f, 34.15f);
	cube[281].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[281].scale = D3DXVECTOR3(3, 1, 10);

	cube[282].position = D3DXVECTOR3(-8.19f, -17.07f, 35.74f);
	cube[282].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[282].scale = D3DXVECTOR3(3, 1, 6);

	cube[283].position = D3DXVECTOR3(-7.67f, -17.09f, 33.88f);
	cube[283].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[283].scale = D3DXVECTOR3(3, 1, 10);

	cube[284].position = D3DXVECTOR3(-10.03f, -15.81f, 35.81f);
	cube[284].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[284].scale = D3DXVECTOR3(4, 1, 5.5);

	cube[285].position = D3DXVECTOR3(-10.14f, -15.39f, 33.74f);
	cube[285].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[285].scale = D3DXVECTOR3(4, 1, 10);

	cube[286].position = D3DXVECTOR3(-6.93f, -19.87f, 41.69f);
	cube[286].rotation = D3DXVECTOR3(14.80f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[286].scale = D3DXVECTOR3(3, 1, 6.5);

	cube[287].position = D3DXVECTOR3(-6.48f, -19.81f, 40.15f);
	cube[287].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[287].scale = D3DXVECTOR3(3, 1, 10);

	cube[288].position = D3DXVECTOR3(-9.34f, -18.87f, 41.04f);
	cube[288].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[288].scale = D3DXVECTOR3(3, 1, 6);

	cube[289].position = D3DXVECTOR3(-9.01f, -18.74f, 39.43f);
	cube[289].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[289].scale = D3DXVECTOR3(3, 1, 10);

	cube[290].position = D3DXVECTOR3(-11.73f, -17.20f, 40.61f);
	cube[290].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[290].scale = D3DXVECTOR3(4, 1, 6);

	cube[291].position = D3DXVECTOR3(-11.41f, -17.03f, 38.86f);
	cube[291].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[291].scale = D3DXVECTOR3(4, 1, 10);

	cube[292].position = D3DXVECTOR3(-9.74f, -21.48f, 47.25f);
	cube[292].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[292].scale = D3DXVECTOR3(3, 1, 6.5);

	cube[293].position = D3DXVECTOR3(-8.94f, -21.51f, 45.95f);
	cube[293].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[293].scale = D3DXVECTOR3(3, 1, 10);

	cube[294].position = D3DXVECTOR3(-12.02f, -20.44f, 46.23f);
	cube[294].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[294].scale = D3DXVECTOR3(3, 1, 6.2);

	cube[295].position = D3DXVECTOR3(-11.31f, -20.44f, 44.80f);
	cube[295].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[295].scale = D3DXVECTOR3(3, 1, 10);

	cube[296].position = D3DXVECTOR3(-14.35f, -18.80f, 45.50f);
	cube[296].rotation = D3DXVECTOR3(17.70f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[296].scale = D3DXVECTOR3(4, 1, 6);

	cube[297].position = D3DXVECTOR3(-13.57f, -18.73f, 43.83f);
	cube[297].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[297].scale = D3DXVECTOR3(4, 1, 10);

	cube[298].position = D3DXVECTOR3(-13.18f, -23.12f, 52.36f);
	cube[298].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[298].scale = D3DXVECTOR3(3, 1, 5.7);

	cube[299].position = D3DXVECTOR3(-11.97f, -22.99f, 50.75f);
	cube[299].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[299].scale = D3DXVECTOR3(3, 1, 10);

	cube[300].position = D3DXVECTOR3(-15.31f, -22.16f, 50.97f);
	cube[300].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[300].scale = D3DXVECTOR3(3, 1, 5.5);

	cube[301].position = D3DXVECTOR3(-14.11f, -21.92f, 49.20f);
	cube[301].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[301].scale = D3DXVECTOR3(3, 1, 10);

	cube[302].position = D3DXVECTOR3(-17.30f, -20.50f, 49.64f);
	cube[302].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[302].scale = D3DXVECTOR3(4, 1, 5.5);

	cube[303].position = D3DXVECTOR3(-16.17f, -20.21f, 47.85f);
	cube[303].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[303].scale = D3DXVECTOR3(4, 1, 10);

	cube[304].position = D3DXVECTOR3(-17.39f, -24.69f, 56.46f);
	cube[304].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[304].scale = D3DXVECTOR3(3, 1, 6.5);

	cube[305].position = D3DXVECTOR3(-16.04f, -24.61f, 55.18f);
	cube[305].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[305].scale = D3DXVECTOR3(3, 1, 10);

	cube[306].position = D3DXVECTOR3(-19.30f, -23.64f, 54.59f);
	cube[306].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[306].scale = D3DXVECTOR3(3, 1, 6);

	cube[307].position = D3DXVECTOR3(-17.98f, -23.57f, 53.38f);
	cube[307].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[307].scale = D3DXVECTOR3(3, 1, 10);

	cube[308].position = D3DXVECTOR3(-21.11f, -22.00f, 53.06f);
	cube[308].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[308].scale = D3DXVECTOR3(4, 1, 5.5);

	cube[309].position = D3DXVECTOR3(-19.67f, -21.83f, 51.60f);
	cube[309].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[309].scale = D3DXVECTOR3(4, 1, 10);

	cube[310].position = D3DXVECTOR3(-21.94f, -26.20f, 59.62f);
	cube[310].rotation = D3DXVECTOR3(15.10f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[310].scale = D3DXVECTOR3(3, 1, 5.5);

	cube[311].position = D3DXVECTOR3(-20.35f, -26.07f, 58.56f);
	cube[311].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[311].scale = D3DXVECTOR3(3, 1, 10);

	cube[312].position = D3DXVECTOR3(-23.30f, -25.30f, 57.63f);
	cube[312].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.60f*3.141592f / 180);
	cube[312].scale = D3DXVECTOR3(3, 1, 5);

	cube[313].position = D3DXVECTOR3(-21.82f, -25.00f, 56.38f);
	cube[313].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[313].scale = D3DXVECTOR3(3, 1, 10);

	cube[314].position = D3DXVECTOR3(-25.06f, -23.62f, 55.80f);
	cube[314].rotation = D3DXVECTOR3(16.90f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[314].scale = D3DXVECTOR3(4, 1, 5);

	cube[315].position = D3DXVECTOR3(-23.30f, -23.29f, 54.41f);
	cube[315].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[315].scale = D3DXVECTOR3(4, 1, 10);

	cube[316].position = D3DXVECTOR3(-27.75f, -27.55f, 61.31f);
	cube[316].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[316].scale = D3DXVECTOR3(3, 1, 6.3);

	cube[317].position = D3DXVECTOR3(-25.80f, -27.72f, 61.34f);
	cube[317].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[317].scale = D3DXVECTOR3(3, 1, 10);

	cube[318].position = D3DXVECTOR3(-28.54f, -26.57f, 59.44f);
	cube[318].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (289.50f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[318].scale = D3DXVECTOR3(3, 1, 6.2);

	cube[319].position = D3DXVECTOR3(-26.87f, -26.65f, 58.94f);
	cube[319].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[319].scale = D3DXVECTOR3(3, 1, 10);

	cube[320].position = D3DXVECTOR3(-29.48f, -25.30f, 57.87f);
	cube[320].rotation = D3DXVECTOR3(18.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 318.00f*3.141592f / 180);
	cube[320].scale = D3DXVECTOR3(4, 1, 6);

	cube[321].position = D3DXVECTOR3(-27.98f, -24.94f, 56.74f);
	cube[321].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[321].scale = D3DXVECTOR3(4, 1, 10);

	cube[322].position = D3DXVECTOR3(-33.93f, -29.22f, 62.79f);
	cube[322].rotation = D3DXVECTOR3(13.70f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[322].scale = D3DXVECTOR3(3, 1, 7.5);

	cube[323].position = D3DXVECTOR3(-32.59f, -29.46f, 63.31f);
	cube[323].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[323].scale = D3DXVECTOR3(3, 1, 10);

	cube[324].position = D3DXVECTOR3(-34.58f, -28.46f, 61.22f);
	cube[324].rotation = D3DXVECTOR3(14.70f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[324].scale = D3DXVECTOR3(3, 1, 7);

	cube[325].position = D3DXVECTOR3(-33.23f, -28.39f, 60.76f);
	cube[325].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[325].scale = D3DXVECTOR3(3, 1, 10);

	cube[326].position = D3DXVECTOR3(-33.94f, -26.70f, 58.42f);
	cube[326].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[326].scale = D3DXVECTOR3(4, 1, 10);

	cube[327].position = D3DXVECTOR3(-35.39f, -26.70f, 58.80f);
	cube[327].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[327].scale = D3DXVECTOR3(4, 1, 6.7);

	cube[328].position = D3DXVECTOR3(-40.77f, -31.17f, 64.16f);
	cube[328].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[328].scale = D3DXVECTOR3(3, 1, 7);

	cube[329].position = D3DXVECTOR3(-39.58f, -31.14f, 64.09f);
	cube[329].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[329].scale = D3DXVECTOR3(3, 1, 10);

	cube[330].position = D3DXVECTOR3(-41.07f, -30.14f, 61.60f);
	cube[330].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[330].scale = D3DXVECTOR3(3, 1, 7);

	cube[331].position = D3DXVECTOR3(-39.77f, -30.07f, 61.46f);
	cube[331].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[331].scale = D3DXVECTOR3(3, 1, 10);

	cube[332].position = D3DXVECTOR3(-41.63f, -28.66f, 59.43f);
	cube[332].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[332].scale = D3DXVECTOR3(4, 1, 6.5);

	cube[333].position = D3DXVECTOR3(-40.06f, -28.36f, 59.02f);
	cube[333].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[333].scale = D3DXVECTOR3(4, 1, 10);

	cube[334].position = D3DXVECTOR3(-46.04f, -32.46f, 64.20f);
	cube[334].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[334].scale = D3DXVECTOR3(3, 1, 10);

	cube[335].position = D3DXVECTOR3(-46.23f, -31.40f, 61.58f);
	cube[335].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[335].scale = D3DXVECTOR3(3, 1, 10);

	cube[336].position = D3DXVECTOR3(-46.52f, -29.68f, 59.13f);
	cube[336].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[336].scale = D3DXVECTOR3(3, 1, 10);

	cube[337].position = D3DXVECTOR3(-53.70f, -33.90f, 62.99f);
	cube[337].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[337].scale = D3DXVECTOR3(3, 1, 6);

	cube[338].position = D3DXVECTOR3(-52.12f, -34.08f, 64.00f);
	cube[338].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[338].scale = D3DXVECTOR3(3, 1, 10);

	cube[339].position = D3DXVECTOR3(-53.71f, -32.98f, 60.87f);
	cube[339].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[339].scale = D3DXVECTOR3(3, 1, 6);

	cube[340].position = D3DXVECTOR3(-51.86f, -33.00f, 61.39f);
	cube[340].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[340].scale = D3DXVECTOR3(3, 1, 10);

	cube[341].position = D3DXVECTOR3(-53.78f, -31.72f, 59.03f);
	cube[341].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[341].scale = D3DXVECTOR3(4, 1, 5.500004);

	cube[342].position = D3DXVECTOR3(-51.71f, -31.30f, 58.92f);
	cube[342].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[342].scale = D3DXVECTOR3(4, 1, 10);

	cube[343].position = D3DXVECTOR3(-59.66f, -35.78f, 62.13f);
	cube[343].rotation = D3DXVECTOR3(14.80f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[343].scale = D3DXVECTOR3(3, 1, 6.500002);

	cube[344].position = D3DXVECTOR3(-58.12f, -35.72f, 62.58f);
	cube[344].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[344].scale = D3DXVECTOR3(3, 1, 10);

	cube[345].position = D3DXVECTOR3(-59.01f, -34.78f, 59.72f);
	cube[345].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[345].scale = D3DXVECTOR3(3, 1, 6);

	cube[346].position = D3DXVECTOR3(-57.40f, -34.66f, 60.05f);
	cube[346].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[346].scale = D3DXVECTOR3(3, 1, 10);

	cube[347].position = D3DXVECTOR3(-58.58f, -33.11f, 57.33f);
	cube[347].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[347].scale = D3DXVECTOR3(4, 1, 6);

	cube[348].position = D3DXVECTOR3(-56.83f, -32.94f, 57.65f);
	cube[348].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (250.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[348].scale = D3DXVECTOR3(4, 1, 10.00002);

	cube[349].position = D3DXVECTOR3(-65.22f, -37.39f, 59.32f);
	cube[349].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[349].scale = D3DXVECTOR3(3, 1, 6.500009);

	cube[350].position = D3DXVECTOR3(-63.92f, -37.42f, 60.12f);
	cube[350].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[350].scale = D3DXVECTOR3(3, 1, 10);

	cube[351].position = D3DXVECTOR3(-64.20f, -36.35f, 57.04f);
	cube[351].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[351].scale = D3DXVECTOR3(3, 1, 6.200005);

	cube[352].position = D3DXVECTOR3(-62.78f, -36.36f, 57.75f);
	cube[352].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[352].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[353].position = D3DXVECTOR3(-63.47f, -34.71f, 54.71f);
	cube[353].rotation = D3DXVECTOR3(17.70f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[353].scale = D3DXVECTOR3(4, 1, 6);

	cube[354].position = D3DXVECTOR3(-61.80f, -34.64f, 55.49f);
	cube[354].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (240.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[354].scale = D3DXVECTOR3(4, 1, 10);

	cube[355].position = D3DXVECTOR3(-70.33f, -39.03f, 55.88f);
	cube[355].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[355].scale = D3DXVECTOR3(3, 1, 5.700007);

	cube[356].position = D3DXVECTOR3(-68.72f, -38.90f, 57.09f);
	cube[356].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[356].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[357].position = D3DXVECTOR3(-68.94f, -38.07f, 53.75f);
	cube[357].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[357].scale = D3DXVECTOR3(3, 1, 5.500004);

	cube[358].position = D3DXVECTOR3(-67.18f, -37.84f, 54.95f);
	cube[358].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[358].scale = D3DXVECTOR3(3, 1, 10);

	cube[359].position = D3DXVECTOR3(-67.61f, -36.41f, 51.76f);
	cube[359].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[359].scale = D3DXVECTOR3(4, 1, 5.50001);

	cube[360].position = D3DXVECTOR3(-65.83f, -36.12f, 52.89f);
	cube[360].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (230.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[360].scale = D3DXVECTOR3(4, 1, 10);

	cube[361].position = D3DXVECTOR3(-74.43f, -40.60f, 51.67f);
	cube[361].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[361].scale = D3DXVECTOR3(3, 1, 6.500007);

	cube[362].position = D3DXVECTOR3(-73.15f, -40.52f, 53.02f);
	cube[362].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[362].scale = D3DXVECTOR3(3, 1, 10);

	cube[363].position = D3DXVECTOR3(-72.56f, -39.55f, 49.76f);
	cube[363].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[363].scale = D3DXVECTOR3(3, 1, 6);

	cube[364].position = D3DXVECTOR3(-71.35f, -39.48f, 51.08f);
	cube[364].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[364].scale = D3DXVECTOR3(3, 1, 10);

	cube[365].position = D3DXVECTOR3(-71.03f, -37.91f, 47.95f);
	cube[365].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[365].scale = D3DXVECTOR3(4, 1, 5.500006);

	cube[366].position = D3DXVECTOR3(-69.57f, -37.74f, 49.39f);
	cube[366].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (220.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[366].scale = D3DXVECTOR3(4, 1, 10);

	cube[367].position = D3DXVECTOR3(-77.59f, -42.11f, 47.12f);
	cube[367].rotation = D3DXVECTOR3(15.10f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[367].scale = D3DXVECTOR3(3, 1, 5.500002);

	cube[368].position = D3DXVECTOR3(-76.53f, -41.98f, 48.71f);
	cube[368].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[368].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[369].position = D3DXVECTOR3(-75.60f, -41.21f, 45.76f);
	cube[369].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 330.60f*3.141592f / 180);
	cube[369].scale = D3DXVECTOR3(3, 1, 5);

	cube[370].position = D3DXVECTOR3(-74.36f, -40.92f, 47.24f);
	cube[370].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[370].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[371].position = D3DXVECTOR3(-73.77f, -39.53f, 44.00f);
	cube[371].rotation = D3DXVECTOR3(16.90f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[371].scale = D3DXVECTOR3(4, 1, 5);

	cube[372].position = D3DXVECTOR3(-72.38f, -39.20f, 45.76f);
	cube[372].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (210.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[372].scale = D3DXVECTOR3(4, 1, 10.00002);

	cube[373].position = D3DXVECTOR3(-79.28f, -43.46f, 41.31f);
	cube[373].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[373].scale = D3DXVECTOR3(3, 1, 6.300006);

	cube[374].position = D3DXVECTOR3(-79.31f, -43.63f, 43.26f);
	cube[374].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[374].scale = D3DXVECTOR3(3, 1, 10);

	cube[375].position = D3DXVECTOR3(-77.41f, -42.48f, 40.52f);
	cube[375].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (199.50f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[375].scale = D3DXVECTOR3(3, 1, 6.200009);

	cube[376].position = D3DXVECTOR3(-76.91f, -42.57f, 42.19f);
	cube[376].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[376].scale = D3DXVECTOR3(3, 1, 10);

	cube[377].position = D3DXVECTOR3(-75.84f, -41.21f, 39.58f);
	cube[377].rotation = D3DXVECTOR3(18.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 318.00f*3.141592f / 180);
	cube[377].scale = D3DXVECTOR3(4, 1, 6);

	cube[378].position = D3DXVECTOR3(-74.71f, -40.85f, 41.08f);
	cube[378].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (200.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[378].scale = D3DXVECTOR3(4, 1, 10);

	cube[379].position = D3DXVECTOR3(-80.76f, -45.13f, 35.13f);
	cube[379].rotation = D3DXVECTOR3(13.70f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[379].scale = D3DXVECTOR3(3, 1, 7.500009);

	cube[380].position = D3DXVECTOR3(-81.28f, -45.37f, 36.47f);
	cube[380].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[380].scale = D3DXVECTOR3(3, 1, 10);

	cube[381].position = D3DXVECTOR3(-79.19f, -44.37f, 34.48f);
	cube[381].rotation = D3DXVECTOR3(14.70f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[381].scale = D3DXVECTOR3(3, 1, 7);

	cube[382].position = D3DXVECTOR3(-78.73f, -44.31f, 35.83f);
	cube[382].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[382].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[383].position = D3DXVECTOR3(-76.39f, -42.61f, 35.12f);
	cube[383].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[383].scale = D3DXVECTOR3(4, 1, 10);

	cube[384].position = D3DXVECTOR3(-76.77f, -42.61f, 33.67f);
	cube[384].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (190.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[384].scale = D3DXVECTOR3(4, 1, 6.700014);

	cube[385].position = D3DXVECTOR3(-82.13f, -47.08f, 28.29f);
	cube[385].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[385].scale = D3DXVECTOR3(3, 1, 7);

	cube[386].position = D3DXVECTOR3(-82.06f, -47.05f, 29.48f);
	cube[386].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[386].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[387].position = D3DXVECTOR3(-79.57f, -46.05f, 27.99f);
	cube[387].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[387].scale = D3DXVECTOR3(3, 1, 7);

	cube[388].position = D3DXVECTOR3(-79.43f, -45.99f, 29.29f);
	cube[388].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[388].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[389].position = D3DXVECTOR3(-77.40f, -44.57f, 27.43f);
	cube[389].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[389].scale = D3DXVECTOR3(4, 1, 6.500017);

	cube[390].position = D3DXVECTOR3(-76.99f, -44.27f, 29.00f);
	cube[390].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[390].scale = D3DXVECTOR3(4, 1, 10.00001);

	cube[391].position = D3DXVECTOR3(-82.04f, -48.79f, 19.92f);
	cube[391].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[391].scale = D3DXVECTOR3(3, 1, 10);

	cube[392].position = D3DXVECTOR3(-79.42f, -47.73f, 19.74f);
	cube[392].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[392].scale = D3DXVECTOR3(3, 1, 10);

	cube[393].position = D3DXVECTOR3(-76.97f, -46.01f, 19.44f);
	cube[393].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[393].scale = D3DXVECTOR3(3, 1, 10);

	cube[394].position = D3DXVECTOR3(-82.04f, -50.54f, 10.36f);
	cube[394].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[394].scale = D3DXVECTOR3(3, 1, 10);

	cube[395].position = D3DXVECTOR3(-79.42f, -49.48f, 10.18f);
	cube[395].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[395].scale = D3DXVECTOR3(3, 1, 10);

	cube[396].position = D3DXVECTOR3(-76.97f, -47.76f, 9.88f);
	cube[396].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[396].scale = D3DXVECTOR3(3, 1, 10);

	cube[397].position = D3DXVECTOR3(-82.04f, -52.32f, 0.80f);
	cube[397].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[397].scale = D3DXVECTOR3(3, 1, 10);

	cube[398].position = D3DXVECTOR3(-79.42f, -51.26f, 0.62f);
	cube[398].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[398].scale = D3DXVECTOR3(3, 1, 10);

	cube[399].position = D3DXVECTOR3(-76.97f, -49.54f, 0.32f);
	cube[399].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[399].scale = D3DXVECTOR3(3, 1, 10);

	cube[400].position = D3DXVECTOR3(-82.04f, -54.10f, -8.85f);
	cube[400].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[400].scale = D3DXVECTOR3(3, 1, 10);

	cube[401].position = D3DXVECTOR3(-79.42f, -53.04f, -9.03f);
	cube[401].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[401].scale = D3DXVECTOR3(3, 1, 10);

	cube[402].position = D3DXVECTOR3(-76.97f, -51.32f, -9.33f);
	cube[402].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[402].scale = D3DXVECTOR3(3, 1, 10);

	cube[403].position = D3DXVECTOR3(-82.04f, -55.81f, -18.24f);
	cube[403].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[403].scale = D3DXVECTOR3(3, 1, 10);

	cube[404].position = D3DXVECTOR3(-79.42f, -54.75f, -18.42f);
	cube[404].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[404].scale = D3DXVECTOR3(3, 1, 10);

	cube[405].position = D3DXVECTOR3(-76.97f, -53.03f, -18.72f);
	cube[405].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[405].scale = D3DXVECTOR3(3, 1, 10);

	cube[406].position = D3DXVECTOR3(-82.06f, -57.28f, -26.68f);
	cube[406].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[406].scale = D3DXVECTOR3(3, 1, 10);

	cube[407].position = D3DXVECTOR3(-79.44f, -56.22f, -26.86f);
	cube[407].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[407].scale = D3DXVECTOR3(3, 1, 10);

	cube[408].position = D3DXVECTOR3(-76.99f, -54.50f, -27.16f);
	cube[408].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[408].scale = D3DXVECTOR3(3, 1, 10);

	cube[409].position = D3DXVECTOR3(-82.06f, -59.00f, -36.38f);
	cube[409].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[409].scale = D3DXVECTOR3(3, 1, 10);

	cube[410].position = D3DXVECTOR3(-79.44f, -57.94f, -36.56f);
	cube[410].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[410].scale = D3DXVECTOR3(3, 1, 10);

	cube[411].position = D3DXVECTOR3(-76.99f, -56.22f, -36.86f);
	cube[411].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[411].scale = D3DXVECTOR3(3, 1, 10);

	cube[412].position = D3DXVECTOR3(-82.04f, -60.75f, -45.68f);
	cube[412].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[412].scale = D3DXVECTOR3(3, 1, 10);

	cube[413].position = D3DXVECTOR3(-79.42f, -59.69f, -45.86f);
	cube[413].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[413].scale = D3DXVECTOR3(3, 1, 10);

	cube[414].position = D3DXVECTOR3(-76.97f, -57.97f, -46.16f);
	cube[414].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[414].scale = D3DXVECTOR3(3, 1, 10);

	cube[415].position = D3DXVECTOR3(-82.04f, -62.53f, -55.05f);
	cube[415].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[415].scale = D3DXVECTOR3(3, 1, 10);

	cube[416].position = D3DXVECTOR3(-79.42f, -61.47f, -55.23f);
	cube[416].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[416].scale = D3DXVECTOR3(3, 1, 10);

	cube[417].position = D3DXVECTOR3(-76.97f, -59.75f, -55.53f);
	cube[417].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[417].scale = D3DXVECTOR3(3, 1, 10);

	cube[418].position = D3DXVECTOR3(-82.04f, -64.28f, -64.56f);
	cube[418].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[418].scale = D3DXVECTOR3(3, 1, 10);

	cube[419].position = D3DXVECTOR3(-79.42f, -63.22f, -64.74f);
	cube[419].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[419].scale = D3DXVECTOR3(3, 1, 10);

	cube[420].position = D3DXVECTOR3(-76.97f, -61.50f, -65.04f);
	cube[420].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[420].scale = D3DXVECTOR3(3, 1, 10);

	cube[421].position = D3DXVECTOR3(-82.04f, -66.00f, -73.59f);
	cube[421].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[421].scale = D3DXVECTOR3(3, 1, 10);

	cube[422].position = D3DXVECTOR3(-79.42f, -64.94f, -73.77f);
	cube[422].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[422].scale = D3DXVECTOR3(3, 1, 10);

	cube[423].position = D3DXVECTOR3(-76.97f, -63.22f, -74.07f);
	cube[423].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[423].scale = D3DXVECTOR3(3, 1, 10);

	cube[424].position = D3DXVECTOR3(-82.04f, -67.72f, -83.65f);
	cube[424].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[424].scale = D3DXVECTOR3(3, 1, 10);

	cube[425].position = D3DXVECTOR3(-79.42f, -66.65f, -83.84f);
	cube[425].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[425].scale = D3DXVECTOR3(3, 1, 10);

	cube[426].position = D3DXVECTOR3(-76.97f, -64.94f, -84.13f);
	cube[426].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[426].scale = D3DXVECTOR3(3, 1, 10);

	cube[427].position = D3DXVECTOR3(-82.04f, -69.14f, -90.94f);
	cube[427].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[427].scale = D3DXVECTOR3(3, 1, 10);

	cube[428].position = D3DXVECTOR3(-79.42f, -68.08f, -91.13f);
	cube[428].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[428].scale = D3DXVECTOR3(3, 1, 10);

	cube[429].position = D3DXVECTOR3(-76.97f, -66.36f, -91.42f);
	cube[429].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (180.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[429].scale = D3DXVECTOR3(3, 1, 10);

	cube[430].position = D3DXVECTOR3(-80.83f, -70.58f, -98.60f);
	cube[430].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[430].scale = D3DXVECTOR3(3, 1, 6);

	cube[431].position = D3DXVECTOR3(-81.84f, -70.76f, -97.02f);
	cube[431].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[431].scale = D3DXVECTOR3(3, 1, 10);

	cube[432].position = D3DXVECTOR3(-78.71f, -69.66f, -98.61f);
	cube[432].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[432].scale = D3DXVECTOR3(3, 1, 6);

	cube[433].position = D3DXVECTOR3(-79.23f, -69.68f, -96.76f);
	cube[433].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[433].scale = D3DXVECTOR3(3, 1, 10);

	cube[434].position = D3DXVECTOR3(-76.87f, -68.40f, -98.68f);
	cube[434].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[434].scale = D3DXVECTOR3(4, 1, 5.500003);

	cube[435].position = D3DXVECTOR3(-76.76f, -67.98f, -96.61f);
	cube[435].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (170.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[435].scale = D3DXVECTOR3(4, 1, 10);

	cube[436].position = D3DXVECTOR3(-79.97f, -72.46f, -104.56f);
	cube[436].rotation = D3DXVECTOR3(14.80f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[436].scale = D3DXVECTOR3(3, 1, 6.500002);

	cube[437].position = D3DXVECTOR3(-80.42f, -72.40f, -103.02f);
	cube[437].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[437].scale = D3DXVECTOR3(3, 1, 10);

	cube[438].position = D3DXVECTOR3(-77.56f, -71.46f, -103.91f);
	cube[438].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[438].scale = D3DXVECTOR3(3, 1, 6);

	cube[439].position = D3DXVECTOR3(-77.89f, -71.34f, -102.30f);
	cube[439].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[439].scale = D3DXVECTOR3(3, 1, 10);

	cube[440].position = D3DXVECTOR3(-75.17f, -69.79f, -103.48f);
	cube[440].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[440].scale = D3DXVECTOR3(4, 1, 6);

	cube[441].position = D3DXVECTOR3(-75.49f, -69.62f, -101.73f);
	cube[441].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (160.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[441].scale = D3DXVECTOR3(4, 1, 10);

	cube[442].position = D3DXVECTOR3(-77.16f, -74.07f, -110.12f);
	cube[442].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[442].scale = D3DXVECTOR3(3, 1, 6.500001);

	cube[443].position = D3DXVECTOR3(-77.96f, -74.10f, -108.83f);
	cube[443].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[443].scale = D3DXVECTOR3(3, 1, 10);

	cube[444].position = D3DXVECTOR3(-74.88f, -73.03f, -109.10f);
	cube[444].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[444].scale = D3DXVECTOR3(3, 1, 6.200004);

	cube[445].position = D3DXVECTOR3(-75.59f, -73.04f, -107.68f);
	cube[445].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[445].scale = D3DXVECTOR3(3, 1, 10);

	cube[446].position = D3DXVECTOR3(-72.55f, -71.39f, -108.37f);
	cube[446].rotation = D3DXVECTOR3(17.70f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[446].scale = D3DXVECTOR3(4, 1, 6);

	cube[447].position = D3DXVECTOR3(-73.33f, -71.32f, -106.70f);
	cube[447].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (150.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[447].scale = D3DXVECTOR3(4, 1, 10);

	cube[448].position = D3DXVECTOR3(-73.72f, -75.71f, -115.23f);
	cube[448].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[448].scale = D3DXVECTOR3(3, 1, 5.7);

	cube[449].position = D3DXVECTOR3(-74.93f, -75.58f, -113.62f);
	cube[449].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[449].scale = D3DXVECTOR3(3, 1, 10);

	cube[450].position = D3DXVECTOR3(-71.59f, -74.75f, -113.84f);
	cube[450].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[450].scale = D3DXVECTOR3(3, 1, 5.5);

	cube[451].position = D3DXVECTOR3(-72.79f, -74.52f, -112.08f);
	cube[451].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[451].scale = D3DXVECTOR3(3, 1, 10);

	cube[452].position = D3DXVECTOR3(-69.60f, -73.09f, -112.51f);
	cube[452].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[452].scale = D3DXVECTOR3(4, 1, 5.499999);

	cube[453].position = D3DXVECTOR3(-70.73f, -72.80f, -110.73f);
	cube[453].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (140.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[453].scale = D3DXVECTOR3(4, 1, 10);

	cube[454].position = D3DXVECTOR3(-69.51f, -77.28f, -119.33f);
	cube[454].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[454].scale = D3DXVECTOR3(3, 1, 6.499999);

	cube[455].position = D3DXVECTOR3(-70.86f, -77.20f, -118.05f);
	cube[455].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[455].scale = D3DXVECTOR3(3, 1, 10);

	cube[456].position = D3DXVECTOR3(-67.60f, -76.23f, -117.46f);
	cube[456].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[456].scale = D3DXVECTOR3(3, 1, 6);

	cube[457].position = D3DXVECTOR3(-68.92f, -76.16f, -116.25f);
	cube[457].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[457].scale = D3DXVECTOR3(3, 1, 10);

	cube[458].position = D3DXVECTOR3(-65.79f, -74.59f, -115.93f);
	cube[458].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[458].scale = D3DXVECTOR3(4, 1, 5.499998);

	cube[459].position = D3DXVECTOR3(-67.23f, -74.42f, -114.47f);
	cube[459].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (130.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[459].scale = D3DXVECTOR3(4, 1, 10);

	cube[460].position = D3DXVECTOR3(-64.96f, -78.79f, -122.49f);
	cube[460].rotation = D3DXVECTOR3(15.10f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[460].scale = D3DXVECTOR3(3, 1, 5.500002);

	cube[461].position = D3DXVECTOR3(-66.55f, -78.66f, -121.43f);
	cube[461].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[461].scale = D3DXVECTOR3(3, 1, 10);

	cube[462].position = D3DXVECTOR3(-63.60f, -77.89f, -120.50f);
	cube[462].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 330.60f*3.141592f / 180);
	cube[462].scale = D3DXVECTOR3(3, 1, 5);

	cube[463].position = D3DXVECTOR3(-65.08f, -77.60f, -119.26f);
	cube[463].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[463].scale = D3DXVECTOR3(3, 1, 10);

	cube[464].position = D3DXVECTOR3(-61.84f, -76.21f, -118.67f);
	cube[464].rotation = D3DXVECTOR3(16.90f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[464].scale = D3DXVECTOR3(4, 1, 5);

	cube[465].position = D3DXVECTOR3(-63.60f, -75.88f, -117.28f);
	cube[465].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (120.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[465].scale = D3DXVECTOR3(4, 1, 10);

	cube[466].position = D3DXVECTOR3(-59.15f, -80.14f, -124.18f);
	cube[466].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[466].scale = D3DXVECTOR3(3, 1, 6.300002);

	cube[467].position = D3DXVECTOR3(-61.10f, -80.31f, -124.21f);
	cube[467].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[467].scale = D3DXVECTOR3(3, 1, 10);

	cube[468].position = D3DXVECTOR3(-58.36f, -79.16f, -122.31f);
	cube[468].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (109.50f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[468].scale = D3DXVECTOR3(3, 1, 6.2);

	cube[469].position = D3DXVECTOR3(-60.03f, -79.25f, -121.81f);
	cube[469].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[469].scale = D3DXVECTOR3(3, 1, 10);

	cube[470].position = D3DXVECTOR3(-57.42f, -77.89f, -120.74f);
	cube[470].rotation = D3DXVECTOR3(18.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 318.00f*3.141592f / 180);
	cube[470].scale = D3DXVECTOR3(4, 1, 6);

	cube[471].position = D3DXVECTOR3(-58.92f, -77.53f, -119.61f);
	cube[471].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (110.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[471].scale = D3DXVECTOR3(4, 1, 10);

	cube[472].position = D3DXVECTOR3(-52.97f, -81.81f, -125.66f);
	cube[472].rotation = D3DXVECTOR3(13.70f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[472].scale = D3DXVECTOR3(3, 1, 7.500005);

	cube[473].position = D3DXVECTOR3(-54.31f, -82.05f, -126.18f);
	cube[473].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[473].scale = D3DXVECTOR3(3, 1, 10);

	cube[474].position = D3DXVECTOR3(-52.32f, -81.05f, -124.09f);
	cube[474].rotation = D3DXVECTOR3(14.70f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[474].scale = D3DXVECTOR3(3, 1, 7);

	cube[475].position = D3DXVECTOR3(-53.67f, -80.99f, -123.63f);
	cube[475].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[475].scale = D3DXVECTOR3(3, 1, 10);

	cube[476].position = D3DXVECTOR3(-52.96f, -79.29f, -121.29f);
	cube[476].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[476].scale = D3DXVECTOR3(4, 1, 10);

	cube[477].position = D3DXVECTOR3(-51.51f, -79.29f, -121.67f);
	cube[477].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (100.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[477].scale = D3DXVECTOR3(4, 1, 6.700002);

	cube[478].position = D3DXVECTOR3(-46.13f, -83.76f, -127.03f);
	cube[478].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[478].scale = D3DXVECTOR3(3, 1, 7);

	cube[479].position = D3DXVECTOR3(-47.32f, -83.73f, -126.96f);
	cube[479].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[479].scale = D3DXVECTOR3(3, 1, 10);

	cube[480].position = D3DXVECTOR3(-45.83f, -82.73f, -124.47f);
	cube[480].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[480].scale = D3DXVECTOR3(3, 1, 7);

	cube[481].position = D3DXVECTOR3(-47.13f, -82.67f, -124.33f);
	cube[481].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[481].scale = D3DXVECTOR3(3, 1, 10);

	cube[482].position = D3DXVECTOR3(-45.27f, -81.25f, -122.30f);
	cube[482].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[482].scale = D3DXVECTOR3(4, 1, 6.500002);

	cube[483].position = D3DXVECTOR3(-46.84f, -80.95f, -121.89f);
	cube[483].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[483].scale = D3DXVECTOR3(4, 1, 10);

	cube[484].position = D3DXVECTOR3(-38.12f, -85.44f, -126.98f);
	cube[484].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[484].scale = D3DXVECTOR3(3, 1, 10);

	cube[485].position = D3DXVECTOR3(-37.93f, -84.38f, -124.36f);
	cube[485].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[485].scale = D3DXVECTOR3(3, 1, 10);

	cube[486].position = D3DXVECTOR3(-37.64f, -82.66f, -121.91f);
	cube[486].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (90.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[486].scale = D3DXVECTOR3(3, 1, 10);

	cube[487].position = D3DXVECTOR3(-30.46f, -86.88f, -125.77f);
	cube[487].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[487].scale = D3DXVECTOR3(3, 1, 6);

	cube[488].position = D3DXVECTOR3(-32.04f, -87.06f, -126.78f);
	cube[488].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[488].scale = D3DXVECTOR3(3, 1, 10);

	cube[489].position = D3DXVECTOR3(-30.45f, -85.96f, -123.65f);
	cube[489].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[489].scale = D3DXVECTOR3(3, 1, 6);

	cube[490].position = D3DXVECTOR3(-32.30f, -85.98f, -124.17f);
	cube[490].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[490].scale = D3DXVECTOR3(3, 1, 10);

	cube[491].position = D3DXVECTOR3(-30.38f, -84.70f, -121.81f);
	cube[491].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[491].scale = D3DXVECTOR3(4, 1, 5.500002);

	cube[492].position = D3DXVECTOR3(-32.45f, -84.28f, -121.70f);
	cube[492].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (80.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[492].scale = D3DXVECTOR3(4, 1, 10);

	cube[493].position = D3DXVECTOR3(-24.50f, -88.76f, -124.91f);
	cube[493].rotation = D3DXVECTOR3(14.80f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[493].scale = D3DXVECTOR3(3, 1, 6.500003);

	cube[494].position = D3DXVECTOR3(-26.04f, -88.70f, -125.36f);
	cube[494].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[494].scale = D3DXVECTOR3(3, 1, 10);

	cube[495].position = D3DXVECTOR3(-25.15f, -87.76f, -122.50f);
	cube[495].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[495].scale = D3DXVECTOR3(3, 1, 6);

	cube[496].position = D3DXVECTOR3(-26.76f, -87.64f, -122.83f);
	cube[496].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[496].scale = D3DXVECTOR3(3, 1, 10);

	cube[497].position = D3DXVECTOR3(-25.58f, -86.09f, -120.11f);
	cube[497].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[497].scale = D3DXVECTOR3(4, 1, 6);

	cube[498].position = D3DXVECTOR3(-27.33f, -85.92f, -120.43f);
	cube[498].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (70.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[498].scale = D3DXVECTOR3(4, 1, 10);

	cube[499].position = D3DXVECTOR3(-18.94f, -90.37f, -122.10f);
	cube[499].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[499].scale = D3DXVECTOR3(3, 1, 6.500001);

	cube[500].position = D3DXVECTOR3(-20.24f, -90.40f, -122.90f);
	cube[500].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[500].scale = D3DXVECTOR3(3, 1, 10);

	cube[501].position = D3DXVECTOR3(-19.96f, -89.33f, -119.82f);
	cube[501].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[501].scale = D3DXVECTOR3(3, 1, 6.200002);

	cube[502].position = D3DXVECTOR3(-21.38f, -89.34f, -120.53f);
	cube[502].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[502].scale = D3DXVECTOR3(3, 1, 10);

	cube[503].position = D3DXVECTOR3(-20.69f, -87.69f, -117.49f);
	cube[503].rotation = D3DXVECTOR3(17.70f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[503].scale = D3DXVECTOR3(4, 1, 6);

	cube[504].position = D3DXVECTOR3(-22.36f, -87.62f, -118.27f);
	cube[504].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (60.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[504].scale = D3DXVECTOR3(4, 1, 10);

	cube[505].position = D3DXVECTOR3(-13.83f, -92.01f, -118.66f);
	cube[505].rotation = D3DXVECTOR3(15.20f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[505].scale = D3DXVECTOR3(3, 1, 5.700001);

	cube[506].position = D3DXVECTOR3(-15.44f, -91.88f, -119.87f);
	cube[506].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[506].scale = D3DXVECTOR3(3, 1, 10);

	cube[507].position = D3DXVECTOR3(-15.22f, -91.05f, -116.53f);
	cube[507].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[507].scale = D3DXVECTOR3(3, 1, 5.500001);

	cube[508].position = D3DXVECTOR3(-16.98f, -90.82f, -117.73f);
	cube[508].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[508].scale = D3DXVECTOR3(3, 1, 10);

	cube[509].position = D3DXVECTOR3(-16.55f, -89.39f, -114.54f);
	cube[509].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[509].scale = D3DXVECTOR3(4, 1, 5.500002);

	cube[510].position = D3DXVECTOR3(-18.33f, -89.10f, -115.67f);
	cube[510].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (50.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[510].scale = D3DXVECTOR3(4, 1, 10);

	cube[511].position = D3DXVECTOR3(-9.73f, -93.58f, -114.45f);
	cube[511].rotation = D3DXVECTOR3(15.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[511].scale = D3DXVECTOR3(3, 1, 6.500001);

	cube[512].position = D3DXVECTOR3(-11.01f, -93.50f, -115.80f);
	cube[512].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[512].scale = D3DXVECTOR3(3, 1, 10);

	cube[513].position = D3DXVECTOR3(-11.60f, -92.53f, -112.54f);
	cube[513].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[513].scale = D3DXVECTOR3(3, 1, 6);

	cube[514].position = D3DXVECTOR3(-12.81f, -92.46f, -113.86f);
	cube[514].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[514].scale = D3DXVECTOR3(3, 1, 10);

	cube[515].position = D3DXVECTOR3(-13.13f, -90.89f, -110.73f);
	cube[515].rotation = D3DXVECTOR3(17.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[515].scale = D3DXVECTOR3(4, 1, 5.500001);

	cube[516].position = D3DXVECTOR3(-14.59f, -90.72f, -112.17f);
	cube[516].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (40.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[516].scale = D3DXVECTOR3(4, 1, 10);

	cube[517].position = D3DXVECTOR3(-6.57f, -95.09f, -109.90f);
	cube[517].rotation = D3DXVECTOR3(15.10f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[517].scale = D3DXVECTOR3(3, 1, 5.500001);

	cube[518].position = D3DXVECTOR3(-7.63f, -94.96f, -111.49f);
	cube[518].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[518].scale = D3DXVECTOR3(3, 1, 10);

	cube[519].position = D3DXVECTOR3(-8.56f, -94.19f, -108.54f);
	cube[519].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 330.60f*3.141592f / 180);
	cube[519].scale = D3DXVECTOR3(3, 1, 5);

	cube[520].position = D3DXVECTOR3(-9.80f, -93.90f, -110.02f);
	cube[520].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[520].scale = D3DXVECTOR3(3, 1, 10);

	cube[521].position = D3DXVECTOR3(-10.39f, -92.51f, -106.78f);
	cube[521].rotation = D3DXVECTOR3(16.90f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[521].scale = D3DXVECTOR3(4, 1, 5);

	cube[522].position = D3DXVECTOR3(-11.78f, -92.18f, -108.54f);
	cube[522].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (30.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[522].scale = D3DXVECTOR3(4, 1, 10);

	cube[523].position = D3DXVECTOR3(-4.88f, -96.44f, -104.09f);
	cube[523].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[523].scale = D3DXVECTOR3(3, 1, 6.300002);

	cube[524].position = D3DXVECTOR3(-4.85f, -96.61f, -106.04f);
	cube[524].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[524].scale = D3DXVECTOR3(3, 1, 10);

	cube[525].position = D3DXVECTOR3(-6.75f, -95.46f, -103.30f);
	cube[525].rotation = D3DXVECTOR3(15.80f*3.141592f / 180, (19.50f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[525].scale = D3DXVECTOR3(3, 1, 6.200002);

	cube[526].position = D3DXVECTOR3(-7.25f, -95.55f, -104.97f);
	cube[526].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[526].scale = D3DXVECTOR3(3, 1, 10);

	cube[527].position = D3DXVECTOR3(-8.32f, -94.19f, -102.36f);
	cube[527].rotation = D3DXVECTOR3(18.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 318.00f*3.141592f / 180);
	cube[527].scale = D3DXVECTOR3(4, 1, 6);

	cube[528].position = D3DXVECTOR3(-9.45f, -93.83f, -103.86f);
	cube[528].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (20.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[528].scale = D3DXVECTOR3(4, 1, 10);

	cube[529].position = D3DXVECTOR3(-3.40f, -98.11f, -97.91f);
	cube[529].rotation = D3DXVECTOR3(13.70f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[529].scale = D3DXVECTOR3(3, 1, 7.500003);

	cube[530].position = D3DXVECTOR3(-2.88f, -98.35f, -99.25f);
	cube[530].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[530].scale = D3DXVECTOR3(3, 1, 10);

	cube[531].position = D3DXVECTOR3(-4.97f, -97.35f, -97.26f);
	cube[531].rotation = D3DXVECTOR3(14.70f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[531].scale = D3DXVECTOR3(3, 1, 7);

	cube[532].position = D3DXVECTOR3(-5.43f, -97.29f, -98.61f);
	cube[532].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[532].scale = D3DXVECTOR3(3, 1, 10);

	cube[533].position = D3DXVECTOR3(-7.77f, -95.59f, -97.90f);
	cube[533].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[533].scale = D3DXVECTOR3(4, 1, 10);

	cube[534].position = D3DXVECTOR3(-7.39f, -95.59f, -96.45f);
	cube[534].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (10.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[534].scale = D3DXVECTOR3(4, 1, 6.700001);

	cube[535].position = D3DXVECTOR3(-2.03f, -100.06f, -91.07f);
	cube[535].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[535].scale = D3DXVECTOR3(3, 1, 7);

	cube[536].position = D3DXVECTOR3(-2.10f, -100.03f, -92.26f);
	cube[536].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[536].scale = D3DXVECTOR3(3, 1, 10);

	cube[537].position = D3DXVECTOR3(-4.59f, -99.03f, -90.77f);
	cube[537].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[537].scale = D3DXVECTOR3(3, 1, 7);

	cube[538].position = D3DXVECTOR3(-4.73f, -98.97f, -92.07f);
	cube[538].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[538].scale = D3DXVECTOR3(3, 1, 10);

	cube[539].position = D3DXVECTOR3(-6.76f, -97.55f, -90.21f);
	cube[539].rotation = D3DXVECTOR3(15.50f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[539].scale = D3DXVECTOR3(4, 1, 6.500001);

	cube[540].position = D3DXVECTOR3(-7.17f, -97.25f, -91.78f);
	cube[540].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[540].scale = D3DXVECTOR3(4, 1, 10);

	cube[541].position = D3DXVECTOR3(-2.16f, -101.69f, -83.22f);
	cube[541].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[541].scale = D3DXVECTOR3(3, 1, 10);

	cube[542].position = D3DXVECTOR3(-4.78f, -100.63f, -83.04f);
	cube[542].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[542].scale = D3DXVECTOR3(3, 1, 10);

	cube[543].position = D3DXVECTOR3(-7.23f, -98.91f, -82.74f);
	cube[543].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[543].scale = D3DXVECTOR3(3, 1, 10);

	cube[544].position = D3DXVECTOR3(-2.16f, -103.43f, -73.72f);
	cube[544].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[544].scale = D3DXVECTOR3(3, 1, 10);

	cube[545].position = D3DXVECTOR3(-4.78f, -102.37f, -73.54f);
	cube[545].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[545].scale = D3DXVECTOR3(3, 1, 10);

	cube[546].position = D3DXVECTOR3(-7.23f, -100.65f, -73.24f);
	cube[546].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[546].scale = D3DXVECTOR3(3, 1, 10);

	cube[547].position = D3DXVECTOR3(-2.16f, -105.16f, -64.52f);
	cube[547].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 345.00f*3.141592f / 180);
	cube[547].scale = D3DXVECTOR3(3, 1, 10);

	cube[548].position = D3DXVECTOR3(-4.78f, -104.10f, -64.34f);
	cube[548].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[548].scale = D3DXVECTOR3(3, 1, 10);

	cube[549].position = D3DXVECTOR3(-7.23f, -102.38f, -64.04f);
	cube[549].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (0.00f - 360)*3.141592f / 180, 320.00f*3.141592f / 180);
	cube[549].scale = D3DXVECTOR3(3, 1, 10);

	rightWall[0].position = D3DXVECTOR3(10.76f, -6.49f, 1.30f);
	rightWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[0].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[1].position = D3DXVECTOR3(10.76f, -8.25f, 10.97f);
	rightWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[1].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[2].position = D3DXVECTOR3(10.76f, -9.92f, 19.98f);
	rightWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[2].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[3].position = D3DXVECTOR3(10.84f, -11.54f, 28.97f);
	rightWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[3].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[4].position = D3DXVECTOR3(10.22f, -13.19f, 37.75f);
	rightWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[4].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[5].position = D3DXVECTOR3(7.96f, -14.80f, 46.36f);
	rightWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[5].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[6].position = D3DXVECTOR3(4.21f, -16.50f, 54.58f);
	rightWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[6].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[7].position = D3DXVECTOR3(-0.53f, -17.98f, 61.53f);
	rightWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[7].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[8].position = D3DXVECTOR3(-6.64f, -19.60f, 67.78f);
	rightWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[8].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[9].position = D3DXVECTOR3(-13.28f, -21.06f, 72.61f);
	rightWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[9].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[10].position = D3DXVECTOR3(-21.27f, -22.71f, 76.40f);
	rightWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[10].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[11].position = D3DXVECTOR3(-30.75f, -24.45f, 78.92f);
	rightWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[11].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[12].position = D3DXVECTOR3(-40.48f, -26.13f, 79.79f);
	rightWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[12].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[13].position = D3DXVECTOR3(-46.94f, -27.45f, 79.90f);
	rightWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[13].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[14].position = D3DXVECTOR3(-55.72f, -29.10f, 79.28f);
	rightWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[14].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[15].position = D3DXVECTOR3(-64.33f, -30.71f, 77.02f);
	rightWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 250.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[15].scale = D3DXVECTOR3(5, 1, 10.00001);

	rightWall[16].position = D3DXVECTOR3(-72.55f, -32.41f, 73.27f);
	rightWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 240.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[16].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[17].position = D3DXVECTOR3(-79.50f, -33.89f, 68.53f);
	rightWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 230.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[17].scale = D3DXVECTOR3(5, 1, 10.00001);

	rightWall[18].position = D3DXVECTOR3(-85.76f, -35.51f, 62.42f);
	rightWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[18].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[19].position = D3DXVECTOR3(-90.58f, -36.97f, 55.78f);
	rightWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[19].scale = D3DXVECTOR3(5, 1, 10.00001);

	rightWall[20].position = D3DXVECTOR3(-94.37f, -38.62f, 47.79f);
	rightWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[20].scale = D3DXVECTOR3(5, 1, 10.00001);

	rightWall[21].position = D3DXVECTOR3(-96.90f, -40.36f, 38.31f);
	rightWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[21].scale = D3DXVECTOR3(5, 1, 10.00001);

	rightWall[22].position = D3DXVECTOR3(-97.76f, -42.04f, 28.58f);
	rightWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[22].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[23].position = D3DXVECTOR3(-97.74f, -43.78f, 19.02f);
	rightWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[23].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[24].position = D3DXVECTOR3(-97.74f, -45.53f, 9.46f);
	rightWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[24].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[25].position = D3DXVECTOR3(-97.74f, -47.31f, -0.10f);
	rightWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[25].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[26].position = D3DXVECTOR3(-97.74f, -49.09f, -9.75f);
	rightWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[26].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[27].position = D3DXVECTOR3(-97.74f, -50.80f, -19.14f);
	rightWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[27].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[28].position = D3DXVECTOR3(-97.76f, -52.27f, -27.58f);
	rightWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[28].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[29].position = D3DXVECTOR3(-97.76f, -53.99f, -37.28f);
	rightWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[29].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[30].position = D3DXVECTOR3(-97.74f, -55.74f, -46.58f);
	rightWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[30].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[31].position = D3DXVECTOR3(-97.74f, -57.52f, -55.95f);
	rightWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[31].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[32].position = D3DXVECTOR3(-97.74f, -59.27f, -65.46f);
	rightWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[32].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[33].position = D3DXVECTOR3(-97.74f, -60.99f, -74.49f);
	rightWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[33].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[34].position = D3DXVECTOR3(-97.74f, -62.71f, -84.55f);
	rightWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[34].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[35].position = D3DXVECTOR3(-97.74f, -64.13f, -91.84f);
	rightWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[35].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[36].position = D3DXVECTOR3(-97.12f, -65.78f, -100.62f);
	rightWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[36].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[37].position = D3DXVECTOR3(-94.86f, -67.39f, -109.23f);
	rightWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[37].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[38].position = D3DXVECTOR3(-91.11f, -69.09f, -117.45f);
	rightWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[38].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[39].position = D3DXVECTOR3(-86.37f, -70.57f, -124.40f);
	rightWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[39].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[40].position = D3DXVECTOR3(-80.26f, -72.19f, -130.66f);
	rightWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[40].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[41].position = D3DXVECTOR3(-73.62f, -73.65f, -135.48f);
	rightWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[41].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[42].position = D3DXVECTOR3(-65.63f, -75.30f, -139.27f);
	rightWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[42].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[43].position = D3DXVECTOR3(-56.15f, -77.04f, -141.80f);
	rightWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[43].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[44].position = D3DXVECTOR3(-46.42f, -78.72f, -142.66f);
	rightWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[44].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[45].position = D3DXVECTOR3(-37.22f, -80.43f, -142.68f);
	rightWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[45].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[46].position = D3DXVECTOR3(-28.44f, -82.08f, -142.06f);
	rightWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[46].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[47].position = D3DXVECTOR3(-19.83f, -83.69f, -139.80f);
	rightWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[47].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[48].position = D3DXVECTOR3(-11.61f, -85.39f, -136.05f);
	rightWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[48].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[49].position = D3DXVECTOR3(-4.66f, -86.87f, -131.31f);
	rightWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[49].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[50].position = D3DXVECTOR3(1.60f, -88.49f, -125.20f);
	rightWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[50].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[51].position = D3DXVECTOR3(6.42f, -89.95f, -118.56f);
	rightWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[51].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[52].position = D3DXVECTOR3(10.21f, -91.60f, -110.57f);
	rightWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[52].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[53].position = D3DXVECTOR3(12.74f, -93.34f, -101.09f);
	rightWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[53].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[54].position = D3DXVECTOR3(13.60f, -95.02f, -91.36f);
	rightWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[54].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[55].position = D3DXVECTOR3(13.54f, -96.68f, -82.32f);
	rightWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[55].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[56].position = D3DXVECTOR3(13.54f, -98.42f, -72.82f);
	rightWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[56].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[57].position = D3DXVECTOR3(13.54f, -100.15f, -63.62f);
	rightWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[57].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[0].position = D3DXVECTOR3(-11.29f, -6.48f, 1.29f);
	leftWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[0].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[1].position = D3DXVECTOR3(-11.29f, -8.24f, 10.96f);
	leftWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[1].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[2].position = D3DXVECTOR3(-11.29f, -9.91f, 19.97f);
	leftWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[2].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[3].position = D3DXVECTOR3(-11.21f, -11.53f, 28.96f);
	leftWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[3].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[4].position = D3DXVECTOR3(-11.72f, -12.96f, 36.17f);
	leftWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[4].scale = D3DXVECTOR3(5, 1, 5.5);

	leftWall[5].position = D3DXVECTOR3(-13.26f, -15.14f, 40.80f);
	leftWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 334.20f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[5].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[6].position = D3DXVECTOR3(-15.92f, -16.84f, 45.18f);
	leftWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 325.10f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[6].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[7].position = D3DXVECTOR3(-19.11f, -18.38f, 48.98f);
	leftWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[7].scale = D3DXVECTOR3(5, 1, 5.15);

	leftWall[8].position = D3DXVECTOR3(-22.39f, -19.95f, 52.10f);
	leftWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[8].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[9].position = D3DXVECTOR3(-26.35f, -21.46f, 54.84f);
	leftWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[9].scale = D3DXVECTOR3(5, 1, 5);

	leftWall[10].position = D3DXVECTOR3(-30.57f, -23.02f, 56.64f);
	leftWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[10].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[11].position = D3DXVECTOR3(-36.15f, -24.71f, 57.59f);
	leftWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 274.50f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[11].scale = D3DXVECTOR3(5, 1, 6.7);

	leftWall[12].position = D3DXVECTOR3(-41.67f, -26.34f, 57.74f);
	leftWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[12].scale = D3DXVECTOR3(5, 1, 7.4);

	leftWall[13].position = D3DXVECTOR3(-46.93f, -27.44f, 57.85f);
	leftWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[13].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[14].position = D3DXVECTOR3(-54.14f, -28.87f, 57.34f);
	leftWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[14].scale = D3DXVECTOR3(5, 1, 5.500005);

	leftWall[15].position = D3DXVECTOR3(-58.77f, -31.05f, 55.80f);
	leftWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 244.20f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[15].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[16].position = D3DXVECTOR3(-63.15f, -32.75f, 53.14f);
	leftWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 235.10f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[16].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[17].position = D3DXVECTOR3(-66.95f, -34.29f, 49.95f);
	leftWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 230.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[17].scale = D3DXVECTOR3(5, 1, 5.150005);

	leftWall[18].position = D3DXVECTOR3(-70.07f, -35.86f, 46.67f);
	leftWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[18].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[19].position = D3DXVECTOR3(-72.81f, -37.37f, 42.71f);
	leftWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[19].scale = D3DXVECTOR3(5, 1, 5);

	leftWall[20].position = D3DXVECTOR3(-74.61f, -38.93f, 38.49f);
	leftWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[20].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[21].position = D3DXVECTOR3(-75.56f, -40.62f, 32.91f);
	leftWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 184.50f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[21].scale = D3DXVECTOR3(5, 1, 6.700006);

	leftWall[22].position = D3DXVECTOR3(-75.71f, -42.25f, 27.39f);
	leftWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[22].scale = D3DXVECTOR3(5, 1, 7.400007);

	leftWall[23].position = D3DXVECTOR3(-75.69f, -43.77f, 19.03f);
	leftWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[23].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[24].position = D3DXVECTOR3(-75.69f, -45.52f, 9.47f);
	leftWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[24].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[25].position = D3DXVECTOR3(-75.69f, -47.30f, -0.09f);
	leftWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[25].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[26].position = D3DXVECTOR3(-75.69f, -49.08f, -9.74f);
	leftWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[26].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[27].position = D3DXVECTOR3(-75.69f, -50.79f, -19.13f);
	leftWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[27].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[28].position = D3DXVECTOR3(-75.71f, -52.26f, -27.57f);
	leftWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[28].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[29].position = D3DXVECTOR3(-75.71f, -53.98f, -37.27f);
	leftWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[29].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[30].position = D3DXVECTOR3(-75.69f, -55.73f, -46.57f);
	leftWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[30].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[31].position = D3DXVECTOR3(-75.69f, -57.51f, -55.94f);
	leftWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[31].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[32].position = D3DXVECTOR3(-75.69f, -59.26f, -65.45f);
	leftWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[32].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[33].position = D3DXVECTOR3(-75.69f, -60.98f, -74.48f);
	leftWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[33].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[34].position = D3DXVECTOR3(-75.69f, -62.71f, -84.54f);
	leftWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[34].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[35].position = D3DXVECTOR3(-75.69f, -64.12f, -91.83f);
	leftWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[35].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[36].position = D3DXVECTOR3(-75.18f, -65.55f, -99.04f);
	leftWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[36].scale = D3DXVECTOR3(5, 1, 5.5);

	leftWall[37].position = D3DXVECTOR3(-73.64f, -67.73f, -103.67f);
	leftWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 154.20f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[37].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[38].position = D3DXVECTOR3(-70.98f, -69.43f, -108.05f);
	leftWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 145.10f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[38].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[39].position = D3DXVECTOR3(-67.79f, -70.97f, -111.85f);
	leftWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[39].scale = D3DXVECTOR3(5, 1, 5.150002);

	leftWall[40].position = D3DXVECTOR3(-64.51f, -72.54f, -114.97f);
	leftWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[40].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[41].position = D3DXVECTOR3(-60.55f, -74.05f, -117.71f);
	leftWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[41].scale = D3DXVECTOR3(5, 1, 5);

	leftWall[42].position = D3DXVECTOR3(-56.33f, -75.61f, -119.51f);
	leftWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[42].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[43].position = D3DXVECTOR3(-50.75f, -77.30f, -120.46f);
	leftWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 94.50f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[43].scale = D3DXVECTOR3(5, 1, 6.700001);

	leftWall[44].position = D3DXVECTOR3(-45.23f, -78.93f, -120.61f);
	leftWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[44].scale = D3DXVECTOR3(5, 1, 7.399999);

	leftWall[45].position = D3DXVECTOR3(-37.23f, -80.42f, -120.63f);
	leftWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[45].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[46].position = D3DXVECTOR3(-30.02f, -81.85f, -120.12f);
	leftWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[46].scale = D3DXVECTOR3(5, 1, 5.500003);

	leftWall[47].position = D3DXVECTOR3(-25.39f, -84.03f, -118.58f);
	leftWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 64.20f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[47].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[48].position = D3DXVECTOR3(-21.01f, -85.73f, -115.92f);
	leftWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 55.10f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[48].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[49].position = D3DXVECTOR3(-17.21f, -87.27f, -112.73f);
	leftWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[49].scale = D3DXVECTOR3(5, 1, 5.150002);

	leftWall[50].position = D3DXVECTOR3(-14.09f, -88.84f, -109.45f);
	leftWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[50].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[51].position = D3DXVECTOR3(-11.35f, -90.35f, -105.49f);
	leftWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[51].scale = D3DXVECTOR3(5, 1, 5);

	leftWall[52].position = D3DXVECTOR3(-9.55f, -91.91f, -101.27f);
	leftWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[52].scale = D3DXVECTOR3(5, 1, 6);

	leftWall[53].position = D3DXVECTOR3(-8.60f, -93.60f, -95.69f);
	leftWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 4.50f*3.141592f / 180, 271.00f*3.141592f / 180);
	leftWall[53].scale = D3DXVECTOR3(5, 1, 6.700002);

	leftWall[54].position = D3DXVECTOR3(-8.45f, -95.23f, -90.17f);
	leftWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[54].scale = D3DXVECTOR3(5, 1, 7.4);

	leftWall[55].position = D3DXVECTOR3(-8.51f, -96.67f, -82.33f);
	leftWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[55].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[56].position = D3DXVECTOR3(-8.51f, -98.41f, -72.83f);
	leftWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[56].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[57].position = D3DXVECTOR3(-8.51f, -100.14f, -63.63f);
	leftWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[57].scale = D3DXVECTOR3(5, 1, 10);

	//加速床座標
	accelSpeed[0].position= D3DXVECTOR3(999, 999, 999);
	accelSpeed[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[0].scale = D3DXVECTOR3(2, 1.5 ,1);

	//ゴール床座標
	goalCube.position = D3DXVECTOR3(999, 999, 999);
	goalCube.rotation = D3DXVECTOR3(0.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	goalCube.scale = D3DXVECTOR3(20,0,20);


	for (int i = 0; i < CUBE_NUM; i++) {
		cube[i].scale *= 1.1f;
	}
}


void StageDraw() {
	D3DXVECTOR3 distance;
	const float DRAW_RANGE = 150;
	//Cubeの描画
	for (int i = 0; i < CUBE_NUM; i++) {
		distance = cube[i].position - GetPlayerPos();//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -DRAW_RANGE && distance.x < DRAW_RANGE;
		const bool isCollisoinRangeY = distance.y > -DRAW_RANGE && distance.y < DRAW_RANGE;
		const bool isCollisoinRangeZ = distance.z > -DRAW_RANGE && distance.z < DRAW_RANGE;

		//一定範囲内にCubeが存在する描画する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			cube[i].Draw(TEXTURE_INDEX_ICE);
		}
	}
	for (int i = 0; i < RIGHT_WALL_NUM; i++) {
		distance = rightWall[i].position - GetPlayerPos();//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -DRAW_RANGE && distance.x < DRAW_RANGE;
		const bool isCollisoinRangeY = distance.y > -DRAW_RANGE && distance.y < DRAW_RANGE;
		const bool isCollisoinRangeZ = distance.z > -DRAW_RANGE && distance.z < DRAW_RANGE;

		//一定範囲内にCubeが存在する描画する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			rightWall[i].Draw(TEXTURE_INDEX_ICE);
		}
	}
	for (int i = 0; i < LEFT_WALL_NUM; i++) {
		distance = leftWall[i].position - GetPlayerPos();//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -DRAW_RANGE && distance.x < DRAW_RANGE;
		const bool isCollisoinRangeY = distance.y > -DRAW_RANGE && distance.y < DRAW_RANGE;
		const bool isCollisoinRangeZ = distance.z > -DRAW_RANGE && distance.z < DRAW_RANGE;

		//一定範囲内にCubeが存在する描画する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			leftWall[i].Draw(TEXTURE_INDEX_ICE);
		}
	}
	goalCube.Draw(TEXTURE_INDEX_ICE);

	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		accelSpeed[i].Draw(TEXTURE_INDEX_MAX, D3DXCOLOR(1, 0 , 0 , 1));
	}
}


Plane GetCube(int n) {
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