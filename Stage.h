#pragma once
void StageInit();
void StageDraw();


//---�����Ŏw�肵��cube�𓾂�
Cube GetCube(int n);
Cube GetAccelSpeedCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Cube GetGoalCube();


//---�g���Ă���cube�̐��𓾂�
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();