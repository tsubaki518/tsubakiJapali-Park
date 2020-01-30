#include"Sori.h"
#include"texture.h"
#include"input.h"
#include"debug_font.h"
#include"NPC.h"
#include"sound.h"
#include"BalanceBoardInput.h"
#include<math.h>
#include"sprite.h"
#include"Stage.h"

#define CHARACTER_ROTATION_SPEED 0.1f
#define SPIN_NUM 4
#define SPIN_SPEED 1.0f
#define ACCEL_FLOOR_ACCEL_SPEED 0.3f
#define CENTRIFUGAL_FORCE 0.035f //遠心力
#define YOKONOSYAMENNNINOTTAATOKASOKUSURUYATU 0.3f //横の斜面に乗った後加速するやつ
#define BPARD_VALUE_BOARDER 4

Sori::Sori() {

}

void Sori::Init(float weight1, float weight2) {
	//キャラクターをセットする
	SetCharacter(weight1, weight2);
	character[1]->Init();
	character[0]->Init();
	bobsled.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv2.jpg");


	//------------------スピードなどのパラメータの初期化----------------------------//
	//最高速の設定
	maxSpeed = (character[0]->maxSpeed + character[1]->maxSpeed) / 2;

	speedAccel = 0;//加速床に当たったときに加速する速度を初期化する

	//プレイヤーの初期位置
	position = D3DXVECTOR3(2.0f, -10.10f, 3.0f);
	rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0, 0);
	isGoalGround = false;
	isSpin = false;

	//遠心力初期化
	centrifugalDirection = D3DXVECTOR3(0, 0, 0);

	//スピン初期化
	spinRot = D3DXVECTOR3(0, 0, 0);

	//キャラクターの情報を入れる
	CharacterTouch();

	slidSpeed = 0;
	slidCount = 0;
	speedAccel = 0;
	speed = 0;

	isWallSpeedAccel = false;
	isMoveSound = false;
}
void Sori::Update() {
	//当たり判定の情報を入れる
	SetCollisionTransform();

	//キャラクターをソリに追従させる
	CharacterTouch();

	//移動処理
	Move();

	//スピン処理
	Spin();

	//摩擦
	Friction();

	//斜面に乗っていたら滑る
	SlideDown();

	//壁に当たったら跳ね返る
	Bound();

	//加速床
	SpeedAccel();

	//遠心力
	CentrifugalForce();

	//敵のスピンが当たった時吹っ飛ぶ
	ReceiveSpinMove();

	if (isMoveSound == false) {
		if ((speed + speedAccel + slidSpeed) >0.01f) {
			PlaySound(SOUND_LABEL_SE_MOVE);
			isMoveSound = true;
		}
	}

	shaveIce[0].Update(GetRight()*0.5f + position - GetForward(), rotation, GetForward(), speed*50);
	shaveIce[1].Update(-GetRight()*0.5f + position - GetForward(), rotation, GetForward(), speed * 50 ,-1);
}
void Sori::Draw() {
	//ソリ用の行列を作成
	{
		D3DXMATRIX g_mtxWorld;
		D3DXMATRIX mtxScl;
		D3DXMATRIX mtxRot;
		D3DXMATRIX spinMtxRot;
		D3DXMATRIX mtxTrs;
		LPDIRECT3DDEVICE9	g_pd3dDevice;
		g_pd3dDevice = MyDirect3D_GetDevice();


		// ワールド変換
		//ワールド行列を単位行列へ初期化
		D3DXMatrixIdentity(&g_mtxWorld);

		//スケール行列を作成＆ワールド行列へ合成
		D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

		//スピン用の回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&spinMtxRot, spinRot.y, spinRot.x, spinRot.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &spinMtxRot);

		//回転行列を作成＆ワールド行列へ合成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

		//平行行列
		D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


		//ワールドマトリクスを設定
		g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	}

	//ソリの描画
	bobsled.Draw();

	//キャラクターの描画
	character[0]->Draw();
	character[1]->Draw();

	if (isGoalGround == false) {
		shaveIce[0].Draw();
		shaveIce[1].Draw();
	}
	int BOARD_VALUE1 = BalanceBoard_GetValue(BALANCEBOARD_1P, 4) / BPARD_VALUE_BOARDER;
	int BOARD_VALUE2= BalanceBoard_GetValue(BALANCEBOARD_2P, 4) / BPARD_VALUE_BOARDER;
	if (fabsf((int)BOARD_VALUE1) < 50) {
		BOARD_VALUE1 = 50;
	}
	if (fabsf((int)BOARD_VALUE2) < 50) {
		BOARD_VALUE2 = 50;
	}

	DebugFont_Draw(0,0,"1P::RF:%d, LR: %d, RB:%d, LB:%d, 基準値:%d", BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF),
		BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF),
		BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB),
		BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB),
		BOARD_VALUE1);

	DebugFont_Draw(0, 30, "2P::RF:%d, LR: %d, RB:%d, LB:%d, 基準値:%d", BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF),
		BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF),
		BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB),
		BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB),
		BOARD_VALUE2);
}
void Sori::UnInit() {
	for (int i = 0; i < 2; i++) {
		character[i]->UnInit();
		delete character[i];
	}
	bobsled.UnInit();

	//パーティクル
	shaveIce[0].UnInit();
	shaveIce[1].UnInit();
}

