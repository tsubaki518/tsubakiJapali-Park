#pragma once
void StageInit();
void StageDraw();
void StageUnInit();

//---�����Ŏw�肵��cube�𓾂�
Plane GetCube(int n);
Cube GetAccelSpeedCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Plane GetGoalCube(int n);


//---�g���Ă���cube�̐��𓾂�
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();
int GetGoalCubeNum();