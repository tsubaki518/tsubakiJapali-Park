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
#include"Setting.h"
#include"ImageNumber.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
NPC npc;
TezukaLine *tezukaLine;
static bool isAnimatioin = false;
static bool isChangeScene = false;
static bool isTimerInit = true;
//UIの描画
void UIDraw();


//初期化
//プレイヤーの初期位置はSoriクラスのInit()関数で行う
void GameInit() {
	tezukaLine = new TezukaLine();
	//フラグの初期化
	isChangeScene = false;
	isAnimatioin = false;

	//体重をもとにキャラクターを設定する
	sori.Init(GetSettingPlayer().weight[0], GetSettingPlayer().weight[1]);//この関数内でプレイヤーの初期位置を決める
	npc.Init(55, 72);

	//ステージ初期化
	StageInit();

	//視聴率初期化
	RatingInit();

	//アニメーションの初期化
	startAnimation.Init();
	goalAnimation.Init();

	

	camera.Init(sori);

}

void GameUpdate() {
	//スタートアニメーション中はUpdate処理を止める
	if (isAnimatioin == false) {
		if (isTimerInit == true) {
			//タイム初期化
			TimerInit();
			isTimerInit = false;
		}

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
	delete tezukaLine;
}

//当たり判定
void GameCollision() {
	const float HIT_CHECK_RANGE = 15;
	D3DXVECTOR3 distance;
	bool isGround = false;
	//ソリとCube(床)の当たり判定
	for (int i = 0; i < GetCubeNum(); i++) {
		distance = GetCube(i).position - sori.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

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
	if (isGround == false && sori.isGoalGround == false) {
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
				sori.isReceiveMoveForward = false;
				sori.isReceiveMoveLeft = true;
				sori.isReceiveMoveRight = false;
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
				sori.isReceiveMoveForward = false;
				sori.isReceiveMoveLeft = false;
				sori.isReceiveMoveRight = true;
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

	//NPCと右の壁の当たり判定
	for (int i = 0; i < GetRightWallNum(); i++) {
		distance = GetRightWall(i).position - npc.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetRightWall(i).collider)) {
				npc.isHitRightWall = true;
				npc.isReceiveMoveForward = false;
				npc.isReceiveMoveLeft = true;
				npc.isReceiveMoveRight = false;
				break;
			} else {
				npc.isHitRightWall = false;
			}
		}
	}

	//NPCと左の壁の当たり判定
	for (int i = 0; i < GetLeftWallNum(); i++) {
		distance = GetLeftWall(i).position - npc.position;//ソリとオブジェクトとの距離を計算
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//一定範囲内にCubeが存在する場合当たり判定を実行する
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetLeftWall(i).collider)) {
				npc.isHitLeftWall = true;
				npc.isReceiveMoveForward = false;
				npc.isReceiveMoveLeft = false;
				npc.isReceiveMoveRight = true;
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
	const float SPIN_POWER = 0.7f;
	//NPCとプレイヤーとの当たり判定
	if (npc.CollisionBack(sori)) {
		if (sori.isSpin == true) {
			npc.isReceiveMoveForward = true;
			npc.isReceiveMoveLeft = false;
			npc.isReceiveMoveRight = false;
			npc.receiveSpinSpeed = sori.GetForward() * SPIN_POWER;
		}
	}


	if(npc.CollisionRight(sori)) {
		if (sori.isSpin == true) {
			npc.isReceiveMoveForward = false;
			npc.isReceiveMoveLeft = true;
			npc.isReceiveMoveRight = false;
			npc.receiveSpinSpeed = sori.GetRight() * SPIN_POWER;
		}
	}
	if (npc.CollisionLeft(sori)) {
		if (sori.isSpin == true) {
			npc.isReceiveMoveForward = false;
			npc.isReceiveMoveLeft = false;
			npc.isReceiveMoveRight = true;
			npc.receiveSpinSpeed = sori.GetRight() * SPIN_POWER;
		}
	}

	if (sori.CollisionBack(npc)) {
		if (npc.isSpin == true) {
			sori.isReceiveMoveForward = true;
			sori.isReceiveMoveLeft = false;
			sori.isReceiveMoveRight = false;
			sori.receiveSpinSpeed = npc.GetForward() * SPIN_POWER;
		}
	}
	if(sori.CollisionRight(npc)){
		if (npc.isSpin == true) {
			sori.isReceiveMoveForward = false;
			sori.isReceiveMoveLeft = true;
			sori.isReceiveMoveRight = false;
			sori.receiveSpinSpeed = npc.GetRight() * SPIN_POWER;
		}
	}
	if (sori.CollisionLeft(npc)) {
		if (npc.isSpin == true) {
			sori.isReceiveMoveForward = false;
			sori.isReceiveMoveLeft = false;
			sori.isReceiveMoveRight = true;
			sori.receiveSpinSpeed = npc.GetRight() * SPIN_POWER;
		}
	}


}

//UIの描画
void UIDraw() {
	if (camera.isStop == true) {
		tezukaLine->Init(75);
	}
	tezukaLine->Draw();
	//Speed表示
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_METER, 1170, 680, 0, 0,sori.speed * (316/sori.maxSpeed), 56);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH/2 * 5 / 12 * 19, SCREEN_HEIGHT /2 *9 ), D3DXVECTOR2(0.2, 0.2), 0);
	

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


D3DXVECTOR3 GetPlayerPos() {
	return sori.position;
}