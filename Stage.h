#pragma once

void StageInit();
void StageDraw();

//---ˆø”‚Åw’è‚µ‚½cube‚ğ“¾‚é
Cube GetCube(int n);
Cube GetRightWall(int n);
Cube GetLeftWall(int n);
Cube GetGoalCube();

//---g‚Á‚Ä‚¢‚écube‚Ì”‚ğ“¾‚é
int GetCubeNum();
int GetRightWallNum();
int GetLeftWallNum();