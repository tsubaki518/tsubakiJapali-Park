#include"Sori.h"
#include"texture.h"
#include"input.h"

#define MOVE_HORIZON_SPEED 0.1f

Sori::Sori() {
	bobsled.position.y = 10;
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
	collisoin.position = bobsled.position;
	collisoin.rotation = bobsled.rotation;
	collisoin.size.x = 0;
	collisoin.size.y = -1;
	collisoin.size.z = 0;

	//キャラクターの情報を入れる
	for (int i = 0; i < 2; i++) {
		character[i]->model->position.x =-bobsled.GetUp().x+ bobsled.position.x;
		character[i]->model->position.y = bobsled.GetUp().y+bobsled.position.y+1;
		character[i]->model->position.z = bobsled.GetUp().z+bobsled.position.z;
		character[i]->model->position += bobsled.GetForward()*(float)i + bobsled.GetForward()*0.5f;
		character[i]->model->rotation = bobsled.rotation;
	}

	//移動処理
	Move();

	//摩擦
	Friction();

	//斜面に乗っていたら滑る
	SlideDown();

	//壁に当たったら跳ね返る
	Bound();

	//---------------デバッグ用の移動(移動量が一定)--------------//
	{
		if (Keyboard_IsPress(DIK_W)) {
			//正面に移動
			bobsled.position -= bobsled.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_S)) {
			//後ろに移動
			bobsled.position += bobsled.GetForward() * 0.1f;
		}

		//回転
		if (Keyboard_IsPress(DIK_D) && isHitRightWall ==false) {
			bobsled.position += bobsled.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*移動量
			
			//左右に移動した時のキャラクターのずれを修正
			character[0]->model->position += bobsled.GetRight() * MOVE_HORIZON_SPEED;
			character[1]->model->position += bobsled.GetRight() * MOVE_HORIZON_SPEED;
		} else if (Keyboard_IsPress(DIK_A) && isHitLeftWall ==false) {
			bobsled.position -= bobsled.GetRight() * MOVE_HORIZON_SPEED;

			//左右に移動した時のキャラクターのずれを修正
			character[0]->model->position -= bobsled.GetRight() * MOVE_HORIZON_SPEED;
			character[1]->model->position -= bobsled.GetRight() * MOVE_HORIZON_SPEED;
		}

		if (Keyboard_IsPress(DIK_SPACE)) {
			bobsled.position.y += 0.2f;
		}
	}
}
void Sori::Draw() {
	bobsled.Draw();
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
		bobsled.position += collider.Collider(collisoin, c).addPosition;
		return true;

	} else {
		return false;
	}
}
bool Sori::Collision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		bobsled.position += collider.Collider(collisoin, c).addPosition;
		bobsled.rotation = -c.rotation;
		bobsled.rotation.x += 0.1f;
		return true;

	} else {
		return false;
	}
}


void Sori::Move() {
	bool isMoveRight = Keyboard_IsPress(DIK_RIGHT) && isHitRightWall == false && isBoundRight == false && isBoundLeft == false;
	bool isMoveLeft = Keyboard_IsPress(DIK_LEFT) && isHitLeftWall == false && isBoundRight == false && isBoundLeft == false;

	//正面に移動
	bobsled.position -= bobsled.GetForward() * speed;

	if (Keyboard_IsPress(DIK_UP)) {
		//speedがmaxSpeedを超えないようにする
		if (speed < maxSpeed) {
			//speed += 0.0005f;
			speed += (character[0]->moveAccel + character[1]->moveAccel) / 2;
		}
	} else if (Keyboard_IsPress(DIK_DOWN)) {
		//後ろに移動できないようにする
		if (speed >= 0.001f) {
			//speed -= 0.0005f;
			speed -= (character[0]->moveAccel + character[1]->moveAccel) / 2;
		}
	}
	if (isMoveRight) {
		//右に移動
		//cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*移動量
		bobsled.position += bobsled.GetRight() * ((character[0]->handling+ character[1]->handling)/2);  //GetRight()*移動量

		//左右に移動した時のキャラクターのずれを修正
		character[0]->model->position+= bobsled.GetRight() * ((character[0]->handling + character[1]->handling) / 2);
		character[1]->model->position += bobsled.GetRight() * ((character[0]->handling + character[1]->handling) / 2);
		
	} else if (isMoveLeft) {
		//左に移動
		bobsled.position -= bobsled.GetRight() * ((character[0]->handling + character[1]->handling) / 2);

		//左右に移動した時のキャラクターのずれを修正
		character[0]->model->position -= bobsled.GetRight() * ((character[0]->handling + character[1]->handling) / 2);
		character[1]->model->position -= bobsled.GetRight() * ((character[0]->handling + character[1]->handling) / 2);
	}
}
void Sori::Friction() {
	if (speed >= 0.001f) {
		speed -= 0.0002f;
	}
}
void Sori::SlideDown() {
	if (bobsled.GetForward().y < 0) {
		bobsled.position += bobsled.GetForward()*-bobsled.GetForward().y*0.03f;
	}
	if (bobsled.GetRight().y < 0) {
		bobsled.position += bobsled.GetRight()*-bobsled.GetRight().y*0.03f;
	}
	if (-bobsled.GetRight().y < 0) {
		bobsled.position -= bobsled.GetRight()*bobsled.GetRight().y*0.03f;
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
		bobsled.position += bobsled.GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*移動量
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		bobsled.position -= bobsled.GetRight() * ((character[0]->handling + character[1]->handling) );  //GetRight()*移動量
		boundCount++;
	} else {
		isBoundLeft = false;
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