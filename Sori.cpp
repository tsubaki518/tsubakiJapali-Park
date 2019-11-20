#include"Sori.h"
#include"texture.h"
#include"input.h"

#define MOVE_HORIZON_SPEED 0.1f

Sori::Sori() {
	cube.position.y = 10;
	cube.scale.z = 2;
}

void Sori::Update() {
	//最高速の設定
	maxSpeed = (character[0].maxSpeed + character[1].maxSpeed) / 2;

	//移動処理
	Move();

	//摩擦
	Friction();

	//斜面に乗っていたら滑る
	SlideDown();

	//---------------デバッグ用の移動(移動量が一定)--------------//
	{
		if (Keyboard_IsPress(DIK_W)) {
			//正面に移動
			cube.position += cube.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_S)) {
			//後ろに移動
			cube.position -= cube.GetForward() * 0.1f;
		}

		//回転
		if (Keyboard_IsPress(DIK_D) && canMoveRight==true) {
			cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*移動量
		} else if (Keyboard_IsPress(DIK_A) && canMoveLeft==true) {
			cube.position -= cube.GetRight() * MOVE_HORIZON_SPEED;
		}

		if (Keyboard_IsPress(DIK_SPACE)) {
			cube.position.y += 0.2f;
		}
	}
}

void Sori::Draw() {
	cube.Draw(TEXTURE_INDEX_MAX,character[0].color);
}

bool Sori::CollisionWall(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(cube.collider, c).isHit) {
		cube.position += collider.Collider(cube.collider, c).addPosition;
		return true;

	} else {
		return false;
	}
}
bool Sori::Collision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(cube.collider, c).isHit) {
		cube.position += collider.Collider(cube.collider, c).addPosition;
		cube.rotation = c.rotation;
		return true;

	} else {
		return false;
	}
}

Sori::~Sori() {

}



void Sori::Move() {
	//正面に移動
	cube.position += cube.GetForward() * speed;

	if (Keyboard_IsPress(DIK_UP)) {
		//speedがmaxSpeedを超えないようにする
		if (speed < maxSpeed) {
			//speed += 0.0005f;
			speed += (character[0].moveAccel + character[1].moveAccel) / 2;
		}
	} else if (Keyboard_IsPress(DIK_DOWN)) {
		//後ろに移動できないようにする
		if (speed >= 0.001f) {
			//speed -= 0.0005f;
			speed -= (character[0].moveAccel + character[1].moveAccel) / 2;
		}
	}
	if (Keyboard_IsPress(DIK_RIGHT) && canMoveRight==true) {
		//右に移動
		//cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*移動量
		cube.position += cube.GetRight() * ((character[0].handling+ character[1].handling)/2);  //GetRight()*移動量
		
	} else if (Keyboard_IsPress(DIK_LEFT) && canMoveLeft==true) {
		//左に移動
		cube.position -= cube.GetRight() * ((character[0].handling + character[1].handling) / 2);
	}
}
void Sori::Friction() {
	if (speed >= 0.001f) {
		speed -= 0.0002f;
	}
}
void Sori::SlideDown() {
	if (cube.GetForward().y < 0) {
		cube.position += cube.GetForward()*-cube.GetForward().y*0.03f;
	}
	if (cube.GetRight().y < 0) {
		cube.position += cube.GetRight()*-cube.GetRight().y*0.03f;
	}
	if (-cube.GetRight().y < 0) {
		cube.position -= cube.GetRight()*cube.GetRight().y*0.03f;
	}
}