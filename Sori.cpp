#include"Sori.h"
#include"texture.h"
#include"input.h"

#define CHARACTER_ROTATION_SPEED 0.1f
#define SPIN_NUM 2
#define SPIN_SPEED 0.5f

Sori::Sori() {
	position.y = 10;
}

void Sori::Init(float weight1, float weight2) {
	bobsled.Init("asset/model/Bobsled/bobsleight.x");

	//キャラクターをセットする
	SetCharacter(weight1, weight2);
	character[0]->Init();
	character[1]->Init();

	//最高速の設定
	maxSpeed = (character[0]->maxSpeed + character[1]->maxSpeed) / 2;
}

void Sori::Update() {
	//当たり判定の情報を入れる
	collisoin.position = position;
	collisoin.rotation = rotation;
	collisoin.size.x = 0;
	collisoin.size.y = -1;
	collisoin.size.z = 0;

	//キャラクターの情報を入れる
	for (int i = 0; i < 2; i++) {
		character[i]->position.x =-GetUp().x+ position.x;
		character[i]->position.y = GetUp().y+position.y+1;
		character[i]->position.z = GetUp().z+position.z;
		character[i]->position += GetForward()*(float)i + GetForward()*0.5f;
		character[i]->rotation = rotation;
		character[i]->rotation.z += character[i]->inputRotZ;
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

	
}
void Sori::Draw() {
	//ソリ用の行列を作成
	{
		D3DXMATRIX g_mtxWorld;
		D3DXMATRIX mtxScl;
		D3DXMATRIX mtxRot;
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f, rotation.z);
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
}
void Sori::UnInit() {
	bobsled.Draw();
	character[0]->UnInit();
	character[1]->UnInit();

	delete character[0];
	delete character[1];
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
		if (isSpin == false) {
			rotation = -c.rotation;
			rotation.x += 0.1f;
		}
		return true;

	} else {
		return false;
	}
}


void Sori::Move() {
	bool canMoveRight = isHitRightWall == false && isBoundRight == false && isBoundLeft == false && isSpin==false;
	bool canMoveLeft = isHitLeftWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;

	//正面に移動
	if (isSpin == false) {
		position -= GetForward() * speed;
		spinMoveDirection = GetForward() * speed;

	} else if (isSpin == true) {
		position -= spinMoveDirection;
	}

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
		if (character[i]->inputRotZ > 0) {
			character[i]->inputRotZ -= CHARACTER_ROTATION_SPEED/2;

		} else if (character[i]->inputRotZ < 0) {
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
	
	
	if (isBoundRight == true && boundCount <= 100) {
		position += GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		position -= GetRight() * ((character[0]->handling + character[1]->handling) );  //GetRight()*移動量
		boundCount++;
	} else {
		isBoundLeft = false;
	}
}
void Sori::Spin() {
	if (Keyboard_IsPress(DIK_A) && Keyboard_IsPress(DIK_RIGHT) && isSpin==false ||
		Keyboard_IsPress(DIK_D) && Keyboard_IsPress(DIK_LEFT) && isSpin == false) {
		isSpin = true;
		beforRotation = rotation;
	}

	if (isSpin == true) {
		rotation.y += SPIN_SPEED;
		if (beforRotation.y + SPIN_NUM * 6.28f <= rotation.y) {
			isSpin = false;
		}
	}
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
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y + 3.1415f, rotation.x - 0.1f, rotation.z);
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
	direction.y *= -1;
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