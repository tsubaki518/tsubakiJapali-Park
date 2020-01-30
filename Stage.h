#pragma once
#include"SpeedAccel.h"

void StageInit();
void StageDraw();
void StageUnInit();

//---ˆø”‚Åw’è‚µ‚½cube‚ğ“¾‚é
Plane GetCube(int n);
SpeedAccel* GetAccelSpeedCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Plane GetGoalCube(int n);


//---g‚Á‚Ä‚¢‚écube‚Ì”‚ğ“¾‚é
int GetCubeNum();
int GetAccelSpeedNum();
int GetRightWallNum();
int GetLeftWallNum();
int GetGoalCubeNum();