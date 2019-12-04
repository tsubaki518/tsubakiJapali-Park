#include"Sori.h"
#include"texture.h"
#include"input.h"
#include"debug_font.h"

#define CHARACTER_ROTATION_SPEED 0.1f
#define SPIN_NUM 4
#define SPIN_SPEED 1.0f
#define ACCEL_FLOOR_ACCEL_SPEED 0.3f
#define CENTRIFUGAL_FORCE 0.035f


Sori::Sori() {

}

void Sori::Init(float weight1, float weight2) {
	
	//キャラクターをセットする
	SetCharacter(weight1, weight2);
	character[1]->Init();
	character[0]->Init();
	bobsled.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv022.jpg");


	//------------------スピードなどのパラメータの初期化----------------------------//
	//最高速の設定
	maxSpeed = (character[0]->maxSpeed + character[1]->maxSpeed) / 2;

	speedAccel = 0;//加速床に当たったときに加速する速度を初期化する

	//プレイヤーの初期位置
	position = D3DXVECTOR3(2, -10.10f, 2);
	rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0, 0);
	isGoalGround = false;
	isSpin = false;

	//遠心力初期化
	centrifugalDirection = D3DXVECTOR3(0, 0, 0);

	//キャラクターの情報を入れる
	for (int i = 0; i < 2; i++) {
		character[i]->position = GetUp()*1.75f + position;
		character[i]->position += GetForward()*(float)i - GetForward()*0.7f - GetForward()*0.5f;
		character[i]->rotation = rotation;
		character[i]->rotation.z += character[i]->inputRotZ - rotation.z * 2;
	}
}
void Sori::Update() {
	//当たり判定の情報を入れる
	collisoin.position = position;
	collisoin.rotation = rotation;
	collisoin.size.x = 1;
	collisoin.size.y = -1.0f;
	collisoin.size.z = 0;

	//キャラクターをソリに追従させる
	for (int i = 0; i < 2; i++) {
		character[i]->position = GetUp()*1.75f + position;
		character[i]->position += GetForward()*(float)i - GetForward()*0.7f-GetForward()*0.5f;
		character[i]->rotation = rotation+spinRot;
		character[i]->rotation.z += character[i]->inputRotZ-rotation.z*2;
	}

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

		//回転行列を作成＆ワールド行列へ合成
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

		//回転行列を作成＆ワールド行列へ合成
		D3DXMatrixRotationYawPitchRoll(&spinMtxRot, spinRot.y, spinRot.x, spinRot.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &spinMtxRot);

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
}
void Sori::UnInit() {
	for (int i = 0; i < 2; i++) {
		character[i]->UnInit();
		delete character[i];
	}
	bobsled.UnInit();
}

Sori::~Sori() {

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
		if (isSpin == false) {
			rotation = c.rotation;
		}
		return true;

	} else {
		return false;
	}
}
bool Sori::CollisionGoal(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		speed = 0;
		return true;

	} else {
		return false;
	}
}
void Sori::AccelFloorCollision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit && isSpin == false) {
		isHitSpeedAccelBoard = true;
	}
}


void Sori::Move() {
	bool canMoveRight = isHitRightWall == false && isBoundRight == false && isBoundLeft == false && isSpin==false;
	bool canMoveLeft = isHitLeftWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;

	//正面に移動
	position += GetForward() * (speed/2+speedAccel)+ (centrifugalDirection*speed/2);

	//1Pの移動
	{
		if (Keyboard_IsPress(DIK_UP) &&isSpin==false) {
			//speedがmaxSpeedを超えないようにする
			if (speed < maxSpeed) {
				speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
			}
		} else if (Keyboard_IsPress(DIK_DOWN) && isSpin == false) {
			//後ろに移動できないようにする
			if (speed >= 0.001f) {
				speed -= (character[0]->moveAccel + character[1]->moveAccel) / 4;
			}
		}
		if (Keyboard_IsPress(DIK_RIGHT) && canMoveRight) {
			//右に移動
			position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);  //GetRight()*移動量

			//左右に移動した時のキャラクターのずれを修正
			character[0]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);
			character[1]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);


			//移動方向にキャラクターが傾く
			if (character[0]->inputRotZ <= 0.8f) {
				character[0]->inputRotZ += CHARACTER_ROTATION_SPEED;
			}

		} else if (Keyboard_IsPress(DIK_LEFT) && canMoveLeft) {
			//左に移動
			position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

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
		if (Keyboard_IsPress(DIK_W) && isSpin == false) {
			//speedがmaxSpeedを超えないようにする
			if (speed < maxSpeed) {
				speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
			}
		} else if (Keyboard_IsPress(DIK_S) && isSpin == false) {
			//後ろに移動できないようにする
			if (speed >= 0.001f) {
				speed -= (character[0]->moveAccel + character[1]->moveAccel) / 4;
			}
		}

		//回転
		if (Keyboard_IsPress(DIK_D) &&canMoveRight) {
			position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);;  //GetRight()*移動量

			//左右に移動した時のキャラクターのずれを修正
			character[0]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);
			character[1]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);

			//移動方向にキャラクターが傾く
			if (character[1]->inputRotZ <= 0.8f) {
				character[1]->inputRotZ += CHARACTER_ROTATION_SPEED;
			}

		} else if (Keyboard_IsPress(DIK_A) && canMoveLeft) {
			position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

			//左右に移動した時のキャラクターのずれを修正
			character[0]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);
			character[1]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

			//移動方向にキャラクターが傾く
			if (character[1]->inputRotZ >= -0.8f) {
				character[1]->inputRotZ -= CHARACTER_ROTATION_SPEED;
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
	if (GetRight().y < 0) {
		position += GetRight()*-GetRight().y*0.03f;
	}
	if (-GetRight().y < 0) {
		position -= GetRight()*GetRight().y*0.03f;
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
	
	if (isBoundRight == true && boundCount <= 100) {
		if (isSpin == false) {
			position += GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			position.y -= GetRight().y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		} else if (isSpin == true) {
			position += spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			position.y -= spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		}
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		if (isSpin == false) {
			position -= GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			position.y += GetRight().y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		} else if (isSpin == true) {
			position -= spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
			position.y += spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//跳ね返ってる間にスピンするとステージ外に行くバグの対策
		}
		boundCount++;
	} else {
		isBoundLeft = false;
	}
}
void Sori::Spin() {
	if (Keyboard_IsPress(DIK_A) && Keyboard_IsPress(DIK_RIGHT) ||
		Keyboard_IsPress(DIK_D) && Keyboard_IsPress(DIK_LEFT) ) {
		isSpin = true;
		beforRotation = spinRot;
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

//ifでweightに値の範囲を指定してセットするキャラを決める
void Sori::SetCharacter(float weight1, float weight2) {

	//キャラの選定
	if (weight1 >= 80)
	{
		character[0] = new Elephant();

	} else if (weight1 >= 70 && weight1 <= 79)
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


	if (weight2 >= 80)
	{
		character[1] = new Elephant;

	} else if (weight2 >= 70 && weight2 <= 79)
	{
		character[1] = new Bear;
	} else if (weight2 >= 60 && weight2 <= 69)
	{
		character[1] = new Dog;
	} else if (weight2 >= 50 && weight2 <= 59)
	{
		character[1] = new Rabbit;
	} else if (weight2 <= 49)
	{
		character[1] = new Hamster;
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