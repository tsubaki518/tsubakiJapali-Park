#pragma once

void StageInit();
void StageDraw();

//---�����Ŏw�肵��cube�𓾂�
Cube GetCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);

//---�g���Ă���cube�̐��𓾂�
int GetCubeNum();
int GetRightWallNum();
int GetLeftWallNum();