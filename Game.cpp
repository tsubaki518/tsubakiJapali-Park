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
#include"NPC.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
NPC npc;
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
	npc.Init(55, 72);

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
		npc.Update();
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
	npc.Draw();

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
	npc.UnInit();
}

//当たり判定
void GameCollision() {
	const float HIT_CHECK_RANGE = 15;
	D3DXVECTOR3 distance;
	bool isGround = false;
	//ソリとCube(床)の当たり判定
	for (int i = 0; i < GetCubeNum(); i++) {
		distance = GetCube(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x> -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y> -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z> -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.Collision(GetCube(i).collider)) {
				isGround = true;
				break;
			} else {
				isGround = false;
			}
		}
	}
	if (isGround == false && sori.isGoalGround==false) {
		sori.position.y -= 0.1f;
	}

	//ソリと右の壁の当たり判定
	for (int i = 0; i < GetRightWallNum(); i++) {
		distance = GetRightWall(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.CollisionWall(GetRightWall(i).collider)) {
				sori.isHitRightWall = true;
				break;
			} else {
				sori.isHitRightWall = false;
			}
		}
	}

	//ソリと左の壁の当たり判定
	for (int i = 0; i < GetLeftWallNum(); i++) {
		distance = GetLeftWall(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.CollisionWall(GetLeftWall(i).collider)) {
				sori.isHitLeftWall = true;
				break;
			} else {
				sori.isHitLeftWall = false;
			}
		}
	}

	//ゴール判定
	if (sori.CollisionWall(GetGoalCube().collider)) {
		sori.speed = 0;
		sori.isGoalGround = true;
	}

	//加速床の当たり判定
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		distance = GetAccelSpeedCube(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			sori.AccelFloorCollision(GetAccelSpeedCube(i).collider);
		}
	}


	//////////////////////////////////////////////////////////////////////////////////////////

	bool isGroundNPC = false;
	//ソリとCube(床)の当たり判定
	for (int i = 0; i < GetCubeNum(); i++) {
		distance = GetCube(i).position - npc.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.Collision(GetCube(i).collider)) {
				isGroundNPC = true;
				break;
			} else {
				isGroundNPC = false;
			}
		}
	}
	if (isGroundNPC == false && npc.isGoalGround == false) {
		npc.position.y -= 0.1f;
	}

	//ソリと右の壁の当たり判定
	for (int i = 0; i < GetRightWallNum(); i++) {
		distance = GetRightWall(i).position - npc.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetRightWall(i).collider)) {
				npc.isHitRightWall = true;
				break;
			} else {
				npc.isHitRightWall = false;
			}
		}
	}

	//ソリと左の壁の当たり判定
	for (int i = 0; i < GetLeftWallNum(); i++) {
		distance = GetLeftWall(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetLeftWall(i).collider)) {
				npc.isHitLeftWall = true;
				break;
			} else {
				npc.isHitLeftWall = false;
			}
		}
	}

	//ゴール判定
	if (npc.CollisionWall(GetGoalCube().collider)) {
		npc.speed = 0;
		npc.isGoalGround = true;
	}

	//加速床の当たり判定
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		distance = GetAccelSpeedCube(i).position - npc.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			npc.AccelFloorCollision(GetAccelSpeedCube(i).collider);
		}
	}

	//NPCとプレイヤーとの当たり判定
	npc.CollisionBack(sori);
	npc.CollisionRight(sori);
	npc.CollisionLeft(sori);
	sori.CollisionBack(npc);
	sori.CollisionRight(npc);
	sori.CollisionLeft(npc);
	
	
}

//UIの描画
void UIDraw() {

	//Speed表示
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_METER, 1170,680, 0, 0, 32, 56);
	

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
	}
	isAnimatioin = startAnimation.Draw();

	Sprite_Draw(TEXTURE_INDEX_UI, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//経過時間表示
	TimerDraw(1, 1);

	//視聴率表示
	RatingDraw();

	
}