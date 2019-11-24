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
#include"Rating.h"
#include"Timer.h"
#include"XFile.h"

Light *light;

Camera camera;
Sori sori;



void GameInit() {
	light = new Light();
	light->Init(D3DLIGHT_DIRECTIONAL);
	light->Use(true);

	StageInit();
	RatingInit();
	TimerInit();
	sori.position.y = 1;
	sori.Init(72, 75);
}

void GameUpdate() {
	RatingUpdate(sori);
	sori.Update();
	TimerUpdate();
	GameCollision();
	
}

void GameDraw() {
	RatingDraw();
	//カメラ追従
	camera.SetCamera(sori);
	TimerDraw(1,1);
	//ステージの描画
	StageDraw();

	//そりの描画
	sori.Draw();
}

void GameUnInit() {
	sori.UnInit();
	delete light;
}

void GameCollision() {

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
		sori.position.y -= 0.1f;
	}

	//ソリと右の壁の当たり判定
	for (int i = 0; i < GetRightWallNum(); i++) {
		if (sori.CollisionWall(GetRightWall(i).collider)) {
			sori.isHitRightWall = true;
			break;
		} else {
			sori.isHitRightWall = false;
		}
	}

	//ソリと左の壁の当たり判定
	for (int i = 0; i < GetLeftWallNum(); i++) {
		if (sori.CollisionWall(GetLeftWall(i).collider)) {
			sori.isHitLeftWall = true;
			break;
		} else {
			sori.isHitLeftWall = false;
		}
	}
}