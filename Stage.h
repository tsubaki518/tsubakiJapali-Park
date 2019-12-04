#pragma once
void StageInit();
void StageDraw();


//---引数で指定したcubeを得る
Cube GetCube(int n);
Cube GetAccelSpeedCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Cube GetGoalCube();


//---使っているcubeの数を得る
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();