#include"figure.h"
#include"Stage.h"
#include"Game.h"
#include"Obstacle.h"
#include<stdlib.h>
#include<time.h>
struct Transform{
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;
};


//最大設置数
const int CUBE_NUM = 1521;
const int ACCEL_SPEED_NUM = 5;
const int RIGHT_WALL_NUM = 257;
const int LEFT_WALL_NUM = 257;
const int OBSTACLE_NUM = 24;
const int GOAL_CUBE_NUM = 15;
//2179→1581

//rotationのx,zは1.4ｆまで
Plane cube[CUBE_NUM];				//床
SpeedAccel accelSpeed[ACCEL_SPEED_NUM];	//加速床
Cube rightWall[RIGHT_WALL_NUM];		//右側の壁
Cube leftWall[LEFT_WALL_NUM];		//左側の壁
Plane goalCube[GOAL_CUBE_NUM];		//ゴール_床
Obstacle obstacle[OBSTACLE_NUM];

//----------------実際に使うオブジェクト----------------//
const int DRAW_LEFT_WALL_NUM = 30;
Cube drawLeftWall[DRAW_LEFT_WALL_NUM];
int leftWallCount = 0;

const int DRAW_RIGHT_WALL_NUM = 30;
Cube drawRightWall[DRAW_LEFT_WALL_NUM];
int rightWallCount = 0;



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

	cube[9].position = D3DXVECTOR3(-0.27f, -25.70f, 83.16f);
	cube[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[9].scale = D3DXVECTOR3(10, 1, 10);

	cube[10].position = D3DXVECTOR3(-0.27f, -27.36f, 92.16f);
	cube[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[10].scale = D3DXVECTOR3(10, 1, 10);

	cube[11].position = D3DXVECTOR3(-0.27f, -28.95f, 100.86f);
	cube[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[11].scale = D3DXVECTOR3(10, 1, 10);

	cube[12].position = D3DXVECTOR3(-0.27f, -30.63f, 109.96f);
	cube[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[12].scale = D3DXVECTOR3(10, 1, 10);

	cube[13].position = D3DXVECTOR3(-0.27f, -32.42f, 119.36f);
	cube[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[13].scale = D3DXVECTOR3(10, 1, 10);

	cube[14].position = D3DXVECTOR3(-0.27f, -34.10f, 128.66f);
	cube[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[14].scale = D3DXVECTOR3(10, 1, 10);

	cube[15].position = D3DXVECTOR3(-0.27f, -35.89f, 138.36f);
	cube[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[15].scale = D3DXVECTOR3(10, 1, 10);

	cube[16].position = D3DXVECTOR3(-0.27f, -37.48f, 147.16f);
	cube[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[16].scale = D3DXVECTOR3(10, 1, 10);

	cube[17].position = D3DXVECTOR3(-0.27f, -38.86f, 154.77f);
	cube[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[17].scale = D3DXVECTOR3(10, 1, 10);

	cube[18].position = D3DXVECTOR3(-0.37f, -40.36f, 161.78f);
	cube[18].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[18].scale = D3DXVECTOR3(11, 1, 5);

	cube[19].position = D3DXVECTOR3(-0.72f, -40.54f, 162.55f);
	cube[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[19].scale = D3DXVECTOR3(10, 1, 10);

	cube[20].position = D3DXVECTOR3(-2.12f, -42.02f, 169.43f);
	cube[20].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[20].scale = D3DXVECTOR3(11, 1, 5);

	cube[21].position = D3DXVECTOR3(-2.58f, -42.20f, 170.13f);
	cube[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[21].scale = D3DXVECTOR3(10, 1, 10);

	cube[22].position = D3DXVECTOR3(-5.21f, -43.65f, 176.53f);
	cube[22].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[22].scale = D3DXVECTOR3(11, 1, 5);

	cube[23].position = D3DXVECTOR3(-5.55f, -43.80f, 176.86f);
	cube[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[23].scale = D3DXVECTOR3(10, 1, 10);

	cube[24].position = D3DXVECTOR3(-9.22f, -45.22f, 182.66f);
	cube[24].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[24].scale = D3DXVECTOR3(11, 1, 5);

	cube[25].position = D3DXVECTOR3(-9.86f, -45.45f, 183.34f);
	cube[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[25].scale = D3DXVECTOR3(10, 1, 10);

	cube[26].position = D3DXVECTOR3(-14.64f, -46.97f, 188.62f);
	cube[26].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[26].scale = D3DXVECTOR3(11, 1, 5);

	cube[27].position = D3DXVECTOR3(-15.41f, -47.16f, 189.04f);
	cube[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[27].scale = D3DXVECTOR3(10, 1, 10);

	cube[28].position = D3DXVECTOR3(-20.47f, -48.52f, 193.15f);
	cube[28].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[28].scale = D3DXVECTOR3(11, 1, 5);

	cube[29].position = D3DXVECTOR3(-21.57f, -48.79f, 193.56f);
	cube[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[29].scale = D3DXVECTOR3(10, 1, 10);

	cube[30].position = D3DXVECTOR3(-29.05f, -50.38f, 197.94f);
	cube[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[30].scale = D3DXVECTOR3(10, 1, 10);

	cube[31].position = D3DXVECTOR3(-37.01f, -52.11f, 202.55f);
	cube[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[31].scale = D3DXVECTOR3(10, 1, 10);

	cube[32].position = D3DXVECTOR3(-44.31f, -53.66f, 206.75f);
	cube[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[32].scale = D3DXVECTOR3(10, 1, 10);

	cube[33].position = D3DXVECTOR3(-51.61f, -55.18f, 210.95f);
	cube[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[33].scale = D3DXVECTOR3(10, 1, 10);

	cube[34].position = D3DXVECTOR3(-59.51f, -56.91f, 215.55f);
	cube[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[34].scale = D3DXVECTOR3(10, 1, 10);

	cube[35].position = D3DXVECTOR3(-67.38f, -58.53f, 219.97f);
	cube[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[35].scale = D3DXVECTOR3(10, 1, 10);

	cube[36].position = D3DXVECTOR3(-74.94f, -60.12f, 224.37f);
	cube[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[36].scale = D3DXVECTOR3(10, 1, 10);

	cube[37].position = D3DXVECTOR3(-82.90f, -61.85f, 228.98f);
	cube[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[37].scale = D3DXVECTOR3(10, 1, 10);

	cube[38].position = D3DXVECTOR3(-90.20f, -63.40f, 233.18f);
	cube[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[38].scale = D3DXVECTOR3(10, 1, 10);

	cube[39].position = D3DXVECTOR3(-97.50f, -64.92f, 237.38f);
	cube[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[39].scale = D3DXVECTOR3(10, 1, 10);

	cube[40].position = D3DXVECTOR3(-105.40f, -66.65f, 241.98f);
	cube[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[40].scale = D3DXVECTOR3(10, 1, 10);

	cube[41].position = D3DXVECTOR3(-113.26f, -68.29f, 246.45f);
	cube[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[41].scale = D3DXVECTOR3(10, 1, 10);

	cube[42].position = D3DXVECTOR3(-119.51f, -69.81f, 249.82f);
	cube[42].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[42].scale = D3DXVECTOR3(11, 1, 5);

	cube[43].position = D3DXVECTOR3(-120.34f, -69.99f, 249.92f);
	cube[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[43].scale = D3DXVECTOR3(10, 1, 10);

	cube[44].position = D3DXVECTOR3(-127.03f, -71.47f, 252.07f);
	cube[44].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[44].scale = D3DXVECTOR3(11, 1, 5);

	cube[45].position = D3DXVECTOR3(-127.84f, -71.65f, 252.11f);
	cube[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[45].scale = D3DXVECTOR3(10, 1, 10);

	cube[46].position = D3DXVECTOR3(-134.70f, -73.10f, 253.01f);
	cube[46].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[46].scale = D3DXVECTOR3(11, 1, 5);

	cube[47].position = D3DXVECTOR3(-135.15f, -73.25f, 252.90f);
	cube[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[47].scale = D3DXVECTOR3(10, 1, 10);

	cube[48].position = D3DXVECTOR3(-142.01f, -74.63f, 252.45f);
	cube[48].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[48].scale = D3DXVECTOR3(11, 1, 5);

	cube[49].position = D3DXVECTOR3(-142.91f, -74.90f, 252.41f);
	cube[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[49].scale = D3DXVECTOR3(10, 1, 10);

	cube[50].position = D3DXVECTOR3(-149.57f, -76.20f, 251.22f);
	cube[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[50].scale = D3DXVECTOR3(10, 1, 10);

	cube[51].position = D3DXVECTOR3(-156.66f, -77.68f, 250.00f);
	cube[51].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[51].scale = D3DXVECTOR3(11, 1, 5);

	cube[52].position = D3DXVECTOR3(-157.33f, -77.81f, 250.38f);
	cube[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[52].scale = D3DXVECTOR3(10, 1, 10);

	cube[53].position = D3DXVECTOR3(-164.45f, -79.26f, 250.64f);
	cube[53].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[53].scale = D3DXVECTOR3(11, 1, 5);

	cube[54].position = D3DXVECTOR3(-164.77f, -79.40f, 250.87f);
	cube[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[54].scale = D3DXVECTOR3(10, 1, 10);

	cube[55].position = D3DXVECTOR3(-171.65f, -80.82f, 252.14f);
	cube[55].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[55].scale = D3DXVECTOR3(11, 1, 5);

	cube[56].position = D3DXVECTOR3(-172.29f, -81.03f, 252.72f);
	cube[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[56].scale = D3DXVECTOR3(10, 1, 10);

	cube[57].position = D3DXVECTOR3(-178.92f, -82.49f, 255.28f);
	cube[57].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[57].scale = D3DXVECTOR3(11, 1, 5);

	cube[58].position = D3DXVECTOR3(-179.35f, -82.66f, 255.83f);
	cube[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[58].scale = D3DXVECTOR3(10, 1, 10);

	cube[59].position = D3DXVECTOR3(-185.31f, -84.08f, 259.46f);
	cube[59].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[59].scale = D3DXVECTOR3(11, 1, 5);

	cube[60].position = D3DXVECTOR3(-185.72f, -84.26f, 260.08f);
	cube[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[60].scale = D3DXVECTOR3(10, 1, 10);

	cube[61].position = D3DXVECTOR3(-191.13f, -85.71f, 265.00f);
	cube[61].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[61].scale = D3DXVECTOR3(11, 1, 5);

	cube[62].position = D3DXVECTOR3(-191.31f, -85.90f, 265.44f);
	cube[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[62].scale = D3DXVECTOR3(10, 1, 10);

	cube[63].position = D3DXVECTOR3(-195.65f, -87.37f, 270.98f);
	cube[63].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[63].scale = D3DXVECTOR3(11, 1, 5);

	cube[64].position = D3DXVECTOR3(-195.69f, -87.56f, 271.54f);
	cube[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[64].scale = D3DXVECTOR3(10, 1, 10);

	cube[65].position = D3DXVECTOR3(-199.19f, -89.04f, 277.76f);
	cube[65].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[65].scale = D3DXVECTOR3(11, 1, 5);

	cube[66].position = D3DXVECTOR3(-198.90f, -89.10f, 278.04f);
	cube[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[66].scale = D3DXVECTOR3(10, 1, 10);

	cube[67].position = D3DXVECTOR3(-201.38f, -90.46f, 284.74f);
	cube[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[67].scale = D3DXVECTOR3(10, 1, 10);

	cube[68].position = D3DXVECTOR3(-203.81f, -91.94f, 291.51f);
	cube[68].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[68].scale = D3DXVECTOR3(11, 1, 5);

	cube[69].position = D3DXVECTOR3(-203.55f, -92.07f, 292.23f);
	cube[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[69].scale = D3DXVECTOR3(10, 1, 10);

	cube[70].position = D3DXVECTOR3(-204.54f, -93.52f, 299.29f);
	cube[70].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[70].scale = D3DXVECTOR3(11, 1, 5);

	cube[71].position = D3DXVECTOR3(-204.36f, -93.66f, 299.64f);
	cube[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[71].scale = D3DXVECTOR3(10, 1, 10);

	cube[72].position = D3DXVECTOR3(-204.31f, -95.08f, 306.64f);
	cube[72].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[72].scale = D3DXVECTOR3(11, 1, 5);

	cube[73].position = D3DXVECTOR3(-203.84f, -95.29f, 307.37f);
	cube[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[73].scale = D3DXVECTOR3(10, 1, 10);

	cube[74].position = D3DXVECTOR3(-202.47f, -96.75f, 314.34f);
	cube[74].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[74].scale = D3DXVECTOR3(11, 1, 5);

	cube[75].position = D3DXVECTOR3(-202.01f, -96.92f, 314.86f);
	cube[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[75].scale = D3DXVECTOR3(10, 1, 10);

	cube[76].position = D3DXVECTOR3(-199.47f, -98.34f, 321.36f);
	cube[76].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[76].scale = D3DXVECTOR3(11, 1, 5);

	cube[77].position = D3DXVECTOR3(-198.93f, -98.52f, 321.87f);
	cube[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[77].scale = D3DXVECTOR3(10, 1, 10);

	cube[78].position = D3DXVECTOR3(-195.02f, -99.97f, 328.06f);
	cube[78].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[78].scale = D3DXVECTOR3(11, 1, 5);

	cube[79].position = D3DXVECTOR3(-194.63f, -100.16f, 328.30f);
	cube[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[79].scale = D3DXVECTOR3(10, 1, 10);

	cube[80].position = D3DXVECTOR3(-189.92f, -101.63f, 333.54f);
	cube[80].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[80].scale = D3DXVECTOR3(11, 1, 5);

	cube[81].position = D3DXVECTOR3(-189.38f, -101.82f, 333.68f);
	cube[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[81].scale = D3DXVECTOR3(10, 1, 10);

	cube[82].position = D3DXVECTOR3(-183.86f, -103.30f, 338.21f);
	cube[82].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[82].scale = D3DXVECTOR3(11, 1, 5);

	cube[83].position = D3DXVECTOR3(-183.53f, -103.36f, 337.97f);
	cube[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[83].scale = D3DXVECTOR3(10, 1, 10);

	cube[84].position = D3DXVECTOR3(-175.80f, -105.04f, 342.45f);
	cube[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[84].scale = D3DXVECTOR3(10, 1, 10);

	cube[85].position = D3DXVECTOR3(-167.72f, -106.74f, 347.12f);
	cube[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[85].scale = D3DXVECTOR3(10, 1, 10);

	cube[86].position = D3DXVECTOR3(-159.22f, -108.49f, 352.05f);
	cube[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[86].scale = D3DXVECTOR3(10, 1, 10);

	cube[87].position = D3DXVECTOR3(-151.17f, -110.15f, 356.77f);
	cube[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[87].scale = D3DXVECTOR3(10, 1, 10);

	cube[88].position = D3DXVECTOR3(-144.93f, -111.63f, 360.35f);
	cube[88].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[88].scale = D3DXVECTOR3(11, 1, 5);

	cube[89].position = D3DXVECTOR3(-144.17f, -111.76f, 360.21f);
	cube[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[89].scale = D3DXVECTOR3(10, 1, 10);

	cube[90].position = D3DXVECTOR3(-137.41f, -113.21f, 362.48f);
	cube[90].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[90].scale = D3DXVECTOR3(11, 1, 5);

	cube[91].position = D3DXVECTOR3(-137.01f, -113.35f, 362.30f);
	cube[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[91].scale = D3DXVECTOR3(10, 1, 10);

	cube[92].position = D3DXVECTOR3(-130.10f, -114.77f, 363.41f);
	cube[92].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[92].scale = D3DXVECTOR3(11, 1, 5);

	cube[93].position = D3DXVECTOR3(-129.30f, -114.98f, 363.13f);
	cube[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[93].scale = D3DXVECTOR3(10, 1, 10);

	cube[94].position = D3DXVECTOR3(-122.20f, -116.44f, 363.03f);
	cube[94].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[94].scale = D3DXVECTOR3(11, 1, 5);

	cube[95].position = D3DXVECTOR3(-121.61f, -116.61f, 362.63f);
	cube[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[95].scale = D3DXVECTOR3(10, 1, 10);

	cube[96].position = D3DXVECTOR3(-112.33f, -118.31f, 360.99f);
	cube[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[96].scale = D3DXVECTOR3(10, 1, 10);

	cube[97].position = D3DXVECTOR3(-105.14f, -119.82f, 359.98f);
	cube[97].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[97].scale = D3DXVECTOR3(11, 1, 5);

	cube[98].position = D3DXVECTOR3(-104.32f, -120.00f, 360.17f);
	cube[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[98].scale = D3DXVECTOR3(10, 1, 10);

	cube[99].position = D3DXVECTOR3(-97.30f, -121.48f, 360.43f);
	cube[99].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[99].scale = D3DXVECTOR3(11, 1, 5);

	cube[100].position = D3DXVECTOR3(-96.53f, -121.66f, 360.68f);
	cube[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[100].scale = D3DXVECTOR3(10, 1, 10);

	cube[101].position = D3DXVECTOR3(-89.77f, -123.11f, 362.17f);
	cube[101].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[101].scale = D3DXVECTOR3(11, 1, 5);

	cube[102].position = D3DXVECTOR3(-89.39f, -123.26f, 362.43f);
	cube[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[102].scale = D3DXVECTOR3(10, 1, 10);

	cube[103].position = D3DXVECTOR3(-83.10f, -124.64f, 365.20f);
	cube[103].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[103].scale = D3DXVECTOR3(11, 1, 5);

	cube[104].position = D3DXVECTOR3(-82.26f, -124.91f, 365.55f);
	cube[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[104].scale = D3DXVECTOR3(10, 1, 10);

	cube[105].position = D3DXVECTOR3(-74.34f, -126.58f, 370.15f);
	cube[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[105].scale = D3DXVECTOR3(10, 1, 10);

	cube[106].position = D3DXVECTOR3(-68.10f, -128.06f, 373.73f);
	cube[106].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[106].scale = D3DXVECTOR3(11, 1, 5);

	cube[107].position = D3DXVECTOR3(-67.34f, -128.19f, 373.59f);
	cube[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[107].scale = D3DXVECTOR3(10, 1, 10);

	cube[108].position = D3DXVECTOR3(-60.58f, -129.64f, 375.86f);
	cube[108].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[108].scale = D3DXVECTOR3(11, 1, 5);

	cube[109].position = D3DXVECTOR3(-60.18f, -129.78f, 375.68f);
	cube[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[109].scale = D3DXVECTOR3(10, 1, 10);

	cube[110].position = D3DXVECTOR3(-53.27f, -131.20f, 376.79f);
	cube[110].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[110].scale = D3DXVECTOR3(11, 1, 5);

	cube[111].position = D3DXVECTOR3(-52.47f, -131.41f, 376.51f);
	cube[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[111].scale = D3DXVECTOR3(10, 1, 10);

	cube[112].position = D3DXVECTOR3(-45.37f, -132.87f, 376.41f);
	cube[112].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[112].scale = D3DXVECTOR3(11, 1, 5);

	cube[113].position = D3DXVECTOR3(-44.78f, -133.04f, 376.01f);
	cube[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[113].scale = D3DXVECTOR3(10, 1, 10);

	cube[114].position = D3DXVECTOR3(-35.65f, -134.76f, 374.44f);
	cube[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[114].scale = D3DXVECTOR3(10, 1, 10);

	cube[115].position = D3DXVECTOR3(-28.46f, -136.27f, 373.43f);
	cube[115].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[115].scale = D3DXVECTOR3(11, 1, 5);

	cube[116].position = D3DXVECTOR3(-27.64f, -136.45f, 373.62f);
	cube[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[116].scale = D3DXVECTOR3(10, 1, 10);

	cube[117].position = D3DXVECTOR3(-20.62f, -137.93f, 373.88f);
	cube[117].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[117].scale = D3DXVECTOR3(11, 1, 5);

	cube[118].position = D3DXVECTOR3(-19.85f, -138.11f, 374.13f);
	cube[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[118].scale = D3DXVECTOR3(10, 1, 10);

	cube[119].position = D3DXVECTOR3(-13.09f, -139.56f, 375.62f);
	cube[119].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[119].scale = D3DXVECTOR3(11, 1, 5);

	cube[120].position = D3DXVECTOR3(-12.71f, -139.71f, 375.88f);
	cube[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[120].scale = D3DXVECTOR3(10, 1, 10);

	cube[121].position = D3DXVECTOR3(-6.42f, -141.09f, 378.65f);
	cube[121].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[121].scale = D3DXVECTOR3(11, 1, 5);

	cube[122].position = D3DXVECTOR3(-5.58f, -141.36f, 379.00f);
	cube[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[122].scale = D3DXVECTOR3(10, 1, 10);

	cube[123].position = D3DXVECTOR3(2.74f, -143.10f, 383.79f);
	cube[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[123].scale = D3DXVECTOR3(10, 1, 10);

	cube[124].position = D3DXVECTOR3(10.77f, -144.79f, 388.44f);
	cube[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[124].scale = D3DXVECTOR3(10, 1, 10);

	cube[125].position = D3DXVECTOR3(19.03f, -146.51f, 393.20f);
	cube[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[125].scale = D3DXVECTOR3(10, 1, 10);

	cube[126].position = D3DXVECTOR3(27.15f, -148.21f, 397.87f);
	cube[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[126].scale = D3DXVECTOR3(10, 1, 10);

	cube[127].position = D3DXVECTOR3(35.25f, -149.88f, 402.53f);
	cube[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[127].scale = D3DXVECTOR3(10, 1, 10);

	cube[128].position = D3DXVECTOR3(43.55f, -151.58f, 407.31f);
	cube[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[128].scale = D3DXVECTOR3(10, 1, 10);

	cube[129].position = D3DXVECTOR3(51.13f, -153.15f, 411.63f);
	cube[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[129].scale = D3DXVECTOR3(10, 1, 10);

	cube[130].position = D3DXVECTOR3(59.45f, -154.91f, 416.42f);
	cube[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[130].scale = D3DXVECTOR3(10, 1, 10);

	cube[131].position = D3DXVECTOR3(67.48f, -156.60f, 421.07f);
	cube[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[131].scale = D3DXVECTOR3(10, 1, 10);

	cube[132].position = D3DXVECTOR3(75.74f, -158.32f, 425.83f);
	cube[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[132].scale = D3DXVECTOR3(10, 1, 10);

	cube[133].position = D3DXVECTOR3(83.86f, -160.02f, 430.50f);
	cube[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[133].scale = D3DXVECTOR3(10, 1, 10);

	cube[134].position = D3DXVECTOR3(91.96f, -161.69f, 435.16f);
	cube[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[134].scale = D3DXVECTOR3(10, 1, 10);

	cube[135].position = D3DXVECTOR3(100.26f, -163.39f, 439.94f);
	cube[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[135].scale = D3DXVECTOR3(10, 1, 10);

	cube[136].position = D3DXVECTOR3(107.84f, -164.96f, 444.26f);
	cube[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[136].scale = D3DXVECTOR3(10, 1, 10);

	cube[137].position = D3DXVECTOR3(113.37f, -166.36f, 447.66f);
	cube[137].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[137].scale = D3DXVECTOR3(11, 1, 5);

	cube[138].position = D3DXVECTOR3(113.88f, -166.54f, 448.34f);
	cube[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[138].scale = D3DXVECTOR3(10, 1, 10);

	cube[139].position = D3DXVECTOR3(119.08f, -168.02f, 453.05f);
	cube[139].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[139].scale = D3DXVECTOR3(11, 1, 5);

	cube[140].position = D3DXVECTOR3(119.51f, -168.20f, 453.73f);
	cube[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[140].scale = D3DXVECTOR3(10, 1, 10);

	cube[141].position = D3DXVECTOR3(123.73f, -169.65f, 459.22f);
	cube[141].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[141].scale = D3DXVECTOR3(11, 1, 5);

	cube[142].position = D3DXVECTOR3(123.86f, -169.80f, 459.67f);
	cube[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[142].scale = D3DXVECTOR3(10, 1, 10);

	cube[143].position = D3DXVECTOR3(126.90f, -171.18f, 465.83f);
	cube[143].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[143].scale = D3DXVECTOR3(11, 1, 5);

	cube[144].position = D3DXVECTOR3(127.31f, -171.45f, 466.64f);
	cube[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[144].scale = D3DXVECTOR3(10, 1, 10);

	cube[145].position = D3DXVECTOR3(130.54f, -173.14f, 475.49f);
	cube[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[145].scale = D3DXVECTOR3(10, 1, 10);

	cube[146].position = D3DXVECTOR3(133.62f, -174.80f, 483.96f);
	cube[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[146].scale = D3DXVECTOR3(10, 1, 10);

	cube[147].position = D3DXVECTOR3(136.74f, -176.45f, 492.41f);
	cube[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[147].scale = D3DXVECTOR3(10, 1, 10);

	cube[148].position = D3DXVECTOR3(138.99f, -177.96f, 499.32f);
	cube[148].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[148].scale = D3DXVECTOR3(11, 1, 5);

	cube[149].position = D3DXVECTOR3(138.95f, -178.14f, 500.16f);
	cube[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[149].scale = D3DXVECTOR3(10, 1, 10);

	cube[150].position = D3DXVECTOR3(139.90f, -179.62f, 507.12f);
	cube[150].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[150].scale = D3DXVECTOR3(11, 1, 5);

	cube[151].position = D3DXVECTOR3(139.79f, -179.80f, 507.92f);
	cube[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[151].scale = D3DXVECTOR3(10, 1, 10);

	cube[152].position = D3DXVECTOR3(139.50f, -181.25f, 514.83f);
	cube[152].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[152].scale = D3DXVECTOR3(11, 1, 5);

	cube[153].position = D3DXVECTOR3(139.31f, -181.40f, 515.26f);
	cube[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[153].scale = D3DXVECTOR3(10, 1, 10);

	cube[154].position = D3DXVECTOR3(137.67f, -182.78f, 521.93f);
	cube[154].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[154].scale = D3DXVECTOR3(11, 1, 5);

	cube[155].position = D3DXVECTOR3(137.47f, -183.05f, 522.82f);
	cube[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[155].scale = D3DXVECTOR3(10, 1, 10);

	cube[156].position = D3DXVECTOR3(134.15f, -184.78f, 531.89f);
	cube[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[156].scale = D3DXVECTOR3(10, 1, 10);

	cube[157].position = D3DXVECTOR3(131.02f, -186.44f, 540.41f);
	cube[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[157].scale = D3DXVECTOR3(10, 1, 10);

	cube[158].position = D3DXVECTOR3(128.58f, -187.92f, 547.17f);
	cube[158].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[158].scale = D3DXVECTOR3(11, 1, 5);

	cube[159].position = D3DXVECTOR3(128.85f, -188.05f, 547.90f);
	cube[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[159].scale = D3DXVECTOR3(10, 1, 10);

	cube[160].position = D3DXVECTOR3(127.80f, -189.50f, 554.94f);
	cube[160].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[160].scale = D3DXVECTOR3(11, 1, 5);

	cube[161].position = D3DXVECTOR3(128.04f, -189.64f, 555.31f);
	cube[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[161].scale = D3DXVECTOR3(10, 1, 10);

	cube[162].position = D3DXVECTOR3(128.15f, -191.06f, 562.31f);
	cube[162].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[162].scale = D3DXVECTOR3(11, 1, 5);

	cube[163].position = D3DXVECTOR3(128.56f, -191.27f, 563.05f);
	cube[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[163].scale = D3DXVECTOR3(10, 1, 10);

	cube[164].position = D3DXVECTOR3(129.90f, -192.73f, 570.02f);
	cube[164].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[164].scale = D3DXVECTOR3(11, 1, 5);

	cube[165].position = D3DXVECTOR3(130.39f, -192.90f, 570.53f);
	cube[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[165].scale = D3DXVECTOR3(10, 1, 10);

	cube[166].position = D3DXVECTOR3(133.52f, -194.57f, 579.17f);
	cube[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[166].scale = D3DXVECTOR3(10, 1, 10);

	cube[167].position = D3DXVECTOR3(135.77f, -196.08f, 586.08f);
	cube[167].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[167].scale = D3DXVECTOR3(11, 1, 5);

	cube[168].position = D3DXVECTOR3(135.73f, -196.26f, 586.92f);
	cube[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[168].scale = D3DXVECTOR3(10, 1, 10);

	cube[169].position = D3DXVECTOR3(136.68f, -197.74f, 593.88f);
	cube[169].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[169].scale = D3DXVECTOR3(11, 1, 5);

	cube[170].position = D3DXVECTOR3(136.57f, -197.92f, 594.68f);
	cube[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[170].scale = D3DXVECTOR3(10, 1, 10);

	cube[171].position = D3DXVECTOR3(136.28f, -199.37f, 601.59f);
	cube[171].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[171].scale = D3DXVECTOR3(11, 1, 5);

	cube[172].position = D3DXVECTOR3(136.09f, -199.52f, 602.02f);
	cube[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[172].scale = D3DXVECTOR3(10, 1, 10);

	cube[173].position = D3DXVECTOR3(134.45f, -200.90f, 608.69f);
	cube[173].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[173].scale = D3DXVECTOR3(11, 1, 5);

	cube[174].position = D3DXVECTOR3(134.25f, -201.17f, 609.58f);
	cube[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[174].scale = D3DXVECTOR3(10, 1, 10);

	cube[175].position = D3DXVECTOR3(131.02f, -202.87f, 618.47f);
	cube[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[175].scale = D3DXVECTOR3(10, 1, 10);

	cube[176].position = D3DXVECTOR3(127.77f, -204.59f, 627.42f);
	cube[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[176].scale = D3DXVECTOR3(10, 1, 10);

	cube[177].position = D3DXVECTOR3(124.64f, -206.24f, 635.98f);
	cube[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[177].scale = D3DXVECTOR3(10, 1, 10);

	cube[178].position = D3DXVECTOR3(122.20f, -207.72f, 642.74f);
	cube[178].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[178].scale = D3DXVECTOR3(11, 1, 5);

	cube[179].position = D3DXVECTOR3(122.47f, -207.85f, 643.47f);
	cube[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[179].scale = D3DXVECTOR3(10, 1, 10);

	cube[180].position = D3DXVECTOR3(121.42f, -209.30f, 650.51f);
	cube[180].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[180].scale = D3DXVECTOR3(11, 1, 5);

	cube[181].position = D3DXVECTOR3(121.66f, -209.44f, 650.88f);
	cube[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[181].scale = D3DXVECTOR3(10, 1, 10);

	cube[182].position = D3DXVECTOR3(121.77f, -210.86f, 657.88f);
	cube[182].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[182].scale = D3DXVECTOR3(11, 1, 5);

	cube[183].position = D3DXVECTOR3(122.18f, -211.07f, 658.62f);
	cube[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[183].scale = D3DXVECTOR3(10, 1, 10);

	cube[184].position = D3DXVECTOR3(123.52f, -212.53f, 665.59f);
	cube[184].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[184].scale = D3DXVECTOR3(11, 1, 5);

	cube[185].position = D3DXVECTOR3(124.01f, -212.70f, 666.10f);
	cube[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[185].scale = D3DXVECTOR3(10, 1, 10);

	cube[186].position = D3DXVECTOR3(127.25f, -214.44f, 675.10f);
	cube[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[186].scale = D3DXVECTOR3(10, 1, 10);

	cube[187].position = D3DXVECTOR3(130.53f, -216.17f, 684.10f);
	cube[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[187].scale = D3DXVECTOR3(10, 1, 10);

	cube[188].position = D3DXVECTOR3(133.75f, -217.86f, 692.94f);
	cube[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[188].scale = D3DXVECTOR3(10, 1, 10);

	cube[189].position = D3DXVECTOR3(136.92f, -219.54f, 701.67f);
	cube[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[189].scale = D3DXVECTOR3(10, 1, 10);

	cube[190].position = D3DXVECTOR3(140.08f, -221.22f, 710.34f);
	cube[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[190].scale = D3DXVECTOR3(10, 1, 10);

	cube[191].position = D3DXVECTOR3(143.32f, -222.96f, 719.27f);
	cube[191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[191].scale = D3DXVECTOR3(10, 1, 10);

	cube[192].position = D3DXVECTOR3(146.55f, -224.66f, 728.15f);
	cube[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[192].scale = D3DXVECTOR3(10, 1, 10);

	cube[193].position = D3DXVECTOR3(149.72f, -226.36f, 736.95f);
	cube[193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[193].scale = D3DXVECTOR3(10, 1, 10);

	cube[194].position = D3DXVECTOR3(152.66f, -227.88f, 744.98f);
	cube[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[194].scale = D3DXVECTOR3(10, 1, 10);

	cube[195].position = D3DXVECTOR3(155.94f, -229.61f, 753.98f);
	cube[195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[195].scale = D3DXVECTOR3(10, 1, 10);

	cube[196].position = D3DXVECTOR3(159.16f, -231.30f, 762.82f);
	cube[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[196].scale = D3DXVECTOR3(10, 1, 10);

	cube[197].position = D3DXVECTOR3(162.33f, -232.98f, 771.55f);
	cube[197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[197].scale = D3DXVECTOR3(10, 1, 10);

	cube[198].position = D3DXVECTOR3(165.49f, -234.66f, 780.22f);
	cube[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[198].scale = D3DXVECTOR3(10, 1, 10);

	cube[199].position = D3DXVECTOR3(168.73f, -236.40f, 789.15f);
	cube[199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[199].scale = D3DXVECTOR3(10, 1, 10);

	cube[200].position = D3DXVECTOR3(171.96f, -238.10f, 798.03f);
	cube[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[200].scale = D3DXVECTOR3(10, 1, 10);

	cube[201].position = D3DXVECTOR3(175.13f, -239.81f, 806.82f);
	cube[201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[201].scale = D3DXVECTOR3(10, 1, 10);

	cube[202].position = D3DXVECTOR3(177.56f, -241.26f, 813.33f);
	cube[202].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[202].scale = D3DXVECTOR3(11, 1, 5);

	cube[203].position = D3DXVECTOR3(178.22f, -241.39f, 813.72f);
	cube[203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[203].scale = D3DXVECTOR3(10, 1, 10);

	cube[204].position = D3DXVECTOR3(182.00f, -242.84f, 819.76f);
	cube[204].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[204].scale = D3DXVECTOR3(11, 1, 5);

	cube[205].position = D3DXVECTOR3(182.37f, -242.98f, 819.91f);
	cube[205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[205].scale = D3DXVECTOR3(10, 1, 10);

	cube[206].position = D3DXVECTOR3(186.91f, -244.40f, 825.24f);
	cube[206].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[206].scale = D3DXVECTOR3(11, 1, 5);

	cube[207].position = D3DXVECTOR3(187.74f, -244.61f, 825.51f);
	cube[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[207].scale = D3DXVECTOR3(10, 1, 10);

	cube[208].position = D3DXVECTOR3(193.26f, -246.07f, 829.96f);
	cube[208].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[208].scale = D3DXVECTOR3(11, 1, 5);

	cube[209].position = D3DXVECTOR3(193.95f, -246.24f, 830.06f);
	cube[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[209].scale = D3DXVECTOR3(10, 1, 10);

	cube[210].position = D3DXVECTOR3(200.07f, -247.66f, 833.41f);
	cube[210].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[210].scale = D3DXVECTOR3(11, 1, 5);

	cube[211].position = D3DXVECTOR3(200.82f, -247.84f, 833.45f);
	cube[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[211].scale = D3DXVECTOR3(10, 1, 10);

	cube[212].position = D3DXVECTOR3(207.79f, -249.29f, 835.68f);
	cube[212].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[212].scale = D3DXVECTOR3(11, 1, 5);

	cube[213].position = D3DXVECTOR3(208.25f, -249.48f, 835.61f);
	cube[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[213].scale = D3DXVECTOR3(10, 1, 10);

	cube[214].position = D3DXVECTOR3(215.22f, -250.95f, 836.60f);
	cube[214].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[214].scale = D3DXVECTOR3(11, 1, 5);

	cube[215].position = D3DXVECTOR3(215.73f, -251.14f, 836.36f);
	cube[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[215].scale = D3DXVECTOR3(10, 1, 10);

	cube[216].position = D3DXVECTOR3(222.86f, -252.62f, 836.28f);
	cube[216].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[216].scale = D3DXVECTOR3(11, 1, 5);

	cube[217].position = D3DXVECTOR3(222.96f, -252.68f, 835.89f);
	cube[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[217].scale = D3DXVECTOR3(10, 1, 10);

	cube[218].position = D3DXVECTOR3(232.16f, -254.35f, 834.27f);
	cube[218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[218].scale = D3DXVECTOR3(10, 1, 10);

	cube[219].position = D3DXVECTOR3(241.49f, -256.04f, 832.63f);
	cube[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[219].scale = D3DXVECTOR3(10, 1, 10);

	cube[220].position = D3DXVECTOR3(250.39f, -257.66f, 831.09f);
	cube[220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[220].scale = D3DXVECTOR3(10, 1, 10);

	cube[221].position = D3DXVECTOR3(257.58f, -259.17f, 830.02f);
	cube[221].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[221].scale = D3DXVECTOR3(11, 1, 5);

	cube[222].position = D3DXVECTOR3(258.41f, -259.35f, 830.26f);
	cube[222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[222].scale = D3DXVECTOR3(10, 1, 10);

	cube[223].position = D3DXVECTOR3(265.43f, -260.83f, 830.45f);
	cube[223].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[223].scale = D3DXVECTOR3(11, 1, 5);

	cube[224].position = D3DXVECTOR3(266.20f, -261.01f, 830.78f);
	cube[224].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[224].scale = D3DXVECTOR3(10, 1, 10);

	cube[225].position = D3DXVECTOR3(272.96f, -262.46f, 832.24f);
	cube[225].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[225].scale = D3DXVECTOR3(11, 1, 5);

	cube[226].position = D3DXVECTOR3(273.34f, -262.61f, 832.53f);
	cube[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[226].scale = D3DXVECTOR3(10, 1, 10);

	cube[227].position = D3DXVECTOR3(279.70f, -264.03f, 835.11f);
	cube[227].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[227].scale = D3DXVECTOR3(11, 1, 5);

	cube[228].position = D3DXVECTOR3(280.47f, -264.26f, 835.65f);
	cube[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[228].scale = D3DXVECTOR3(10, 1, 10);

	cube[229].position = D3DXVECTOR3(286.54f, -265.78f, 839.38f);
	cube[229].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[229].scale = D3DXVECTOR3(11, 1, 5);

	cube[230].position = D3DXVECTOR3(287.05f, -265.97f, 840.13f);
	cube[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[230].scale = D3DXVECTOR3(10, 1, 10);

	cube[231].position = D3DXVECTOR3(291.90f, -267.33f, 844.49f);
	cube[231].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[231].scale = D3DXVECTOR3(11, 1, 5);

	cube[232].position = D3DXVECTOR3(292.57f, -267.60f, 845.41f);
	cube[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[232].scale = D3DXVECTOR3(10, 1, 10);

	cube[233].position = D3DXVECTOR3(296.55f, -268.88f, 850.33f);
	cube[233].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[233].scale = D3DXVECTOR3(11, 1, 5);

	cube[234].position = D3DXVECTOR3(297.19f, -269.23f, 851.76f);
	cube[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[234].scale = D3DXVECTOR3(10, 1, 10);

	cube[235].position = D3DXVECTOR3(300.36f, -270.61f, 857.77f);
	cube[235].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[235].scale = D3DXVECTOR3(11, 1, 5);

	cube[236].position = D3DXVECTOR3(300.52f, -270.79f, 858.48f);
	cube[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[236].scale = D3DXVECTOR3(10, 1, 10);

	cube[237].position = D3DXVECTOR3(303.70f, -272.46f, 867.18f);
	cube[237].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[237].scale = D3DXVECTOR3(10, 1, 10);

	cube[238].position = D3DXVECTOR3(306.96f, -274.16f, 876.15f);
	cube[238].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[238].scale = D3DXVECTOR3(10, 1, 10);

	cube[239].position = D3DXVECTOR3(310.22f, -275.93f, 885.09f);
	cube[239].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[239].scale = D3DXVECTOR3(10, 1, 10);

	cube[240].position = D3DXVECTOR3(312.71f, -277.41f, 891.84f);
	cube[240].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[240].scale = D3DXVECTOR3(11, 1, 5);

	cube[241].position = D3DXVECTOR3(313.37f, -277.54f, 892.23f);
	cube[241].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[241].scale = D3DXVECTOR3(10, 1, 10);

	cube[242].position = D3DXVECTOR3(317.15f, -278.99f, 898.27f);
	cube[242].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[242].scale = D3DXVECTOR3(11, 1, 5);

	cube[243].position = D3DXVECTOR3(317.52f, -279.13f, 898.42f);
	cube[243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[243].scale = D3DXVECTOR3(10, 1, 10);

	cube[244].position = D3DXVECTOR3(322.06f, -280.55f, 903.75f);
	cube[244].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[244].scale = D3DXVECTOR3(11, 1, 5);

	cube[245].position = D3DXVECTOR3(322.89f, -280.76f, 904.02f);
	cube[245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[245].scale = D3DXVECTOR3(10, 1, 10);

	cube[246].position = D3DXVECTOR3(328.41f, -282.22f, 908.47f);
	cube[246].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[246].scale = D3DXVECTOR3(11, 1, 5);

	cube[247].position = D3DXVECTOR3(329.10f, -282.39f, 908.57f);
	cube[247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[247].scale = D3DXVECTOR3(10, 1, 10);

	cube[248].position = D3DXVECTOR3(335.22f, -283.81f, 911.92f);
	cube[248].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[248].scale = D3DXVECTOR3(11, 1, 5);

	cube[249].position = D3DXVECTOR3(335.97f, -283.99f, 911.96f);
	cube[249].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[249].scale = D3DXVECTOR3(10, 1, 10);

	cube[250].position = D3DXVECTOR3(342.94f, -285.44f, 914.19f);
	cube[250].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[250].scale = D3DXVECTOR3(11, 1, 5);

	cube[251].position = D3DXVECTOR3(343.40f, -285.63f, 914.12f);
	cube[251].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[251].scale = D3DXVECTOR3(10, 1, 10);

	cube[252].position = D3DXVECTOR3(350.37f, -287.10f, 915.11f);
	cube[252].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[252].scale = D3DXVECTOR3(11, 1, 5);

	cube[253].position = D3DXVECTOR3(350.88f, -287.29f, 914.87f);
	cube[253].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[253].scale = D3DXVECTOR3(10, 1, 10);

	cube[254].position = D3DXVECTOR3(358.01f, -288.77f, 914.79f);
	cube[254].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[254].scale = D3DXVECTOR3(11, 1, 5);

	cube[255].position = D3DXVECTOR3(358.11f, -288.83f, 914.40f);
	cube[255].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[255].scale = D3DXVECTOR3(10, 1, 10);

	cube[256].position = D3DXVECTOR3(367.50f, -290.56f, 912.75f);
	cube[256].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[256].scale = D3DXVECTOR3(10, 1, 10);

	cube[257].position = D3DXVECTOR3(374.58f, -292.04f, 911.47f);
	cube[257].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[257].scale = D3DXVECTOR3(11, 1, 5);

	cube[258].position = D3DXVECTOR3(375.08f, -292.17f, 910.88f);
	cube[258].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[258].scale = D3DXVECTOR3(10, 1, 10);

	cube[259].position = D3DXVECTOR3(381.69f, -293.62f, 908.21f);
	cube[259].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[259].scale = D3DXVECTOR3(11, 1, 5);

	cube[260].position = D3DXVECTOR3(381.90f, -293.76f, 907.88f);
	cube[260].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[260].scale = D3DXVECTOR3(10, 1, 10);

	cube[261].position = D3DXVECTOR3(387.94f, -295.18f, 904.33f);
	cube[261].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[261].scale = D3DXVECTOR3(11, 1, 5);

	cube[262].position = D3DXVECTOR3(388.34f, -295.39f, 903.56f);
	cube[262].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[262].scale = D3DXVECTOR3(10, 1, 10);

	cube[263].position = D3DXVECTOR3(393.69f, -296.85f, 898.89f);
	cube[263].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[263].scale = D3DXVECTOR3(11, 1, 5);

	cube[264].position = D3DXVECTOR3(393.91f, -297.02f, 898.23f);
	cube[264].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[264].scale = D3DXVECTOR3(10, 1, 10);

	cube[265].position = D3DXVECTOR3(398.27f, -298.44f, 892.78f);
	cube[265].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[265].scale = D3DXVECTOR3(11, 1, 5);

	cube[266].position = D3DXVECTOR3(398.44f, -298.62f, 892.05f);
	cube[266].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[266].scale = D3DXVECTOR3(10, 1, 10);

	cube[267].position = D3DXVECTOR3(401.84f, -300.07f, 885.58f);
	cube[267].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[267].scale = D3DXVECTOR3(11, 1, 5);

	cube[268].position = D3DXVECTOR3(401.86f, -300.26f, 885.11f);
	cube[268].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[268].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[269].position = D3DXVECTOR3(404.04f, -301.73f, 878.42f);
	cube[269].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[269].scale = D3DXVECTOR3(11, 1, 5);

	cube[270].position = D3DXVECTOR3(403.90f, -301.92f, 877.88f);
	cube[270].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[270].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[271].position = D3DXVECTOR3(405.05f, -303.40f, 870.84f);
	cube[271].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[271].scale = D3DXVECTOR3(11, 1, 5);

	cube[272].position = D3DXVECTOR3(404.69f, -303.46f, 870.67f);
	cube[272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[272].scale = D3DXVECTOR3(10, 1, 10);

	cube[273].position = D3DXVECTOR3(404.66f, -305.18f, 861.25f);
	cube[273].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[273].scale = D3DXVECTOR3(10, 1, 10);

	cube[274].position = D3DXVECTOR3(404.66f, -306.93f, 851.71f);
	cube[274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[274].scale = D3DXVECTOR3(10, 1, 10);

	cube[275].position = D3DXVECTOR3(404.66f, -308.63f, 842.32f);
	cube[275].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[275].scale = D3DXVECTOR3(10, 1, 10);

	cube[276].position = D3DXVECTOR3(404.66f, -310.28f, 833.16f);
	cube[276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[276].scale = D3DXVECTOR3(10, 1, 10);

	cube[277].position = D3DXVECTOR3(404.66f, -312.02f, 823.58f);
	cube[277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[277].scale = D3DXVECTOR3(10, 1, 10);

	cube[278].position = D3DXVECTOR3(404.66f, -313.61f, 814.85f);
	cube[278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[278].scale = D3DXVECTOR3(10, 1, 10);

	cube[279].position = D3DXVECTOR3(404.61f, -315.22f, 805.90f);
	cube[279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[279].scale = D3DXVECTOR3(10, 1, 10);

	cube[280].position = D3DXVECTOR3(404.61f, -316.97f, 796.36f);
	cube[280].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[280].scale = D3DXVECTOR3(10, 1, 10);

	cube[281].position = D3DXVECTOR3(404.61f, -318.67f, 786.97f);
	cube[281].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[281].scale = D3DXVECTOR3(10, 1, 10);

	cube[282].position = D3DXVECTOR3(404.61f, -320.32f, 777.81f);
	cube[282].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[282].scale = D3DXVECTOR3(10, 1, 10);

	cube[283].position = D3DXVECTOR3(404.61f, -322.06f, 768.23f);
	cube[283].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[283].scale = D3DXVECTOR3(10, 1, 10);

	cube[284].position = D3DXVECTOR3(404.61f, -323.64f, 759.50f);
	cube[284].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[284].scale = D3DXVECTOR3(10, 1, 10);

	cube[285].position = D3DXVECTOR3(404.61f, -325.19f, 752.47f);
	cube[285].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[285].scale = D3DXVECTOR3(11, 1, 5);

	cube[286].position = D3DXVECTOR3(404.11f, -325.32f, 751.88f);
	cube[286].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[286].scale = D3DXVECTOR3(10, 1, 10);

	cube[287].position = D3DXVECTOR3(402.69f, -326.77f, 744.90f);
	cube[287].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[287].scale = D3DXVECTOR3(11, 1, 5);

	cube[288].position = D3DXVECTOR3(402.33f, -326.91f, 744.64f);
	cube[288].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[288].scale = D3DXVECTOR3(10, 1, 10);

	cube[289].position = D3DXVECTOR3(399.84f, -328.33f, 738.10f);
	cube[289].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[289].scale = D3DXVECTOR3(11, 1, 5);

	cube[290].position = D3DXVECTOR3(399.20f, -328.54f, 737.55f);
	cube[290].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[290].scale = D3DXVECTOR3(10, 1, 10);

	cube[291].position = D3DXVECTOR3(395.56f, -330.00f, 731.45f);
	cube[291].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[291].scale = D3DXVECTOR3(11, 1, 5);

	cube[292].position = D3DXVECTOR3(394.92f, -330.17f, 731.14f);
	cube[292].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[292].scale = D3DXVECTOR3(10, 1, 10);

	cube[293].position = D3DXVECTOR3(388.96f, -331.85f, 724.04f);
	cube[293].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[293].scale = D3DXVECTOR3(10, 1, 10);

	cube[294].position = D3DXVECTOR3(384.48f, -333.36f, 718.31f);
	cube[294].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 220.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[294].scale = D3DXVECTOR3(11, 1, 5);

	cube[295].position = D3DXVECTOR3(384.24f, -333.54f, 717.51f);
	cube[295].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[295].scale = D3DXVECTOR3(10, 1, 10);

	cube[296].position = D3DXVECTOR3(380.96f, -335.02f, 711.29f);
	cube[296].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[296].scale = D3DXVECTOR3(11, 1, 5);

	cube[297].position = D3DXVECTOR3(380.79f, -335.20f, 710.51f);
	cube[297].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[297].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[298].position = D3DXVECTOR3(378.70f, -336.65f, 703.91f);
	cube[298].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 200.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[298].scale = D3DXVECTOR3(11, 1, 5);

	cube[299].position = D3DXVECTOR3(378.74f, -336.80f, 703.44f);
	cube[299].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[299].scale = D3DXVECTOR3(10, 1, 10);

	cube[300].position = D3DXVECTOR3(377.99f, -338.18f, 696.61f);
	cube[300].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 190.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[300].scale = D3DXVECTOR3(11, 1, 5);

	cube[301].position = D3DXVECTOR3(377.87f, -338.45f, 695.71f);
	cube[301].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[301].scale = D3DXVECTOR3(10, 1, 10);

	cube[302].position = D3DXVECTOR3(377.87f, -340.11f, 686.38f);
	cube[302].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[302].scale = D3DXVECTOR3(10, 1, 10);

	cube[303].position = D3DXVECTOR3(377.87f, -341.80f, 676.93f);
	cube[303].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[303].scale = D3DXVECTOR3(10, 1, 10);

	cube[304].position = D3DXVECTOR3(377.88f, -343.35f, 668.49f);
	cube[304].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[304].scale = D3DXVECTOR3(10, 1, 10);

	cube[305].position = D3DXVECTOR3(378.13f, -344.86f, 661.23f);
	cube[305].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[305].scale = D3DXVECTOR3(11, 1, 5);

	cube[306].position = D3DXVECTOR3(378.46f, -345.04f, 660.46f);
	cube[306].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[306].scale = D3DXVECTOR3(10, 1, 10);

	cube[307].position = D3DXVECTOR3(379.94f, -346.52f, 653.59f);
	cube[307].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 170.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[307].scale = D3DXVECTOR3(11, 1, 5);

	cube[308].position = D3DXVECTOR3(380.31f, -346.70f, 652.88f);
	cube[308].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[308].scale = D3DXVECTOR3(10, 1, 10.00001);

	cube[309].position = D3DXVECTOR3(382.96f, -348.15f, 646.48f);
	cube[309].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 160.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[309].scale = D3DXVECTOR3(11, 1, 5);

	cube[310].position = D3DXVECTOR3(383.28f, -348.30f, 646.15f);
	cube[310].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[310].scale = D3DXVECTOR3(10, 1, 10);

	cube[311].position = D3DXVECTOR3(387.10f, -349.68f, 640.43f);
	cube[311].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 150.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[311].scale = D3DXVECTOR3(11, 1, 5);

	cube[312].position = D3DXVECTOR3(387.59f, -349.95f, 639.67f);
	cube[312].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[312].scale = D3DXVECTOR3(10, 1, 10);

	cube[313].position = D3DXVECTOR3(393.74f, -351.67f, 632.32f);
	cube[313].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[313].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[314].position = D3DXVECTOR3(399.79f, -353.37f, 625.11f);
	cube[314].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[314].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[315].position = D3DXVECTOR3(405.91f, -355.10f, 617.81f);
	cube[315].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[315].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[316].position = D3DXVECTOR3(412.02f, -356.85f, 610.58f);
	cube[316].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[316].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[317].position = D3DXVECTOR3(416.87f, -358.36f, 605.17f);
	cube[317].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 140.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[317].scale = D3DXVECTOR3(11.00001, 1, 5);

	cube[318].position = D3DXVECTOR3(417.63f, -358.54f, 604.80f);
	cube[318].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[318].scale = D3DXVECTOR3(10, 1, 10);

	cube[319].position = D3DXVECTOR3(423.12f, -360.02f, 600.43f);
	cube[319].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 130.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[319].scale = D3DXVECTOR3(11.00001, 1, 5);

	cube[320].position = D3DXVECTOR3(423.92f, -360.20f, 600.19f);
	cube[320].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[320].scale = D3DXVECTOR3(10.00001, 1, 10.00001);

	cube[321].position = D3DXVECTOR3(430.05f, -361.65f, 596.98f);
	cube[321].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 120.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[321].scale = D3DXVECTOR3(11, 1, 5);

	cube[322].position = D3DXVECTOR3(430.52f, -361.80f, 596.94f);
	cube[322].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[322].scale = D3DXVECTOR3(10, 1, 10);

	cube[323].position = D3DXVECTOR3(437.07f, -363.22f, 594.86f);
	cube[323].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 110.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[323].scale = D3DXVECTOR3(11, 1, 5);

	cube[324].position = D3DXVECTOR3(437.99f, -363.45f, 594.75f);
	cube[324].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[324].scale = D3DXVECTOR3(10, 1, 10);

	cube[325].position = D3DXVECTOR3(445.05f, -364.97f, 593.78f);
	cube[325].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[325].scale = D3DXVECTOR3(11, 1, 5);

	cube[326].position = D3DXVECTOR3(445.91f, -365.16f, 593.95f);
	cube[326].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[326].scale = D3DXVECTOR3(10, 1, 10);

	cube[327].position = D3DXVECTOR3(452.43f, -366.52f, 594.06f);
	cube[327].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[327].scale = D3DXVECTOR3(11, 1, 5);

	cube[328].position = D3DXVECTOR3(453.54f, -366.79f, 594.45f);
	cube[328].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[328].scale = D3DXVECTOR3(10, 1, 10);

	cube[329].position = D3DXVECTOR3(462.66f, -368.50f, 596.03f);
	cube[329].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[329].scale = D3DXVECTOR3(10, 1, 10);

	cube[330].position = D3DXVECTOR3(472.21f, -370.26f, 597.71f);
	cube[330].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[330].scale = D3DXVECTOR3(10, 1, 10);

	cube[331].position = D3DXVECTOR3(481.59f, -371.98f, 599.37f);
	cube[331].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[331].scale = D3DXVECTOR3(10, 1, 10);

	cube[332].position = D3DXVECTOR3(491.03f, -373.71f, 601.03f);
	cube[332].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[332].scale = D3DXVECTOR3(10, 1, 10);

	cube[333].position = D3DXVECTOR3(498.72f, -375.09f, 602.42f);
	cube[333].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[333].scale = D3DXVECTOR3(10, 1, 10);

	cube[334].position = D3DXVECTOR3(508.27f, -376.83f, 604.09f);
	cube[334].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[334].scale = D3DXVECTOR3(10, 1, 10);

	cube[335].position = D3DXVECTOR3(517.56f, -378.51f, 605.73f);
	cube[335].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[335].scale = D3DXVECTOR3(10, 1, 10);

	cube[336].position = D3DXVECTOR3(526.97f, -380.22f, 607.39f);
	cube[336].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[336].scale = D3DXVECTOR3(10, 1, 10);

	cube[337].position = D3DXVECTOR3(536.36f, -381.93f, 609.05f);
	cube[337].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[337].scale = D3DXVECTOR3(10, 1, 10);

	cube[338].position = D3DXVECTOR3(545.72f, -383.63f, 610.70f);
	cube[338].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[338].scale = D3DXVECTOR3(10, 1, 10);

	cube[339].position = D3DXVECTOR3(554.83f, -385.34f, 612.32f);
	cube[339].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[339].scale = D3DXVECTOR3(10, 1, 10);

	cube[340].position = D3DXVECTOR3(564.38f, -387.10f, 614.00f);
	cube[340].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[340].scale = D3DXVECTOR3(10, 1, 10);

	cube[341].position = D3DXVECTOR3(573.76f, -388.82f, 615.66f);
	cube[341].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[341].scale = D3DXVECTOR3(10, 1, 10);

	cube[342].position = D3DXVECTOR3(583.20f, -390.55f, 617.32f);
	cube[342].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[342].scale = D3DXVECTOR3(10, 1, 10);

	cube[343].position = D3DXVECTOR3(590.89f, -391.93f, 618.71f);
	cube[343].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[343].scale = D3DXVECTOR3(10, 1, 10);

	cube[344].position = D3DXVECTOR3(600.44f, -393.67f, 620.38f);
	cube[344].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[344].scale = D3DXVECTOR3(10, 1, 10);

	cube[345].position = D3DXVECTOR3(609.73f, -395.35f, 622.02f);
	cube[345].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[345].scale = D3DXVECTOR3(10, 1, 10);

	cube[346].position = D3DXVECTOR3(619.14f, -397.06f, 623.68f);
	cube[346].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[346].scale = D3DXVECTOR3(10, 1, 10);

	cube[347].position = D3DXVECTOR3(628.53f, -398.77f, 625.34f);
	cube[347].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[347].scale = D3DXVECTOR3(10, 1, 10);

	cube[348].position = D3DXVECTOR3(637.89f, -400.47f, 626.99f);
	cube[348].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	cube[348].scale = D3DXVECTOR3(10, 1, 10);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cube[349].position = D3DXVECTOR3(5.70f, -10.22f, 2.16f);
	cube[349].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[349].scale = D3DXVECTOR3(3, 1, 10);

	cube[350].position = D3DXVECTOR3(7.02f, -9.07f, 2.37f);
	cube[350].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[350].scale = D3DXVECTOR3(3, 1, 10);

	cube[351].position = D3DXVECTOR3(5.70f, -11.88f, 11.16f);
	cube[351].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[351].scale = D3DXVECTOR3(3, 1, 10);

	cube[352].position = D3DXVECTOR3(7.02f, -10.73f, 11.37f);
	cube[352].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[352].scale = D3DXVECTOR3(3, 1, 10);

	cube[353].position = D3DXVECTOR3(5.70f, -13.47f, 19.86f);
	cube[353].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[353].scale = D3DXVECTOR3(3, 1, 10);

	cube[354].position = D3DXVECTOR3(7.02f, -12.32f, 20.07f);
	cube[354].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[354].scale = D3DXVECTOR3(3, 1, 10);

	cube[355].position = D3DXVECTOR3(5.70f, -15.15f, 28.96f);
	cube[355].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[355].scale = D3DXVECTOR3(3, 1, 10);

	cube[356].position = D3DXVECTOR3(7.02f, -14.00f, 29.17f);
	cube[356].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[356].scale = D3DXVECTOR3(3, 1, 10);

	cube[357].position = D3DXVECTOR3(5.70f, -16.94f, 38.36f);
	cube[357].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[357].scale = D3DXVECTOR3(3, 1, 10);

	cube[358].position = D3DXVECTOR3(7.02f, -15.79f, 38.57f);
	cube[358].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[358].scale = D3DXVECTOR3(3, 1, 10);

	cube[359].position = D3DXVECTOR3(5.70f, -18.62f, 47.66f);
	cube[359].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[359].scale = D3DXVECTOR3(3, 1, 10);

	cube[360].position = D3DXVECTOR3(7.02f, -17.47f, 47.87f);
	cube[360].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[360].scale = D3DXVECTOR3(3, 1, 10);

	cube[361].position = D3DXVECTOR3(5.70f, -20.41f, 57.36f);
	cube[361].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[361].scale = D3DXVECTOR3(3, 1, 10);

	cube[362].position = D3DXVECTOR3(7.02f, -19.26f, 57.57f);
	cube[362].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[362].scale = D3DXVECTOR3(3, 1, 10);

	cube[363].position = D3DXVECTOR3(5.70f, -22.00f, 66.16f);
	cube[363].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[363].scale = D3DXVECTOR3(3, 1, 10);

	cube[364].position = D3DXVECTOR3(7.02f, -20.85f, 66.37f);
	cube[364].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[364].scale = D3DXVECTOR3(3, 1, 10);

	cube[365].position = D3DXVECTOR3(5.70f, -23.37f, 73.77f);
	cube[365].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[365].scale = D3DXVECTOR3(3, 1, 10);

	cube[366].position = D3DXVECTOR3(7.02f, -22.22f, 73.98f);
	cube[366].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[366].scale = D3DXVECTOR3(3, 1, 10);

	cube[367].position = D3DXVECTOR3(5.70f, -25.07f, 83.25f);
	cube[367].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[367].scale = D3DXVECTOR3(3, 1, 10);

	cube[368].position = D3DXVECTOR3(7.02f, -23.92f, 83.46f);
	cube[368].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[368].scale = D3DXVECTOR3(3, 1, 10);

	cube[369].position = D3DXVECTOR3(5.70f, -26.73f, 92.25f);
	cube[369].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[369].scale = D3DXVECTOR3(3, 1, 10);

	cube[370].position = D3DXVECTOR3(7.02f, -25.58f, 92.46f);
	cube[370].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[370].scale = D3DXVECTOR3(3, 1, 10);

	cube[371].position = D3DXVECTOR3(5.70f, -28.32f, 100.95f);
	cube[371].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[371].scale = D3DXVECTOR3(3, 1, 10);

	cube[372].position = D3DXVECTOR3(7.02f, -27.17f, 101.16f);
	cube[372].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[372].scale = D3DXVECTOR3(3, 1, 10);

	cube[373].position = D3DXVECTOR3(5.70f, -30.00f, 110.05f);
	cube[373].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[373].scale = D3DXVECTOR3(3, 1, 10);

	cube[374].position = D3DXVECTOR3(7.02f, -28.85f, 110.26f);
	cube[374].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[374].scale = D3DXVECTOR3(3, 1, 10);

	cube[375].position = D3DXVECTOR3(5.70f, -31.79f, 119.45f);
	cube[375].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[375].scale = D3DXVECTOR3(3, 1, 10);

	cube[376].position = D3DXVECTOR3(7.02f, -30.64f, 119.66f);
	cube[376].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[376].scale = D3DXVECTOR3(3, 1, 10);

	cube[377].position = D3DXVECTOR3(5.70f, -33.47f, 128.75f);
	cube[377].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[377].scale = D3DXVECTOR3(3, 1, 10);

	cube[378].position = D3DXVECTOR3(7.02f, -32.32f, 128.96f);
	cube[378].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[378].scale = D3DXVECTOR3(3, 1, 10);

	cube[379].position = D3DXVECTOR3(5.70f, -35.26f, 138.45f);
	cube[379].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[379].scale = D3DXVECTOR3(3, 1, 10);

	cube[380].position = D3DXVECTOR3(7.02f, -34.11f, 138.66f);
	cube[380].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[380].scale = D3DXVECTOR3(3, 1, 10);

	cube[381].position = D3DXVECTOR3(5.70f, -36.85f, 147.25f);
	cube[381].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[381].scale = D3DXVECTOR3(3, 1, 10);

	cube[382].position = D3DXVECTOR3(7.02f, -35.70f, 147.46f);
	cube[382].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[382].scale = D3DXVECTOR3(3, 1, 10);

	cube[383].position = D3DXVECTOR3(5.70f, -38.22f, 154.87f);
	cube[383].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[383].scale = D3DXVECTOR3(3, 1, 10);

	cube[384].position = D3DXVECTOR3(7.02f, -37.07f, 155.08f);
	cube[384].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[384].scale = D3DXVECTOR3(3, 1, 10);

	cube[385].position = D3DXVECTOR3(5.14f, -39.91f, 163.68f);
	cube[385].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[385].scale = D3DXVECTOR3(3, 1, 10);

	cube[386].position = D3DXVECTOR3(6.40f, -38.76f, 164.12f);
	cube[386].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[386].scale = D3DXVECTOR3(3, 1, 10);

	cube[387].position = D3DXVECTOR3(3.00f, -41.57f, 172.26f);
	cube[387].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[387].scale = D3DXVECTOR3(3, 1, 10);

	cube[388].position = D3DXVECTOR3(4.16f, -40.42f, 172.91f);
	cube[388].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[388].scale = D3DXVECTOR3(3, 1, 10);

	cube[389].position = D3DXVECTOR3(-0.43f, -43.17f, 179.93f);
	cube[389].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[389].scale = D3DXVECTOR3(3, 1, 10);

	cube[390].position = D3DXVECTOR3(0.61f, -42.02f, 180.77f);
	cube[390].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[390].scale = D3DXVECTOR3(3, 1, 10);

	cube[391].position = D3DXVECTOR3(-5.35f, -44.82f, 187.25f);
	cube[391].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[391].scale = D3DXVECTOR3(3, 1, 10);

	cube[392].position = D3DXVECTOR3(-4.47f, -43.67f, 188.26f);
	cube[392].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[392].scale = D3DXVECTOR3(3, 1, 10);

	cube[393].position = D3DXVECTOR3(-11.65f, -46.53f, 193.68f);
	cube[393].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[393].scale = D3DXVECTOR3(3, 1, 10);

	cube[394].position = D3DXVECTOR3(-10.96f, -45.38f, 194.82f);
	cube[394].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[394].scale = D3DXVECTOR3(3, 1, 10);

	cube[395].position = D3DXVECTOR3(-18.67f, -48.16f, 198.78f);
	cube[395].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[395].scale = D3DXVECTOR3(3, 1, 10);

	cube[396].position = D3DXVECTOR3(-18.19f, -47.01f, 200.03f);
	cube[396].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[396].scale = D3DXVECTOR3(3, 1, 10);

	cube[397].position = D3DXVECTOR3(-26.15f, -49.75f, 203.15f);
	cube[397].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[397].scale = D3DXVECTOR3(3, 1, 10);

	cube[398].position = D3DXVECTOR3(-25.67f, -48.60f, 204.40f);
	cube[398].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[398].scale = D3DXVECTOR3(3, 1, 10);

	cube[399].position = D3DXVECTOR3(-34.11f, -51.48f, 207.76f);
	cube[399].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[399].scale = D3DXVECTOR3(3, 1, 10);

	cube[400].position = D3DXVECTOR3(-33.63f, -50.33f, 209.01f);
	cube[400].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[400].scale = D3DXVECTOR3(3, 1, 10);

	cube[401].position = D3DXVECTOR3(-41.41f, -53.03f, 211.96f);
	cube[401].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[401].scale = D3DXVECTOR3(3, 1, 10);

	cube[402].position = D3DXVECTOR3(-40.93f, -51.88f, 213.21f);
	cube[402].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[402].scale = D3DXVECTOR3(3, 1, 10);

	cube[403].position = D3DXVECTOR3(-48.71f, -54.55f, 216.16f);
	cube[403].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[403].scale = D3DXVECTOR3(3, 1, 10);

	cube[404].position = D3DXVECTOR3(-48.23f, -53.40f, 217.41f);
	cube[404].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[404].scale = D3DXVECTOR3(3, 1, 10);

	cube[405].position = D3DXVECTOR3(-56.61f, -56.28f, 220.76f);
	cube[405].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[405].scale = D3DXVECTOR3(3, 1, 10);

	cube[406].position = D3DXVECTOR3(-56.13f, -55.13f, 222.01f);
	cube[406].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[406].scale = D3DXVECTOR3(3, 1, 10);

	cube[407].position = D3DXVECTOR3(-64.47f, -57.92f, 225.23f);
	cube[407].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[407].scale = D3DXVECTOR3(3, 1, 10);

	cube[408].position = D3DXVECTOR3(-63.99f, -56.77f, 226.48f);
	cube[408].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[408].scale = D3DXVECTOR3(3, 1, 10);

	cube[409].position = D3DXVECTOR3(-72.04f, -59.49f, 229.58f);
	cube[409].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[409].scale = D3DXVECTOR3(3, 1, 10);

	cube[410].position = D3DXVECTOR3(-71.56f, -58.34f, 230.83f);
	cube[410].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[410].scale = D3DXVECTOR3(3, 1, 10);

	cube[411].position = D3DXVECTOR3(-80.00f, -61.22f, 234.19f);
	cube[411].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[411].scale = D3DXVECTOR3(3, 1, 10);

	cube[412].position = D3DXVECTOR3(-79.52f, -60.07f, 235.44f);
	cube[412].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[412].scale = D3DXVECTOR3(3, 1, 10);

	cube[413].position = D3DXVECTOR3(-87.30f, -62.77f, 238.39f);
	cube[413].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[413].scale = D3DXVECTOR3(3, 1, 10);

	cube[414].position = D3DXVECTOR3(-86.82f, -61.62f, 239.64f);
	cube[414].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[414].scale = D3DXVECTOR3(3, 1, 10);

	cube[415].position = D3DXVECTOR3(-94.60f, -64.29f, 242.59f);
	cube[415].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[415].scale = D3DXVECTOR3(3, 1, 10);

	cube[416].position = D3DXVECTOR3(-94.12f, -63.14f, 243.84f);
	cube[416].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[416].scale = D3DXVECTOR3(3, 1, 10);

	cube[417].position = D3DXVECTOR3(-102.50f, -66.02f, 247.19f);
	cube[417].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[417].scale = D3DXVECTOR3(3, 1, 10);

	cube[418].position = D3DXVECTOR3(-102.02f, -64.87f, 248.44f);
	cube[418].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[418].scale = D3DXVECTOR3(3, 1, 10);

	cube[419].position = D3DXVECTOR3(-110.36f, -67.66f, 251.66f);
	cube[419].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[419].scale = D3DXVECTOR3(3, 1, 10);

	cube[420].position = D3DXVECTOR3(-109.88f, -66.51f, 252.91f);
	cube[420].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[420].scale = D3DXVECTOR3(3, 1, 10);

	cube[421].position = D3DXVECTOR3(-118.39f, -69.36f, 255.56f);
	cube[421].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[421].scale = D3DXVECTOR3(3, 1, 10);

	cube[422].position = D3DXVECTOR3(-118.14f, -68.21f, 256.88f);
	cube[422].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[422].scale = D3DXVECTOR3(3, 1, 10);

	cube[423].position = D3DXVECTOR3(-126.89f, -71.02f, 258.00f);
	cube[423].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[423].scale = D3DXVECTOR3(3, 1, 10);

	cube[424].position = D3DXVECTOR3(-126.87f, -69.87f, 259.34f);
	cube[424].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[424].scale = D3DXVECTOR3(3, 1, 10);

	cube[425].position = D3DXVECTOR3(-135.24f, -72.62f, 258.87f);
	cube[425].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[425].scale = D3DXVECTOR3(3, 1, 10);

	cube[426].position = D3DXVECTOR3(-135.45f, -71.47f, 260.19f);
	cube[426].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[426].scale = D3DXVECTOR3(3, 1, 10);

	cube[427].position = D3DXVECTOR3(-144.04f, -74.27f, 258.27f);
	cube[427].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[427].scale = D3DXVECTOR3(3, 1, 10);

	cube[428].position = D3DXVECTOR3(-144.48f, -73.12f, 259.53f);
	cube[428].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[428].scale = D3DXVECTOR3(3, 1, 10);

	cube[429].position = D3DXVECTOR3(-150.70f, -75.57f, 257.08f);
	cube[429].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[429].scale = D3DXVECTOR3(3, 1, 10);

	cube[430].position = D3DXVECTOR3(-151.14f, -74.42f, 258.34f);
	cube[430].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[430].scale = D3DXVECTOR3(3, 1, 10);

	cube[431].position = D3DXVECTOR3(-157.42f, -77.18f, 256.35f);
	cube[431].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[431].scale = D3DXVECTOR3(3, 1, 10);

	cube[432].position = D3DXVECTOR3(-158.30f, -77.28f, 256.05f);
	cube[432].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[432].scale = D3DXVECTOR3(3, 1, 7);

	cube[433].position = D3DXVECTOR3(-157.63f, -76.03f, 257.67f);
	cube[433].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[433].scale = D3DXVECTOR3(3, 1, 10);

	cube[434].position = D3DXVECTOR3(-158.80f, -76.04f, 257.58f);
	cube[434].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[434].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[435].position = D3DXVECTOR3(-163.82f, -78.77f, 256.77f);
	cube[435].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[435].scale = D3DXVECTOR3(3, 1, 10);

	cube[436].position = D3DXVECTOR3(-165.14f, -78.86f, 256.81f);
	cube[436].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[436].scale = D3DXVECTOR3(3, 1, 7);

	cube[437].position = D3DXVECTOR3(-163.80f, -77.62f, 258.10f);
	cube[437].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[437].scale = D3DXVECTOR3(3, 1, 10);

	cube[438].position = D3DXVECTOR3(-165.42f, -77.77f, 258.16f);
	cube[438].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[438].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[439].position = D3DXVECTOR3(-170.34f, -80.40f, 258.37f);
	cube[439].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[439].scale = D3DXVECTOR3(3, 1, 10);

	cube[440].position = D3DXVECTOR3(-171.60f, -80.45f, 258.69f);
	cube[440].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[440].scale = D3DXVECTOR3(3, 1, 7);

	cube[441].position = D3DXVECTOR3(-170.09f, -79.25f, 259.68f);
	cube[441].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[441].scale = D3DXVECTOR3(3, 1, 10);

	cube[442].position = D3DXVECTOR3(-171.39f, -79.36f, 259.95f);
	cube[442].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[442].scale = D3DXVECTOR3(5, 1, 7);

	cube[443].position = D3DXVECTOR3(-176.45f, -82.03f, 261.04f);
	cube[443].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[443].scale = D3DXVECTOR3(3, 1, 10);

	cube[444].position = D3DXVECTOR3(-177.61f, -82.09f, 261.57f);
	cube[444].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[444].scale = D3DXVECTOR3(3, 1, 7);

	cube[445].position = D3DXVECTOR3(-175.97f, -80.88f, 262.29f);
	cube[445].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[445].scale = D3DXVECTOR3(3, 1, 10);

	cube[446].position = D3DXVECTOR3(-177.20f, -81.00f, 262.79f);
	cube[446].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[446].scale = D3DXVECTOR3(5, 1, 7);

	cube[447].position = D3DXVECTOR3(-181.96f, -83.63f, 264.72f);
	cube[447].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[447].scale = D3DXVECTOR3(3, 1, 10);

	cube[448].position = D3DXVECTOR3(-182.92f, -83.68f, 265.36f);
	cube[448].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[448].scale = D3DXVECTOR3(3, 1, 7);

	cube[449].position = D3DXVECTOR3(-181.27f, -82.48f, 265.86f);
	cube[449].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[449].scale = D3DXVECTOR3(3, 1, 10);

	cube[450].position = D3DXVECTOR3(-182.33f, -82.58f, 266.49f);
	cube[450].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[450].scale = D3DXVECTOR3(5, 1, 7);

	cube[451].position = D3DXVECTOR3(-186.79f, -85.27f, 269.35f);
	cube[451].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[451].scale = D3DXVECTOR3(3, 1, 10);

	cube[452].position = D3DXVECTOR3(-187.54f, -85.28f, 270.03f);
	cube[452].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[452].scale = D3DXVECTOR3(3, 1, 7);

	cube[453].position = D3DXVECTOR3(-185.92f, -84.12f, 270.35f);
	cube[453].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[453].scale = D3DXVECTOR3(3, 1, 10);

	cube[454].position = D3DXVECTOR3(-186.90f, -84.21f, 271.22f);
	cube[454].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[454].scale = D3DXVECTOR3(5, 1, 6.500003);

	cube[455].position = D3DXVECTOR3(-190.57f, -86.93f, 274.60f);
	cube[455].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[455].scale = D3DXVECTOR3(3, 1, 10);

	cube[456].position = D3DXVECTOR3(-191.34f, -86.94f, 275.61f);
	cube[456].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[456].scale = D3DXVECTOR3(3, 1, 7);

	cube[457].position = D3DXVECTOR3(-189.53f, -85.78f, 275.44f);
	cube[457].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[457].scale = D3DXVECTOR3(3, 1, 10);

	cube[458].position = D3DXVECTOR3(-190.50f, -85.91f, 276.67f);
	cube[458].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[458].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[459].position = D3DXVECTOR3(-193.33f, -88.47f, 280.17f);
	cube[459].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[459].scale = D3DXVECTOR3(3, 1, 10);

	cube[460].position = D3DXVECTOR3(-193.89f, -88.51f, 281.28f);
	cube[460].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[460].scale = D3DXVECTOR3(3, 1, 7);

	cube[461].position = D3DXVECTOR3(-192.16f, -87.32f, 280.82f);
	cube[461].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[461].scale = D3DXVECTOR3(3, 1, 10);

	cube[462].position = D3DXVECTOR3(-192.87f, -87.46f, 282.17f);
	cube[462].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[462].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[463].position = D3DXVECTOR3(-195.80f, -89.83f, 286.86f);
	cube[463].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[463].scale = D3DXVECTOR3(3, 1, 10);

	cube[464].position = D3DXVECTOR3(-194.64f, -88.68f, 287.51f);
	cube[464].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[464].scale = D3DXVECTOR3(3, 1, 10);

	cube[465].position = D3DXVECTOR3(-197.69f, -91.44f, 293.36f);
	cube[465].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[465].scale = D3DXVECTOR3(3, 1, 10);

	cube[466].position = D3DXVECTOR3(-198.14f, -91.54f, 294.17f);
	cube[466].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[466].scale = D3DXVECTOR3(3, 1, 7);

	cube[467].position = D3DXVECTOR3(-196.43f, -90.29f, 293.79f);
	cube[467].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[467].scale = D3DXVECTOR3(3, 1, 10);

	cube[468].position = D3DXVECTOR3(-196.72f, -90.30f, 294.93f);
	cube[468].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[468].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[469].position = D3DXVECTOR3(-198.39f, -93.03f, 299.73f);
	cube[469].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[469].scale = D3DXVECTOR3(3, 1, 10);

	cube[470].position = D3DXVECTOR3(-198.58f, -93.12f, 301.04f);
	cube[470].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[470].scale = D3DXVECTOR3(3, 1, 7);

	cube[471].position = D3DXVECTOR3(-197.07f, -91.88f, 299.94f);
	cube[471].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[471].scale = D3DXVECTOR3(3, 1, 10);

	cube[472].position = D3DXVECTOR3(-197.30f, -92.03f, 301.55f);
	cube[472].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[472].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[473].position = D3DXVECTOR3(-197.95f, -94.66f, 306.43f);
	cube[473].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[473].scale = D3DXVECTOR3(3, 1, 10);

	cube[474].position = D3DXVECTOR3(-197.85f, -94.71f, 307.72f);
	cube[474].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[474].scale = D3DXVECTOR3(3, 1, 7);

	cube[475].position = D3DXVECTOR3(-196.61f, -93.51f, 306.41f);
	cube[475].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[475].scale = D3DXVECTOR3(3, 1, 10);

	cube[476].position = D3DXVECTOR3(-196.57f, -93.62f, 307.74f);
	cube[476].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[476].scale = D3DXVECTOR3(5, 1, 7);

	cube[477].position = D3DXVECTOR3(-196.37f, -96.29f, 312.91f);
	cube[477].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[477].scale = D3DXVECTOR3(3, 1, 10);

	cube[478].position = D3DXVECTOR3(-196.06f, -96.35f, 314.14f);
	cube[478].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[478].scale = D3DXVECTOR3(3, 1, 7);

	cube[479].position = D3DXVECTOR3(-195.06f, -95.14f, 312.65f);
	cube[479].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[479].scale = D3DXVECTOR3(3, 1, 10);

	cube[480].position = D3DXVECTOR3(-194.79f, -95.26f, 313.96f);
	cube[480].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[480].scale = D3DXVECTOR3(5, 1, 7);

	cube[481].position = D3DXVECTOR3(-193.71f, -97.89f, 318.97f);
	cube[481].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[481].scale = D3DXVECTOR3(3, 1, 10);

	cube[482].position = D3DXVECTOR3(-193.24f, -97.94f, 320.03f);
	cube[482].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[482].scale = D3DXVECTOR3(3, 1, 7);

	cube[483].position = D3DXVECTOR3(-192.46f, -96.74f, 318.49f);
	cube[483].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[483].scale = D3DXVECTOR3(3, 1, 10);

	cube[484].position = D3DXVECTOR3(-192.03f, -96.84f, 319.64f);
	cube[484].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[484].scale = D3DXVECTOR3(5, 1, 7);

	cube[485].position = D3DXVECTOR3(-189.99f, -99.53f, 324.54f);
	cube[485].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[485].scale = D3DXVECTOR3(3, 1, 10);

	cube[486].position = D3DXVECTOR3(-189.45f, -99.54f, 325.39f);
	cube[486].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[486].scale = D3DXVECTOR3(3, 1, 7);

	cube[487].position = D3DXVECTOR3(-188.85f, -98.38f, 323.85f);
	cube[487].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[487].scale = D3DXVECTOR3(3, 1, 10);

	cube[488].position = D3DXVECTOR3(-188.16f, -98.47f, 324.97f);
	cube[488].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[488].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[489].position = D3DXVECTOR3(-185.47f, -101.19f, 329.17f);
	cube[489].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[489].scale = D3DXVECTOR3(3, 1, 10);

	cube[490].position = D3DXVECTOR3(-184.62f, -101.20f, 330.10f);
	cube[490].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[490].scale = D3DXVECTOR3(3, 1, 7);

	cube[491].position = D3DXVECTOR3(-184.46f, -100.04f, 328.30f);
	cube[491].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[491].scale = D3DXVECTOR3(3, 1, 10);

	cube[492].position = D3DXVECTOR3(-183.42f, -100.17f, 329.46f);
	cube[492].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[492].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[493].position = D3DXVECTOR3(-180.47f, -102.73f, 332.85f);
	cube[493].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[493].scale = D3DXVECTOR3(3, 1, 10);

	cube[494].position = D3DXVECTOR3(-179.47f, -102.77f, 333.60f);
	cube[494].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[494].scale = D3DXVECTOR3(3, 1, 7);

	cube[495].position = D3DXVECTOR3(-179.63f, -101.58f, 331.82f);
	cube[495].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[495].scale = D3DXVECTOR3(3, 1, 10);

	cube[496].position = D3DXVECTOR3(-178.42f, -101.72f, 332.75f);
	cube[496].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[496].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[497].position = D3DXVECTOR3(-172.74f, -104.40f, 337.33f);
	cube[497].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[497].scale = D3DXVECTOR3(3, 1, 10);

	cube[498].position = D3DXVECTOR3(-171.90f, -103.25f, 336.29f);
	cube[498].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[498].scale = D3DXVECTOR3(3, 1, 10);

	cube[499].position = D3DXVECTOR3(-164.66f, -106.10f, 342.00f);
	cube[499].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[499].scale = D3DXVECTOR3(3, 1, 10);

	cube[500].position = D3DXVECTOR3(-163.82f, -104.95f, 340.96f);
	cube[500].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[500].scale = D3DXVECTOR3(3, 1, 10);

	cube[501].position = D3DXVECTOR3(-156.16f, -107.85f, 346.93f);
	cube[501].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[501].scale = D3DXVECTOR3(3, 1, 10);

	cube[502].position = D3DXVECTOR3(-155.32f, -106.70f, 345.89f);
	cube[502].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[502].scale = D3DXVECTOR3(3, 1, 10);

	cube[503].position = D3DXVECTOR3(-148.10f, -109.52f, 351.65f);
	cube[503].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[503].scale = D3DXVECTOR3(3, 1, 10);

	cube[504].position = D3DXVECTOR3(-147.26f, -108.37f, 350.61f);
	cube[504].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[504].scale = D3DXVECTOR3(3, 1, 10);

	cube[505].position = D3DXVECTOR3(-142.04f, -111.13f, 354.64f);
	cube[505].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[505].scale = D3DXVECTOR3(3, 1, 10);

	cube[506].position = D3DXVECTOR3(-141.32f, -111.23f, 355.22f);
	cube[506].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[506].scale = D3DXVECTOR3(3, 1, 7);

	cube[507].position = D3DXVECTOR3(-141.39f, -109.98f, 353.47f);
	cube[507].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[507].scale = D3DXVECTOR3(3, 1, 10);

	cube[508].position = D3DXVECTOR3(-140.32f, -109.99f, 353.95f);
	cube[508].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[508].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[509].position = D3DXVECTOR3(-135.88f, -112.72f, 356.44f);
	cube[509].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[509].scale = D3DXVECTOR3(3, 1, 10);

	cube[510].position = D3DXVECTOR3(-134.63f, -112.81f, 356.85f);
	cube[510].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[510].scale = D3DXVECTOR3(3, 1, 7);

	cube[511].position = D3DXVECTOR3(-135.45f, -111.57f, 355.17f);
	cube[511].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[511].scale = D3DXVECTOR3(3, 1, 10);

	cube[512].position = D3DXVECTOR3(-133.90f, -111.72f, 355.67f);
	cube[512].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[512].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[513].position = D3DXVECTOR3(-129.21f, -114.35f, 357.16f);
	cube[513].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[513].scale = D3DXVECTOR3(3, 1, 10);

	cube[514].position = D3DXVECTOR3(-127.92f, -114.40f, 357.29f);
	cube[514].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[514].scale = D3DXVECTOR3(3, 1, 7);

	cube[515].position = D3DXVECTOR3(-129.00f, -113.20f, 355.84f);
	cube[515].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[515].scale = D3DXVECTOR3(3, 1, 10);

	cube[516].position = D3DXVECTOR3(-127.68f, -113.31f, 356.03f);
	cube[516].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[516].scale = D3DXVECTOR3(5, 1, 7);

	cube[517].position = D3DXVECTOR3(-122.56f, -115.98f, 356.73f);
	cube[517].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[517].scale = D3DXVECTOR3(3, 1, 10);

	cube[518].position = D3DXVECTOR3(-121.28f, -116.04f, 356.64f);
	cube[518].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[518].scale = D3DXVECTOR3(3, 1, 7);

	cube[519].position = D3DXVECTOR3(-122.58f, -114.83f, 355.40f);
	cube[519].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[519].scale = D3DXVECTOR3(3, 1, 10);

	cube[520].position = D3DXVECTOR3(-121.25f, -114.95f, 355.35f);
	cube[520].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[520].scale = D3DXVECTOR3(5, 1, 7);

	cube[521].position = D3DXVECTOR3(-113.28f, -117.68f, 355.10f);
	cube[521].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[521].scale = D3DXVECTOR3(3, 1, 10);

	cube[522].position = D3DXVECTOR3(-113.30f, -116.53f, 353.76f);
	cube[522].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[522].scale = D3DXVECTOR3(3, 1, 10);

	cube[523].position = D3DXVECTOR3(-104.22f, -119.37f, 354.20f);
	cube[523].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[523].scale = D3DXVECTOR3(3, 1, 10);

	cube[524].position = D3DXVECTOR3(-104.01f, -118.22f, 352.88f);
	cube[524].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[524].scale = D3DXVECTOR3(3, 1, 10);

	cube[525].position = D3DXVECTOR3(-95.40f, -121.03f, 354.82f);
	cube[525].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[525].scale = D3DXVECTOR3(3, 1, 10);

	cube[526].position = D3DXVECTOR3(-94.97f, -119.88f, 353.56f);
	cube[526].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[526].scale = D3DXVECTOR3(3, 1, 10);

	cube[527].position = D3DXVECTOR3(-87.26f, -122.63f, 356.86f);
	cube[527].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[527].scale = D3DXVECTOR3(3, 1, 10);

	cube[528].position = D3DXVECTOR3(-86.61f, -121.48f, 355.69f);
	cube[528].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[528].scale = D3DXVECTOR3(3, 1, 10);

	cube[529].position = D3DXVECTOR3(-79.19f, -124.28f, 360.43f);
	cube[529].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[529].scale = D3DXVECTOR3(3, 1, 10);

	cube[530].position = D3DXVECTOR3(-78.35f, -123.13f, 359.39f);
	cube[530].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[530].scale = D3DXVECTOR3(3, 1, 10);

	cube[531].position = D3DXVECTOR3(-71.27f, -125.95f, 365.03f);
	cube[531].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[531].scale = D3DXVECTOR3(3, 1, 10);

	cube[532].position = D3DXVECTOR3(-70.43f, -124.80f, 363.99f);
	cube[532].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[532].scale = D3DXVECTOR3(3, 1, 10);

	cube[533].position = D3DXVECTOR3(-65.21f, -127.56f, 368.02f);
	cube[533].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[533].scale = D3DXVECTOR3(3, 1, 10);

	cube[534].position = D3DXVECTOR3(-64.49f, -127.66f, 368.60f);
	cube[534].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[534].scale = D3DXVECTOR3(3, 1, 7);

	cube[535].position = D3DXVECTOR3(-64.56f, -126.41f, 366.85f);
	cube[535].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[535].scale = D3DXVECTOR3(3, 1, 10);

	cube[536].position = D3DXVECTOR3(-63.49f, -126.42f, 367.33f);
	cube[536].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[536].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[537].position = D3DXVECTOR3(-59.05f, -129.15f, 369.82f);
	cube[537].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[537].scale = D3DXVECTOR3(3, 1, 10);

	cube[538].position = D3DXVECTOR3(-57.80f, -129.24f, 370.23f);
	cube[538].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[538].scale = D3DXVECTOR3(3, 1, 7);

	cube[539].position = D3DXVECTOR3(-58.62f, -128.00f, 368.55f);
	cube[539].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[539].scale = D3DXVECTOR3(3, 1, 10);

	cube[540].position = D3DXVECTOR3(-57.07f, -128.15f, 369.05f);
	cube[540].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[540].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[541].position = D3DXVECTOR3(-52.38f, -130.78f, 370.54f);
	cube[541].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[541].scale = D3DXVECTOR3(3, 1, 10);

	cube[542].position = D3DXVECTOR3(-51.09f, -130.83f, 370.67f);
	cube[542].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[542].scale = D3DXVECTOR3(3, 1, 7);

	cube[543].position = D3DXVECTOR3(-52.17f, -129.63f, 369.22f);
	cube[543].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[543].scale = D3DXVECTOR3(3, 1, 10);

	cube[544].position = D3DXVECTOR3(-50.85f, -129.74f, 369.41f);
	cube[544].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[544].scale = D3DXVECTOR3(5, 1, 7);

	cube[545].position = D3DXVECTOR3(-45.73f, -132.41f, 370.11f);
	cube[545].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[545].scale = D3DXVECTOR3(3, 1, 10);

	cube[546].position = D3DXVECTOR3(-44.45f, -132.47f, 370.02f);
	cube[546].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[546].scale = D3DXVECTOR3(3, 1, 7);

	cube[547].position = D3DXVECTOR3(-45.75f, -131.26f, 368.78f);
	cube[547].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[547].scale = D3DXVECTOR3(3, 1, 10);

	cube[548].position = D3DXVECTOR3(-44.42f, -131.38f, 368.73f);
	cube[548].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[548].scale = D3DXVECTOR3(5, 1, 7);

	cube[549].position = D3DXVECTOR3(-36.60f, -134.13f, 368.55f);
	cube[549].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[549].scale = D3DXVECTOR3(3, 1, 10);

	cube[550].position = D3DXVECTOR3(-36.62f, -132.98f, 367.21f);
	cube[550].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[550].scale = D3DXVECTOR3(3, 1, 10);

	cube[551].position = D3DXVECTOR3(-27.54f, -135.82f, 367.65f);
	cube[551].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[551].scale = D3DXVECTOR3(3, 1, 10);

	cube[552].position = D3DXVECTOR3(-27.33f, -134.67f, 366.33f);
	cube[552].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[552].scale = D3DXVECTOR3(3, 1, 10);

	cube[553].position = D3DXVECTOR3(-18.72f, -137.48f, 368.27f);
	cube[553].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[553].scale = D3DXVECTOR3(3, 1, 10);

	cube[554].position = D3DXVECTOR3(-18.29f, -136.33f, 367.00f);
	cube[554].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[554].scale = D3DXVECTOR3(3, 1, 10);

	cube[555].position = D3DXVECTOR3(-10.58f, -139.08f, 370.31f);
	cube[555].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[555].scale = D3DXVECTOR3(3, 1, 10);

	cube[556].position = D3DXVECTOR3(-9.93f, -137.93f, 369.14f);
	cube[556].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[556].scale = D3DXVECTOR3(3, 1, 10);

	cube[557].position = D3DXVECTOR3(-2.51f, -140.73f, 373.88f);
	cube[557].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[557].scale = D3DXVECTOR3(3, 1, 10);

	cube[558].position = D3DXVECTOR3(-1.67f, -139.58f, 372.84f);
	cube[558].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[558].scale = D3DXVECTOR3(3, 1, 10);

	cube[559].position = D3DXVECTOR3(5.81f, -142.47f, 378.67f);
	cube[559].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[559].scale = D3DXVECTOR3(3, 1, 10);

	cube[560].position = D3DXVECTOR3(6.65f, -141.32f, 377.63f);
	cube[560].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[560].scale = D3DXVECTOR3(3, 1, 10);

	cube[561].position = D3DXVECTOR3(13.84f, -144.16f, 383.32f);
	cube[561].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[561].scale = D3DXVECTOR3(3, 1, 10);

	cube[562].position = D3DXVECTOR3(14.68f, -143.01f, 382.28f);
	cube[562].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[562].scale = D3DXVECTOR3(3, 1, 10);

	cube[563].position = D3DXVECTOR3(22.10f, -145.88f, 388.08f);
	cube[563].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[563].scale = D3DXVECTOR3(3, 1, 10);

	cube[564].position = D3DXVECTOR3(22.94f, -144.73f, 387.04f);
	cube[564].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[564].scale = D3DXVECTOR3(3, 1, 10);

	cube[565].position = D3DXVECTOR3(30.22f, -147.58f, 392.75f);
	cube[565].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[565].scale = D3DXVECTOR3(3, 1, 10);

	cube[566].position = D3DXVECTOR3(31.06f, -146.43f, 391.71f);
	cube[566].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[566].scale = D3DXVECTOR3(3, 1, 10);

	cube[567].position = D3DXVECTOR3(38.32f, -149.25f, 397.41f);
	cube[567].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[567].scale = D3DXVECTOR3(3, 1, 10);

	cube[568].position = D3DXVECTOR3(39.16f, -148.10f, 396.37f);
	cube[568].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[568].scale = D3DXVECTOR3(3, 1, 10);

	cube[569].position = D3DXVECTOR3(46.62f, -150.95f, 402.19f);
	cube[569].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[569].scale = D3DXVECTOR3(3, 1, 10);

	cube[570].position = D3DXVECTOR3(47.46f, -149.80f, 401.15f);
	cube[570].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[570].scale = D3DXVECTOR3(3, 1, 10);

	cube[571].position = D3DXVECTOR3(54.19f, -152.52f, 406.50f);
	cube[571].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[571].scale = D3DXVECTOR3(3, 1, 10);

	cube[572].position = D3DXVECTOR3(55.03f, -151.37f, 405.47f);
	cube[572].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[572].scale = D3DXVECTOR3(3, 1, 10);

	cube[573].position = D3DXVECTOR3(62.52f, -154.28f, 411.30f);
	cube[573].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[573].scale = D3DXVECTOR3(3, 1, 10);

	cube[574].position = D3DXVECTOR3(63.36f, -153.13f, 410.26f);
	cube[574].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[574].scale = D3DXVECTOR3(3, 1, 10);

	cube[575].position = D3DXVECTOR3(70.55f, -155.97f, 415.95f);
	cube[575].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[575].scale = D3DXVECTOR3(3, 1, 10);

	cube[576].position = D3DXVECTOR3(71.39f, -154.82f, 414.91f);
	cube[576].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[576].scale = D3DXVECTOR3(3, 1, 10);

	cube[577].position = D3DXVECTOR3(78.81f, -157.69f, 420.71f);
	cube[577].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[577].scale = D3DXVECTOR3(3, 1, 10);

	cube[578].position = D3DXVECTOR3(79.65f, -156.54f, 419.67f);
	cube[578].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[578].scale = D3DXVECTOR3(3, 1, 10);

	cube[579].position = D3DXVECTOR3(86.93f, -159.39f, 425.38f);
	cube[579].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[579].scale = D3DXVECTOR3(3, 1, 10);

	cube[580].position = D3DXVECTOR3(87.77f, -158.24f, 424.34f);
	cube[580].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[580].scale = D3DXVECTOR3(3, 1, 10);

	cube[581].position = D3DXVECTOR3(95.03f, -161.06f, 430.04f);
	cube[581].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[581].scale = D3DXVECTOR3(3, 1, 10);

	cube[582].position = D3DXVECTOR3(95.87f, -159.91f, 429.00f);
	cube[582].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[582].scale = D3DXVECTOR3(3, 1, 10);

	cube[583].position = D3DXVECTOR3(103.33f, -162.76f, 434.82f);
	cube[583].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[583].scale = D3DXVECTOR3(3, 1, 10);

	cube[584].position = D3DXVECTOR3(104.17f, -161.61f, 433.78f);
	cube[584].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[584].scale = D3DXVECTOR3(3, 1, 10);

	cube[585].position = D3DXVECTOR3(110.90f, -164.33f, 439.14f);
	cube[585].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[585].scale = D3DXVECTOR3(3, 1, 10);

	cube[586].position = D3DXVECTOR3(111.75f, -163.18f, 438.10f);
	cube[586].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[586].scale = D3DXVECTOR3(3, 1, 10);

	cube[587].position = D3DXVECTOR3(117.78f, -165.91f, 443.82f);
	cube[587].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[587].scale = D3DXVECTOR3(3, 1, 10);

	cube[588].position = D3DXVECTOR3(118.79f, -164.76f, 442.95f);
	cube[588].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[588].scale = D3DXVECTOR3(3, 1, 10);

	cube[589].position = D3DXVECTOR3(124.14f, -167.57f, 449.97f);
	cube[589].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[589].scale = D3DXVECTOR3(3, 1, 10);

	cube[590].position = D3DXVECTOR3(125.29f, -166.42f, 449.28f);
	cube[590].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[590].scale = D3DXVECTOR3(3, 1, 10);

	cube[591].position = D3DXVECTOR3(129.07f, -169.17f, 456.77f);
	cube[591].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[591].scale = D3DXVECTOR3(3, 1, 10);

	cube[592].position = D3DXVECTOR3(130.32f, -168.02f, 456.29f);
	cube[592].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[592].scale = D3DXVECTOR3(3, 1, 10);

	cube[593].position = D3DXVECTOR3(132.95f, -170.82f, 464.69f);
	cube[593].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[593].scale = D3DXVECTOR3(3, 1, 10);

	cube[594].position = D3DXVECTOR3(134.26f, -169.67f, 464.43f);
	cube[594].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[594].scale = D3DXVECTOR3(3, 1, 10);

	cube[595].position = D3DXVECTOR3(136.18f, -172.51f, 473.54f);
	cube[595].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[595].scale = D3DXVECTOR3(3, 1, 10);

	cube[596].position = D3DXVECTOR3(137.49f, -171.36f, 473.28f);
	cube[596].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[596].scale = D3DXVECTOR3(3, 1, 10);

	cube[597].position = D3DXVECTOR3(139.26f, -174.17f, 482.01f);
	cube[597].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[597].scale = D3DXVECTOR3(3, 1, 10);

	cube[598].position = D3DXVECTOR3(140.57f, -173.02f, 481.75f);
	cube[598].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[598].scale = D3DXVECTOR3(3, 1, 10);

	cube[599].position = D3DXVECTOR3(142.38f, -175.82f, 490.46f);
	cube[599].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[599].scale = D3DXVECTOR3(3, 1, 10);

	cube[600].position = D3DXVECTOR3(143.69f, -174.67f, 490.20f);
	cube[600].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[600].scale = D3DXVECTOR3(3, 1, 10);

	cube[601].position = D3DXVECTOR3(144.84f, -177.51f, 499.22f);
	cube[601].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[601].scale = D3DXVECTOR3(3, 1, 10);

	cube[602].position = D3DXVECTOR3(146.18f, -176.36f, 499.19f);
	cube[602].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[602].scale = D3DXVECTOR3(3, 1, 10);

	cube[603].position = D3DXVECTOR3(145.76f, -179.17f, 508.01f);
	cube[603].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[603].scale = D3DXVECTOR3(3, 1, 10);

	cube[604].position = D3DXVECTOR3(147.08f, -178.02f, 508.22f);
	cube[604].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[604].scale = D3DXVECTOR3(3, 1, 10);

	cube[605].position = D3DXVECTOR3(145.17f, -180.77f, 516.39f);
	cube[605].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[605].scale = D3DXVECTOR3(3, 1, 10);

	cube[606].position = D3DXVECTOR3(146.43f, -179.62f, 516.82f);
	cube[606].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[606].scale = D3DXVECTOR3(3, 1, 10);

	cube[607].position = D3DXVECTOR3(143.05f, -182.42f, 524.95f);
	cube[607].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[607].scale = D3DXVECTOR3(3, 1, 10);

	cube[608].position = D3DXVECTOR3(144.22f, -181.27f, 525.60f);
	cube[608].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[608].scale = D3DXVECTOR3(3, 1, 10);

	cube[609].position = D3DXVECTOR3(139.73f, -184.15f, 534.02f);
	cube[609].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[609].scale = D3DXVECTOR3(3, 1, 10);

	cube[610].position = D3DXVECTOR3(140.90f, -183.00f, 534.67f);
	cube[610].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[610].scale = D3DXVECTOR3(3, 1, 10);

	cube[611].position = D3DXVECTOR3(136.60f, -185.81f, 542.54f);
	cube[611].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[611].scale = D3DXVECTOR3(3, 1, 10);

	cube[612].position = D3DXVECTOR3(137.77f, -184.66f, 543.19f);
	cube[612].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[612].scale = D3DXVECTOR3(3, 1, 10);

	cube[613].position = D3DXVECTOR3(134.71f, -187.42f, 549.03f);
	cube[613].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[613].scale = D3DXVECTOR3(3, 1, 10);

	cube[614].position = D3DXVECTOR3(134.26f, -187.52f, 549.84f);
	cube[614].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[614].scale = D3DXVECTOR3(3, 1, 7);

	cube[615].position = D3DXVECTOR3(135.97f, -186.27f, 549.47f);
	cube[615].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[615].scale = D3DXVECTOR3(3, 1, 10);

	cube[616].position = D3DXVECTOR3(135.69f, -186.28f, 550.60f);
	cube[616].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[616].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[617].position = D3DXVECTOR3(134.01f, -189.01f, 555.40f);
	cube[617].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[617].scale = D3DXVECTOR3(3, 1, 10);

	cube[618].position = D3DXVECTOR3(133.82f, -189.10f, 556.71f);
	cube[618].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[618].scale = D3DXVECTOR3(3, 1, 7);

	cube[619].position = D3DXVECTOR3(135.33f, -187.86f, 555.61f);
	cube[619].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[619].scale = D3DXVECTOR3(3, 1, 10);

	cube[620].position = D3DXVECTOR3(135.11f, -188.01f, 557.22f);
	cube[620].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[620].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[621].position = D3DXVECTOR3(134.45f, -190.64f, 562.10f);
	cube[621].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[621].scale = D3DXVECTOR3(3, 1, 10);

	cube[622].position = D3DXVECTOR3(134.55f, -190.69f, 563.39f);
	cube[622].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[622].scale = D3DXVECTOR3(3, 1, 7);

	cube[623].position = D3DXVECTOR3(135.79f, -189.49f, 562.08f);
	cube[623].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[623].scale = D3DXVECTOR3(3, 1, 10);

	cube[624].position = D3DXVECTOR3(135.83f, -189.60f, 563.41f);
	cube[624].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[624].scale = D3DXVECTOR3(5, 1, 7);

	cube[625].position = D3DXVECTOR3(136.03f, -192.27f, 568.58f);
	cube[625].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[625].scale = D3DXVECTOR3(3, 1, 10);

	cube[626].position = D3DXVECTOR3(136.35f, -192.33f, 569.82f);
	cube[626].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[626].scale = D3DXVECTOR3(3, 1, 7);

	cube[627].position = D3DXVECTOR3(137.34f, -191.12f, 568.33f);
	cube[627].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[627].scale = D3DXVECTOR3(3, 1, 10);

	cube[628].position = D3DXVECTOR3(137.62f, -191.24f, 569.63f);
	cube[628].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[628].scale = D3DXVECTOR3(5, 1, 7);

	cube[629].position = D3DXVECTOR3(139.16f, -193.94f, 577.22f);
	cube[629].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[629].scale = D3DXVECTOR3(3, 1, 10);

	cube[630].position = D3DXVECTOR3(140.47f, -192.79f, 576.96f);
	cube[630].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[630].scale = D3DXVECTOR3(3, 1, 10);

	cube[631].position = D3DXVECTOR3(141.62f, -195.63f, 585.98f);
	cube[631].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[631].scale = D3DXVECTOR3(3, 1, 10);

	cube[632].position = D3DXVECTOR3(142.96f, -194.48f, 585.95f);
	cube[632].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[632].scale = D3DXVECTOR3(3, 1, 10);

	cube[633].position = D3DXVECTOR3(142.54f, -197.29f, 594.77f);
	cube[633].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[633].scale = D3DXVECTOR3(3, 1, 10);

	cube[634].position = D3DXVECTOR3(143.86f, -196.14f, 594.98f);
	cube[634].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[634].scale = D3DXVECTOR3(3, 1, 10);

	cube[635].position = D3DXVECTOR3(141.95f, -198.89f, 603.15f);
	cube[635].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[635].scale = D3DXVECTOR3(3, 1, 10);

	cube[636].position = D3DXVECTOR3(143.21f, -197.74f, 603.58f);
	cube[636].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[636].scale = D3DXVECTOR3(3, 1, 10);

	cube[637].position = D3DXVECTOR3(139.83f, -200.54f, 611.71f);
	cube[637].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[637].scale = D3DXVECTOR3(3, 1, 10);

	cube[638].position = D3DXVECTOR3(141.00f, -199.39f, 612.36f);
	cube[638].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[638].scale = D3DXVECTOR3(3, 1, 10);

	cube[639].position = D3DXVECTOR3(136.60f, -202.24f, 620.60f);
	cube[639].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[639].scale = D3DXVECTOR3(3, 1, 10);

	cube[640].position = D3DXVECTOR3(137.77f, -201.09f, 621.25f);
	cube[640].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[640].scale = D3DXVECTOR3(3, 1, 10);

	cube[641].position = D3DXVECTOR3(133.35f, -203.96f, 629.55f);
	cube[641].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[641].scale = D3DXVECTOR3(3, 1, 10);

	cube[642].position = D3DXVECTOR3(134.52f, -202.81f, 630.20f);
	cube[642].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[642].scale = D3DXVECTOR3(3, 1, 10);

	cube[643].position = D3DXVECTOR3(130.22f, -205.61f, 638.11f);
	cube[643].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[643].scale = D3DXVECTOR3(3, 1, 10);

	cube[644].position = D3DXVECTOR3(131.39f, -204.46f, 638.76f);
	cube[644].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[644].scale = D3DXVECTOR3(3, 1, 10);

	cube[645].position = D3DXVECTOR3(128.33f, -207.22f, 644.60f);
	cube[645].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[645].scale = D3DXVECTOR3(3, 1, 10);

	cube[646].position = D3DXVECTOR3(127.88f, -207.32f, 645.41f);
	cube[646].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[646].scale = D3DXVECTOR3(3, 1, 7);

	cube[647].position = D3DXVECTOR3(129.59f, -206.07f, 645.04f);
	cube[647].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[647].scale = D3DXVECTOR3(3, 1, 10);

	cube[648].position = D3DXVECTOR3(129.31f, -206.08f, 646.17f);
	cube[648].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[648].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[649].position = D3DXVECTOR3(127.63f, -208.81f, 650.97f);
	cube[649].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[649].scale = D3DXVECTOR3(3, 1, 10);

	cube[650].position = D3DXVECTOR3(127.44f, -208.90f, 652.28f);
	cube[650].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[650].scale = D3DXVECTOR3(3, 1, 7);

	cube[651].position = D3DXVECTOR3(128.95f, -207.66f, 651.18f);
	cube[651].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[651].scale = D3DXVECTOR3(3, 1, 10);

	cube[652].position = D3DXVECTOR3(128.73f, -207.81f, 652.79f);
	cube[652].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 0.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[652].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[653].position = D3DXVECTOR3(128.07f, -210.44f, 657.67f);
	cube[653].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[653].scale = D3DXVECTOR3(3, 1, 10);

	cube[654].position = D3DXVECTOR3(128.17f, -210.49f, 658.96f);
	cube[654].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[654].scale = D3DXVECTOR3(3, 1, 7);

	cube[655].position = D3DXVECTOR3(129.41f, -209.29f, 657.65f);
	cube[655].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[655].scale = D3DXVECTOR3(3, 1, 10);

	cube[656].position = D3DXVECTOR3(129.45f, -209.40f, 658.98f);
	cube[656].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 10.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[656].scale = D3DXVECTOR3(5, 1, 7);

	cube[657].position = D3DXVECTOR3(129.65f, -212.07f, 664.15f);
	cube[657].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[657].scale = D3DXVECTOR3(3, 1, 10);

	cube[658].position = D3DXVECTOR3(129.97f, -212.13f, 665.39f);
	cube[658].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[658].scale = D3DXVECTOR3(3, 1, 7);

	cube[659].position = D3DXVECTOR3(130.96f, -210.92f, 663.90f);
	cube[659].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[659].scale = D3DXVECTOR3(3, 1, 10);

	cube[660].position = D3DXVECTOR3(131.24f, -211.04f, 665.20f);
	cube[660].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[660].scale = D3DXVECTOR3(5, 1, 7);

	cube[661].position = D3DXVECTOR3(132.89f, -213.81f, 673.15f);
	cube[661].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[661].scale = D3DXVECTOR3(3, 1, 10);

	cube[662].position = D3DXVECTOR3(134.20f, -212.66f, 672.89f);
	cube[662].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[662].scale = D3DXVECTOR3(3, 1, 10);

	cube[663].position = D3DXVECTOR3(136.17f, -215.54f, 682.15f);
	cube[663].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[663].scale = D3DXVECTOR3(3, 1, 10);

	cube[664].position = D3DXVECTOR3(137.48f, -214.39f, 681.89f);
	cube[664].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[664].scale = D3DXVECTOR3(3, 1, 10);

	cube[665].position = D3DXVECTOR3(139.39f, -217.23f, 690.99f);
	cube[665].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[665].scale = D3DXVECTOR3(3, 1, 10);

	cube[666].position = D3DXVECTOR3(140.70f, -216.08f, 690.73f);
	cube[666].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[666].scale = D3DXVECTOR3(3, 1, 10);

	cube[667].position = D3DXVECTOR3(142.56f, -218.91f, 699.72f);
	cube[667].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[667].scale = D3DXVECTOR3(3, 1, 10);

	cube[668].position = D3DXVECTOR3(143.87f, -217.76f, 699.46f);
	cube[668].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[668].scale = D3DXVECTOR3(3, 1, 10);

	cube[669].position = D3DXVECTOR3(145.72f, -220.59f, 708.39f);
	cube[669].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[669].scale = D3DXVECTOR3(3, 1, 10);

	cube[670].position = D3DXVECTOR3(147.03f, -219.44f, 708.13f);
	cube[670].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[670].scale = D3DXVECTOR3(3, 1, 10);

	cube[671].position = D3DXVECTOR3(148.96f, -222.33f, 717.32f);
	cube[671].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[671].scale = D3DXVECTOR3(3, 1, 10);

	cube[672].position = D3DXVECTOR3(150.27f, -221.18f, 717.06f);
	cube[672].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[672].scale = D3DXVECTOR3(3, 1, 10);

	cube[673].position = D3DXVECTOR3(152.19f, -224.03f, 726.20f);
	cube[673].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[673].scale = D3DXVECTOR3(3, 1, 10);

	cube[674].position = D3DXVECTOR3(153.50f, -222.88f, 725.94f);
	cube[674].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[674].scale = D3DXVECTOR3(3, 1, 10);

	cube[675].position = D3DXVECTOR3(155.36f, -225.73f, 734.99f);
	cube[675].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[675].scale = D3DXVECTOR3(3, 1, 10);

	cube[676].position = D3DXVECTOR3(156.67f, -224.58f, 734.74f);
	cube[676].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[676].scale = D3DXVECTOR3(3, 1, 10);

	cube[677].position = D3DXVECTOR3(158.30f, -227.25f, 743.02f);
	cube[677].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[677].scale = D3DXVECTOR3(3, 1, 10);

	cube[678].position = D3DXVECTOR3(159.61f, -226.10f, 742.77f);
	cube[678].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[678].scale = D3DXVECTOR3(3, 1, 10);

	cube[679].position = D3DXVECTOR3(161.58f, -228.98f, 752.02f);
	cube[679].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[679].scale = D3DXVECTOR3(3, 1, 10);

	cube[680].position = D3DXVECTOR3(162.89f, -227.83f, 751.77f);
	cube[680].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[680].scale = D3DXVECTOR3(3, 1, 10);

	cube[681].position = D3DXVECTOR3(164.80f, -230.67f, 760.86f);
	cube[681].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[681].scale = D3DXVECTOR3(3, 1, 10);

	cube[682].position = D3DXVECTOR3(166.11f, -229.52f, 760.61f);
	cube[682].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[682].scale = D3DXVECTOR3(3, 1, 10);

	cube[683].position = D3DXVECTOR3(167.97f, -232.35f, 769.59f);
	cube[683].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[683].scale = D3DXVECTOR3(3, 1, 10);

	cube[684].position = D3DXVECTOR3(169.28f, -231.20f, 769.34f);
	cube[684].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[684].scale = D3DXVECTOR3(3, 1, 10);

	cube[685].position = D3DXVECTOR3(171.13f, -234.03f, 778.26f);
	cube[685].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[685].scale = D3DXVECTOR3(3, 1, 10);

	cube[686].position = D3DXVECTOR3(172.44f, -232.88f, 778.01f);
	cube[686].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[686].scale = D3DXVECTOR3(3, 1, 10);

	cube[687].position = D3DXVECTOR3(174.37f, -235.77f, 787.19f);
	cube[687].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[687].scale = D3DXVECTOR3(3, 1, 10);

	cube[688].position = D3DXVECTOR3(175.68f, -234.62f, 786.94f);
	cube[688].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[688].scale = D3DXVECTOR3(3, 1, 10);

	cube[689].position = D3DXVECTOR3(177.60f, -237.47f, 796.07f);
	cube[689].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[689].scale = D3DXVECTOR3(3, 1, 10);

	cube[690].position = D3DXVECTOR3(178.91f, -236.32f, 795.82f);
	cube[690].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[690].scale = D3DXVECTOR3(3, 1, 10);

	cube[691].position = D3DXVECTOR3(180.77f, -239.17f, 804.87f);
	cube[691].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[691].scale = D3DXVECTOR3(3, 1, 10);

	cube[692].position = D3DXVECTOR3(182.08f, -238.02f, 804.62f);
	cube[692].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[692].scale = D3DXVECTOR3(3, 1, 10);

	cube[693].position = D3DXVECTOR3(183.44f, -240.76f, 810.81f);
	cube[693].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[693].scale = D3DXVECTOR3(3, 1, 10);

	cube[694].position = D3DXVECTOR3(183.61f, -240.86f, 811.72f);
	cube[694].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[694].scale = D3DXVECTOR3(3, 1, 7);

	cube[695].position = D3DXVECTOR3(184.69f, -239.61f, 810.34f);
	cube[695].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[695].scale = D3DXVECTOR3(3, 1, 10);

	cube[696].position = D3DXVECTOR3(185.20f, -239.62f, 811.39f);
	cube[696].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[696].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[697].position = D3DXVECTOR3(187.00f, -242.35f, 816.15f);
	cube[697].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[697].scale = D3DXVECTOR3(3, 1, 10);

	cube[698].position = D3DXVECTOR3(187.70f, -242.44f, 817.27f);
	cube[698].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[698].scale = D3DXVECTOR3(3, 1, 7);

	cube[699].position = D3DXVECTOR3(188.14f, -241.20f, 815.46f);
	cube[699].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[699].scale = D3DXVECTOR3(3, 1, 10);

	cube[700].position = D3DXVECTOR3(189.01f, -241.35f, 816.84f);
	cube[700].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[700].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[701].position = D3DXVECTOR3(191.64f, -243.98f, 820.99f);
	cube[701].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[701].scale = D3DXVECTOR3(3, 1, 10);

	cube[702].position = D3DXVECTOR3(192.55f, -244.03f, 821.92f);
	cube[702].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[702].scale = D3DXVECTOR3(3, 1, 7);

	cube[703].position = D3DXVECTOR3(192.65f, -242.83f, 820.12f);
	cube[703].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[703].scale = D3DXVECTOR3(3, 1, 10);

	cube[704].position = D3DXVECTOR3(193.54f, -242.94f, 821.11f);
	cube[704].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[704].scale = D3DXVECTOR3(5, 1, 7);

	cube[705].position = D3DXVECTOR3(197.02f, -245.61f, 824.94f);
	cube[705].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[705].scale = D3DXVECTOR3(3, 1, 10);

	cube[706].position = D3DXVECTOR3(198.05f, -245.67f, 825.69f);
	cube[706].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[706].scale = D3DXVECTOR3(3, 1, 7);

	cube[707].position = D3DXVECTOR3(197.86f, -244.46f, 823.90f);
	cube[707].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[707].scale = D3DXVECTOR3(3, 1, 10);

	cube[708].position = D3DXVECTOR3(198.90f, -244.58f, 824.73f);
	cube[708].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[708].scale = D3DXVECTOR3(5, 1, 7);

	cube[709].position = D3DXVECTOR3(202.95f, -247.21f, 827.88f);
	cube[709].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[709].scale = D3DXVECTOR3(3, 1, 10);

	cube[710].position = D3DXVECTOR3(203.99f, -247.26f, 828.39f);
	cube[710].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[710].scale = D3DXVECTOR3(3, 1, 7);

	cube[711].position = D3DXVECTOR3(203.60f, -246.06f, 826.71f);
	cube[711].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[711].scale = D3DXVECTOR3(3, 1, 10);

	cube[712].position = D3DXVECTOR3(204.67f, -246.16f, 827.31f);
	cube[712].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[712].scale = D3DXVECTOR3(5, 1, 7);

	cube[713].position = D3DXVECTOR3(209.38f, -248.85f, 829.75f);
	cube[713].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[713].scale = D3DXVECTOR3(3, 1, 10);

	cube[714].position = D3DXVECTOR3(210.35f, -248.86f, 830.05f);
	cube[714].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[714].scale = D3DXVECTOR3(3, 1, 7);

	cube[715].position = D3DXVECTOR3(209.81f, -247.70f, 828.49f);
	cube[715].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[715].scale = D3DXVECTOR3(3, 1, 10);

	cube[716].position = D3DXVECTOR3(211.05f, -247.79f, 828.90f);
	cube[716].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[716].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[717].position = D3DXVECTOR3(215.82f, -250.51f, 830.40f);
	cube[717].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[717].scale = D3DXVECTOR3(3, 1, 10);

	cube[718].position = D3DXVECTOR3(217.07f, -250.52f, 830.55f);
	cube[718].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[718].scale = D3DXVECTOR3(3, 1, 7);

	cube[719].position = D3DXVECTOR3(216.03f, -249.36f, 829.08f);
	cube[719].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[719].scale = D3DXVECTOR3(3, 1, 10);

	cube[720].position = D3DXVECTOR3(217.57f, -249.49f, 829.30f);
	cube[720].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[720].scale = D3DXVECTOR3(5, 1, 6.500004);

	cube[721].position = D3DXVECTOR3(222.02f, -252.05f, 830.00f);
	cube[721].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[721].scale = D3DXVECTOR3(3, 1, 10);

	cube[722].position = D3DXVECTOR3(223.26f, -252.09f, 829.93f);
	cube[722].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[722].scale = D3DXVECTOR3(3, 1, 7);

	cube[723].position = D3DXVECTOR3(222.00f, -250.90f, 828.66f);
	cube[723].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[723].scale = D3DXVECTOR3(3, 1, 10);

	cube[724].position = D3DXVECTOR3(223.52f, -251.04f, 828.60f);
	cube[724].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[724].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[725].position = D3DXVECTOR3(231.22f, -253.71f, 828.38f);
	cube[725].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[725].scale = D3DXVECTOR3(3, 1, 10);

	cube[726].position = D3DXVECTOR3(231.19f, -252.56f, 827.04f);
	cube[726].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[726].scale = D3DXVECTOR3(3, 1, 10);

	cube[727].position = D3DXVECTOR3(240.55f, -255.40f, 826.74f);
	cube[727].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[727].scale = D3DXVECTOR3(3, 1, 10);

	cube[728].position = D3DXVECTOR3(240.52f, -254.25f, 825.40f);
	cube[728].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[728].scale = D3DXVECTOR3(3, 1, 10);

	cube[729].position = D3DXVECTOR3(249.45f, -257.03f, 825.19f);
	cube[729].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[729].scale = D3DXVECTOR3(3, 1, 10);

	cube[730].position = D3DXVECTOR3(249.43f, -255.88f, 823.86f);
	cube[730].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[730].scale = D3DXVECTOR3(3, 1, 10);

	cube[731].position = D3DXVECTOR3(258.51f, -258.72f, 824.30f);
	cube[731].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[731].scale = D3DXVECTOR3(3, 1, 10);

	cube[732].position = D3DXVECTOR3(258.72f, -257.57f, 822.98f);
	cube[732].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[732].scale = D3DXVECTOR3(3, 1, 10);

	cube[733].position = D3DXVECTOR3(267.33f, -260.38f, 824.92f);
	cube[733].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[733].scale = D3DXVECTOR3(3, 1, 10);

	cube[734].position = D3DXVECTOR3(267.76f, -259.23f, 823.65f);
	cube[734].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[734].scale = D3DXVECTOR3(3, 1, 10);

	cube[735].position = D3DXVECTOR3(275.47f, -261.98f, 826.95f);
	cube[735].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[735].scale = D3DXVECTOR3(3, 1, 10);

	cube[736].position = D3DXVECTOR3(276.12f, -260.83f, 825.79f);
	cube[736].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[736].scale = D3DXVECTOR3(3, 1, 10);

	cube[737].position = D3DXVECTOR3(283.54f, -263.63f, 830.53f);
	cube[737].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[737].scale = D3DXVECTOR3(3, 1, 10);

	cube[738].position = D3DXVECTOR3(284.38f, -262.48f, 829.49f);
	cube[738].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[738].scale = D3DXVECTOR3(3, 1, 10);

	cube[739].position = D3DXVECTOR3(290.96f, -265.34f, 835.62f);
	cube[739].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[739].scale = D3DXVECTOR3(3, 1, 10);

	cube[740].position = D3DXVECTOR3(291.97f, -264.19f, 834.74f);
	cube[740].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[740].scale = D3DXVECTOR3(3, 1, 10);

	cube[741].position = D3DXVECTOR3(297.20f, -266.97f, 841.65f);
	cube[741].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[741].scale = D3DXVECTOR3(3, 1, 10);

	cube[742].position = D3DXVECTOR3(298.35f, -265.82f, 840.96f);
	cube[742].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[742].scale = D3DXVECTOR3(3, 1, 10);

	cube[743].position = D3DXVECTOR3(302.41f, -268.60f, 848.85f);
	cube[743].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[743].scale = D3DXVECTOR3(3, 1, 10);

	cube[744].position = D3DXVECTOR3(303.65f, -267.45f, 848.37f);
	cube[744].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[744].scale = D3DXVECTOR3(3, 1, 10);

	cube[745].position = D3DXVECTOR3(306.16f, -270.16f, 856.53f);
	cube[745].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[745].scale = D3DXVECTOR3(3, 1, 10);

	cube[746].position = D3DXVECTOR3(307.47f, -269.01f, 856.27f);
	cube[746].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[746].scale = D3DXVECTOR3(3, 1, 10);

	cube[747].position = D3DXVECTOR3(309.34f, -271.82f, 865.23f);
	cube[747].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[747].scale = D3DXVECTOR3(3, 1, 10);

	cube[748].position = D3DXVECTOR3(310.65f, -270.67f, 864.98f);
	cube[748].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[748].scale = D3DXVECTOR3(3, 1, 10);

	cube[749].position = D3DXVECTOR3(312.60f, -273.52f, 874.20f);
	cube[749].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[749].scale = D3DXVECTOR3(3, 1, 10);

	cube[750].position = D3DXVECTOR3(313.91f, -272.37f, 873.95f);
	cube[750].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[750].scale = D3DXVECTOR3(3, 1, 10);

	cube[751].position = D3DXVECTOR3(315.86f, -275.30f, 883.14f);
	cube[751].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[751].scale = D3DXVECTOR3(3, 1, 10);

	cube[752].position = D3DXVECTOR3(317.17f, -274.15f, 882.88f);
	cube[752].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[752].scale = D3DXVECTOR3(3, 1, 10);

	cube[753].position = D3DXVECTOR3(318.59f, -276.91f, 889.32f);
	cube[753].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[753].scale = D3DXVECTOR3(3, 1, 10);

	cube[754].position = D3DXVECTOR3(318.76f, -277.01f, 890.23f);
	cube[754].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 30.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[754].scale = D3DXVECTOR3(3, 1, 7);

	cube[755].position = D3DXVECTOR3(319.84f, -275.76f, 888.85f);
	cube[755].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[755].scale = D3DXVECTOR3(3, 1, 10);

	cube[756].position = D3DXVECTOR3(320.35f, -275.77f, 889.90f);
	cube[756].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[756].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[757].position = D3DXVECTOR3(322.15f, -278.50f, 894.66f);
	cube[757].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[757].scale = D3DXVECTOR3(3, 1, 10);

	cube[758].position = D3DXVECTOR3(322.85f, -278.59f, 895.78f);
	cube[758].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[758].scale = D3DXVECTOR3(3, 1, 7);

	cube[759].position = D3DXVECTOR3(323.29f, -277.35f, 893.97f);
	cube[759].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[759].scale = D3DXVECTOR3(3, 1, 10);

	cube[760].position = D3DXVECTOR3(324.16f, -277.50f, 895.35f);
	cube[760].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[760].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[761].position = D3DXVECTOR3(326.79f, -280.13f, 899.50f);
	cube[761].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[761].scale = D3DXVECTOR3(3, 1, 10);

	cube[762].position = D3DXVECTOR3(327.70f, -280.18f, 900.43f);
	cube[762].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[762].scale = D3DXVECTOR3(3, 1, 7);

	cube[763].position = D3DXVECTOR3(327.80f, -278.98f, 898.63f);
	cube[763].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[763].scale = D3DXVECTOR3(3, 1, 10);

	cube[764].position = D3DXVECTOR3(328.69f, -279.09f, 899.62f);
	cube[764].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[764].scale = D3DXVECTOR3(5, 1, 7);

	cube[765].position = D3DXVECTOR3(332.17f, -281.76f, 903.45f);
	cube[765].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[765].scale = D3DXVECTOR3(3, 1, 10);

	cube[766].position = D3DXVECTOR3(333.20f, -281.82f, 904.20f);
	cube[766].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[766].scale = D3DXVECTOR3(3, 1, 7);

	cube[767].position = D3DXVECTOR3(333.01f, -280.61f, 902.41f);
	cube[767].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[767].scale = D3DXVECTOR3(3, 1, 10);

	cube[768].position = D3DXVECTOR3(334.05f, -280.73f, 903.24f);
	cube[768].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[768].scale = D3DXVECTOR3(5, 1, 7);

	cube[769].position = D3DXVECTOR3(338.10f, -283.36f, 906.39f);
	cube[769].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[769].scale = D3DXVECTOR3(3, 1, 10);

	cube[770].position = D3DXVECTOR3(339.14f, -283.41f, 906.90f);
	cube[770].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 70.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[770].scale = D3DXVECTOR3(3, 1, 7);

	cube[771].position = D3DXVECTOR3(338.75f, -282.21f, 905.22f);
	cube[771].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[771].scale = D3DXVECTOR3(3, 1, 10);

	cube[772].position = D3DXVECTOR3(339.82f, -282.31f, 905.82f);
	cube[772].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[772].scale = D3DXVECTOR3(5, 1, 7);

	cube[773].position = D3DXVECTOR3(344.53f, -285.00f, 908.26f);
	cube[773].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[773].scale = D3DXVECTOR3(3, 1, 10);

	cube[774].position = D3DXVECTOR3(345.50f, -285.01f, 908.56f);
	cube[774].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[774].scale = D3DXVECTOR3(3, 1, 7);

	cube[775].position = D3DXVECTOR3(344.96f, -283.85f, 907.00f);
	cube[775].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[775].scale = D3DXVECTOR3(3, 1, 10);

	cube[776].position = D3DXVECTOR3(346.20f, -283.94f, 907.41f);
	cube[776].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[776].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[777].position = D3DXVECTOR3(350.97f, -286.66f, 908.91f);
	cube[777].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[777].scale = D3DXVECTOR3(3, 1, 10);

	cube[778].position = D3DXVECTOR3(352.22f, -286.67f, 909.06f);
	cube[778].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[778].scale = D3DXVECTOR3(3, 1, 7);

	cube[779].position = D3DXVECTOR3(351.18f, -285.51f, 907.59f);
	cube[779].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[779].scale = D3DXVECTOR3(3, 1, 10);

	cube[780].position = D3DXVECTOR3(352.72f, -285.64f, 907.81f);
	cube[780].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[780].scale = D3DXVECTOR3(5, 1, 6.500004);

	cube[781].position = D3DXVECTOR3(357.17f, -288.20f, 908.51f);
	cube[781].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[781].scale = D3DXVECTOR3(3, 1, 10);

	cube[782].position = D3DXVECTOR3(358.41f, -288.24f, 908.44f);
	cube[782].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[782].scale = D3DXVECTOR3(3, 1, 7);

	cube[783].position = D3DXVECTOR3(357.15f, -287.05f, 907.17f);
	cube[783].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[783].scale = D3DXVECTOR3(3, 1, 10);

	cube[784].position = D3DXVECTOR3(358.67f, -287.19f, 907.11f);
	cube[784].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[784].scale = D3DXVECTOR3(5, 1, 6.500002);

	cube[785].position = D3DXVECTOR3(366.56f, -289.93f, 906.85f);
	cube[785].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[785].scale = D3DXVECTOR3(3, 1, 10);

	cube[786].position = D3DXVECTOR3(366.54f, -288.78f, 905.52f);
	cube[786].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[786].scale = D3DXVECTOR3(3, 1, 10);

	cube[787].position = D3DXVECTOR3(373.13f, -291.54f, 905.24f);
	cube[787].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[787].scale = D3DXVECTOR3(3, 1, 10);

	cube[788].position = D3DXVECTOR3(374.05f, -291.64f, 905.23f);
	cube[788].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[788].scale = D3DXVECTOR3(3, 1, 7);

	cube[789].position = D3DXVECTOR3(372.87f, -290.39f, 903.93f);
	cube[789].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[789].scale = D3DXVECTOR3(3, 1, 10);

	cube[790].position = D3DXVECTOR3(374.00f, -290.40f, 903.61f);
	cube[790].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[790].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[791].position = D3DXVECTOR3(379.00f, -293.13f, 902.66f);
	cube[791].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[791].scale = D3DXVECTOR3(3, 1, 10);

	cube[792].position = D3DXVECTOR3(380.22f, -293.22f, 902.17f);
	cube[792].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[792].scale = D3DXVECTOR3(3, 1, 7);

	cube[793].position = D3DXVECTOR3(378.52f, -291.98f, 901.41f);
	cube[793].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[793].scale = D3DXVECTOR3(3, 1, 10);

	cube[794].position = D3DXVECTOR3(380.02f, -292.13f, 900.80f);
	cube[794].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[794].scale = D3DXVECTOR3(5, 1, 6.5);

	cube[795].position = D3DXVECTOR3(384.58f, -294.76f, 898.93f);
	cube[795].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[795].scale = D3DXVECTOR3(3, 1, 10);

	cube[796].position = D3DXVECTOR3(385.65f, -294.81f, 898.20f);
	cube[796].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[796].scale = D3DXVECTOR3(3, 1, 7);

	cube[797].position = D3DXVECTOR3(383.89f, -293.61f, 897.78f);
	cube[797].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[797].scale = D3DXVECTOR3(3, 1, 10);

	cube[798].position = D3DXVECTOR3(385.02f, -293.72f, 897.08f);
	cube[798].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[798].scale = D3DXVECTOR3(5, 1, 7);

	cube[799].position = D3DXVECTOR3(389.40f, -296.39f, 894.32f);
	cube[799].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[799].scale = D3DXVECTOR3(3, 1, 10);

	cube[800].position = D3DXVECTOR3(390.31f, -296.45f, 893.43f);
	cube[800].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[800].scale = D3DXVECTOR3(3, 1, 7);

	cube[801].position = D3DXVECTOR3(388.52f, -295.24f, 893.31f);
	cube[801].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[801].scale = D3DXVECTOR3(3, 1, 10);

	cube[802].position = D3DXVECTOR3(389.51f, -295.36f, 892.43f);
	cube[802].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[802].scale = D3DXVECTOR3(5, 1, 7);

	cube[803].position = D3DXVECTOR3(393.32f, -297.99f, 888.99f);
	cube[803].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[803].scale = D3DXVECTOR3(3, 1, 10);

	cube[804].position = D3DXVECTOR3(394.00f, -298.04f, 888.05f);
	cube[804].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[804].scale = D3DXVECTOR3(3, 1, 7);

	cube[805].position = D3DXVECTOR3(392.28f, -296.84f, 888.15f);
	cube[805].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[805].scale = D3DXVECTOR3(3, 1, 10);

	cube[806].position = D3DXVECTOR3(393.06f, -296.94f, 887.19f);
	cube[806].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[806].scale = D3DXVECTOR3(5, 1, 7);

	cube[807].position = D3DXVECTOR3(396.28f, -299.63f, 882.98f);
	cube[807].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[807].scale = D3DXVECTOR3(3, 1, 10);

	cube[808].position = D3DXVECTOR3(396.75f, -299.64f, 882.08f);
	cube[808].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[808].scale = D3DXVECTOR3(3, 1, 7);

	cube[809].position = D3DXVECTOR3(395.11f, -298.48f, 882.34f);
	cube[809].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[809].scale = D3DXVECTOR3(3, 1, 10);

	cube[810].position = D3DXVECTOR3(395.74f, -298.57f, 881.19f);
	cube[810].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[810].scale = D3DXVECTOR3(5, 1, 6.500005);

	cube[811].position = D3DXVECTOR3(398.03f, -301.29f, 876.75f);
	cube[811].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[811].scale = D3DXVECTOR3(3, 1, 9.99999);

	cube[812].position = D3DXVECTOR3(398.41f, -301.30f, 875.55f);
	cube[812].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[812].scale = D3DXVECTOR3(3, 1, 7);

	cube[813].position = D3DXVECTOR3(396.77f, -300.14f, 876.32f);
	cube[813].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[813].scale = D3DXVECTOR3(3, 1, 10);

	cube[814].position = D3DXVECTOR3(397.26f, -300.27f, 874.84f);
	cube[814].rotation = D3DXVECTOR3(16.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[814].scale = D3DXVECTOR3(5, 1, 6.500006);

	cube[815].position = D3DXVECTOR3(398.72f, -302.83f, 870.58f);
	cube[815].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[815].scale = D3DXVECTOR3(3, 1, 10);

	cube[816].position = D3DXVECTOR3(398.87f, -302.87f, 869.34f);
	cube[816].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[816].scale = D3DXVECTOR3(3, 1, 7);

	cube[817].position = D3DXVECTOR3(397.40f, -301.68f, 870.37f);
	cube[817].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[817].scale = D3DXVECTOR3(3, 1, 10);

	cube[818].position = D3DXVECTOR3(397.60f, -301.82f, 868.86f);
	cube[818].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[818].scale = D3DXVECTOR3(5, 1, 6.500001);

	cube[819].position = D3DXVECTOR3(398.69f, -304.55f, 861.16f);
	cube[819].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[819].scale = D3DXVECTOR3(3, 1, 10);

	cube[820].position = D3DXVECTOR3(397.37f, -303.40f, 860.95f);
	cube[820].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[820].scale = D3DXVECTOR3(3, 1, 10);

	cube[821].position = D3DXVECTOR3(398.69f, -306.30f, 851.62f);
	cube[821].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[821].scale = D3DXVECTOR3(3, 1, 10);

	cube[822].position = D3DXVECTOR3(397.37f, -305.15f, 851.41f);
	cube[822].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[822].scale = D3DXVECTOR3(3, 1, 10);

	cube[823].position = D3DXVECTOR3(398.69f, -308.00f, 842.23f);
	cube[823].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[823].scale = D3DXVECTOR3(3, 1, 10);

	cube[824].position = D3DXVECTOR3(397.37f, -306.85f, 842.02f);
	cube[824].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[824].scale = D3DXVECTOR3(3, 1, 10);

	cube[825].position = D3DXVECTOR3(398.69f, -309.65f, 833.07f);
	cube[825].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[825].scale = D3DXVECTOR3(3, 1, 10);

	cube[826].position = D3DXVECTOR3(397.37f, -308.50f, 832.86f);
	cube[826].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[826].scale = D3DXVECTOR3(3, 1, 10);

	cube[827].position = D3DXVECTOR3(398.69f, -311.39f, 823.49f);
	cube[827].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[827].scale = D3DXVECTOR3(3, 1, 10);

	cube[828].position = D3DXVECTOR3(397.37f, -310.24f, 823.28f);
	cube[828].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[828].scale = D3DXVECTOR3(3, 1, 10);

	cube[829].position = D3DXVECTOR3(398.69f, -312.97f, 814.76f);
	cube[829].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[829].scale = D3DXVECTOR3(3, 1, 10);

	cube[830].position = D3DXVECTOR3(397.37f, -311.82f, 814.55f);
	cube[830].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[830].scale = D3DXVECTOR3(3, 1, 10);

	cube[831].position = D3DXVECTOR3(398.64f, -314.58f, 805.80f);
	cube[831].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[831].scale = D3DXVECTOR3(3, 1, 10);

	cube[832].position = D3DXVECTOR3(397.32f, -313.43f, 805.59f);
	cube[832].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[832].scale = D3DXVECTOR3(3, 1, 10);

	cube[833].position = D3DXVECTOR3(398.64f, -316.33f, 796.26f);
	cube[833].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[833].scale = D3DXVECTOR3(3, 1, 10);

	cube[834].position = D3DXVECTOR3(397.32f, -315.18f, 796.05f);
	cube[834].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[834].scale = D3DXVECTOR3(3, 1, 10);

	cube[835].position = D3DXVECTOR3(398.64f, -318.03f, 786.87f);
	cube[835].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[835].scale = D3DXVECTOR3(3, 1, 10);

	cube[836].position = D3DXVECTOR3(397.32f, -316.88f, 786.66f);
	cube[836].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[836].scale = D3DXVECTOR3(3, 1, 10);

	cube[837].position = D3DXVECTOR3(398.64f, -319.68f, 777.71f);
	cube[837].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[837].scale = D3DXVECTOR3(3, 1, 10);

	cube[838].position = D3DXVECTOR3(397.32f, -318.53f, 777.50f);
	cube[838].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[838].scale = D3DXVECTOR3(3, 1, 10);

	cube[839].position = D3DXVECTOR3(398.64f, -321.42f, 768.13f);
	cube[839].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[839].scale = D3DXVECTOR3(3, 1, 10);

	cube[840].position = D3DXVECTOR3(397.32f, -320.27f, 767.92f);
	cube[840].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[840].scale = D3DXVECTOR3(3, 1, 10);

	cube[841].position = D3DXVECTOR3(398.64f, -323.01f, 759.41f);
	cube[841].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[841].scale = D3DXVECTOR3(3, 1, 10);

	cube[842].position = D3DXVECTOR3(397.32f, -321.86f, 759.19f);
	cube[842].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[842].scale = D3DXVECTOR3(3, 1, 10);

	cube[843].position = D3DXVECTOR3(398.21f, -324.69f, 752.82f);
	cube[843].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[843].scale = D3DXVECTOR3(3, 1, 10);

	cube[844].position = D3DXVECTOR3(398.36f, -324.79f, 751.91f);
	cube[844].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[844].scale = D3DXVECTOR3(3, 1, 7);

	cube[845].position = D3DXVECTOR3(396.88f, -323.54f, 752.85f);
	cube[845].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[845].scale = D3DXVECTOR3(3, 1, 10);

	cube[846].position = D3DXVECTOR3(396.76f, -323.55f, 751.68f);
	cube[846].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[846].scale = D3DXVECTOR3(5, 1, 6.499998);

	cube[847].position = D3DXVECTOR3(396.69f, -326.28f, 746.59f);
	cube[847].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[847].scale = D3DXVECTOR3(3, 1, 10);

	cube[848].position = D3DXVECTOR3(396.42f, -326.37f, 745.30f);
	cube[848].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[848].scale = D3DXVECTOR3(3, 1, 7);

	cube[849].position = D3DXVECTOR3(395.38f, -325.13f, 746.85f);
	cube[849].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[849].scale = D3DXVECTOR3(3, 1, 10);

	cube[850].position = D3DXVECTOR3(395.04f, -325.28f, 745.26f);
	cube[850].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[850].scale = D3DXVECTOR3(5, 1, 6.499999);

	cube[851].position = D3DXVECTOR3(393.99f, -327.91f, 740.45f);
	cube[851].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[851].scale = D3DXVECTOR3(3, 1, 10);

	cube[852].position = D3DXVECTOR3(393.45f, -327.96f, 739.27f);
	cube[852].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[852].scale = D3DXVECTOR3(3, 1, 7);

	cube[853].position = D3DXVECTOR3(392.74f, -326.76f, 740.93f);
	cube[853].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[853].scale = D3DXVECTOR3(3, 1, 10);

	cube[854].position = D3DXVECTOR3(392.24f, -326.87f, 739.69f);
	cube[854].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[854].scale = D3DXVECTOR3(5, 1, 7);

	cube[855].position = D3DXVECTOR3(390.29f, -329.54f, 734.90f);
	cube[855].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[855].scale = D3DXVECTOR3(3, 1, 10);

	cube[856].position = D3DXVECTOR3(389.57f, -329.60f, 733.85f);
	cube[856].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[856].scale = D3DXVECTOR3(3, 1, 7);

	cube[857].position = D3DXVECTOR3(389.14f, -328.39f, 735.59f);
	cube[857].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[857].scale = D3DXVECTOR3(3, 1, 10);

	cube[858].position = D3DXVECTOR3(388.44f, -328.51f, 734.46f);
	cube[858].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[858].scale = D3DXVECTOR3(5, 1, 7);

	cube[859].position = D3DXVECTOR3(384.33f, -331.22f, 727.80f);
	cube[859].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[859].scale = D3DXVECTOR3(3, 1, 10);

	cube[860].position = D3DXVECTOR3(383.18f, -330.07f, 728.49f);
	cube[860].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[860].scale = D3DXVECTOR3(3, 1, 10);

	cube[861].position = D3DXVECTOR3(379.02f, -332.91f, 720.41f);
	cube[861].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[861].scale = D3DXVECTOR3(3, 1, 10);

	cube[862].position = D3DXVECTOR3(377.77f, -331.76f, 720.89f);
	cube[862].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[862].scale = D3DXVECTOR3(3, 1, 10);

	cube[863].position = D3DXVECTOR3(375.15f, -334.57f, 712.46f);
	cube[863].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[863].scale = D3DXVECTOR3(3, 1, 10);

	cube[864].position = D3DXVECTOR3(373.84f, -333.42f, 712.71f);
	cube[864].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[864].scale = D3DXVECTOR3(3, 1, 10);

	cube[865].position = D3DXVECTOR3(372.84f, -336.17f, 704.39f);
	cube[865].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[865].scale = D3DXVECTOR3(3, 1, 10);

	cube[866].position = D3DXVECTOR3(371.51f, -335.02f, 704.41f);
	cube[866].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[866].scale = D3DXVECTOR3(3, 1, 10);

	cube[867].position = D3DXVECTOR3(371.91f, -337.82f, 695.62f);
	cube[867].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[867].scale = D3DXVECTOR3(3, 1, 10);

	cube[868].position = D3DXVECTOR3(370.59f, -336.67f, 695.41f);
	cube[868].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[868].scale = D3DXVECTOR3(3, 1, 10);

	cube[869].position = D3DXVECTOR3(371.90f, -339.48f, 686.29f);
	cube[869].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[869].scale = D3DXVECTOR3(3, 1, 10);

	cube[870].position = D3DXVECTOR3(370.58f, -338.33f, 686.08f);
	cube[870].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[870].scale = D3DXVECTOR3(3, 1, 10);

	cube[871].position = D3DXVECTOR3(371.90f, -341.17f, 676.84f);
	cube[871].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[871].scale = D3DXVECTOR3(3, 1, 10);

	cube[872].position = D3DXVECTOR3(370.58f, -340.02f, 676.63f);
	cube[872].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[872].scale = D3DXVECTOR3(3, 1, 10);

	cube[873].position = D3DXVECTOR3(371.91f, -342.72f, 668.40f);
	cube[873].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[873].scale = D3DXVECTOR3(3, 1, 10);

	cube[874].position = D3DXVECTOR3(370.59f, -341.57f, 668.19f);
	cube[874].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[874].scale = D3DXVECTOR3(3, 1, 10);

	cube[875].position = D3DXVECTOR3(372.60f, -344.41f, 659.33f);
	cube[875].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[875].scale = D3DXVECTOR3(3, 1, 10);

	cube[876].position = D3DXVECTOR3(371.33f, -343.26f, 658.89f);
	cube[876].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[876].scale = D3DXVECTOR3(3, 1, 10);

	cube[877].position = D3DXVECTOR3(374.74f, -346.07f, 650.75f);
	cube[877].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[877].scale = D3DXVECTOR3(3, 1, 10);

	cube[878].position = D3DXVECTOR3(373.57f, -344.92f, 650.10f);
	cube[878].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[878].scale = D3DXVECTOR3(3, 1, 10);

	cube[879].position = D3DXVECTOR3(378.16f, -347.67f, 643.08f);
	cube[879].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[879].scale = D3DXVECTOR3(3, 1, 10);

	cube[880].position = D3DXVECTOR3(377.12f, -346.52f, 642.24f);
	cube[880].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[880].scale = D3DXVECTOR3(3, 1, 10);

	cube[881].position = D3DXVECTOR3(383.08f, -349.32f, 635.76f);
	cube[881].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[881].scale = D3DXVECTOR3(3, 1, 10);

	cube[882].position = D3DXVECTOR3(382.20f, -348.17f, 634.75f);
	cube[882].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[882].scale = D3DXVECTOR3(3, 1, 10);

	cube[883].position = D3DXVECTOR3(389.23f, -351.04f, 628.42f);
	cube[883].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[883].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[884].position = D3DXVECTOR3(388.35f, -349.89f, 627.41f);
	cube[884].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[884].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[885].position = D3DXVECTOR3(395.28f, -352.74f, 621.21f);
	cube[885].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[885].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[886].position = D3DXVECTOR3(394.40f, -351.59f, 620.20f);
	cube[886].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[886].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[887].position = D3DXVECTOR3(401.40f, -354.47f, 613.91f);
	cube[887].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[887].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[888].position = D3DXVECTOR3(400.52f, -353.32f, 612.90f);
	cube[888].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[888].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[889].position = D3DXVECTOR3(407.51f, -356.22f, 606.68f);
	cube[889].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[889].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[890].position = D3DXVECTOR3(406.63f, -355.07f, 605.67f);
	cube[890].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[890].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[891].position = D3DXVECTOR3(413.87f, -357.91f, 600.17f);
	cube[891].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[891].scale = D3DXVECTOR3(3, 1, 10);

	cube[892].position = D3DXVECTOR3(413.18f, -356.76f, 599.02f);
	cube[892].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[892].scale = D3DXVECTOR3(3, 1, 10);

	cube[893].position = D3DXVECTOR3(421.02f, -359.57f, 594.97f);
	cube[893].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[893].scale = D3DXVECTOR3(3, 1, 10);

	cube[894].position = D3DXVECTOR3(420.54f, -358.42f, 593.72f);
	cube[894].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[894].scale = D3DXVECTOR3(3, 1, 10);

	cube[895].position = D3DXVECTOR3(428.57f, -361.17f, 591.30f);
	cube[895].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[895].scale = D3DXVECTOR3(3, 1, 10);

	cube[896].position = D3DXVECTOR3(428.32f, -360.02f, 589.99f);
	cube[896].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[896].scale = D3DXVECTOR3(3, 1, 10);

	cube[897].position = D3DXVECTOR3(437.05f, -362.82f, 588.85f);
	cube[897].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[897].scale = D3DXVECTOR3(3, 1, 10);

	cube[898].position = D3DXVECTOR3(437.02f, -361.67f, 587.52f);
	cube[898].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[898].scale = D3DXVECTOR3(3, 1, 10);

	cube[899].position = D3DXVECTOR3(446.01f, -364.53f, 587.98f);
	cube[899].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[899].scale = D3DXVECTOR3(3, 1, 10);

	cube[900].position = D3DXVECTOR3(446.22f, -363.38f, 586.66f);
	cube[900].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[900].scale = D3DXVECTOR3(3, 1, 10);

	cube[901].position = D3DXVECTOR3(454.66f, -366.16f, 588.59f);
	cube[901].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[901].scale = D3DXVECTOR3(3, 1, 10);

	cube[902].position = D3DXVECTOR3(455.10f, -365.01f, 587.32f);
	cube[902].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[902].scale = D3DXVECTOR3(3, 1, 10);

	cube[903].position = D3DXVECTOR3(463.78f, -367.86f, 590.17f);
	cube[903].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[903].scale = D3DXVECTOR3(3, 1, 10);

	cube[904].position = D3DXVECTOR3(464.22f, -366.71f, 588.90f);
	cube[904].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[904].scale = D3DXVECTOR3(3, 1, 10);

	cube[905].position = D3DXVECTOR3(473.33f, -369.62f, 591.85f);
	cube[905].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[905].scale = D3DXVECTOR3(3, 1, 10);

	cube[906].position = D3DXVECTOR3(473.77f, -368.47f, 590.58f);
	cube[906].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[906].scale = D3DXVECTOR3(3, 1, 10);

	cube[907].position = D3DXVECTOR3(482.71f, -371.34f, 593.51f);
	cube[907].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[907].scale = D3DXVECTOR3(3, 1, 10);

	cube[908].position = D3DXVECTOR3(483.15f, -370.19f, 592.24f);
	cube[908].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[908].scale = D3DXVECTOR3(3, 1, 10);

	cube[909].position = D3DXVECTOR3(490.45f, -372.75f, 594.89f);
	cube[909].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[909].scale = D3DXVECTOR3(3, 1, 10);

	cube[910].position = D3DXVECTOR3(490.89f, -371.60f, 593.62f);
	cube[910].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[910].scale = D3DXVECTOR3(3, 1, 10);

	cube[911].position = D3DXVECTOR3(499.85f, -374.46f, 596.56f);
	cube[911].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[911].scale = D3DXVECTOR3(3, 1, 10);

	cube[912].position = D3DXVECTOR3(500.29f, -373.31f, 595.29f);
	cube[912].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[912].scale = D3DXVECTOR3(3, 1, 10);

	cube[913].position = D3DXVECTOR3(509.40f, -376.20f, 598.23f);
	cube[913].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[913].scale = D3DXVECTOR3(3, 1, 10);

	cube[914].position = D3DXVECTOR3(509.84f, -375.05f, 596.96f);
	cube[914].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[914].scale = D3DXVECTOR3(3, 1, 10);

	cube[915].position = D3DXVECTOR3(518.69f, -377.88f, 599.87f);
	cube[915].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[915].scale = D3DXVECTOR3(3, 1, 10);

	cube[916].position = D3DXVECTOR3(519.13f, -376.73f, 598.60f);
	cube[916].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[916].scale = D3DXVECTOR3(3, 1, 10);

	cube[917].position = D3DXVECTOR3(528.10f, -379.59f, 601.53f);
	cube[917].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[917].scale = D3DXVECTOR3(3, 1, 10);

	cube[918].position = D3DXVECTOR3(528.54f, -378.44f, 600.26f);
	cube[918].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[918].scale = D3DXVECTOR3(3, 1, 10);

	cube[919].position = D3DXVECTOR3(537.49f, -381.30f, 603.19f);
	cube[919].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[919].scale = D3DXVECTOR3(3, 1, 10);

	cube[920].position = D3DXVECTOR3(537.93f, -380.15f, 601.92f);
	cube[920].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[920].scale = D3DXVECTOR3(3, 1, 10);

	cube[921].position = D3DXVECTOR3(546.85f, -383.00f, 604.84f);
	cube[921].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[921].scale = D3DXVECTOR3(3, 1, 10);

	cube[922].position = D3DXVECTOR3(547.29f, -381.85f, 603.57f);
	cube[922].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[922].scale = D3DXVECTOR3(3, 1, 10);

	cube[923].position = D3DXVECTOR3(555.95f, -384.71f, 606.46f);
	cube[923].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[923].scale = D3DXVECTOR3(3, 1, 10);

	cube[924].position = D3DXVECTOR3(556.39f, -383.56f, 605.19f);
	cube[924].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[924].scale = D3DXVECTOR3(3, 1, 10);

	cube[925].position = D3DXVECTOR3(565.50f, -386.47f, 608.14f);
	cube[925].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[925].scale = D3DXVECTOR3(3, 1, 10);

	cube[926].position = D3DXVECTOR3(565.94f, -385.32f, 606.87f);
	cube[926].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[926].scale = D3DXVECTOR3(3, 1, 10);

	cube[927].position = D3DXVECTOR3(574.88f, -388.19f, 609.80f);
	cube[927].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[927].scale = D3DXVECTOR3(3, 1, 10);

	cube[928].position = D3DXVECTOR3(575.32f, -387.04f, 608.53f);
	cube[928].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[928].scale = D3DXVECTOR3(3, 1, 10);

	cube[929].position = D3DXVECTOR3(582.62f, -389.59f, 611.18f);
	cube[929].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[929].scale = D3DXVECTOR3(3, 1, 10);

	cube[930].position = D3DXVECTOR3(583.06f, -388.44f, 609.92f);
	cube[930].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[930].scale = D3DXVECTOR3(3, 1, 10);

	cube[931].position = D3DXVECTOR3(592.02f, -391.30f, 612.85f);
	cube[931].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[931].scale = D3DXVECTOR3(3, 1, 10);

	cube[932].position = D3DXVECTOR3(592.46f, -390.15f, 611.59f);
	cube[932].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[932].scale = D3DXVECTOR3(3, 1, 10);

	cube[933].position = D3DXVECTOR3(601.57f, -393.04f, 614.52f);
	cube[933].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[933].scale = D3DXVECTOR3(3, 1, 10);

	cube[934].position = D3DXVECTOR3(602.01f, -391.89f, 613.26f);
	cube[934].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[934].scale = D3DXVECTOR3(3, 1, 10);

	cube[935].position = D3DXVECTOR3(610.86f, -394.72f, 616.16f);
	cube[935].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[935].scale = D3DXVECTOR3(3, 1, 10);

	cube[936].position = D3DXVECTOR3(611.30f, -393.57f, 614.90f);
	cube[936].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[936].scale = D3DXVECTOR3(3, 1, 10);

	cube[937].position = D3DXVECTOR3(620.27f, -396.43f, 617.82f);
	cube[937].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[937].scale = D3DXVECTOR3(3, 1, 10);

	cube[938].position = D3DXVECTOR3(620.71f, -395.28f, 616.56f);
	cube[938].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[938].scale = D3DXVECTOR3(3, 1, 10);

	cube[939].position = D3DXVECTOR3(629.66f, -398.14f, 619.48f);
	cube[939].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[939].scale = D3DXVECTOR3(3, 1, 10);

	cube[940].position = D3DXVECTOR3(630.10f, -396.99f, 618.22f);
	cube[940].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[940].scale = D3DXVECTOR3(3, 1, 10);

	cube[941].position = D3DXVECTOR3(639.02f, -399.84f, 621.13f);
	cube[941].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);
	cube[941].scale = D3DXVECTOR3(3, 1, 10);

	cube[942].position = D3DXVECTOR3(639.46f, -398.69f, 619.87f);
	cube[942].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	cube[942].scale = D3DXVECTOR3(3, 1, 10);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cube[943].position = D3DXVECTOR3(-6.27f, -10.24f, 2.16f);
	cube[943].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[943].scale = D3DXVECTOR3(3, 1, 10);

	cube[944].position = D3DXVECTOR3(-7.52f, -9.08f, 2.37f);
	cube[944].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[944].scale = D3DXVECTOR3(3, 1, 10);

	cube[945].position = D3DXVECTOR3(-6.27f, -11.90f, 11.16f);
	cube[945].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[945].scale = D3DXVECTOR3(3, 1, 10);

	cube[946].position = D3DXVECTOR3(-7.52f, -10.74f, 11.37f);
	cube[946].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[946].scale = D3DXVECTOR3(3, 1, 10);

	cube[947].position = D3DXVECTOR3(-6.27f, -13.49f, 19.86f);
	cube[947].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[947].scale = D3DXVECTOR3(3, 1, 10);

	cube[948].position = D3DXVECTOR3(-7.52f, -12.33f, 20.07f);
	cube[948].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[948].scale = D3DXVECTOR3(3, 1, 10);

	cube[949].position = D3DXVECTOR3(-6.27f, -15.17f, 28.96f);
	cube[949].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[949].scale = D3DXVECTOR3(3, 1, 10);

	cube[950].position = D3DXVECTOR3(-7.52f, -14.01f, 29.17f);
	cube[950].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[950].scale = D3DXVECTOR3(3, 1, 10);

	cube[951].position = D3DXVECTOR3(-6.27f, -16.96f, 38.36f);
	cube[951].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[951].scale = D3DXVECTOR3(3, 1, 10);

	cube[952].position = D3DXVECTOR3(-7.52f, -15.80f, 38.57f);
	cube[952].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[952].scale = D3DXVECTOR3(3, 1, 10);

	cube[953].position = D3DXVECTOR3(-6.27f, -18.64f, 47.66f);
	cube[953].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[953].scale = D3DXVECTOR3(3, 1, 10);

	cube[954].position = D3DXVECTOR3(-7.52f, -17.48f, 47.87f);
	cube[954].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[954].scale = D3DXVECTOR3(3, 1, 10);

	cube[955].position = D3DXVECTOR3(-6.27f, -20.43f, 57.36f);
	cube[955].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[955].scale = D3DXVECTOR3(3, 1, 10);

	cube[956].position = D3DXVECTOR3(-7.52f, -19.27f, 57.57f);
	cube[956].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[956].scale = D3DXVECTOR3(3, 1, 10);

	cube[957].position = D3DXVECTOR3(-6.27f, -22.02f, 66.16f);
	cube[957].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[957].scale = D3DXVECTOR3(3, 1, 10);

	cube[958].position = D3DXVECTOR3(-7.52f, -20.86f, 66.37f);
	cube[958].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[958].scale = D3DXVECTOR3(3, 1, 10);

	cube[959].position = D3DXVECTOR3(-6.27f, -23.39f, 73.77f);
	cube[959].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[959].scale = D3DXVECTOR3(3, 1, 10);

	cube[960].position = D3DXVECTOR3(-7.52f, -22.23f, 73.98f);
	cube[960].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[960].scale = D3DXVECTOR3(3, 1, 10);

	cube[961].position = D3DXVECTOR3(-6.27f, -25.09f, 83.25f);
	cube[961].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[961].scale = D3DXVECTOR3(3, 1, 10);

	cube[962].position = D3DXVECTOR3(-7.52f, -23.93f, 83.46f);
	cube[962].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[962].scale = D3DXVECTOR3(3, 1, 10);

	cube[963].position = D3DXVECTOR3(-6.27f, -26.75f, 92.25f);
	cube[963].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[963].scale = D3DXVECTOR3(3, 1, 10);

	cube[964].position = D3DXVECTOR3(-7.52f, -25.59f, 92.46f);
	cube[964].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[964].scale = D3DXVECTOR3(3, 1, 10);

	cube[965].position = D3DXVECTOR3(-6.27f, -28.34f, 100.95f);
	cube[965].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[965].scale = D3DXVECTOR3(3, 1, 10);

	cube[966].position = D3DXVECTOR3(-7.52f, -27.18f, 101.16f);
	cube[966].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[966].scale = D3DXVECTOR3(3, 1, 10);

	cube[967].position = D3DXVECTOR3(-6.27f, -30.02f, 110.05f);
	cube[967].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[967].scale = D3DXVECTOR3(3, 1, 10);

	cube[968].position = D3DXVECTOR3(-7.52f, -28.86f, 110.26f);
	cube[968].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[968].scale = D3DXVECTOR3(3, 1, 10);

	cube[969].position = D3DXVECTOR3(-6.27f, -31.81f, 119.45f);
	cube[969].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[969].scale = D3DXVECTOR3(3, 1, 10);

	cube[970].position = D3DXVECTOR3(-7.52f, -30.65f, 119.66f);
	cube[970].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[970].scale = D3DXVECTOR3(3, 1, 10);

	cube[971].position = D3DXVECTOR3(-6.27f, -33.49f, 128.75f);
	cube[971].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[971].scale = D3DXVECTOR3(3, 1, 10);

	cube[972].position = D3DXVECTOR3(-7.52f, -32.33f, 128.96f);
	cube[972].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[972].scale = D3DXVECTOR3(3, 1, 10);

	cube[973].position = D3DXVECTOR3(-6.27f, -35.28f, 138.45f);
	cube[973].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[973].scale = D3DXVECTOR3(3, 1, 10);

	cube[974].position = D3DXVECTOR3(-7.52f, -34.12f, 138.66f);
	cube[974].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[974].scale = D3DXVECTOR3(3, 1, 10);

	cube[975].position = D3DXVECTOR3(-6.27f, -36.87f, 147.25f);
	cube[975].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[975].scale = D3DXVECTOR3(3, 1, 10);

	cube[976].position = D3DXVECTOR3(-7.52f, -35.71f, 147.46f);
	cube[976].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[976].scale = D3DXVECTOR3(3, 1, 10);

	cube[977].position = D3DXVECTOR3(-6.27f, -38.24f, 154.87f);
	cube[977].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[977].scale = D3DXVECTOR3(3, 1, 10);

	cube[978].position = D3DXVECTOR3(-7.52f, -37.08f, 155.08f);
	cube[978].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[978].scale = D3DXVECTOR3(3, 1, 10);

	cube[979].position = D3DXVECTOR3(-6.65f, -39.93f, 161.60f);
	cube[979].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[979].scale = D3DXVECTOR3(3, 1, 10);

	cube[980].position = D3DXVECTOR3(-6.40f, -40.11f, 162.59f);
	cube[980].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[980].scale = D3DXVECTOR3(3, 1, 7);

	cube[981].position = D3DXVECTOR3(-7.92f, -38.77f, 161.59f);
	cube[981].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[981].scale = D3DXVECTOR3(3, 1, 10);

	cube[982].position = D3DXVECTOR3(-7.94f, -38.80f, 162.62f);
	cube[982].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[982].scale = D3DXVECTOR3(5, 1, 7);

	cube[983].position = D3DXVECTOR3(-8.25f, -41.59f, 168.17f);
	cube[983].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[983].scale = D3DXVECTOR3(3, 1, 10);

	cube[984].position = D3DXVECTOR3(-8.11f, -41.95f, 169.56f);
	cube[984].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[984].scale = D3DXVECTOR3(3, 1, 7);

	cube[985].position = D3DXVECTOR3(-9.50f, -40.43f, 167.94f);
	cube[985].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[985].scale = D3DXVECTOR3(3, 1, 10);

	cube[986].position = D3DXVECTOR3(-9.99f, -40.35f, 169.25f);
	cube[986].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[986].scale = D3DXVECTOR3(5, 1, 7);

	cube[987].position = D3DXVECTOR3(-10.79f, -43.19f, 173.94f);
	cube[987].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[987].scale = D3DXVECTOR3(3, 1, 10);

	cube[988].position = D3DXVECTOR3(-10.94f, -43.45f, 175.35f);
	cube[988].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[988].scale = D3DXVECTOR3(3, 1, 7);

	cube[989].position = D3DXVECTOR3(-11.98f, -42.03f, 173.50f);
	cube[989].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[989].scale = D3DXVECTOR3(3, 1, 10);

	cube[990].position = D3DXVECTOR3(-12.49f, -42.13f, 174.82f);
	cube[990].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[990].scale = D3DXVECTOR3(5, 1, 7);

	cube[991].position = D3DXVECTOR3(-14.52f, -44.84f, 179.55f);
	cube[991].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[991].scale = D3DXVECTOR3(3, 1, 10);

	cube[992].position = D3DXVECTOR3(-14.79f, -45.17f, 180.86f);
	cube[992].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[992].scale = D3DXVECTOR3(3, 1, 7);

	cube[993].position = D3DXVECTOR3(-15.61f, -43.68f, 178.91f);
	cube[993].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[993].scale = D3DXVECTOR3(3, 1, 10);

	cube[994].position = D3DXVECTOR3(-16.29f, -43.79f, 180.06f);
	cube[994].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[994].scale = D3DXVECTOR3(5, 1, 7);

	cube[995].position = D3DXVECTOR3(-19.34f, -46.55f, 184.51f);
	cube[995].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[995].scale = D3DXVECTOR3(3, 1, 10);

	cube[996].position = D3DXVECTOR3(-19.88f, -46.78f, 185.63f);
	cube[996].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[996].scale = D3DXVECTOR3(3, 1, 7);

	cube[997].position = D3DXVECTOR3(-20.31f, -45.39f, 183.68f);
	cube[997].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[997].scale = D3DXVECTOR3(3, 1, 10);

	cube[998].position = D3DXVECTOR3(-21.11f, -45.48f, 184.65f);
	cube[998].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[998].scale = D3DXVECTOR3(5, 1, 7);

	cube[999].position = D3DXVECTOR3(-24.66f, -48.18f, 188.41f);
	cube[999].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[999].scale = D3DXVECTOR3(3, 1, 10);

	cube[1000].position = D3DXVECTOR3(-25.37f, -48.51f, 189.56f);
	cube[1000].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1000].scale = D3DXVECTOR3(3, 1, 7);

	cube[1001].position = D3DXVECTOR3(-25.46f, -47.02f, 187.43f);
	cube[1001].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1001].scale = D3DXVECTOR3(3, 1, 10);

	cube[1002].position = D3DXVECTOR3(-26.49f, -47.13f, 188.26f);
	cube[1002].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1002].scale = D3DXVECTOR3(5, 1, 7);

	cube[1003].position = D3DXVECTOR3(-32.13f, -49.77f, 192.78f);
	cube[1003].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1003].scale = D3DXVECTOR3(3, 1, 10);

	cube[1004].position = D3DXVECTOR3(-32.94f, -48.61f, 191.81f);
	cube[1004].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1004].scale = D3DXVECTOR3(3, 1, 10);

	cube[1005].position = D3DXVECTOR3(-40.09f, -51.50f, 197.39f);
	cube[1005].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1005].scale = D3DXVECTOR3(3, 1, 10);

	cube[1006].position = D3DXVECTOR3(-40.90f, -50.34f, 196.42f);
	cube[1006].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1006].scale = D3DXVECTOR3(3, 1, 10);

	cube[1007].position = D3DXVECTOR3(-47.39f, -53.05f, 201.59f);
	cube[1007].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1007].scale = D3DXVECTOR3(3, 1, 10);

	cube[1008].position = D3DXVECTOR3(-48.20f, -51.89f, 200.62f);
	cube[1008].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1008].scale = D3DXVECTOR3(3, 1, 10);

	cube[1009].position = D3DXVECTOR3(-54.69f, -54.57f, 205.79f);
	cube[1009].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1009].scale = D3DXVECTOR3(3, 1, 10);

	cube[1010].position = D3DXVECTOR3(-55.50f, -53.41f, 204.82f);
	cube[1010].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1010].scale = D3DXVECTOR3(3, 1, 10);

	cube[1011].position = D3DXVECTOR3(-62.59f, -56.30f, 210.39f);
	cube[1011].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1011].scale = D3DXVECTOR3(3, 1, 10);

	cube[1012].position = D3DXVECTOR3(-63.40f, -55.14f, 209.42f);
	cube[1012].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1012].scale = D3DXVECTOR3(3, 1, 10);

	cube[1013].position = D3DXVECTOR3(-70.45f, -57.94f, 214.86f);
	cube[1013].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1013].scale = D3DXVECTOR3(3, 1, 10);

	cube[1014].position = D3DXVECTOR3(-71.26f, -56.78f, 213.88f);
	cube[1014].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1014].scale = D3DXVECTOR3(3, 1, 10);

	cube[1015].position = D3DXVECTOR3(-78.02f, -59.51f, 219.22f);
	cube[1015].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1015].scale = D3DXVECTOR3(3, 1, 10);

	cube[1016].position = D3DXVECTOR3(-78.83f, -58.35f, 218.24f);
	cube[1016].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1016].scale = D3DXVECTOR3(3, 1, 10);

	cube[1017].position = D3DXVECTOR3(-85.98f, -61.24f, 223.83f);
	cube[1017].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1017].scale = D3DXVECTOR3(3, 1, 10);

	cube[1018].position = D3DXVECTOR3(-86.79f, -60.08f, 222.85f);
	cube[1018].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1018].scale = D3DXVECTOR3(3, 1, 10);

	cube[1019].position = D3DXVECTOR3(-93.28f, -62.79f, 228.03f);
	cube[1019].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1019].scale = D3DXVECTOR3(3, 1, 10);

	cube[1020].position = D3DXVECTOR3(-94.09f, -61.63f, 227.05f);
	cube[1020].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1020].scale = D3DXVECTOR3(3, 1, 10);

	cube[1021].position = D3DXVECTOR3(-100.58f, -64.31f, 232.23f);
	cube[1021].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1021].scale = D3DXVECTOR3(3, 1, 10);

	cube[1022].position = D3DXVECTOR3(-101.39f, -63.15f, 231.25f);
	cube[1022].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1022].scale = D3DXVECTOR3(3, 1, 10);

	cube[1023].position = D3DXVECTOR3(-108.48f, -66.04f, 236.83f);
	cube[1023].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1023].scale = D3DXVECTOR3(3, 1, 10);

	cube[1024].position = D3DXVECTOR3(-109.29f, -64.88f, 235.85f);
	cube[1024].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1024].scale = D3DXVECTOR3(3, 1, 10);

	cube[1025].position = D3DXVECTOR3(-116.34f, -67.68f, 241.30f);
	cube[1025].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1025].scale = D3DXVECTOR3(3, 1, 10);

	cube[1026].position = D3DXVECTOR3(-117.15f, -66.52f, 240.32f);
	cube[1026].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1026].scale = D3DXVECTOR3(3, 1, 10);

	cube[1027].position = D3DXVECTOR3(-122.48f, -69.38f, 244.32f);
	cube[1027].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1027].scale = D3DXVECTOR3(3, 1, 10);

	cube[1028].position = D3DXVECTOR3(-123.22f, -69.56f, 245.02f);
	cube[1028].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1028].scale = D3DXVECTOR3(3, 1, 7);

	cube[1029].position = D3DXVECTOR3(-123.11f, -68.22f, 243.21f);
	cube[1029].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1029].scale = D3DXVECTOR3(3, 1, 10);

	cube[1030].position = D3DXVECTOR3(-124.01f, -68.25f, 243.70f);
	cube[1030].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1030].scale = D3DXVECTOR3(5, 1, 7);

	cube[1031].position = D3DXVECTOR3(-128.97f, -71.04f, 246.21f);
	cube[1031].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1031].scale = D3DXVECTOR3(3, 1, 10);

	cube[1032].position = D3DXVECTOR3(-130.11f, -71.40f, 247.03f);
	cube[1032].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1032].scale = D3DXVECTOR3(3, 1, 7);

	cube[1033].position = D3DXVECTOR3(-129.39f, -69.88f, 245.02f);
	cube[1033].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1033].scale = D3DXVECTOR3(3, 1, 10);

	cube[1034].position = D3DXVECTOR3(-130.78f, -69.80f, 245.24f);
	cube[1034].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1034].scale = D3DXVECTOR3(5, 1, 7);

	cube[1035].position = D3DXVECTOR3(-135.24f, -72.64f, 246.90f);
	cube[1035].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1035].scale = D3DXVECTOR3(3, 1, 10);

	cube[1036].position = D3DXVECTOR3(-136.54f, -72.90f, 247.47f);
	cube[1036].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1036].scale = D3DXVECTOR3(3, 1, 7);

	cube[1037].position = D3DXVECTOR3(-135.45f, -71.48f, 245.65f);
	cube[1037].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1037].scale = D3DXVECTOR3(3, 1, 10);

	cube[1038].position = D3DXVECTOR3(-136.85f, -71.58f, 245.86f);
	cube[1038].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1038].scale = D3DXVECTOR3(5, 1, 7);

	cube[1039].position = D3DXVECTOR3(-141.96f, -74.29f, 246.48f);
	cube[1039].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1039].scale = D3DXVECTOR3(3, 1, 10);

	cube[1040].position = D3DXVECTOR3(-143.23f, -74.62f, 246.89f);
	cube[1040].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1040].scale = D3DXVECTOR3(3, 1, 7);

	cube[1041].position = D3DXVECTOR3(-141.95f, -73.13f, 245.21f);
	cube[1041].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1041].scale = D3DXVECTOR3(3, 1, 10);

	cube[1042].position = D3DXVECTOR3(-143.29f, -73.24f, 245.19f);
	cube[1042].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1042].scale = D3DXVECTOR3(5, 1, 7);

	cube[1043].position = D3DXVECTOR3(-148.62f, -75.59f, 245.29f);
	cube[1043].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1043].scale = D3DXVECTOR3(3, 1, 10);

	cube[1044].position = D3DXVECTOR3(-148.61f, -74.43f, 244.03f);
	cube[1044].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (260.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1044].scale = D3DXVECTOR3(3, 1, 10);

	cube[1045].position = D3DXVECTOR3(-157.42f, -77.20f, 244.38f);
	cube[1045].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1045].scale = D3DXVECTOR3(3, 1, 10);

	cube[1046].position = D3DXVECTOR3(-157.63f, -76.04f, 243.13f);
	cube[1046].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (270.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1046].scale = D3DXVECTOR3(3, 1, 10);

	cube[1047].position = D3DXVECTOR3(-165.90f, -78.79f, 244.98f);
	cube[1047].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1047].scale = D3DXVECTOR3(3, 1, 10);

	cube[1048].position = D3DXVECTOR3(-166.33f, -77.63f, 243.78f);
	cube[1048].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (280.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1048].scale = D3DXVECTOR3(3, 1, 10);

	cube[1049].position = D3DXVECTOR3(-174.44f, -80.42f, 247.12f);
	cube[1049].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1049].scale = D3DXVECTOR3(3, 1, 10);

	cube[1050].position = D3DXVECTOR3(-175.06f, -79.26f, 246.01f);
	cube[1050].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (290.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1050].scale = D3DXVECTOR3(3, 1, 10);

	cube[1051].position = D3DXVECTOR3(-182.43f, -82.05f, 250.68f);
	cube[1051].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1051].scale = D3DXVECTOR3(3, 1, 10);

	cube[1052].position = D3DXVECTOR3(-183.24f, -80.89f, 249.70f);
	cube[1052].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (300.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1052].scale = D3DXVECTOR3(3, 1, 10);

	cube[1053].position = D3DXVECTOR3(-189.65f, -83.65f, 255.55f);
	cube[1053].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1053].scale = D3DXVECTOR3(3, 1, 10);

	cube[1054].position = D3DXVECTOR3(-190.62f, -82.49f, 254.72f);
	cube[1054].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (310.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1054].scale = D3DXVECTOR3(3, 1, 10);

	cube[1055].position = D3DXVECTOR3(-195.96f, -85.29f, 261.65f);
	cube[1055].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1055].scale = D3DXVECTOR3(3, 1, 10);

	cube[1056].position = D3DXVECTOR3(-197.06f, -84.13f, 261.01f);
	cube[1056].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (320.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1056].scale = D3DXVECTOR3(3, 1, 10);

	cube[1057].position = D3DXVECTOR3(-200.94f, -86.95f, 268.62f);
	cube[1057].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1057].scale = D3DXVECTOR3(3, 1, 10);

	cube[1058].position = D3DXVECTOR3(-202.13f, -85.79f, 268.17f);
	cube[1058].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (330.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1058].scale = D3DXVECTOR3(3, 1, 10);

	cube[1059].position = D3DXVECTOR3(-204.58f, -88.49f, 276.07f);
	cube[1059].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1059].scale = D3DXVECTOR3(3, 1, 10);

	cube[1060].position = D3DXVECTOR3(-205.82f, -87.33f, 275.84f);
	cube[1060].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1060].scale = D3DXVECTOR3(3, 1, 10);

	cube[1061].position = D3DXVECTOR3(-207.05f, -89.85f, 282.77f);
	cube[1061].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1061].scale = D3DXVECTOR3(3, 1, 10);

	cube[1062].position = D3DXVECTOR3(-208.30f, -88.69f, 282.54f);
	cube[1062].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1062].scale = D3DXVECTOR3(3, 1, 10);

	cube[1063].position = D3DXVECTOR3(-209.48f, -91.46f, 291.28f);
	cube[1063].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1063].scale = D3DXVECTOR3(3, 1, 10);

	cube[1064].position = D3DXVECTOR3(-210.75f, -90.30f, 291.27f);
	cube[1064].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1064].scale = D3DXVECTOR3(3, 1, 10);

	cube[1065].position = D3DXVECTOR3(-210.36f, -93.05f, 299.73f);
	cube[1065].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1065].scale = D3DXVECTOR3(3, 1, 10);

	cube[1066].position = D3DXVECTOR3(-211.61f, -91.89f, 299.94f);
	cube[1066].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1066].scale = D3DXVECTOR3(3, 1, 10);

	cube[1067].position = D3DXVECTOR3(-209.74f, -94.68f, 308.51f);
	cube[1067].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1067].scale = D3DXVECTOR3(3, 1, 10);

	cube[1068].position = D3DXVECTOR3(-210.93f, -93.52f, 308.93f);
	cube[1068].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1068].scale = D3DXVECTOR3(3, 1, 10);

	cube[1069].position = D3DXVECTOR3(-207.62f, -96.31f, 317.00f);
	cube[1069].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1069].scale = D3DXVECTOR3(3, 1, 10);

	cube[1070].position = D3DXVECTOR3(-208.72f, -95.15f, 317.63f);
	cube[1070].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1070].scale = D3DXVECTOR3(3, 1, 10);

	cube[1071].position = D3DXVECTOR3(-204.08f, -97.91f, 324.96f);
	cube[1071].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1071].scale = D3DXVECTOR3(3, 1, 10);

	cube[1072].position = D3DXVECTOR3(-205.06f, -96.75f, 325.76f);
	cube[1072].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1072].scale = D3DXVECTOR3(3, 1, 10);

	cube[1073].position = D3DXVECTOR3(-199.16f, -99.55f, 332.23f);
	cube[1073].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1073].scale = D3DXVECTOR3(3, 1, 10);

	cube[1074].position = D3DXVECTOR3(-199.99f, -98.39f, 333.20f);
	cube[1074].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1074].scale = D3DXVECTOR3(3, 1, 10);

	cube[1075].position = D3DXVECTOR3(-193.17f, -101.21f, 338.34f);
	cube[1075].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1075].scale = D3DXVECTOR3(3, 1, 10);

	cube[1076].position = D3DXVECTOR3(-193.81f, -100.05f, 339.43f);
	cube[1076].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1076].scale = D3DXVECTOR3(3, 1, 10);

	cube[1077].position = D3DXVECTOR3(-186.45f, -102.75f, 343.22f);
	cube[1077].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1077].scale = D3DXVECTOR3(3, 1, 10);

	cube[1078].position = D3DXVECTOR3(-186.90f, -101.59f, 344.41f);
	cube[1078].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1078].scale = D3DXVECTOR3(3, 1, 10);

	cube[1079].position = D3DXVECTOR3(-178.72f, -104.42f, 347.70f);
	cube[1079].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1079].scale = D3DXVECTOR3(3, 1, 10);

	cube[1080].position = D3DXVECTOR3(-179.17f, -103.26f, 348.88f);
	cube[1080].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1080].scale = D3DXVECTOR3(3, 1, 10);

	cube[1081].position = D3DXVECTOR3(-170.64f, -106.12f, 352.37f);
	cube[1081].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1081].scale = D3DXVECTOR3(3, 1, 10);

	cube[1082].position = D3DXVECTOR3(-171.09f, -104.96f, 353.55f);
	cube[1082].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1082].scale = D3DXVECTOR3(3, 1, 10);

	cube[1083].position = D3DXVECTOR3(-162.14f, -107.87f, 357.30f);
	cube[1083].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1083].scale = D3DXVECTOR3(3, 1, 10);

	cube[1084].position = D3DXVECTOR3(-162.59f, -106.71f, 358.48f);
	cube[1084].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1084].scale = D3DXVECTOR3(3, 1, 10);

	cube[1085].position = D3DXVECTOR3(-154.09f, -109.54f, 362.02f);
	cube[1085].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1085].scale = D3DXVECTOR3(3, 1, 10);

	cube[1086].position = D3DXVECTOR3(-154.53f, -108.38f, 363.20f);
	cube[1086].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1086].scale = D3DXVECTOR3(3, 1, 10);

	cube[1087].position = D3DXVECTOR3(-146.13f, -111.15f, 365.89f);
	cube[1087].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1087].scale = D3DXVECTOR3(3, 1, 10);

	cube[1088].position = D3DXVECTOR3(-146.36f, -109.99f, 367.13f);
	cube[1088].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1088].scale = D3DXVECTOR3(3, 1, 10);

	cube[1089].position = D3DXVECTOR3(-137.96f, -112.74f, 368.22f);
	cube[1089].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1089].scale = D3DXVECTOR3(3, 1, 10);

	cube[1090].position = D3DXVECTOR3(-137.97f, -111.58f, 369.49f);
	cube[1090].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1090].scale = D3DXVECTOR3(3, 1, 10);

	cube[1091].position = D3DXVECTOR3(-129.21f, -114.37f, 369.13f);
	cube[1091].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1091].scale = D3DXVECTOR3(3, 1, 10);

	cube[1092].position = D3DXVECTOR3(-129.00f, -113.21f, 370.38f);
	cube[1092].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1092].scale = D3DXVECTOR3(3, 1, 10);

	cube[1093].position = D3DXVECTOR3(-120.48f, -116.00f, 368.52f);
	cube[1093].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1093].scale = D3DXVECTOR3(3, 1, 10);

	cube[1094].position = D3DXVECTOR3(-120.05f, -114.84f, 369.72f);
	cube[1094].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1094].scale = D3DXVECTOR3(3, 1, 10);

	cube[1095].position = D3DXVECTOR3(-111.20f, -117.70f, 366.89f);
	cube[1095].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1095].scale = D3DXVECTOR3(3, 1, 10);

	cube[1096].position = D3DXVECTOR3(-110.78f, -116.54f, 368.08f);
	cube[1096].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1096].scale = D3DXVECTOR3(3, 1, 10);

	cube[1097].position = D3DXVECTOR3(-104.22f, -119.39f, 366.17f);
	cube[1097].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1097].scale = D3DXVECTOR3(3, 1, 10);

	cube[1098].position = D3DXVECTOR3(-103.30f, -119.57f, 365.76f);
	cube[1098].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1098].scale = D3DXVECTOR3(3, 1, 7);

	cube[1099].position = D3DXVECTOR3(-104.01f, -118.23f, 367.42f);
	cube[1099].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1099].scale = D3DXVECTOR3(3, 1, 10);

	cube[1100].position = D3DXVECTOR3(-103.00f, -118.26f, 367.27f);
	cube[1100].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1100].scale = D3DXVECTOR3(5, 1, 7);

	cube[1101].position = D3DXVECTOR3(-97.48f, -121.05f, 366.61f);
	cube[1101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1101].scale = D3DXVECTOR3(3, 1, 10);

	cube[1102].position = D3DXVECTOR3(-96.13f, -121.41f, 366.23f);
	cube[1102].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1102].scale = D3DXVECTOR3(3, 1, 7);

	cube[1103].position = D3DXVECTOR3(-97.49f, -119.89f, 367.87f);
	cube[1103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1103].scale = D3DXVECTOR3(3, 1, 10);

	cube[1104].position = D3DXVECTOR3(-96.11f, -119.81f, 368.13f);
	cube[1104].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1104].scale = D3DXVECTOR3(5, 1, 7);

	cube[1105].position = D3DXVECTOR3(-91.35f, -122.65f, 368.11f);
	cube[1105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1105].scale = D3DXVECTOR3(3, 1, 10);

	cube[1106].position = D3DXVECTOR3(-89.94f, -122.91f, 368.01f);
	cube[1106].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1106].scale = D3DXVECTOR3(3, 1, 7);

	cube[1107].position = D3DXVECTOR3(-91.58f, -121.49f, 369.35f);
	cube[1107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1107].scale = D3DXVECTOR3(3, 1, 10);

	cube[1108].position = D3DXVECTOR3(-90.19f, -121.59f, 369.63f);
	cube[1108].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1108].scale = D3DXVECTOR3(5, 1, 7);

	cube[1109].position = D3DXVECTOR3(-85.18f, -124.30f, 370.80f);
	cube[1109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1109].scale = D3DXVECTOR3(3, 1, 10);

	cube[1110].position = D3DXVECTOR3(-83.85f, -124.63f, 370.85f);
	cube[1110].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1110].scale = D3DXVECTOR3(3, 1, 7);

	cube[1111].position = D3DXVECTOR3(-85.62f, -123.14f, 371.99f);
	cube[1111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1111].scale = D3DXVECTOR3(3, 1, 10);

	cube[1112].position = D3DXVECTOR3(-84.37f, -123.25f, 372.46f);
	cube[1112].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1112].scale = D3DXVECTOR3(5, 1, 7);

	cube[1113].position = D3DXVECTOR3(-77.26f, -125.97f, 375.40f);
	cube[1113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1113].scale = D3DXVECTOR3(3, 1, 10);

	cube[1114].position = D3DXVECTOR3(-77.70f, -124.81f, 376.58f);
	cube[1114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1114].scale = D3DXVECTOR3(3, 1, 10);

	cube[1115].position = D3DXVECTOR3(-69.30f, -127.58f, 379.27f);
	cube[1115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1115].scale = D3DXVECTOR3(3, 1, 10);

	cube[1116].position = D3DXVECTOR3(-69.53f, -126.42f, 380.51f);
	cube[1116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1116].scale = D3DXVECTOR3(3, 1, 10);

	cube[1117].position = D3DXVECTOR3(-61.13f, -129.17f, 381.60f);
	cube[1117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1117].scale = D3DXVECTOR3(3, 1, 10);

	cube[1118].position = D3DXVECTOR3(-61.14f, -128.01f, 382.87f);
	cube[1118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1118].scale = D3DXVECTOR3(3, 1, 10);

	cube[1119].position = D3DXVECTOR3(-52.38f, -130.80f, 382.51f);
	cube[1119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1119].scale = D3DXVECTOR3(3, 1, 10);

	cube[1120].position = D3DXVECTOR3(-52.17f, -129.64f, 383.76f);
	cube[1120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1120].scale = D3DXVECTOR3(3, 1, 10);

	cube[1121].position = D3DXVECTOR3(-43.65f, -132.43f, 381.90f);
	cube[1121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1121].scale = D3DXVECTOR3(3, 1, 10);

	cube[1122].position = D3DXVECTOR3(-43.22f, -131.27f, 383.10f);
	cube[1122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1122].scale = D3DXVECTOR3(3, 1, 10);

	cube[1123].position = D3DXVECTOR3(-34.52f, -134.15f, 380.34f);
	cube[1123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1123].scale = D3DXVECTOR3(3, 1, 10);

	cube[1124].position = D3DXVECTOR3(-34.10f, -132.99f, 381.53f);
	cube[1124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1124].scale = D3DXVECTOR3(3, 1, 10);

	cube[1125].position = D3DXVECTOR3(-27.54f, -135.84f, 379.62f);
	cube[1125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1125].scale = D3DXVECTOR3(3, 1, 10);

	cube[1126].position = D3DXVECTOR3(-26.62f, -136.02f, 379.21f);
	cube[1126].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1126].scale = D3DXVECTOR3(3, 1, 7);

	cube[1127].position = D3DXVECTOR3(-27.33f, -134.68f, 380.87f);
	cube[1127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1127].scale = D3DXVECTOR3(3, 1, 10);

	cube[1128].position = D3DXVECTOR3(-26.32f, -134.71f, 380.72f);
	cube[1128].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1128].scale = D3DXVECTOR3(5, 1, 7);

	cube[1129].position = D3DXVECTOR3(-20.80f, -137.50f, 380.06f);
	cube[1129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1129].scale = D3DXVECTOR3(3, 1, 10);

	cube[1130].position = D3DXVECTOR3(-19.45f, -137.86f, 379.68f);
	cube[1130].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1130].scale = D3DXVECTOR3(3, 1, 7);

	cube[1131].position = D3DXVECTOR3(-20.81f, -136.34f, 381.32f);
	cube[1131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1131].scale = D3DXVECTOR3(3, 1, 10);

	cube[1132].position = D3DXVECTOR3(-19.43f, -136.26f, 381.58f);
	cube[1132].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1132].scale = D3DXVECTOR3(5, 1, 7);

	cube[1133].position = D3DXVECTOR3(-14.67f, -139.10f, 381.56f);
	cube[1133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1133].scale = D3DXVECTOR3(3, 1, 10);

	cube[1134].position = D3DXVECTOR3(-13.26f, -139.36f, 381.46f);
	cube[1134].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1134].scale = D3DXVECTOR3(3, 1, 7);

	cube[1135].position = D3DXVECTOR3(-14.90f, -137.94f, 382.80f);
	cube[1135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1135].scale = D3DXVECTOR3(3, 1, 10);

	cube[1136].position = D3DXVECTOR3(-13.51f, -138.04f, 383.08f);
	cube[1136].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1136].scale = D3DXVECTOR3(5, 1, 7);

	cube[1137].position = D3DXVECTOR3(-8.50f, -140.75f, 384.25f);
	cube[1137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1137].scale = D3DXVECTOR3(3, 1, 10);

	cube[1138].position = D3DXVECTOR3(-7.17f, -141.08f, 384.30f);
	cube[1138].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1138].scale = D3DXVECTOR3(3, 1, 7);

	cube[1139].position = D3DXVECTOR3(-8.94f, -139.59f, 385.44f);
	cube[1139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1139].scale = D3DXVECTOR3(3, 1, 10);

	cube[1140].position = D3DXVECTOR3(-7.69f, -139.70f, 385.91f);
	cube[1140].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1140].scale = D3DXVECTOR3(5, 1, 7);

	cube[1141].position = D3DXVECTOR3(-0.18f, -142.49f, 389.03f);
	cube[1141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1141].scale = D3DXVECTOR3(3, 1, 10);

	cube[1142].position = D3DXVECTOR3(-0.62f, -141.33f, 390.22f);
	cube[1142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1142].scale = D3DXVECTOR3(3, 1, 10);

	cube[1143].position = D3DXVECTOR3(7.85f, -144.18f, 393.68f);
	cube[1143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1143].scale = D3DXVECTOR3(3, 1, 10);

	cube[1144].position = D3DXVECTOR3(7.41f, -143.02f, 394.87f);
	cube[1144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1144].scale = D3DXVECTOR3(3, 1, 10);

	cube[1145].position = D3DXVECTOR3(16.11f, -145.90f, 398.44f);
	cube[1145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1145].scale = D3DXVECTOR3(3, 1, 10);

	cube[1146].position = D3DXVECTOR3(15.67f, -144.74f, 399.63f);
	cube[1146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1146].scale = D3DXVECTOR3(3, 1, 10);

	cube[1147].position = D3DXVECTOR3(24.23f, -147.60f, 403.11f);
	cube[1147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1147].scale = D3DXVECTOR3(3, 1, 10);

	cube[1148].position = D3DXVECTOR3(23.79f, -146.44f, 404.30f);
	cube[1148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1148].scale = D3DXVECTOR3(3, 1, 10);

	cube[1149].position = D3DXVECTOR3(32.33f, -149.27f, 407.77f);
	cube[1149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1149].scale = D3DXVECTOR3(3, 1, 10);

	cube[1150].position = D3DXVECTOR3(31.89f, -148.11f, 408.96f);
	cube[1150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1150].scale = D3DXVECTOR3(3, 1, 10);

	cube[1151].position = D3DXVECTOR3(40.63f, -150.97f, 412.55f);
	cube[1151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1151].scale = D3DXVECTOR3(3, 1, 10);

	cube[1152].position = D3DXVECTOR3(40.19f, -149.81f, 413.74f);
	cube[1152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1152].scale = D3DXVECTOR3(3, 1, 10);

	cube[1153].position = D3DXVECTOR3(48.21f, -152.54f, 416.87f);
	cube[1153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1153].scale = D3DXVECTOR3(3, 1, 10);

	cube[1154].position = D3DXVECTOR3(47.76f, -151.38f, 418.06f);
	cube[1154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1154].scale = D3DXVECTOR3(3, 1, 10);

	cube[1155].position = D3DXVECTOR3(56.53f, -154.30f, 421.67f);
	cube[1155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1155].scale = D3DXVECTOR3(3, 1, 10);

	cube[1156].position = D3DXVECTOR3(56.09f, -153.14f, 422.86f);
	cube[1156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1156].scale = D3DXVECTOR3(3, 1, 10);

	cube[1157].position = D3DXVECTOR3(64.56f, -155.99f, 426.32f);
	cube[1157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1157].scale = D3DXVECTOR3(3, 1, 10);

	cube[1158].position = D3DXVECTOR3(64.12f, -154.83f, 427.51f);
	cube[1158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1158].scale = D3DXVECTOR3(3, 1, 10);

	cube[1159].position = D3DXVECTOR3(72.82f, -157.71f, 431.08f);
	cube[1159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1159].scale = D3DXVECTOR3(3, 1, 10);

	cube[1160].position = D3DXVECTOR3(72.38f, -156.55f, 432.27f);
	cube[1160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1160].scale = D3DXVECTOR3(3, 1, 10);

	cube[1161].position = D3DXVECTOR3(80.94f, -159.41f, 435.75f);
	cube[1161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1161].scale = D3DXVECTOR3(3, 1, 10);

	cube[1162].position = D3DXVECTOR3(80.50f, -158.25f, 436.94f);
	cube[1162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1162].scale = D3DXVECTOR3(3, 1, 10);

	cube[1163].position = D3DXVECTOR3(89.04f, -161.08f, 440.41f);
	cube[1163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1163].scale = D3DXVECTOR3(3, 1, 10);

	cube[1164].position = D3DXVECTOR3(88.60f, -159.92f, 441.60f);
	cube[1164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1164].scale = D3DXVECTOR3(3, 1, 10);

	cube[1165].position = D3DXVECTOR3(97.34f, -162.78f, 445.19f);
	cube[1165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1165].scale = D3DXVECTOR3(3, 1, 10);

	cube[1166].position = D3DXVECTOR3(96.90f, -161.62f, 446.38f);
	cube[1166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1166].scale = D3DXVECTOR3(3, 1, 10);

	cube[1167].position = D3DXVECTOR3(104.92f, -164.35f, 449.51f);
	cube[1167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1167].scale = D3DXVECTOR3(3, 1, 10);

	cube[1168].position = D3DXVECTOR3(104.48f, -163.19f, 450.70f);
	cube[1168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1168].scale = D3DXVECTOR3(3, 1, 10);

	cube[1169].position = D3DXVECTOR3(110.09f, -165.93f, 452.99f);
	cube[1169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1169].scale = D3DXVECTOR3(3, 1, 10);

	cube[1170].position = D3DXVECTOR3(111.07f, -166.11f, 453.27f);
	cube[1170].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1170].scale = D3DXVECTOR3(3, 1, 7);

	cube[1171].position = D3DXVECTOR3(109.45f, -164.77f, 454.09f);
	cube[1171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1171].scale = D3DXVECTOR3(3, 1, 10);

	cube[1172].position = D3DXVECTOR3(110.32f, -164.80f, 454.62f);
	cube[1172].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1172].scale = D3DXVECTOR3(5, 1, 7);

	cube[1173].position = D3DXVECTOR3(114.97f, -167.59f, 457.66f);
	cube[1173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1173].scale = D3DXVECTOR3(3, 1, 10);

	cube[1174].position = D3DXVECTOR3(116.25f, -167.95f, 458.24f);
	cube[1174].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1174].scale = D3DXVECTOR3(3, 1, 7);

	cube[1175].position = D3DXVECTOR3(114.15f, -166.43f, 458.63f);
	cube[1175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1175].scale = D3DXVECTOR3(3, 1, 10);

	cube[1176].position = D3DXVECTOR3(115.04f, -166.35f, 459.71f);
	cube[1176].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1176].scale = D3DXVECTOR3(5, 1, 7);

	cube[1177].position = D3DXVECTOR3(118.71f, -169.19f, 462.75f);
	cube[1177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1177].scale = D3DXVECTOR3(3, 1, 10);

	cube[1178].position = D3DXVECTOR3(119.85f, -169.45f, 463.58f);
	cube[1178].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1178].scale = D3DXVECTOR3(3, 1, 7);

	cube[1179].position = D3DXVECTOR3(117.73f, -168.03f, 463.56f);
	cube[1179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1179].scale = D3DXVECTOR3(3, 1, 10);

	cube[1180].position = D3DXVECTOR3(118.61f, -168.13f, 464.66f);
	cube[1180].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1180].scale = D3DXVECTOR3(5, 1, 7);

	cube[1181].position = D3DXVECTOR3(121.70f, -170.84f, 468.78f);
	cube[1181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1181].scale = D3DXVECTOR3(3, 1, 10);

	cube[1182].position = D3DXVECTOR3(122.69f, -171.17f, 469.67f);
	cube[1182].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1182].scale = D3DXVECTOR3(3, 1, 7);

	cube[1183].position = D3DXVECTOR3(120.60f, -169.68f, 469.41f);
	cube[1183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1183].scale = D3DXVECTOR3(3, 1, 10);

	cube[1184].position = D3DXVECTOR3(121.25f, -169.79f, 470.57f);
	cube[1184].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1184].scale = D3DXVECTOR3(5, 1, 7);

	cube[1185].position = D3DXVECTOR3(124.93f, -172.53f, 477.63f);
	cube[1185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1185].scale = D3DXVECTOR3(3, 1, 10);

	cube[1186].position = D3DXVECTOR3(123.83f, -171.37f, 478.25f);
	cube[1186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1186].scale = D3DXVECTOR3(3, 1, 10);

	cube[1187].position = D3DXVECTOR3(128.01f, -174.19f, 486.10f);
	cube[1187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1187].scale = D3DXVECTOR3(3, 1, 10);

	cube[1188].position = D3DXVECTOR3(126.91f, -173.03f, 486.72f);
	cube[1188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1188].scale = D3DXVECTOR3(3, 1, 10);

	cube[1189].position = D3DXVECTOR3(131.13f, -175.84f, 494.55f);
	cube[1189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1189].scale = D3DXVECTOR3(3, 1, 10);

	cube[1190].position = D3DXVECTOR3(130.03f, -174.68f, 495.17f);
	cube[1190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1190].scale = D3DXVECTOR3(3, 1, 10);

	cube[1191].position = D3DXVECTOR3(133.05f, -177.53f, 501.30f);
	cube[1191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1191].scale = D3DXVECTOR3(3, 1, 10);

	cube[1192].position = D3DXVECTOR3(133.62f, -177.71f, 502.14f);
	cube[1192].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1192].scale = D3DXVECTOR3(3, 1, 7);

	cube[1193].position = D3DXVECTOR3(131.86f, -176.37f, 501.72f);
	cube[1193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1193].scale = D3DXVECTOR3(3, 1, 10);

	cube[1194].position = D3DXVECTOR3(132.18f, -176.40f, 502.69f);
	cube[1194].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1194].scale = D3DXVECTOR3(5, 1, 7);

	cube[1195].position = D3DXVECTOR3(133.79f, -179.19f, 508.01f);
	cube[1195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1195].scale = D3DXVECTOR3(3, 1, 10);

	cube[1196].position = D3DXVECTOR3(134.40f, -179.55f, 509.27f);
	cube[1196].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1196].scale = D3DXVECTOR3(3, 1, 7);

	cube[1197].position = D3DXVECTOR3(132.54f, -178.03f, 508.22f);
	cube[1197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1197].scale = D3DXVECTOR3(3, 1, 10);

	cube[1198].position = D3DXVECTOR3(132.52f, -177.95f, 509.62f);
	cube[1198].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1198].scale = D3DXVECTOR3(5, 1, 7);

	cube[1199].position = D3DXVECTOR3(133.38f, -180.79f, 514.31f);
	cube[1199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1199].scale = D3DXVECTOR3(3, 1, 10);

	cube[1200].position = D3DXVECTOR3(133.72f, -181.05f, 515.68f);
	cube[1200].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1200].scale = D3DXVECTOR3(3, 1, 7);

	cube[1201].position = D3DXVECTOR3(132.11f, -179.63f, 514.30f);
	cube[1201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1201].scale = D3DXVECTOR3(3, 1, 10);

	cube[1202].position = D3DXVECTOR3(132.08f, -179.73f, 515.71f);
	cube[1202].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1202].scale = D3DXVECTOR3(5, 1, 7);

	cube[1203].position = D3DXVECTOR3(131.80f, -182.44f, 520.86f);
	cube[1203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1203].scale = D3DXVECTOR3(3, 1, 10);

	cube[1204].position = D3DXVECTOR3(131.98f, -182.77f, 522.18f);
	cube[1204].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1204].scale = D3DXVECTOR3(3, 1, 7);

	cube[1205].position = D3DXVECTOR3(130.55f, -181.28f, 520.62f);
	cube[1205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1205].scale = D3DXVECTOR3(3, 1, 10);

	cube[1206].position = D3DXVECTOR3(130.30f, -181.39f, 521.94f);
	cube[1206].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1206].scale = D3DXVECTOR3(5, 1, 7);

	cube[1207].position = D3DXVECTOR3(128.48f, -184.17f, 529.93f);
	cube[1207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1207].scale = D3DXVECTOR3(3, 1, 10);

	cube[1208].position = D3DXVECTOR3(127.24f, -183.01f, 529.70f);
	cube[1208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1208].scale = D3DXVECTOR3(3, 1, 10);

	cube[1209].position = D3DXVECTOR3(125.35f, -185.83f, 538.44f);
	cube[1209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1209].scale = D3DXVECTOR3(3, 1, 10);

	cube[1210].position = D3DXVECTOR3(124.11f, -184.67f, 538.21f);
	cube[1210].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1210].scale = D3DXVECTOR3(3, 1, 10);

	cube[1211].position = D3DXVECTOR3(122.92f, -187.44f, 546.95f);
	cube[1211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1211].scale = D3DXVECTOR3(3, 1, 10);

	cube[1212].position = D3DXVECTOR3(121.66f, -186.28f, 546.94f);
	cube[1212].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1212].scale = D3DXVECTOR3(3, 1, 10);

	cube[1213].position = D3DXVECTOR3(122.04f, -189.03f, 555.40f);
	cube[1213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1213].scale = D3DXVECTOR3(3, 1, 10);

	cube[1214].position = D3DXVECTOR3(120.79f, -187.87f, 555.61f);
	cube[1214].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1214].scale = D3DXVECTOR3(3, 1, 10);

	cube[1215].position = D3DXVECTOR3(122.67f, -190.66f, 564.18f);
	cube[1215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1215].scale = D3DXVECTOR3(3, 1, 10);

	cube[1216].position = D3DXVECTOR3(121.47f, -189.50f, 564.60f);
	cube[1216].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1216].scale = D3DXVECTOR3(3, 1, 10);

	cube[1217].position = D3DXVECTOR3(124.78f, -192.29f, 572.67f);
	cube[1217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1217].scale = D3DXVECTOR3(3, 1, 10);

	cube[1218].position = D3DXVECTOR3(123.68f, -191.13f, 573.30f);
	cube[1218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1218].scale = D3DXVECTOR3(3, 1, 10);

	cube[1219].position = D3DXVECTOR3(127.91f, -193.96f, 581.31f);
	cube[1219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1219].scale = D3DXVECTOR3(3, 1, 10);

	cube[1220].position = D3DXVECTOR3(126.81f, -192.80f, 581.93f);
	cube[1220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1220].scale = D3DXVECTOR3(3, 1, 10);

	cube[1221].position = D3DXVECTOR3(129.83f, -195.65f, 588.06f);
	cube[1221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1221].scale = D3DXVECTOR3(3, 1, 10);

	cube[1222].position = D3DXVECTOR3(130.40f, -195.83f, 588.90f);
	cube[1222].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1222].scale = D3DXVECTOR3(3, 1, 7);

	cube[1223].position = D3DXVECTOR3(128.64f, -194.49f, 588.48f);
	cube[1223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1223].scale = D3DXVECTOR3(3, 1, 10);

	cube[1224].position = D3DXVECTOR3(128.96f, -194.52f, 589.45f);
	cube[1224].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1224].scale = D3DXVECTOR3(5, 1, 7);

	cube[1225].position = D3DXVECTOR3(130.57f, -197.31f, 594.77f);
	cube[1225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1225].scale = D3DXVECTOR3(3, 1, 10);

	cube[1226].position = D3DXVECTOR3(131.18f, -197.67f, 596.03f);
	cube[1226].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1226].scale = D3DXVECTOR3(3, 1, 7);

	cube[1227].position = D3DXVECTOR3(129.32f, -196.15f, 594.98f);
	cube[1227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1227].scale = D3DXVECTOR3(3, 1, 10);

	cube[1228].position = D3DXVECTOR3(129.30f, -196.07f, 596.38f);
	cube[1228].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1228].scale = D3DXVECTOR3(5, 1, 7);

	cube[1229].position = D3DXVECTOR3(130.16f, -198.91f, 601.07f);
	cube[1229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1229].scale = D3DXVECTOR3(3, 1, 10);

	cube[1230].position = D3DXVECTOR3(130.50f, -199.17f, 602.44f);
	cube[1230].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1230].scale = D3DXVECTOR3(3, 1, 7);

	cube[1231].position = D3DXVECTOR3(128.89f, -197.75f, 601.06f);
	cube[1231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1231].scale = D3DXVECTOR3(3, 1, 10);

	cube[1232].position = D3DXVECTOR3(128.86f, -197.85f, 602.47f);
	cube[1232].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1232].scale = D3DXVECTOR3(5, 1, 7);

	cube[1233].position = D3DXVECTOR3(128.58f, -200.56f, 607.61f);
	cube[1233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1233].scale = D3DXVECTOR3(3, 1, 10);

	cube[1234].position = D3DXVECTOR3(128.76f, -200.89f, 608.94f);
	cube[1234].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1234].scale = D3DXVECTOR3(3, 1, 7);

	cube[1235].position = D3DXVECTOR3(127.33f, -199.40f, 607.38f);
	cube[1235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1235].scale = D3DXVECTOR3(3, 1, 10);

	cube[1236].position = D3DXVECTOR3(127.08f, -199.51f, 608.70f);
	cube[1236].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1236].scale = D3DXVECTOR3(5, 1, 7);

	cube[1237].position = D3DXVECTOR3(125.35f, -202.26f, 616.51f);
	cube[1237].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1237].scale = D3DXVECTOR3(3, 1, 10);

	cube[1238].position = D3DXVECTOR3(124.11f, -201.10f, 616.28f);
	cube[1238].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1238].scale = D3DXVECTOR3(3, 1, 10);

	cube[1239].position = D3DXVECTOR3(122.10f, -203.98f, 625.46f);
	cube[1239].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1239].scale = D3DXVECTOR3(3, 1, 10);

	cube[1240].position = D3DXVECTOR3(120.86f, -202.82f, 625.23f);
	cube[1240].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1240].scale = D3DXVECTOR3(3, 1, 10);

	cube[1241].position = D3DXVECTOR3(118.97f, -205.63f, 634.01f);
	cube[1241].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1241].scale = D3DXVECTOR3(3, 1, 10);

	cube[1242].position = D3DXVECTOR3(117.73f, -204.47f, 633.78f);
	cube[1242].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (340.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1242].scale = D3DXVECTOR3(3, 1, 10);

	cube[1243].position = D3DXVECTOR3(116.54f, -207.24f, 642.52f);
	cube[1243].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1243].scale = D3DXVECTOR3(3, 1, 10);

	cube[1244].position = D3DXVECTOR3(115.28f, -206.08f, 642.51f);
	cube[1244].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, (350.00f - 360)*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1244].scale = D3DXVECTOR3(3, 1, 10);

	cube[1245].position = D3DXVECTOR3(115.66f, -208.83f, 650.97f);
	cube[1245].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1245].scale = D3DXVECTOR3(3, 1, 10);

	cube[1246].position = D3DXVECTOR3(114.41f, -207.67f, 651.18f);
	cube[1246].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1246].scale = D3DXVECTOR3(3, 1, 10);

	cube[1247].position = D3DXVECTOR3(116.29f, -210.46f, 659.75f);
	cube[1247].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1247].scale = D3DXVECTOR3(3, 1, 10);

	cube[1248].position = D3DXVECTOR3(115.09f, -209.30f, 660.17f);
	cube[1248].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1248].scale = D3DXVECTOR3(3, 1, 10);

	cube[1249].position = D3DXVECTOR3(118.40f, -212.09f, 668.24f);
	cube[1249].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1249].scale = D3DXVECTOR3(3, 1, 10);

	cube[1250].position = D3DXVECTOR3(117.30f, -210.93f, 668.87f);
	cube[1250].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1250].scale = D3DXVECTOR3(3, 1, 10);

	cube[1251].position = D3DXVECTOR3(121.64f, -213.83f, 677.24f);
	cube[1251].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1251].scale = D3DXVECTOR3(3, 1, 10);

	cube[1252].position = D3DXVECTOR3(120.54f, -212.67f, 677.87f);
	cube[1252].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1252].scale = D3DXVECTOR3(3, 1, 10);

	cube[1253].position = D3DXVECTOR3(124.92f, -215.56f, 686.24f);
	cube[1253].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1253].scale = D3DXVECTOR3(3, 1, 10);

	cube[1254].position = D3DXVECTOR3(123.82f, -214.40f, 686.87f);
	cube[1254].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1254].scale = D3DXVECTOR3(3, 1, 10);

	cube[1255].position = D3DXVECTOR3(128.14f, -217.25f, 695.08f);
	cube[1255].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1255].scale = D3DXVECTOR3(3, 1, 10);

	cube[1256].position = D3DXVECTOR3(127.04f, -216.09f, 695.71f);
	cube[1256].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1256].scale = D3DXVECTOR3(3, 1, 10);

	cube[1257].position = D3DXVECTOR3(131.31f, -218.93f, 703.81f);
	cube[1257].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1257].scale = D3DXVECTOR3(3, 1, 10);

	cube[1258].position = D3DXVECTOR3(130.21f, -217.77f, 704.44f);
	cube[1258].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1258].scale = D3DXVECTOR3(3, 1, 10);

	cube[1259].position = D3DXVECTOR3(134.47f, -220.61f, 712.48f);
	cube[1259].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1259].scale = D3DXVECTOR3(3, 1, 10);

	cube[1260].position = D3DXVECTOR3(133.37f, -219.45f, 713.11f);
	cube[1260].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1260].scale = D3DXVECTOR3(3, 1, 10);

	cube[1261].position = D3DXVECTOR3(137.71f, -222.35f, 721.41f);
	cube[1261].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1261].scale = D3DXVECTOR3(3, 1, 10);

	cube[1262].position = D3DXVECTOR3(136.61f, -221.19f, 722.04f);
	cube[1262].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1262].scale = D3DXVECTOR3(3, 1, 10);

	cube[1263].position = D3DXVECTOR3(140.94f, -224.05f, 730.29f);
	cube[1263].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1263].scale = D3DXVECTOR3(3, 1, 10);

	cube[1264].position = D3DXVECTOR3(139.84f, -222.89f, 730.92f);
	cube[1264].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1264].scale = D3DXVECTOR3(3, 1, 10);

	cube[1265].position = D3DXVECTOR3(144.11f, -225.75f, 739.09f);
	cube[1265].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1265].scale = D3DXVECTOR3(3, 1, 10);

	cube[1266].position = D3DXVECTOR3(143.01f, -224.59f, 739.71f);
	cube[1266].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1266].scale = D3DXVECTOR3(3, 1, 10);

	cube[1267].position = D3DXVECTOR3(147.05f, -227.27f, 747.12f);
	cube[1267].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1267].scale = D3DXVECTOR3(3, 1, 10);

	cube[1268].position = D3DXVECTOR3(145.95f, -226.11f, 747.74f);
	cube[1268].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1268].scale = D3DXVECTOR3(3, 1, 10);

	cube[1269].position = D3DXVECTOR3(150.33f, -229.00f, 756.12f);
	cube[1269].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1269].scale = D3DXVECTOR3(3, 1, 10);

	cube[1270].position = D3DXVECTOR3(149.23f, -227.84f, 756.74f);
	cube[1270].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1270].scale = D3DXVECTOR3(3, 1, 10);

	cube[1271].position = D3DXVECTOR3(153.55f, -230.69f, 764.96f);
	cube[1271].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1271].scale = D3DXVECTOR3(3, 1, 10);

	cube[1272].position = D3DXVECTOR3(152.45f, -229.53f, 765.58f);
	cube[1272].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1272].scale = D3DXVECTOR3(3, 1, 10);

	cube[1273].position = D3DXVECTOR3(156.72f, -232.37f, 773.69f);
	cube[1273].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1273].scale = D3DXVECTOR3(3, 1, 10);

	cube[1274].position = D3DXVECTOR3(155.62f, -231.21f, 774.31f);
	cube[1274].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1274].scale = D3DXVECTOR3(3, 1, 10);

	cube[1275].position = D3DXVECTOR3(159.88f, -234.05f, 782.36f);
	cube[1275].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1275].scale = D3DXVECTOR3(3, 1, 10);

	cube[1276].position = D3DXVECTOR3(158.78f, -232.89f, 782.98f);
	cube[1276].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1276].scale = D3DXVECTOR3(3, 1, 10);

	cube[1277].position = D3DXVECTOR3(163.12f, -235.79f, 791.29f);
	cube[1277].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1277].scale = D3DXVECTOR3(3, 1, 10);

	cube[1278].position = D3DXVECTOR3(162.02f, -234.63f, 791.91f);
	cube[1278].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1278].scale = D3DXVECTOR3(3, 1, 10);

	cube[1279].position = D3DXVECTOR3(166.35f, -237.49f, 800.17f);
	cube[1279].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1279].scale = D3DXVECTOR3(3, 1, 10);

	cube[1280].position = D3DXVECTOR3(165.25f, -236.33f, 800.79f);
	cube[1280].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1280].scale = D3DXVECTOR3(3, 1, 10);

	cube[1281].position = D3DXVECTOR3(169.52f, -239.19f, 808.96f);
	cube[1281].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1281].scale = D3DXVECTOR3(3, 1, 10);

	cube[1282].position = D3DXVECTOR3(168.42f, -238.03f, 809.59f);
	cube[1282].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1282].scale = D3DXVECTOR3(3, 1, 10);

	cube[1283].position = D3DXVECTOR3(173.07f, -240.78f, 816.80f);
	cube[1283].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1283].scale = D3DXVECTOR3(3, 1, 10);

	cube[1284].position = D3DXVECTOR3(172.09f, -239.62f, 817.61f);
	cube[1284].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1284].scale = D3DXVECTOR3(3, 1, 10);

	cube[1285].position = D3DXVECTOR3(177.83f, -242.37f, 823.84f);
	cube[1285].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1285].scale = D3DXVECTOR3(3, 1, 10);

	cube[1286].position = D3DXVECTOR3(177.01f, -241.21f, 824.81f);
	cube[1286].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1286].scale = D3DXVECTOR3(3, 1, 10);

	cube[1287].position = D3DXVECTOR3(183.95f, -244.00f, 830.16f);
	cube[1287].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1287].scale = D3DXVECTOR3(3, 1, 10);

	cube[1288].position = D3DXVECTOR3(183.31f, -242.84f, 831.26f);
	cube[1288].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1288].scale = D3DXVECTOR3(3, 1, 10);

	cube[1289].position = D3DXVECTOR3(191.03f, -245.63f, 835.31f);
	cube[1289].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1289].scale = D3DXVECTOR3(3, 1, 10);

	cube[1290].position = D3DXVECTOR3(190.59f, -244.47f, 836.50f);
	cube[1290].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1290].scale = D3DXVECTOR3(3, 1, 10);

	cube[1291].position = D3DXVECTOR3(198.86f, -247.23f, 839.13f);
	cube[1291].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1291].scale = D3DXVECTOR3(3, 1, 10);

	cube[1292].position = D3DXVECTOR3(198.63f, -246.07f, 840.37f);
	cube[1292].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1292].scale = D3DXVECTOR3(3, 1, 10);

	cube[1293].position = D3DXVECTOR3(207.30f, -248.87f, 841.54f);
	cube[1293].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1293].scale = D3DXVECTOR3(3, 1, 10);

	cube[1294].position = D3DXVECTOR3(207.29f, -247.71f, 842.81f);
	cube[1294].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1294].scale = D3DXVECTOR3(3, 1, 10);

	cube[1295].position = D3DXVECTOR3(215.82f, -250.53f, 842.37f);
	cube[1295].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1295].scale = D3DXVECTOR3(3, 1, 10);

	cube[1296].position = D3DXVECTOR3(216.03f, -249.37f, 843.62f);
	cube[1296].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1296].scale = D3DXVECTOR3(3, 1, 10);

	cube[1297].position = D3DXVECTOR3(224.10f, -252.07f, 841.79f);
	cube[1297].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1297].scale = D3DXVECTOR3(3, 1, 10);

	cube[1298].position = D3DXVECTOR3(224.52f, -250.91f, 842.98f);
	cube[1298].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1298].scale = D3DXVECTOR3(3, 1, 10);

	cube[1299].position = D3DXVECTOR3(233.30f, -253.73f, 840.17f);
	cube[1299].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1299].scale = D3DXVECTOR3(3, 1, 10);

	cube[1300].position = D3DXVECTOR3(233.72f, -252.57f, 841.36f);
	cube[1300].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1300].scale = D3DXVECTOR3(3, 1, 10);

	cube[1301].position = D3DXVECTOR3(242.63f, -255.42f, 838.53f);
	cube[1301].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1301].scale = D3DXVECTOR3(3, 1, 10);

	cube[1302].position = D3DXVECTOR3(243.05f, -254.26f, 839.72f);
	cube[1302].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1302].scale = D3DXVECTOR3(3, 1, 10);

	cube[1303].position = D3DXVECTOR3(251.53f, -257.05f, 836.98f);
	cube[1303].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1303].scale = D3DXVECTOR3(3, 1, 10);

	cube[1304].position = D3DXVECTOR3(251.95f, -255.89f, 838.18f);
	cube[1304].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1304].scale = D3DXVECTOR3(3, 1, 10);

	cube[1305].position = D3DXVECTOR3(258.51f, -258.74f, 836.27f);
	cube[1305].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1305].scale = D3DXVECTOR3(3, 1, 10);

	cube[1306].position = D3DXVECTOR3(259.43f, -258.92f, 835.85f);
	cube[1306].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1306].scale = D3DXVECTOR3(3, 1, 7);

	cube[1307].position = D3DXVECTOR3(258.72f, -257.58f, 837.52f);
	cube[1307].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1307].scale = D3DXVECTOR3(3, 1, 10);

	cube[1308].position = D3DXVECTOR3(259.73f, -257.61f, 837.36f);
	cube[1308].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1308].scale = D3DXVECTOR3(5, 1, 7);

	cube[1309].position = D3DXVECTOR3(265.25f, -260.40f, 836.70f);
	cube[1309].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1309].scale = D3DXVECTOR3(3, 1, 10);

	cube[1310].position = D3DXVECTOR3(266.59f, -260.76f, 836.33f);
	cube[1310].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1310].scale = D3DXVECTOR3(3, 1, 7);

	cube[1311].position = D3DXVECTOR3(265.24f, -259.24f, 837.97f);
	cube[1311].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1311].scale = D3DXVECTOR3(3, 1, 10);

	cube[1312].position = D3DXVECTOR3(266.62f, -259.16f, 838.23f);
	cube[1312].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1312].scale = D3DXVECTOR3(5, 1, 7);

	cube[1313].position = D3DXVECTOR3(271.38f, -262.00f, 838.20f);
	cube[1313].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1313].scale = D3DXVECTOR3(3, 1, 10);

	cube[1314].position = D3DXVECTOR3(272.79f, -262.26f, 838.11f);
	cube[1314].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1314].scale = D3DXVECTOR3(3, 1, 7);

	cube[1315].position = D3DXVECTOR3(271.15f, -260.84f, 839.45f);
	cube[1315].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1315].scale = D3DXVECTOR3(3, 1, 10);

	cube[1316].position = D3DXVECTOR3(272.54f, -260.94f, 839.73f);
	cube[1316].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1316].scale = D3DXVECTOR3(5, 1, 7);

	cube[1317].position = D3DXVECTOR3(277.55f, -263.65f, 840.89f);
	cube[1317].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1317].scale = D3DXVECTOR3(3, 1, 10);

	cube[1318].position = D3DXVECTOR3(278.88f, -263.98f, 840.94f);
	cube[1318].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1318].scale = D3DXVECTOR3(3, 1, 7);

	cube[1319].position = D3DXVECTOR3(277.11f, -262.49f, 842.08f);
	cube[1319].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1319].scale = D3DXVECTOR3(3, 1, 10);

	cube[1320].position = D3DXVECTOR3(278.36f, -262.60f, 842.56f);
	cube[1320].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1320].scale = D3DXVECTOR3(5, 1, 7);

	cube[1321].position = D3DXVECTOR3(283.27f, -265.36f, 844.79f);
	cube[1321].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1321].scale = D3DXVECTOR3(3, 1, 10);

	cube[1322].position = D3DXVECTOR3(284.46f, -265.59f, 845.13f);
	cube[1322].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1322].scale = D3DXVECTOR3(3, 1, 7);

	cube[1323].position = D3DXVECTOR3(282.62f, -264.20f, 845.88f);
	cube[1323].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1323].scale = D3DXVECTOR3(3, 1, 10);

	cube[1324].position = D3DXVECTOR3(283.71f, -264.29f, 846.51f);
	cube[1324].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1324].scale = D3DXVECTOR3(5, 1, 7);

	cube[1325].position = D3DXVECTOR3(288.03f, -266.99f, 849.34f);
	cube[1325].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1325].scale = D3DXVECTOR3(3, 1, 10);

	cube[1326].position = D3DXVECTOR3(289.29f, -267.32f, 849.85f);
	cube[1326].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1326].scale = D3DXVECTOR3(3, 1, 7);

	cube[1327].position = D3DXVECTOR3(287.21f, -265.83f, 850.31f);
	cube[1327].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1327].scale = D3DXVECTOR3(3, 1, 10);

	cube[1328].position = D3DXVECTOR3(288.20f, -265.94f, 851.18f);
	cube[1328].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1328].scale = D3DXVECTOR3(5, 1, 7);

	cube[1329].position = D3DXVECTOR3(292.04f, -268.62f, 854.84f);
	cube[1329].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1329].scale = D3DXVECTOR3(3, 1, 10);

	cube[1330].position = D3DXVECTOR3(293.13f, -268.92f, 855.61f);
	cube[1330].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1330].scale = D3DXVECTOR3(3, 1, 7);

	cube[1331].position = D3DXVECTOR3(291.06f, -267.46f, 855.64f);
	cube[1331].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1331].scale = D3DXVECTOR3(3, 1, 10);

	cube[1332].position = D3DXVECTOR3(291.91f, -267.58f, 856.70f);
	cube[1332].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1332].scale = D3DXVECTOR3(5, 1, 7);

	cube[1333].position = D3DXVECTOR3(294.91f, -270.18f, 860.62f);
	cube[1333].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1333].scale = D3DXVECTOR3(3, 1, 10);

	cube[1334].position = D3DXVECTOR3(295.27f, -270.13f, 861.67f);
	cube[1334].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1334].scale = D3DXVECTOR3(3, 1, 7);

	cube[1335].position = D3DXVECTOR3(293.81f, -269.02f, 861.24f);
	cube[1335].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1335].scale = D3DXVECTOR3(3, 1, 10);

	cube[1336].position = D3DXVECTOR3(294.37f, -269.11f, 862.27f);
	cube[1336].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1336].scale = D3DXVECTOR3(5, 1, 7);

	cube[1337].position = D3DXVECTOR3(298.09f, -271.84f, 869.32f);
	cube[1337].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1337].scale = D3DXVECTOR3(3, 1, 10);

	cube[1338].position = D3DXVECTOR3(296.99f, -270.68f, 869.95f);
	cube[1338].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1338].scale = D3DXVECTOR3(3, 1, 10);

	cube[1339].position = D3DXVECTOR3(301.35f, -273.54f, 878.29f);
	cube[1339].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1339].scale = D3DXVECTOR3(3, 1, 10);

	cube[1340].position = D3DXVECTOR3(300.25f, -272.38f, 878.92f);
	cube[1340].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1340].scale = D3DXVECTOR3(3, 1, 10);

	cube[1341].position = D3DXVECTOR3(304.61f, -275.32f, 887.23f);
	cube[1341].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1341].scale = D3DXVECTOR3(3, 1, 10);

	cube[1342].position = D3DXVECTOR3(303.51f, -274.16f, 887.86f);
	cube[1342].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1342].scale = D3DXVECTOR3(3, 1, 10);

	cube[1343].position = D3DXVECTOR3(308.22f, -276.93f, 895.31f);
	cube[1343].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1343].scale = D3DXVECTOR3(3, 1, 10);

	cube[1344].position = D3DXVECTOR3(307.24f, -275.77f, 896.12f);
	cube[1344].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1344].scale = D3DXVECTOR3(3, 1, 10);

	cube[1345].position = D3DXVECTOR3(312.98f, -278.52f, 902.35f);
	cube[1345].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1345].scale = D3DXVECTOR3(3, 1, 10);

	cube[1346].position = D3DXVECTOR3(312.16f, -277.36f, 903.32f);
	cube[1346].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1346].scale = D3DXVECTOR3(3, 1, 10);

	cube[1347].position = D3DXVECTOR3(319.10f, -280.15f, 908.67f);
	cube[1347].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1347].scale = D3DXVECTOR3(3, 1, 10);

	cube[1348].position = D3DXVECTOR3(318.46f, -278.99f, 909.77f);
	cube[1348].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1348].scale = D3DXVECTOR3(3, 1, 10);

	cube[1349].position = D3DXVECTOR3(326.18f, -281.78f, 913.82f);
	cube[1349].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1349].scale = D3DXVECTOR3(3, 1, 10);

	cube[1350].position = D3DXVECTOR3(325.74f, -280.62f, 915.01f);
	cube[1350].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1350].scale = D3DXVECTOR3(3, 1, 10);

	cube[1351].position = D3DXVECTOR3(334.01f, -283.38f, 917.64f);
	cube[1351].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1351].scale = D3DXVECTOR3(3, 1, 10);

	cube[1352].position = D3DXVECTOR3(333.78f, -282.22f, 918.88f);
	cube[1352].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1352].scale = D3DXVECTOR3(3, 1, 10);

	cube[1353].position = D3DXVECTOR3(342.45f, -285.02f, 920.05f);
	cube[1353].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1353].scale = D3DXVECTOR3(3, 1, 10);

	cube[1354].position = D3DXVECTOR3(342.44f, -283.86f, 921.32f);
	cube[1354].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1354].scale = D3DXVECTOR3(3, 1, 10);

	cube[1355].position = D3DXVECTOR3(350.97f, -286.68f, 920.88f);
	cube[1355].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1355].scale = D3DXVECTOR3(3, 1, 10);

	cube[1356].position = D3DXVECTOR3(351.18f, -285.52f, 922.13f);
	cube[1356].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1356].scale = D3DXVECTOR3(3, 1, 10);

	cube[1357].position = D3DXVECTOR3(359.25f, -288.22f, 920.30f);
	cube[1357].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1357].scale = D3DXVECTOR3(3, 1, 10);

	cube[1358].position = D3DXVECTOR3(359.67f, -287.06f, 921.49f);
	cube[1358].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1358].scale = D3DXVECTOR3(3, 1, 10);

	cube[1359].position = D3DXVECTOR3(368.64f, -289.95f, 918.64f);
	cube[1359].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1359].scale = D3DXVECTOR3(3, 1, 10);

	cube[1360].position = D3DXVECTOR3(369.06f, -288.79f, 919.84f);
	cube[1360].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1360].scale = D3DXVECTOR3(3, 1, 10);

	cube[1361].position = D3DXVECTOR3(377.22f, -291.56f, 916.49f);
	cube[1361].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1361].scale = D3DXVECTOR3(3, 1, 10);

	cube[1362].position = D3DXVECTOR3(377.85f, -290.40f, 917.59f);
	cube[1362].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1362].scale = D3DXVECTOR3(3, 1, 10);

	cube[1363].position = D3DXVECTOR3(384.98f, -293.15f, 913.03f);
	cube[1363].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1363].scale = D3DXVECTOR3(3, 1, 10);

	cube[1364].position = D3DXVECTOR3(385.79f, -291.99f, 914.01f);
	cube[1364].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1364].scale = D3DXVECTOR3(3, 1, 10);

	cube[1365].position = D3DXVECTOR3(392.27f, -294.78f, 908.10f);
	cube[1365].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1365].scale = D3DXVECTOR3(3, 1, 10);

	cube[1366].position = D3DXVECTOR3(393.24f, -293.62f, 908.92f);
	cube[1366].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1366].scale = D3DXVECTOR3(3, 1, 10);

	cube[1367].position = D3DXVECTOR3(398.57f, -296.41f, 902.02f);
	cube[1367].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1367].scale = D3DXVECTOR3(3, 1, 10);

	cube[1368].position = D3DXVECTOR3(399.66f, -295.25f, 902.66f);
	cube[1368].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1368].scale = D3DXVECTOR3(3, 1, 10);

	cube[1369].position = D3DXVECTOR3(403.69f, -298.01f, 894.97f);
	cube[1369].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1369].scale = D3DXVECTOR3(3, 1, 10);

	cube[1370].position = D3DXVECTOR3(404.87f, -296.85f, 895.42f);
	cube[1370].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1370].scale = D3DXVECTOR3(3, 1, 10);

	cube[1371].position = D3DXVECTOR3(407.53f, -299.65f, 887.08f);
	cube[1371].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1371].scale = D3DXVECTOR3(3, 1, 10);

	cube[1372].position = D3DXVECTOR3(408.78f, -298.49f, 887.31f);
	cube[1372].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1372].scale = D3DXVECTOR3(3, 1, 10);

	cube[1373].position = D3DXVECTOR3(409.82f, -301.31f, 878.83f);
	cube[1373].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1373].scale = D3DXVECTOR3(3, 1, 10);

	cube[1374].position = D3DXVECTOR3(411.09f, -300.15f, 878.84f);
	cube[1374].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1374].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1375].position = D3DXVECTOR3(410.69f, -302.85f, 870.58f);
	cube[1375].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1375].scale = D3DXVECTOR3(3, 1, 10);

	cube[1376].position = D3DXVECTOR3(411.94f, -301.69f, 870.37f);
	cube[1376].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1376].scale = D3DXVECTOR3(3, 1, 10);

	cube[1377].position = D3DXVECTOR3(410.66f, -304.57f, 861.16f);
	cube[1377].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1377].scale = D3DXVECTOR3(3, 1, 10);

	cube[1378].position = D3DXVECTOR3(411.91f, -303.41f, 860.95f);
	cube[1378].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1378].scale = D3DXVECTOR3(3, 1, 10);

	cube[1379].position = D3DXVECTOR3(410.66f, -306.32f, 851.62f);
	cube[1379].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1379].scale = D3DXVECTOR3(3, 1, 10);

	cube[1380].position = D3DXVECTOR3(411.91f, -305.16f, 851.41f);
	cube[1380].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1380].scale = D3DXVECTOR3(3, 1, 10);

	cube[1381].position = D3DXVECTOR3(410.66f, -308.02f, 842.23f);
	cube[1381].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1381].scale = D3DXVECTOR3(3, 1, 10);

	cube[1382].position = D3DXVECTOR3(411.91f, -306.86f, 842.02f);
	cube[1382].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1382].scale = D3DXVECTOR3(3, 1, 10);

	cube[1383].position = D3DXVECTOR3(410.66f, -309.67f, 833.07f);
	cube[1383].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1383].scale = D3DXVECTOR3(3, 1, 10);

	cube[1384].position = D3DXVECTOR3(411.91f, -308.51f, 832.86f);
	cube[1384].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1384].scale = D3DXVECTOR3(3, 1, 10);

	cube[1385].position = D3DXVECTOR3(410.66f, -311.41f, 823.49f);
	cube[1385].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1385].scale = D3DXVECTOR3(3, 1, 10);

	cube[1386].position = D3DXVECTOR3(411.91f, -310.25f, 823.28f);
	cube[1386].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1386].scale = D3DXVECTOR3(3, 1, 10);

	cube[1387].position = D3DXVECTOR3(410.66f, -312.99f, 814.76f);
	cube[1387].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1387].scale = D3DXVECTOR3(3, 1, 10.00004);

	cube[1388].position = D3DXVECTOR3(411.91f, -311.83f, 814.55f);
	cube[1388].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1388].scale = D3DXVECTOR3(3, 1, 10);

	cube[1389].position = D3DXVECTOR3(410.61f, -314.60f, 805.80f);
	cube[1389].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1389].scale = D3DXVECTOR3(3, 1, 10);

	cube[1390].position = D3DXVECTOR3(411.86f, -313.44f, 805.59f);
	cube[1390].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1390].scale = D3DXVECTOR3(3, 1, 10);

	cube[1391].position = D3DXVECTOR3(410.61f, -316.35f, 796.26f);
	cube[1391].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1391].scale = D3DXVECTOR3(3, 1, 10);

	cube[1392].position = D3DXVECTOR3(411.86f, -315.19f, 796.05f);
	cube[1392].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1392].scale = D3DXVECTOR3(3, 1, 10);

	cube[1393].position = D3DXVECTOR3(410.61f, -318.05f, 786.87f);
	cube[1393].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1393].scale = D3DXVECTOR3(3, 1, 10);

	cube[1394].position = D3DXVECTOR3(411.86f, -316.89f, 786.66f);
	cube[1394].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1394].scale = D3DXVECTOR3(3, 1, 10);

	cube[1395].position = D3DXVECTOR3(410.61f, -319.70f, 777.71f);
	cube[1395].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1395].scale = D3DXVECTOR3(3, 1, 10);

	cube[1396].position = D3DXVECTOR3(411.86f, -318.54f, 777.50f);
	cube[1396].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1396].scale = D3DXVECTOR3(3, 1, 10);

	cube[1397].position = D3DXVECTOR3(410.61f, -321.44f, 768.13f);
	cube[1397].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1397].scale = D3DXVECTOR3(3, 1, 10);

	cube[1398].position = D3DXVECTOR3(411.86f, -320.28f, 767.92f);
	cube[1398].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1398].scale = D3DXVECTOR3(3, 1, 10);

	cube[1399].position = D3DXVECTOR3(410.61f, -323.03f, 759.41f);
	cube[1399].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1399].scale = D3DXVECTOR3(3, 1, 10);

	cube[1400].position = D3DXVECTOR3(411.86f, -321.87f, 759.19f);
	cube[1400].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1400].scale = D3DXVECTOR3(3, 1, 10);

	cube[1401].position = D3DXVECTOR3(410.00f, -324.71f, 750.74f);
	cube[1401].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1401].scale = D3DXVECTOR3(3, 1, 10);

	cube[1402].position = D3DXVECTOR3(411.20f, -323.55f, 750.32f);
	cube[1402].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1402].scale = D3DXVECTOR3(3, 1, 10);

	cube[1403].position = D3DXVECTOR3(407.94f, -326.30f, 742.50f);
	cube[1403].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1403].scale = D3DXVECTOR3(3, 1, 10);

	cube[1404].position = D3DXVECTOR3(409.04f, -325.14f, 741.87f);
	cube[1404].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1404].scale = D3DXVECTOR3(3, 1, 10);

	cube[1405].position = D3DXVECTOR3(404.35f, -327.93f, 734.47f);
	cube[1405].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1405].scale = D3DXVECTOR3(3, 1, 10);

	cube[1406].position = D3DXVECTOR3(405.33f, -326.77f, 733.66f);
	cube[1406].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1406].scale = D3DXVECTOR3(3, 1, 10);

	cube[1407].position = D3DXVECTOR3(399.46f, -329.56f, 727.21f);
	cube[1407].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1407].scale = D3DXVECTOR3(3, 1, 10);

	cube[1408].position = D3DXVECTOR3(400.28f, -328.40f, 726.24f);
	cube[1408].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1408].scale = D3DXVECTOR3(3, 1, 10);

	cube[1409].position = D3DXVECTOR3(393.50f, -331.24f, 720.11f);
	cube[1409].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1409].scale = D3DXVECTOR3(3, 1, 10);

	cube[1410].position = D3DXVECTOR3(394.32f, -330.08f, 719.14f);
	cube[1410].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1410].scale = D3DXVECTOR3(3, 1, 10);

	cube[1411].position = D3DXVECTOR3(389.39f, -332.93f, 714.42f);
	cube[1411].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1411].scale = D3DXVECTOR3(3, 1, 10);

	cube[1412].position = D3DXVECTOR3(388.57f, -333.11f, 713.83f);
	cube[1412].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1412].scale = D3DXVECTOR3(3, 1, 7);

	cube[1413].position = D3DXVECTOR3(390.37f, -331.77f, 713.62f);
	cube[1413].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1413].scale = D3DXVECTOR3(3, 1, 10);

	cube[1414].position = D3DXVECTOR3(389.73f, -331.80f, 712.81f);
	cube[1414].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 210.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1414].scale = D3DXVECTOR3(5, 1, 7);

	cube[1415].position = D3DXVECTOR3(386.40f, -334.59f, 708.37f);
	cube[1415].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1415].scale = D3DXVECTOR3(3, 1, 10);

	cube[1416].position = D3DXVECTOR3(385.40f, -334.95f, 707.39f);
	cube[1416].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 200.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1416].scale = D3DXVECTOR3(3, 1, 7);

	cube[1417].position = D3DXVECTOR3(387.50f, -333.43f, 707.74f);
	cube[1417].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1417].scale = D3DXVECTOR3(3, 1, 10);

	cube[1418].position = D3DXVECTOR3(387.04f, -333.35f, 706.42f);
	cube[1418].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 200.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1418].scale = D3DXVECTOR3(5, 1, 7);

	cube[1419].position = D3DXVECTOR3(384.63f, -336.19f, 702.31f);
	cube[1419].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1419].scale = D3DXVECTOR3(3, 1, 10);

	cube[1420].position = D3DXVECTOR3(383.84f, -336.45f, 701.13f);
	cube[1420].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 190.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1420].scale = D3DXVECTOR3(3, 1, 7);

	cube[1421].position = D3DXVECTOR3(385.82f, -335.03f, 701.88f);
	cube[1421].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1421].scale = D3DXVECTOR3(3, 1, 10);

	cube[1422].position = D3DXVECTOR3(385.37f, -335.13f, 700.54f);
	cube[1422].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 190.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1422].scale = D3DXVECTOR3(5, 1, 7);

	cube[1423].position = D3DXVECTOR3(383.88f, -337.84f, 695.62f);
	cube[1423].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1423].scale = D3DXVECTOR3(3, 1, 10);

	cube[1424].position = D3DXVECTOR3(383.25f, -338.17f, 694.44f);
	cube[1424].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1424].scale = D3DXVECTOR3(3, 1, 7);

	cube[1425].position = D3DXVECTOR3(385.13f, -336.68f, 695.41f);
	cube[1425].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1425].scale = D3DXVECTOR3(3, 1, 10);

	cube[1426].position = D3DXVECTOR3(384.91f, -336.79f, 694.09f);
	cube[1426].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1426].scale = D3DXVECTOR3(5, 1, 7);

	cube[1427].position = D3DXVECTOR3(383.87f, -339.50f, 686.29f);
	cube[1427].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1427].scale = D3DXVECTOR3(3, 1, 10);

	cube[1428].position = D3DXVECTOR3(385.12f, -338.34f, 686.08f);
	cube[1428].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1428].scale = D3DXVECTOR3(3, 1, 10);

	cube[1429].position = D3DXVECTOR3(383.87f, -341.19f, 676.84f);
	cube[1429].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1429].scale = D3DXVECTOR3(3, 1, 10);

	cube[1430].position = D3DXVECTOR3(385.12f, -340.03f, 676.63f);
	cube[1430].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1430].scale = D3DXVECTOR3(3, 1, 10);

	cube[1431].position = D3DXVECTOR3(383.88f, -342.74f, 668.40f);
	cube[1431].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1431].scale = D3DXVECTOR3(3, 1, 10);

	cube[1432].position = D3DXVECTOR3(385.13f, -341.58f, 668.19f);
	cube[1432].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1432].scale = D3DXVECTOR3(3, 1, 10);

	cube[1433].position = D3DXVECTOR3(384.38f, -344.43f, 661.41f);
	cube[1433].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1433].scale = D3DXVECTOR3(3, 1, 10);

	cube[1434].position = D3DXVECTOR3(384.14f, -344.61f, 660.42f);
	cube[1434].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 170.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1434].scale = D3DXVECTOR3(3, 1, 7);

	cube[1435].position = D3DXVECTOR3(385.65f, -343.27f, 661.42f);
	cube[1435].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1435].scale = D3DXVECTOR3(3, 1, 10);

	cube[1436].position = D3DXVECTOR3(385.68f, -343.30f, 660.39f);
	cube[1436].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 170.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1436].scale = D3DXVECTOR3(5, 1, 7);

	cube[1437].position = D3DXVECTOR3(385.99f, -346.09f, 654.84f);
	cube[1437].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1437].scale = D3DXVECTOR3(3, 1, 10);

	cube[1438].position = D3DXVECTOR3(385.85f, -346.45f, 653.45f);
	cube[1438].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 160.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1438].scale = D3DXVECTOR3(3, 1, 7);

	cube[1439].position = D3DXVECTOR3(387.23f, -344.93f, 655.07f);
	cube[1439].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1439].scale = D3DXVECTOR3(3, 1, 10);

	cube[1440].position = D3DXVECTOR3(387.73f, -344.85f, 653.76f);
	cube[1440].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 160.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1440].scale = D3DXVECTOR3(5, 1, 7);

	cube[1441].position = D3DXVECTOR3(388.53f, -347.69f, 649.07f);
	cube[1441].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1441].scale = D3DXVECTOR3(3, 1, 10);

	cube[1442].position = D3DXVECTOR3(388.68f, -347.95f, 647.66f);
	cube[1442].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1442].scale = D3DXVECTOR3(3, 1, 7);

	cube[1443].position = D3DXVECTOR3(389.71f, -346.53f, 649.51f);
	cube[1443].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1443].scale = D3DXVECTOR3(3, 1, 10);

	cube[1444].position = D3DXVECTOR3(390.23f, -346.63f, 648.19f);
	cube[1444].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 150.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1444].scale = D3DXVECTOR3(5, 1, 7);

	cube[1445].position = D3DXVECTOR3(392.25f, -349.34f, 643.45f);
	cube[1445].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1445].scale = D3DXVECTOR3(3, 1, 10);

	cube[1446].position = D3DXVECTOR3(392.53f, -349.67f, 642.15f);
	cube[1446].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1446].scale = D3DXVECTOR3(3, 1, 7);

	cube[1447].position = D3DXVECTOR3(393.34f, -348.18f, 644.10f);
	cube[1447].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1447].scale = D3DXVECTOR3(3, 1, 10);

	cube[1448].position = D3DXVECTOR3(394.03f, -348.29f, 642.95f);
	cube[1448].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1448].scale = D3DXVECTOR3(5, 1, 7);

	cube[1449].position = D3DXVECTOR3(398.39f, -351.06f, 636.11f);
	cube[1449].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1449].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1450].position = D3DXVECTOR3(399.49f, -349.90f, 636.75f);
	cube[1450].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1450].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1451].position = D3DXVECTOR3(404.44f, -352.76f, 628.90f);
	cube[1451].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1451].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1452].position = D3DXVECTOR3(405.54f, -351.60f, 629.54f);
	cube[1452].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1452].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1453].position = D3DXVECTOR3(410.56f, -354.49f, 621.60f);
	cube[1453].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1453].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1454].position = D3DXVECTOR3(411.66f, -353.33f, 622.24f);
	cube[1454].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1454].scale = D3DXVECTOR3(3, 1, 10.00002);

	cube[1455].position = D3DXVECTOR3(416.68f, -356.24f, 614.37f);
	cube[1455].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1455].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1456].position = D3DXVECTOR3(417.77f, -355.08f, 615.01f);
	cube[1456].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1456].scale = D3DXVECTOR3(3, 1, 10);

	cube[1457].position = D3DXVECTOR3(421.56f, -357.93f, 609.34f);
	cube[1457].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1457].scale = D3DXVECTOR3(3, 1, 10);

	cube[1458].position = D3DXVECTOR3(422.01f, -358.11f, 608.42f);
	cube[1458].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 130.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1458].scale = D3DXVECTOR3(3, 1, 7);

	cube[1459].position = D3DXVECTOR3(422.52f, -356.77f, 610.16f);
	cube[1459].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1459].scale = D3DXVECTOR3(3, 1, 10);

	cube[1460].position = D3DXVECTOR3(423.20f, -356.80f, 609.39f);
	cube[1460].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 130.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1460].scale = D3DXVECTOR3(5, 1, 7);

	cube[1461].position = D3DXVECTOR3(427.01f, -359.59f, 605.34f);
	cube[1461].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1461].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1462].position = D3DXVECTOR3(427.80f, -359.95f, 604.18f);
	cube[1462].rotation = D3DXVECTOR3(12.00f*3.141592f / 180, 120.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1462].scale = D3DXVECTOR3(3, 1, 7);

	cube[1463].position = D3DXVECTOR3(427.81f, -358.43f, 606.32f);
	cube[1463].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1463].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1464].position = D3DXVECTOR3(429.04f, -358.35f, 605.63f);
	cube[1464].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 120.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1464].scale = D3DXVECTOR3(5, 1, 7);

	cube[1465].position = D3DXVECTOR3(432.67f, -361.19f, 602.55f);
	cube[1465].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1465].scale = D3DXVECTOR3(3, 1, 10);

	cube[1466].position = D3DXVECTOR3(433.69f, -361.45f, 601.57f);
	cube[1466].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 110.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1466].scale = D3DXVECTOR3(3, 1, 7);

	cube[1467].position = D3DXVECTOR3(433.29f, -360.03f, 603.65f);
	cube[1467].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1467].scale = D3DXVECTOR3(3, 1, 10);

	cube[1468].position = D3DXVECTOR3(434.53f, -360.13f, 602.97f);
	cube[1468].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 110.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1468].scale = D3DXVECTOR3(5, 1, 7);

	cube[1469].position = D3DXVECTOR3(439.13f, -362.84f, 600.64f);
	cube[1469].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1469].scale = D3DXVECTOR3(3, 1, 10);

	cube[1470].position = D3DXVECTOR3(440.18f, -363.17f, 599.82f);
	cube[1470].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1470].scale = D3DXVECTOR3(3, 1, 7);

	cube[1471].position = D3DXVECTOR3(439.55f, -361.68f, 601.84f);
	cube[1471].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1471].scale = D3DXVECTOR3(3, 1, 10.00001);

	cube[1472].position = D3DXVECTOR3(440.81f, -361.79f, 601.40f);
	cube[1472].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 100.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1472].scale = D3DXVECTOR3(5, 1, 7);

	cube[1473].position = D3DXVECTOR3(446.01f, -364.55f, 599.95f);
	cube[1473].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1473].scale = D3DXVECTOR3(3, 1, 10);

	cube[1474].position = D3DXVECTOR3(447.14f, -364.78f, 599.44f);
	cube[1474].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1474].scale = D3DXVECTOR3(3, 1, 7);

	cube[1475].position = D3DXVECTOR3(446.22f, -363.39f, 601.20f);
	cube[1475].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1475].scale = D3DXVECTOR3(3, 1, 10);

	cube[1476].position = D3DXVECTOR3(447.45f, -363.48f, 600.98f);
	cube[1476].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 90.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1476].scale = D3DXVECTOR3(5, 1, 7);

	cube[1477].position = D3DXVECTOR3(452.59f, -366.18f, 600.37f);
	cube[1477].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1477].scale = D3DXVECTOR3(3, 1, 10);

	cube[1478].position = D3DXVECTOR3(453.87f, -366.51f, 599.96f);
	cube[1478].rotation = D3DXVECTOR3(13.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1478].scale = D3DXVECTOR3(3, 1, 7);

	cube[1479].position = D3DXVECTOR3(452.57f, -365.02f, 601.64f);
	cube[1479].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1479].scale = D3DXVECTOR3(3, 1, 10);

	cube[1480].position = D3DXVECTOR3(453.90f, -365.13f, 601.67f);
	cube[1480].rotation = D3DXVECTOR3(14.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1480].scale = D3DXVECTOR3(5, 1, 7);

	cube[1481].position = D3DXVECTOR3(461.71f, -367.88f, 601.95f);
	cube[1481].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1481].scale = D3DXVECTOR3(3, 1, 10);

	cube[1482].position = D3DXVECTOR3(461.70f, -366.72f, 603.22f);
	cube[1482].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1482].scale = D3DXVECTOR3(3, 1, 10);

	cube[1483].position = D3DXVECTOR3(471.26f, -369.64f, 603.63f);
	cube[1483].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1483].scale = D3DXVECTOR3(3, 1, 10);

	cube[1484].position = D3DXVECTOR3(471.25f, -368.48f, 604.90f);
	cube[1484].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1484].scale = D3DXVECTOR3(3, 1, 10);

	cube[1485].position = D3DXVECTOR3(480.64f, -371.36f, 605.29f);
	cube[1485].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1485].scale = D3DXVECTOR3(3, 1, 10);

	cube[1486].position = D3DXVECTOR3(480.63f, -370.20f, 606.56f);
	cube[1486].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1486].scale = D3DXVECTOR3(3, 1, 10);

	cube[1487].position = D3DXVECTOR3(490.08f, -373.09f, 606.95f);
	cube[1487].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1487].scale = D3DXVECTOR3(3, 1, 10);

	cube[1488].position = D3DXVECTOR3(490.07f, -371.93f, 608.22f);
	cube[1488].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1488].scale = D3DXVECTOR3(3, 1, 10);

	cube[1489].position = D3DXVECTOR3(497.77f, -374.48f, 608.35f);
	cube[1489].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1489].scale = D3DXVECTOR3(3, 1, 10);

	cube[1490].position = D3DXVECTOR3(497.76f, -373.32f, 609.61f);
	cube[1490].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1490].scale = D3DXVECTOR3(3, 1, 10);

	cube[1491].position = D3DXVECTOR3(507.32f, -376.22f, 610.02f);
	cube[1491].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1491].scale = D3DXVECTOR3(3, 1, 10);

	cube[1492].position = D3DXVECTOR3(507.31f, -375.06f, 611.28f);
	cube[1492].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1492].scale = D3DXVECTOR3(3, 1, 10);

	cube[1493].position = D3DXVECTOR3(516.61f, -377.90f, 611.66f);
	cube[1493].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1493].scale = D3DXVECTOR3(3, 1, 10);

	cube[1494].position = D3DXVECTOR3(516.60f, -376.74f, 612.92f);
	cube[1494].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1494].scale = D3DXVECTOR3(3, 1, 10);

	cube[1495].position = D3DXVECTOR3(526.02f, -379.61f, 613.32f);
	cube[1495].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1495].scale = D3DXVECTOR3(3, 1, 10);

	cube[1496].position = D3DXVECTOR3(526.01f, -378.45f, 614.58f);
	cube[1496].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1496].scale = D3DXVECTOR3(3, 1, 10);

	cube[1497].position = D3DXVECTOR3(535.41f, -381.32f, 614.98f);
	cube[1497].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1497].scale = D3DXVECTOR3(3, 1, 10);

	cube[1498].position = D3DXVECTOR3(535.40f, -380.16f, 616.24f);
	cube[1498].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1498].scale = D3DXVECTOR3(3, 1, 10);

	cube[1499].position = D3DXVECTOR3(544.77f, -383.02f, 616.63f);
	cube[1499].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1499].scale = D3DXVECTOR3(3, 1, 10);

	cube[1500].position = D3DXVECTOR3(544.76f, -381.86f, 617.89f);
	cube[1500].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1500].scale = D3DXVECTOR3(3, 1, 10);

	cube[1501].position = D3DXVECTOR3(553.88f, -384.73f, 618.25f);
	cube[1501].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1501].scale = D3DXVECTOR3(3, 1, 10);

	cube[1502].position = D3DXVECTOR3(553.87f, -383.57f, 619.51f);
	cube[1502].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1502].scale = D3DXVECTOR3(3, 1, 10);

	cube[1503].position = D3DXVECTOR3(563.43f, -386.49f, 619.93f);
	cube[1503].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1503].scale = D3DXVECTOR3(3, 1, 10);

	cube[1504].position = D3DXVECTOR3(563.42f, -385.33f, 621.19f);
	cube[1504].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1504].scale = D3DXVECTOR3(3, 1, 10);

	cube[1505].position = D3DXVECTOR3(572.81f, -388.21f, 621.59f);
	cube[1505].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1505].scale = D3DXVECTOR3(3, 1, 10);

	cube[1506].position = D3DXVECTOR3(572.80f, -387.05f, 622.85f);
	cube[1506].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1506].scale = D3DXVECTOR3(3, 1, 10);

	cube[1507].position = D3DXVECTOR3(582.25f, -389.94f, 623.25f);
	cube[1507].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1507].scale = D3DXVECTOR3(3, 1, 10);

	cube[1508].position = D3DXVECTOR3(582.24f, -388.78f, 624.51f);
	cube[1508].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1508].scale = D3DXVECTOR3(3, 1, 10);

	cube[1509].position = D3DXVECTOR3(589.94f, -391.32f, 624.64f);
	cube[1509].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1509].scale = D3DXVECTOR3(3, 1, 10);

	cube[1510].position = D3DXVECTOR3(589.93f, -390.16f, 625.91f);
	cube[1510].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1510].scale = D3DXVECTOR3(3, 1, 10);

	cube[1511].position = D3DXVECTOR3(599.49f, -393.06f, 626.31f);
	cube[1511].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1511].scale = D3DXVECTOR3(3, 1, 10);

	cube[1512].position = D3DXVECTOR3(599.48f, -391.90f, 627.58f);
	cube[1512].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1512].scale = D3DXVECTOR3(3, 1, 10);

	cube[1513].position = D3DXVECTOR3(608.78f, -394.74f, 627.95f);
	cube[1513].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1513].scale = D3DXVECTOR3(3, 1, 10);

	cube[1514].position = D3DXVECTOR3(608.77f, -393.58f, 629.22f);
	cube[1514].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1514].scale = D3DXVECTOR3(3, 1, 10);

	cube[1515].position = D3DXVECTOR3(618.19f, -396.45f, 629.61f);
	cube[1515].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1515].scale = D3DXVECTOR3(3, 1, 10);

	cube[1516].position = D3DXVECTOR3(618.18f, -395.29f, 630.88f);
	cube[1516].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1516].scale = D3DXVECTOR3(3, 1, 10);

	cube[1517].position = D3DXVECTOR3(627.58f, -398.16f, 631.27f);
	cube[1517].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1517].scale = D3DXVECTOR3(3, 1, 10);

	cube[1518].position = D3DXVECTOR3(627.57f, -397.00f, 632.54f);
	cube[1518].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1518].scale = D3DXVECTOR3(3, 1, 10);

	cube[1519].position = D3DXVECTOR3(636.94f, -399.86f, 632.92f);
	cube[1519].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);
	cube[1519].scale = D3DXVECTOR3(3, 1, 10);

	cube[1520].position = D3DXVECTOR3(636.93f, -398.70f, 634.19f);
	cube[1520].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 315.00f*3.141592f / 180);
	cube[1520].scale = D3DXVECTOR3(3, 1, 10);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

	rightWall[9].position = D3DXVECTOR3(8.30f, -20.96f, 84.04f);
	rightWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[9].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[10].position = D3DXVECTOR3(8.30f, -22.62f, 93.04f);
	rightWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[10].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[11].position = D3DXVECTOR3(8.30f, -24.21f, 101.74f);
	rightWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[11].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[12].position = D3DXVECTOR3(8.30f, -25.89f, 110.84f);
	rightWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[12].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[13].position = D3DXVECTOR3(8.30f, -27.68f, 120.24f);
	rightWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[13].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[14].position = D3DXVECTOR3(8.30f, -29.36f, 129.54f);
	rightWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[14].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[15].position = D3DXVECTOR3(8.30f, -31.15f, 139.24f);
	rightWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[15].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[16].position = D3DXVECTOR3(8.30f, -32.74f, 148.04f);
	rightWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[16].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[17].position = D3DXVECTOR3(8.30f, -34.11f, 155.66f);
	rightWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[17].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[18].position = D3DXVECTOR3(7.56f, -35.80f, 164.91f);
	rightWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[18].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[19].position = D3DXVECTOR3(5.17f, -37.46f, 173.89f);
	rightWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[19].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[20].position = D3DXVECTOR3(1.43f, -39.06f, 181.91f);
	rightWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[20].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[21].position = D3DXVECTOR3(-3.86f, -40.71f, 189.52f);
	rightWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[21].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[22].position = D3DXVECTOR3(-10.58f, -42.42f, 196.17f);
	rightWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[22].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[23].position = D3DXVECTOR3(-18.06f, -44.05f, 201.42f);
	rightWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[23].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[24].position = D3DXVECTOR3(-25.53f, -45.64f, 205.80f);
	rightWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[24].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[25].position = D3DXVECTOR3(-33.49f, -47.37f, 210.41f);
	rightWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[25].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[26].position = D3DXVECTOR3(-40.79f, -48.92f, 214.61f);
	rightWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[26].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[27].position = D3DXVECTOR3(-48.09f, -50.44f, 218.81f);
	rightWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[27].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[28].position = D3DXVECTOR3(-55.99f, -52.17f, 223.41f);
	rightWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[28].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[29].position = D3DXVECTOR3(-63.85f, -53.81f, 227.87f);
	rightWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[29].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[30].position = D3DXVECTOR3(-71.42f, -55.38f, 232.23f);
	rightWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[30].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[31].position = D3DXVECTOR3(-79.38f, -57.11f, 236.84f);
	rightWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[31].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[32].position = D3DXVECTOR3(-86.68f, -58.66f, 241.04f);
	rightWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[32].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[33].position = D3DXVECTOR3(-93.98f, -60.18f, 245.24f);
	rightWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[33].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[34].position = D3DXVECTOR3(-101.88f, -61.91f, 249.84f);
	rightWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[34].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[35].position = D3DXVECTOR3(-109.74f, -63.55f, 254.31f);
	rightWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[35].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[36].position = D3DXVECTOR3(-118.24f, -65.25f, 258.28f);
	rightWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[36].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[37].position = D3DXVECTOR3(-127.22f, -66.91f, 260.70f);
	rightWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[37].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[38].position = D3DXVECTOR3(-136.03f, -68.51f, 261.47f);
	rightWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[38].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[39].position = D3DXVECTOR3(-145.27f, -70.16f, 260.69f);
	rightWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[39].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[40].position = D3DXVECTOR3(-151.93f, -71.46f, 259.50f);
	rightWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[40].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[41].position = D3DXVECTOR3(-159.17f, -73.24f, 258.95f);
	rightWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[41].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[42].position = D3DXVECTOR3(-165.11f, -74.83f, 259.63f);
	rightWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[42].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[43].position = D3DXVECTOR3(-171.09f, -76.46f, 261.41f);
	rightWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[43].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[44].position = D3DXVECTOR3(-176.67f, -78.09f, 264.17f);
	rightWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[44].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[45].position = D3DXVECTOR3(-181.60f, -79.69f, 267.81f);
	rightWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[45].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[46].position = D3DXVECTOR3(-185.89f, -81.32f, 272.32f);
	rightWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[46].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[47].position = D3DXVECTOR3(-189.18f, -82.98f, 277.40f);
	rightWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[47].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[48].position = D3DXVECTOR3(-191.56f, -84.56f, 282.92f);
	rightWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[48].scale = D3DXVECTOR3(5, 1, 7.5);

	rightWall[49].position = D3DXVECTOR3(-193.63f, -85.72f, 288.50f);
	rightWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[49].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[50].position = D3DXVECTOR3(-195.44f, -87.50f, 295.53f);
	rightWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[50].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[51].position = D3DXVECTOR3(-195.80f, -89.09f, 301.50f);
	rightWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[51].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[52].position = D3DXVECTOR3(-195.09f, -90.72f, 307.70f);
	rightWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[52].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[53].position = D3DXVECTOR3(-193.33f, -92.35f, 313.67f);
	rightWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[53].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[54].position = D3DXVECTOR3(-190.61f, -93.95f, 319.16f);
	rightWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[54].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[55].position = D3DXVECTOR3(-186.91f, -95.58f, 324.17f);
	rightWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[55].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[56].position = D3DXVECTOR3(-182.48f, -97.24f, 328.29f);
	rightWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[56].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[57].position = D3DXVECTOR3(-177.45f, -98.82f, 331.59f);
	rightWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[57].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[58].position = D3DXVECTOR3(-170.76f, -100.30f, 335.47f);
	rightWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[58].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[59].position = D3DXVECTOR3(-162.68f, -102.00f, 340.14f);
	rightWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[59].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[60].position = D3DXVECTOR3(-154.18f, -103.75f, 345.07f);
	rightWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[60].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[61].position = D3DXVECTOR3(-146.12f, -105.41f, 349.79f);
	rightWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[61].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[62].position = D3DXVECTOR3(-139.50f, -107.19f, 352.80f);
	rightWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[62].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[63].position = D3DXVECTOR3(-133.69f, -108.78f, 354.19f);
	rightWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[63].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[64].position = D3DXVECTOR3(-127.46f, -110.41f, 354.56f);
	rightWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[64].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[65].position = D3DXVECTOR3(-121.28f, -112.04f, 353.87f);
	rightWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[65].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[66].position = D3DXVECTOR3(-112.95f, -113.57f, 352.40f);
	rightWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[66].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[67].position = D3DXVECTOR3(-103.43f, -115.26f, 351.60f);
	rightWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[67].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[68].position = D3DXVECTOR3(-94.17f, -116.92f, 352.40f);
	rightWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[68].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[69].position = D3DXVECTOR3(-85.63f, -118.52f, 354.68f);
	rightWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[69].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[70].position = D3DXVECTOR3(-77.21f, -120.17f, 358.58f);
	rightWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[70].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[71].position = D3DXVECTOR3(-69.29f, -121.84f, 363.17f);
	rightWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[71].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[72].position = D3DXVECTOR3(-62.67f, -123.62f, 366.18f);
	rightWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[72].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[73].position = D3DXVECTOR3(-56.86f, -125.21f, 367.57f);
	rightWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[73].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[74].position = D3DXVECTOR3(-50.63f, -126.84f, 367.94f);
	rightWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[74].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[75].position = D3DXVECTOR3(-44.45f, -128.47f, 367.25f);
	rightWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[75].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[76].position = D3DXVECTOR3(-36.27f, -130.02f, 365.85f);
	rightWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[76].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[77].position = D3DXVECTOR3(-26.75f, -131.71f, 365.05f);
	rightWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[77].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[78].position = D3DXVECTOR3(-17.49f, -133.37f, 365.85f);
	rightWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[78].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[79].position = D3DXVECTOR3(-8.95f, -134.97f, 368.13f);
	rightWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[79].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[80].position = D3DXVECTOR3(-0.53f, -136.62f, 372.03f);
	rightWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[80].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[81].position = D3DXVECTOR3(7.79f, -138.36f, 376.81f);
	rightWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[81].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[82].position = D3DXVECTOR3(15.82f, -140.05f, 381.46f);
	rightWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[82].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[83].position = D3DXVECTOR3(24.08f, -141.77f, 386.22f);
	rightWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[83].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[84].position = D3DXVECTOR3(32.20f, -143.47f, 390.89f);
	rightWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[84].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[85].position = D3DXVECTOR3(40.30f, -145.14f, 395.55f);
	rightWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[85].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[86].position = D3DXVECTOR3(48.60f, -146.84f, 400.33f);
	rightWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[86].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[87].position = D3DXVECTOR3(56.18f, -148.41f, 404.65f);
	rightWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[87].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[88].position = D3DXVECTOR3(64.50f, -150.17f, 409.45f);
	rightWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[88].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[89].position = D3DXVECTOR3(72.53f, -151.86f, 414.10f);
	rightWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[89].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[90].position = D3DXVECTOR3(80.79f, -153.58f, 418.86f);
	rightWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[90].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[91].position = D3DXVECTOR3(88.91f, -155.28f, 423.53f);
	rightWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[91].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[92].position = D3DXVECTOR3(97.01f, -156.95f, 428.19f);
	rightWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[92].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[93].position = D3DXVECTOR3(105.31f, -158.65f, 432.97f);
	rightWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[93].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[94].position = D3DXVECTOR3(112.89f, -160.22f, 437.29f);
	rightWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[94].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[95].position = D3DXVECTOR3(120.06f, -161.80f, 442.34f);
	rightWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[95].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[96].position = D3DXVECTOR3(126.64f, -163.46f, 448.90f);
	rightWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[96].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[97].position = D3DXVECTOR3(131.72f, -165.06f, 456.15f);
	rightWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[97].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[98].position = D3DXVECTOR3(135.66f, -166.71f, 464.54f);
	rightWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[98].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[99].position = D3DXVECTOR3(138.89f, -168.40f, 473.39f);
	rightWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[99].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[100].position = D3DXVECTOR3(141.97f, -170.06f, 481.86f);
	rightWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[100].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[101].position = D3DXVECTOR3(145.10f, -171.71f, 490.31f);
	rightWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[101].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[102].position = D3DXVECTOR3(147.54f, -173.40f, 499.54f);
	rightWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[102].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[103].position = D3DXVECTOR3(148.36f, -175.06f, 508.80f);
	rightWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[103].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[104].position = D3DXVECTOR3(147.59f, -176.66f, 517.62f);
	rightWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[104].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[105].position = D3DXVECTOR3(145.22f, -178.31f, 526.58f);
	rightWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[105].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[106].position = D3DXVECTOR3(141.90f, -180.04f, 535.65f);
	rightWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[106].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[107].position = D3DXVECTOR3(138.77f, -181.70f, 544.17f);
	rightWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[107].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[108].position = D3DXVECTOR3(136.97f, -183.48f, 551.21f);
	rightWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[108].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[109].position = D3DXVECTOR3(136.60f, -185.07f, 557.17f);
	rightWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[109].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[110].position = D3DXVECTOR3(137.32f, -186.70f, 563.37f);
	rightWall[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[110].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[111].position = D3DXVECTOR3(139.07f, -188.33f, 569.34f);
	rightWall[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[111].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[112].position = D3DXVECTOR3(141.88f, -189.83f, 577.07f);
	rightWall[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[112].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[113].position = D3DXVECTOR3(144.32f, -191.52f, 586.30f);
	rightWall[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[113].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[114].position = D3DXVECTOR3(145.14f, -193.18f, 595.56f);
	rightWall[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[114].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[115].position = D3DXVECTOR3(144.37f, -194.78f, 604.38f);
	rightWall[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[115].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[116].position = D3DXVECTOR3(142.00f, -196.43f, 613.34f);
	rightWall[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[116].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[117].position = D3DXVECTOR3(138.77f, -198.13f, 622.23f);
	rightWall[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[117].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[118].position = D3DXVECTOR3(135.52f, -199.85f, 631.18f);
	rightWall[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[118].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[119].position = D3DXVECTOR3(132.39f, -201.50f, 639.74f);
	rightWall[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[119].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[120].position = D3DXVECTOR3(130.59f, -203.28f, 646.78f);
	rightWall[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[120].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[121].position = D3DXVECTOR3(130.22f, -204.87f, 652.74f);
	rightWall[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[121].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[122].position = D3DXVECTOR3(130.94f, -206.50f, 658.94f);
	rightWall[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[122].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[123].position = D3DXVECTOR3(132.69f, -208.13f, 664.91f);
	rightWall[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[123].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[124].position = D3DXVECTOR3(135.60f, -209.70f, 673.00f);
	rightWall[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[124].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[125].position = D3DXVECTOR3(138.88f, -211.43f, 682.00f);
	rightWall[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[125].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[126].position = D3DXVECTOR3(142.10f, -213.12f, 690.84f);
	rightWall[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[126].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[127].position = D3DXVECTOR3(145.27f, -214.80f, 699.57f);
	rightWall[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[127].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[128].position = D3DXVECTOR3(148.43f, -216.48f, 708.24f);
	rightWall[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[128].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[129].position = D3DXVECTOR3(151.67f, -218.22f, 717.17f);
	rightWall[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[129].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[130].position = D3DXVECTOR3(154.90f, -219.92f, 726.05f);
	rightWall[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[130].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[131].position = D3DXVECTOR3(158.07f, -221.62f, 734.85f);
	rightWall[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[131].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[132].position = D3DXVECTOR3(161.01f, -223.14f, 742.88f);
	rightWall[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[132].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[133].position = D3DXVECTOR3(164.29f, -224.87f, 751.88f);
	rightWall[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[133].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[134].position = D3DXVECTOR3(167.51f, -226.56f, 760.72f);
	rightWall[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[134].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[135].position = D3DXVECTOR3(170.68f, -228.24f, 769.45f);
	rightWall[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[135].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[136].position = D3DXVECTOR3(173.84f, -229.92f, 778.12f);
	rightWall[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[136].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[137].position = D3DXVECTOR3(177.08f, -231.66f, 787.05f);
	rightWall[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[137].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[138].position = D3DXVECTOR3(180.31f, -233.36f, 795.93f);
	rightWall[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[138].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[139].position = D3DXVECTOR3(183.48f, -235.06f, 804.72f);
	rightWall[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[139].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[140].position = D3DXVECTOR3(186.56f, -236.82f, 811.03f);
	rightWall[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[140].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[141].position = D3DXVECTOR3(190.12f, -238.41f, 815.83f);
	rightWall[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[141].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[142].position = D3DXVECTOR3(194.65f, -240.04f, 820.12f);
	rightWall[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[142].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[143].position = D3DXVECTOR3(199.83f, -241.67f, 823.57f);
	rightWall[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[143].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[144].position = D3DXVECTOR3(205.45f, -243.27f, 826.03f);
	rightWall[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[144].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[145].position = D3DXVECTOR3(211.51f, -244.90f, 827.48f);
	rightWall[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[145].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[146].position = D3DXVECTOR3(217.55f, -246.56f, 827.80f);
	rightWall[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[146].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[147].position = D3DXVECTOR3(223.52f, -248.14f, 827.09f);
	rightWall[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[147].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[148].position = D3DXVECTOR3(231.54f, -249.61f, 825.68f);
	rightWall[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[148].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[149].position = D3DXVECTOR3(240.87f, -251.30f, 824.04f);
	rightWall[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[149].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[150].position = D3DXVECTOR3(249.78f, -252.92f, 822.50f);
	rightWall[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[150].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[151].position = D3DXVECTOR3(259.30f, -254.61f, 821.70f);
	rightWall[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[151].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[152].position = D3DXVECTOR3(268.56f, -256.27f, 822.49f);
	rightWall[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[152].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[153].position = D3DXVECTOR3(277.10f, -257.87f, 824.78f);
	rightWall[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[153].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[154].position = D3DXVECTOR3(285.52f, -259.52f, 828.67f);
	rightWall[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[154].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[155].position = D3DXVECTOR3(293.24f, -261.23f, 834.13f);
	rightWall[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[155].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[156].position = D3DXVECTOR3(299.70f, -262.86f, 840.58f);
	rightWall[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[156].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[157].position = D3DXVECTOR3(305.05f, -264.49f, 848.24f);
	rightWall[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[157].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[158].position = D3DXVECTOR3(308.88f, -266.05f, 856.38f);
	rightWall[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[158].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[159].position = D3DXVECTOR3(312.05f, -267.72f, 865.08f);
	rightWall[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[159].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[160].position = D3DXVECTOR3(315.31f, -269.42f, 874.05f);
	rightWall[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[160].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[161].position = D3DXVECTOR3(318.57f, -271.19f, 882.99f);
	rightWall[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[161].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[162].position = D3DXVECTOR3(321.71f, -272.97f, 889.54f);
	rightWall[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[162].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[163].position = D3DXVECTOR3(325.27f, -274.56f, 894.34f);
	rightWall[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[163].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[164].position = D3DXVECTOR3(329.80f, -276.19f, 898.63f);
	rightWall[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[164].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[165].position = D3DXVECTOR3(334.98f, -277.82f, 902.08f);
	rightWall[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[165].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[166].position = D3DXVECTOR3(340.60f, -279.42f, 904.54f);
	rightWall[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[166].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[167].position = D3DXVECTOR3(346.66f, -281.05f, 905.99f);
	rightWall[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[167].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[168].position = D3DXVECTOR3(352.70f, -282.71f, 906.31f);
	rightWall[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[168].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[169].position = D3DXVECTOR3(358.67f, -284.29f, 905.60f);
	rightWall[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[169].scale = D3DXVECTOR3(5, 1, 7.500003);

	rightWall[170].position = D3DXVECTOR3(366.89f, -285.82f, 904.16f);
	rightWall[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[170].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[171].position = D3DXVECTOR3(373.88f, -287.60f, 902.20f);
	rightWall[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[171].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[172].position = D3DXVECTOR3(379.23f, -289.19f, 899.53f);
	rightWall[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[172].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[173].position = D3DXVECTOR3(384.24f, -290.82f, 895.82f);
	rightWall[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[173].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[174].position = D3DXVECTOR3(388.54f, -292.45f, 891.31f);
	rightWall[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[174].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[175].position = D3DXVECTOR3(391.93f, -294.05f, 886.20f);
	rightWall[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[175].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[176].position = D3DXVECTOR3(394.42f, -295.68f, 880.50f);
	rightWall[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[176].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[177].position = D3DXVECTOR3(395.77f, -297.34f, 874.60f);
	rightWall[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[177].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[178].position = D3DXVECTOR3(396.12f, -298.92f, 868.60f);
	rightWall[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[178].scale = D3DXVECTOR3(5, 1, 7.500008);

	rightWall[179].position = D3DXVECTOR3(396.09f, -300.44f, 860.37f);
	rightWall[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[179].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[180].position = D3DXVECTOR3(396.09f, -302.19f, 850.83f);
	rightWall[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[180].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[181].position = D3DXVECTOR3(396.09f, -303.89f, 841.44f);
	rightWall[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[181].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[182].position = D3DXVECTOR3(396.09f, -305.54f, 832.28f);
	rightWall[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[182].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[183].position = D3DXVECTOR3(396.09f, -307.28f, 822.70f);
	rightWall[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[183].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[184].position = D3DXVECTOR3(396.09f, -308.86f, 813.97f);
	rightWall[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[184].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[185].position = D3DXVECTOR3(396.04f, -310.48f, 805.01f);
	rightWall[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[185].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[186].position = D3DXVECTOR3(396.04f, -312.23f, 795.47f);
	rightWall[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[186].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[187].position = D3DXVECTOR3(396.04f, -313.93f, 786.08f);
	rightWall[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[187].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[188].position = D3DXVECTOR3(396.04f, -315.58f, 776.92f);
	rightWall[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[188].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[189].position = D3DXVECTOR3(396.04f, -317.32f, 767.34f);
	rightWall[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[189].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[190].position = D3DXVECTOR3(396.04f, -318.90f, 758.61f);
	rightWall[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[190].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[191].position = D3DXVECTOR3(395.35f, -320.75f, 751.55f);
	rightWall[191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[191].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[192].position = D3DXVECTOR3(393.65f, -322.34f, 745.82f);
	rightWall[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[192].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[193].position = D3DXVECTOR3(390.86f, -323.97f, 740.24f);
	rightWall[193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[193].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[194].position = D3DXVECTOR3(387.17f, -325.60f, 735.23f);
	rightWall[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[194].scale = D3DXVECTOR3(5, 1, 8);

	rightWall[195].position = D3DXVECTOR3(381.83f, -327.11f, 728.87f);
	rightWall[195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[195].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[196].position = D3DXVECTOR3(376.38f, -328.80f, 721.02f);
	rightWall[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[196].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[197].position = D3DXVECTOR3(372.44f, -330.46f, 712.61f);
	rightWall[197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[197].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[198].position = D3DXVECTOR3(370.15f, -332.06f, 704.06f);
	rightWall[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[198].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[199].position = D3DXVECTOR3(369.31f, -333.71f, 694.83f);
	rightWall[199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[199].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[200].position = D3DXVECTOR3(369.30f, -335.37f, 685.50f);
	rightWall[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[200].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[201].position = D3DXVECTOR3(369.30f, -337.06f, 676.05f);
	rightWall[201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[201].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[202].position = D3DXVECTOR3(369.31f, -338.61f, 667.61f);
	rightWall[202].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[202].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[203].position = D3DXVECTOR3(370.17f, -340.30f, 658.10f);
	rightWall[203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[203].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[204].position = D3DXVECTOR3(372.57f, -341.96f, 649.12f);
	rightWall[204].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[204].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[205].position = D3DXVECTOR3(376.30f, -343.56f, 641.10f);
	rightWall[205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[205].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[206].position = D3DXVECTOR3(381.60f, -345.21f, 633.48f);
	rightWall[206].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[206].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[207].position = D3DXVECTOR3(387.74f, -346.93f, 626.14f);
	rightWall[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[207].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[208].position = D3DXVECTOR3(393.79f, -348.63f, 618.93f);
	rightWall[208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[208].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[209].position = D3DXVECTOR3(399.91f, -350.36f, 611.63f);
	rightWall[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[209].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[210].position = D3DXVECTOR3(406.02f, -352.11f, 604.40f);
	rightWall[210].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[210].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[211].position = D3DXVECTOR3(412.80f, -353.80f, 597.67f);
	rightWall[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[211].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[212].position = D3DXVECTOR3(420.41f, -355.46f, 592.33f);
	rightWall[212].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[212].scale = D3DXVECTOR3(5, 1, 10.00002);

	rightWall[213].position = D3DXVECTOR3(428.42f, -357.06f, 588.59f);
	rightWall[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[213].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[214].position = D3DXVECTOR3(437.37f, -358.71f, 586.16f);
	rightWall[214].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[214].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[215].position = D3DXVECTOR3(446.80f, -360.42f, 585.38f);
	rightWall[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[215].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[216].position = D3DXVECTOR3(455.89f, -362.05f, 586.16f);
	rightWall[216].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[216].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[217].position = D3DXVECTOR3(465.01f, -363.76f, 587.74f);
	rightWall[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[217].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[218].position = D3DXVECTOR3(474.56f, -365.52f, 589.42f);
	rightWall[218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[218].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[219].position = D3DXVECTOR3(483.94f, -367.24f, 591.08f);
	rightWall[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[219].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[220].position = D3DXVECTOR3(491.68f, -368.64f, 592.47f);
	rightWall[220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[220].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[221].position = D3DXVECTOR3(501.08f, -370.35f, 594.14f);
	rightWall[221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[221].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[222].position = D3DXVECTOR3(510.63f, -372.09f, 595.81f);
	rightWall[222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[222].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[223].position = D3DXVECTOR3(519.92f, -373.77f, 597.45f);
	rightWall[223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[223].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[224].position = D3DXVECTOR3(529.33f, -375.48f, 599.11f);
	rightWall[224].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[224].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[225].position = D3DXVECTOR3(538.72f, -377.19f, 600.77f);
	rightWall[225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[225].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[226].position = D3DXVECTOR3(548.08f, -378.89f, 602.42f);
	rightWall[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[226].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[227].position = D3DXVECTOR3(557.18f, -380.60f, 604.04f);
	rightWall[227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[227].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[228].position = D3DXVECTOR3(566.73f, -382.36f, 605.72f);
	rightWall[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[228].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[229].position = D3DXVECTOR3(576.11f, -384.08f, 607.38f);
	rightWall[229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[229].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[230].position = D3DXVECTOR3(583.85f, -385.48f, 608.76f);
	rightWall[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[230].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[231].position = D3DXVECTOR3(593.25f, -387.19f, 610.43f);
	rightWall[231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[231].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[232].position = D3DXVECTOR3(602.80f, -388.93f, 612.10f);
	rightWall[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[232].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[233].position = D3DXVECTOR3(612.09f, -390.61f, 613.74f);
	rightWall[233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[233].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[234].position = D3DXVECTOR3(621.50f, -392.32f, 615.40f);
	rightWall[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[234].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[235].position = D3DXVECTOR3(630.89f, -394.03f, 617.06f);
	rightWall[235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[235].scale = D3DXVECTOR3(5, 1, 10);

	rightWall[236].position = D3DXVECTOR3(640.25f, -395.73f, 618.71f);
	rightWall[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 85.00f*3.141592f / 180);
	rightWall[236].scale = D3DXVECTOR3(5, 1, 10);

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

	leftWall[9].position = D3DXVECTOR3(-8.76f, -21.19f, 83.98f);
	leftWall[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[9].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[10].position = D3DXVECTOR3(-8.76f, -22.85f, 92.98f);
	leftWall[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[10].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[11].position = D3DXVECTOR3(-8.76f, -24.44f, 101.68f);
	leftWall[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[11].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[12].position = D3DXVECTOR3(-8.76f, -26.12f, 110.78f);
	leftWall[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[12].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[13].position = D3DXVECTOR3(-8.76f, -27.91f, 120.18f);
	leftWall[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[13].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[14].position = D3DXVECTOR3(-8.76f, -29.59f, 129.48f);
	leftWall[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[14].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[15].position = D3DXVECTOR3(-8.76f, -31.38f, 139.18f);
	leftWall[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[15].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[16].position = D3DXVECTOR3(-8.76f, -32.97f, 147.98f);
	leftWall[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[16].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[17].position = D3DXVECTOR3(-8.76f, -34.34f, 155.60f);
	leftWall[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[17].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[18].position = D3DXVECTOR3(-9.40f, -36.20f, 162.82f);
	leftWall[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[18].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[19].position = D3DXVECTOR3(-11.16f, -37.85f, 168.86f);
	leftWall[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[19].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[20].position = D3DXVECTOR3(-13.79f, -39.46f, 174.15f);
	leftWall[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[20].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[21].position = D3DXVECTOR3(-17.50f, -41.10f, 179.23f);
	leftWall[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[21].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[22].position = D3DXVECTOR3(-22.23f, -42.82f, 183.67f);
	leftWall[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[22].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[23].position = D3DXVECTOR3(-27.34f, -44.44f, 187.09f);
	leftWall[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[23].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[24].position = D3DXVECTOR3(-34.01f, -45.87f, 190.99f);
	leftWall[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[24].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[25].position = D3DXVECTOR3(-41.97f, -47.60f, 195.60f);
	leftWall[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[25].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[26].position = D3DXVECTOR3(-49.27f, -49.15f, 199.80f);
	leftWall[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[26].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[27].position = D3DXVECTOR3(-56.57f, -50.67f, 204.00f);
	leftWall[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[27].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[28].position = D3DXVECTOR3(-64.47f, -52.40f, 208.60f);
	leftWall[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[28].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[29].position = D3DXVECTOR3(-72.33f, -54.04f, 213.07f);
	leftWall[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[29].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[30].position = D3DXVECTOR3(-79.90f, -55.61f, 217.43f);
	leftWall[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[30].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[31].position = D3DXVECTOR3(-87.86f, -57.34f, 222.04f);
	leftWall[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[31].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[32].position = D3DXVECTOR3(-95.16f, -58.89f, 226.24f);
	leftWall[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[32].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[33].position = D3DXVECTOR3(-102.46f, -60.41f, 230.44f);
	leftWall[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[33].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[34].position = D3DXVECTOR3(-110.36f, -62.14f, 235.04f);
	leftWall[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[34].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[35].position = D3DXVECTOR3(-118.22f, -63.78f, 239.50f);
	leftWall[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[35].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[36].position = D3DXVECTOR3(-124.91f, -65.65f, 242.55f);
	leftWall[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[36].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[37].position = D3DXVECTOR3(-131.02f, -67.30f, 244.04f);
	leftWall[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[37].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[38].position = D3DXVECTOR3(-136.92f, -68.91f, 244.41f);
	leftWall[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[38].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[39].position = D3DXVECTOR3(-143.17f, -70.55f, 243.74f);
	leftWall[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[39].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[40].position = D3DXVECTOR3(-148.91f, -71.69f, 242.71f);
	leftWall[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 260.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[40].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[41].position = D3DXVECTOR3(-158.15f, -73.30f, 241.89f);
	leftWall[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 270.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[41].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[42].position = D3DXVECTOR3(-167.05f, -74.89f, 242.65f);
	leftWall[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 280.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[42].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[43].position = D3DXVECTOR3(-175.97f, -76.52f, 245.03f);
	leftWall[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 290.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[43].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[44].position = D3DXVECTOR3(-184.31f, -78.15f, 248.89f);
	leftWall[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[44].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[45].position = D3DXVECTOR3(-191.81f, -79.75f, 254.11f);
	leftWall[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 310.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[45].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[46].position = D3DXVECTOR3(-198.34f, -81.39f, 260.61f);
	leftWall[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 320.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[46].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[47].position = D3DXVECTOR3(-203.46f, -83.05f, 268.00f);
	leftWall[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 330.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[47].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[48].position = D3DXVECTOR3(-207.17f, -84.59f, 275.91f);
	leftWall[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[48].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[49].position = D3DXVECTOR3(-209.64f, -85.95f, 282.60f);
	leftWall[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[49].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[50].position = D3DXVECTOR3(-212.06f, -87.56f, 291.56f);
	leftWall[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[50].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[51].position = D3DXVECTOR3(-212.85f, -89.15f, 300.46f);
	leftWall[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[51].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[52].position = D3DXVECTOR3(-212.06f, -90.78f, 309.66f);
	leftWall[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[52].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[53].position = D3DXVECTOR3(-209.71f, -92.41f, 318.54f);
	leftWall[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[53].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[54].position = D3DXVECTOR3(-205.87f, -94.01f, 326.83f);
	leftWall[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[54].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[55].position = D3DXVECTOR3(-200.60f, -95.65f, 334.39f);
	leftWall[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[55].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[56].position = D3DXVECTOR3(-194.21f, -97.31f, 340.72f);
	leftWall[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[56].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[57].position = D3DXVECTOR3(-187.07f, -98.85f, 345.74f);
	leftWall[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[57].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[58].position = D3DXVECTOR3(-179.34f, -100.53f, 350.22f);
	leftWall[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[58].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[59].position = D3DXVECTOR3(-171.26f, -102.23f, 354.89f);
	leftWall[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[59].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[60].position = D3DXVECTOR3(-162.76f, -103.98f, 359.82f);
	leftWall[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[60].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[61].position = D3DXVECTOR3(-154.70f, -105.64f, 364.54f);
	leftWall[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[61].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[62].position = D3DXVECTOR3(-146.30f, -107.25f, 368.48f);
	leftWall[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[62].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[63].position = D3DXVECTOR3(-137.67f, -108.84f, 370.80f);
	leftWall[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[63].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[64].position = D3DXVECTOR3(-128.48f, -110.47f, 371.62f);
	leftWall[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[64].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[65].position = D3DXVECTOR3(-119.33f, -112.10f, 370.85f);
	leftWall[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[65].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[66].position = D3DXVECTOR3(-110.05f, -113.80f, 369.21f);
	leftWall[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[66].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[67].position = D3DXVECTOR3(-102.55f, -115.66f, 368.66f);
	leftWall[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[67].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[68].position = D3DXVECTOR3(-96.30f, -117.31f, 369.35f);
	leftWall[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[68].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[69].position = D3DXVECTOR3(-90.63f, -118.92f, 371.02f);
	leftWall[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[69].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[70].position = D3DXVECTOR3(-84.98f, -120.56f, 373.79f);
	leftWall[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[70].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[71].position = D3DXVECTOR3(-77.87f, -122.07f, 377.92f);
	leftWall[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[71].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[72].position = D3DXVECTOR3(-69.47f, -123.68f, 381.86f);
	leftWall[72].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[72].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[73].position = D3DXVECTOR3(-60.84f, -125.27f, 384.18f);
	leftWall[73].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[73].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[74].position = D3DXVECTOR3(-51.65f, -126.90f, 385.00f);
	leftWall[74].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[74].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[75].position = D3DXVECTOR3(-42.50f, -128.53f, 384.23f);
	leftWall[75].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[75].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[76].position = D3DXVECTOR3(-33.37f, -130.25f, 382.66f);
	leftWall[76].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[76].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[77].position = D3DXVECTOR3(-25.87f, -132.11f, 382.11f);
	leftWall[77].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[77].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[78].position = D3DXVECTOR3(-19.62f, -133.76f, 382.80f);
	leftWall[78].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[78].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[79].position = D3DXVECTOR3(-13.95f, -135.37f, 384.47f);
	leftWall[79].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[79].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[80].position = D3DXVECTOR3(-8.30f, -137.01f, 387.24f);
	leftWall[80].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[80].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[81].position = D3DXVECTOR3(-0.79f, -138.59f, 391.55f);
	leftWall[81].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[81].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[82].position = D3DXVECTOR3(7.24f, -140.28f, 396.20f);
	leftWall[82].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[82].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[83].position = D3DXVECTOR3(15.50f, -142.00f, 400.96f);
	leftWall[83].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[83].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[84].position = D3DXVECTOR3(23.62f, -143.70f, 405.63f);
	leftWall[84].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[84].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[85].position = D3DXVECTOR3(31.72f, -145.37f, 410.29f);
	leftWall[85].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[85].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[86].position = D3DXVECTOR3(40.02f, -147.07f, 415.07f);
	leftWall[86].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[86].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[87].position = D3DXVECTOR3(47.59f, -148.64f, 419.39f);
	leftWall[87].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[87].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[88].position = D3DXVECTOR3(55.92f, -150.40f, 424.19f);
	leftWall[88].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[88].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[89].position = D3DXVECTOR3(63.95f, -152.09f, 428.84f);
	leftWall[89].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[89].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[90].position = D3DXVECTOR3(72.21f, -153.81f, 433.60f);
	leftWall[90].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[90].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[91].position = D3DXVECTOR3(80.33f, -155.51f, 438.27f);
	leftWall[91].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[91].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[92].position = D3DXVECTOR3(88.43f, -157.18f, 442.93f);
	leftWall[92].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[92].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[93].position = D3DXVECTOR3(96.73f, -158.88f, 447.71f);
	leftWall[93].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[93].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[94].position = D3DXVECTOR3(104.31f, -160.45f, 452.03f);
	leftWall[94].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[94].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[95].position = D3DXVECTOR3(109.77f, -162.20f, 455.98f);
	leftWall[95].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[95].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[96].position = D3DXVECTOR3(114.12f, -163.85f, 460.52f);
	leftWall[96].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[96].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[97].position = D3DXVECTOR3(117.39f, -165.46f, 465.45f);
	leftWall[97].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[97].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[98].position = D3DXVECTOR3(119.93f, -167.10f, 471.20f);
	leftWall[98].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[98].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[99].position = D3DXVECTOR3(122.84f, -168.63f, 479.17f);
	leftWall[99].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[99].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[100].position = D3DXVECTOR3(125.92f, -170.29f, 487.64f);
	leftWall[100].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[100].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[101].position = D3DXVECTOR3(129.04f, -171.94f, 496.09f);
	leftWall[101].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[101].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[102].position = D3DXVECTOR3(130.89f, -173.80f, 503.38f);
	leftWall[102].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[102].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[103].position = D3DXVECTOR3(131.30f, -175.45f, 509.65f);
	leftWall[103].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[103].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[104].position = D3DXVECTOR3(130.64f, -177.06f, 515.52f);
	leftWall[104].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[104].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[105].position = D3DXVECTOR3(128.89f, -178.70f, 521.57f);
	leftWall[105].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[105].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[106].position = D3DXVECTOR3(125.89f, -180.27f, 529.76f);
	leftWall[106].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[106].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[107].position = D3DXVECTOR3(122.76f, -181.93f, 538.28f);
	leftWall[107].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[107].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[108].position = D3DXVECTOR3(120.34f, -183.54f, 547.24f);
	leftWall[108].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[108].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[109].position = D3DXVECTOR3(119.55f, -185.13f, 556.13f);
	leftWall[109].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[109].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[110].position = D3DXVECTOR3(120.34f, -186.76f, 565.33f);
	leftWall[110].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[110].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[111].position = D3DXVECTOR3(122.69f, -188.39f, 574.21f);
	leftWall[111].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[111].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[112].position = D3DXVECTOR3(125.82f, -190.06f, 582.85f);
	leftWall[112].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[112].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[113].position = D3DXVECTOR3(127.67f, -191.92f, 590.14f);
	leftWall[113].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[113].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[114].position = D3DXVECTOR3(128.08f, -193.57f, 596.41f);
	leftWall[114].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[114].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[115].position = D3DXVECTOR3(127.42f, -195.18f, 602.28f);
	leftWall[115].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[115].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[116].position = D3DXVECTOR3(125.67f, -196.82f, 608.33f);
	leftWall[116].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[116].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[117].position = D3DXVECTOR3(122.76f, -198.36f, 616.34f);
	leftWall[117].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[117].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[118].position = D3DXVECTOR3(119.51f, -200.08f, 625.29f);
	leftWall[118].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[118].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[119].position = D3DXVECTOR3(116.38f, -201.73f, 633.85f);
	leftWall[119].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 340.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[119].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[120].position = D3DXVECTOR3(113.96f, -203.34f, 642.81f);
	leftWall[120].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 350.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[120].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[121].position = D3DXVECTOR3(113.17f, -204.93f, 651.70f);
	leftWall[121].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[121].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[122].position = D3DXVECTOR3(113.96f, -206.56f, 660.90f);
	leftWall[122].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 10.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[122].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[123].position = D3DXVECTOR3(116.31f, -208.19f, 669.78f);
	leftWall[123].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[123].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[124].position = D3DXVECTOR3(119.55f, -209.93f, 678.78f);
	leftWall[124].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[124].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[125].position = D3DXVECTOR3(122.83f, -211.66f, 687.78f);
	leftWall[125].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[125].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[126].position = D3DXVECTOR3(126.05f, -213.35f, 696.62f);
	leftWall[126].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[126].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[127].position = D3DXVECTOR3(129.22f, -215.03f, 705.35f);
	leftWall[127].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[127].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[128].position = D3DXVECTOR3(132.38f, -216.71f, 714.02f);
	leftWall[128].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[128].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[129].position = D3DXVECTOR3(135.62f, -218.45f, 722.95f);
	leftWall[129].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[129].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[130].position = D3DXVECTOR3(138.85f, -220.15f, 731.83f);
	leftWall[130].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[130].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[131].position = D3DXVECTOR3(142.02f, -221.85f, 740.63f);
	leftWall[131].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[131].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[132].position = D3DXVECTOR3(144.96f, -223.37f, 748.65f);
	leftWall[132].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[132].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[133].position = D3DXVECTOR3(148.24f, -225.10f, 757.65f);
	leftWall[133].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[133].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[134].position = D3DXVECTOR3(151.46f, -226.79f, 766.49f);
	leftWall[134].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[134].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[135].position = D3DXVECTOR3(154.63f, -228.47f, 775.22f);
	leftWall[135].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[135].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[136].position = D3DXVECTOR3(157.79f, -230.15f, 783.89f);
	leftWall[136].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[136].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[137].position = D3DXVECTOR3(161.03f, -231.89f, 792.82f);
	leftWall[137].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[137].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[138].position = D3DXVECTOR3(164.26f, -233.59f, 801.70f);
	leftWall[138].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[138].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[139].position = D3DXVECTOR3(167.43f, -235.29f, 810.50f);
	leftWall[139].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[139].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[140].position = D3DXVECTOR3(171.28f, -236.88f, 818.68f);
	leftWall[140].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[140].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[141].position = D3DXVECTOR3(176.39f, -238.47f, 826.00f);
	leftWall[141].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[141].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[142].position = D3DXVECTOR3(182.91f, -240.10f, 832.54f);
	leftWall[142].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[142].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[143].position = D3DXVECTOR3(190.42f, -241.73f, 837.83f);
	leftWall[143].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[143].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[144].position = D3DXVECTOR3(198.69f, -243.33f, 841.72f);
	leftWall[144].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[144].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[145].position = D3DXVECTOR3(207.59f, -244.97f, 844.12f);
	leftWall[145].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[145].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[146].position = D3DXVECTOR3(216.55f, -246.63f, 844.86f);
	leftWall[146].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[146].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[147].position = D3DXVECTOR3(225.25f, -248.17f, 844.11f);
	leftWall[147].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[147].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[148].position = D3DXVECTOR3(234.45f, -249.84f, 842.49f);
	leftWall[148].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[148].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[149].position = D3DXVECTOR3(243.78f, -251.53f, 840.85f);
	leftWall[149].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[149].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[150].position = D3DXVECTOR3(252.68f, -253.15f, 839.31f);
	leftWall[150].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[150].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[151].position = D3DXVECTOR3(260.18f, -255.01f, 838.76f);
	leftWall[151].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[151].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[152].position = D3DXVECTOR3(266.43f, -256.66f, 839.44f);
	leftWall[152].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[152].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[153].position = D3DXVECTOR3(272.10f, -258.27f, 841.11f);
	leftWall[153].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[153].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[154].position = D3DXVECTOR3(277.75f, -259.91f, 843.89f);
	leftWall[154].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[154].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[155].position = D3DXVECTOR3(282.94f, -261.63f, 847.77f);
	leftWall[155].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[155].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[156].position = D3DXVECTOR3(287.20f, -263.25f, 852.21f);
	leftWall[156].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[156].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[157].position = D3DXVECTOR3(290.73f, -264.89f, 857.55f);
	leftWall[157].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[157].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[158].position = D3DXVECTOR3(293.15f, -266.45f, 863.06f);
	leftWall[158].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[158].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[159].position = D3DXVECTOR3(296.00f, -267.95f, 870.86f);
	leftWall[159].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[159].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[160].position = D3DXVECTOR3(299.26f, -269.65f, 879.83f);
	leftWall[160].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[160].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[161].position = D3DXVECTOR3(302.52f, -271.42f, 888.77f);
	leftWall[161].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[161].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[162].position = D3DXVECTOR3(306.43f, -273.03f, 897.19f);
	leftWall[162].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 30.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[162].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[163].position = D3DXVECTOR3(311.54f, -274.62f, 904.51f);
	leftWall[163].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 40.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[163].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[164].position = D3DXVECTOR3(318.06f, -276.25f, 911.05f);
	leftWall[164].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 50.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[164].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[165].position = D3DXVECTOR3(325.57f, -277.88f, 916.34f);
	leftWall[165].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[165].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[166].position = D3DXVECTOR3(333.84f, -279.48f, 920.23f);
	leftWall[166].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 70.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[166].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[167].position = D3DXVECTOR3(342.74f, -281.12f, 922.63f);
	leftWall[167].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[167].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[168].position = D3DXVECTOR3(351.70f, -282.78f, 923.37f);
	leftWall[168].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[168].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[169].position = D3DXVECTOR3(360.40f, -284.32f, 922.62f);
	leftWall[169].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[169].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[170].position = D3DXVECTOR3(369.79f, -286.05f, 920.97f);
	leftWall[170].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[170].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[171].position = D3DXVECTOR3(378.76f, -287.66f, 918.58f);
	leftWall[171].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[171].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[172].position = D3DXVECTOR3(386.86f, -289.25f, 914.82f);
	leftWall[172].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[172].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[173].position = D3DXVECTOR3(394.43f, -290.88f, 909.54f);
	leftWall[173].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[173].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[174].position = D3DXVECTOR3(400.95f, -292.51f, 903.06f);
	leftWall[174].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[174].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[175].position = D3DXVECTOR3(406.21f, -294.11f, 895.59f);
	leftWall[175].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[175].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[176].position = D3DXVECTOR3(410.12f, -295.75f, 887.24f);
	leftWall[176].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[176].scale = D3DXVECTOR3(5, 1, 10.00001);

	leftWall[177].position = D3DXVECTOR3(412.40f, -297.41f, 878.54f);
	leftWall[177].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[177].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[178].position = D3DXVECTOR3(413.18f, -298.95f, 869.85f);
	leftWall[178].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[178].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[179].position = D3DXVECTOR3(413.15f, -300.67f, 860.43f);
	leftWall[179].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[179].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[180].position = D3DXVECTOR3(413.15f, -302.42f, 850.89f);
	leftWall[180].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[180].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[181].position = D3DXVECTOR3(413.15f, -304.12f, 841.50f);
	leftWall[181].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[181].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[182].position = D3DXVECTOR3(413.15f, -305.77f, 832.34f);
	leftWall[182].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[182].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[183].position = D3DXVECTOR3(413.15f, -307.51f, 822.76f);
	leftWall[183].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[183].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[184].position = D3DXVECTOR3(413.15f, -309.09f, 814.03f);
	leftWall[184].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[184].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[185].position = D3DXVECTOR3(413.10f, -310.71f, 805.07f);
	leftWall[185].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[185].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[186].position = D3DXVECTOR3(413.10f, -312.46f, 795.53f);
	leftWall[186].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[186].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[187].position = D3DXVECTOR3(413.10f, -314.16f, 786.14f);
	leftWall[187].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[187].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[188].position = D3DXVECTOR3(413.10f, -315.81f, 776.98f);
	leftWall[188].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[188].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[189].position = D3DXVECTOR3(413.10f, -317.55f, 767.40f);
	leftWall[189].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[189].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[190].position = D3DXVECTOR3(413.10f, -319.13f, 758.67f);
	leftWall[190].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[190].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[191].position = D3DXVECTOR3(412.33f, -320.81f, 749.59f);
	leftWall[191].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[191].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[192].position = D3DXVECTOR3(410.03f, -322.40f, 740.96f);
	leftWall[192].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[192].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[193].position = D3DXVECTOR3(406.14f, -324.03f, 732.59f);
	leftWall[193].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[193].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[194].position = D3DXVECTOR3(400.90f, -325.66f, 725.05f);
	leftWall[194].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[194].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[195].position = D3DXVECTOR3(394.94f, -327.34f, 717.95f);
	leftWall[195].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 220.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[195].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[196].position = D3DXVECTOR3(390.71f, -329.20f, 711.73f);
	leftWall[196].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[196].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[197].position = D3DXVECTOR3(388.18f, -330.85f, 705.97f);
	leftWall[197].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 200.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[197].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[198].position = D3DXVECTOR3(386.79f, -332.46f, 700.23f);
	leftWall[198].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 190.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[198].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[199].position = D3DXVECTOR3(386.37f, -334.10f, 693.95f);
	leftWall[199].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[199].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[200].position = D3DXVECTOR3(386.36f, -335.60f, 685.56f);
	leftWall[200].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[200].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[201].position = D3DXVECTOR3(386.36f, -337.29f, 676.11f);
	leftWall[201].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[201].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[202].position = D3DXVECTOR3(386.37f, -338.84f, 667.67f);
	leftWall[202].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[202].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[203].position = D3DXVECTOR3(387.13f, -340.70f, 660.19f);
	leftWall[203].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 170.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[203].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[204].position = D3DXVECTOR3(388.89f, -342.35f, 654.15f);
	leftWall[204].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 160.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[204].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[205].position = D3DXVECTOR3(391.52f, -343.96f, 648.86f);
	leftWall[205].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 150.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[205].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[206].position = D3DXVECTOR3(395.23f, -345.60f, 643.78f);
	leftWall[206].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[206].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[207].position = D3DXVECTOR3(400.77f, -347.16f, 637.15f);
	leftWall[207].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[207].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[208].position = D3DXVECTOR3(406.82f, -348.86f, 629.94f);
	leftWall[208].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[208].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[209].position = D3DXVECTOR3(412.94f, -350.59f, 622.64f);
	leftWall[209].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[209].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[210].position = D3DXVECTOR3(419.05f, -352.34f, 615.41f);
	leftWall[210].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 140.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[210].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[211].position = D3DXVECTOR3(424.44f, -354.20f, 610.17f);
	leftWall[211].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 130.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[211].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[212].position = D3DXVECTOR3(429.68f, -355.85f, 606.68f);
	leftWall[212].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 120.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[212].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[213].position = D3DXVECTOR3(435.09f, -357.46f, 604.31f);
	leftWall[213].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 110.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[213].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[214].position = D3DXVECTOR3(441.20f, -359.10f, 602.81f);
	leftWall[214].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[214].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[215].position = D3DXVECTOR3(447.67f, -360.82f, 602.45f);
	leftWall[215].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[215].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[216].position = D3DXVECTOR3(453.79f, -362.44f, 603.11f);
	leftWall[216].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[216].scale = D3DXVECTOR3(5, 1, 8);

	leftWall[217].position = D3DXVECTOR3(461.99f, -363.99f, 604.53f);
	leftWall[217].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[217].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[218].position = D3DXVECTOR3(471.54f, -365.75f, 606.21f);
	leftWall[218].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[218].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[219].position = D3DXVECTOR3(480.92f, -367.47f, 607.87f);
	leftWall[219].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[219].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[220].position = D3DXVECTOR3(490.36f, -369.20f, 609.53f);
	leftWall[220].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[220].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[221].position = D3DXVECTOR3(498.06f, -370.58f, 610.93f);
	leftWall[221].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[221].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[222].position = D3DXVECTOR3(507.61f, -372.32f, 612.60f);
	leftWall[222].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[222].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[223].position = D3DXVECTOR3(516.90f, -374.00f, 614.24f);
	leftWall[223].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[223].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[224].position = D3DXVECTOR3(526.31f, -375.71f, 615.90f);
	leftWall[224].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[224].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[225].position = D3DXVECTOR3(535.70f, -377.42f, 617.56f);
	leftWall[225].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[225].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[226].position = D3DXVECTOR3(545.06f, -379.12f, 619.21f);
	leftWall[226].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[226].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[227].position = D3DXVECTOR3(554.16f, -380.83f, 620.83f);
	leftWall[227].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[227].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[228].position = D3DXVECTOR3(563.71f, -382.59f, 622.51f);
	leftWall[228].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[228].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[229].position = D3DXVECTOR3(573.09f, -384.31f, 624.17f);
	leftWall[229].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[229].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[230].position = D3DXVECTOR3(582.53f, -386.04f, 625.83f);
	leftWall[230].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[230].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[231].position = D3DXVECTOR3(590.23f, -387.42f, 627.22f);
	leftWall[231].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[231].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[232].position = D3DXVECTOR3(599.78f, -389.16f, 628.89f);
	leftWall[232].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[232].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[233].position = D3DXVECTOR3(609.07f, -390.84f, 630.53f);
	leftWall[233].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[233].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[234].position = D3DXVECTOR3(618.48f, -392.55f, 632.19f);
	leftWall[234].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[234].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[235].position = D3DXVECTOR3(627.87f, -394.26f, 633.85f);
	leftWall[235].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[235].scale = D3DXVECTOR3(5, 1, 10);

	leftWall[236].position = D3DXVECTOR3(637.23f, -395.96f, 635.50f);
	leftWall[236].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 275.00f*3.141592f / 180);
	leftWall[236].scale = D3DXVECTOR3(5, 1, 10);

	

	Transform obstaclePattern[72];
	obstaclePattern[0].position = D3DXVECTOR3(-67.59f, -57.33f, 220.31f);
	obstaclePattern[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[1].position = D3DXVECTOR3(-64.77f, -56.37f, 225.53f);
	obstaclePattern[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 40.00f*3.141592f / 180);

	obstaclePattern[2].position = D3DXVECTOR3(-70.81f, -56.39f, 215.06f);
	obstaclePattern[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 320.00f*3.141592f / 180);

	obstaclePattern[3].position = D3DXVECTOR3(-105.93f, -65.54f, 242.43f);
	obstaclePattern[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[4].position = D3DXVECTOR3(-103.01f, -64.46f, 247.85f);
	obstaclePattern[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[5].position = D3DXVECTOR3(-109.22f, -64.61f, 237.05f);
	obstaclePattern[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 300.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[6].position = D3DXVECTOR3(-158.47f, -107.38f, 352.30f);
	obstaclePattern[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[7].position = D3DXVECTOR3(-155.27f, -106.35f, 347.11f);
	obstaclePattern[7].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[8].position = D3DXVECTOR3(-161.48f, -106.49f, 357.84f);
	obstaclePattern[8].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[9].position = D3DXVECTOR3(-132.99f, -112.83f, 362.92f);
	obstaclePattern[9].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[10].position = D3DXVECTOR3(-131.76f, -111.85f, 356.96f);
	obstaclePattern[10].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[11].position = D3DXVECTOR3(-133.92f, -111.92f, 369.13f);
	obstaclePattern[11].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[12].position = D3DXVECTOR3(11.74f, -143.72f, 389.01f);
	obstaclePattern[12].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[13].position = D3DXVECTOR3(15.04f, -142.75f, 383.63f);
	obstaclePattern[13].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[14].position = D3DXVECTOR3(8.79f, -142.81f, 394.43f);
	obstaclePattern[14].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[15].position = D3DXVECTOR3(52.06f, -152.08f, 412.09f);
	obstaclePattern[15].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[16].position = D3DXVECTOR3(55.33f, -151.08f, 406.81f);
	obstaclePattern[16].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[17].position = D3DXVECTOR3(49.09f, -151.24f, 417.53f);
	obstaclePattern[17].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[18].position = D3DXVECTOR3(59.87f, -153.78f, 416.67f);
	obstaclePattern[18].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[19].position = D3DXVECTOR3(63.19f, -152.73f, 411.29f);
	obstaclePattern[19].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[20].position = D3DXVECTOR3(56.98f, -152.92f, 421.97f);
	obstaclePattern[20].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[21].position = D3DXVECTOR3(67.94f, -155.45f, 421.28f);
	obstaclePattern[21].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[22].position = D3DXVECTOR3(71.22f, -154.41f, 415.97f);
	obstaclePattern[22].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[23].position = D3DXVECTOR3(64.99f, -154.51f, 426.74f);
	obstaclePattern[23].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[24].position = D3DXVECTOR3(121.73f, -208.77f, 654.11f);
	obstaclePattern[24].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[25].position = D3DXVECTOR3(127.38f, -207.86f, 654.27f);
	obstaclePattern[25].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[26].position = D3DXVECTOR3(115.87f, -208.07f, 654.24f);
	obstaclePattern[26].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[27].position = D3DXVECTOR3(134.38f, -216.89f, 694.17f);
	obstaclePattern[27].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[28].position = D3DXVECTOR3(139.86f, -215.92f, 692.37f);
	obstaclePattern[28].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[29].position = D3DXVECTOR3(128.90f, -216.07f, 696.31f);
	obstaclePattern[29].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[30].position = D3DXVECTOR3(137.25f, -218.41f, 702.05f);
	obstaclePattern[30].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[31].position = D3DXVECTOR3(142.77f, -217.49f, 700.21f);
	obstaclePattern[31].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[32].position = D3DXVECTOR3(131.76f, -217.62f, 704.20f);
	obstaclePattern[32].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[33].position = D3DXVECTOR3(261.95f, -258.75f, 830.19f);
	obstaclePattern[33].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[34].position = D3DXVECTOR3(262.12f, -257.80f, 824.20f);
	obstaclePattern[34].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[35].position = D3DXVECTOR3(262.10f, -257.87f, 835.88f);
	obstaclePattern[35].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 90.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[36].position = D3DXVECTOR3(301.81f, -270.22f, 861.85f);
	obstaclePattern[36].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[37].position = D3DXVECTOR3(307.45f, -269.30f, 859.98f);
	obstaclePattern[37].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[38].position = D3DXVECTOR3(296.42f, -269.33f, 863.97f);
	obstaclePattern[38].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[39].position = D3DXVECTOR3(368.25f, -289.45f, 912.57f);
	obstaclePattern[39].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[40].position = D3DXVECTOR3(367.37f, -288.52f, 906.66f);
	obstaclePattern[40].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[41].position = D3DXVECTOR3(369.40f, -288.55f, 918.13f);
	obstaclePattern[41].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 100.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[42].position = D3DXVECTOR3(404.56f, -307.59f, 841.51f);
	obstaclePattern[42].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[43].position = D3DXVECTOR3(398.71f, -306.58f, 841.33f);
	obstaclePattern[43].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[44].position = D3DXVECTOR3(410.40f, -306.70f, 841.36f);
	obstaclePattern[44].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[45].position = D3DXVECTOR3(404.56f, -309.17f, 832.26f);
	obstaclePattern[45].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[46].position = D3DXVECTOR3(398.73f, -308.29f, 832.10f);
	obstaclePattern[46].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[47].position = D3DXVECTOR3(410.41f, -308.36f, 832.12f);
	obstaclePattern[47].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[48].position = D3DXVECTOR3(404.70f, -310.96f, 822.54f);
	obstaclePattern[48].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[49].position = D3DXVECTOR3(398.72f, -310.01f, 822.38f);
	obstaclePattern[49].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[50].position = D3DXVECTOR3(410.44f, -310.15f, 822.40f);
	obstaclePattern[50].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[51].position = D3DXVECTOR3(382.55f, -332.91f, 714.54f);
	obstaclePattern[51].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[52].position = D3DXVECTOR3(377.38f, -331.97f, 717.34f);
	obstaclePattern[52].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[53].position = D3DXVECTOR3(387.45f, -332.04f, 711.54f);
	obstaclePattern[53].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 210.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[54].position = D3DXVECTOR3(377.94f, -338.96f, 685.61f);
	obstaclePattern[54].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[55].position = D3DXVECTOR3(371.89f, -338.09f, 685.46f);
	obstaclePattern[55].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[56].position = D3DXVECTOR3(383.63f, -338.19f, 685.48f);
	obstaclePattern[56].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[57].position = D3DXVECTOR3(472.74f, -369.18f, 597.76f);
	obstaclePattern[57].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[58].position = D3DXVECTOR3(473.95f, -368.26f, 591.85f);
	obstaclePattern[58].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[59].position = D3DXVECTOR3(471.90f, -368.39f, 603.39f);
	obstaclePattern[59].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[60].position = D3DXVECTOR3(482.17f, -370.91f, 599.42f);
	obstaclePattern[60].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[61].position = D3DXVECTOR3(483.38f, -369.94f, 593.55f);
	obstaclePattern[61].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[62].position = D3DXVECTOR3(481.32f, -370.13f, 605.03f);
	obstaclePattern[62].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[63].position = D3DXVECTOR3(517.96f, -377.41f, 605.66f);
	obstaclePattern[63].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[64].position = D3DXVECTOR3(519.41f, -376.52f, 599.90f);
	obstaclePattern[64].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[65].position = D3DXVECTOR3(516.99f, -376.53f, 611.37f);
	obstaclePattern[65].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[66].position = D3DXVECTOR3(573.97f, -387.78f, 615.71f);
	obstaclePattern[66].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[67].position = D3DXVECTOR3(575.22f, -386.69f, 609.77f);
	obstaclePattern[67].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[68].position = D3DXVECTOR3(573.16f, -386.87f, 621.28f);
	obstaclePattern[68].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	obstaclePattern[69].position = D3DXVECTOR3(583.90f, -389.55f, 617.50f);
	obstaclePattern[69].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);

	obstaclePattern[70].position = D3DXVECTOR3(585.14f, -388.51f, 611.50f);
	obstaclePattern[70].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 30.00f*3.141592f / 180);

	obstaclePattern[71].position = D3DXVECTOR3(583.08f, -388.67f, 623.03f);
	obstaclePattern[71].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 330.00f*3.141592f / 180);

	int count = 0;
	for (int i = 0; i < 72 - 3; i += 3) {
		int p = rand() % 3;
		obstacle[count].Init();
		obstacle[count].position = obstaclePattern[i + p].position;
		obstacle[count].rotation = obstaclePattern[i + p].rotation;
		count++;
	}

	//ゴール床座標
	for (int i = 0; i < GOAL_CUBE_NUM; i++) {
		goalCube[i].position = D3DXVECTOR3(651.14f, -401.45f, 629.33f)+goalCube[0].GetForward()*20*i;
		goalCube[i].rotation = D3DXVECTOR3(0.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
		goalCube[i].scale = D3DXVECTOR3(20, 0, 20);
	}



	////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////

	//加速床の情報をランダムで決定する
	const int ACCELSPEED_PATTERN = 7;
	Transform accelSpeedPattern[ACCELSPEED_PATTERN];
	int pattern[ACCELSPEED_PATTERN];

	//加速床の情報の候補を設定
	accelSpeedPattern[0].position = D3DXVECTOR3(-0.26f, -25.70f, 83.15f);
	accelSpeedPattern[0].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeedPattern[0].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[1].position = D3DXVECTOR3(35.25f, -149.88f, 402.52f);
	accelSpeedPattern[1].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 60.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeedPattern[1].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[2].position = D3DXVECTOR3(127.25f, -214.44f, 675.10f);
	accelSpeedPattern[2].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 20.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeedPattern[2].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[3].position = D3DXVECTOR3(404.61f, -322.05f, 768.22f);
	accelSpeedPattern[3].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeedPattern[3].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[4].position = D3DXVECTOR3(398.05f, -307.62f, 767.42f);
	accelSpeedPattern[4].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, 45.00f*3.141592f / 180);
	accelSpeedPattern[4].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[5].position = D3DXVECTOR3(410.51f, -307.75f, 767.44f);
	accelSpeedPattern[5].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 180.00f*3.141592f / 180, -45.00f*3.141592f / 180);
	accelSpeedPattern[5].scale = D3DXVECTOR3(2, 1.5, 1);

	accelSpeedPattern[6].position = D3DXVECTOR3(498.72f, -375.09f, 602.41f);
	accelSpeedPattern[6].rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
	accelSpeedPattern[6].scale = D3DXVECTOR3(2, 1.5, 1);


	//何番目のパターンの情報を入れるか決定する
	int n;
	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		n = (int)(rand() % ACCELSPEED_PATTERN);
		pattern[i] = n;
		for (int j = i; j >= 0; j--) {
			if (pattern[i] == pattern[j]) {
				n = (int)(rand() % ACCELSPEED_PATTERN);
				pattern[i] = n;
				j = i;
			}
		}
	}

	//ランダムで決定した情報を入れる
	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		accelSpeed[i].Init();
		accelSpeed[i].position = accelSpeedPattern[pattern[i]].position;
		accelSpeed[i].rotation = accelSpeedPattern[pattern[i]].rotation;
	}


	for (int i = 0; i < CUBE_NUM; i++) {
		cube[i].scale *= 1.1f;
	}

	
	////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////


	leftWallCount = 0;
	for (int i = 0; i < DRAW_LEFT_WALL_NUM; i++) {
		drawLeftWall[i].position = leftWall[i].position;
		drawLeftWall[i].rotation = leftWall[i].rotation;
		drawLeftWall[i].scale = leftWall[i].scale;
	}

	rightWallCount = 0;
	for (int i = 0; i < DRAW_RIGHT_WALL_NUM; i++) {
		drawRightWall[i].position = rightWall[i].position;
		drawRightWall[i].rotation = rightWall[i].rotation;
		drawRightWall[i].scale = rightWall[i].scale;
	}
}


void StageDraw() {
	
	D3DXVECTOR3 distance;
	const float DRAW_RANGE = 215;
	const float BACK_DRAW_RANGE = 20;

	//障害物の描画
	for (int i = 0; i < OBSTACLE_NUM; i++) {
		distance = obstacle[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
			distance.y*distance.y +
			distance.z*distance.z, 0.5f);

		//プレイヤーの正面方向&距離が150以内だったら描画する
		if (sinf(rad + GetPlayer()->rotation.y) >= 0 && vecLen <= DRAW_RANGE) {
			obstacle[i].Update();
			obstacle[i].Draw();

		} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= BACK_DRAW_RANGE) {
			//プレイヤーの後ろ方向でも距離が30以内だったら描画する
			obstacle[i].Update();
			obstacle[i].Draw();
		}
	
	}

	//Cubeの描画
	for (int i = 0; i < CUBE_NUM; i++) {
		distance = cube[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
						   distance.y*distance.y + 
			               distance.z*distance.z, 0.5f);


		//プレイヤーの正面方向&距離が150以内だったら描画する
		if (sinf(rad+GetPlayer()->rotation.y)>=0 && vecLen<= DRAW_RANGE) {
			cube[i].Draw(TEXTURE_INDEX_ICE);

		} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= 20) {
			//プレイヤーの後ろ方向でも距離が30以内だったら描画する
			cube[i].Draw(TEXTURE_INDEX_ICE);
		}
	}




	{
		//for (int i = 0; i < RIGHT_WALL_NUM; i++) {
		//	distance = rightWall[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		//	float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		//	float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
		//		distance.y*distance.y +
		//		distance.z*distance.z, 0.5f);

		//	//プレイヤーの正面方向&距離が150以内だったら描画する
		//	if (sinf(rad + GetPlayer()->rotation.y) >= 0 && vecLen <= DRAW_RANGE) {
		//		rightWall[i].Draw(TEXTURE_INDEX_ICE);

		//	} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= BACK_DRAW_RANGE) {
		//		//プレイヤーの後ろ方向でも距離が30以内だったら描画する
		//		rightWall[i].Draw(TEXTURE_INDEX_ICE);
		//	}
		//}


		//for (int i = 0; i < LEFT_WALL_NUM; i++) {
		//	distance = leftWall[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		//	float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		//	float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
		//		distance.y*distance.y +
		//		distance.z*distance.z, 0.5f);

		//	//プレイヤーの正面方向&距離が150以内だったら描画する
		//	if (sinf(rad + GetPlayer()->rotation.y) >= 0 && vecLen <= DRAW_RANGE) {
		//		leftWall[i].Draw(TEXTURE_INDEX_ICE);

		//	} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= BACK_DRAW_RANGE) {
		//		//プレイヤーの後ろ方向でも距離が30以内だったら描画する
		//		leftWall[i].Draw(TEXTURE_INDEX_ICE);
		//	}
		//}
	}
	{
		distance = drawLeftWall[0].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
			distance.y*distance.y +
			distance.z*distance.z, 0.5f);

		if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen > 20) {
			leftWallCount++;
			for (int i = leftWallCount; i < leftWallCount + DRAW_LEFT_WALL_NUM; i++) {
				drawLeftWall[i - leftWallCount].position = leftWall[i].position;
				drawLeftWall[i - leftWallCount].rotation = leftWall[i].rotation;
				drawLeftWall[i - leftWallCount].scale	 = leftWall[i].scale;
			}
		}

	}
	{
		distance = drawRightWall[0].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
			distance.y*distance.y +
			distance.z*distance.z, 0.5f);

		if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen > 20) {
			rightWallCount++;
			for (int i = leftWallCount; i < leftWallCount + DRAW_LEFT_WALL_NUM; i++) {
				drawRightWall[i - leftWallCount].position = rightWall[i].position;
				drawRightWall[i - leftWallCount].rotation = rightWall[i].rotation;
				drawRightWall[i - leftWallCount].scale = rightWall[i].scale;
			}
		}
		//両サイドの壁の描画
		for (int i = 0; i < DRAW_LEFT_WALL_NUM; i++) {
			drawRightWall[i].Draw(TEXTURE_INDEX_ICE);
			drawLeftWall[i].Draw(TEXTURE_INDEX_ICE);
		}
	}

	//ゴールキューブの描画
	for (int i = 0; i < GOAL_CUBE_NUM; i++) {
		distance = goalCube[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
			distance.y*distance.y +
			distance.z*distance.z, 0.5f);

		//プレイヤーの正面方向&距離が150以内だったら描画する
		if (sinf(rad + GetPlayer()->rotation.y) >= 0 && vecLen <= DRAW_RANGE) {
			goalCube[i].Draw(TEXTURE_INDEX_RED_FLOOR);

		} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= BACK_DRAW_RANGE) {
			//プレイヤーの後ろ方向でも距離が30以内だったら描画する
			goalCube[i].Draw(TEXTURE_INDEX_RED_FLOOR);
		}
		
	}

	//ゴール_テェック床の描画
	Cube check[4];

	for (int i = 0; i < 4; i++) {
		check[i].position = D3DXVECTOR3(643.76f, -401.41f, 628.03f);
		check[i].rotation = D3DXVECTOR3(0.00f*3.141592f / 180, 80.00f*3.141592f / 180, 0.00f*3.141592f / 180);
		check[i].scale = D3DXVECTOR3(5, 0, 5);
		check[i].position += check[0].GetRight()*(5*i)- (check[0].GetRight()*(5 * 3))/2;
		check[i].Draw(TEXTURE_INDEX_CHECK_FLOOR);
	}

	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		distance = accelSpeed[i].position - GetPlayerPos();   //ソリとオブジェクトとの距離を計算
		float rad = atan2f(distance.z, distance.x);		//cubeとプレイヤーとのｘｚ軸をとって角度を取得
		float vecLen = pow(distance.x*distance.x +      //距離のベクトルの長さを取得
			distance.y*distance.y +
			distance.z*distance.z, 0.5f);

		//プレイヤーの正面方向&距離が150以内だったら描画する
		if (sinf(rad + GetPlayer()->rotation.y) >= 0 && vecLen <= DRAW_RANGE) {
			accelSpeed[i].Draw();

		} else if (sinf(rad + GetPlayer()->rotation.y) < 0 && vecLen <= BACK_DRAW_RANGE) {
			//プレイヤーの後ろ方向でも距離が30以内だったら描画する
			accelSpeed[i].Draw();
		}
	}
}
void StageUnInit() {
	for (int i = 0; i < OBSTACLE_NUM; i++) {
		obstacle[i].UnInit();
	}
	for (int i = 0; i < ACCEL_SPEED_NUM; i++) {
		accelSpeed[i].UnInit();
	}
}

Plane GetCube(int n) {
	return cube[n];
}
SpeedAccel* GetAccelSpeedCube(int n) {
	return &accelSpeed[n];
}
Cube GetRightWall(int n) {
	return drawRightWall[n];
}
Cube GetLeftWall(int n) {
	return drawLeftWall[n];
}
Plane GetGoalCube(int n) {
	return goalCube[n];
}


int GetCubeNum() {
	return CUBE_NUM;
}
int GetAccelSpeedNum() {
	return ACCEL_SPEED_NUM;
}
int GetRightWallNum() {
	return DRAW_RIGHT_WALL_NUM;
}
int GetLeftWallNum() {
	return DRAW_LEFT_WALL_NUM;
}
int GetGoalCubeNum() {
	return GOAL_CUBE_NUM;
}