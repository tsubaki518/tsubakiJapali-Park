#pragma once

void StageInit();
void StageDraw();

//---引数で指定したcubeを得る
Cube GetCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);

//---使っているcubeの数を得る
int GetCubeNum();
int GetRightWallNum();
int GetLeftWallNum();