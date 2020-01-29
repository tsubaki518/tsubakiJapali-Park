#pragma once
#include"SpeedAccel.h"

void StageInit();
void StageDraw();
void StageUnInit();

//---引数で指定したcubeを得る
Plane GetCube(int n);
SpeedAccel GetAccelSpeedCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Plane GetGoalCube(int n);


//---使っているcubeの数を得る
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();
int GetGoalCubeNum();