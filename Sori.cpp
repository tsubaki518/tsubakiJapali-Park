#include"Sori.h"
#include"texture.h"
#include"input.h"

#define MOVE_HORIZON_SPEED 0.1f

Sori::Sori() {
	bobsled.position.y = 10;
}

void Sori::Init() {
	bobsled.LoadMesh("asset/model/bobsleight.x");
}

void Sori::Update() {
	//�����蔻��̏�������
	collisoin.position = bobsled.position;
	collisoin.rotation = bobsled.rotation;
	collisoin.size.x = 0;
	collisoin.size.y = -1;
	collisoin.size.z = 0;

	//�ō����̐ݒ�
	maxSpeed = (character[0].maxSpeed + character[1].maxSpeed) / 2;

	//�ړ�����
	Move();

	//���C
	Friction();

	//�Ζʂɏ���Ă����犊��
	SlideDown();

	//�ǂɓ��������璵�˕Ԃ�
	Bound();

	//---------------�f�o�b�O�p�̈ړ�(�ړ��ʂ����)--------------//
	{
		if (Keyboard_IsPress(DIK_W)) {
			//���ʂɈړ�
			bobsled.position += bobsled.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_S)) {
			//���Ɉړ�
			bobsled.position -= bobsled.GetForward() * 0.1f;
		}

		//��]
		if (Keyboard_IsPress(DIK_D) && isHitRightWall ==false) {
			bobsled.position += bobsled.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*�ړ���
		} else if (Keyboard_IsPress(DIK_A) && isHitLeftWall ==false) {
			bobsled.position -= bobsled.GetRight() * MOVE_HORIZON_SPEED;
		}

		if (Keyboard_IsPress(DIK_SPACE)) {
			bobsled.position.y += 0.2f;
		}
	}
}
void Sori::Draw() {
	bobsled.RenderParactice();
}
void Sori::UnInit() {
	bobsled.CleanUp();
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
		return true;

	} else {
		return false;
	}
}


void Sori::Move() {
	bool isMoveRight = Keyboard_IsPress(DIK_RIGHT) && isHitRightWall == false && isBoundRight == false && isBoundLeft == false;
	bool isMoveLeft = Keyboard_IsPress(DIK_LEFT) && isHitLeftWall == false && isBoundRight == false && isBoundLeft == false;

	//���ʂɈړ�
	bobsled.position += bobsled.GetForward() * speed;

	if (Keyboard_IsPress(DIK_UP)) {
		//speed��maxSpeed�𒴂��Ȃ��悤�ɂ���
		if (speed < maxSpeed) {
			//speed += 0.0005f;
			speed += (character[0].moveAccel + character[1].moveAccel) / 2;
		}
	} else if (Keyboard_IsPress(DIK_DOWN)) {
		//���Ɉړ��ł��Ȃ��悤�ɂ���
		if (speed >= 0.001f) {
			//speed -= 0.0005f;
			speed -= (character[0].moveAccel + character[1].moveAccel) / 2;
		}
	}
	if (isMoveRight) {
		//�E�Ɉړ�
		//cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*�ړ���
		bobsled.position += bobsled.GetRight() * ((character[0].handling+ character[1].handling)/2);  //GetRight()*�ړ���
		
	} else if (isMoveLeft) {
		//���Ɉړ�
		bobsled.position -= bobsled.GetRight() * ((character[0].handling + character[1].handling) / 2);
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
	//�ǂɓ�����������
	if (isHitLeftWall == true) {
		boundCount = 0;
		isBoundRight = true;
	}
	if (isHitRightWall == true) {
		boundCount = 0;
		isBoundLeft = true;
	}
	
	
	if (isBoundRight == true && boundCount <= 100) {
		bobsled.position += bobsled.GetRight() * ((character[0].handling + character[1].handling));  //GetRight()*�ړ���
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		bobsled.position -= bobsled.GetRight() * ((character[0].handling + character[1].handling) );  //GetRight()*�ړ���
		boundCount++;
	} else {
		isBoundLeft = false;
	}
}