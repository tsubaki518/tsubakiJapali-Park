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
#include"Animation.h"

Light light;
StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
static bool isAnimatioin;

void UIDraw();

void GameInit() {
	//ライト初期化
	light.Init(D3DLIGHT_DIRECTIONAL);
	light.Use(true);

	//ステージ初期化
	StageInit();

	//視聴率初期化
	RatingInit();

	//体重をもとにキャラクターを設定する
	sori.Init(72, 55);

	//アニメーションの初期化
	startAnimation.Init();

	//タイム初期化
	TimerInit();

	//プレイヤーの初期位置
	sori.position.y = 1;

}

void GameUpdate() {
	if (isAnimatioin == false) {
		RatingUpdate(sori);
		sori.Update();
		TimerUpdate();
		GameCollision();
	}
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

	//UIを描画する
	UIDraw();

}

void GameUnInit() {
	sori.UnInit();
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
	if (isGround == false && sori.isGoalGround==false) {
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

	//ソリと左の壁の当たり判定
	if (sori.CollisionWall(GetGoalCube().collider)) {
		sori.speed = 0;
		sori.isGoalGround = true;
	}
	
}

void UIDraw() {
	if (sori.isGoalGround == true) {
		goalAnimation.Draw();
	}

	isAnimatioin = startAnimation.Draw();
}