Sori::~Sori() {

}

D3DXVECTOR2 pos = D3DXVECTOR2(0, 0);
void Sori::DrawCharacterIcon() {
	 if (weight[0] >= 70)
	{
		 Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH*0.111979f, SCREEN_HEIGHT*0.693287f,0,0, 150, 150);
	} else if (weight[0] >= 60 && weight[0] <= 69)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH*0.111979f, SCREEN_HEIGHT*0.693287f, 0, 0, 150, 150);
	} else if (weight[0] >= 50 && weight[0] <= 59)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH*0.111979f, SCREEN_HEIGHT*0.693287f, 0, 0, 150, 150);
	} else if (weight[0] <= 49)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH*0.111979f, SCREEN_HEIGHT*0.693287f, 0, 0, 150, 150);
	}

	 if (weight[1] >= 70 )
	{
		 Sprite_Draw(TEXTURE_INDEX_ICON_BEAR, SCREEN_WIDTH*0.157552f, SCREEN_HEIGHT*0.756944f, 0, 0, 150, 150);
	} else if (weight[1] >= 60 && weight[1] <= 69)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_DOG, SCREEN_WIDTH*0.157552f, SCREEN_HEIGHT*0.756944f, 0, 0, 150, 150);
	} else if (weight[1] >= 50 && weight[1] <= 59)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_RABBIT, SCREEN_WIDTH*0.157552f, SCREEN_HEIGHT*0.756944f, 0, 0, 150, 150);
	} else if (weight[1] <= 49)
	{
		Sprite_Draw(TEXTURE_INDEX_ICON_HAMSTER, SCREEN_WIDTH*0.157552f, SCREEN_HEIGHT*0.756944f, 0, 0, 150, 150);
	}
}

bool Sori::CollisionWall(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		return true;

	} else {
		return false;
	}
}
bool Sori::Collision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		rotation = c.rotation;

		return true;

	} else {
		return false;
	}
}
bool Sori::CollisionGoal(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		rotation = c.rotation;
		return true;

	} else {
		return false;
	}
}
bool Sori::AccelFloorCollision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit && isSpin == false) {
		isHitSpeedAccelBoard = true;
		PlaySound(SOUND_LABEL_SE_SPEED_ACCEL);
		return true;
	}
	return false;
}
bool Sori::CollisionRight(NPC c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(rightCollider, c.leftCollider)) {
		position += c.leftSpeed*2.0f;
		isNPCcollision = true;
		return true;
	} else {
		isNPCcollision = false;
	}
	return false;
}
bool Sori::CollisionLeft(NPC c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(leftCollider, c.rightCollider)) {
		position += c.rightSpeed*2.0f;
		isNPCcollision = true;
		return true;
	} else {
		isNPCcollision = false;
	}
	return false;
}
bool Sori::CollisionBack(NPC c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(backCollider, c.forwardCollider)) {
		position += c.GetForward() * (c.speed / 2 + c.speedAccel) + (c.centrifugalDirection*c.speed / 2)*2.0f;
		isNPCcollision = true;
		return true;
	} else {
		isNPCcollision = false;
	}
	return false;
}


