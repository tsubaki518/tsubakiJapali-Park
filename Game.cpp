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
#include"Sky.h"
#include"sound.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
NPC npc;
TezukaLine *tezukaLine[2];
static bool isAnimatioin = false;
static bool isChangeScene = false;
static bool isTimerInit = true;
static int playerRank = 1;
static bool isGoalGroundSoundOnece = false;
//UIの描画
void UIDraw();


//初期化
//プレイヤーの初期位置はSoriクラスのInit()関数で行う
void GameInit() {
	for (int i = 0; i < 2; i++) {
		tezukaLine[i] = new TezukaLine();
	}
	//フラグの初期化
	isChangeScene = false;
	isAnimatioin = false;
	isGoalGroundSoundOnece = false;

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

	TimerInit();
	PlaySound(SOUND_LABEL_BGM_GAME);

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
		if (sori.isGoalGround == false) {
			TimerUpdate();
			
		}
		GameCollision();
	}

	//シーンの切り替え
	if (isChangeScene == true) {
		SetScene(RESULT);
	}
}

void GameDraw() {
	Sky sky;
	sky.Draw();
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
	for (int i=0; i < 2; i++) {
		delete tezukaLine[i];
	}
	StageUnInit();
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
	for (int i = 0; i < GetGoalCubeNum(); i++) {
		if (sori.CollisionWall(GetGoalCube(i).collider)) {
			sori.isGoalGround = true;
		}
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
	for (int i = 0; i < GetGoalCubeNum(); i++) {
		if (npc.CollisionWall(GetGoalCube(i).collider)) {
			npc.isGoalGround = true;
		}
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
		tezukaLine[0]->Init(75);
	}
	if (sori.isWallSpeedAccel == true) {
		tezukaLine[1]->Init(5);
	}
	tezukaLine[0]->Draw();
	tezukaLine[1]->Draw();
	//Speed表示
	float meterCutSizeX = ((sori.speed + sori.speedAccel + sori.slidSpeed)*0.6f) * (316 / sori.maxSpeed);
	if (meterCutSizeX > 316) {
		meterCutSizeX = 316;
	}
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_METER, 1170, 678, 0, 0, meterCutSizeX, 56);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH/2 * 5 / 12 * 19, SCREEN_HEIGHT /2 *9 ), D3DXVECTOR2(0.2, 0.2), 0);
	

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
	}
	isAnimatioin = startAnimation.Draw();

	Sprite_Draw(TEXTURE_INDEX_UI, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	
	// ゴールの表示
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
		if (isGoalGroundSoundOnece == false) {
			StopSound();
			PlaySound(SOUND_LABEL_BUZZER);
			PlaySound(SOUND_LABEL_BGM_GOALandRESULT);

			isGoalGroundSoundOnece = true;
		}
	}
	isAnimatioin = startAnimation.Draw();

	Sprite_Draw(TEXTURE_INDEX_UI, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//時速の表示
	float syousuu;
	float hitoketa;
	float hutaketa;
	float sanketa;
	float seisuu = (sori.speed + sori.speedAccel+sori.slidSpeed) * 200;
	hitoketa = (int)seisuu % 10;
	hutaketa = (int)seisuu/10 % 100;
	sanketa = (int)seisuu/100 % 1000;
	syousuu = seisuu - (int)seisuu;
	syousuu  *= 10;
	if (hutaketa > 9) {
		hutaketa = (int)hutaketa%10;
	}
	

	//DebugFont_Draw(1, 1, "%lf",sori.speed*150);
	// 少数の表示
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH / 3 * 10.57, SCREEN_HEIGHT / 5 * 17.8), D3DXVECTOR2(0.25, 0.25),(int)syousuu);
	//　一桁の表示
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH / 3 * 7.17, SCREEN_HEIGHT / 5 * 12.5), D3DXVECTOR2(0.35, 0.35),(int)hitoketa);
	//　二桁の表示	
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH / 3 * 6.92, SCREEN_HEIGHT / 5 * 12.5), D3DXVECTOR2(0.35, 0.35),(int)hutaketa);
	// 三桁の表示	
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH / 3 * 6.67, SCREEN_HEIGHT / 5 * 12.5), D3DXVECTOR2(0.35, 0.35),(int)sanketa);


	//経過時間表示
	TimerDraw(1, 1);

	//視聴率表示
	RatingDraw();

	//順位判定
	if (sori.isGoalGround == false && npc.isGoalGround==false) {
		/*if (sori.position.y <= npc.position.y) {
			playerRank = 1;
		} else {
			playerRank = 2;
		}*/
		D3DXVECTOR3 distance = npc.position - sori.position;
		float vecLen = pow(distance.x*distance.x + distance.y*distance.y + distance.z*distance.z, 0.5f);
		float rad = atan2f(distance.z, distance.x)+sori.rotation.y;
		if (vecLen < 30) {
			if (sinf(rad) < 0) {
				playerRank = 1;
				sori.isChangeRank = true;
			} else {
				sori.isChangeRank = false;
				playerRank = 2;
			}
		}
	}
	//順位の表示
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	if (playerRank == 1) {
		Sprite_Draw(TEXTURE_INDEX_1ST, 0, SCREEN_HEIGHT - 210, 0, 0, 269, 171);

	} else if (playerRank == 2) {
		Sprite_Draw(TEXTURE_INDEX_2ND, 0, SCREEN_HEIGHT - 210, 0, 0, 269, 171);

	}

	sori.DrawCharacterIcon();
}


D3DXVECTOR3 GetPlayerPos() {
	return sori.position;
}
Sori* GetPlayer() {
	return &sori;
}
NPC* GetNPC() {
	return &npc;
}