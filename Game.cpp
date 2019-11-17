#include"Game.h"
#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"input.h"
#include"Camera.h"
#include<vector>
#include"main.h"
#include"Sori.h"
#include"Figure.h"
#include"debug_font.h"
#include"Light.h"
#include"Stage.h"

Camera camera;
Sori sori;




void GameInit() {

	sori.cube.position.y = 11;
	StageInit();

}
void GameUpdate() {

	sori.Update();

	bool isGround = false;
	//ソリとCube(床)の当たり判定
	for (int i = 0; i < GetCubeNum(); i++) {
		if (sori.Collision(GetCube(i).collider)) {
			isGround = true;
			break;
		} else {
			isGround = false;
		}
	}
	if (isGround == false) {
		sori.cube.position.y -= 0.1f;
	}

	//ソリと右の壁の当たり判定
	for (int i = 0; i < GetRightWallNum(); i++) {
		if (sori.CollisionWall(GetRightWall(i).collider)) {
			sori.canMoveRight = false;
			break;
		} else {
			sori.canMoveRight = true;
		}
	}

	//ソリと左の壁の当たり判定
	for (int i = 0; i < GetLeftWallNum(); i++) {
		if (sori.CollisionWall(GetLeftWall(i).collider)) {
			sori.canMoveLeft = false;
			break;
		} else {
			sori.canMoveLeft = true;
		}
	}
	
}

void GameDraw() {
	//カメラ追従
	camera.SetCamera(sori);

	//ステージの描画
	StageDraw();

	//そりの描画
	sori.Draw();



}

void GameUnInit() {

}