void Sori::Move() { 
	int BOARD_VALUE1 = BalanceBoard_GetValue(BALANCEBOARD_1P, 4) / BPARD_VALUE_BOARDER;
	int BOARD_VALUE2 = BalanceBoard_GetValue(BALANCEBOARD_2P, 4) / BPARD_VALUE_BOARDER;
	if (fabsf((int)BOARD_VALUE1) < 50) {
		BOARD_VALUE1 = 50;
	}
	if (fabsf((int)BOARD_VALUE2) < 50) {
		BOARD_VALUE2 = 50;
	}
	bool canMoveRight = isHitRightWall == false && isBoundRight == false && isBoundLeft == false && isSpin==false;
	bool canMoveLeft = isHitLeftWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;
	bool boardForward1P = BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF)> BOARD_VALUE1 &&  isSpin == false || BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF)> BOARD_VALUE1 && isSpin == false;
	bool boardForward2P = BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF)> BOARD_VALUE2 && isSpin == false || BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF)> BOARD_VALUE2 && isSpin == false;

	bool boardRight1P = BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1) ||
						BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1);
	bool boardRight2P = BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2) ||
						BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2);

	bool boardLeft1P = BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1) ||
						BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1);
	bool boardLeft2P = BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2) ||
						BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2);

	//正面に移動
	position += GetForward() * (speed/2+speedAccel+ slidSpeed)+ (centrifugalDirection*speed/2);
	position += rightSpeed;
	position += leftSpeed;
	leftSpeed = D3DXVECTOR3(0, 0, 0);
	rightSpeed = D3DXVECTOR3(0, 0, 0);

	if (isGoalGround == true) {
		rotation.x = 0;
		rotation.z = 0;
	}

	//ゴールしたら操作できないようにする
	if (isGoalGround == false) {
		//1Pの移動
		{
			if (Keyboard_IsPress(DIK_W) && isSpin == false  || boardForward1P) {
				//speedがmaxSpeedを超えないようにする
				if (speed < maxSpeed) {
					speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
				}
				//移動方向にキャラクターが傾く
				if (character[0]->inputRotX >= -0.6f) {
					character[0]->inputRotX -= CHARACTER_ROTATION_SPEED/2;
				}
			}
			else if (Keyboard_IsPress(DIK_S) && isSpin == false ) {
				//後ろに移動できないようにする
				if (speed >= 0.001f) {
					speed -= (character[0]->moveAccel + character[1]->moveAccel) / 4;
				}
				//移動方向にキャラクターが傾く
				if (character[0]->inputRotX <= 0.4f) {
					character[0]->inputRotX += CHARACTER_ROTATION_SPEED/2;
				}
			}

			//回転
			if (Keyboard_IsPress(DIK_D) && canMoveRight || boardRight1P && canMoveRight) {
				rightSpeed += GetRight() * ((character[0]->handling + character[1]->handling) / 2);  //GetRight()*移動量

				//左右に移動した時のキャラクターのずれを修正
				character[0]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);
				character[1]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);

				//移動方向にキャラクターが傾く
				if (character[0]->inputRotZ <= 0.8f) {
					character[0]->inputRotZ += CHARACTER_ROTATION_SPEED;
				}

			}
			else if (Keyboard_IsPress(DIK_A) && canMoveLeft || boardLeft1P && canMoveRight) {
				leftSpeed -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

				//左右に移動した時のキャラクターのずれを修正
				character[0]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);
				character[1]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

				//移動方向にキャラクターが傾く
				if (character[0]->inputRotZ >= -0.8f) {
					character[0]->inputRotZ -= CHARACTER_ROTATION_SPEED;
				}
			}
		}


		//2Pの移動
		{
			if (Keyboard_IsPress(DIK_UP) && isSpin == false || boardForward2P) {
				//speedがmaxSpeedを超えないようにする
				if (speed < maxSpeed) {
					speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
				}
				//移動方向にキャラクターが傾く
				if (character[1]->inputRotX >= -0.6f) {
					character[1]->inputRotX -= CHARACTER_ROTATION_SPEED/2;
				}

			}
			else if (Keyboard_IsPress(DIK_DOWN) && isSpin == false) {
				//後ろに移動できないようにする
				if (speed >= 0.001f) {
					speed -= (character[0]->moveAccel + character[1]->moveAccel) / 4;
				}
				//移動方向にキャラクターが傾く
				if (character[1]->inputRotX <= 0.4f) {
					character[1]->inputRotX += CHARACTER_ROTATION_SPEED/2;
				}
			}
			if (Keyboard_IsPress(DIK_RIGHT) && canMoveRight || boardRight2P && canMoveRight) {
				//右に移動
				rightSpeed += GetRight() * ((character[0]->handling + character[1]->handling) / 2);  //GetRight()*移動量

				//左右に移動した時のキャラクターのずれを修正
				character[0]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);
				character[1]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);


				//移動方向にキャラクターが傾く
				if (character[1]->inputRotZ <= 0.8f) {
					character[1]->inputRotZ += CHARACTER_ROTATION_SPEED;
				}

			}
			else if (Keyboard_IsPress(DIK_LEFT) && canMoveLeft || boardLeft2P && canMoveRight) {
				//左に移動
				leftSpeed -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

				//左右に移動した時のキャラクターのずれを修正
				character[0]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);
				character[1]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

				//移動方向にキャラクターが傾く
				if (character[1]->inputRotZ >= -0.8f) {
					character[1]->inputRotZ -= CHARACTER_ROTATION_SPEED;
				}
			}
		}
	}
	//操作していなかったらキャラクターが傾いてるのを直す
	for (int i = 0; i < 2; i++) {
		if (character[i]->inputRotZ > 0.05f) {
			character[i]->inputRotZ -= CHARACTER_ROTATION_SPEED/2;

		} else if (character[i]->inputRotZ < -0.05f) {
			character[i]->inputRotZ += CHARACTER_ROTATION_SPEED/2;
		}

		if (character[i]->inputRotX > 0.03f) {
			character[i]->inputRotX -= CHARACTER_ROTATION_SPEED / 4;

		} else if (character[i]->inputRotX < -0.03f) {
			character[i]->inputRotX += CHARACTER_ROTATION_SPEED / 4;
		}
	}
}
void Sori::Friction() {
	if (speed >= 0.001f) {
		speed -= 0.0002f;
	}
}
void Sori::SlideDown() {
	if (GetForward().y < 0) {
		position -= GetForward()*GetForward().y*0.03f;
	}
	if (GetRight().y > 0) {
		position += GetRight()*-GetRight().y*0.03f;
		if (slidCount < YOKONOSYAMENNNINOTTAATOKASOKUSURUYATU) {
			slidCount += 0.003f;
		}
	}
	if (-GetRight().y > 0) {
		position -= GetRight()*GetRight().y*0.03f;
		if (slidCount < YOKONOSYAMENNNINOTTAATOKASOKUSURUYATU) {
			slidCount += 0.003f;
		}
	}

	if (rotation.z == 0) {
		slidSpeed = slidCount;

	}
	if (slidCount > 0 && GetRight().y == 0 && -GetRight().y==0) {
		slidCount -= 0.0004f;
		isWallSpeedAccel = true;
	} else {
		isWallSpeedAccel = false;
	}
}
void Sori::Bound() {
	//壁に当たった判定
	if (isHitLeftWall == true) {
		boundCount = 0;
		isBoundRight = true;
	}
	if (isHitRightWall == true) {
		boundCount = 0;
		isBoundLeft = true;
	}
	

	//壁に当たった時の移動方向を取得
	if (isSpin == false) {
		spinMoveDirectionRight = GetRight();
	}
	
	if (isBoundRight == true && boundCount <= 50) {
		if (isSpin == false) {
			rightSpeed += GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			rightSpeed.y -= GetRight().y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		} else if (isSpin == true) {
			rightSpeed += spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			rightSpeed.y -= spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		}
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		if (isSpin == false) {
			leftSpeed -= GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			leftSpeed.y += GetRight().y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		} else if (isSpin == true) {
			leftSpeed -= spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			leftSpeed.y += spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		}
		boundCount++;
	} else {
		isBoundLeft = false;
	}
}
void Sori::Spin() {
	int BOARD_VALUE1 = BalanceBoard_GetValue(BALANCEBOARD_1P, 4) / BPARD_VALUE_BOARDER;
	int BOARD_VALUE2 = BalanceBoard_GetValue(BALANCEBOARD_2P, 4) / BPARD_VALUE_BOARDER;
	if (fabsf((int)BOARD_VALUE1) < 50) {
		BOARD_VALUE1 = 50;
	}
	if (fabsf((int)BOARD_VALUE2) < 50) {
		BOARD_VALUE2 = 50;
	}

	bool canMoveRight = isHitRightWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;
	bool canMoveLeft = isHitLeftWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;

	bool boardRight1P = BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1) ||
		BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1);
	bool boardRight2P = BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2) ||
		BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2);

	bool boardLeft1P = BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LF) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1) ||
		BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_LB) > BOARD_VALUE1 && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RF) > BOARD_VALUE1) && !(BalanceBoard_GetValue(BALANCEBOARD_1P, BALANCEBOARD_RB) > BOARD_VALUE1);
	bool boardLeft2P = BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LF) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2) ||
		BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_LB) > BOARD_VALUE2 && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RF) > BOARD_VALUE2) && !(BalanceBoard_GetValue(BALANCEBOARD_2P, BALANCEBOARD_RB) > BOARD_VALUE2);


	if (isGoalGround == false) {
		if (Keyboard_IsPress(DIK_A) && Keyboard_IsPress(DIK_RIGHT) ||
			Keyboard_IsPress(DIK_D) && Keyboard_IsPress(DIK_LEFT) ||
			boardLeft1P && boardRight2P ||
			boardRight1P && boardLeft2P) {
			spinCount++;
			if (spinCount > 20) {
				isSpin = true;
				beforRotation = spinRot;
			}
		} else {
			spinCount = 0;

		}
	}
	if (isSpin == true) {
		spinRot.y += SPIN_SPEED;
		if (beforRotation.y + SPIN_NUM * 6.28f < spinRot.y) {
			isSpin = false;
			spinRot.y = 0;
		}
	}
}
void Sori::SpeedAccel() {
	if (isHitSpeedAccelBoard == true && isSpin==false) {
		speedAccel = ACCEL_FLOOR_ACCEL_SPEED;
		isHitSpeedAccelBoard = false;
	}
	if (speedAccel > 0) {
		speedAccel -= 0.0008f;
	}
}
void Sori::CentrifugalForce() {
	D3DXMATRIX matrixWorld;    //ワールド行列
	D3DXMATRIX centrifugalMtxRot;		   //回転行列

	if (centrifugalRotation.x > rotation.x) {
		centrifugalRotation.x -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.x < rotation.x) {
		centrifugalRotation.x += CENTRIFUGAL_FORCE;
	}

	if (centrifugalRotation.y > rotation.y) {
		centrifugalRotation.y -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.y < rotation.y) {
		centrifugalRotation.y += CENTRIFUGAL_FORCE;
	}

	if (centrifugalRotation.z > rotation.z) {
		centrifugalRotation.z -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.z < rotation.z) {
		centrifugalRotation.z += CENTRIFUGAL_FORCE;
	}


	//行列を初期化
	D3DXMatrixIdentity(&matrixWorld);
	D3DXMatrixIdentity(&centrifugalMtxRot);

	//回転行列を作成
	D3DXMatrixRotationYawPitchRoll(&centrifugalMtxRot, centrifugalRotation.y, centrifugalRotation.x, centrifugalRotation.z);
	D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &centrifugalMtxRot);

	//行列から回転させたベクトルを取り出す
	centrifugalDirection = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);

}
void Sori::SetCollisionTransform() {
	//床との当たり判定
	collisoin.position = position;
	collisoin.rotation = rotation;
	collisoin.size.x = 1;
	collisoin.size.y = -1.0f;
	collisoin.size.z = 0;

	//NPCとの当たり判定用
	rightCollider.position = position;
	rightCollider.position.x += 0.4f;
	rightCollider.rotation = rotation;
	rightCollider.size.x = 1.8f;
	rightCollider.size.y = 1;
	rightCollider.size.z = 5;

	leftCollider.position = position;
	leftCollider.position.x -= 0.4f;
	leftCollider.rotation = rotation;
	leftCollider.size.x = 1.8f;
	leftCollider.size.y = 1;
	leftCollider.size.z = 5;

	forwardCollider.position = position;
	forwardCollider.position.z += 2.0f;
	forwardCollider.rotation = rotation;
	forwardCollider.size.x = 1.8f;
	forwardCollider.size.y = 1;
	forwardCollider.size.z = 3;

	backCollider.position = position;
	backCollider.position.z -= 2.0f;
	backCollider.rotation = rotation;
	backCollider.size.x = 1.8f;
	backCollider.size.y = 1;
	backCollider.size.z = 3;

	//障害物との当たり判定
	objCollider.position = position;
	objCollider.size.x = 1;
	objCollider.size.y = 1;
	objCollider.size.z = 5;
	objCollider.rotation = rotation;
}
void Sori::CharacterTouch() {
	for (int i = 0; i < 2; i++) {
		character[i]->position = GetUp()*1.75f + position;
		character[i]->position -= GetForward()*(float)i + GetForward()*0.3f + GetForward()*0.2f;
		character[i]->rotation = rotation + spinRot;
		character[i]->rotation.z += character[i]->inputRotZ - rotation.z * 2;
	}

}
void Sori::ReceiveSpinMove() {
	if (isReceiveMoveForward == true) {
		position += receiveSpinSpeed;

	} else if (isReceiveMoveRight == true) {
		position += receiveSpinSpeed;
		receiveSpinSpeed.y *= GetRight().y;

	} else if (isReceiveMoveLeft == true) {
		position -= receiveSpinSpeed;
		receiveSpinSpeed.y *= -GetRight().y;
	}
	receiveSpinSpeed *= 0.8f;
}

