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
#include"main.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
static bool isAnimatioin=false;
static bool isChangeScene = false;

//UIの描画
void UIDraw();

//初期化
//プレイヤーの初期位置はSoriクラスのInit()関数で行う
void GameInit() {
	//フラグの初期化
	isChangeScene = false;
	isAnimatioin = false;

	//体重をもとにキャラクターを設定する
	sori.Init(72, 55);//この関数内でプレイヤーの初期位置を決める

	//ステージ初期化
	StageInit();

	//視聴率初期化
	RatingInit();

	//アニメーションの初期化
	startAnimation.Init();
	goalAnimation.Init();

	//タイム初期化
	TimerInit();

	camera.Init(sori);

}

void GameUpdate() {
	//スタートアニメーション中はUpdate処理を止める
	if (isAnimatioin == false) {
		sori.Update();
		RatingUpdate(sori);
		TimerUpdate();
		GameCollision();
	}

	//シーンの切り替え
	if (isChangeScene == true) {
		SetScene(RESULT);
	}
}

void GameDraw() {

	//そりの描画
	sori.Draw();

	//カメラ追従
	camera.SetCamera(sori);

	//ステージの描画
	StageDraw();

	//UIを描画する
	//UIの描画はこの関数内でやる
	UIDraw();


}

//終了処理
void GameUnInit() {

	sori.UnInit();
}

//当たり判定
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

	//加速床の当たり判定
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		sori.AccelFloorCollision(GetAccelSpeedCube(i).collider);
	}


	
}

//UIの描画
void UIDraw() {
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
	}
	isAnimatioin = startAnimation.Draw();

	//経過時間表示
	TimerDraw(1, 1);

	//視聴率表示
	RatingDraw();
}