#include"Sori.h"
#include"texture.h"
#include"input.h"

#define MOVE_HORIZON_SPEED 0.1f

Sori::Sori() {
	cube.position.y = 10;
	cube.scale.z = 2;
}

void Sori::Update() {
	//�ō����̐ݒ�
	maxSpeed = (character[0].maxSpeed + character[1].maxSpeed) / 2;

	//�ړ�����
	Move();

	//���C
	Friction();

	//�Ζʂɏ���Ă����犊��
	SlideDown();

	//---------------�f�o�b�O�p�̈ړ�(�ړ��ʂ����)--------------//
	{
		if (Keyboard_IsPress(DIK_W)) {
			//���ʂɈړ�
			cube.position += cube.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_S)) {
			//���Ɉړ�
			cube.position -= cube.GetForward() * 0.1f;
		}

		//��]
		if (Keyboard_IsPress(DIK_D) && canMoveRight==true) {
			cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*�ړ���
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
	//���ʂɈړ�
	cube.position += cube.GetForward() * speed;

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
	if (Keyboard_IsPress(DIK_RIGHT) && canMoveRight==true) {
		//�E�Ɉړ�
		//cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*�ړ���
		cube.position += cube.GetRight() * ((character[0].handling+ character[1].handling)/2);  //GetRight()*�ړ���
		
	} else if (Keyboard_IsPress(DIK_LEFT) && canMoveLeft==true) {
		//���Ɉړ�
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