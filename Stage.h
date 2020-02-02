#pragma once
#include"SpeedAccel.h"

void StageInit();
void StageDraw();
void StageUnInit();

//---�����Ŏw�肵��cube�𓾂�
Plane GetCube(int n);
SpeedAccel* GetAccelSpeedCube(int n);
Wall GetRightWall(int n);
Wall GetLeftWall(int n);
Plane GetGoalCube(int n);


//---�g���Ă���cube�̐��𓾂�
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();
int GetGoalCubeNum();