//ifでweightに値の範囲を指定してセットするキャラを決める
void Sori::SetCharacter(float weight1, float weight2) {
	weight[0] = weight1;
	weight[1] = weight2;
	//キャラの選定
	 if (weight1 >= 70 )
	{
		character[0] = new Bear();
	} else if (weight1 >= 60 && weight1 <= 69)
	{
		character[0] = new Dog();
	} else if (weight1 >= 50 && weight1 <= 59)
	{
		character[0] = new Rabbit();
	} else if (weight1 <= 49)
	{
		character[0] = new Hamster();
	}


	if (weight2 >= 70)
	{
		character[1] = new Bear();
	} else if (weight2 >= 60 && weight2 <= 69)
	{
		character[1] = new Dog();
	} else if (weight2 >= 50 && weight2 <= 59)
	{
		character[1] = new Rabbit();
	} else if (weight2 <= 49)
	{
		character[1] = new Hamster();
	}

}
D3DXVECTOR3 Sori::GetForward() {
	D3DXMATRIX matrixWorld;    //ワールド行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 Sori::GetRight() {
	D3DXMATRIX matrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;
	D3DXVECTOR3 direction;
	direction.x = 1;
	direction.y = 0;
	direction.z = 0;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._11, matrixWorld._12, matrixWorld._13);
	}
	return direction;
}
D3DXVECTOR3 Sori::GetUp() {
	D3DXMATRIX matrixWorld;    //頂点の行列
	D3DXMATRIX mtxRot;		   //回転行列
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 1;
	direction.z = 0;

	{
		//行列を初期化
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//回転行列を作成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//行列から回転させたベクトルを取り出す
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}