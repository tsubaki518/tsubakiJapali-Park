#include"figure.h"
#include"Stage.h"
#include"Game.h"

//最大設置数
const int CUBE_NUM = 1291;
const int ACCEL_SPEED_NUM = 7;
const int RIGHT_WALL_NUM = 191;
const int LEFT_WALL_NUM = 191;


//rotationのx,zは1.4ｆまで
Plane cube[CUBE_NUM];				//床
Cube accelSpeed[ACCEL_SPEED_NUM];	//加速床
Cube rightWall[RIGHT_WALL_NUM];		//右側の壁
Cube leftWall[LEFT_WALL_NUM];		//左側の壁
Cube goalCube;						//ゴール_床


void StageInit() {			//座標とサイズと角度を入れる
	//ステージ座標
	cube[0].position = D3DXVECTOR3(-0.27f, -10.85f, 2.06f);
	cube[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[0].scale = D3DXVECTOR3(10, 1, 10);

	cube[1].position = D3DXVECTOR3(-0.27f, -12.51f, 11.06f);
	cube[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[1].scale = D3DXVECTOR3(10, 1, 10);

	cube[2].position = D3DXVECTOR3(-0.27f, -14.10f, 19.76f);
	cube[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[2].scale = D3DXVECTOR3(10, 1, 10);

	cube[3].position = D3DXVECTOR3(-0.27f, -15.78f, 28.86f);
	cube[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[3].scale = D3DXVECTOR3(10, 1, 10);

	cube[4].position = D3DXVECTOR3(-0.27f, -17.57f, 38.26f);
	cube[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[4].scale = D3DXVECTOR3(10, 1, 10);

	cube[5].position = D3DXVECTOR3(-0.27f, -19.25f, 47.56f);
	cube[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[5].scale = D3DXVECTOR3(10, 1, 10);

	cube[6].position = D3DXVECTOR3(-0.27f, -21.04f, 57.26f);
	cube[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[6].scale = D3DXVECTOR3(10, 1, 10);

	cube[7].position = D3DXVECTOR3(-0.27f, -22.63f, 66.06f);
	cube[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[7].scale = D3DXVECTOR3(10, 1, 10);

	cube[8].position = D3DXVECTOR3(-0.27f, -24.00f, 73.68f);
	cube[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[8].scale = D3DXVECTOR3(10, 1, 10);

	cube[9].position = D3DXVECTOR3(-0.50f, -25.51f, 80.94f);
	cube[9].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[9].scale = D3DXVECTOR3(11, 1, 5);

	cube[10].position = D3DXVECTOR3(-0.85f, -25.69f, 81.72f);
	cube[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[10].scale = D3DXVECTOR3(10, 1, 10);

	cube[11].position = D3DXVECTOR3(-2.25f, -27.17f, 88.59f);
	cube[11].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[11].scale = D3DXVECTOR3(11, 1, 5);

	cube[12].position = D3DXVECTOR3(-2.71f, -27.35f, 89.30f);
	cube[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[12].scale = D3DXVECTOR3(10, 1, 10);

	cube[13].position = D3DXVECTOR3(-5.34f, -28.80f, 95.69f);
	cube[13].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[13].scale = D3DXVECTOR3(11, 1, 5);

	cube[14].position = D3DXVECTOR3(-5.68f, -28.95f, 96.03f);
	cube[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[14].scale = D3DXVECTOR3(10, 1, 10);

	cube[15].position = D3DXVECTOR3(-9.35f, -30.37f, 101.82f);
	cube[15].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[15].scale = D3DXVECTOR3(11, 1, 5);

	cube[16].position = D3DXVECTOR3(-9.99f, -30.60f, 102.51f);
	cube[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[16].scale = D3DXVECTOR3(10, 1, 10);

	cube[17].position = D3DXVECTOR3(-14.77f, -32.12f, 107.78f);
	cube[17].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[17].scale = D3DXVECTOR3(11, 1, 5);

	cube[18].position = D3DXVECTOR3(-15.54f, -32.31f, 108.21f);
	cube[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[18].scale = D3DXVECTOR3(10, 1, 10);

	cube[19].position = D3DXVECTOR3(-20.60f, -33.67f, 112.31f);
	cube[19].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[19].scale = D3DXVECTOR3(11, 1, 5);

	cube[20].position = D3DXVECTOR3(-21.70f, -33.94f, 112.73f);
	cube[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[20].scale = D3DXVECTOR3(10, 1, 10);

	cube[21].position = D3DXVECTOR3(-29.79f, -35.66f, 117.40f);
	cube[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[21].scale = D3DXVECTOR3(10, 1, 10);

	cube[22].position = D3DXVECTOR3(-37.75f, -37.39f, 122.01f);
	cube[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[22].scale = D3DXVECTOR3(10, 1, 10);

	cube[23].position = D3DXVECTOR3(-45.05f, -38.94f, 126.21f);
	cube[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[23].scale = D3DXVECTOR3(10, 1, 10);

	cube[24].position = D3DXVECTOR3(-52.35f, -40.46f, 130.41f);
	cube[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[24].scale = D3DXVECTOR3(10, 1, 10);

	cube[25].position = D3DXVECTOR3(-60.25f, -42.19f, 135.01f);
	cube[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[25].scale = D3DXVECTOR3(10, 1, 10);

	cube[26].position = D3DXVECTOR3(-68.11f, -43.83f, 139.48f);
	cube[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[26].scale = D3DXVECTOR3(10, 1, 10);

	cube[27].position = D3DXVECTOR3(-74.52f, -45.34f, 142.89f);
	cube[27].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[27].scale = D3DXVECTOR3(11, 1, 5);

	cube[28].position = D3DXVECTOR3(-75.36f, -45.52f, 142.99f);
	cube[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[28].scale = D3DXVECTOR3(10, 1, 10);

	cube[29].position = D3DXVECTOR3(-82.05f, -47.00f, 145.14f);
	cube[29].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[29].scale = D3DXVECTOR3(11, 1, 5);

	cube[30].position = D3DXVECTOR3(-82.85f, -47.18f, 145.18f);
	cube[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[30].scale = D3DXVECTOR3(10, 1, 10);

	cube[31].position = D3DXVECTOR3(-89.71f, -48.63f, 146.08f);
	cube[31].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[31].scale = D3DXVECTOR3(11, 1, 5);

	cube[32].position = D3DXVECTOR3(-90.16f, -48.78f, 145.97f);
	cube[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[32].scale = D3DXVECTOR3(10, 1, 10);

	cube[33].position = D3DXVECTOR3(-97.02f, -50.16f, 145.52f);
	cube[33].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[33].scale = D3DXVECTOR3(11, 1, 5);

	cube[34].position = D3DXVECTOR3(-97.93f, -50.43f, 145.48f);
	cube[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[34].scale = D3DXVECTOR3(10, 1, 10);

	cube[35].position = D3DXVECTOR3(-104.59f, -51.74f, 144.29f);
	cube[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[35].scale = D3DXVECTOR3(10, 1, 10);

	cube[36].position = D3DXVECTOR3(-111.68f, -53.21f, 143.07f);
	cube[36].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[36].scale = D3DXVECTOR3(11, 1, 5);

	cube[37].position = D3DXVECTOR3(-112.34f, -53.35f, 143.45f);
	cube[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[37].scale = D3DXVECTOR3(10, 1, 10);

	cube[38].position = D3DXVECTOR3(-119.47f, -54.79f, 143.71f);
	cube[38].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[38].scale = D3DXVECTOR3(11, 1, 5);

	cube[39].position = D3DXVECTOR3(-119.78f, -54.94f, 143.94f);
	cube[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[39].scale = D3DXVECTOR3(10, 1, 10);

	cube[40].position = D3DXVECTOR3(-126.67f, -56.35f, 145.21f);
	cube[40].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[40].scale = D3DXVECTOR3(11, 1, 5);

	cube[41].position = D3DXVECTOR3(-127.31f, -56.57f, 145.80f);
	cube[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[41].scale = D3DXVECTOR3(10, 1, 10);

	cube[42].position = D3DXVECTOR3(-133.93f, -58.02f, 148.35f);
	cube[42].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[42].scale = D3DXVECTOR3(11, 1, 5);

	cube[43].position = D3DXVECTOR3(-134.37f, -58.20f, 148.90f);
	cube[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[43].scale = D3DXVECTOR3(10, 1, 10);

	cube[44].position = D3DXVECTOR3(-140.32f, -59.61f, 152.53f);
	cube[44].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[44].scale = D3DXVECTOR3(11, 1, 5);

	cube[45].position = D3DXVECTOR3(-140.74f, -59.80f, 153.15f);
	cube[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[45].scale = D3DXVECTOR3(10, 1, 10);

	cube[46].position = D3DXVECTOR3(-146.15f, -61.24f, 158.07f);
	cube[46].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[46].scale = D3DXVECTOR3(11, 1, 5);

	cube[47].position = D3DXVECTOR3(-146.32f, -61.44f, 158.51f);
	cube[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[47].scale = D3DXVECTOR3(10, 1, 10);

	cube[48].position = D3DXVECTOR3(-150.66f, -62.90f, 164.05f);
	cube[48].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[48].scale = D3DXVECTOR3(11, 1, 5);

	cube[49].position = D3DXVECTOR3(-150.71f, -63.10f, 164.61f);
	cube[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[49].scale = D3DXVECTOR3(10, 1, 10);

	cube[50].position = D3DXVECTOR3(-154.20f, -64.57f, 170.83f);
	cube[50].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[50].scale = D3DXVECTOR3(11, 1, 5);

	cube[51].position = D3DXVECTOR3(-153.92f, -64.64f, 171.11f);
	cube[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[51].scale = D3DXVECTOR3(10, 1, 10);

	cube[52].position = D3DXVECTOR3(-156.40f, -66.00f, 177.81f);
	cube[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[52].scale = D3DXVECTOR3(10, 1, 10);

	cube[53].position = D3DXVECTOR3(-158.83f, -67.47f, 184.58f);
	cube[53].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[53].scale = D3DXVECTOR3(11, 1, 5);

	cube[54].position = D3DXVECTOR3(-158.57f, -67.61f, 185.30f);
	cube[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[54].scale = D3DXVECTOR3(10, 1, 10);

	cube[55].position = D3DXVECTOR3(-159.55f, -69.05f, 192.36f);
	cube[55].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[55].scale = D3DXVECTOR3(11, 1, 5);

	cube[56].position = D3DXVECTOR3(-159.38f, -69.20f, 192.71f);
	cube[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[56].scale = D3DXVECTOR3(10, 1, 10);

	cube[57].position = D3DXVECTOR3(-159.32f, -70.61f, 199.71f);
	cube[57].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[57].scale = D3DXVECTOR3(11, 1, 5);

	cube[58].position = D3DXVECTOR3(-158.86f, -70.83f, 200.44f);
	cube[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[58].scale = D3DXVECTOR3(10, 1, 10);

	cube[59].position = D3DXVECTOR3(-157.49f, -72.28f, 207.41f);
	cube[59].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[59].scale = D3DXVECTOR3(11, 1, 5);

	cube[60].position = D3DXVECTOR3(-157.03f, -72.46f, 207.93f);
	cube[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[60].scale = D3DXVECTOR3(10, 1, 10);

	cube[61].position = D3DXVECTOR3(-154.49f, -73.87f, 214.43f);
	cube[61].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[61].scale = D3DXVECTOR3(11, 1, 5);

	cube[62].position = D3DXVECTOR3(-153.94f, -74.06f, 214.94f);
	cube[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[62].scale = D3DXVECTOR3(10, 1, 10);

	cube[63].position = D3DXVECTOR3(-150.04f, -75.50f, 221.13f);
	cube[63].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[63].scale = D3DXVECTOR3(11, 1, 5);

	cube[64].position = D3DXVECTOR3(-149.64f, -75.70f, 221.37f);
	cube[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[64].scale = D3DXVECTOR3(10, 1, 10);

	cube[65].position = D3DXVECTOR3(-144.94f, -77.16f, 226.61f);
	cube[65].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[65].scale = D3DXVECTOR3(11, 1, 5);

	cube[66].position = D3DXVECTOR3(-144.40f, -77.36f, 226.75f);
	cube[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[66].scale = D3DXVECTOR3(10, 1, 10);

	cube[67].position = D3DXVECTOR3(-138.88f, -78.83f, 231.28f);
	cube[67].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[67].scale = D3DXVECTOR3(11, 1, 5);

	cube[68].position = D3DXVECTOR3(-138.55f, -78.90f, 231.05f);
	cube[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[68].scale = D3DXVECTOR3(10, 1, 10);

	cube[69].position = D3DXVECTOR3(-130.82f, -80.57f, 235.52f);
	cube[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[69].scale = D3DXVECTOR3(10, 1, 10);

	cube[70].position = D3DXVECTOR3(-122.74f, -82.27f, 240.19f);
	cube[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[70].scale = D3DXVECTOR3(10, 1, 10);

	cube[71].position = D3DXVECTOR3(-114.24f, -84.02f, 245.12f);
	cube[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[71].scale = D3DXVECTOR3(10, 1, 10);

	cube[72].position = D3DXVECTOR3(-106.18f, -85.69f, 249.84f);
	cube[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[72].scale = D3DXVECTOR3(10, 1, 10);

	cube[73].position = D3DXVECTOR3(-99.95f, -87.16f, 253.42f);
	cube[73].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[73].scale = D3DXVECTOR3(11, 1, 5);

	cube[74].position = D3DXVECTOR3(-99.18f, -87.30f, 253.29f);
	cube[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[74].scale = D3DXVECTOR3(10, 1, 10);

	cube[75].position = D3DXVECTOR3(-92.43f, -88.74f, 255.55f);
	cube[75].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[75].scale = D3DXVECTOR3(11, 1, 5);

	cube[76].position = D3DXVECTOR3(-92.03f, -88.89f, 255.37f);
	cube[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[76].scale = D3DXVECTOR3(10, 1, 10);

	cube[77].position = D3DXVECTOR3(-85.12f, -90.30f, 256.48f);
	cube[77].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[77].scale = D3DXVECTOR3(11, 1, 5);

	cube[78].position = D3DXVECTOR3(-84.32f, -90.52f, 256.20f);
	cube[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[78].scale = D3DXVECTOR3(10, 1, 10);

	cube[79].position = D3DXVECTOR3(-77.22f, -91.97f, 256.10f);
	cube[79].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[79].scale = D3DXVECTOR3(11, 1, 5);

	cube[80].position = D3DXVECTOR3(-76.63f, -92.15f, 255.70f);
	cube[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[80].scale = D3DXVECTOR3(10, 1, 10);

	cube[81].position = D3DXVECTOR3(-67.35f, -93.84f, 254.06f);
	cube[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[81].scale = D3DXVECTOR3(10, 1, 10);

	cube[82].position = D3DXVECTOR3(-60.15f, -95.35f, 253.05f);
	cube[82].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[82].scale = D3DXVECTOR3(11, 1, 5);

	cube[83].position = D3DXVECTOR3(-59.33f, -95.53f, 253.24f);
	cube[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[83].scale = D3DXVECTOR3(10, 1, 10);

	cube[84].position = D3DXVECTOR3(-52.31f, -97.01f, 253.50f);
	cube[84].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[84].scale = D3DXVECTOR3(11, 1, 5);

	cube[85].position = D3DXVECTOR3(-51.55f, -97.19f, 253.75f);
	cube[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[85].scale = D3DXVECTOR3(10, 1, 10);

	cube[86].position = D3DXVECTOR3(-44.79f, -98.64f, 255.24f);
	cube[86].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[86].scale = D3DXVECTOR3(11, 1, 5);

	cube[87].position = D3DXVECTOR3(-44.40f, -98.79f, 255.50f);
	cube[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[87].scale = D3DXVECTOR3(10, 1, 10);

	cube[88].position = D3DXVECTOR3(-38.11f, -100.17f, 258.27f);
	cube[88].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[88].scale = D3DXVECTOR3(11, 1, 5);

	cube[89].position = D3DXVECTOR3(-37.27f, -100.44f, 258.62f);
	cube[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[89].scale = D3DXVECTOR3(10, 1, 10);

	cube[90].position = D3DXVECTOR3(-29.35f, -102.12f, 263.22f);
	cube[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[90].scale = D3DXVECTOR3(10, 1, 10);

	cube[91].position = D3DXVECTOR3(-23.12f, -103.59f, 266.80f);
	cube[91].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[91].scale = D3DXVECTOR3(11, 1, 5);

	cube[92].position = D3DXVECTOR3(-22.35f, -103.73f, 266.67f);
	cube[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[92].scale = D3DXVECTOR3(10, 1, 10);

	cube[93].position = D3DXVECTOR3(-15.60f, -105.17f, 268.93f);
	cube[93].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[93].scale = D3DXVECTOR3(11, 1, 5);

	cube[94].position = D3DXVECTOR3(-15.20f, -105.32f, 268.75f);
	cube[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[94].scale = D3DXVECTOR3(10, 1, 10);

	cube[95].position = D3DXVECTOR3(-8.29f, -106.73f, 269.86f);
	cube[95].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[95].scale = D3DXVECTOR3(11, 1, 5);

	cube[96].position = D3DXVECTOR3(-7.49f, -106.95f, 269.58f);
	cube[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[96].scale = D3DXVECTOR3(10, 1, 10);

	cube[97].position = D3DXVECTOR3(-0.39f, -108.40f, 269.48f);
	cube[97].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[97].scale = D3DXVECTOR3(11, 1, 5);

	cube[98].position = D3DXVECTOR3(0.20f, -108.58f, 269.08f);
	cube[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[98].scale = D3DXVECTOR3(10, 1, 10);

	cube[99].position = D3DXVECTOR3(9.33f, -110.29f, 267.51f);
	cube[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[99].scale = D3DXVECTOR3(10, 1, 10);

	cube[100].position = D3DXVECTOR3(16.53f, -111.80f, 266.50f);
	cube[100].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[100].scale = D3DXVECTOR3(11, 1, 5);

	cube[101].position = D3DXVECTOR3(17.35f, -111.98f, 266.69f);
	cube[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[101].scale = D3DXVECTOR3(10, 1, 10);

	cube[102].position = D3DXVECTOR3(24.37f, -113.46f, 266.95f);
	cube[102].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[102].scale = D3DXVECTOR3(11, 1, 5);

	cube[103].position = D3DXVECTOR3(25.13f, -113.64f, 267.20f);
	cube[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[103].scale = D3DXVECTOR3(10, 1, 10);

	cube[104].position = D3DXVECTOR3(31.89f, -115.09f, 268.69f);
	cube[104].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[104].scale = D3DXVECTOR3(11, 1, 5);

	cube[105].position = D3DXVECTOR3(32.28f, -115.24f, 268.95f);
	cube[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[105].scale = D3DXVECTOR3(10, 1, 10);

	cube[106].position = D3DXVECTOR3(38.57f, -116.62f, 271.72f);
	cube[106].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[106].scale = D3DXVECTOR3(11, 1, 5);

	cube[107].position = D3DXVECTOR3(39.41f, -116.89f, 272.07f);
	cube[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[107].scale = D3DXVECTOR3(10, 1, 10);

	cube[108].position = D3DXVECTOR3(47.36f, -118.63f, 276.66f);
	cube[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[108].scale = D3DXVECTOR3(10, 1, 10);

	cube[109].position = D3DXVECTOR3(55.39f, -120.32f, 281.31f);
	cube[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[109].scale = D3DXVECTOR3(10, 1, 10);

	cube[110].position = D3DXVECTOR3(63.65f, -122.04f, 286.07f);
	cube[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[110].scale = D3DXVECTOR3(10, 1, 10);

	cube[111].position = D3DXVECTOR3(71.77f, -123.74f, 290.74f);
	cube[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[111].scale = D3DXVECTOR3(10, 1, 10);

	cube[112].position = D3DXVECTOR3(79.87f, -125.41f, 295.40f);
	cube[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[112].scale = D3DXVECTOR3(10, 1, 10);

	cube[113].position = D3DXVECTOR3(88.17f, -127.11f, 300.18f);
	cube[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[113].scale = D3DXVECTOR3(10, 1, 10);

	cube[114].position = D3DXVECTOR3(95.75f, -128.68f, 304.50f);
	cube[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[114].scale = D3DXVECTOR3(10, 1, 10);

	cube[115].position = D3DXVECTOR3(101.91f, -130.19f, 308.35f);
	cube[115].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[115].scale = D3DXVECTOR3(11, 1, 5);

	cube[116].position = D3DXVECTOR3(102.42f, -130.37f, 309.02f);
	cube[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[116].scale = D3DXVECTOR3(10, 1, 10);

	cube[117].position = D3DXVECTOR3(107.62f, -131.85f, 313.74f);
	cube[117].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[117].scale = D3DXVECTOR3(11, 1, 5);

	cube[118].position = D3DXVECTOR3(108.05f, -132.03f, 314.42f);
	cube[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[118].scale = D3DXVECTOR3(10, 1, 10);

	cube[119].position = D3DXVECTOR3(112.27f, -133.48f, 319.91f);
	cube[119].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[119].scale = D3DXVECTOR3(11, 1, 5);

	cube[120].position = D3DXVECTOR3(112.40f, -133.63f, 320.36f);
	cube[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[120].scale = D3DXVECTOR3(10, 1, 10);

	cube[121].position = D3DXVECTOR3(115.44f, -135.01f, 326.52f);
	cube[121].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[121].scale = D3DXVECTOR3(11, 1, 5);

	cube[122].position = D3DXVECTOR3(115.85f, -135.28f, 327.33f);
	cube[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[122].scale = D3DXVECTOR3(10, 1, 10);

	cube[123].position = D3DXVECTOR3(119.08f, -136.97f, 336.18f);
	cube[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[123].scale = D3DXVECTOR3(10, 1, 10);

	cube[124].position = D3DXVECTOR3(122.16f, -138.63f, 344.65f);
	cube[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[124].scale = D3DXVECTOR3(10, 1, 10);

	cube[125].position = D3DXVECTOR3(125.28f, -140.28f, 353.10f);
	cube[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[125].scale = D3DXVECTOR3(10, 1, 10);

	cube[126].position = D3DXVECTOR3(127.53f, -141.79f, 360.01f);
	cube[126].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[126].scale = D3DXVECTOR3(11, 1, 5);

	cube[127].position = D3DXVECTOR3(127.49f, -141.97f, 360.85f);
	cube[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[127].scale = D3DXVECTOR3(10, 1, 10);

	cube[128].position = D3DXVECTOR3(128.44f, -143.45f, 367.81f);
	cube[128].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[128].scale = D3DXVECTOR3(11, 1, 5);

	cube[129].position = D3DXVECTOR3(128.33f, -143.63f, 368.61f);
	cube[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[129].scale = D3DXVECTOR3(10, 1, 10);

	cube[130].position = D3DXVECTOR3(128.04f, -145.08f, 375.52f);
	cube[130].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[130].scale = D3DXVECTOR3(11, 1, 5);

	cube[131].position = D3DXVECTOR3(127.85f, -145.23f, 375.95f);
	cube[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[131].scale = D3DXVECTOR3(10, 1, 10);

	cube[132].position = D3DXVECTOR3(126.22f, -146.61f, 382.62f);
	cube[132].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[132].scale = D3DXVECTOR3(11, 1, 5);

	cube[133].position = D3DXVECTOR3(126.01f, -146.88f, 383.51f);
	cube[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[133].scale = D3DXVECTOR3(10, 1, 10);

	cube[134].position = D3DXVECTOR3(122.70f, -148.61f, 392.58f);
	cube[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[134].scale = D3DXVECTOR3(10, 1, 10);

	cube[135].position = D3DXVECTOR3(119.56f, -150.28f, 401.10f);
	cube[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[135].scale = D3DXVECTOR3(10, 1, 10);

	cube[136].position = D3DXVECTOR3(117.12f, -151.75f, 407.86f);
	cube[136].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[136].scale = D3DXVECTOR3(11, 1, 5);

	cube[137].position = D3DXVECTOR3(117.39f, -151.89f, 408.59f);
	cube[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[137].scale = D3DXVECTOR3(10, 1, 10);

	cube[138].position = D3DXVECTOR3(116.34f, -153.33f, 415.63f);
	cube[138].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[138].scale = D3DXVECTOR3(11, 1, 5);

	cube[139].position = D3DXVECTOR3(116.58f, -153.48f, 416.00f);
	cube[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[139].scale = D3DXVECTOR3(10, 1, 10);

	cube[140].position = D3DXVECTOR3(116.69f, -154.89f, 423.00f);
	cube[140].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[140].scale = D3DXVECTOR3(11, 1, 5);

	cube[141].position = D3DXVECTOR3(117.10f, -155.11f, 423.73f);
	cube[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[141].scale = D3DXVECTOR3(10, 1, 10);

	cube[142].position = D3DXVECTOR3(118.44f, -156.56f, 430.71f);
	cube[142].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[142].scale = D3DXVECTOR3(11, 1, 5);

	cube[143].position = D3DXVECTOR3(118.93f, -156.74f, 431.22f);
	cube[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[143].scale = D3DXVECTOR3(10, 1, 10);

	cube[144].position = D3DXVECTOR3(122.06f, -158.40f, 439.86f);
	cube[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[144].scale = D3DXVECTOR3(10, 1, 10);

	cube[145].position = D3DXVECTOR3(124.31f, -159.91f, 446.77f);
	cube[145].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[145].scale = D3DXVECTOR3(11, 1, 5);

	cube[146].position = D3DXVECTOR3(124.27f, -160.09f, 447.61f);
	cube[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[146].scale = D3DXVECTOR3(10, 1, 10);

	cube[147].position = D3DXVECTOR3(125.22f, -161.57f, 454.57f);
	cube[147].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[147].scale = D3DXVECTOR3(11, 1, 5);

	cube[148].position = D3DXVECTOR3(125.11f, -161.75f, 455.37f);
	cube[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[148].scale = D3DXVECTOR3(10, 1, 10);

	cube[149].position = D3DXVECTOR3(124.82f, -163.20f, 462.28f);
	cube[149].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[149].scale = D3DXVECTOR3(11, 1, 5);

	cube[150].position = D3DXVECTOR3(124.63f, -163.35f, 462.71f);
	cube[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[150].scale = D3DXVECTOR3(10, 1, 10);

	cube[151].position = D3DXVECTOR3(123.00f, -164.73f, 469.38f);
	cube[151].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[151].scale = D3DXVECTOR3(11, 1, 5);

	cube[152].position = D3DXVECTOR3(122.79f, -165.00f, 470.27f);
	cube[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[152].scale = D3DXVECTOR3(10, 1, 10);

	cube[153].position = D3DXVECTOR3(119.57f, -166.70f, 479.16f);
	cube[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[153].scale = D3DXVECTOR3(10, 1, 10);

	cube[154].position = D3DXVECTOR3(116.32f, -168.42f, 488.11f);
	cube[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[154].scale = D3DXVECTOR3(10, 1, 10);

	cube[155].position = D3DXVECTOR3(113.18f, -170.08f, 496.67f);
	cube[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[155].scale = D3DXVECTOR3(10, 1, 10);

	cube[156].position = D3DXVECTOR3(110.74f, -171.55f, 503.43f);
	cube[156].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[156].scale = D3DXVECTOR3(11, 1, 5);

	cube[157].position = D3DXVECTOR3(111.01f, -171.69f, 504.16f);
	cube[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[157].scale = D3DXVECTOR3(10, 1, 10);

	cube[158].position = D3DXVECTOR3(109.96f, -173.13f, 511.20f);
	cube[158].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[158].scale = D3DXVECTOR3(11, 1, 5);

	cube[159].position = D3DXVECTOR3(110.20f, -173.28f, 511.57f);
	cube[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[159].scale = D3DXVECTOR3(10, 1, 10);

	cube[160].position = D3DXVECTOR3(110.31f, -174.69f, 518.57f);
	cube[160].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[160].scale = D3DXVECTOR3(11, 1, 5);

	cube[161].position = D3DXVECTOR3(110.72f, -174.91f, 519.30f);
	cube[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[161].scale = D3DXVECTOR3(10, 1, 10);

	cube[162].position = D3DXVECTOR3(112.06f, -176.36f, 526.28f);
	cube[162].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[162].scale = D3DXVECTOR3(11, 1, 5);

	cube[163].position = D3DXVECTOR3(112.55f, -176.54f, 526.79f);
	cube[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[163].scale = D3DXVECTOR3(10, 1, 10);

	cube[164].position = D3DXVECTOR3(115.83f, -178.25f, 535.79f);
	cube[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[164].scale = D3DXVECTOR3(10, 1, 10);

	cube[165].position = D3DXVECTOR3(119.11f, -179.98f, 544.79f);
	cube[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[165].scale = D3DXVECTOR3(10, 1, 10);

	cube[166].position = D3DXVECTOR3(122.33f, -181.67f, 553.63f);
	cube[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[166].scale = D3DXVECTOR3(10, 1, 10);

	cube[167].position = D3DXVECTOR3(125.50f, -183.35f, 562.36f);
	cube[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[167].scale = D3DXVECTOR3(10, 1, 10);

	cube[168].position = D3DXVECTOR3(128.66f, -185.03f, 571.03f);
	cube[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[168].scale = D3DXVECTOR3(10, 1, 10);

	cube[169].position = D3DXVECTOR3(131.90f, -186.77f, 579.96f);
	cube[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[169].scale = D3DXVECTOR3(10, 1, 10);

	cube[170].position = D3DXVECTOR3(135.13f, -188.47f, 588.84f);
	cube[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[170].scale = D3DXVECTOR3(10, 1, 10);

	cube[171].position = D3DXVECTOR3(138.30f, -190.18f, 597.63f);
	cube[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[171].scale = D3DXVECTOR3(10, 1, 10);

	cube[172].position = D3DXVECTOR3(140.78f, -191.65f, 604.38f);
	cube[172].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[172].scale = D3DXVECTOR3(11, 1, 5);

	cube[173].position = D3DXVECTOR3(141.45f, -191.79f, 604.77f);
	cube[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[173].scale = D3DXVECTOR3(10, 1, 10);

	cube[174].position = D3DXVECTOR3(145.23f, -193.23f, 610.81f);
	cube[174].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[174].scale = D3DXVECTOR3(11, 1, 5);

	cube[175].position = D3DXVECTOR3(145.59f, -193.38f, 610.97f);
	cube[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[175].scale = D3DXVECTOR3(10, 1, 10);

	cube[176].position = D3DXVECTOR3(150.13f, -194.79f, 616.30f);
	cube[176].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[176].scale = D3DXVECTOR3(11, 1, 5);

	cube[177].position = D3DXVECTOR3(150.96f, -195.01f, 616.56f);
	cube[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[177].scale = D3DXVECTOR3(10, 1, 10);

	cube[178].position = D3DXVECTOR3(156.49f, -196.46f, 621.02f);
	cube[178].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[178].scale = D3DXVECTOR3(11, 1, 5);

	cube[179].position = D3DXVECTOR3(157.18f, -196.64f, 621.12f);
	cube[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[179].scale = D3DXVECTOR3(10, 1, 10);

	cube[180].position = D3DXVECTOR3(163.30f, -198.05f, 624.46f);
	cube[180].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[180].scale = D3DXVECTOR3(11, 1, 5);

	cube[181].position = D3DXVECTOR3(164.05f, -198.24f, 624.51f);
	cube[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[181].scale = D3DXVECTOR3(10, 1, 10);

	cube[182].position = D3DXVECTOR3(171.01f, -199.68f, 626.73f);
	cube[182].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[182].scale = D3DXVECTOR3(11, 1, 5);

	cube[183].position = D3DXVECTOR3(171.48f, -199.88f, 626.67f);
	cube[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[183].scale = D3DXVECTOR3(10, 1, 10);

	cube[184].position = D3DXVECTOR3(178.45f, -201.34f, 627.66f);
	cube[184].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[184].scale = D3DXVECTOR3(11, 1, 5);

	cube[185].position = D3DXVECTOR3(178.95f, -201.54f, 627.42f);
	cube[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[185].scale = D3DXVECTOR3(10, 1, 10);

	cube[186].position = D3DXVECTOR3(186.09f, -203.01f, 627.33f);
	cube[186].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[186].scale = D3DXVECTOR3(11, 1, 5);

	cube[187].position = D3DXVECTOR3(186.19f, -203.08f, 626.95f);
	cube[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[187].scale = D3DXVECTOR3(10, 1, 10);

	cube[188].position = D3DXVECTOR3(195.39f, -204.74f, 625.33f);
	cube[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[188].scale = D3DXVECTOR3(10, 1, 10);

	cube[189].position = D3DXVECTOR3(204.72f, -206.43f, 623.69f);
	cube[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[189].scale = D3DXVECTOR3(10, 1, 10);

	cube[190].position = D3DXVECTOR3(213.62f, -208.05f, 622.14f);
	cube[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[190].scale = D3DXVECTOR3(10, 1, 10);

	cube[191].position = D3DXVECTOR3(220.81f, -209.56f, 621.08f);
	cube[191].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[191].scale = D3DXVECTOR3(11, 1, 5);

	cube[192].position = D3DXVECTOR3(221.64f, -209.74f, 621.32f);
	cube[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[192].scale = D3DXVECTOR3(10, 1, 10);

	cube[193].position = D3DXVECTOR3(228.65f, -211.22f, 621.50f);
	cube[193].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[193].scale = D3DXVECTOR3(11, 1, 5);

	cube[194].position = D3DXVECTOR3(229.42f, -211.40f, 621.83f);
	cube[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[194].scale = D3DXVECTOR3(10, 1, 10);

	cube[195].position = D3DXVECTOR3(236.19f, -212.85f, 623.29f);
	cube[195].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[195].scale = D3DXVECTOR3(11, 1, 5);

	cube[196].position = D3DXVECTOR3(236.57f, -213.00f, 623.58f);
	cube[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[196].scale = D3DXVECTOR3(10, 1, 10);

	cube[197].position = D3DXVECTOR3(242.93f, -214.42f, 626.16f);
	cube[197].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[197].scale = D3DXVECTOR3(11, 1, 5);

	cube[198].position = D3DXVECTOR3(243.70f, -214.65f, 626.70f);
	cube[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[198].scale = D3DXVECTOR3(10, 1, 10);

	cube[199].position = D3DXVECTOR3(249.76f, -216.17f, 630.43f);
	cube[199].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[199].scale = D3DXVECTOR3(11, 1, 5);

	cube[200].position = D3DXVECTOR3(250.28f, -216.36f, 631.18f);
	cube[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[200].scale = D3DXVECTOR3(10, 1, 10);

	cube[201].position = D3DXVECTOR3(255.12f, -217.72f, 635.54f);
	cube[201].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[201].scale = D3DXVECTOR3(11, 1, 5);

	cube[202].position = D3DXVECTOR3(255.80f, -217.99f, 636.47f);
	cube[202].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[202].scale = D3DXVECTOR3(10, 1, 10);

	cube[203].position = D3DXVECTOR3(259.78f, -219.27f, 641.38f);
	cube[203].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[203].scale = D3DXVECTOR3(11, 1, 5);

	cube[204].position = D3DXVECTOR3(260.42f, -219.62f, 642.81f);
	cube[204].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[204].scale = D3DXVECTOR3(10, 1, 10);

	cube[205].position = D3DXVECTOR3(263.59f, -221.00f, 648.82f);
	cube[205].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[205].scale = D3DXVECTOR3(11, 1, 5);

	cube[206].position = D3DXVECTOR3(263.75f, -221.18f, 649.53f);
	cube[206].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[206].scale = D3DXVECTOR3(10, 1, 10);

	cube[207].position = D3DXVECTOR3(266.93f, -222.85f, 658.24f);
	cube[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[207].scale = D3DXVECTOR3(10, 1, 10);

	cube[208].position = D3DXVECTOR3(270.19f, -224.55f, 667.21f);
	cube[208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[208].scale = D3DXVECTOR3(10, 1, 10);

	cube[209].position = D3DXVECTOR3(273.45f, -226.33f, 676.14f);
	cube[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[209].scale = D3DXVECTOR3(10, 1, 10);

	cube[210].position = D3DXVECTOR3(275.93f, -227.80f, 682.89f);
	cube[210].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[210].scale = D3DXVECTOR3(11, 1, 5);

	cube[211].position = D3DXVECTOR3(276.60f, -227.94f, 683.28f);
	cube[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[211].scale = D3DXVECTOR3(10, 1, 10);

	cube[212].position = D3DXVECTOR3(280.38f, -229.38f, 689.32f);
	cube[212].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[212].scale = D3DXVECTOR3(11, 1, 5);

	cube[213].position = D3DXVECTOR3(280.74f, -229.53f, 689.48f);
	cube[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[213].scale = D3DXVECTOR3(10, 1, 10);

	cube[214].position = D3DXVECTOR3(285.28f, -230.94f, 694.81f);
	cube[214].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[214].scale = D3DXVECTOR3(11, 1, 5);

	cube[215].position = D3DXVECTOR3(286.11f, -231.16f, 695.07f);
	cube[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[215].scale = D3DXVECTOR3(10, 1, 10);

	cube[216].position = D3DXVECTOR3(291.64f, -232.61f, 699.53f);
	cube[216].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[216].scale = D3DXVECTOR3(11, 1, 5);

	cube[217].position = D3DXVECTOR3(292.33f, -232.79f, 699.63f);
	cube[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[217].scale = D3DXVECTOR3(10, 1, 10);

	cube[218].position = D3DXVECTOR3(298.45f, -234.20f, 702.97f);
	cube[218].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[218].scale = D3DXVECTOR3(11, 1, 5);

	cube[219].position = D3DXVECTOR3(299.20f, -234.39f, 703.02f);
	cube[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[219].scale = D3DXVECTOR3(10, 1, 10);

	cube[220].position = D3DXVECTOR3(306.16f, -235.83f, 705.24f);
	cube[220].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[220].scale = D3DXVECTOR3(11, 1, 5);

	cube[221].position = D3DXVECTOR3(306.63f, -236.03f, 705.18f);
	cube[221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[221].scale = D3DXVECTOR3(10, 1, 10);

	cube[222].position = D3DXVECTOR3(313.60f, -237.49f, 706.17f);
	cube[222].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[222].scale = D3DXVECTOR3(11, 1, 5);

	cube[223].position = D3DXVECTOR3(314.10f, -237.69f, 705.93f);
	cube[223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[223].scale = D3DXVECTOR3(10, 1, 10);

	cube[224].position = D3DXVECTOR3(321.24f, -239.16f, 705.84f);
	cube[224].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[224].scale = D3DXVECTOR3(11, 1, 5);

	cube[225].position = D3DXVECTOR3(321.34f, -239.23f, 705.46f);
	cube[225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[225].scale = D3DXVECTOR3(10, 1, 10);

	cube[226].position = D3DXVECTOR3(330.70f, -240.99f, 703.82f);
	cube[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[226].scale = D3DXVECTOR3(10, 1, 10);

	cube[227].position = D3DXVECTOR3(337.78f, -242.46f, 702.55f);
	cube[227].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[227].scale = D3DXVECTOR3(11, 1, 5);

	cube[228].position = D3DXVECTOR3(338.28f, -242.60f, 701.96f);
	cube[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[228].scale = D3DXVECTOR3(10, 1, 10);

	cube[229].position = D3DXVECTOR3(344.88f, -244.04f, 699.28f);
	cube[229].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[229].scale = D3DXVECTOR3(11, 1, 5);

	cube[230].position = D3DXVECTOR3(345.10f, -244.19f, 698.95f);
	cube[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[230].scale = D3DXVECTOR3(10, 1, 10);

	cube[231].position = D3DXVECTOR3(351.13f, -245.60f, 695.41f);
	cube[231].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[231].scale = D3DXVECTOR3(11, 1, 5);

	cube[232].position = D3DXVECTOR3(351.54f, -245.82f, 694.64f);
	cube[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[232].scale = D3DXVECTOR3(10, 1, 10);

	cube[233].position = D3DXVECTOR3(356.88f, -247.27f, 689.97f);
	cube[233].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[233].scale = D3DXVECTOR3(11, 1, 5);

	cube[234].position = D3DXVECTOR3(357.10f, -247.45f, 689.31f);
	cube[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[234].scale = D3DXVECTOR3(10, 1, 10);

	cube[235].position = D3DXVECTOR3(361.46f, -248.86f, 683.86f);
	cube[235].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[235].scale = D3DXVECTOR3(11, 1, 5);

	cube[236].position = D3DXVECTOR3(361.64f, -249.05f, 683.13f);
	cube[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[236].scale = D3DXVECTOR3(10, 1, 10);

	cube[237].position = D3DXVECTOR3(365.04f, -250.49f, 676.66f);
	cube[237].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[237].scale = D3DXVECTOR3(11, 1, 5);

	cube[238].position = D3DXVECTOR3(365.05f, -250.69f, 676.19f);
	cube[238].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[238].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[239].position = D3DXVECTOR3(367.24f, -252.15f, 669.50f);
	cube[239].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[239].scale = D3DXVECTOR3(11, 1, 5);

	cube[240].position = D3DXVECTOR3(367.09f, -252.35f, 668.96f);
	cube[240].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[240].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[241].position = D3DXVECTOR3(368.25f, -253.82f, 661.92f);
	cube[241].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[241].scale = D3DXVECTOR3(11, 1, 5);

	cube[242].position = D3DXVECTOR3(367.88f, -253.89f, 661.75f);
	cube[242].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[242].scale = D3DXVECTOR3(10, 1, 10);

	cube[243].position = D3DXVECTOR3(367.88f, -255.56f, 652.39f);
	cube[243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[243].scale = D3DXVECTOR3(10, 1, 10);

	cube[244].position = D3DXVECTOR3(367.88f, -257.31f, 642.85f);
	cube[244].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[244].scale = D3DXVECTOR3(10, 1, 10);

	cube[245].position = D3DXVECTOR3(367.88f, -259.01f, 633.46f);
	cube[245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[245].scale = D3DXVECTOR3(10, 1, 10);

	cube[246].position = D3DXVECTOR3(367.88f, -260.66f, 624.30f);
	cube[246].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[246].scale = D3DXVECTOR3(10, 1, 10);

	cube[247].position = D3DXVECTOR3(367.88f, -262.40f, 614.72f);
	cube[247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[247].scale = D3DXVECTOR3(10, 1, 10);

	cube[248].position = D3DXVECTOR3(367.87f, -263.99f, 605.99f);
	cube[248].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[248].scale = D3DXVECTOR3(10, 1, 10);

	cube[249].position = D3DXVECTOR3(367.86f, -265.46f, 598.80f);
	cube[249].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[249].scale = D3DXVECTOR3(11, 1, 5);

	cube[250].position = D3DXVECTOR3(367.35f, -265.60f, 598.21f);
	cube[250].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[250].scale = D3DXVECTOR3(10, 1, 10);

	cube[251].position = D3DXVECTOR3(365.94f, -267.04f, 591.23f);
	cube[251].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[251].scale = D3DXVECTOR3(11, 1, 5);

	cube[252].position = D3DXVECTOR3(365.58f, -267.19f, 590.97f);
	cube[252].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[252].scale = D3DXVECTOR3(10, 1, 10);

	cube[253].position = D3DXVECTOR3(363.09f, -268.60f, 584.43f);
	cube[253].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[253].scale = D3DXVECTOR3(11, 1, 5);

	cube[254].position = D3DXVECTOR3(362.45f, -268.82f, 583.87f);
	cube[254].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[254].scale = D3DXVECTOR3(10, 1, 10);

	cube[255].position = D3DXVECTOR3(358.81f, -270.27f, 577.78f);
	cube[255].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[255].scale = D3DXVECTOR3(11, 1, 5);

	cube[256].position = D3DXVECTOR3(358.16f, -270.45f, 577.46f);
	cube[256].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[256].scale = D3DXVECTOR3(10, 1, 10);

	cube[257].position = D3DXVECTOR3(352.21f, -272.12f, 570.36f);
	cube[257].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[257].scale = D3DXVECTOR3(10, 1, 10);

	cube[258].position = D3DXVECTOR3(347.73f, -273.63f, 564.64f);
	cube[258].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[258].scale = D3DXVECTOR3(11, 1, 5);

	cube[259].position = D3DXVECTOR3(347.48f, -273.81f, 563.83f);
	cube[259].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[259].scale = D3DXVECTOR3(10, 1, 10);

	cube[260].position = D3DXVECTOR3(344.21f, -275.29f, 557.62f);
	cube[260].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[260].scale = D3DXVECTOR3(11, 1, 5);

	cube[261].position = D3DXVECTOR3(344.03f, -275.47f, 556.83f);
	cube[261].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[261].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[262].position = D3DXVECTOR3(341.95f, -276.92f, 550.23f);
	cube[262].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[262].scale = D3DXVECTOR3(11, 1, 5);

	cube[263].position = D3DXVECTOR3(341.98f, -277.07f, 549.77f);
	cube[263].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[263].scale = D3DXVECTOR3(10, 1, 10);

	cube[264].position = D3DXVECTOR3(341.23f, -278.45f, 542.94f);
	cube[264].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[264].scale = D3DXVECTOR3(11, 1, 5);

	cube[265].position = D3DXVECTOR3(341.12f, -278.72f, 542.04f);
	cube[265].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[265].scale = D3DXVECTOR3(10, 1, 10);

	cube[266].position = D3DXVECTOR3(341.12f, -280.38f, 532.71f);
	cube[266].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[266].scale = D3DXVECTOR3(10, 1, 10);

	cube[267].position = D3DXVECTOR3(341.12f, -282.07f, 523.26f);
	cube[267].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[267].scale = D3DXVECTOR3(10, 1, 10);

	cube[268].position = D3DXVECTOR3(341.12f, -283.62f, 514.82f);
	cube[268].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[268].scale = D3DXVECTOR3(10, 1, 10);

	cube[269].position = D3DXVECTOR3(341.37f, -285.13f, 507.56f);
	cube[269].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[269].scale = D3DXVECTOR3(11, 1, 5);

	cube[270].position = D3DXVECTOR3(341.70f, -285.31f, 506.78f);
	cube[270].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[270].scale = D3DXVECTOR3(10, 1, 10);

	cube[271].position = D3DXVECTOR3(343.18f, -286.79f, 499.92f);
	cube[271].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[271].scale = D3DXVECTOR3(11, 1, 5);

	cube[272].position = D3DXVECTOR3(343.56f, -286.97f, 499.20f);
	cube[272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[272].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[273].position = D3DXVECTOR3(346.20f, -288.42f, 492.81f);
	cube[273].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[273].scale = D3DXVECTOR3(11, 1, 5);

	cube[274].position = D3DXVECTOR3(346.53f, -288.57f, 492.47f);
	cube[274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[274].scale = D3DXVECTOR3(10, 1, 10);

	cube[275].position = D3DXVECTOR3(350.34f, -289.95f, 486.76f);
	cube[275].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[275].scale = D3DXVECTOR3(11, 1, 5);

	cube[276].position = D3DXVECTOR3(350.84f, -290.22f, 485.99f);
	cube[276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[276].scale = D3DXVECTOR3(10, 1, 10);

	cube[277].position = D3DXVECTOR3(356.98f, -291.94f, 478.65f);
	cube[277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[277].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[278].position = D3DXVECTOR3(363.03f, -293.64f, 471.44f);
	cube[278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[278].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[279].position = D3DXVECTOR3(369.15f, -295.37f, 464.14f);
	cube[279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[279].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[280].position = D3DXVECTOR3(375.26f, -297.12f, 456.91f);
	cube[280].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[280].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[281].position = D3DXVECTOR3(380.11f, -298.63f, 451.50f);
	cube[281].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[281].scale = D3DXVECTOR3(11.00001, 1, 5);

	cube[282].position = D3DXVECTOR3(380.88f, -298.81f, 451.13f);
	cube[282].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[282].scale = D3DXVECTOR3(10, 1, 10);

	cube[283].position = D3DXVECTOR3(386.37f, -300.29f, 446.76f);
	cube[283].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[283].scale = D3DXVECTOR3(11.00001, 1, 5);

	cube[284].position = D3DXVECTOR3(387.17f, -300.47f, 446.51f);
	cube[284].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[284].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[285].position = D3DXVECTOR3(393.30f, -301.92f, 443.31f);
	cube[285].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[285].scale = D3DXVECTOR3(11, 1, 5);

	cube[286].position = D3DXVECTOR3(393.77f, -302.07f, 443.27f);
	cube[286].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[286].scale = D3DXVECTOR3(10, 1, 10);

	cube[287].position = D3DXVECTOR3(400.31f, -303.49f, 441.19f);
	cube[287].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[287].scale = D3DXVECTOR3(11, 1, 5);

	cube[288].position = D3DXVECTOR3(401.24f, -303.72f, 441.07f);
	cube[288].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[288].scale = D3DXVECTOR3(10, 1, 10);

	cube[289].position = D3DXVECTOR3(408.30f, -305.24f, 440.11f);
	cube[289].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[289].scale = D3DXVECTOR3(11, 1, 5);

	cube[290].position = D3DXVECTOR3(409.16f, -305.43f, 440.27f);
	cube[290].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[290].scale = D3DXVECTOR3(10, 1, 10);

	cube[291].position = D3DXVECTOR3(415.67f, -306.79f, 440.38f);
	cube[291].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[291].scale = D3DXVECTOR3(11, 1, 5);

	cube[292].position = D3DXVECTOR3(416.78f, -307.06f, 440.77f);
	cube[292].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[292].scale = D3DXVECTOR3(10, 1, 10);

	cube[293].position = D3DXVECTOR3(425.96f, -308.74f, 442.40f);
	cube[293].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[293].scale = D3DXVECTOR3(10, 1, 10);

	cube[294].position = D3DXVECTOR3(435.51f, -310.50f, 444.08f);
	cube[294].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[294].scale = D3DXVECTOR3(10, 1, 10);

	cube[295].position = D3DXVECTOR3(444.89f, -312.22f, 445.74f);
	cube[295].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[295].scale = D3DXVECTOR3(10, 1, 10);

	cube[296].position = D3DXVECTOR3(454.33f, -313.95f, 447.40f);
	cube[296].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[296].scale = D3DXVECTOR3(10, 1, 10);

	cube[297].position = D3DXVECTOR3(463.73f, -315.66f, 449.07f);
	cube[297].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[297].scale = D3DXVECTOR3(10, 1, 10);

	cube[298].position = D3DXVECTOR3(473.28f, -317.40f, 450.74f);
	cube[298].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[298].scale = D3DXVECTOR3(10, 1, 10);

	cube[299].position = D3DXVECTOR3(482.57f, -319.08f, 452.38f);
	cube[299].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[299].scale = D3DXVECTOR3(10, 1, 10);

	cube[300].position = D3DXVECTOR3(491.98f, -320.79f, 454.04f);
	cube[300].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[300].scale = D3DXVECTOR3(10, 1, 10);

	cube[301].position = D3DXVECTOR3(501.37f, -322.50f, 455.70f);
	cube[301].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[301].scale = D3DXVECTOR3(10, 1, 10);

	cube[302].position = D3DXVECTOR3(510.73f, -324.20f, 457.35f);
	cube[302].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[302].scale = D3DXVECTOR3(10, 1, 10);

	cube[303].position = D3DXVECTOR3(5.70f, -10.22f, 2.16f);
	cube[303].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[303].scale = D3DXVECTOR3(3, 1, 10);

	cube[304].position = D3DXVECTOR3(7.02f, -9.07f, 2.37f);
	cube[304].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[304].scale = D3DXVECTOR3(3, 1, 10);

	cube[305].position = D3DXVECTOR3(5.70f, -11.88f, 11.16f);
	cube[305].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[305].scale = D3DXVECTOR3(3, 1, 10);

	cube[306].position = D3DXVECTOR3(7.02f, -10.73f, 11.37f);
	cube[306].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[306].scale = D3DXVECTOR3(3, 1, 10);

	cube[307].position = D3DXVECTOR3(5.70f, -13.47f, 19.86f);
	cube[307].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[307].scale = D3DXVECTOR3(3, 1, 10);

	cube[308].position = D3DXVECTOR3(7.02f, -12.32f, 20.07f);
	cube[308].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[308].scale = D3DXVECTOR3(3, 1, 10);

	cube[309].position = D3DXVECTOR3(5.70f, -15.15f, 28.96f);
	cube[309].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[309].scale = D3DXVECTOR3(3, 1, 10);

	cube[310].position = D3DXVECTOR3(7.02f, -14.00f, 29.17f);
	cube[310].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[310].scale = D3DXVECTOR3(3, 1, 10);

	cube[311].position = D3DXVECTOR3(5.70f, -16.94f, 38.36f);
	cube[311].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[311].scale = D3DXVECTOR3(3, 1, 10);

	cube[312].position = D3DXVECTOR3(7.02f, -15.79f, 38.57f);
	cube[312].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[312].scale = D3DXVECTOR3(3, 1, 10);

	cube[313].position = D3DXVECTOR3(5.70f, -18.62f, 47.66f);
	cube[313].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[313].scale = D3DXVECTOR3(3, 1, 10);

	cube[314].position = D3DXVECTOR3(7.02f, -17.47f, 47.87f);
	cube[314].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[314].scale = D3DXVECTOR3(3, 1, 10);

	cube[315].position = D3DXVECTOR3(5.70f, -20.41f, 57.36f);
	cube[315].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[315].scale = D3DXVECTOR3(3, 1, 10);

	cube[316].position = D3DXVECTOR3(7.02f, -19.26f, 57.57f);
	cube[316].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[316].scale = D3DXVECTOR3(3, 1, 10);

	cube[317].position = D3DXVECTOR3(5.70f, -22.00f, 66.16f);
	cube[317].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[317].scale = D3DXVECTOR3(3, 1, 10);

	cube[318].position = D3DXVECTOR3(7.02f, -20.85f, 66.37f);
	cube[318].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[318].scale = D3DXVECTOR3(3, 1, 10);

	cube[319].position = D3DXVECTOR3(5.70f, -23.37f, 73.77f);
	cube[319].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[319].scale = D3DXVECTOR3(3, 1, 10);

	cube[320].position = D3DXVECTOR3(7.02f, -22.22f, 73.98f);
	cube[320].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[320].scale = D3DXVECTOR3(3, 1, 10);

	cube[321].position = D3DXVECTOR3(5.01f, -25.06f, 82.85f);
	cube[321].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[321].scale = D3DXVECTOR3(3, 1, 10);

	cube[322].position = D3DXVECTOR3(6.27f, -23.91f, 83.28f);
	cube[322].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[322].scale = D3DXVECTOR3(3, 1, 10);

	cube[323].position = D3DXVECTOR3(2.87f, -26.72f, 91.43f);
	cube[323].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[323].scale = D3DXVECTOR3(3, 1, 10);

	cube[324].position = D3DXVECTOR3(4.04f, -25.57f, 92.07f);
	cube[324].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[324].scale = D3DXVECTOR3(3, 1, 10);

	cube[325].position = D3DXVECTOR3(-0.56f, -28.32f, 99.09f);
	cube[325].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[325].scale = D3DXVECTOR3(3, 1, 10);

	cube[326].position = D3DXVECTOR3(0.48f, -27.17f, 99.93f);
	cube[326].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[326].scale = D3DXVECTOR3(3, 1, 10);

	cube[327].position = D3DXVECTOR3(-5.48f, -29.97f, 106.41f);
	cube[327].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[327].scale = D3DXVECTOR3(3, 1, 10);

	cube[328].position = D3DXVECTOR3(-4.60f, -28.82f, 107.42f);
	cube[328].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[328].scale = D3DXVECTOR3(3, 1, 10);

	cube[329].position = D3DXVECTOR3(-11.78f, -31.68f, 112.84f);
	cube[329].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[329].scale = D3DXVECTOR3(3, 1, 10);

	cube[330].position = D3DXVECTOR3(-11.09f, -30.53f, 113.99f);
	cube[330].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[330].scale = D3DXVECTOR3(3, 1, 10);

	cube[331].position = D3DXVECTOR3(-18.80f, -33.31f, 117.94f);
	cube[331].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[331].scale = D3DXVECTOR3(3, 1, 10);

	cube[332].position = D3DXVECTOR3(-18.32f, -32.16f, 119.19f);
	cube[332].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[332].scale = D3DXVECTOR3(3, 1, 10);

	cube[333].position = D3DXVECTOR3(-26.89f, -35.03f, 122.62f);
	cube[333].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[333].scale = D3DXVECTOR3(3, 1, 10);

	cube[334].position = D3DXVECTOR3(-26.41f, -33.88f, 123.86f);
	cube[334].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[334].scale = D3DXVECTOR3(3, 1, 10);

	cube[335].position = D3DXVECTOR3(-34.85f, -36.76f, 127.23f);
	cube[335].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[335].scale = D3DXVECTOR3(3, 1, 10);

	cube[336].position = D3DXVECTOR3(-34.37f, -35.61f, 128.47f);
	cube[336].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[336].scale = D3DXVECTOR3(3, 1, 10);

	cube[337].position = D3DXVECTOR3(-42.15f, -38.31f, 131.43f);
	cube[337].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[337].scale = D3DXVECTOR3(3, 1, 10);

	cube[338].position = D3DXVECTOR3(-41.67f, -37.16f, 132.67f);
	cube[338].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[338].scale = D3DXVECTOR3(3, 1, 10);

	cube[339].position = D3DXVECTOR3(-49.45f, -39.83f, 135.63f);
	cube[339].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[339].scale = D3DXVECTOR3(3, 1, 10);

	cube[340].position = D3DXVECTOR3(-48.97f, -38.68f, 136.87f);
	cube[340].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[340].scale = D3DXVECTOR3(3, 1, 10);

	cube[341].position = D3DXVECTOR3(-57.35f, -41.56f, 140.23f);
	cube[341].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[341].scale = D3DXVECTOR3(3, 1, 10);

	cube[342].position = D3DXVECTOR3(-56.87f, -40.41f, 141.47f);
	cube[342].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[342].scale = D3DXVECTOR3(3, 1, 10);

	cube[343].position = D3DXVECTOR3(-65.20f, -43.20f, 144.69f);
	cube[343].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[343].scale = D3DXVECTOR3(3, 1, 10);

	cube[344].position = D3DXVECTOR3(-64.73f, -42.05f, 145.94f);
	cube[344].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[344].scale = D3DXVECTOR3(3, 1, 10);

	cube[345].position = D3DXVECTOR3(-73.41f, -44.89f, 148.63f);
	cube[345].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[345].scale = D3DXVECTOR3(3, 1, 10);

	cube[346].position = D3DXVECTOR3(-73.15f, -43.74f, 149.95f);
	cube[346].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[346].scale = D3DXVECTOR3(3, 1, 10);

	cube[347].position = D3DXVECTOR3(-81.91f, -46.55f, 151.07f);
	cube[347].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[347].scale = D3DXVECTOR3(3, 1, 10);

	cube[348].position = D3DXVECTOR3(-81.88f, -45.40f, 152.41f);
	cube[348].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[348].scale = D3DXVECTOR3(3, 1, 10);

	cube[349].position = D3DXVECTOR3(-90.26f, -48.15f, 151.94f);
	cube[349].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[349].scale = D3DXVECTOR3(3, 1, 10);

	cube[350].position = D3DXVECTOR3(-90.47f, -47.00f, 153.26f);
	cube[350].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[350].scale = D3DXVECTOR3(3, 1, 10);

	cube[351].position = D3DXVECTOR3(-99.06f, -49.80f, 151.34f);
	cube[351].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[351].scale = D3DXVECTOR3(3, 1, 10);

	cube[352].position = D3DXVECTOR3(-99.49f, -48.65f, 152.60f);
	cube[352].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[352].scale = D3DXVECTOR3(3, 1, 10);

	cube[353].position = D3DXVECTOR3(-105.72f, -51.10f, 150.15f);
	cube[353].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[353].scale = D3DXVECTOR3(3, 1, 10);

	cube[354].position = D3DXVECTOR3(-106.15f, -49.95f, 151.42f);
	cube[354].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[354].scale = D3DXVECTOR3(3, 1, 10);

	cube[355].position = D3DXVECTOR3(-112.44f, -52.71f, 149.42f);
	cube[355].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[355].scale = D3DXVECTOR3(3, 1, 10);

	cube[356].position = D3DXVECTOR3(-113.31f, -52.81f, 149.12f);
	cube[356].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[356].scale = D3DXVECTOR3(3, 1, 7);

	cube[357].position = D3DXVECTOR3(-112.65f, -51.56f, 150.74f);
	cube[357].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[357].scale = D3DXVECTOR3(3, 1, 10);

	cube[358].position = D3DXVECTOR3(-113.82f, -51.57f, 150.65f);
	cube[358].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[358].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[359].position = D3DXVECTOR3(-118.84f, -54.30f, 149.84f);
	cube[359].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[359].scale = D3DXVECTOR3(3, 1, 10);

	cube[360].position = D3DXVECTOR3(-120.16f, -54.39f, 149.88f);
	cube[360].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[360].scale = D3DXVECTOR3(3, 1, 7);

	cube[361].position = D3DXVECTOR3(-118.82f, -53.15f, 151.17f);
	cube[361].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[361].scale = D3DXVECTOR3(3, 1, 10);

	cube[362].position = D3DXVECTOR3(-120.44f, -53.30f, 151.23f);
	cube[362].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[362].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[363].position = D3DXVECTOR3(-125.36f, -55.93f, 151.44f);
	cube[363].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[363].scale = D3DXVECTOR3(3, 1, 10);

	cube[364].position = D3DXVECTOR3(-126.61f, -55.98f, 151.76f);
	cube[364].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[364].scale = D3DXVECTOR3(3, 1, 7);

	cube[365].position = D3DXVECTOR3(-125.10f, -54.78f, 152.75f);
	cube[365].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[365].scale = D3DXVECTOR3(3, 1, 10);

	cube[366].position = D3DXVECTOR3(-126.41f, -54.89f, 153.02f);
	cube[366].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[366].scale = D3DXVECTOR3(5, 1, 7);

	cube[367].position = D3DXVECTOR3(-131.46f, -57.56f, 154.11f);
	cube[367].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[367].scale = D3DXVECTOR3(3, 1, 10);

	cube[368].position = D3DXVECTOR3(-132.62f, -57.62f, 154.64f);
	cube[368].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[368].scale = D3DXVECTOR3(3, 1, 7);

	cube[369].position = D3DXVECTOR3(-130.98f, -56.41f, 155.36f);
	cube[369].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[369].scale = D3DXVECTOR3(3, 1, 10);

	cube[370].position = D3DXVECTOR3(-132.22f, -56.53f, 155.86f);
	cube[370].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[370].scale = D3DXVECTOR3(5, 1, 7);

	cube[371].position = D3DXVECTOR3(-136.97f, -59.16f, 157.79f);
	cube[371].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[371].scale = D3DXVECTOR3(3, 1, 10);

	cube[372].position = D3DXVECTOR3(-137.93f, -59.21f, 158.43f);
	cube[372].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[372].scale = D3DXVECTOR3(3, 1, 7);

	cube[373].position = D3DXVECTOR3(-136.28f, -58.01f, 158.93f);
	cube[373].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[373].scale = D3DXVECTOR3(3, 1, 10);

	cube[374].position = D3DXVECTOR3(-137.34f, -58.11f, 159.56f);
	cube[374].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[374].scale = D3DXVECTOR3(5, 1, 7);

	cube[375].position = D3DXVECTOR3(-141.81f, -60.80f, 162.42f);
	cube[375].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[375].scale = D3DXVECTOR3(3, 1, 10);

	cube[376].position = D3DXVECTOR3(-142.55f, -60.81f, 163.10f);
	cube[376].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[376].scale = D3DXVECTOR3(3, 1, 7);

	cube[377].position = D3DXVECTOR3(-140.93f, -59.65f, 163.42f);
	cube[377].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[377].scale = D3DXVECTOR3(3, 1, 10);

	cube[378].position = D3DXVECTOR3(-141.91f, -59.74f, 164.29f);
	cube[378].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[378].scale = D3DXVECTOR3(5, 1, 6.500003);

	cube[379].position = D3DXVECTOR3(-145.59f, -62.46f, 167.67f);
	cube[379].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[379].scale = D3DXVECTOR3(3, 1, 10);

	cube[380].position = D3DXVECTOR3(-146.35f, -62.47f, 168.68f);
	cube[380].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[380].scale = D3DXVECTOR3(3, 1, 7);

	cube[381].position = D3DXVECTOR3(-144.55f, -61.31f, 168.51f);
	cube[381].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[381].scale = D3DXVECTOR3(3, 1, 10);

	cube[382].position = D3DXVECTOR3(-145.51f, -61.44f, 169.74f);
	cube[382].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[382].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[383].position = D3DXVECTOR3(-148.34f, -64.00f, 173.24f);
	cube[383].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[383].scale = D3DXVECTOR3(3, 1, 10);

	cube[384].position = D3DXVECTOR3(-148.90f, -64.04f, 174.35f);
	cube[384].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[384].scale = D3DXVECTOR3(3, 1, 7);

	cube[385].position = D3DXVECTOR3(-147.17f, -62.85f, 173.89f);
	cube[385].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[385].scale = D3DXVECTOR3(3, 1, 10);

	cube[386].position = D3DXVECTOR3(-147.88f, -62.99f, 175.24f);
	cube[386].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[386].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[387].position = D3DXVECTOR3(-150.82f, -65.36f, 179.94f);
	cube[387].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[387].scale = D3DXVECTOR3(3, 1, 10);

	cube[388].position = D3DXVECTOR3(-149.65f, -64.21f, 180.58f);
	cube[388].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[388].scale = D3DXVECTOR3(3, 1, 10);

	cube[389].position = D3DXVECTOR3(-152.71f, -66.97f, 186.43f);
	cube[389].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[389].scale = D3DXVECTOR3(3, 1, 10);

	cube[390].position = D3DXVECTOR3(-153.16f, -67.07f, 187.24f);
	cube[390].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[390].scale = D3DXVECTOR3(3, 1, 7);

	cube[391].position = D3DXVECTOR3(-151.44f, -65.82f, 186.86f);
	cube[391].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[391].scale = D3DXVECTOR3(3, 1, 10);

	cube[392].position = D3DXVECTOR3(-151.73f, -65.83f, 188.00f);
	cube[392].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[392].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[393].position = D3DXVECTOR3(-153.41f, -68.56f, 192.80f);
	cube[393].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[393].scale = D3DXVECTOR3(3, 1, 10);

	cube[394].position = D3DXVECTOR3(-153.59f, -68.65f, 194.11f);
	cube[394].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[394].scale = D3DXVECTOR3(3, 1, 7);

	cube[395].position = D3DXVECTOR3(-152.09f, -67.41f, 193.01f);
	cube[395].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[395].scale = D3DXVECTOR3(3, 1, 10);

	cube[396].position = D3DXVECTOR3(-152.31f, -67.56f, 194.62f);
	cube[396].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[396].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[397].position = D3DXVECTOR3(-152.97f, -70.19f, 199.50f);
	cube[397].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[397].scale = D3DXVECTOR3(3, 1, 10);

	cube[398].position = D3DXVECTOR3(-152.87f, -70.24f, 200.79f);
	cube[398].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[398].scale = D3DXVECTOR3(3, 1, 7);

	cube[399].position = D3DXVECTOR3(-151.63f, -69.04f, 199.48f);
	cube[399].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[399].scale = D3DXVECTOR3(3, 1, 10);

	cube[400].position = D3DXVECTOR3(-151.59f, -69.15f, 200.81f);
	cube[400].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[400].scale = D3DXVECTOR3(5, 1, 7);

	cube[401].position = D3DXVECTOR3(-151.39f, -71.82f, 205.98f);
	cube[401].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[401].scale = D3DXVECTOR3(3, 1, 10);

	cube[402].position = D3DXVECTOR3(-151.07f, -71.88f, 207.21f);
	cube[402].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[402].scale = D3DXVECTOR3(3, 1, 7);

	cube[403].position = D3DXVECTOR3(-150.08f, -70.67f, 205.72f);
	cube[403].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[403].scale = D3DXVECTOR3(3, 1, 10);

	cube[404].position = D3DXVECTOR3(-149.80f, -70.79f, 207.03f);
	cube[404].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[404].scale = D3DXVECTOR3(5, 1, 7);

	cube[405].position = D3DXVECTOR3(-148.73f, -73.42f, 212.04f);
	cube[405].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[405].scale = D3DXVECTOR3(3, 1, 10);

	cube[406].position = D3DXVECTOR3(-148.26f, -73.47f, 213.10f);
	cube[406].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[406].scale = D3DXVECTOR3(3, 1, 7);

	cube[407].position = D3DXVECTOR3(-147.48f, -72.27f, 211.56f);
	cube[407].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[407].scale = D3DXVECTOR3(3, 1, 10);

	cube[408].position = D3DXVECTOR3(-147.04f, -72.37f, 212.71f);
	cube[408].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[408].scale = D3DXVECTOR3(5, 1, 7);

	cube[409].position = D3DXVECTOR3(-145.01f, -75.06f, 217.61f);
	cube[409].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[409].scale = D3DXVECTOR3(3, 1, 10);

	cube[410].position = D3DXVECTOR3(-144.46f, -75.07f, 218.46f);
	cube[410].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[410].scale = D3DXVECTOR3(3, 1, 7);

	cube[411].position = D3DXVECTOR3(-143.86f, -73.91f, 216.92f);
	cube[411].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[411].scale = D3DXVECTOR3(3, 1, 10);

	cube[412].position = D3DXVECTOR3(-143.18f, -74.00f, 218.04f);
	cube[412].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[412].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[413].position = D3DXVECTOR3(-140.49f, -76.72f, 222.24f);
	cube[413].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[413].scale = D3DXVECTOR3(3, 1, 10);

	cube[414].position = D3DXVECTOR3(-139.63f, -76.73f, 223.17f);
	cube[414].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[414].scale = D3DXVECTOR3(3, 1, 7);

	cube[415].position = D3DXVECTOR3(-139.48f, -75.57f, 221.37f);
	cube[415].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[415].scale = D3DXVECTOR3(3, 1, 10);

	cube[416].position = D3DXVECTOR3(-138.44f, -75.70f, 222.53f);
	cube[416].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[416].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[417].position = D3DXVECTOR3(-135.48f, -78.26f, 225.92f);
	cube[417].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[417].scale = D3DXVECTOR3(3, 1, 10);

	cube[418].position = D3DXVECTOR3(-134.49f, -78.30f, 226.67f);
	cube[418].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[418].scale = D3DXVECTOR3(3, 1, 7);

	cube[419].position = D3DXVECTOR3(-134.64f, -77.11f, 224.89f);
	cube[419].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[419].scale = D3DXVECTOR3(3, 1, 10);

	cube[420].position = D3DXVECTOR3(-133.43f, -77.25f, 225.82f);
	cube[420].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[420].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[421].position = D3DXVECTOR3(-127.75f, -79.94f, 230.40f);
	cube[421].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[421].scale = D3DXVECTOR3(3, 1, 10);

	cube[422].position = D3DXVECTOR3(-126.91f, -78.79f, 229.36f);
	cube[422].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[422].scale = D3DXVECTOR3(3, 1, 10);

	cube[423].position = D3DXVECTOR3(-119.67f, -81.64f, 235.07f);
	cube[423].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[423].scale = D3DXVECTOR3(3, 1, 10);

	cube[424].position = D3DXVECTOR3(-118.83f, -80.49f, 234.03f);
	cube[424].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[424].scale = D3DXVECTOR3(3, 1, 10);

	cube[425].position = D3DXVECTOR3(-111.17f, -83.39f, 240.00f);
	cube[425].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[425].scale = D3DXVECTOR3(3, 1, 10);

	cube[426].position = D3DXVECTOR3(-110.33f, -82.24f, 238.96f);
	cube[426].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[426].scale = D3DXVECTOR3(3, 1, 10);

	cube[427].position = D3DXVECTOR3(-103.12f, -85.05f, 244.72f);
	cube[427].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[427].scale = D3DXVECTOR3(3, 1, 10);

	cube[428].position = D3DXVECTOR3(-102.28f, -83.90f, 243.68f);
	cube[428].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[428].scale = D3DXVECTOR3(3, 1, 10);

	cube[429].position = D3DXVECTOR3(-97.05f, -86.66f, 247.71f);
	cube[429].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[429].scale = D3DXVECTOR3(3, 1, 10);

	cube[430].position = D3DXVECTOR3(-96.34f, -86.76f, 248.29f);
	cube[430].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[430].scale = D3DXVECTOR3(3, 1, 7);

	cube[431].position = D3DXVECTOR3(-96.40f, -85.51f, 246.54f);
	cube[431].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[431].scale = D3DXVECTOR3(3, 1, 10);

	cube[432].position = D3DXVECTOR3(-95.34f, -85.52f, 247.02f);
	cube[432].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[432].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[433].position = D3DXVECTOR3(-90.90f, -88.25f, 249.51f);
	cube[433].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[433].scale = D3DXVECTOR3(3, 1, 10);

	cube[434].position = D3DXVECTOR3(-89.64f, -88.34f, 249.92f);
	cube[434].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[434].scale = D3DXVECTOR3(3, 1, 7);

	cube[435].position = D3DXVECTOR3(-90.46f, -87.10f, 248.24f);
	cube[435].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[435].scale = D3DXVECTOR3(3, 1, 10);

	cube[436].position = D3DXVECTOR3(-88.92f, -87.25f, 248.74f);
	cube[436].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[436].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[437].position = D3DXVECTOR3(-84.22f, -89.88f, 250.23f);
	cube[437].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[437].scale = D3DXVECTOR3(3, 1, 10);

	cube[438].position = D3DXVECTOR3(-82.93f, -89.93f, 250.36f);
	cube[438].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[438].scale = D3DXVECTOR3(3, 1, 7);

	cube[439].position = D3DXVECTOR3(-84.01f, -88.73f, 248.91f);
	cube[439].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[439].scale = D3DXVECTOR3(3, 1, 10);

	cube[440].position = D3DXVECTOR3(-82.69f, -88.84f, 249.10f);
	cube[440].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[440].scale = D3DXVECTOR3(5, 1, 7);

	cube[441].position = D3DXVECTOR3(-77.57f, -91.51f, 249.80f);
	cube[441].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[441].scale = D3DXVECTOR3(3, 1, 10);

	cube[442].position = D3DXVECTOR3(-76.30f, -91.57f, 249.71f);
	cube[442].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[442].scale = D3DXVECTOR3(3, 1, 7);

	cube[443].position = D3DXVECTOR3(-77.59f, -90.36f, 248.47f);
	cube[443].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[443].scale = D3DXVECTOR3(3, 1, 10);

	cube[444].position = D3DXVECTOR3(-76.26f, -90.48f, 248.43f);
	cube[444].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[444].scale = D3DXVECTOR3(5, 1, 7);

	cube[445].position = D3DXVECTOR3(-68.29f, -93.21f, 248.17f);
	cube[445].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[445].scale = D3DXVECTOR3(3, 1, 10);

	cube[446].position = D3DXVECTOR3(-68.32f, -92.06f, 246.83f);
	cube[446].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[446].scale = D3DXVECTOR3(3, 1, 10);

	cube[447].position = D3DXVECTOR3(-59.24f, -94.90f, 247.27f);
	cube[447].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[447].scale = D3DXVECTOR3(3, 1, 10);

	cube[448].position = D3DXVECTOR3(-59.03f, -93.75f, 245.95f);
	cube[448].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[448].scale = D3DXVECTOR3(3, 1, 10);

	cube[449].position = D3DXVECTOR3(-50.42f, -96.56f, 247.89f);
	cube[449].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[449].scale = D3DXVECTOR3(3, 1, 10);

	cube[450].position = D3DXVECTOR3(-49.98f, -95.41f, 246.63f);
	cube[450].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[450].scale = D3DXVECTOR3(3, 1, 10);

	cube[451].position = D3DXVECTOR3(-42.27f, -98.16f, 249.93f);
	cube[451].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[451].scale = D3DXVECTOR3(3, 1, 10);

	cube[452].position = D3DXVECTOR3(-41.62f, -97.01f, 248.76f);
	cube[452].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[452].scale = D3DXVECTOR3(3, 1, 10);

	cube[453].position = D3DXVECTOR3(-34.21f, -99.81f, 253.50f);
	cube[453].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[453].scale = D3DXVECTOR3(3, 1, 10);

	cube[454].position = D3DXVECTOR3(-33.37f, -98.66f, 252.46f);
	cube[454].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[454].scale = D3DXVECTOR3(3, 1, 10);

	cube[455].position = D3DXVECTOR3(-26.29f, -101.48f, 258.10f);
	cube[455].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[455].scale = D3DXVECTOR3(3, 1, 10);

	cube[456].position = D3DXVECTOR3(-25.45f, -100.33f, 257.06f);
	cube[456].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[456].scale = D3DXVECTOR3(3, 1, 10);

	cube[457].position = D3DXVECTOR3(-20.22f, -103.09f, 261.09f);
	cube[457].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[457].scale = D3DXVECTOR3(3, 1, 10);

	cube[458].position = D3DXVECTOR3(-19.51f, -103.19f, 261.67f);
	cube[458].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[458].scale = D3DXVECTOR3(3, 1, 7);

	cube[459].position = D3DXVECTOR3(-19.57f, -101.94f, 259.92f);
	cube[459].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[459].scale = D3DXVECTOR3(3, 1, 10);

	cube[460].position = D3DXVECTOR3(-18.51f, -101.95f, 260.40f);
	cube[460].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[460].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[461].position = D3DXVECTOR3(-14.07f, -104.68f, 262.89f);
	cube[461].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[461].scale = D3DXVECTOR3(3, 1, 10);

	cube[462].position = D3DXVECTOR3(-12.81f, -104.77f, 263.30f);
	cube[462].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[462].scale = D3DXVECTOR3(3, 1, 7);

	cube[463].position = D3DXVECTOR3(-13.63f, -103.53f, 261.62f);
	cube[463].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[463].scale = D3DXVECTOR3(3, 1, 10);

	cube[464].position = D3DXVECTOR3(-12.09f, -103.68f, 262.12f);
	cube[464].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[464].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[465].position = D3DXVECTOR3(-7.39f, -106.31f, 263.61f);
	cube[465].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[465].scale = D3DXVECTOR3(3, 1, 10);

	cube[466].position = D3DXVECTOR3(-6.10f, -106.36f, 263.74f);
	cube[466].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[466].scale = D3DXVECTOR3(3, 1, 7);

	cube[467].position = D3DXVECTOR3(-7.18f, -105.16f, 262.29f);
	cube[467].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[467].scale = D3DXVECTOR3(3, 1, 10);

	cube[468].position = D3DXVECTOR3(-5.86f, -105.27f, 262.48f);
	cube[468].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[468].scale = D3DXVECTOR3(5, 1, 7);

	cube[469].position = D3DXVECTOR3(-0.74f, -107.94f, 263.18f);
	cube[469].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[469].scale = D3DXVECTOR3(3, 1, 10);

	cube[470].position = D3DXVECTOR3(0.53f, -108.00f, 263.09f);
	cube[470].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[470].scale = D3DXVECTOR3(3, 1, 7);

	cube[471].position = D3DXVECTOR3(-0.76f, -106.79f, 261.85f);
	cube[471].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[471].scale = D3DXVECTOR3(3, 1, 10);

	cube[472].position = D3DXVECTOR3(0.57f, -106.91f, 261.81f);
	cube[472].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[472].scale = D3DXVECTOR3(5, 1, 7);

	cube[473].position = D3DXVECTOR3(8.39f, -109.66f, 261.62f);
	cube[473].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[473].scale = D3DXVECTOR3(3, 1, 10);

	cube[474].position = D3DXVECTOR3(8.36f, -108.51f, 260.28f);
	cube[474].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[474].scale = D3DXVECTOR3(3, 1, 10);

	cube[475].position = D3DXVECTOR3(17.44f, -111.35f, 260.72f);
	cube[475].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[475].scale = D3DXVECTOR3(3, 1, 10);

	cube[476].position = D3DXVECTOR3(17.65f, -110.20f, 259.40f);
	cube[476].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[476].scale = D3DXVECTOR3(3, 1, 10);

	cube[477].position = D3DXVECTOR3(26.26f, -113.01f, 261.34f);
	cube[477].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[477].scale = D3DXVECTOR3(3, 1, 10);

	cube[478].position = D3DXVECTOR3(26.70f, -111.86f, 260.08f);
	cube[478].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[478].scale = D3DXVECTOR3(3, 1, 10);

	cube[479].position = D3DXVECTOR3(34.41f, -114.61f, 263.38f);
	cube[479].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[479].scale = D3DXVECTOR3(3, 1, 10);

	cube[480].position = D3DXVECTOR3(35.06f, -113.46f, 262.21f);
	cube[480].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[480].scale = D3DXVECTOR3(3, 1, 10);

	cube[481].position = D3DXVECTOR3(42.47f, -116.26f, 266.95f);
	cube[481].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[481].scale = D3DXVECTOR3(3, 1, 10);

	cube[482].position = D3DXVECTOR3(43.31f, -115.11f, 265.91f);
	cube[482].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[482].scale = D3DXVECTOR3(3, 1, 10);

	cube[483].position = D3DXVECTOR3(50.43f, -118.00f, 271.54f);
	cube[483].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[483].scale = D3DXVECTOR3(3, 1, 10);

	cube[484].position = D3DXVECTOR3(51.27f, -116.85f, 270.50f);
	cube[484].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[484].scale = D3DXVECTOR3(3, 1, 10);

	cube[485].position = D3DXVECTOR3(58.46f, -119.69f, 276.19f);
	cube[485].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[485].scale = D3DXVECTOR3(3, 1, 10);

	cube[486].position = D3DXVECTOR3(59.30f, -118.54f, 275.15f);
	cube[486].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[486].scale = D3DXVECTOR3(3, 1, 10);

	cube[487].position = D3DXVECTOR3(66.72f, -121.41f, 280.95f);
	cube[487].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[487].scale = D3DXVECTOR3(3, 1, 10);

	cube[488].position = D3DXVECTOR3(67.56f, -120.26f, 279.91f);
	cube[488].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[488].scale = D3DXVECTOR3(3, 1, 10);

	cube[489].position = D3DXVECTOR3(74.84f, -123.11f, 285.62f);
	cube[489].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[489].scale = D3DXVECTOR3(3, 1, 10);

	cube[490].position = D3DXVECTOR3(75.68f, -121.96f, 284.58f);
	cube[490].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[490].scale = D3DXVECTOR3(3, 1, 10);

	cube[491].position = D3DXVECTOR3(82.94f, -124.78f, 290.28f);
	cube[491].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[491].scale = D3DXVECTOR3(3, 1, 10);

	cube[492].position = D3DXVECTOR3(83.78f, -123.63f, 289.24f);
	cube[492].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[492].scale = D3DXVECTOR3(3, 1, 10);

	cube[493].position = D3DXVECTOR3(91.24f, -126.48f, 295.06f);
	cube[493].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[493].scale = D3DXVECTOR3(3, 1, 10);

	cube[494].position = D3DXVECTOR3(92.08f, -125.33f, 294.02f);
	cube[494].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[494].scale = D3DXVECTOR3(3, 1, 10);

	cube[495].position = D3DXVECTOR3(98.81f, -128.05f, 299.38f);
	cube[495].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[495].scale = D3DXVECTOR3(3, 1, 10);

	cube[496].position = D3DXVECTOR3(99.65f, -126.90f, 298.34f);
	cube[496].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[496].scale = D3DXVECTOR3(3, 1, 10);

	cube[497].position = D3DXVECTOR3(106.33f, -129.74f, 304.51f);
	cube[497].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[497].scale = D3DXVECTOR3(3, 1, 10);

	cube[498].position = D3DXVECTOR3(107.33f, -128.59f, 303.64f);
	cube[498].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[498].scale = D3DXVECTOR3(3, 1, 10);

	cube[499].position = D3DXVECTOR3(112.68f, -131.40f, 310.66f);
	cube[499].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[499].scale = D3DXVECTOR3(3, 1, 10);

	cube[500].position = D3DXVECTOR3(113.83f, -130.25f, 309.97f);
	cube[500].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[500].scale = D3DXVECTOR3(3, 1, 10);

	cube[501].position = D3DXVECTOR3(117.61f, -133.00f, 317.45f);
	cube[501].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[501].scale = D3DXVECTOR3(3, 1, 10);

	cube[502].position = D3DXVECTOR3(118.86f, -131.85f, 316.98f);
	cube[502].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[502].scale = D3DXVECTOR3(3, 1, 10);

	cube[503].position = D3DXVECTOR3(121.49f, -134.65f, 325.38f);
	cube[503].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[503].scale = D3DXVECTOR3(3, 1, 10);

	cube[504].position = D3DXVECTOR3(122.81f, -133.50f, 325.12f);
	cube[504].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[504].scale = D3DXVECTOR3(3, 1, 10);

	cube[505].position = D3DXVECTOR3(124.72f, -136.34f, 334.22f);
	cube[505].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[505].scale = D3DXVECTOR3(3, 1, 10);

	cube[506].position = D3DXVECTOR3(126.03f, -135.19f, 333.97f);
	cube[506].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[506].scale = D3DXVECTOR3(3, 1, 10);

	cube[507].position = D3DXVECTOR3(127.80f, -138.00f, 342.69f);
	cube[507].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[507].scale = D3DXVECTOR3(3, 1, 10);

	cube[508].position = D3DXVECTOR3(129.11f, -136.85f, 342.44f);
	cube[508].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[508].scale = D3DXVECTOR3(3, 1, 10);

	cube[509].position = D3DXVECTOR3(130.92f, -139.65f, 351.14f);
	cube[509].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[509].scale = D3DXVECTOR3(3, 1, 10);

	cube[510].position = D3DXVECTOR3(132.24f, -138.50f, 350.89f);
	cube[510].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[510].scale = D3DXVECTOR3(3, 1, 10);

	cube[511].position = D3DXVECTOR3(133.38f, -141.34f, 359.90f);
	cube[511].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[511].scale = D3DXVECTOR3(3, 1, 10);

	cube[512].position = D3DXVECTOR3(134.72f, -140.19f, 359.88f);
	cube[512].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[512].scale = D3DXVECTOR3(3, 1, 10);

	cube[513].position = D3DXVECTOR3(134.30f, -143.00f, 368.70f);
	cube[513].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[513].scale = D3DXVECTOR3(3, 1, 10);

	cube[514].position = D3DXVECTOR3(135.62f, -141.85f, 368.91f);
	cube[514].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[514].scale = D3DXVECTOR3(3, 1, 10);

	cube[515].position = D3DXVECTOR3(133.71f, -144.60f, 377.07f);
	cube[515].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[515].scale = D3DXVECTOR3(3, 1, 10);

	cube[516].position = D3DXVECTOR3(134.97f, -143.45f, 377.51f);
	cube[516].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[516].scale = D3DXVECTOR3(3, 1, 10);

	cube[517].position = D3DXVECTOR3(131.59f, -146.25f, 385.64f);
	cube[517].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[517].scale = D3DXVECTOR3(3, 1, 10);

	cube[518].position = D3DXVECTOR3(132.76f, -145.10f, 386.29f);
	cube[518].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[518].scale = D3DXVECTOR3(3, 1, 10);

	cube[519].position = D3DXVECTOR3(128.27f, -147.98f, 394.71f);
	cube[519].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[519].scale = D3DXVECTOR3(3, 1, 10);

	cube[520].position = D3DXVECTOR3(129.44f, -146.83f, 395.36f);
	cube[520].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[520].scale = D3DXVECTOR3(3, 1, 10);

	cube[521].position = D3DXVECTOR3(125.14f, -149.64f, 403.23f);
	cube[521].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[521].scale = D3DXVECTOR3(3, 1, 10);

	cube[522].position = D3DXVECTOR3(126.31f, -148.49f, 403.87f);
	cube[522].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[522].scale = D3DXVECTOR3(3, 1, 10);

	cube[523].position = D3DXVECTOR3(123.25f, -151.25f, 409.72f);
	cube[523].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[523].scale = D3DXVECTOR3(3, 1, 10);

	cube[524].position = D3DXVECTOR3(122.80f, -151.35f, 410.53f);
	cube[524].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[524].scale = D3DXVECTOR3(3, 1, 7);

	cube[525].position = D3DXVECTOR3(124.52f, -150.10f, 410.15f);
	cube[525].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[525].scale = D3DXVECTOR3(3, 1, 10);

	cube[526].position = D3DXVECTOR3(124.23f, -150.11f, 411.29f);
	cube[526].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[526].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[527].position = D3DXVECTOR3(122.55f, -152.84f, 416.09f);
	cube[527].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[527].scale = D3DXVECTOR3(3, 1, 10);

	cube[528].position = D3DXVECTOR3(122.37f, -152.93f, 417.40f);
	cube[528].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[528].scale = D3DXVECTOR3(3, 1, 7);

	cube[529].position = D3DXVECTOR3(123.87f, -151.69f, 416.30f);
	cube[529].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[529].scale = D3DXVECTOR3(3, 1, 10);

	cube[530].position = D3DXVECTOR3(123.65f, -151.84f, 417.91f);
	cube[530].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[530].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[531].position = D3DXVECTOR3(122.99f, -154.47f, 422.79f);
	cube[531].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[531].scale = D3DXVECTOR3(3, 1, 10);

	cube[532].position = D3DXVECTOR3(123.09f, -154.52f, 424.08f);
	cube[532].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[532].scale = D3DXVECTOR3(3, 1, 7);

	cube[533].position = D3DXVECTOR3(124.33f, -153.32f, 422.77f);
	cube[533].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[533].scale = D3DXVECTOR3(3, 1, 10);

	cube[534].position = D3DXVECTOR3(124.37f, -153.43f, 424.10f);
	cube[534].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[534].scale = D3DXVECTOR3(5, 1, 7);

	cube[535].position = D3DXVECTOR3(124.57f, -156.10f, 429.27f);
	cube[535].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[535].scale = D3DXVECTOR3(3, 1, 10);

	cube[536].position = D3DXVECTOR3(124.89f, -156.16f, 430.50f);
	cube[536].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[536].scale = D3DXVECTOR3(3, 1, 7);

	cube[537].position = D3DXVECTOR3(125.88f, -154.95f, 429.01f);
	cube[537].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[537].scale = D3DXVECTOR3(3, 1, 10);

	cube[538].position = D3DXVECTOR3(126.16f, -155.07f, 430.32f);
	cube[538].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[538].scale = D3DXVECTOR3(5, 1, 7);

	cube[539].position = D3DXVECTOR3(127.70f, -157.77f, 437.90f);
	cube[539].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[539].scale = D3DXVECTOR3(3, 1, 10);

	cube[540].position = D3DXVECTOR3(129.02f, -156.62f, 437.65f);
	cube[540].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[540].scale = D3DXVECTOR3(3, 1, 10);

	cube[541].position = D3DXVECTOR3(130.16f, -159.46f, 446.66f);
	cube[541].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[541].scale = D3DXVECTOR3(3, 1, 10);

	cube[542].position = D3DXVECTOR3(131.50f, -158.31f, 446.64f);
	cube[542].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[542].scale = D3DXVECTOR3(3, 1, 10);

	cube[543].position = D3DXVECTOR3(131.08f, -161.12f, 455.46f);
	cube[543].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[543].scale = D3DXVECTOR3(3, 1, 10);

	cube[544].position = D3DXVECTOR3(132.40f, -159.97f, 455.67f);
	cube[544].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[544].scale = D3DXVECTOR3(3, 1, 10);

	cube[545].position = D3DXVECTOR3(130.49f, -162.72f, 463.83f);
	cube[545].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[545].scale = D3DXVECTOR3(3, 1, 10);

	cube[546].position = D3DXVECTOR3(131.75f, -161.57f, 464.27f);
	cube[546].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[546].scale = D3DXVECTOR3(3, 1, 10);

	cube[547].position = D3DXVECTOR3(128.37f, -164.37f, 472.40f);
	cube[547].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[547].scale = D3DXVECTOR3(3, 1, 10);

	cube[548].position = D3DXVECTOR3(129.54f, -163.22f, 473.05f);
	cube[548].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[548].scale = D3DXVECTOR3(3, 1, 10);

	cube[549].position = D3DXVECTOR3(125.14f, -166.07f, 481.29f);
	cube[549].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[549].scale = D3DXVECTOR3(3, 1, 10);

	cube[550].position = D3DXVECTOR3(126.31f, -164.92f, 481.94f);
	cube[550].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[550].scale = D3DXVECTOR3(3, 1, 10);

	cube[551].position = D3DXVECTOR3(121.89f, -167.79f, 490.24f);
	cube[551].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[551].scale = D3DXVECTOR3(3, 1, 10);

	cube[552].position = D3DXVECTOR3(123.06f, -166.64f, 490.89f);
	cube[552].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[552].scale = D3DXVECTOR3(3, 1, 10);

	cube[553].position = D3DXVECTOR3(118.76f, -169.44f, 498.80f);
	cube[553].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[553].scale = D3DXVECTOR3(3, 1, 10);

	cube[554].position = D3DXVECTOR3(119.93f, -168.29f, 499.44f);
	cube[554].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[554].scale = D3DXVECTOR3(3, 1, 10);

	cube[555].position = D3DXVECTOR3(116.87f, -171.05f, 505.29f);
	cube[555].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[555].scale = D3DXVECTOR3(3, 1, 10);

	cube[556].position = D3DXVECTOR3(116.42f, -171.15f, 506.10f);
	cube[556].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[556].scale = D3DXVECTOR3(3, 1, 7);

	cube[557].position = D3DXVECTOR3(118.14f, -169.90f, 505.72f);
	cube[557].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[557].scale = D3DXVECTOR3(3, 1, 10);

	cube[558].position = D3DXVECTOR3(117.85f, -169.91f, 506.86f);
	cube[558].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[558].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[559].position = D3DXVECTOR3(116.17f, -172.64f, 511.66f);
	cube[559].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[559].scale = D3DXVECTOR3(3, 1, 10);

	cube[560].position = D3DXVECTOR3(115.99f, -172.73f, 512.97f);
	cube[560].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[560].scale = D3DXVECTOR3(3, 1, 7);

	cube[561].position = D3DXVECTOR3(117.49f, -171.49f, 511.87f);
	cube[561].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[561].scale = D3DXVECTOR3(3, 1, 10);

	cube[562].position = D3DXVECTOR3(117.27f, -171.64f, 513.48f);
	cube[562].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[562].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[563].position = D3DXVECTOR3(116.61f, -174.27f, 518.36f);
	cube[563].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[563].scale = D3DXVECTOR3(3, 1, 10);

	cube[564].position = D3DXVECTOR3(116.71f, -174.32f, 519.65f);
	cube[564].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[564].scale = D3DXVECTOR3(3, 1, 7);

	cube[565].position = D3DXVECTOR3(117.95f, -173.12f, 518.34f);
	cube[565].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[565].scale = D3DXVECTOR3(3, 1, 10);

	cube[566].position = D3DXVECTOR3(117.99f, -173.23f, 519.67f);
	cube[566].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[566].scale = D3DXVECTOR3(5, 1, 7);

	cube[567].position = D3DXVECTOR3(118.19f, -175.90f, 524.84f);
	cube[567].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[567].scale = D3DXVECTOR3(3, 1, 10);

	cube[568].position = D3DXVECTOR3(118.51f, -175.96f, 526.07f);
	cube[568].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[568].scale = D3DXVECTOR3(3, 1, 7);

	cube[569].position = D3DXVECTOR3(119.51f, -174.75f, 524.58f);
	cube[569].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[569].scale = D3DXVECTOR3(3, 1, 10);

	cube[570].position = D3DXVECTOR3(119.78f, -174.87f, 525.89f);
	cube[570].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[570].scale = D3DXVECTOR3(5, 1, 7);

	cube[571].position = D3DXVECTOR3(121.47f, -177.62f, 533.83f);
	cube[571].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[571].scale = D3DXVECTOR3(3, 1, 10);

	cube[572].position = D3DXVECTOR3(122.78f, -176.47f, 533.58f);
	cube[572].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[572].scale = D3DXVECTOR3(3, 1, 10);

	cube[573].position = D3DXVECTOR3(124.75f, -179.35f, 542.83f);
	cube[573].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[573].scale = D3DXVECTOR3(3, 1, 10);

	cube[574].position = D3DXVECTOR3(126.06f, -178.20f, 542.58f);
	cube[574].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[574].scale = D3DXVECTOR3(3, 1, 10);

	cube[575].position = D3DXVECTOR3(127.97f, -181.04f, 551.67f);
	cube[575].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[575].scale = D3DXVECTOR3(3, 1, 10);

	cube[576].position = D3DXVECTOR3(129.28f, -179.89f, 551.42f);
	cube[576].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[576].scale = D3DXVECTOR3(3, 1, 10);

	cube[577].position = D3DXVECTOR3(131.14f, -182.72f, 560.40f);
	cube[577].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[577].scale = D3DXVECTOR3(3, 1, 10);

	cube[578].position = D3DXVECTOR3(132.45f, -181.57f, 560.15f);
	cube[578].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[578].scale = D3DXVECTOR3(3, 1, 10);

	cube[579].position = D3DXVECTOR3(134.30f, -184.40f, 569.07f);
	cube[579].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[579].scale = D3DXVECTOR3(3, 1, 10);

	cube[580].position = D3DXVECTOR3(135.61f, -183.25f, 568.82f);
	cube[580].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[580].scale = D3DXVECTOR3(3, 1, 10);

	cube[581].position = D3DXVECTOR3(137.54f, -186.14f, 578.00f);
	cube[581].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[581].scale = D3DXVECTOR3(3, 1, 10);

	cube[582].position = D3DXVECTOR3(138.85f, -184.99f, 577.75f);
	cube[582].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[582].scale = D3DXVECTOR3(3, 1, 10);

	cube[583].position = D3DXVECTOR3(140.77f, -187.84f, 586.88f);
	cube[583].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[583].scale = D3DXVECTOR3(3, 1, 10);

	cube[584].position = D3DXVECTOR3(142.08f, -186.69f, 586.63f);
	cube[584].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[584].scale = D3DXVECTOR3(3, 1, 10);

	cube[585].position = D3DXVECTOR3(143.94f, -189.54f, 595.68f);
	cube[585].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[585].scale = D3DXVECTOR3(3, 1, 10);

	cube[586].position = D3DXVECTOR3(145.25f, -188.39f, 595.43f);
	cube[586].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[586].scale = D3DXVECTOR3(3, 1, 10);

	cube[587].position = D3DXVECTOR3(146.66f, -191.15f, 601.87f);
	cube[587].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[587].scale = D3DXVECTOR3(3, 1, 10);

	cube[588].position = D3DXVECTOR3(146.84f, -191.25f, 602.78f);
	cube[588].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[588].scale = D3DXVECTOR3(3, 1, 7);

	cube[589].position = D3DXVECTOR3(147.91f, -190.00f, 601.39f);
	cube[589].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[589].scale = D3DXVECTOR3(3, 1, 10);

	cube[590].position = D3DXVECTOR3(148.42f, -190.01f, 602.44f);
	cube[590].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[590].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[591].position = D3DXVECTOR3(150.22f, -192.74f, 607.20f);
	cube[591].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[591].scale = D3DXVECTOR3(3, 1, 10);

	cube[592].position = D3DXVECTOR3(150.92f, -192.83f, 608.32f);
	cube[592].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[592].scale = D3DXVECTOR3(3, 1, 7);

	cube[593].position = D3DXVECTOR3(151.37f, -191.59f, 606.51f);
	cube[593].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[593].scale = D3DXVECTOR3(3, 1, 10);

	cube[594].position = D3DXVECTOR3(152.23f, -191.74f, 607.89f);
	cube[594].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[594].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[595].position = D3DXVECTOR3(154.87f, -194.37f, 612.05f);
	cube[595].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[595].scale = D3DXVECTOR3(3, 1, 10);

	cube[596].position = D3DXVECTOR3(155.78f, -194.42f, 612.97f);
	cube[596].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[596].scale = D3DXVECTOR3(3, 1, 7);

	cube[597].position = D3DXVECTOR3(155.88f, -193.22f, 611.17f);
	cube[597].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[597].scale = D3DXVECTOR3(3, 1, 10);

	cube[598].position = D3DXVECTOR3(156.77f, -193.33f, 612.17f);
	cube[598].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[598].scale = D3DXVECTOR3(5, 1, 7);

	cube[599].position = D3DXVECTOR3(160.24f, -196.00f, 616.00f);
	cube[599].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[599].scale = D3DXVECTOR3(3, 1, 10);

	cube[600].position = D3DXVECTOR3(161.28f, -196.06f, 616.74f);
	cube[600].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[600].scale = D3DXVECTOR3(3, 1, 7);

	cube[601].position = D3DXVECTOR3(161.08f, -194.85f, 614.96f);
	cube[601].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[601].scale = D3DXVECTOR3(3, 1, 10);

	cube[602].position = D3DXVECTOR3(162.13f, -194.97f, 615.78f);
	cube[602].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[602].scale = D3DXVECTOR3(5, 1, 7);

	cube[603].position = D3DXVECTOR3(166.18f, -197.60f, 618.93f);
	cube[603].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[603].scale = D3DXVECTOR3(3, 1, 10);

	cube[604].position = D3DXVECTOR3(167.22f, -197.65f, 619.44f);
	cube[604].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[604].scale = D3DXVECTOR3(3, 1, 7);

	cube[605].position = D3DXVECTOR3(166.83f, -196.45f, 617.76f);
	cube[605].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[605].scale = D3DXVECTOR3(3, 1, 10);

	cube[606].position = D3DXVECTOR3(167.90f, -196.55f, 618.36f);
	cube[606].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[606].scale = D3DXVECTOR3(5, 1, 7);

	cube[607].position = D3DXVECTOR3(172.60f, -199.24f, 620.81f);
	cube[607].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[607].scale = D3DXVECTOR3(3, 1, 10);

	cube[608].position = D3DXVECTOR3(173.57f, -199.25f, 621.11f);
	cube[608].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[608].scale = D3DXVECTOR3(3, 1, 7);

	cube[609].position = D3DXVECTOR3(173.04f, -198.09f, 619.54f);
	cube[609].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[609].scale = D3DXVECTOR3(3, 1, 10);

	cube[610].position = D3DXVECTOR3(174.28f, -198.18f, 619.96f);
	cube[610].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[610].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[611].position = D3DXVECTOR3(179.05f, -200.90f, 621.45f);
	cube[611].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[611].scale = D3DXVECTOR3(3, 1, 10);

	cube[612].position = D3DXVECTOR3(180.30f, -200.91f, 621.61f);
	cube[612].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[612].scale = D3DXVECTOR3(3, 1, 7);

	cube[613].position = D3DXVECTOR3(179.26f, -199.75f, 620.13f);
	cube[613].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[613].scale = D3DXVECTOR3(3, 1, 10);

	cube[614].position = D3DXVECTOR3(180.80f, -199.88f, 620.35f);
	cube[614].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[614].scale = D3DXVECTOR3(5, 1, 6.500004);

	cube[615].position = D3DXVECTOR3(185.25f, -202.44f, 621.05f);
	cube[615].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[615].scale = D3DXVECTOR3(3, 1, 10);

	cube[616].position = D3DXVECTOR3(186.49f, -202.48f, 620.98f);
	cube[616].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[616].scale = D3DXVECTOR3(3, 1, 7);

	cube[617].position = D3DXVECTOR3(185.22f, -201.29f, 619.72f);
	cube[617].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[617].scale = D3DXVECTOR3(3, 1, 10);

	cube[618].position = D3DXVECTOR3(186.75f, -201.43f, 619.65f);
	cube[618].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[618].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[619].position = D3DXVECTOR3(194.44f, -204.11f, 619.43f);
	cube[619].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[619].scale = D3DXVECTOR3(3, 1, 10);

	cube[620].position = D3DXVECTOR3(194.42f, -202.96f, 618.10f);
	cube[620].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[620].scale = D3DXVECTOR3(3, 1, 10);

	cube[621].position = D3DXVECTOR3(203.77f, -205.80f, 617.79f);
	cube[621].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[621].scale = D3DXVECTOR3(3, 1, 10);

	cube[622].position = D3DXVECTOR3(203.75f, -204.65f, 616.46f);
	cube[622].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[622].scale = D3DXVECTOR3(3, 1, 10);

	cube[623].position = D3DXVECTOR3(212.68f, -207.42f, 616.25f);
	cube[623].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[623].scale = D3DXVECTOR3(3, 1, 10);

	cube[624].position = D3DXVECTOR3(212.65f, -206.27f, 614.91f);
	cube[624].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[624].scale = D3DXVECTOR3(3, 1, 10);

	cube[625].position = D3DXVECTOR3(221.73f, -209.11f, 615.35f);
	cube[625].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[625].scale = D3DXVECTOR3(3, 1, 10);

	cube[626].position = D3DXVECTOR3(221.94f, -207.96f, 614.03f);
	cube[626].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[626].scale = D3DXVECTOR3(3, 1, 10);

	cube[627].position = D3DXVECTOR3(230.55f, -210.77f, 615.97f);
	cube[627].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[627].scale = D3DXVECTOR3(3, 1, 10);

	cube[628].position = D3DXVECTOR3(230.99f, -209.62f, 614.71f);
	cube[628].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[628].scale = D3DXVECTOR3(3, 1, 10);

	cube[629].position = D3DXVECTOR3(238.70f, -212.37f, 618.01f);
	cube[629].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[629].scale = D3DXVECTOR3(3, 1, 10);

	cube[630].position = D3DXVECTOR3(239.35f, -211.22f, 616.84f);
	cube[630].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[630].scale = D3DXVECTOR3(3, 1, 10);

	cube[631].position = D3DXVECTOR3(246.76f, -214.02f, 621.58f);
	cube[631].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[631].scale = D3DXVECTOR3(3, 1, 10);

	cube[632].position = D3DXVECTOR3(247.60f, -212.87f, 620.54f);
	cube[632].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[632].scale = D3DXVECTOR3(3, 1, 10);

	cube[633].position = D3DXVECTOR3(254.19f, -215.73f, 626.67f);
	cube[633].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[633].scale = D3DXVECTOR3(3, 1, 10);

	cube[634].position = D3DXVECTOR3(255.19f, -214.58f, 625.80f);
	cube[634].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[634].scale = D3DXVECTOR3(3, 1, 10);

	cube[635].position = D3DXVECTOR3(260.43f, -217.36f, 632.70f);
	cube[635].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[635].scale = D3DXVECTOR3(3, 1, 10);

	cube[636].position = D3DXVECTOR3(261.58f, -216.21f, 632.01f);
	cube[636].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[636].scale = D3DXVECTOR3(3, 1, 10);

	cube[637].position = D3DXVECTOR3(265.63f, -218.99f, 639.91f);
	cube[637].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[637].scale = D3DXVECTOR3(3, 1, 10);

	cube[638].position = D3DXVECTOR3(266.88f, -217.84f, 639.43f);
	cube[638].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[638].scale = D3DXVECTOR3(3, 1, 10);

	cube[639].position = D3DXVECTOR3(269.39f, -220.55f, 647.58f);
	cube[639].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[639].scale = D3DXVECTOR3(3, 1, 10);

	cube[640].position = D3DXVECTOR3(270.70f, -219.40f, 647.33f);
	cube[640].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[640].scale = D3DXVECTOR3(3, 1, 10);

	cube[641].position = D3DXVECTOR3(272.57f, -222.22f, 656.28f);
	cube[641].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[641].scale = D3DXVECTOR3(3, 1, 10);

	cube[642].position = D3DXVECTOR3(273.88f, -221.07f, 656.03f);
	cube[642].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[642].scale = D3DXVECTOR3(3, 1, 10);

	cube[643].position = D3DXVECTOR3(275.83f, -223.92f, 665.25f);
	cube[643].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[643].scale = D3DXVECTOR3(3, 1, 10);

	cube[644].position = D3DXVECTOR3(277.14f, -222.77f, 665.00f);
	cube[644].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[644].scale = D3DXVECTOR3(3, 1, 10);

	cube[645].position = D3DXVECTOR3(279.09f, -225.69f, 674.19f);
	cube[645].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[645].scale = D3DXVECTOR3(3, 1, 10);

	cube[646].position = D3DXVECTOR3(280.40f, -224.54f, 673.94f);
	cube[646].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[646].scale = D3DXVECTOR3(3, 1, 10);

	cube[647].position = D3DXVECTOR3(281.81f, -227.30f, 680.38f);
	cube[647].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[647].scale = D3DXVECTOR3(3, 1, 10);

	cube[648].position = D3DXVECTOR3(281.99f, -227.40f, 681.29f);
	cube[648].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[648].scale = D3DXVECTOR3(3, 1, 7);

	cube[649].position = D3DXVECTOR3(283.06f, -226.15f, 679.90f);
	cube[649].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[649].scale = D3DXVECTOR3(3, 1, 10);

	cube[650].position = D3DXVECTOR3(283.57f, -226.16f, 680.95f);
	cube[650].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[650].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[651].position = D3DXVECTOR3(285.37f, -228.89f, 685.71f);
	cube[651].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[651].scale = D3DXVECTOR3(3, 1, 10);

	cube[652].position = D3DXVECTOR3(286.07f, -228.98f, 686.83f);
	cube[652].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[652].scale = D3DXVECTOR3(3, 1, 7);

	cube[653].position = D3DXVECTOR3(286.52f, -227.74f, 685.02f);
	cube[653].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[653].scale = D3DXVECTOR3(3, 1, 10);

	cube[654].position = D3DXVECTOR3(287.38f, -227.89f, 686.40f);
	cube[654].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[654].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[655].position = D3DXVECTOR3(290.02f, -230.52f, 690.56f);
	cube[655].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[655].scale = D3DXVECTOR3(3, 1, 10);

	cube[656].position = D3DXVECTOR3(290.93f, -230.57f, 691.48f);
	cube[656].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[656].scale = D3DXVECTOR3(3, 1, 7);

	cube[657].position = D3DXVECTOR3(291.03f, -229.37f, 689.68f);
	cube[657].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[657].scale = D3DXVECTOR3(3, 1, 10);

	cube[658].position = D3DXVECTOR3(291.92f, -229.48f, 690.68f);
	cube[658].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[658].scale = D3DXVECTOR3(5, 1, 7);

	cube[659].position = D3DXVECTOR3(295.39f, -232.15f, 694.51f);
	cube[659].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[659].scale = D3DXVECTOR3(3, 1, 10);

	cube[660].position = D3DXVECTOR3(296.43f, -232.21f, 695.25f);
	cube[660].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[660].scale = D3DXVECTOR3(3, 1, 7);

	cube[661].position = D3DXVECTOR3(296.23f, -231.00f, 693.47f);
	cube[661].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[661].scale = D3DXVECTOR3(3, 1, 10);

	cube[662].position = D3DXVECTOR3(297.28f, -231.12f, 694.29f);
	cube[662].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[662].scale = D3DXVECTOR3(5, 1, 7);

	cube[663].position = D3DXVECTOR3(301.33f, -233.75f, 697.44f);
	cube[663].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[663].scale = D3DXVECTOR3(3, 1, 10);

	cube[664].position = D3DXVECTOR3(302.37f, -233.80f, 697.95f);
	cube[664].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[664].scale = D3DXVECTOR3(3, 1, 7);

	cube[665].position = D3DXVECTOR3(301.98f, -232.60f, 696.27f);
	cube[665].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[665].scale = D3DXVECTOR3(3, 1, 10);

	cube[666].position = D3DXVECTOR3(303.05f, -232.70f, 696.87f);
	cube[666].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[666].scale = D3DXVECTOR3(5, 1, 7);

	cube[667].position = D3DXVECTOR3(307.75f, -235.39f, 699.32f);
	cube[667].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[667].scale = D3DXVECTOR3(3, 1, 10);

	cube[668].position = D3DXVECTOR3(308.72f, -235.40f, 699.62f);
	cube[668].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[668].scale = D3DXVECTOR3(3, 1, 7);

	cube[669].position = D3DXVECTOR3(308.19f, -234.24f, 698.05f);
	cube[669].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[669].scale = D3DXVECTOR3(3, 1, 10);

	cube[670].position = D3DXVECTOR3(309.43f, -234.33f, 698.47f);
	cube[670].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[670].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[671].position = D3DXVECTOR3(314.20f, -237.05f, 699.96f);
	cube[671].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[671].scale = D3DXVECTOR3(3, 1, 10);

	cube[672].position = D3DXVECTOR3(315.45f, -237.06f, 700.12f);
	cube[672].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[672].scale = D3DXVECTOR3(3, 1, 7);

	cube[673].position = D3DXVECTOR3(314.41f, -235.90f, 698.64f);
	cube[673].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[673].scale = D3DXVECTOR3(3, 1, 10);

	cube[674].position = D3DXVECTOR3(315.95f, -236.03f, 698.86f);
	cube[674].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[674].scale = D3DXVECTOR3(5, 1, 6.500004);

	cube[675].position = D3DXVECTOR3(320.40f, -238.59f, 699.56f);
	cube[675].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[675].scale = D3DXVECTOR3(3, 1, 10);

	cube[676].position = D3DXVECTOR3(321.64f, -238.63f, 699.49f);
	cube[676].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[676].scale = D3DXVECTOR3(3, 1, 7);

	cube[677].position = D3DXVECTOR3(320.37f, -237.44f, 698.23f);
	cube[677].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[677].scale = D3DXVECTOR3(3, 1, 10);

	cube[678].position = D3DXVECTOR3(321.90f, -237.58f, 698.16f);
	cube[678].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[678].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[679].position = D3DXVECTOR3(329.76f, -240.35f, 697.93f);
	cube[679].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[679].scale = D3DXVECTOR3(3, 1, 10);

	cube[680].position = D3DXVECTOR3(329.73f, -239.20f, 696.59f);
	cube[680].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[680].scale = D3DXVECTOR3(3, 1, 10);

	cube[681].position = D3DXVECTOR3(336.32f, -241.96f, 696.32f);
	cube[681].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[681].scale = D3DXVECTOR3(3, 1, 10);

	cube[682].position = D3DXVECTOR3(337.25f, -242.06f, 696.30f);
	cube[682].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[682].scale = D3DXVECTOR3(3, 1, 7);

	cube[683].position = D3DXVECTOR3(336.07f, -240.81f, 695.01f);
	cube[683].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[683].scale = D3DXVECTOR3(3, 1, 10);

	cube[684].position = D3DXVECTOR3(337.20f, -240.82f, 694.69f);
	cube[684].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[684].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[685].position = D3DXVECTOR3(342.19f, -243.55f, 693.74f);
	cube[685].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[685].scale = D3DXVECTOR3(3, 1, 10);

	cube[686].position = D3DXVECTOR3(343.42f, -243.64f, 693.25f);
	cube[686].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[686].scale = D3DXVECTOR3(3, 1, 7);

	cube[687].position = D3DXVECTOR3(341.72f, -242.40f, 692.49f);
	cube[687].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[687].scale = D3DXVECTOR3(3, 1, 10);

	cube[688].position = D3DXVECTOR3(343.22f, -242.55f, 691.88f);
	cube[688].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[688].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[689].position = D3DXVECTOR3(347.77f, -245.18f, 690.01f);
	cube[689].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[689].scale = D3DXVECTOR3(3, 1, 10);

	cube[690].position = D3DXVECTOR3(348.84f, -245.23f, 689.27f);
	cube[690].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[690].scale = D3DXVECTOR3(3, 1, 7);

	cube[691].position = D3DXVECTOR3(347.08f, -244.03f, 688.86f);
	cube[691].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[691].scale = D3DXVECTOR3(3, 1, 10);

	cube[692].position = D3DXVECTOR3(348.22f, -244.14f, 688.15f);
	cube[692].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[692].scale = D3DXVECTOR3(5, 1, 7);

	cube[693].position = D3DXVECTOR3(352.59f, -246.81f, 685.40f);
	cube[693].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[693].scale = D3DXVECTOR3(3, 1, 10);

	cube[694].position = D3DXVECTOR3(353.51f, -246.87f, 684.51f);
	cube[694].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[694].scale = D3DXVECTOR3(3, 1, 7);

	cube[695].position = D3DXVECTOR3(351.72f, -245.66f, 684.39f);
	cube[695].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[695].scale = D3DXVECTOR3(3, 1, 10);

	cube[696].position = D3DXVECTOR3(352.71f, -245.78f, 683.50f);
	cube[696].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[696].scale = D3DXVECTOR3(5, 1, 7);

	cube[697].position = D3DXVECTOR3(356.51f, -248.41f, 680.06f);
	cube[697].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[697].scale = D3DXVECTOR3(3, 1, 10);

	cube[698].position = D3DXVECTOR3(357.20f, -248.46f, 679.13f);
	cube[698].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[698].scale = D3DXVECTOR3(3, 1, 7);

	cube[699].position = D3DXVECTOR3(355.48f, -247.26f, 679.22f);
	cube[699].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[699].scale = D3DXVECTOR3(3, 1, 10);

	cube[700].position = D3DXVECTOR3(356.25f, -247.36f, 678.27f);
	cube[700].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[700].scale = D3DXVECTOR3(5, 1, 7);

	cube[701].position = D3DXVECTOR3(359.48f, -250.05f, 674.06f);
	cube[701].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[701].scale = D3DXVECTOR3(3, 1, 10);

	cube[702].position = D3DXVECTOR3(359.94f, -250.06f, 673.16f);
	cube[702].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[702].scale = D3DXVECTOR3(3, 1, 7);

	cube[703].position = D3DXVECTOR3(358.31f, -248.90f, 673.41f);
	cube[703].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[703].scale = D3DXVECTOR3(3, 1, 10);

	cube[704].position = D3DXVECTOR3(358.93f, -248.99f, 672.26f);
	cube[704].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[704].scale = D3DXVECTOR3(5, 1, 6.500005);

	cube[705].position = D3DXVECTOR3(361.23f, -251.71f, 667.83f);
	cube[705].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[705].scale = D3DXVECTOR3(3, 1, 9.99999);

	cube[706].position = D3DXVECTOR3(361.60f, -251.72f, 666.62f);
	cube[706].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[706].scale = D3DXVECTOR3(3, 1, 7);

	cube[707].position = D3DXVECTOR3(359.97f, -250.56f, 667.39f);
	cube[707].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[707].scale = D3DXVECTOR3(3, 1, 10);

	cube[708].position = D3DXVECTOR3(360.45f, -250.69f, 665.91f);
	cube[708].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[708].scale = D3DXVECTOR3(5, 1, 6.500006);

	cube[709].position = D3DXVECTOR3(361.92f, -253.25f, 661.66f);
	cube[709].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[709].scale = D3DXVECTOR3(3, 1, 10);

	cube[710].position = D3DXVECTOR3(362.06f, -253.29f, 660.42f);
	cube[710].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[710].scale = D3DXVECTOR3(3, 1, 7);

	cube[711].position = D3DXVECTOR3(360.60f, -252.10f, 661.45f);
	cube[711].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[711].scale = D3DXVECTOR3(3, 1, 10);

	cube[712].position = D3DXVECTOR3(360.80f, -252.24f, 659.93f);
	cube[712].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[712].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[713].position = D3DXVECTOR3(361.91f, -254.93f, 652.29f);
	cube[713].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[713].scale = D3DXVECTOR3(3, 1, 10);

	cube[714].position = D3DXVECTOR3(360.59f, -253.78f, 652.08f);
	cube[714].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[714].scale = D3DXVECTOR3(3, 1, 10);

	cube[715].position = D3DXVECTOR3(361.91f, -256.68f, 642.75f);
	cube[715].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[715].scale = D3DXVECTOR3(3, 1, 10);

	cube[716].position = D3DXVECTOR3(360.59f, -255.53f, 642.54f);
	cube[716].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[716].scale = D3DXVECTOR3(3, 1, 10);

	cube[717].position = D3DXVECTOR3(361.91f, -258.38f, 633.36f);
	cube[717].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[717].scale = D3DXVECTOR3(3, 1, 10);

	cube[718].position = D3DXVECTOR3(360.59f, -257.23f, 633.15f);
	cube[718].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[718].scale = D3DXVECTOR3(3, 1, 10);

	cube[719].position = D3DXVECTOR3(361.91f, -260.03f, 624.20f);
	cube[719].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[719].scale = D3DXVECTOR3(3, 1, 10);

	cube[720].position = D3DXVECTOR3(360.59f, -258.88f, 623.99f);
	cube[720].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[720].scale = D3DXVECTOR3(3, 1, 10);

	cube[721].position = D3DXVECTOR3(361.91f, -261.77f, 614.62f);
	cube[721].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[721].scale = D3DXVECTOR3(3, 1, 10);

	cube[722].position = D3DXVECTOR3(360.59f, -260.62f, 614.41f);
	cube[722].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[722].scale = D3DXVECTOR3(3, 1, 10);

	cube[723].position = D3DXVECTOR3(361.91f, -263.35f, 605.90f);
	cube[723].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[723].scale = D3DXVECTOR3(3, 1, 10);

	cube[724].position = D3DXVECTOR3(360.59f, -262.20f, 605.69f);
	cube[724].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[724].scale = D3DXVECTOR3(3, 1, 10);

	cube[725].position = D3DXVECTOR3(361.46f, -264.96f, 599.15f);
	cube[725].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[725].scale = D3DXVECTOR3(3, 1, 10);

	cube[726].position = D3DXVECTOR3(361.61f, -265.06f, 598.24f);
	cube[726].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[726].scale = D3DXVECTOR3(3, 1, 7);

	cube[727].position = D3DXVECTOR3(360.12f, -263.81f, 599.17f);
	cube[727].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[727].scale = D3DXVECTOR3(3, 1, 10);

	cube[728].position = D3DXVECTOR3(360.01f, -263.82f, 598.01f);
	cube[728].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[728].scale = D3DXVECTOR3(5, 1, 6.499998);

	cube[729].position = D3DXVECTOR3(359.94f, -266.55f, 592.92f);
	cube[729].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[729].scale = D3DXVECTOR3(3, 1, 10);

	cube[730].position = D3DXVECTOR3(359.67f, -266.64f, 591.63f);
	cube[730].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[730].scale = D3DXVECTOR3(3, 1, 7);

	cube[731].position = D3DXVECTOR3(358.63f, -265.40f, 593.17f);
	cube[731].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[731].scale = D3DXVECTOR3(3, 1, 10);

	cube[732].position = D3DXVECTOR3(358.29f, -265.55f, 591.59f);
	cube[732].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[732].scale = D3DXVECTOR3(5, 1, 6.499999);

	cube[733].position = D3DXVECTOR3(357.23f, -268.18f, 586.78f);
	cube[733].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[733].scale = D3DXVECTOR3(3, 1, 10);

	cube[734].position = D3DXVECTOR3(356.70f, -268.23f, 585.60f);
	cube[734].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[734].scale = D3DXVECTOR3(3, 1, 7);

	cube[735].position = D3DXVECTOR3(355.98f, -267.03f, 587.26f);
	cube[735].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[735].scale = D3DXVECTOR3(3, 1, 10);

	cube[736].position = D3DXVECTOR3(355.49f, -267.14f, 586.02f);
	cube[736].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[736].scale = D3DXVECTOR3(5, 1, 7);

	cube[737].position = D3DXVECTOR3(353.53f, -269.81f, 581.23f);
	cube[737].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[737].scale = D3DXVECTOR3(3, 1, 10);

	cube[738].position = D3DXVECTOR3(352.82f, -269.87f, 580.18f);
	cube[738].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[738].scale = D3DXVECTOR3(3, 1, 7);

	cube[739].position = D3DXVECTOR3(352.39f, -268.66f, 581.92f);
	cube[739].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[739].scale = D3DXVECTOR3(3, 1, 10);

	cube[740].position = D3DXVECTOR3(351.69f, -268.78f, 580.79f);
	cube[740].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[740].scale = D3DXVECTOR3(5, 1, 7);

	cube[741].position = D3DXVECTOR3(347.57f, -271.49f, 574.13f);
	cube[741].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[741].scale = D3DXVECTOR3(3, 1, 10);

	cube[742].position = D3DXVECTOR3(346.43f, -270.34f, 574.81f);
	cube[742].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[742].scale = D3DXVECTOR3(3, 1, 10);

	cube[743].position = D3DXVECTOR3(342.27f, -273.18f, 566.73f);
	cube[743].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[743].scale = D3DXVECTOR3(3, 1, 10);

	cube[744].position = D3DXVECTOR3(341.02f, -272.03f, 567.21f);
	cube[744].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[744].scale = D3DXVECTOR3(3, 1, 10);

	cube[745].position = D3DXVECTOR3(338.39f, -274.84f, 558.79f);
	cube[745].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[745].scale = D3DXVECTOR3(3, 1, 10);

	cube[746].position = D3DXVECTOR3(337.08f, -273.69f, 559.04f);
	cube[746].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[746].scale = D3DXVECTOR3(3, 1, 10);

	cube[747].position = D3DXVECTOR3(336.09f, -276.44f, 550.71f);
	cube[747].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[747].scale = D3DXVECTOR3(3, 1, 10);

	cube[748].position = D3DXVECTOR3(334.75f, -275.29f, 550.73f);
	cube[748].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[748].scale = D3DXVECTOR3(3, 1, 10);

	cube[749].position = D3DXVECTOR3(335.15f, -278.09f, 541.94f);
	cube[749].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[749].scale = D3DXVECTOR3(3, 1, 10);

	cube[750].position = D3DXVECTOR3(333.83f, -276.94f, 541.73f);
	cube[750].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[750].scale = D3DXVECTOR3(3, 1, 10);

	cube[751].position = D3DXVECTOR3(335.15f, -279.75f, 532.61f);
	cube[751].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[751].scale = D3DXVECTOR3(3, 1, 10);

	cube[752].position = D3DXVECTOR3(333.83f, -278.60f, 532.40f);
	cube[752].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[752].scale = D3DXVECTOR3(3, 1, 10);

	cube[753].position = D3DXVECTOR3(335.15f, -281.44f, 523.16f);
	cube[753].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[753].scale = D3DXVECTOR3(3, 1, 10);

	cube[754].position = D3DXVECTOR3(333.83f, -280.29f, 522.95f);
	cube[754].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[754].scale = D3DXVECTOR3(3, 1, 10);

	cube[755].position = D3DXVECTOR3(335.15f, -282.99f, 514.73f);
	cube[755].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[755].scale = D3DXVECTOR3(3, 1, 10);

	cube[756].position = D3DXVECTOR3(333.83f, -281.84f, 514.52f);
	cube[756].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[756].scale = D3DXVECTOR3(3, 1, 10);

	cube[757].position = D3DXVECTOR3(335.84f, -284.68f, 505.65f);
	cube[757].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[757].scale = D3DXVECTOR3(3, 1, 10);

	cube[758].position = D3DXVECTOR3(334.58f, -283.53f, 505.22f);
	cube[758].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[758].scale = D3DXVECTOR3(3, 1, 10);

	cube[759].position = D3DXVECTOR3(337.98f, -286.34f, 497.07f);
	cube[759].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[759].scale = D3DXVECTOR3(3, 1, 10);

	cube[760].position = D3DXVECTOR3(336.81f, -285.19f, 496.43f);
	cube[760].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[760].scale = D3DXVECTOR3(3, 1, 10);

	cube[761].position = D3DXVECTOR3(341.41f, -287.94f, 489.41f);
	cube[761].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[761].scale = D3DXVECTOR3(3, 1, 10);

	cube[762].position = D3DXVECTOR3(340.37f, -286.79f, 488.57f);
	cube[762].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[762].scale = D3DXVECTOR3(3, 1, 10);

	cube[763].position = D3DXVECTOR3(346.33f, -289.59f, 482.09f);
	cube[763].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[763].scale = D3DXVECTOR3(3, 1, 10);

	cube[764].position = D3DXVECTOR3(345.45f, -288.44f, 481.08f);
	cube[764].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[764].scale = D3DXVECTOR3(3, 1, 10);

	cube[765].position = D3DXVECTOR3(352.47f, -291.31f, 474.74f);
	cube[765].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[765].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[766].position = D3DXVECTOR3(351.59f, -290.16f, 473.73f);
	cube[766].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[766].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[767].position = D3DXVECTOR3(358.52f, -293.01f, 467.53f);
	cube[767].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[767].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[768].position = D3DXVECTOR3(357.64f, -291.86f, 466.52f);
	cube[768].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[768].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[769].position = D3DXVECTOR3(364.64f, -294.74f, 460.23f);
	cube[769].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[769].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[770].position = D3DXVECTOR3(363.76f, -293.59f, 459.22f);
	cube[770].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[770].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[771].position = D3DXVECTOR3(370.75f, -296.49f, 453.00f);
	cube[771].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[771].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[772].position = D3DXVECTOR3(369.88f, -295.34f, 451.99f);
	cube[772].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[772].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[773].position = D3DXVECTOR3(377.11f, -298.18f, 446.49f);
	cube[773].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[773].scale = D3DXVECTOR3(3, 1, 10);

	cube[774].position = D3DXVECTOR3(376.42f, -297.03f, 445.35f);
	cube[774].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[774].scale = D3DXVECTOR3(3, 1, 10);

	cube[775].position = D3DXVECTOR3(384.27f, -299.84f, 441.30f);
	cube[775].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[775].scale = D3DXVECTOR3(3, 1, 10);

	cube[776].position = D3DXVECTOR3(383.79f, -298.69f, 440.05f);
	cube[776].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[776].scale = D3DXVECTOR3(3, 1, 10);

	cube[777].position = D3DXVECTOR3(391.82f, -301.44f, 437.63f);
	cube[777].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[777].scale = D3DXVECTOR3(3, 1, 10);

	cube[778].position = D3DXVECTOR3(391.56f, -300.29f, 436.31f);
	cube[778].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[778].scale = D3DXVECTOR3(3, 1, 10);

	cube[779].position = D3DXVECTOR3(400.29f, -303.09f, 435.18f);
	cube[779].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[779].scale = D3DXVECTOR3(3, 1, 10);

	cube[780].position = D3DXVECTOR3(400.27f, -301.94f, 433.84f);
	cube[780].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[780].scale = D3DXVECTOR3(3, 1, 10);

	cube[781].position = D3DXVECTOR3(409.25f, -304.80f, 434.31f);
	cube[781].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[781].scale = D3DXVECTOR3(3, 1, 10);

	cube[782].position = D3DXVECTOR3(409.46f, -303.65f, 432.99f);
	cube[782].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[782].scale = D3DXVECTOR3(3, 1, 10);

	cube[783].position = D3DXVECTOR3(417.91f, -306.43f, 434.91f);
	cube[783].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[783].scale = D3DXVECTOR3(3, 1, 10);

	cube[784].position = D3DXVECTOR3(418.35f, -305.28f, 433.65f);
	cube[784].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[784].scale = D3DXVECTOR3(3, 1, 10);

	cube[785].position = D3DXVECTOR3(427.09f, -308.11f, 436.54f);
	cube[785].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[785].scale = D3DXVECTOR3(3, 1, 10);

	cube[786].position = D3DXVECTOR3(427.53f, -306.96f, 435.27f);
	cube[786].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[786].scale = D3DXVECTOR3(3, 1, 10);

	cube[787].position = D3DXVECTOR3(436.64f, -309.87f, 438.22f);
	cube[787].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[787].scale = D3DXVECTOR3(3, 1, 10);

	cube[788].position = D3DXVECTOR3(437.08f, -308.72f, 436.95f);
	cube[788].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[788].scale = D3DXVECTOR3(3, 1, 10);

	cube[789].position = D3DXVECTOR3(446.02f, -311.59f, 439.88f);
	cube[789].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[789].scale = D3DXVECTOR3(3, 1, 10);

	cube[790].position = D3DXVECTOR3(446.46f, -310.44f, 438.61f);
	cube[790].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[790].scale = D3DXVECTOR3(3, 1, 10);

	cube[791].position = D3DXVECTOR3(455.46f, -313.32f, 441.54f);
	cube[791].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[791].scale = D3DXVECTOR3(3, 1, 10);

	cube[792].position = D3DXVECTOR3(455.90f, -312.17f, 440.27f);
	cube[792].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[792].scale = D3DXVECTOR3(3, 1, 10);

	cube[793].position = D3DXVECTOR3(464.86f, -315.03f, 443.21f);
	cube[793].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[793].scale = D3DXVECTOR3(3, 1, 10);

	cube[794].position = D3DXVECTOR3(465.30f, -313.88f, 441.94f);
	cube[794].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[794].scale = D3DXVECTOR3(3, 1, 10);

	cube[795].position = D3DXVECTOR3(474.41f, -316.77f, 444.88f);
	cube[795].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[795].scale = D3DXVECTOR3(3, 1, 10);

	cube[796].position = D3DXVECTOR3(474.85f, -315.62f, 443.61f);
	cube[796].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[796].scale = D3DXVECTOR3(3, 1, 10);

	cube[797].position = D3DXVECTOR3(483.70f, -318.45f, 446.52f);
	cube[797].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[797].scale = D3DXVECTOR3(3, 1, 10);

	cube[798].position = D3DXVECTOR3(484.14f, -317.30f, 445.25f);
	cube[798].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[798].scale = D3DXVECTOR3(3, 1, 10);

	cube[799].position = D3DXVECTOR3(493.11f, -320.16f, 448.18f);
	cube[799].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[799].scale = D3DXVECTOR3(3, 1, 10);

	cube[800].position = D3DXVECTOR3(493.55f, -319.01f, 446.91f);
	cube[800].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[800].scale = D3DXVECTOR3(3, 1, 10);

	cube[801].position = D3DXVECTOR3(502.50f, -321.87f, 449.84f);
	cube[801].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[801].scale = D3DXVECTOR3(3, 1, 10);

	cube[802].position = D3DXVECTOR3(502.94f, -320.72f, 448.57f);
	cube[802].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[802].scale = D3DXVECTOR3(3, 1, 10);

	cube[803].position = D3DXVECTOR3(511.86f, -323.57f, 451.49f);
	cube[803].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[803].scale = D3DXVECTOR3(3, 1, 10);

	cube[804].position = D3DXVECTOR3(512.30f, -322.42f, 450.22f);
	cube[804].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[804].scale = D3DXVECTOR3(3, 1, 10);

	cube[805].position = D3DXVECTOR3(-6.27f, -10.24f, 2.16f);
	cube[805].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[805].scale = D3DXVECTOR3(3, 1, 10);

	cube[806].position = D3DXVECTOR3(-7.52f, -9.08f, 2.37f);
	cube[806].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[806].scale = D3DXVECTOR3(3, 1, 10);

	cube[807].position = D3DXVECTOR3(-6.27f, -11.90f, 11.16f);
	cube[807].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[807].scale = D3DXVECTOR3(3, 1, 10);

	cube[808].position = D3DXVECTOR3(-7.52f, -10.74f, 11.37f);
	cube[808].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[808].scale = D3DXVECTOR3(3, 1, 10);

	cube[809].position = D3DXVECTOR3(-6.27f, -13.49f, 19.86f);
	cube[809].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[809].scale = D3DXVECTOR3(3, 1, 10);

	cube[810].position = D3DXVECTOR3(-7.52f, -12.33f, 20.07f);
	cube[810].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[810].scale = D3DXVECTOR3(3, 1, 10);

	cube[811].position = D3DXVECTOR3(-6.27f, -15.17f, 28.96f);
	cube[811].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[811].scale = D3DXVECTOR3(3, 1, 10);

	cube[812].position = D3DXVECTOR3(-7.52f, -14.01f, 29.17f);
	cube[812].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[812].scale = D3DXVECTOR3(3, 1, 10);

	cube[813].position = D3DXVECTOR3(-6.27f, -16.96f, 38.36f);
	cube[813].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[813].scale = D3DXVECTOR3(3, 1, 10);

	cube[814].position = D3DXVECTOR3(-7.52f, -15.80f, 38.57f);
	cube[814].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[814].scale = D3DXVECTOR3(3, 1, 10);

	cube[815].position = D3DXVECTOR3(-6.27f, -18.64f, 47.66f);
	cube[815].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[815].scale = D3DXVECTOR3(3, 1, 10);

	cube[816].position = D3DXVECTOR3(-7.52f, -17.48f, 47.87f);
	cube[816].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[816].scale = D3DXVECTOR3(3, 1, 10);

	cube[817].position = D3DXVECTOR3(-6.27f, -20.43f, 57.36f);
	cube[817].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[817].scale = D3DXVECTOR3(3, 1, 10);

	cube[818].position = D3DXVECTOR3(-7.52f, -19.27f, 57.57f);
	cube[818].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[818].scale = D3DXVECTOR3(3, 1, 10);

	cube[819].position = D3DXVECTOR3(-6.27f, -22.02f, 66.16f);
	cube[819].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[819].scale = D3DXVECTOR3(3, 1, 10);

	cube[820].position = D3DXVECTOR3(-7.52f, -20.86f, 66.37f);
	cube[820].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[820].scale = D3DXVECTOR3(3, 1, 10);

	cube[821].position = D3DXVECTOR3(-6.27f, -23.39f, 73.77f);
	cube[821].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[821].scale = D3DXVECTOR3(3, 1, 10);

	cube[822].position = D3DXVECTOR3(-7.52f, -22.23f, 73.98f);
	cube[822].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[822].scale = D3DXVECTOR3(3, 1, 10);

	cube[823].position = D3DXVECTOR3(-6.78f, -25.08f, 80.77f);
	cube[823].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[823].scale = D3DXVECTOR3(3, 1, 10);

	cube[824].position = D3DXVECTOR3(-6.53f, -25.26f, 81.75f);
	cube[824].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[824].scale = D3DXVECTOR3(3, 1, 7);

	cube[825].position = D3DXVECTOR3(-8.05f, -23.92f, 80.76f);
	cube[825].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[825].scale = D3DXVECTOR3(3, 1, 10);

	cube[826].position = D3DXVECTOR3(-8.07f, -23.95f, 81.78f);
	cube[826].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[826].scale = D3DXVECTOR3(5, 1, 7);

	cube[827].position = D3DXVECTOR3(-8.38f, -26.74f, 87.33f);
	cube[827].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[827].scale = D3DXVECTOR3(3, 1, 10);

	cube[828].position = D3DXVECTOR3(-8.24f, -27.10f, 88.72f);
	cube[828].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[828].scale = D3DXVECTOR3(3, 1, 7);

	cube[829].position = D3DXVECTOR3(-9.63f, -25.58f, 87.10f);
	cube[829].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[829].scale = D3DXVECTOR3(3, 1, 10);

	cube[830].position = D3DXVECTOR3(-10.12f, -25.50f, 88.41f);
	cube[830].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[830].scale = D3DXVECTOR3(5, 1, 7);

	cube[831].position = D3DXVECTOR3(-10.92f, -28.34f, 93.11f);
	cube[831].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[831].scale = D3DXVECTOR3(3, 1, 10);

	cube[832].position = D3DXVECTOR3(-11.07f, -28.60f, 94.51f);
	cube[832].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[832].scale = D3DXVECTOR3(3, 1, 7);

	cube[833].position = D3DXVECTOR3(-12.11f, -27.18f, 92.66f);
	cube[833].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[833].scale = D3DXVECTOR3(3, 1, 10);

	cube[834].position = D3DXVECTOR3(-12.62f, -27.28f, 93.98f);
	cube[834].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[834].scale = D3DXVECTOR3(5, 1, 7);

	cube[835].position = D3DXVECTOR3(-14.64f, -29.99f, 98.72f);
	cube[835].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[835].scale = D3DXVECTOR3(3, 1, 10);

	cube[836].position = D3DXVECTOR3(-14.92f, -30.32f, 100.02f);
	cube[836].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[836].scale = D3DXVECTOR3(3, 1, 7);

	cube[837].position = D3DXVECTOR3(-15.74f, -28.83f, 98.08f);
	cube[837].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[837].scale = D3DXVECTOR3(3, 1, 10);

	cube[838].position = D3DXVECTOR3(-16.42f, -28.94f, 99.22f);
	cube[838].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[838].scale = D3DXVECTOR3(5, 1, 7);

	cube[839].position = D3DXVECTOR3(-19.47f, -31.70f, 103.67f);
	cube[839].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[839].scale = D3DXVECTOR3(3, 1, 10);

	cube[840].position = D3DXVECTOR3(-20.01f, -31.93f, 104.79f);
	cube[840].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[840].scale = D3DXVECTOR3(3, 1, 7);

	cube[841].position = D3DXVECTOR3(-20.44f, -30.54f, 102.85f);
	cube[841].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[841].scale = D3DXVECTOR3(3, 1, 10);

	cube[842].position = D3DXVECTOR3(-21.24f, -30.63f, 103.81f);
	cube[842].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[842].scale = D3DXVECTOR3(5, 1, 7);

	cube[843].position = D3DXVECTOR3(-24.78f, -33.33f, 107.58f);
	cube[843].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[843].scale = D3DXVECTOR3(3, 1, 10);

	cube[844].position = D3DXVECTOR3(-25.50f, -33.66f, 108.72f);
	cube[844].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[844].scale = D3DXVECTOR3(3, 1, 7);

	cube[845].position = D3DXVECTOR3(-25.59f, -32.17f, 106.60f);
	cube[845].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[845].scale = D3DXVECTOR3(3, 1, 10);

	cube[846].position = D3DXVECTOR3(-26.62f, -32.28f, 107.42f);
	cube[846].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[846].scale = D3DXVECTOR3(5, 1, 7);

	cube[847].position = D3DXVECTOR3(-32.87f, -35.05f, 112.25f);
	cube[847].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[847].scale = D3DXVECTOR3(3, 1, 10);

	cube[848].position = D3DXVECTOR3(-33.68f, -33.89f, 111.27f);
	cube[848].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[848].scale = D3DXVECTOR3(3, 1, 10);

	cube[849].position = D3DXVECTOR3(-40.83f, -36.78f, 116.86f);
	cube[849].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[849].scale = D3DXVECTOR3(3, 1, 10);

	cube[850].position = D3DXVECTOR3(-41.64f, -35.62f, 115.88f);
	cube[850].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[850].scale = D3DXVECTOR3(3, 1, 10);

	cube[851].position = D3DXVECTOR3(-48.13f, -38.33f, 121.06f);
	cube[851].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[851].scale = D3DXVECTOR3(3, 1, 10);

	cube[852].position = D3DXVECTOR3(-48.94f, -37.17f, 120.08f);
	cube[852].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[852].scale = D3DXVECTOR3(3, 1, 10);

	cube[853].position = D3DXVECTOR3(-55.43f, -39.85f, 125.26f);
	cube[853].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[853].scale = D3DXVECTOR3(3, 1, 10);

	cube[854].position = D3DXVECTOR3(-56.24f, -38.69f, 124.28f);
	cube[854].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[854].scale = D3DXVECTOR3(3, 1, 10);

	cube[855].position = D3DXVECTOR3(-63.33f, -41.58f, 129.86f);
	cube[855].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[855].scale = D3DXVECTOR3(3, 1, 10);

	cube[856].position = D3DXVECTOR3(-64.14f, -40.42f, 128.88f);
	cube[856].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[856].scale = D3DXVECTOR3(3, 1, 10);

	cube[857].position = D3DXVECTOR3(-71.19f, -43.22f, 134.33f);
	cube[857].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[857].scale = D3DXVECTOR3(3, 1, 10);

	cube[858].position = D3DXVECTOR3(-72.00f, -42.06f, 133.35f);
	cube[858].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[858].scale = D3DXVECTOR3(3, 1, 10);

	cube[859].position = D3DXVECTOR3(-77.50f, -44.91f, 137.39f);
	cube[859].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[859].scale = D3DXVECTOR3(3, 1, 10);

	cube[860].position = D3DXVECTOR3(-78.23f, -45.09f, 138.09f);
	cube[860].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[860].scale = D3DXVECTOR3(3, 1, 7);

	cube[861].position = D3DXVECTOR3(-78.12f, -43.75f, 136.28f);
	cube[861].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[861].scale = D3DXVECTOR3(3, 1, 10);

	cube[862].position = D3DXVECTOR3(-79.03f, -43.78f, 136.77f);
	cube[862].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[862].scale = D3DXVECTOR3(5, 1, 7);

	cube[863].position = D3DXVECTOR3(-83.99f, -46.57f, 139.28f);
	cube[863].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[863].scale = D3DXVECTOR3(3, 1, 10);

	cube[864].position = D3DXVECTOR3(-85.12f, -46.93f, 140.10f);
	cube[864].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[864].scale = D3DXVECTOR3(3, 1, 7);

	cube[865].position = D3DXVECTOR3(-84.41f, -45.41f, 138.09f);
	cube[865].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[865].scale = D3DXVECTOR3(3, 1, 10);

	cube[866].position = D3DXVECTOR3(-85.79f, -45.33f, 138.31f);
	cube[866].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[866].scale = D3DXVECTOR3(5, 1, 7);

	cube[867].position = D3DXVECTOR3(-90.26f, -48.17f, 139.97f);
	cube[867].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[867].scale = D3DXVECTOR3(3, 1, 10);

	cube[868].position = D3DXVECTOR3(-91.55f, -48.43f, 140.54f);
	cube[868].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[868].scale = D3DXVECTOR3(3, 1, 7);

	cube[869].position = D3DXVECTOR3(-90.47f, -47.01f, 138.72f);
	cube[869].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[869].scale = D3DXVECTOR3(3, 1, 10);

	cube[870].position = D3DXVECTOR3(-91.87f, -47.11f, 138.93f);
	cube[870].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[870].scale = D3DXVECTOR3(5, 1, 7);

	cube[871].position = D3DXVECTOR3(-96.98f, -49.82f, 139.55f);
	cube[871].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[871].scale = D3DXVECTOR3(3, 1, 10);

	cube[872].position = D3DXVECTOR3(-98.25f, -50.15f, 139.96f);
	cube[872].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[872].scale = D3DXVECTOR3(3, 1, 7);

	cube[873].position = D3DXVECTOR3(-96.97f, -48.66f, 138.28f);
	cube[873].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[873].scale = D3DXVECTOR3(3, 1, 10);

	cube[874].position = D3DXVECTOR3(-98.31f, -48.77f, 138.26f);
	cube[874].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[874].scale = D3DXVECTOR3(5, 1, 7);

	cube[875].position = D3DXVECTOR3(-103.64f, -51.12f, 138.36f);
	cube[875].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[875].scale = D3DXVECTOR3(3, 1, 10);

	cube[876].position = D3DXVECTOR3(-103.63f, -49.96f, 137.10f);
	cube[876].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[876].scale = D3DXVECTOR3(3, 1, 10);

	cube[877].position = D3DXVECTOR3(-112.44f, -52.73f, 137.45f);
	cube[877].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[877].scale = D3DXVECTOR3(3, 1, 10);

	cube[878].position = D3DXVECTOR3(-112.65f, -51.57f, 136.20f);
	cube[878].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[878].scale = D3DXVECTOR3(3, 1, 10);

	cube[879].position = D3DXVECTOR3(-120.92f, -54.32f, 138.05f);
	cube[879].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[879].scale = D3DXVECTOR3(3, 1, 10);

	cube[880].position = D3DXVECTOR3(-121.34f, -53.16f, 136.85f);
	cube[880].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[880].scale = D3DXVECTOR3(3, 1, 10);

	cube[881].position = D3DXVECTOR3(-129.45f, -55.95f, 140.19f);
	cube[881].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[881].scale = D3DXVECTOR3(3, 1, 10);

	cube[882].position = D3DXVECTOR3(-130.08f, -54.79f, 139.08f);
	cube[882].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[882].scale = D3DXVECTOR3(3, 1, 10);

	cube[883].position = D3DXVECTOR3(-137.45f, -57.58f, 143.75f);
	cube[883].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[883].scale = D3DXVECTOR3(3, 1, 10);

	cube[884].position = D3DXVECTOR3(-138.25f, -56.42f, 142.77f);
	cube[884].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[884].scale = D3DXVECTOR3(3, 1, 10);

	cube[885].position = D3DXVECTOR3(-144.67f, -59.18f, 148.62f);
	cube[885].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[885].scale = D3DXVECTOR3(3, 1, 10);

	cube[886].position = D3DXVECTOR3(-145.63f, -58.02f, 147.79f);
	cube[886].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[886].scale = D3DXVECTOR3(3, 1, 10);

	cube[887].position = D3DXVECTOR3(-150.98f, -60.82f, 154.72f);
	cube[887].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[887].scale = D3DXVECTOR3(3, 1, 10);

	cube[888].position = D3DXVECTOR3(-152.07f, -59.66f, 154.08f);
	cube[888].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[888].scale = D3DXVECTOR3(3, 1, 10);

	cube[889].position = D3DXVECTOR3(-155.95f, -62.48f, 161.69f);
	cube[889].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[889].scale = D3DXVECTOR3(3, 1, 10);

	cube[890].position = D3DXVECTOR3(-157.14f, -61.32f, 161.24f);
	cube[890].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[890].scale = D3DXVECTOR3(3, 1, 10);

	cube[891].position = D3DXVECTOR3(-159.59f, -64.02f, 169.14f);
	cube[891].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[891].scale = D3DXVECTOR3(3, 1, 10);

	cube[892].position = D3DXVECTOR3(-160.84f, -62.86f, 168.91f);
	cube[892].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[892].scale = D3DXVECTOR3(3, 1, 10);

	cube[893].position = D3DXVECTOR3(-162.07f, -65.38f, 175.84f);
	cube[893].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[893].scale = D3DXVECTOR3(3, 1, 10);

	cube[894].position = D3DXVECTOR3(-163.31f, -64.22f, 175.61f);
	cube[894].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[894].scale = D3DXVECTOR3(3, 1, 10);

	cube[895].position = D3DXVECTOR3(-164.50f, -66.99f, 184.35f);
	cube[895].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[895].scale = D3DXVECTOR3(3, 1, 10);

	cube[896].position = D3DXVECTOR3(-165.76f, -65.83f, 184.34f);
	cube[896].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[896].scale = D3DXVECTOR3(3, 1, 10);

	cube[897].position = D3DXVECTOR3(-165.38f, -68.58f, 192.80f);
	cube[897].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[897].scale = D3DXVECTOR3(3, 1, 10);

	cube[898].position = D3DXVECTOR3(-166.63f, -67.42f, 193.01f);
	cube[898].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[898].scale = D3DXVECTOR3(3, 1, 10);

	cube[899].position = D3DXVECTOR3(-164.75f, -70.21f, 201.58f);
	cube[899].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[899].scale = D3DXVECTOR3(3, 1, 10);

	cube[900].position = D3DXVECTOR3(-165.95f, -69.05f, 202.00f);
	cube[900].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[900].scale = D3DXVECTOR3(3, 1, 10);

	cube[901].position = D3DXVECTOR3(-162.64f, -71.84f, 210.07f);
	cube[901].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[901].scale = D3DXVECTOR3(3, 1, 10);

	cube[902].position = D3DXVECTOR3(-163.74f, -70.68f, 210.70f);
	cube[902].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[902].scale = D3DXVECTOR3(3, 1, 10);

	cube[903].position = D3DXVECTOR3(-159.09f, -73.44f, 218.03f);
	cube[903].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[903].scale = D3DXVECTOR3(3, 1, 10);

	cube[904].position = D3DXVECTOR3(-160.07f, -72.28f, 218.83f);
	cube[904].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[904].scale = D3DXVECTOR3(3, 1, 10);

	cube[905].position = D3DXVECTOR3(-154.18f, -75.08f, 225.30f);
	cube[905].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[905].scale = D3DXVECTOR3(3, 1, 10);

	cube[906].position = D3DXVECTOR3(-155.00f, -73.92f, 226.27f);
	cube[906].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[906].scale = D3DXVECTOR3(3, 1, 10);

	cube[907].position = D3DXVECTOR3(-148.18f, -76.74f, 231.41f);
	cube[907].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[907].scale = D3DXVECTOR3(3, 1, 10);

	cube[908].position = D3DXVECTOR3(-148.82f, -75.58f, 232.50f);
	cube[908].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[908].scale = D3DXVECTOR3(3, 1, 10);

	cube[909].position = D3DXVECTOR3(-141.47f, -78.28f, 236.29f);
	cube[909].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[909].scale = D3DXVECTOR3(3, 1, 10);

	cube[910].position = D3DXVECTOR3(-141.91f, -77.12f, 237.48f);
	cube[910].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[910].scale = D3DXVECTOR3(3, 1, 10);

	cube[911].position = D3DXVECTOR3(-133.74f, -79.96f, 240.77f);
	cube[911].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[911].scale = D3DXVECTOR3(3, 1, 10);

	cube[912].position = D3DXVECTOR3(-134.18f, -78.80f, 241.95f);
	cube[912].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[912].scale = D3DXVECTOR3(3, 1, 10);

	cube[913].position = D3DXVECTOR3(-125.66f, -81.66f, 245.44f);
	cube[913].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[913].scale = D3DXVECTOR3(3, 1, 10);

	cube[914].position = D3DXVECTOR3(-126.10f, -80.50f, 246.62f);
	cube[914].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[914].scale = D3DXVECTOR3(3, 1, 10);

	cube[915].position = D3DXVECTOR3(-117.16f, -83.41f, 250.37f);
	cube[915].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[915].scale = D3DXVECTOR3(3, 1, 10);

	cube[916].position = D3DXVECTOR3(-117.60f, -82.25f, 251.55f);
	cube[916].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[916].scale = D3DXVECTOR3(3, 1, 10);

	cube[917].position = D3DXVECTOR3(-109.10f, -85.07f, 255.09f);
	cube[917].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[917].scale = D3DXVECTOR3(3, 1, 10);

	cube[918].position = D3DXVECTOR3(-109.55f, -83.91f, 256.28f);
	cube[918].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[918].scale = D3DXVECTOR3(3, 1, 10);

	cube[919].position = D3DXVECTOR3(-101.15f, -86.68f, 258.96f);
	cube[919].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[919].scale = D3DXVECTOR3(3, 1, 10);

	cube[920].position = D3DXVECTOR3(-101.38f, -85.52f, 260.20f);
	cube[920].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[920].scale = D3DXVECTOR3(3, 1, 10);

	cube[921].position = D3DXVECTOR3(-92.98f, -88.27f, 261.29f);
	cube[921].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[921].scale = D3DXVECTOR3(3, 1, 10);

	cube[922].position = D3DXVECTOR3(-92.99f, -87.11f, 262.56f);
	cube[922].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[922].scale = D3DXVECTOR3(3, 1, 10);

	cube[923].position = D3DXVECTOR3(-84.22f, -89.90f, 262.20f);
	cube[923].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[923].scale = D3DXVECTOR3(3, 1, 10);

	cube[924].position = D3DXVECTOR3(-84.01f, -88.74f, 263.45f);
	cube[924].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[924].scale = D3DXVECTOR3(3, 1, 10);

	cube[925].position = D3DXVECTOR3(-75.49f, -91.53f, 261.59f);
	cube[925].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[925].scale = D3DXVECTOR3(3, 1, 10);

	cube[926].position = D3DXVECTOR3(-75.07f, -90.37f, 262.79f);
	cube[926].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[926].scale = D3DXVECTOR3(3, 1, 10);

	cube[927].position = D3DXVECTOR3(-66.21f, -93.23f, 259.96f);
	cube[927].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[927].scale = D3DXVECTOR3(3, 1, 10);

	cube[928].position = D3DXVECTOR3(-65.79f, -92.07f, 261.15f);
	cube[928].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[928].scale = D3DXVECTOR3(3, 1, 10);

	cube[929].position = D3DXVECTOR3(-59.24f, -94.92f, 259.24f);
	cube[929].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[929].scale = D3DXVECTOR3(3, 1, 10);

	cube[930].position = D3DXVECTOR3(-58.31f, -95.10f, 258.83f);
	cube[930].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[930].scale = D3DXVECTOR3(3, 1, 7);

	cube[931].position = D3DXVECTOR3(-59.03f, -93.76f, 260.49f);
	cube[931].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[931].scale = D3DXVECTOR3(3, 1, 10);

	cube[932].position = D3DXVECTOR3(-58.01f, -93.79f, 260.34f);
	cube[932].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[932].scale = D3DXVECTOR3(5, 1, 7);

	cube[933].position = D3DXVECTOR3(-52.50f, -96.58f, 259.68f);
	cube[933].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[933].scale = D3DXVECTOR3(3, 1, 10);

	cube[934].position = D3DXVECTOR3(-51.15f, -96.94f, 259.30f);
	cube[934].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[934].scale = D3DXVECTOR3(3, 1, 7);

	cube[935].position = D3DXVECTOR3(-52.51f, -95.42f, 260.94f);
	cube[935].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[935].scale = D3DXVECTOR3(3, 1, 10);

	cube[936].position = D3DXVECTOR3(-51.13f, -95.34f, 261.20f);
	cube[936].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[936].scale = D3DXVECTOR3(5, 1, 7);

	cube[937].position = D3DXVECTOR3(-46.37f, -98.18f, 261.18f);
	cube[937].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[937].scale = D3DXVECTOR3(3, 1, 10);

	cube[938].position = D3DXVECTOR3(-44.96f, -98.44f, 261.08f);
	cube[938].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[938].scale = D3DXVECTOR3(3, 1, 7);

	cube[939].position = D3DXVECTOR3(-46.60f, -97.02f, 262.42f);
	cube[939].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[939].scale = D3DXVECTOR3(3, 1, 10);

	cube[940].position = D3DXVECTOR3(-45.21f, -97.12f, 262.70f);
	cube[940].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[940].scale = D3DXVECTOR3(5, 1, 7);

	cube[941].position = D3DXVECTOR3(-40.19f, -99.83f, 263.87f);
	cube[941].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[941].scale = D3DXVECTOR3(3, 1, 10);

	cube[942].position = D3DXVECTOR3(-38.86f, -100.16f, 263.92f);
	cube[942].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[942].scale = D3DXVECTOR3(3, 1, 7);

	cube[943].position = D3DXVECTOR3(-40.64f, -98.67f, 265.06f);
	cube[943].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[943].scale = D3DXVECTOR3(3, 1, 10);

	cube[944].position = D3DXVECTOR3(-39.39f, -98.78f, 265.53f);
	cube[944].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[944].scale = D3DXVECTOR3(5, 1, 7);

	cube[945].position = D3DXVECTOR3(-32.27f, -101.50f, 268.47f);
	cube[945].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[945].scale = D3DXVECTOR3(3, 1, 10);

	cube[946].position = D3DXVECTOR3(-32.72f, -100.34f, 269.66f);
	cube[946].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[946].scale = D3DXVECTOR3(3, 1, 10);

	cube[947].position = D3DXVECTOR3(-24.32f, -103.11f, 272.34f);
	cube[947].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[947].scale = D3DXVECTOR3(3, 1, 10);

	cube[948].position = D3DXVECTOR3(-24.55f, -101.95f, 273.58f);
	cube[948].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[948].scale = D3DXVECTOR3(3, 1, 10);

	cube[949].position = D3DXVECTOR3(-16.15f, -104.70f, 274.67f);
	cube[949].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[949].scale = D3DXVECTOR3(3, 1, 10);

	cube[950].position = D3DXVECTOR3(-16.16f, -103.54f, 275.94f);
	cube[950].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[950].scale = D3DXVECTOR3(3, 1, 10);

	cube[951].position = D3DXVECTOR3(-7.39f, -106.33f, 275.58f);
	cube[951].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[951].scale = D3DXVECTOR3(3, 1, 10);

	cube[952].position = D3DXVECTOR3(-7.18f, -105.17f, 276.83f);
	cube[952].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[952].scale = D3DXVECTOR3(3, 1, 10);

	cube[953].position = D3DXVECTOR3(1.34f, -107.96f, 274.97f);
	cube[953].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[953].scale = D3DXVECTOR3(3, 1, 10);

	cube[954].position = D3DXVECTOR3(1.76f, -106.80f, 276.17f);
	cube[954].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[954].scale = D3DXVECTOR3(3, 1, 10);

	cube[955].position = D3DXVECTOR3(10.47f, -109.68f, 273.41f);
	cube[955].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[955].scale = D3DXVECTOR3(3, 1, 10);

	cube[956].position = D3DXVECTOR3(10.89f, -108.52f, 274.60f);
	cube[956].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[956].scale = D3DXVECTOR3(3, 1, 10);

	cube[957].position = D3DXVECTOR3(17.44f, -111.37f, 272.69f);
	cube[957].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[957].scale = D3DXVECTOR3(3, 1, 10);

	cube[958].position = D3DXVECTOR3(18.37f, -111.55f, 272.28f);
	cube[958].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[958].scale = D3DXVECTOR3(3, 1, 7);

	cube[959].position = D3DXVECTOR3(17.65f, -110.21f, 273.94f);
	cube[959].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[959].scale = D3DXVECTOR3(3, 1, 10);

	cube[960].position = D3DXVECTOR3(18.67f, -110.24f, 273.79f);
	cube[960].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[960].scale = D3DXVECTOR3(5, 1, 7);

	cube[961].position = D3DXVECTOR3(24.18f, -113.03f, 273.13f);
	cube[961].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[961].scale = D3DXVECTOR3(3, 1, 10);

	cube[962].position = D3DXVECTOR3(25.53f, -113.39f, 272.75f);
	cube[962].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[962].scale = D3DXVECTOR3(3, 1, 7);

	cube[963].position = D3DXVECTOR3(24.17f, -111.87f, 274.39f);
	cube[963].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[963].scale = D3DXVECTOR3(3, 1, 10);

	cube[964].position = D3DXVECTOR3(25.55f, -111.79f, 274.65f);
	cube[964].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[964].scale = D3DXVECTOR3(5, 1, 7);

	cube[965].position = D3DXVECTOR3(30.31f, -114.63f, 274.63f);
	cube[965].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[965].scale = D3DXVECTOR3(3, 1, 10);

	cube[966].position = D3DXVECTOR3(31.72f, -114.89f, 274.53f);
	cube[966].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[966].scale = D3DXVECTOR3(3, 1, 7);

	cube[967].position = D3DXVECTOR3(30.08f, -113.47f, 275.87f);
	cube[967].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[967].scale = D3DXVECTOR3(3, 1, 10);

	cube[968].position = D3DXVECTOR3(31.47f, -113.57f, 276.15f);
	cube[968].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[968].scale = D3DXVECTOR3(5, 1, 7);

	cube[969].position = D3DXVECTOR3(36.49f, -116.28f, 277.32f);
	cube[969].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[969].scale = D3DXVECTOR3(3, 1, 10);

	cube[970].position = D3DXVECTOR3(37.82f, -116.61f, 277.37f);
	cube[970].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[970].scale = D3DXVECTOR3(3, 1, 7);

	cube[971].position = D3DXVECTOR3(36.04f, -115.12f, 278.51f);
	cube[971].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[971].scale = D3DXVECTOR3(3, 1, 10);

	cube[972].position = D3DXVECTOR3(37.29f, -115.23f, 278.98f);
	cube[972].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[972].scale = D3DXVECTOR3(5, 1, 7);

	cube[973].position = D3DXVECTOR3(44.44f, -118.02f, 281.91f);
	cube[973].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[973].scale = D3DXVECTOR3(3, 1, 10);

	cube[974].position = D3DXVECTOR3(44.00f, -116.86f, 283.09f);
	cube[974].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[974].scale = D3DXVECTOR3(3, 1, 10);

	cube[975].position = D3DXVECTOR3(52.47f, -119.71f, 286.56f);
	cube[975].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[975].scale = D3DXVECTOR3(3, 1, 10);

	cube[976].position = D3DXVECTOR3(52.03f, -118.55f, 287.74f);
	cube[976].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[976].scale = D3DXVECTOR3(3, 1, 10);

	cube[977].position = D3DXVECTOR3(60.73f, -121.43f, 291.32f);
	cube[977].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[977].scale = D3DXVECTOR3(3, 1, 10);

	cube[978].position = D3DXVECTOR3(60.29f, -120.27f, 292.50f);
	cube[978].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[978].scale = D3DXVECTOR3(3, 1, 10);

	cube[979].position = D3DXVECTOR3(68.85f, -123.13f, 295.99f);
	cube[979].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[979].scale = D3DXVECTOR3(3, 1, 10);

	cube[980].position = D3DXVECTOR3(68.41f, -121.97f, 297.17f);
	cube[980].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[980].scale = D3DXVECTOR3(3, 1, 10);

	cube[981].position = D3DXVECTOR3(76.95f, -124.80f, 300.65f);
	cube[981].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[981].scale = D3DXVECTOR3(3, 1, 10);

	cube[982].position = D3DXVECTOR3(76.51f, -123.64f, 301.83f);
	cube[982].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[982].scale = D3DXVECTOR3(3, 1, 10);

	cube[983].position = D3DXVECTOR3(85.25f, -126.50f, 305.43f);
	cube[983].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[983].scale = D3DXVECTOR3(3, 1, 10);

	cube[984].position = D3DXVECTOR3(84.81f, -125.34f, 306.61f);
	cube[984].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[984].scale = D3DXVECTOR3(3, 1, 10);

	cube[985].position = D3DXVECTOR3(92.83f, -128.07f, 309.75f);
	cube[985].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[985].scale = D3DXVECTOR3(3, 1, 10);

	cube[986].position = D3DXVECTOR3(92.38f, -126.91f, 310.93f);
	cube[986].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[986].scale = D3DXVECTOR3(3, 1, 10);

	cube[987].position = D3DXVECTOR3(98.63f, -129.76f, 313.68f);
	cube[987].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[987].scale = D3DXVECTOR3(3, 1, 10);

	cube[988].position = D3DXVECTOR3(99.61f, -129.94f, 313.96f);
	cube[988].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[988].scale = D3DXVECTOR3(3, 1, 7);

	cube[989].position = D3DXVECTOR3(97.99f, -128.60f, 314.77f);
	cube[989].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[989].scale = D3DXVECTOR3(3, 1, 10);

	cube[990].position = D3DXVECTOR3(98.86f, -128.63f, 315.31f);
	cube[990].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[990].scale = D3DXVECTOR3(5, 1, 7);

	cube[991].position = D3DXVECTOR3(103.51f, -131.42f, 318.35f);
	cube[991].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[991].scale = D3DXVECTOR3(3, 1, 10);

	cube[992].position = D3DXVECTOR3(104.79f, -131.78f, 318.93f);
	cube[992].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[992].scale = D3DXVECTOR3(3, 1, 7);

	cube[993].position = D3DXVECTOR3(102.69f, -130.26f, 319.31f);
	cube[993].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[993].scale = D3DXVECTOR3(3, 1, 10);

	cube[994].position = D3DXVECTOR3(103.58f, -130.18f, 320.40f);
	cube[994].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[994].scale = D3DXVECTOR3(5, 1, 7);

	cube[995].position = D3DXVECTOR3(107.25f, -133.02f, 323.44f);
	cube[995].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[995].scale = D3DXVECTOR3(3, 1, 10);

	cube[996].position = D3DXVECTOR3(108.39f, -133.28f, 324.27f);
	cube[996].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[996].scale = D3DXVECTOR3(3, 1, 7);

	cube[997].position = D3DXVECTOR3(106.27f, -131.86f, 324.25f);
	cube[997].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[997].scale = D3DXVECTOR3(3, 1, 10);

	cube[998].position = D3DXVECTOR3(107.15f, -131.96f, 325.35f);
	cube[998].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[998].scale = D3DXVECTOR3(5, 1, 7);

	cube[999].position = D3DXVECTOR3(110.25f, -134.67f, 329.47f);
	cube[999].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[999].scale = D3DXVECTOR3(3, 1, 10);

	cube[1000].position = D3DXVECTOR3(111.23f, -135.00f, 330.36f);
	cube[1000].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1000].scale = D3DXVECTOR3(3, 1, 7);

	cube[1001].position = D3DXVECTOR3(109.14f, -133.51f, 330.09f);
	cube[1001].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1001].scale = D3DXVECTOR3(3, 1, 10);

	cube[1002].position = D3DXVECTOR3(109.79f, -133.62f, 331.26f);
	cube[1002].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1002].scale = D3DXVECTOR3(5, 1, 7);

	cube[1003].position = D3DXVECTOR3(113.47f, -136.36f, 338.32f);
	cube[1003].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1003].scale = D3DXVECTOR3(3, 1, 10);

	cube[1004].position = D3DXVECTOR3(112.37f, -135.20f, 338.94f);
	cube[1004].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1004].scale = D3DXVECTOR3(3, 1, 10);

	cube[1005].position = D3DXVECTOR3(116.55f, -138.02f, 346.79f);
	cube[1005].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1005].scale = D3DXVECTOR3(3, 1, 10);

	cube[1006].position = D3DXVECTOR3(115.45f, -136.86f, 347.41f);
	cube[1006].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1006].scale = D3DXVECTOR3(3, 1, 10);

	cube[1007].position = D3DXVECTOR3(119.68f, -139.67f, 355.24f);
	cube[1007].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1007].scale = D3DXVECTOR3(3, 1, 10);

	cube[1008].position = D3DXVECTOR3(118.57f, -138.51f, 355.86f);
	cube[1008].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1008].scale = D3DXVECTOR3(3, 1, 10);

	cube[1009].position = D3DXVECTOR3(121.59f, -141.36f, 361.98f);
	cube[1009].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1009].scale = D3DXVECTOR3(3, 1, 10);

	cube[1010].position = D3DXVECTOR3(122.16f, -141.54f, 362.83f);
	cube[1010].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1010].scale = D3DXVECTOR3(3, 1, 7);

	cube[1011].position = D3DXVECTOR3(120.40f, -140.20f, 362.41f);
	cube[1011].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1011].scale = D3DXVECTOR3(3, 1, 10);

	cube[1012].position = D3DXVECTOR3(120.72f, -140.23f, 363.38f);
	cube[1012].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1012].scale = D3DXVECTOR3(5, 1, 7);

	cube[1013].position = D3DXVECTOR3(122.33f, -143.02f, 368.70f);
	cube[1013].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1013].scale = D3DXVECTOR3(3, 1, 10);

	cube[1014].position = D3DXVECTOR3(122.94f, -143.38f, 369.96f);
	cube[1014].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1014].scale = D3DXVECTOR3(3, 1, 7);

	cube[1015].position = D3DXVECTOR3(121.08f, -141.86f, 368.91f);
	cube[1015].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1015].scale = D3DXVECTOR3(3, 1, 10);

	cube[1016].position = D3DXVECTOR3(121.06f, -141.78f, 370.31f);
	cube[1016].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1016].scale = D3DXVECTOR3(5, 1, 7);

	cube[1017].position = D3DXVECTOR3(121.92f, -144.62f, 375.00f);
	cube[1017].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1017].scale = D3DXVECTOR3(3, 1, 10);

	cube[1018].position = D3DXVECTOR3(122.26f, -144.88f, 376.37f);
	cube[1018].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1018].scale = D3DXVECTOR3(3, 1, 7);

	cube[1019].position = D3DXVECTOR3(120.65f, -143.46f, 374.99f);
	cube[1019].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1019].scale = D3DXVECTOR3(3, 1, 10);

	cube[1020].position = D3DXVECTOR3(120.62f, -143.56f, 376.40f);
	cube[1020].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1020].scale = D3DXVECTOR3(5, 1, 7);

	cube[1021].position = D3DXVECTOR3(120.34f, -146.27f, 381.54f);
	cube[1021].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1021].scale = D3DXVECTOR3(3, 1, 10);

	cube[1022].position = D3DXVECTOR3(120.53f, -146.60f, 382.86f);
	cube[1022].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1022].scale = D3DXVECTOR3(3, 1, 7);

	cube[1023].position = D3DXVECTOR3(119.09f, -145.11f, 381.31f);
	cube[1023].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1023].scale = D3DXVECTOR3(3, 1, 10);

	cube[1024].position = D3DXVECTOR3(118.84f, -145.22f, 382.62f);
	cube[1024].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1024].scale = D3DXVECTOR3(5, 1, 7);

	cube[1025].position = D3DXVECTOR3(117.02f, -148.00f, 390.61f);
	cube[1025].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1025].scale = D3DXVECTOR3(3, 1, 10);

	cube[1026].position = D3DXVECTOR3(115.78f, -146.84f, 390.38f);
	cube[1026].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1026].scale = D3DXVECTOR3(3, 1, 10);

	cube[1027].position = D3DXVECTOR3(113.89f, -149.66f, 399.13f);
	cube[1027].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1027].scale = D3DXVECTOR3(3, 1, 10);

	cube[1028].position = D3DXVECTOR3(112.65f, -148.50f, 398.90f);
	cube[1028].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1028].scale = D3DXVECTOR3(3, 1, 10);

	cube[1029].position = D3DXVECTOR3(111.46f, -151.27f, 407.64f);
	cube[1029].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1029].scale = D3DXVECTOR3(3, 1, 10);

	cube[1030].position = D3DXVECTOR3(110.20f, -150.11f, 407.63f);
	cube[1030].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1030].scale = D3DXVECTOR3(3, 1, 10);

	cube[1031].position = D3DXVECTOR3(110.58f, -152.86f, 416.09f);
	cube[1031].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1031].scale = D3DXVECTOR3(3, 1, 10);

	cube[1032].position = D3DXVECTOR3(109.33f, -151.70f, 416.30f);
	cube[1032].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1032].scale = D3DXVECTOR3(3, 1, 10);

	cube[1033].position = D3DXVECTOR3(111.21f, -154.49f, 424.87f);
	cube[1033].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1033].scale = D3DXVECTOR3(3, 1, 10);

	cube[1034].position = D3DXVECTOR3(110.01f, -153.33f, 425.29f);
	cube[1034].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1034].scale = D3DXVECTOR3(3, 1, 10);

	cube[1035].position = D3DXVECTOR3(113.32f, -156.12f, 433.36f);
	cube[1035].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1035].scale = D3DXVECTOR3(3, 1, 10);

	cube[1036].position = D3DXVECTOR3(112.22f, -154.96f, 433.99f);
	cube[1036].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1036].scale = D3DXVECTOR3(3, 1, 10);

	cube[1037].position = D3DXVECTOR3(116.46f, -157.79f, 442.00f);
	cube[1037].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1037].scale = D3DXVECTOR3(3, 1, 10);

	cube[1038].position = D3DXVECTOR3(115.35f, -156.63f, 442.62f);
	cube[1038].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1038].scale = D3DXVECTOR3(3, 1, 10);

	cube[1039].position = D3DXVECTOR3(118.37f, -159.48f, 448.74f);
	cube[1039].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1039].scale = D3DXVECTOR3(3, 1, 10);

	cube[1040].position = D3DXVECTOR3(118.94f, -159.66f, 449.59f);
	cube[1040].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1040].scale = D3DXVECTOR3(3, 1, 7);

	cube[1041].position = D3DXVECTOR3(117.18f, -158.32f, 449.17f);
	cube[1041].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1041].scale = D3DXVECTOR3(3, 1, 10);

	cube[1042].position = D3DXVECTOR3(117.50f, -158.35f, 450.14f);
	cube[1042].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1042].scale = D3DXVECTOR3(5, 1, 7);

	cube[1043].position = D3DXVECTOR3(119.11f, -161.14f, 455.46f);
	cube[1043].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1043].scale = D3DXVECTOR3(3, 1, 10);

	cube[1044].position = D3DXVECTOR3(119.72f, -161.50f, 456.72f);
	cube[1044].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1044].scale = D3DXVECTOR3(3, 1, 7);

	cube[1045].position = D3DXVECTOR3(117.86f, -159.98f, 455.67f);
	cube[1045].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1045].scale = D3DXVECTOR3(3, 1, 10);

	cube[1046].position = D3DXVECTOR3(117.84f, -159.90f, 457.07f);
	cube[1046].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1046].scale = D3DXVECTOR3(5, 1, 7);

	cube[1047].position = D3DXVECTOR3(118.70f, -162.74f, 461.76f);
	cube[1047].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1047].scale = D3DXVECTOR3(3, 1, 10);

	cube[1048].position = D3DXVECTOR3(119.04f, -163.00f, 463.13f);
	cube[1048].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1048].scale = D3DXVECTOR3(3, 1, 7);

	cube[1049].position = D3DXVECTOR3(117.43f, -161.58f, 461.75f);
	cube[1049].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1049].scale = D3DXVECTOR3(3, 1, 10);

	cube[1050].position = D3DXVECTOR3(117.40f, -161.68f, 463.16f);
	cube[1050].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1050].scale = D3DXVECTOR3(5, 1, 7);

	cube[1051].position = D3DXVECTOR3(117.12f, -164.39f, 468.30f);
	cube[1051].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1051].scale = D3DXVECTOR3(3, 1, 10);

	cube[1052].position = D3DXVECTOR3(117.31f, -164.72f, 469.62f);
	cube[1052].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1052].scale = D3DXVECTOR3(3, 1, 7);

	cube[1053].position = D3DXVECTOR3(115.87f, -163.23f, 468.07f);
	cube[1053].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1053].scale = D3DXVECTOR3(3, 1, 10);

	cube[1054].position = D3DXVECTOR3(115.62f, -163.34f, 469.38f);
	cube[1054].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1054].scale = D3DXVECTOR3(5, 1, 7);

	cube[1055].position = D3DXVECTOR3(113.89f, -166.09f, 477.19f);
	cube[1055].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1055].scale = D3DXVECTOR3(3, 1, 10);

	cube[1056].position = D3DXVECTOR3(112.65f, -164.93f, 476.96f);
	cube[1056].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1056].scale = D3DXVECTOR3(3, 1, 10);

	cube[1057].position = D3DXVECTOR3(110.64f, -167.81f, 486.14f);
	cube[1057].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1057].scale = D3DXVECTOR3(3, 1, 10);

	cube[1058].position = D3DXVECTOR3(109.40f, -166.65f, 485.91f);
	cube[1058].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1058].scale = D3DXVECTOR3(3, 1, 10);

	cube[1059].position = D3DXVECTOR3(107.51f, -169.46f, 494.70f);
	cube[1059].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1059].scale = D3DXVECTOR3(3, 1, 10);

	cube[1060].position = D3DXVECTOR3(106.27f, -168.30f, 494.47f);
	cube[1060].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1060].scale = D3DXVECTOR3(3, 1, 10);

	cube[1061].position = D3DXVECTOR3(105.08f, -171.07f, 503.21f);
	cube[1061].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1061].scale = D3DXVECTOR3(3, 1, 10);

	cube[1062].position = D3DXVECTOR3(103.82f, -169.91f, 503.20f);
	cube[1062].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1062].scale = D3DXVECTOR3(3, 1, 10);

	cube[1063].position = D3DXVECTOR3(104.20f, -172.66f, 511.66f);
	cube[1063].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1063].scale = D3DXVECTOR3(3, 1, 10);

	cube[1064].position = D3DXVECTOR3(102.95f, -171.50f, 511.87f);
	cube[1064].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1064].scale = D3DXVECTOR3(3, 1, 10);

	cube[1065].position = D3DXVECTOR3(104.83f, -174.29f, 520.44f);
	cube[1065].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1065].scale = D3DXVECTOR3(3, 1, 10);

	cube[1066].position = D3DXVECTOR3(103.63f, -173.13f, 520.86f);
	cube[1066].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1066].scale = D3DXVECTOR3(3, 1, 10);

	cube[1067].position = D3DXVECTOR3(106.94f, -175.92f, 528.93f);
	cube[1067].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1067].scale = D3DXVECTOR3(3, 1, 10);

	cube[1068].position = D3DXVECTOR3(105.84f, -174.76f, 529.56f);
	cube[1068].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1068].scale = D3DXVECTOR3(3, 1, 10);

	cube[1069].position = D3DXVECTOR3(110.22f, -177.64f, 537.93f);
	cube[1069].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1069].scale = D3DXVECTOR3(3, 1, 10);

	cube[1070].position = D3DXVECTOR3(109.12f, -176.48f, 538.55f);
	cube[1070].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1070].scale = D3DXVECTOR3(3, 1, 10);

	cube[1071].position = D3DXVECTOR3(113.50f, -179.37f, 546.93f);
	cube[1071].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1071].scale = D3DXVECTOR3(3, 1, 10);

	cube[1072].position = D3DXVECTOR3(112.40f, -178.21f, 547.55f);
	cube[1072].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1072].scale = D3DXVECTOR3(3, 1, 10);

	cube[1073].position = D3DXVECTOR3(116.72f, -181.06f, 555.77f);
	cube[1073].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1073].scale = D3DXVECTOR3(3, 1, 10);

	cube[1074].position = D3DXVECTOR3(115.62f, -179.90f, 556.39f);
	cube[1074].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1074].scale = D3DXVECTOR3(3, 1, 10);

	cube[1075].position = D3DXVECTOR3(119.89f, -182.74f, 564.50f);
	cube[1075].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1075].scale = D3DXVECTOR3(3, 1, 10);

	cube[1076].position = D3DXVECTOR3(118.79f, -181.58f, 565.12f);
	cube[1076].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1076].scale = D3DXVECTOR3(3, 1, 10);

	cube[1077].position = D3DXVECTOR3(123.05f, -184.42f, 573.17f);
	cube[1077].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1077].scale = D3DXVECTOR3(3, 1, 10);

	cube[1078].position = D3DXVECTOR3(121.95f, -183.26f, 573.79f);
	cube[1078].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1078].scale = D3DXVECTOR3(3, 1, 10);

	cube[1079].position = D3DXVECTOR3(126.29f, -186.16f, 582.10f);
	cube[1079].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1079].scale = D3DXVECTOR3(3, 1, 10);

	cube[1080].position = D3DXVECTOR3(125.19f, -185.00f, 582.72f);
	cube[1080].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1080].scale = D3DXVECTOR3(3, 1, 10);

	cube[1081].position = D3DXVECTOR3(129.52f, -187.86f, 590.98f);
	cube[1081].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1081].scale = D3DXVECTOR3(3, 1, 10);

	cube[1082].position = D3DXVECTOR3(128.42f, -186.70f, 591.60f);
	cube[1082].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1082].scale = D3DXVECTOR3(3, 1, 10);

	cube[1083].position = D3DXVECTOR3(132.69f, -189.56f, 599.77f);
	cube[1083].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1083].scale = D3DXVECTOR3(3, 1, 10);

	cube[1084].position = D3DXVECTOR3(131.59f, -188.40f, 600.40f);
	cube[1084].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1084].scale = D3DXVECTOR3(3, 1, 10);

	cube[1085].position = D3DXVECTOR3(136.30f, -191.17f, 607.85f);
	cube[1085].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1085].scale = D3DXVECTOR3(3, 1, 10);

	cube[1086].position = D3DXVECTOR3(135.32f, -190.01f, 608.66f);
	cube[1086].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1086].scale = D3DXVECTOR3(3, 1, 10);

	cube[1087].position = D3DXVECTOR3(141.06f, -192.76f, 614.90f);
	cube[1087].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1087].scale = D3DXVECTOR3(3, 1, 10);

	cube[1088].position = D3DXVECTOR3(140.23f, -191.60f, 615.86f);
	cube[1088].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1088].scale = D3DXVECTOR3(3, 1, 10);

	cube[1089].position = D3DXVECTOR3(147.18f, -194.39f, 621.22f);
	cube[1089].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1089].scale = D3DXVECTOR3(3, 1, 10);

	cube[1090].position = D3DXVECTOR3(146.53f, -193.23f, 622.31f);
	cube[1090].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1090].scale = D3DXVECTOR3(3, 1, 10);

	cube[1091].position = D3DXVECTOR3(154.26f, -196.02f, 626.36f);
	cube[1091].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1091].scale = D3DXVECTOR3(3, 1, 10);

	cube[1092].position = D3DXVECTOR3(153.81f, -194.86f, 627.55f);
	cube[1092].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1092].scale = D3DXVECTOR3(3, 1, 10);

	cube[1093].position = D3DXVECTOR3(162.08f, -197.62f, 630.18f);
	cube[1093].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1093].scale = D3DXVECTOR3(3, 1, 10);

	cube[1094].position = D3DXVECTOR3(161.85f, -196.46f, 631.43f);
	cube[1094].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1094].scale = D3DXVECTOR3(3, 1, 10);

	cube[1095].position = D3DXVECTOR3(170.53f, -199.26f, 632.59f);
	cube[1095].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1095].scale = D3DXVECTOR3(3, 1, 10);

	cube[1096].position = D3DXVECTOR3(170.52f, -198.10f, 633.86f);
	cube[1096].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1096].scale = D3DXVECTOR3(3, 1, 10);

	cube[1097].position = D3DXVECTOR3(179.05f, -200.92f, 633.42f);
	cube[1097].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1097].scale = D3DXVECTOR3(3, 1, 10);

	cube[1098].position = D3DXVECTOR3(179.26f, -199.76f, 634.67f);
	cube[1098].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1098].scale = D3DXVECTOR3(3, 1, 10);

	cube[1099].position = D3DXVECTOR3(187.32f, -202.46f, 632.84f);
	cube[1099].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1099].scale = D3DXVECTOR3(3, 1, 10);

	cube[1100].position = D3DXVECTOR3(187.75f, -201.30f, 634.04f);
	cube[1100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1100].scale = D3DXVECTOR3(3, 1, 10);

	cube[1101].position = D3DXVECTOR3(196.52f, -204.13f, 631.22f);
	cube[1101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1101].scale = D3DXVECTOR3(3, 1, 10);

	cube[1102].position = D3DXVECTOR3(196.95f, -202.97f, 632.42f);
	cube[1102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1102].scale = D3DXVECTOR3(3, 1, 10);

	cube[1103].position = D3DXVECTOR3(205.85f, -205.82f, 629.58f);
	cube[1103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1103].scale = D3DXVECTOR3(3, 1, 10);

	cube[1104].position = D3DXVECTOR3(206.28f, -204.66f, 630.78f);
	cube[1104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1104].scale = D3DXVECTOR3(3, 1, 10);

	cube[1105].position = D3DXVECTOR3(214.76f, -207.44f, 628.04f);
	cube[1105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1105].scale = D3DXVECTOR3(3, 1, 10);

	cube[1106].position = D3DXVECTOR3(215.18f, -206.28f, 629.23f);
	cube[1106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1106].scale = D3DXVECTOR3(3, 1, 10);

	cube[1107].position = D3DXVECTOR3(221.73f, -209.13f, 627.32f);
	cube[1107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1107].scale = D3DXVECTOR3(3, 1, 10);

	cube[1108].position = D3DXVECTOR3(222.66f, -209.31f, 626.91f);
	cube[1108].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1108].scale = D3DXVECTOR3(3, 1, 7);

	cube[1109].position = D3DXVECTOR3(221.94f, -207.97f, 628.57f);
	cube[1109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1109].scale = D3DXVECTOR3(3, 1, 10);

	cube[1110].position = D3DXVECTOR3(222.96f, -208.00f, 628.42f);
	cube[1110].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1110].scale = D3DXVECTOR3(5, 1, 7);

	cube[1111].position = D3DXVECTOR3(228.47f, -210.79f, 627.76f);
	cube[1111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1111].scale = D3DXVECTOR3(3, 1, 10);

	cube[1112].position = D3DXVECTOR3(229.82f, -211.15f, 627.38f);
	cube[1112].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1112].scale = D3DXVECTOR3(3, 1, 7);

	cube[1113].position = D3DXVECTOR3(228.46f, -209.63f, 629.02f);
	cube[1113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1113].scale = D3DXVECTOR3(3, 1, 10);

	cube[1114].position = D3DXVECTOR3(229.84f, -209.55f, 629.28f);
	cube[1114].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1114].scale = D3DXVECTOR3(5, 1, 7);

	cube[1115].position = D3DXVECTOR3(234.60f, -212.39f, 629.26f);
	cube[1115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1115].scale = D3DXVECTOR3(3, 1, 10);

	cube[1116].position = D3DXVECTOR3(236.01f, -212.65f, 629.16f);
	cube[1116].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1116].scale = D3DXVECTOR3(3, 1, 7);

	cube[1117].position = D3DXVECTOR3(234.37f, -211.23f, 630.50f);
	cube[1117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1117].scale = D3DXVECTOR3(3, 1, 10);

	cube[1118].position = D3DXVECTOR3(235.76f, -211.33f, 630.78f);
	cube[1118].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1118].scale = D3DXVECTOR3(5, 1, 7);

	cube[1119].position = D3DXVECTOR3(240.78f, -214.04f, 631.95f);
	cube[1119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1119].scale = D3DXVECTOR3(3, 1, 10);

	cube[1120].position = D3DXVECTOR3(242.11f, -214.37f, 632.00f);
	cube[1120].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1120].scale = D3DXVECTOR3(3, 1, 7);

	cube[1121].position = D3DXVECTOR3(240.33f, -212.88f, 633.14f);
	cube[1121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1121].scale = D3DXVECTOR3(3, 1, 10);

	cube[1122].position = D3DXVECTOR3(241.58f, -212.99f, 633.61f);
	cube[1122].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1122].scale = D3DXVECTOR3(5, 1, 7);

	cube[1123].position = D3DXVECTOR3(246.49f, -215.75f, 635.84f);
	cube[1123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1123].scale = D3DXVECTOR3(3, 1, 10);

	cube[1124].position = D3DXVECTOR3(247.69f, -215.98f, 636.18f);
	cube[1124].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1124].scale = D3DXVECTOR3(3, 1, 7);

	cube[1125].position = D3DXVECTOR3(245.85f, -214.59f, 636.93f);
	cube[1125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1125].scale = D3DXVECTOR3(3, 1, 10);

	cube[1126].position = D3DXVECTOR3(246.94f, -214.68f, 637.56f);
	cube[1126].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1126].scale = D3DXVECTOR3(5, 1, 7);

	cube[1127].position = D3DXVECTOR3(251.26f, -217.38f, 640.40f);
	cube[1127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1127].scale = D3DXVECTOR3(3, 1, 10);

	cube[1128].position = D3DXVECTOR3(252.51f, -217.71f, 640.90f);
	cube[1128].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1128].scale = D3DXVECTOR3(3, 1, 7);

	cube[1129].position = D3DXVECTOR3(250.44f, -216.22f, 641.36f);
	cube[1129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1129].scale = D3DXVECTOR3(3, 1, 10);

	cube[1130].position = D3DXVECTOR3(251.43f, -216.33f, 642.23f);
	cube[1130].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1130].scale = D3DXVECTOR3(5, 1, 7);

	cube[1131].position = D3DXVECTOR3(255.27f, -219.01f, 645.89f);
	cube[1131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1131].scale = D3DXVECTOR3(3, 1, 10);

	cube[1132].position = D3DXVECTOR3(256.35f, -219.31f, 646.67f);
	cube[1132].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1132].scale = D3DXVECTOR3(3, 1, 7);

	cube[1133].position = D3DXVECTOR3(254.29f, -217.85f, 646.70f);
	cube[1133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1133].scale = D3DXVECTOR3(3, 1, 10);

	cube[1134].position = D3DXVECTOR3(255.13f, -217.97f, 647.75f);
	cube[1134].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1134].scale = D3DXVECTOR3(5, 1, 7);

	cube[1135].position = D3DXVECTOR3(258.14f, -220.57f, 651.67f);
	cube[1135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1135].scale = D3DXVECTOR3(3, 1, 10);

	cube[1136].position = D3DXVECTOR3(258.50f, -220.52f, 652.72f);
	cube[1136].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1136].scale = D3DXVECTOR3(3, 1, 7);

	cube[1137].position = D3DXVECTOR3(257.04f, -219.41f, 652.30f);
	cube[1137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1137].scale = D3DXVECTOR3(3, 1, 10);

	cube[1138].position = D3DXVECTOR3(257.60f, -219.50f, 653.32f);
	cube[1138].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1138].scale = D3DXVECTOR3(5, 1, 7);

	cube[1139].position = D3DXVECTOR3(261.32f, -222.24f, 660.38f);
	cube[1139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1139].scale = D3DXVECTOR3(3, 1, 10);

	cube[1140].position = D3DXVECTOR3(260.22f, -221.08f, 661.00f);
	cube[1140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1140].scale = D3DXVECTOR3(3, 1, 10);

	cube[1141].position = D3DXVECTOR3(264.58f, -223.94f, 669.35f);
	cube[1141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1141].scale = D3DXVECTOR3(3, 1, 10);

	cube[1142].position = D3DXVECTOR3(263.48f, -222.78f, 669.97f);
	cube[1142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1142].scale = D3DXVECTOR3(3, 1, 10);

	cube[1143].position = D3DXVECTOR3(267.84f, -225.71f, 678.28f);
	cube[1143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1143].scale = D3DXVECTOR3(3, 1, 10);

	cube[1144].position = D3DXVECTOR3(266.74f, -224.55f, 678.91f);
	cube[1144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1144].scale = D3DXVECTOR3(3, 1, 10);

	cube[1145].position = D3DXVECTOR3(271.45f, -227.32f, 686.36f);
	cube[1145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1145].scale = D3DXVECTOR3(3, 1, 10);

	cube[1146].position = D3DXVECTOR3(270.47f, -226.16f, 687.17f);
	cube[1146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1146].scale = D3DXVECTOR3(3, 1, 10);

	cube[1147].position = D3DXVECTOR3(276.21f, -228.91f, 693.41f);
	cube[1147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1147].scale = D3DXVECTOR3(3, 1, 10);

	cube[1148].position = D3DXVECTOR3(275.38f, -227.75f, 694.37f);
	cube[1148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1148].scale = D3DXVECTOR3(3, 1, 10);

	cube[1149].position = D3DXVECTOR3(282.33f, -230.54f, 699.73f);
	cube[1149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1149].scale = D3DXVECTOR3(3, 1, 10);

	cube[1150].position = D3DXVECTOR3(281.68f, -229.38f, 700.82f);
	cube[1150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1150].scale = D3DXVECTOR3(3, 1, 10);

	cube[1151].position = D3DXVECTOR3(289.41f, -232.17f, 704.87f);
	cube[1151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1151].scale = D3DXVECTOR3(3, 1, 10);

	cube[1152].position = D3DXVECTOR3(288.96f, -231.01f, 706.06f);
	cube[1152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1152].scale = D3DXVECTOR3(3, 1, 10);

	cube[1153].position = D3DXVECTOR3(297.23f, -233.77f, 708.69f);
	cube[1153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1153].scale = D3DXVECTOR3(3, 1, 10);

	cube[1154].position = D3DXVECTOR3(297.00f, -232.61f, 709.94f);
	cube[1154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1154].scale = D3DXVECTOR3(3, 1, 10);

	cube[1155].position = D3DXVECTOR3(305.68f, -235.41f, 711.10f);
	cube[1155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1155].scale = D3DXVECTOR3(3, 1, 10);

	cube[1156].position = D3DXVECTOR3(305.67f, -234.25f, 712.37f);
	cube[1156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1156].scale = D3DXVECTOR3(3, 1, 10);

	cube[1157].position = D3DXVECTOR3(314.20f, -237.07f, 711.93f);
	cube[1157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1157].scale = D3DXVECTOR3(3, 1, 10);

	cube[1158].position = D3DXVECTOR3(314.41f, -235.91f, 713.18f);
	cube[1158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1158].scale = D3DXVECTOR3(3, 1, 10);

	cube[1159].position = D3DXVECTOR3(322.47f, -238.61f, 711.35f);
	cube[1159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1159].scale = D3DXVECTOR3(3, 1, 10);

	cube[1160].position = D3DXVECTOR3(322.90f, -237.45f, 712.55f);
	cube[1160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1160].scale = D3DXVECTOR3(3, 1, 10);

	cube[1161].position = D3DXVECTOR3(331.83f, -240.37f, 709.72f);
	cube[1161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1161].scale = D3DXVECTOR3(3, 1, 10);

	cube[1162].position = D3DXVECTOR3(332.26f, -239.21f, 710.91f);
	cube[1162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1162].scale = D3DXVECTOR3(3, 1, 10);

	cube[1163].position = D3DXVECTOR3(340.42f, -241.98f, 707.57f);
	cube[1163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1163].scale = D3DXVECTOR3(3, 1, 10);

	cube[1164].position = D3DXVECTOR3(341.04f, -240.82f, 708.67f);
	cube[1164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1164].scale = D3DXVECTOR3(3, 1, 10);

	cube[1165].position = D3DXVECTOR3(348.18f, -243.57f, 704.10f);
	cube[1165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1165].scale = D3DXVECTOR3(3, 1, 10);

	cube[1166].position = D3DXVECTOR3(348.99f, -242.41f, 705.08f);
	cube[1166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1166].scale = D3DXVECTOR3(3, 1, 10);

	cube[1167].position = D3DXVECTOR3(355.47f, -245.20f, 699.17f);
	cube[1167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1167].scale = D3DXVECTOR3(3, 1, 10);

	cube[1168].position = D3DXVECTOR3(356.43f, -244.04f, 700.00f);
	cube[1168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1168].scale = D3DXVECTOR3(3, 1, 10);

	cube[1169].position = D3DXVECTOR3(361.76f, -246.83f, 693.09f);
	cube[1169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1169].scale = D3DXVECTOR3(3, 1, 10);

	cube[1170].position = D3DXVECTOR3(362.85f, -245.67f, 693.74f);
	cube[1170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1170].scale = D3DXVECTOR3(3, 1, 10);

	cube[1171].position = D3DXVECTOR3(366.88f, -248.43f, 686.05f);
	cube[1171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1171].scale = D3DXVECTOR3(3, 1, 10);

	cube[1172].position = D3DXVECTOR3(368.07f, -247.27f, 686.49f);
	cube[1172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1172].scale = D3DXVECTOR3(3, 1, 10);

	cube[1173].position = D3DXVECTOR3(370.72f, -250.07f, 678.15f);
	cube[1173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1173].scale = D3DXVECTOR3(3, 1, 10);

	cube[1174].position = D3DXVECTOR3(371.97f, -248.91f, 678.38f);
	cube[1174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1174].scale = D3DXVECTOR3(3, 1, 10);

	cube[1175].position = D3DXVECTOR3(373.02f, -251.73f, 669.91f);
	cube[1175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1175].scale = D3DXVECTOR3(3, 1, 10);

	cube[1176].position = D3DXVECTOR3(374.28f, -250.57f, 669.92f);
	cube[1176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1176].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1177].position = D3DXVECTOR3(373.89f, -253.27f, 661.66f);
	cube[1177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1177].scale = D3DXVECTOR3(3, 1, 10);

	cube[1178].position = D3DXVECTOR3(375.14f, -252.11f, 661.45f);
	cube[1178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1178].scale = D3DXVECTOR3(3, 1, 10);

	cube[1179].position = D3DXVECTOR3(373.88f, -254.95f, 652.29f);
	cube[1179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1179].scale = D3DXVECTOR3(3, 1, 10);

	cube[1180].position = D3DXVECTOR3(375.13f, -253.79f, 652.08f);
	cube[1180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1180].scale = D3DXVECTOR3(3, 1, 10);

	cube[1181].position = D3DXVECTOR3(373.88f, -256.70f, 642.75f);
	cube[1181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1181].scale = D3DXVECTOR3(3, 1, 10);

	cube[1182].position = D3DXVECTOR3(375.13f, -255.54f, 642.54f);
	cube[1182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1182].scale = D3DXVECTOR3(3, 1, 10);

	cube[1183].position = D3DXVECTOR3(373.88f, -258.40f, 633.36f);
	cube[1183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1183].scale = D3DXVECTOR3(3, 1, 10);

	cube[1184].position = D3DXVECTOR3(375.13f, -257.24f, 633.15f);
	cube[1184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1184].scale = D3DXVECTOR3(3, 1, 10);

	cube[1185].position = D3DXVECTOR3(373.88f, -260.05f, 624.20f);
	cube[1185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1185].scale = D3DXVECTOR3(3, 1, 10);

	cube[1186].position = D3DXVECTOR3(375.13f, -258.89f, 623.99f);
	cube[1186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1186].scale = D3DXVECTOR3(3, 1, 10);

	cube[1187].position = D3DXVECTOR3(373.88f, -261.79f, 614.62f);
	cube[1187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1187].scale = D3DXVECTOR3(3, 1, 10);

	cube[1188].position = D3DXVECTOR3(375.13f, -260.63f, 614.41f);
	cube[1188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1188].scale = D3DXVECTOR3(3, 1, 10);

	cube[1189].position = D3DXVECTOR3(373.88f, -263.37f, 605.90f);
	cube[1189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1189].scale = D3DXVECTOR3(3, 1, 10);

	cube[1190].position = D3DXVECTOR3(375.13f, -262.21f, 605.69f);
	cube[1190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1190].scale = D3DXVECTOR3(3, 1, 10);

	cube[1191].position = D3DXVECTOR3(373.25f, -264.98f, 597.07f);
	cube[1191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1191].scale = D3DXVECTOR3(3, 1, 10);

	cube[1192].position = D3DXVECTOR3(374.44f, -263.82f, 596.65f);
	cube[1192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1192].scale = D3DXVECTOR3(3, 1, 10);

	cube[1193].position = D3DXVECTOR3(371.19f, -266.57f, 588.82f);
	cube[1193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1193].scale = D3DXVECTOR3(3, 1, 10);

	cube[1194].position = D3DXVECTOR3(372.29f, -265.41f, 588.20f);
	cube[1194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1194].scale = D3DXVECTOR3(3, 1, 10);

	cube[1195].position = D3DXVECTOR3(367.60f, -268.20f, 580.79f);
	cube[1195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1195].scale = D3DXVECTOR3(3, 1, 10);

	cube[1196].position = D3DXVECTOR3(368.57f, -267.04f, 579.99f);
	cube[1196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1196].scale = D3DXVECTOR3(3, 1, 10);

	cube[1197].position = D3DXVECTOR3(362.70f, -269.83f, 573.54f);
	cube[1197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1197].scale = D3DXVECTOR3(3, 1, 10);

	cube[1198].position = D3DXVECTOR3(363.52f, -268.67f, 572.57f);
	cube[1198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1198].scale = D3DXVECTOR3(3, 1, 10);

	cube[1199].position = D3DXVECTOR3(356.74f, -271.51f, 566.43f);
	cube[1199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1199].scale = D3DXVECTOR3(3, 1, 10);

	cube[1200].position = D3DXVECTOR3(357.57f, -270.35f, 565.47f);
	cube[1200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1200].scale = D3DXVECTOR3(3, 1, 10);

	cube[1201].position = D3DXVECTOR3(352.63f, -273.20f, 560.75f);
	cube[1201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1201].scale = D3DXVECTOR3(3, 1, 10);

	cube[1202].position = D3DXVECTOR3(351.81f, -273.38f, 560.15f);
	cube[1202].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1202].scale = D3DXVECTOR3(3, 1, 7);

	cube[1203].position = D3DXVECTOR3(353.61f, -272.04f, 559.94f);
	cube[1203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1203].scale = D3DXVECTOR3(3, 1, 10);

	cube[1204].position = D3DXVECTOR3(352.97f, -272.07f, 559.14f);
	cube[1204].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1204].scale = D3DXVECTOR3(5, 1, 7);

	cube[1205].position = D3DXVECTOR3(349.64f, -274.86f, 554.69f);
	cube[1205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1205].scale = D3DXVECTOR3(3, 1, 10);

	cube[1206].position = D3DXVECTOR3(348.64f, -275.22f, 553.71f);
	cube[1206].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1206].scale = D3DXVECTOR3(3, 1, 7);

	cube[1207].position = D3DXVECTOR3(350.75f, -273.70f, 554.07f);
	cube[1207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1207].scale = D3DXVECTOR3(3, 1, 10);

	cube[1208].position = D3DXVECTOR3(350.28f, -273.62f, 552.74f);
	cube[1208].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1208].scale = D3DXVECTOR3(5, 1, 7);

	cube[1209].position = D3DXVECTOR3(347.88f, -276.46f, 548.63f);
	cube[1209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1209].scale = D3DXVECTOR3(3, 1, 10);

	cube[1210].position = D3DXVECTOR3(347.09f, -276.72f, 547.46f);
	cube[1210].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1210].scale = D3DXVECTOR3(3, 1, 7);

	cube[1211].position = D3DXVECTOR3(349.07f, -275.30f, 548.21f);
	cube[1211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1211].scale = D3DXVECTOR3(3, 1, 10);

	cube[1212].position = D3DXVECTOR3(348.62f, -275.40f, 546.87f);
	cube[1212].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1212].scale = D3DXVECTOR3(5, 1, 7);

	cube[1213].position = D3DXVECTOR3(347.12f, -278.11f, 541.94f);
	cube[1213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1213].scale = D3DXVECTOR3(3, 1, 10);

	cube[1214].position = D3DXVECTOR3(346.50f, -278.44f, 540.76f);
	cube[1214].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1214].scale = D3DXVECTOR3(3, 1, 7);

	cube[1215].position = D3DXVECTOR3(348.37f, -276.95f, 541.73f);
	cube[1215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1215].scale = D3DXVECTOR3(3, 1, 10);

	cube[1216].position = D3DXVECTOR3(348.16f, -277.06f, 540.41f);
	cube[1216].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1216].scale = D3DXVECTOR3(5, 1, 7);

	cube[1217].position = D3DXVECTOR3(347.12f, -279.77f, 532.61f);
	cube[1217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1217].scale = D3DXVECTOR3(3, 1, 10);

	cube[1218].position = D3DXVECTOR3(348.37f, -278.61f, 532.40f);
	cube[1218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1218].scale = D3DXVECTOR3(3, 1, 10);

	cube[1219].position = D3DXVECTOR3(347.12f, -281.46f, 523.16f);
	cube[1219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1219].scale = D3DXVECTOR3(3, 1, 10);

	cube[1220].position = D3DXVECTOR3(348.37f, -280.30f, 522.95f);
	cube[1220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1220].scale = D3DXVECTOR3(3, 1, 10);

	cube[1221].position = D3DXVECTOR3(347.12f, -283.01f, 514.73f);
	cube[1221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1221].scale = D3DXVECTOR3(3, 1, 10);

	cube[1222].position = D3DXVECTOR3(348.37f, -281.85f, 514.52f);
	cube[1222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1222].scale = D3DXVECTOR3(3, 1, 10);

	cube[1223].position = D3DXVECTOR3(347.63f, -284.70f, 507.73f);
	cube[1223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1223].scale = D3DXVECTOR3(3, 1, 10);

	cube[1224].position = D3DXVECTOR3(347.38f, -284.88f, 506.75f);
	cube[1224].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1224].scale = D3DXVECTOR3(3, 1, 7);

	cube[1225].position = D3DXVECTOR3(348.90f, -283.54f, 507.74f);
	cube[1225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1225].scale = D3DXVECTOR3(3, 1, 10);

	cube[1226].position = D3DXVECTOR3(348.92f, -283.57f, 506.72f);
	cube[1226].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1226].scale = D3DXVECTOR3(5, 1, 7);

	cube[1227].position = D3DXVECTOR3(349.23f, -286.36f, 501.17f);
	cube[1227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1227].scale = D3DXVECTOR3(3, 1, 10);

	cube[1228].position = D3DXVECTOR3(349.09f, -286.72f, 499.78f);
	cube[1228].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1228].scale = D3DXVECTOR3(3, 1, 7);

	cube[1229].position = D3DXVECTOR3(350.48f, -285.20f, 501.40f);
	cube[1229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1229].scale = D3DXVECTOR3(3, 1, 10);

	cube[1230].position = D3DXVECTOR3(350.97f, -285.12f, 500.09f);
	cube[1230].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1230].scale = D3DXVECTOR3(5, 1, 7);

	cube[1231].position = D3DXVECTOR3(351.77f, -287.96f, 495.39f);
	cube[1231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1231].scale = D3DXVECTOR3(3, 1, 10);

	cube[1232].position = D3DXVECTOR3(351.92f, -288.22f, 493.99f);
	cube[1232].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1232].scale = D3DXVECTOR3(3, 1, 7);

	cube[1233].position = D3DXVECTOR3(352.96f, -286.80f, 495.84f);
	cube[1233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1233].scale = D3DXVECTOR3(3, 1, 10);

	cube[1234].position = D3DXVECTOR3(353.47f, -286.90f, 494.52f);
	cube[1234].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1234].scale = D3DXVECTOR3(5, 1, 7);

	cube[1235].position = D3DXVECTOR3(355.49f, -289.61f, 489.78f);
	cube[1235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1235].scale = D3DXVECTOR3(3, 1, 10);

	cube[1236].position = D3DXVECTOR3(355.77f, -289.94f, 488.48f);
	cube[1236].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1236].scale = D3DXVECTOR3(3, 1, 7);

	cube[1237].position = D3DXVECTOR3(356.59f, -288.45f, 490.42f);
	cube[1237].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1237].scale = D3DXVECTOR3(3, 1, 10);

	cube[1238].position = D3DXVECTOR3(357.27f, -288.56f, 489.28f);
	cube[1238].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1238].scale = D3DXVECTOR3(5, 1, 7);

	cube[1239].position = D3DXVECTOR3(361.64f, -291.33f, 482.44f);
	cube[1239].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1239].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1240].position = D3DXVECTOR3(362.73f, -290.17f, 483.08f);
	cube[1240].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1240].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1241].position = D3DXVECTOR3(367.69f, -293.03f, 475.23f);
	cube[1241].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1241].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1242].position = D3DXVECTOR3(368.78f, -291.87f, 475.87f);
	cube[1242].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1242].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1243].position = D3DXVECTOR3(373.81f, -294.76f, 467.93f);
	cube[1243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1243].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1244].position = D3DXVECTOR3(374.90f, -293.60f, 468.57f);
	cube[1244].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1244].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1245].position = D3DXVECTOR3(379.92f, -296.51f, 460.70f);
	cube[1245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1245].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1246].position = D3DXVECTOR3(381.02f, -295.35f, 461.34f);
	cube[1246].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1246].scale = D3DXVECTOR3(3, 1, 10);

	cube[1247].position = D3DXVECTOR3(384.81f, -298.20f, 455.66f);
	cube[1247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1247].scale = D3DXVECTOR3(3, 1, 10);

	cube[1248].position = D3DXVECTOR3(385.25f, -298.38f, 454.75f);
	cube[1248].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1248].scale = D3DXVECTOR3(3, 1, 7);

	cube[1249].position = D3DXVECTOR3(385.77f, -297.04f, 456.49f);
	cube[1249].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1249].scale = D3DXVECTOR3(3, 1, 10);

	cube[1250].position = D3DXVECTOR3(386.45f, -297.07f, 455.72f);
	cube[1250].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1250].scale = D3DXVECTOR3(5, 1, 7);

	cube[1251].position = D3DXVECTOR3(390.25f, -299.86f, 451.67f);
	cube[1251].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1251].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1252].position = D3DXVECTOR3(391.04f, -300.22f, 450.51f);
	cube[1252].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1252].scale = D3DXVECTOR3(3, 1, 7);

	cube[1253].position = D3DXVECTOR3(391.06f, -298.70f, 452.64f);
	cube[1253].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1253].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1254].position = D3DXVECTOR3(392.28f, -298.62f, 451.96f);
	cube[1254].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1254].scale = D3DXVECTOR3(5, 1, 7);

	cube[1255].position = D3DXVECTOR3(395.91f, -301.46f, 448.87f);
	cube[1255].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1255].scale = D3DXVECTOR3(3, 1, 10);

	cube[1256].position = D3DXVECTOR3(396.93f, -301.72f, 447.89f);
	cube[1256].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1256].scale = D3DXVECTOR3(3, 1, 7);

	cube[1257].position = D3DXVECTOR3(396.54f, -300.30f, 449.98f);
	cube[1257].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1257].scale = D3DXVECTOR3(3, 1, 10);

	cube[1258].position = D3DXVECTOR3(397.78f, -300.40f, 449.30f);
	cube[1258].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1258].scale = D3DXVECTOR3(5, 1, 7);

	cube[1259].position = D3DXVECTOR3(402.37f, -303.11f, 446.97f);
	cube[1259].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1259].scale = D3DXVECTOR3(3, 1, 10);

	cube[1260].position = D3DXVECTOR3(403.42f, -303.44f, 446.15f);
	cube[1260].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1260].scale = D3DXVECTOR3(3, 1, 7);

	cube[1261].position = D3DXVECTOR3(402.79f, -301.95f, 448.16f);
	cube[1261].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1261].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1262].position = D3DXVECTOR3(404.06f, -302.06f, 447.73f);
	cube[1262].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1262].scale = D3DXVECTOR3(5, 1, 7);

	cube[1263].position = D3DXVECTOR3(409.25f, -304.82f, 446.28f);
	cube[1263].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1263].scale = D3DXVECTOR3(3, 1, 10);

	cube[1264].position = D3DXVECTOR3(410.39f, -305.05f, 445.77f);
	cube[1264].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1264].scale = D3DXVECTOR3(3, 1, 7);

	cube[1265].position = D3DXVECTOR3(409.46f, -303.66f, 447.53f);
	cube[1265].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1265].scale = D3DXVECTOR3(3, 1, 10);

	cube[1266].position = D3DXVECTOR3(410.70f, -303.75f, 447.31f);
	cube[1266].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1266].scale = D3DXVECTOR3(5, 1, 7);

	cube[1267].position = D3DXVECTOR3(415.83f, -306.45f, 446.70f);
	cube[1267].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1267].scale = D3DXVECTOR3(3, 1, 10);

	cube[1268].position = D3DXVECTOR3(417.12f, -306.78f, 446.28f);
	cube[1268].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1268].scale = D3DXVECTOR3(3, 1, 7);

	cube[1269].position = D3DXVECTOR3(415.82f, -305.29f, 447.97f);
	cube[1269].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1269].scale = D3DXVECTOR3(3, 1, 10);

	cube[1270].position = D3DXVECTOR3(417.14f, -305.40f, 448.00f);
	cube[1270].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1270].scale = D3DXVECTOR3(5, 1, 7);

	cube[1271].position = D3DXVECTOR3(425.01f, -308.13f, 448.32f);
	cube[1271].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1271].scale = D3DXVECTOR3(3, 1, 10);

	cube[1272].position = D3DXVECTOR3(425.00f, -306.97f, 449.59f);
	cube[1272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1272].scale = D3DXVECTOR3(3, 1, 10);

	cube[1273].position = D3DXVECTOR3(434.56f, -309.89f, 450.00f);
	cube[1273].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1273].scale = D3DXVECTOR3(3, 1, 10);

	cube[1274].position = D3DXVECTOR3(434.55f, -308.73f, 451.27f);
	cube[1274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1274].scale = D3DXVECTOR3(3, 1, 10);

	cube[1275].position = D3DXVECTOR3(443.94f, -311.61f, 451.66f);
	cube[1275].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1275].scale = D3DXVECTOR3(3, 1, 10);

	cube[1276].position = D3DXVECTOR3(443.93f, -310.45f, 452.93f);
	cube[1276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1276].scale = D3DXVECTOR3(3, 1, 10);

	cube[1277].position = D3DXVECTOR3(453.38f, -313.34f, 453.32f);
	cube[1277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1277].scale = D3DXVECTOR3(3, 1, 10);

	cube[1278].position = D3DXVECTOR3(453.37f, -312.18f, 454.59f);
	cube[1278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1278].scale = D3DXVECTOR3(3, 1, 10);

	cube[1279].position = D3DXVECTOR3(462.78f, -315.05f, 454.99f);
	cube[1279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1279].scale = D3DXVECTOR3(3, 1, 10);

	cube[1280].position = D3DXVECTOR3(462.77f, -313.89f, 456.26f);
	cube[1280].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1280].scale = D3DXVECTOR3(3, 1, 10);

	cube[1281].position = D3DXVECTOR3(472.33f, -316.79f, 456.66f);
	cube[1281].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1281].scale = D3DXVECTOR3(3, 1, 10);

	cube[1282].position = D3DXVECTOR3(472.32f, -315.63f, 457.93f);
	cube[1282].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1282].scale = D3DXVECTOR3(3, 1, 10);

	cube[1283].position = D3DXVECTOR3(481.62f, -318.47f, 458.30f);
	cube[1283].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1283].scale = D3DXVECTOR3(3, 1, 10);

	cube[1284].position = D3DXVECTOR3(481.61f, -317.31f, 459.57f);
	cube[1284].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1284].scale = D3DXVECTOR3(3, 1, 10);

	cube[1285].position = D3DXVECTOR3(491.03f, -320.18f, 459.96f);
	cube[1285].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1285].scale = D3DXVECTOR3(3, 1, 10);

	cube[1286].position = D3DXVECTOR3(491.02f, -319.02f, 461.23f);
	cube[1286].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1286].scale = D3DXVECTOR3(3, 1, 10);

	cube[1287].position = D3DXVECTOR3(500.42f, -321.89f, 461.62f);
	cube[1287].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1287].scale = D3DXVECTOR3(3, 1, 10);

	cube[1288].position = D3DXVECTOR3(500.41f, -320.73f, 462.89f);
	cube[1288].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1288].scale = D3DXVECTOR3(3, 1, 10);

	cube[1289].position = D3DXVECTOR3(509.78f, -323.59f, 463.27f);
	cube[1289].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1289].scale = D3DXVECTOR3(3, 1, 10);

	cube[1290].position = D3DXVECTOR3(509.77f, -322.43f, 464.54f);
	cube[1290].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1290].scale = D3DXVECTOR3(3, 1, 10);

	rightWall[0].position = D3DXVECTOR3(8.30f, -6.11f, 2.95f);
	rightWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[0].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[1].position = D3DXVECTOR3(8.30f, -7.77f, 11.95f);
	rightWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[1].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[2].position = D3DXVECTOR3(8.30f, -9.36f, 20.65f);
	rightWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[2].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[3].position = D3DXVECTOR3(8.30f, -11.04f, 29.75f);
	rightWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[3].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[4].position = D3DXVECTOR3(8.30f, -12.83f, 39.15f);
	rightWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[4].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[5].position = D3DXVECTOR3(8.30f, -14.51f, 48.45f);
	rightWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[5].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[6].position = D3DXVECTOR3(8.30f, -16.30f, 58.15f);
	rightWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[6].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[7].position = D3DXVECTOR3(8.30f, -17.89f, 66.95f);
	rightWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[7].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[8].position = D3DXVECTOR3(8.30f, -19.26f, 74.56f);
	rightWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[8].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[9].position = D3DXVECTOR3(7.43f, -20.95f, 84.08f);
	rightWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[9].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[10].position = D3DXVECTOR3(5.04f, -22.61f, 93.06f);
	rightWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[10].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[11].position = D3DXVECTOR3(1.30f, -24.21f, 101.08f);
	rightWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[11].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[12].position = D3DXVECTOR3(-3.99f, -25.86f, 108.69f);
	rightWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[12].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[13].position = D3DXVECTOR3(-10.71f, -27.57f, 115.34f);
	rightWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[13].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[14].position = D3DXVECTOR3(-18.18f, -29.20f, 120.59f);
	rightWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[14].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[15].position = D3DXVECTOR3(-26.27f, -30.92f, 125.26f);
	rightWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[15].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[16].position = D3DXVECTOR3(-34.23f, -32.65f, 129.87f);
	rightWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[16].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[17].position = D3DXVECTOR3(-41.53f, -34.20f, 134.07f);
	rightWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[17].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[18].position = D3DXVECTOR3(-48.83f, -35.72f, 138.27f);
	rightWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[18].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[19].position = D3DXVECTOR3(-56.73f, -37.45f, 142.87f);
	rightWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[19].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[20].position = D3DXVECTOR3(-64.59f, -39.09f, 147.34f);
	rightWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[20].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[21].position = D3DXVECTOR3(-73.26f, -40.78f, 151.35f);
	rightWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[21].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[22].position = D3DXVECTOR3(-82.23f, -42.44f, 153.77f);
	rightWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[22].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[23].position = D3DXVECTOR3(-91.05f, -44.04f, 154.54f);
	rightWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[23].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[24].position = D3DXVECTOR3(-100.29f, -45.69f, 153.76f);
	rightWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[24].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[25].position = D3DXVECTOR3(-106.95f, -46.99f, 152.57f);
	rightWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[25].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[26].position = D3DXVECTOR3(-114.19f, -48.77f, 152.02f);
	rightWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[26].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[27].position = D3DXVECTOR3(-120.13f, -50.36f, 152.70f);
	rightWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[27].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[28].position = D3DXVECTOR3(-126.11f, -51.99f, 154.48f);
	rightWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[28].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[29].position = D3DXVECTOR3(-131.68f, -53.62f, 157.24f);
	rightWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[29].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[30].position = D3DXVECTOR3(-136.62f, -55.22f, 160.88f);
	rightWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[30].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[31].position = D3DXVECTOR3(-140.91f, -56.85f, 165.39f);
	rightWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[31].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[32].position = D3DXVECTOR3(-144.20f, -58.51f, 170.47f);
	rightWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[32].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[33].position = D3DXVECTOR3(-146.57f, -60.09f, 175.99f);
	rightWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[33].scale = D3DXVECTOR3(5, 1, 7.5);

	rightWall[34].position = D3DXVECTOR3(-148.65f, -61.25f, 181.57f);
	rightWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[34].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[35].position = D3DXVECTOR3(-150.45f, -63.03f, 188.60f);
	rightWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[35].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[36].position = D3DXVECTOR3(-150.81f, -64.62f, 194.57f);
	rightWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[36].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[37].position = D3DXVECTOR3(-150.10f, -66.25f, 200.77f);
	rightWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[37].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[38].position = D3DXVECTOR3(-148.35f, -67.88f, 206.74f);
	rightWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[38].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[39].position = D3DXVECTOR3(-145.62f, -69.48f, 212.23f);
	rightWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[39].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[40].position = D3DXVECTOR3(-141.92f, -71.11f, 217.24f);
	rightWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[40].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[41].position = D3DXVECTOR3(-137.49f, -72.77f, 221.36f);
	rightWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[41].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[42].position = D3DXVECTOR3(-132.47f, -74.35f, 224.66f);
	rightWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[42].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[43].position = D3DXVECTOR3(-125.77f, -75.83f, 228.54f);
	rightWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[43].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[44].position = D3DXVECTOR3(-117.69f, -77.53f, 233.21f);
	rightWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[44].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[45].position = D3DXVECTOR3(-109.19f, -79.28f, 238.14f);
	rightWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[45].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[46].position = D3DXVECTOR3(-101.14f, -80.94f, 242.87f);
	rightWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[46].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[47].position = D3DXVECTOR3(-94.52f, -82.72f, 245.87f);
	rightWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[47].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[48].position = D3DXVECTOR3(-88.71f, -84.31f, 247.26f);
	rightWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[48].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[49].position = D3DXVECTOR3(-82.48f, -85.94f, 247.63f);
	rightWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[49].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[50].position = D3DXVECTOR3(-76.30f, -87.57f, 246.94f);
	rightWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[50].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[51].position = D3DXVECTOR3(-67.97f, -89.10f, 245.47f);
	rightWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[51].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[52].position = D3DXVECTOR3(-58.45f, -90.79f, 244.67f);
	rightWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[52].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[53].position = D3DXVECTOR3(-49.19f, -92.45f, 245.47f);
	rightWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[53].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[54].position = D3DXVECTOR3(-40.64f, -94.05f, 247.76f);
	rightWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[54].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[55].position = D3DXVECTOR3(-32.22f, -95.70f, 251.65f);
	rightWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[55].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[56].position = D3DXVECTOR3(-24.31f, -97.37f, 256.25f);
	rightWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[56].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[57].position = D3DXVECTOR3(-17.69f, -99.15f, 259.25f);
	rightWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[57].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[58].position = D3DXVECTOR3(-11.88f, -100.74f, 260.64f);
	rightWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[58].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[59].position = D3DXVECTOR3(-5.65f, -102.37f, 261.01f);
	rightWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[59].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[60].position = D3DXVECTOR3(0.53f, -104.00f, 260.32f);
	rightWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[60].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[61].position = D3DXVECTOR3(8.71f, -105.55f, 258.92f);
	rightWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[61].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[62].position = D3DXVECTOR3(18.23f, -107.24f, 258.12f);
	rightWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[62].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[63].position = D3DXVECTOR3(27.49f, -108.90f, 258.92f);
	rightWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[63].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[64].position = D3DXVECTOR3(36.04f, -110.50f, 261.21f);
	rightWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[64].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[65].position = D3DXVECTOR3(44.46f, -112.15f, 265.10f);
	rightWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[65].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[66].position = D3DXVECTOR3(52.41f, -113.89f, 269.68f);
	rightWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[66].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[67].position = D3DXVECTOR3(60.44f, -115.58f, 274.33f);
	rightWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[67].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[68].position = D3DXVECTOR3(68.70f, -117.30f, 279.09f);
	rightWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[68].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[69].position = D3DXVECTOR3(76.82f, -119.00f, 283.76f);
	rightWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[69].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[70].position = D3DXVECTOR3(84.92f, -120.67f, 288.42f);
	rightWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[70].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[71].position = D3DXVECTOR3(93.22f, -122.37f, 293.20f);
	rightWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[71].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[72].position = D3DXVECTOR3(100.80f, -123.94f, 297.52f);
	rightWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[72].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[73].position = D3DXVECTOR3(108.60f, -125.63f, 303.03f);
	rightWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[73].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[74].position = D3DXVECTOR3(115.18f, -127.29f, 309.59f);
	rightWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[74].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[75].position = D3DXVECTOR3(120.26f, -128.89f, 316.84f);
	rightWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[75].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[76].position = D3DXVECTOR3(124.21f, -130.54f, 325.23f);
	rightWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[76].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[77].position = D3DXVECTOR3(127.43f, -132.23f, 334.08f);
	rightWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[77].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[78].position = D3DXVECTOR3(130.51f, -133.89f, 342.55f);
	rightWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[78].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[79].position = D3DXVECTOR3(133.64f, -135.54f, 351.00f);
	rightWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[79].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[80].position = D3DXVECTOR3(136.08f, -137.23f, 360.23f);
	rightWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[80].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[81].position = D3DXVECTOR3(136.90f, -138.89f, 369.49f);
	rightWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[81].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[82].position = D3DXVECTOR3(136.13f, -140.49f, 378.30f);
	rightWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[82].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[83].position = D3DXVECTOR3(133.76f, -142.14f, 387.27f);
	rightWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[83].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[84].position = D3DXVECTOR3(130.44f, -143.87f, 396.34f);
	rightWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[84].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[85].position = D3DXVECTOR3(127.31f, -145.53f, 404.86f);
	rightWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[85].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[86].position = D3DXVECTOR3(125.51f, -147.31f, 411.89f);
	rightWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[86].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[87].position = D3DXVECTOR3(125.15f, -148.90f, 417.86f);
	rightWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[87].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[88].position = D3DXVECTOR3(125.86f, -150.53f, 424.06f);
	rightWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[88].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[89].position = D3DXVECTOR3(127.61f, -152.16f, 430.03f);
	rightWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[89].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[90].position = D3DXVECTOR3(130.42f, -153.66f, 437.76f);
	rightWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[90].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[91].position = D3DXVECTOR3(132.86f, -155.35f, 446.99f);
	rightWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[91].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[92].position = D3DXVECTOR3(133.68f, -157.01f, 456.25f);
	rightWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[92].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[93].position = D3DXVECTOR3(132.91f, -158.61f, 465.06f);
	rightWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[93].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[94].position = D3DXVECTOR3(130.54f, -160.26f, 474.03f);
	rightWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[94].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[95].position = D3DXVECTOR3(127.31f, -161.96f, 482.92f);
	rightWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[95].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[96].position = D3DXVECTOR3(124.06f, -163.68f, 491.87f);
	rightWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[96].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[97].position = D3DXVECTOR3(120.93f, -165.33f, 500.43f);
	rightWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[97].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[98].position = D3DXVECTOR3(119.13f, -167.11f, 507.46f);
	rightWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[98].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[99].position = D3DXVECTOR3(118.77f, -168.70f, 513.43f);
	rightWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[99].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[100].position = D3DXVECTOR3(119.48f, -170.33f, 519.63f);
	rightWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[100].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[101].position = D3DXVECTOR3(121.23f, -171.96f, 525.60f);
	rightWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[101].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[102].position = D3DXVECTOR3(124.18f, -173.51f, 533.69f);
	rightWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[102].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[103].position = D3DXVECTOR3(127.46f, -175.24f, 542.69f);
	rightWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[103].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[104].position = D3DXVECTOR3(130.68f, -176.93f, 551.53f);
	rightWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[104].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[105].position = D3DXVECTOR3(133.85f, -178.61f, 560.26f);
	rightWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[105].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[106].position = D3DXVECTOR3(137.01f, -180.29f, 568.93f);
	rightWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[106].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[107].position = D3DXVECTOR3(140.25f, -182.03f, 577.86f);
	rightWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[107].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[108].position = D3DXVECTOR3(143.48f, -183.73f, 586.74f);
	rightWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[108].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[109].position = D3DXVECTOR3(146.65f, -185.43f, 595.53f);
	rightWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[109].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[110].position = D3DXVECTOR3(149.79f, -187.21f, 602.09f);
	rightWall[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[110].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[111].position = D3DXVECTOR3(153.35f, -188.80f, 606.89f);
	rightWall[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[111].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[112].position = D3DXVECTOR3(157.88f, -190.43f, 611.18f);
	rightWall[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[112].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[113].position = D3DXVECTOR3(163.06f, -192.06f, 614.62f);
	rightWall[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[113].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[114].position = D3DXVECTOR3(168.68f, -193.66f, 617.08f);
	rightWall[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[114].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[115].position = D3DXVECTOR3(174.73f, -195.29f, 618.54f);
	rightWall[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[115].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[116].position = D3DXVECTOR3(180.77f, -196.95f, 618.85f);
	rightWall[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[116].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[117].position = D3DXVECTOR3(186.74f, -198.53f, 618.15f);
	rightWall[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[117].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[118].position = D3DXVECTOR3(194.77f, -200.00f, 616.74f);
	rightWall[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[118].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[119].position = D3DXVECTOR3(204.10f, -201.69f, 615.10f);
	rightWall[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[119].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[120].position = D3DXVECTOR3(213.00f, -203.31f, 613.55f);
	rightWall[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[120].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[121].position = D3DXVECTOR3(222.52f, -205.00f, 612.75f);
	rightWall[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[121].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[122].position = D3DXVECTOR3(231.78f, -206.66f, 613.55f);
	rightWall[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[122].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[123].position = D3DXVECTOR3(240.33f, -208.26f, 615.84f);
	rightWall[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[123].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[124].position = D3DXVECTOR3(248.75f, -209.91f, 619.73f);
	rightWall[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[124].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[125].position = D3DXVECTOR3(256.46f, -211.62f, 625.19f);
	rightWall[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[125].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[126].position = D3DXVECTOR3(262.93f, -213.25f, 631.64f);
	rightWall[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[126].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[127].position = D3DXVECTOR3(268.28f, -214.88f, 639.29f);
	rightWall[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[127].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[128].position = D3DXVECTOR3(272.10f, -216.44f, 647.43f);
	rightWall[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[128].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[129].position = D3DXVECTOR3(275.28f, -218.11f, 656.14f);
	rightWall[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[129].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[130].position = D3DXVECTOR3(278.54f, -219.81f, 665.11f);
	rightWall[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[130].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[131].position = D3DXVECTOR3(281.80f, -221.58f, 674.04f);
	rightWall[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[131].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[132].position = D3DXVECTOR3(284.94f, -223.36f, 680.60f);
	rightWall[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[132].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[133].position = D3DXVECTOR3(288.50f, -224.95f, 685.40f);
	rightWall[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[133].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[134].position = D3DXVECTOR3(293.03f, -226.58f, 689.69f);
	rightWall[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[134].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[135].position = D3DXVECTOR3(298.21f, -228.21f, 693.13f);
	rightWall[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[135].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[136].position = D3DXVECTOR3(303.83f, -229.81f, 695.59f);
	rightWall[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[136].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[137].position = D3DXVECTOR3(309.88f, -231.44f, 697.05f);
	rightWall[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[137].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[138].position = D3DXVECTOR3(315.92f, -233.10f, 697.36f);
	rightWall[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[138].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[139].position = D3DXVECTOR3(321.89f, -234.68f, 696.66f);
	rightWall[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[139].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[140].position = D3DXVECTOR3(330.08f, -236.24f, 695.23f);
	rightWall[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[140].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[141].position = D3DXVECTOR3(337.08f, -238.02f, 693.28f);
	rightWall[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[141].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[142].position = D3DXVECTOR3(342.43f, -239.61f, 690.61f);
	rightWall[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[142].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[143].position = D3DXVECTOR3(347.44f, -241.24f, 686.89f);
	rightWall[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[143].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[144].position = D3DXVECTOR3(351.73f, -242.87f, 682.39f);
	rightWall[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[144].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[145].position = D3DXVECTOR3(355.12f, -244.47f, 677.28f);
	rightWall[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[145].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[146].position = D3DXVECTOR3(357.61f, -246.10f, 671.57f);
	rightWall[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[146].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[147].position = D3DXVECTOR3(358.97f, -247.76f, 665.68f);
	rightWall[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[147].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[148].position = D3DXVECTOR3(359.31f, -249.34f, 659.68f);
	rightWall[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[148].scale = D3DXVECTOR3(5, 1, 7.500008);

	rightWall[149].position = D3DXVECTOR3(359.31f, -250.82f, 651.50f);
	rightWall[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[149].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[150].position = D3DXVECTOR3(359.31f, -252.57f, 641.96f);
	rightWall[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[150].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[151].position = D3DXVECTOR3(359.31f, -254.27f, 632.57f);
	rightWall[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[151].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[152].position = D3DXVECTOR3(359.31f, -255.92f, 623.41f);
	rightWall[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[152].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[153].position = D3DXVECTOR3(359.31f, -257.66f, 613.83f);
	rightWall[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[153].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[154].position = D3DXVECTOR3(359.31f, -259.24f, 605.11f);
	rightWall[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[154].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[155].position = D3DXVECTOR3(358.60f, -261.02f, 597.88f);
	rightWall[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[155].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[156].position = D3DXVECTOR3(356.90f, -262.61f, 592.15f);
	rightWall[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[156].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[157].position = D3DXVECTOR3(354.11f, -264.24f, 586.57f);
	rightWall[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[157].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[158].position = D3DXVECTOR3(350.42f, -265.87f, 581.56f);
	rightWall[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[158].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[159].position = D3DXVECTOR3(345.07f, -267.38f, 575.19f);
	rightWall[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[159].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[160].position = D3DXVECTOR3(339.62f, -269.07f, 567.35f);
	rightWall[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[160].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[161].position = D3DXVECTOR3(335.68f, -270.73f, 558.93f);
	rightWall[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[161].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[162].position = D3DXVECTOR3(333.39f, -272.33f, 550.39f);
	rightWall[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[162].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[163].position = D3DXVECTOR3(332.55f, -273.98f, 541.15f);
	rightWall[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[163].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[164].position = D3DXVECTOR3(332.55f, -275.64f, 531.82f);
	rightWall[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[164].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[165].position = D3DXVECTOR3(332.55f, -277.33f, 522.37f);
	rightWall[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[165].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[166].position = D3DXVECTOR3(332.55f, -278.88f, 513.94f);
	rightWall[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[166].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[167].position = D3DXVECTOR3(333.42f, -280.57f, 504.42f);
	rightWall[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[167].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[168].position = D3DXVECTOR3(335.81f, -282.23f, 495.44f);
	rightWall[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[168].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[169].position = D3DXVECTOR3(339.55f, -283.83f, 487.42f);
	rightWall[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[169].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[170].position = D3DXVECTOR3(344.84f, -285.48f, 479.81f);
	rightWall[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[170].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[171].position = D3DXVECTOR3(350.99f, -287.20f, 472.47f);
	rightWall[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[171].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[172].position = D3DXVECTOR3(357.04f, -288.90f, 465.26f);
	rightWall[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[172].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[173].position = D3DXVECTOR3(363.16f, -290.63f, 457.96f);
	rightWall[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[173].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[174].position = D3DXVECTOR3(369.27f, -292.38f, 450.73f);
	rightWall[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[174].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[175].position = D3DXVECTOR3(376.05f, -294.07f, 444.00f);
	rightWall[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[175].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[176].position = D3DXVECTOR3(383.65f, -295.73f, 438.65f);
	rightWall[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[176].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[177].position = D3DXVECTOR3(391.67f, -297.33f, 434.91f);
	rightWall[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[177].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[178].position = D3DXVECTOR3(400.62f, -298.98f, 432.48f);
	rightWall[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[178].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[179].position = D3DXVECTOR3(410.04f, -300.69f, 431.71f);
	rightWall[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[179].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[180].position = D3DXVECTOR3(419.14f, -302.32f, 432.49f);
	rightWall[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[180].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[181].position = D3DXVECTOR3(428.32f, -304.00f, 434.11f);
	rightWall[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[181].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[182].position = D3DXVECTOR3(437.87f, -305.76f, 435.79f);
	rightWall[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[182].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[183].position = D3DXVECTOR3(447.25f, -307.48f, 437.45f);
	rightWall[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[183].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[184].position = D3DXVECTOR3(456.69f, -309.21f, 439.11f);
	rightWall[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[184].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[185].position = D3DXVECTOR3(466.09f, -310.92f, 440.78f);
	rightWall[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[185].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[186].position = D3DXVECTOR3(475.64f, -312.66f, 442.45f);
	rightWall[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[186].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[187].position = D3DXVECTOR3(484.93f, -314.34f, 444.09f);
	rightWall[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[187].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[188].position = D3DXVECTOR3(494.34f, -316.05f, 445.75f);
	rightWall[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[188].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[189].position = D3DXVECTOR3(503.73f, -317.76f, 447.41f);
	rightWall[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[189].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[190].position = D3DXVECTOR3(513.09f, -319.46f, 449.06f);
	rightWall[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[190].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[0].position = D3DXVECTOR3(-8.76f, -6.34f, 2.89f);
	leftWall[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[0].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[1].position = D3DXVECTOR3(-8.76f, -8.00f, 11.89f);
	leftWall[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[1].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[2].position = D3DXVECTOR3(-8.76f, -9.59f, 20.59f);
	leftWall[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[2].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[3].position = D3DXVECTOR3(-8.76f, -11.27f, 29.69f);
	leftWall[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[3].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[4].position = D3DXVECTOR3(-8.76f, -13.06f, 39.09f);
	leftWall[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[4].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[5].position = D3DXVECTOR3(-8.76f, -14.74f, 48.39f);
	leftWall[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[5].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[6].position = D3DXVECTOR3(-8.76f, -16.53f, 58.09f);
	leftWall[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[6].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[7].position = D3DXVECTOR3(-8.76f, -18.12f, 66.89f);
	leftWall[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[7].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[8].position = D3DXVECTOR3(-8.76f, -19.49f, 74.50f);
	leftWall[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[8].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[9].position = D3DXVECTOR3(-9.52f, -21.35f, 81.98f);
	leftWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[9].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[10].position = D3DXVECTOR3(-11.28f, -23.00f, 88.02f);
	leftWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[10].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[11].position = D3DXVECTOR3(-13.91f, -24.61f, 93.31f);
	leftWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[11].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[12].position = D3DXVECTOR3(-17.62f, -26.25f, 98.39f);
	leftWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[12].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[13].position = D3DXVECTOR3(-22.35f, -27.97f, 102.83f);
	leftWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[13].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[14].position = D3DXVECTOR3(-27.46f, -29.59f, 106.25f);
	leftWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[14].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[15].position = D3DXVECTOR3(-34.75f, -31.15f, 110.46f);
	leftWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[15].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[16].position = D3DXVECTOR3(-42.71f, -32.88f, 115.07f);
	leftWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[16].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[17].position = D3DXVECTOR3(-50.01f, -34.43f, 119.27f);
	leftWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[17].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[18].position = D3DXVECTOR3(-57.31f, -35.95f, 123.47f);
	leftWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[18].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[19].position = D3DXVECTOR3(-65.21f, -37.68f, 128.07f);
	leftWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[19].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[20].position = D3DXVECTOR3(-73.07f, -39.32f, 132.54f);
	leftWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[20].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[21].position = D3DXVECTOR3(-79.93f, -41.18f, 135.62f);
	leftWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[21].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[22].position = D3DXVECTOR3(-86.04f, -42.83f, 137.11f);
	leftWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[22].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[23].position = D3DXVECTOR3(-91.93f, -44.44f, 137.48f);
	leftWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[23].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[24].position = D3DXVECTOR3(-98.19f, -46.08f, 136.81f);
	leftWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[24].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[25].position = D3DXVECTOR3(-103.92f, -47.22f, 135.78f);
	leftWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[25].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[26].position = D3DXVECTOR3(-113.17f, -48.83f, 134.96f);
	leftWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[26].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[27].position = D3DXVECTOR3(-122.07f, -50.42f, 135.72f);
	leftWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[27].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[28].position = D3DXVECTOR3(-130.99f, -52.05f, 138.10f);
	leftWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[28].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[29].position = D3DXVECTOR3(-139.32f, -53.68f, 141.96f);
	leftWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[29].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[30].position = D3DXVECTOR3(-146.83f, -55.28f, 147.18f);
	leftWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[30].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[31].position = D3DXVECTOR3(-153.36f, -56.92f, 153.68f);
	leftWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[31].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[32].position = D3DXVECTOR3(-158.48f, -58.58f, 161.07f);
	leftWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[32].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[33].position = D3DXVECTOR3(-162.18f, -60.12f, 168.98f);
	leftWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[33].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[34].position = D3DXVECTOR3(-164.66f, -61.48f, 175.68f);
	leftWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[34].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[35].position = D3DXVECTOR3(-167.08f, -63.09f, 184.63f);
	leftWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[35].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[36].position = D3DXVECTOR3(-167.87f, -64.68f, 193.53f);
	leftWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[36].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[37].position = D3DXVECTOR3(-167.08f, -66.31f, 202.73f);
	leftWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[37].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[38].position = D3DXVECTOR3(-164.73f, -67.94f, 211.61f);
	leftWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[38].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[39].position = D3DXVECTOR3(-160.89f, -69.54f, 219.90f);
	leftWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[39].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[40].position = D3DXVECTOR3(-155.62f, -71.18f, 227.46f);
	leftWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[40].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[41].position = D3DXVECTOR3(-149.22f, -72.84f, 233.79f);
	leftWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[41].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[42].position = D3DXVECTOR3(-142.08f, -74.38f, 238.81f);
	leftWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[42].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[43].position = D3DXVECTOR3(-134.35f, -76.06f, 243.29f);
	leftWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[43].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[44].position = D3DXVECTOR3(-126.27f, -77.76f, 247.96f);
	leftWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[44].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[45].position = D3DXVECTOR3(-117.77f, -79.51f, 252.89f);
	leftWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[45].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[46].position = D3DXVECTOR3(-109.72f, -81.17f, 257.61f);
	leftWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[46].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[47].position = D3DXVECTOR3(-101.31f, -82.78f, 261.55f);
	leftWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[47].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[48].position = D3DXVECTOR3(-92.69f, -84.37f, 263.87f);
	leftWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[48].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[49].position = D3DXVECTOR3(-83.49f, -86.00f, 264.69f);
	leftWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[49].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[50].position = D3DXVECTOR3(-74.34f, -87.63f, 263.92f);
	leftWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[50].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[51].position = D3DXVECTOR3(-65.06f, -89.33f, 262.28f);
	leftWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[51].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[52].position = D3DXVECTOR3(-57.56f, -91.19f, 261.73f);
	leftWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[52].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[53].position = D3DXVECTOR3(-51.31f, -92.84f, 262.42f);
	leftWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[53].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[54].position = D3DXVECTOR3(-45.64f, -94.45f, 264.09f);
	leftWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[54].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[55].position = D3DXVECTOR3(-40.00f, -96.09f, 266.86f);
	leftWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[55].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[56].position = D3DXVECTOR3(-32.89f, -97.60f, 270.99f);
	leftWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[56].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[57].position = D3DXVECTOR3(-24.48f, -99.21f, 274.93f);
	leftWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[57].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[58].position = D3DXVECTOR3(-15.86f, -100.80f, 277.25f);
	leftWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[58].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[59].position = D3DXVECTOR3(-6.66f, -102.43f, 278.07f);
	leftWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[59].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[60].position = D3DXVECTOR3(2.49f, -104.06f, 277.30f);
	leftWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[60].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[61].position = D3DXVECTOR3(11.62f, -105.78f, 275.73f);
	leftWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[61].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[62].position = D3DXVECTOR3(19.12f, -107.64f, 275.18f);
	leftWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[62].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[63].position = D3DXVECTOR3(25.37f, -109.29f, 275.87f);
	leftWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[63].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[64].position = D3DXVECTOR3(31.04f, -110.90f, 277.54f);
	leftWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[64].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[65].position = D3DXVECTOR3(36.68f, -112.54f, 280.31f);
	leftWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[65].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[66].position = D3DXVECTOR3(43.83f, -114.12f, 284.43f);
	leftWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[66].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[67].position = D3DXVECTOR3(51.86f, -115.81f, 289.08f);
	leftWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[67].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[68].position = D3DXVECTOR3(60.12f, -117.53f, 293.84f);
	leftWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[68].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[69].position = D3DXVECTOR3(68.24f, -119.23f, 298.51f);
	leftWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[69].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[70].position = D3DXVECTOR3(76.34f, -120.90f, 303.17f);
	leftWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[70].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[71].position = D3DXVECTOR3(84.64f, -122.60f, 307.95f);
	leftWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[71].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[72].position = D3DXVECTOR3(92.21f, -124.17f, 312.27f);
	leftWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[72].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[73].position = D3DXVECTOR3(98.31f, -126.03f, 316.67f);
	leftWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[73].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[74].position = D3DXVECTOR3(102.66f, -127.68f, 321.21f);
	leftWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[74].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[75].position = D3DXVECTOR3(105.93f, -129.29f, 326.13f);
	leftWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[75].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[76].position = D3DXVECTOR3(108.47f, -130.93f, 331.89f);
	leftWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[76].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[77].position = D3DXVECTOR3(111.38f, -132.46f, 339.86f);
	leftWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[77].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[78].position = D3DXVECTOR3(114.46f, -134.12f, 348.33f);
	leftWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[78].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[79].position = D3DXVECTOR3(117.58f, -135.77f, 356.78f);
	leftWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[79].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[80].position = D3DXVECTOR3(119.43f, -137.63f, 364.06f);
	leftWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[80].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[81].position = D3DXVECTOR3(119.84f, -139.28f, 370.34f);
	leftWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[81].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[82].position = D3DXVECTOR3(119.18f, -140.89f, 376.21f);
	leftWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[82].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[83].position = D3DXVECTOR3(117.43f, -142.53f, 382.26f);
	leftWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[83].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[84].position = D3DXVECTOR3(114.43f, -144.10f, 390.45f);
	leftWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[84].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[85].position = D3DXVECTOR3(111.30f, -145.76f, 398.97f);
	leftWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[85].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[86].position = D3DXVECTOR3(108.88f, -147.37f, 407.93f);
	leftWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[86].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[87].position = D3DXVECTOR3(108.09f, -148.96f, 416.82f);
	leftWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[87].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[88].position = D3DXVECTOR3(108.88f, -150.59f, 426.02f);
	leftWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[88].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[89].position = D3DXVECTOR3(111.23f, -152.22f, 434.90f);
	leftWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[89].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[90].position = D3DXVECTOR3(114.36f, -153.89f, 443.54f);
	leftWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[90].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[91].position = D3DXVECTOR3(116.21f, -155.75f, 450.82f);
	leftWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[91].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[92].position = D3DXVECTOR3(116.62f, -157.40f, 457.10f);
	leftWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[92].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[93].position = D3DXVECTOR3(115.96f, -159.01f, 462.97f);
	leftWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[93].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[94].position = D3DXVECTOR3(114.21f, -160.65f, 469.02f);
	leftWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[94].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[95].position = D3DXVECTOR3(111.30f, -162.19f, 477.03f);
	leftWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[95].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[96].position = D3DXVECTOR3(108.05f, -163.91f, 485.98f);
	leftWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[96].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[97].position = D3DXVECTOR3(104.92f, -165.56f, 494.54f);
	leftWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[97].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[98].position = D3DXVECTOR3(102.50f, -167.17f, 503.49f);
	leftWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[98].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[99].position = D3DXVECTOR3(101.71f, -168.76f, 512.39f);
	leftWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[99].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[100].position = D3DXVECTOR3(102.50f, -170.39f, 521.59f);
	leftWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[100].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[101].position = D3DXVECTOR3(104.85f, -172.02f, 530.47f);
	leftWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[101].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[102].position = D3DXVECTOR3(108.13f, -173.74f, 539.47f);
	leftWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[102].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[103].position = D3DXVECTOR3(111.41f, -175.47f, 548.47f);
	leftWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[103].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[104].position = D3DXVECTOR3(114.63f, -177.16f, 557.31f);
	leftWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[104].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[105].position = D3DXVECTOR3(117.80f, -178.84f, 566.04f);
	leftWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[105].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[106].position = D3DXVECTOR3(120.96f, -180.52f, 574.71f);
	leftWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[106].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[107].position = D3DXVECTOR3(124.20f, -182.26f, 583.64f);
	leftWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[107].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[108].position = D3DXVECTOR3(127.43f, -183.96f, 592.52f);
	leftWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[108].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[109].position = D3DXVECTOR3(130.60f, -185.66f, 601.31f);
	leftWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[109].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[110].position = D3DXVECTOR3(134.50f, -187.27f, 609.73f);
	leftWall[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[110].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[111].position = D3DXVECTOR3(139.62f, -188.86f, 617.06f);
	leftWall[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[111].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[112].position = D3DXVECTOR3(146.13f, -190.49f, 623.59f);
	leftWall[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[112].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[113].position = D3DXVECTOR3(153.64f, -192.12f, 628.88f);
	leftWall[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[113].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[114].position = D3DXVECTOR3(161.92f, -193.72f, 632.77f);
	leftWall[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[114].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[115].position = D3DXVECTOR3(170.81f, -195.36f, 635.17f);
	leftWall[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[115].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[116].position = D3DXVECTOR3(179.78f, -197.02f, 635.91f);
	leftWall[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[116].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[117].position = D3DXVECTOR3(188.48f, -198.56f, 635.17f);
	leftWall[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[117].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[118].position = D3DXVECTOR3(197.67f, -200.23f, 633.55f);
	leftWall[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[118].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[119].position = D3DXVECTOR3(207.00f, -201.92f, 631.91f);
	leftWall[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[119].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[120].position = D3DXVECTOR3(215.91f, -203.54f, 630.36f);
	leftWall[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[120].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[121].position = D3DXVECTOR3(223.41f, -205.40f, 629.81f);
	leftWall[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[121].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[122].position = D3DXVECTOR3(229.66f, -207.05f, 630.50f);
	leftWall[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[122].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[123].position = D3DXVECTOR3(235.33f, -208.66f, 632.17f);
	leftWall[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[123].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[124].position = D3DXVECTOR3(240.97f, -210.30f, 634.94f);
	leftWall[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[124].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[125].position = D3DXVECTOR3(246.17f, -212.02f, 638.83f);
	leftWall[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[125].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[126].position = D3DXVECTOR3(250.42f, -213.64f, 643.26f);
	leftWall[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[126].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[127].position = D3DXVECTOR3(253.95f, -215.28f, 648.60f);
	leftWall[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[127].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[128].position = D3DXVECTOR3(256.38f, -216.84f, 654.12f);
	leftWall[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[128].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[129].position = D3DXVECTOR3(259.23f, -218.34f, 661.92f);
	leftWall[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[129].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[130].position = D3DXVECTOR3(262.49f, -220.04f, 670.89f);
	leftWall[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[130].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[131].position = D3DXVECTOR3(265.75f, -221.81f, 679.82f);
	leftWall[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[131].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[132].position = D3DXVECTOR3(269.65f, -223.42f, 688.24f);
	leftWall[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[132].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[133].position = D3DXVECTOR3(274.77f, -225.01f, 695.57f);
	leftWall[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[133].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[134].position = D3DXVECTOR3(281.28f, -226.64f, 702.10f);
	leftWall[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[134].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[135].position = D3DXVECTOR3(288.79f, -228.27f, 707.39f);
	leftWall[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[135].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[136].position = D3DXVECTOR3(297.07f, -229.87f, 711.28f);
	leftWall[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[136].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[137].position = D3DXVECTOR3(305.96f, -231.51f, 713.68f);
	leftWall[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[137].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[138].position = D3DXVECTOR3(314.93f, -233.17f, 714.42f);
	leftWall[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[138].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[139].position = D3DXVECTOR3(323.63f, -234.71f, 713.68f);
	leftWall[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[139].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[140].position = D3DXVECTOR3(332.99f, -236.47f, 712.04f);
	leftWall[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[140].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[141].position = D3DXVECTOR3(341.95f, -238.08f, 709.66f);
	leftWall[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[141].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[142].position = D3DXVECTOR3(350.06f, -239.67f, 705.90f);
	leftWall[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[142].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[143].position = D3DXVECTOR3(357.63f, -241.30f, 700.61f);
	leftWall[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[143].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[144].position = D3DXVECTOR3(364.14f, -242.93f, 694.14f);
	leftWall[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[144].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[145].position = D3DXVECTOR3(369.40f, -244.53f, 686.66f);
	leftWall[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[145].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[146].position = D3DXVECTOR3(373.31f, -246.17f, 678.32f);
	leftWall[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[146].scale = D3DXVECTOR3(5, 1, 10.00001);

	leftWall[147].position = D3DXVECTOR3(375.60f, -247.83f, 669.62f);
	leftWall[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[147].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[148].position = D3DXVECTOR3(376.38f, -249.37f, 660.93f);
	leftWall[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[148].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[149].position = D3DXVECTOR3(376.37f, -251.05f, 651.56f);
	leftWall[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[149].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[150].position = D3DXVECTOR3(376.37f, -252.80f, 642.02f);
	leftWall[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[150].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[151].position = D3DXVECTOR3(376.37f, -254.50f, 632.63f);
	leftWall[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[151].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[152].position = D3DXVECTOR3(376.37f, -256.15f, 623.47f);
	leftWall[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[152].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[153].position = D3DXVECTOR3(376.37f, -257.89f, 613.89f);
	leftWall[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[153].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[154].position = D3DXVECTOR3(376.37f, -259.47f, 605.17f);
	leftWall[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[154].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[155].position = D3DXVECTOR3(375.58f, -261.08f, 595.92f);
	leftWall[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[155].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[156].position = D3DXVECTOR3(373.28f, -262.67f, 587.29f);
	leftWall[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[156].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[157].position = D3DXVECTOR3(369.39f, -264.30f, 578.91f);
	leftWall[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[157].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[158].position = D3DXVECTOR3(364.14f, -265.93f, 571.37f);
	leftWall[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[158].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[159].position = D3DXVECTOR3(358.18f, -267.61f, 564.27f);
	leftWall[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[159].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[160].position = D3DXVECTOR3(353.96f, -269.47f, 558.05f);
	leftWall[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[160].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[161].position = D3DXVECTOR3(351.42f, -271.12f, 552.30f);
	leftWall[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[161].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[162].position = D3DXVECTOR3(350.04f, -272.73f, 546.55f);
	leftWall[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[162].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[163].position = D3DXVECTOR3(349.61f, -274.37f, 540.28f);
	leftWall[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[163].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[164].position = D3DXVECTOR3(349.61f, -275.87f, 531.88f);
	leftWall[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[164].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[165].position = D3DXVECTOR3(349.61f, -277.56f, 522.43f);
	leftWall[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[165].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[166].position = D3DXVECTOR3(349.61f, -279.11f, 514.00f);
	leftWall[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[166].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[167].position = D3DXVECTOR3(350.37f, -280.97f, 506.52f);
	leftWall[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[167].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[168].position = D3DXVECTOR3(352.13f, -282.62f, 500.48f);
	leftWall[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[168].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[169].position = D3DXVECTOR3(354.76f, -284.23f, 495.19f);
	leftWall[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[169].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[170].position = D3DXVECTOR3(358.47f, -285.87f, 490.11f);
	leftWall[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[170].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[171].position = D3DXVECTOR3(364.02f, -287.43f, 483.48f);
	leftWall[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[171].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[172].position = D3DXVECTOR3(370.07f, -289.13f, 476.27f);
	leftWall[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[172].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[173].position = D3DXVECTOR3(376.19f, -290.86f, 468.97f);
	leftWall[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[173].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[174].position = D3DXVECTOR3(382.30f, -292.61f, 461.74f);
	leftWall[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[174].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[175].position = D3DXVECTOR3(387.69f, -294.47f, 456.50f);
	leftWall[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[175].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[176].position = D3DXVECTOR3(392.92f, -296.12f, 453.00f);
	leftWall[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[176].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[177].position = D3DXVECTOR3(398.34f, -297.73f, 450.64f);
	leftWall[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[177].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[178].position = D3DXVECTOR3(404.44f, -299.37f, 449.13f);
	leftWall[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[178].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[179].position = D3DXVECTOR3(410.92f, -301.09f, 448.77f);
	leftWall[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[179].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[180].position = D3DXVECTOR3(417.03f, -302.71f, 449.44f);
	leftWall[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[180].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[181].position = D3DXVECTOR3(425.30f, -304.23f, 450.90f);
	leftWall[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[181].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[182].position = D3DXVECTOR3(434.85f, -305.99f, 452.58f);
	leftWall[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[182].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[183].position = D3DXVECTOR3(444.23f, -307.71f, 454.24f);
	leftWall[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[183].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[184].position = D3DXVECTOR3(453.67f, -309.44f, 455.90f);
	leftWall[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[184].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[185].position = D3DXVECTOR3(463.07f, -311.15f, 457.57f);
	leftWall[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[185].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[186].position = D3DXVECTOR3(472.62f, -312.89f, 459.24f);
	leftWall[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[186].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[187].position = D3DXVECTOR3(481.91f, -314.57f, 460.88f);
	leftWall[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[187].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[188].position = D3DXVECTOR3(491.32f, -316.28f, 462.54f);
	leftWall[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[188].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[189].position = D3DXVECTOR3(500.71f, -317.99f, 464.20f);
	leftWall[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[189].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[190].position = D3DXVECTOR3(510.07f, -319.69f, 465.85f);
	leftWall[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[190].scale = D3DXVECTOR3(5, 1, 10);

	//加速床座標
	accelSpeed[0].position = D3DXVECTOR3(-0.27f, -15.78f, 28.86f);
	accelSpeed[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[0].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[1].position = D3DXVECTOR3(63.65f, -122.04f, 286.07f);
	accelSpeed[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[1].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[2].position = D3DXVECTOR3(115.83f, -178.25f, 535.79f);
	accelSpeed[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[2].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[3].position = D3DXVECTOR3(367.88f, -262.40f, 614.72f);
	accelSpeed[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[3].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[4].position = D3DXVECTOR3(361.37f, -261.39f, 614.55f);
	accelSpeed[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	accelSpeed[4].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[5].position = D3DXVECTOR3(374.47f, -261.28f, 614.53f);
	accelSpeed[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, -45.00f*3.141592f / 180);
	accelSpeed[5].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeed[6].position = D3DXVECTOR3(444.89f, -312.22f, 445.74f);
	accelSpeed[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeed[6].scale = D3DXVECTOR3(2, 1.5, 1);

	//ゴール床座標
	goalCube.position = D3DXVECTOR3(523.82f, -325.23f, 459.65f);
	goalCube.rotation = D3DXVECTOR3(0.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	goalCube.scale = D3DXVECTOR3(20, 0, 20);


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
		accelSpeed[i].Draw(TEXTURE_INDEX_MAX, D3DXCOLOR(1, 0, 0, 1));
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