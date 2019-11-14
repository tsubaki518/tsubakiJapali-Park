#include"Sori.h"
#include"texture.h"
#include"input.h"

#define MOVE_HORIZON_SPEED 0.1f

Sori::Sori() {
	cube.position.y = 10;
	cube.scale.z = 2;
}

void Sori::Update() {
	//--------------------�ړ�---------------------------------------
	{
		if (Keyboard_IsPress(DIK_UP)) {
			cube.position += cube.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_DOWN)) {
			cube.position -= cube.GetForward() * 0.1f;
		}
		if (Keyboard_IsPress(DIK_RIGHT)) {
			//�E�Ɉړ�
			cube.position += cube.GetRight() * MOVE_HORIZON_SPEED;  //GetRight()*�ړ���

		} else if (Keyboard_IsPress(DIK_LEFT)) {
			//���Ɉړ�
			cube.position -= cube.GetRight() * MOVE_HORIZON_SPEED;
		}
	}
	//---------------------------------------------------------------



	//---------------�΂ߔ���̃f�o�b�O�p--------------//
	{
		if (Keyboard_IsPress(DIK_W)) {
			//���ʂɈړ�
			cube.position += cube.GetForward() * 0.1f;
		} else if (Keyboard_IsPress(DIK_S)) {
			//���Ɉړ�
			cube.position -= cube.GetForward() * 0.1f;
		}

		//��]
		if (Keyboard_IsPress(DIK_D)) {
			cube.rotation.y += 0.02f;
		} else if (Keyboard_IsPress(DIK_A)) {
			cube.rotation.y -= 0.02f;
		}

		if (Keyboard_IsPress(DIK_SPACE)) {
			cube.position.y += 0.2f;
		}
	}
	//------------------------------------------------//
	

}

void Sori::Draw() {
	cube.Draw(TEXTURE_INDEX_CEMENT);
}

bool Sori::Collision(Collider3D c) {
	BoxCollider collider;

	if (collider.Collider(cube.collider, c)) {
		cube.rotation = c.rotation;
		return true;

	} else {
		return false;
	}
}
bool Sori::Collision2(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(cube.collider, c).isHit) {
		cube.position.y = collider.Collider(cube.collider, c).posY;
		cube.rotation = c.rotation;
		return true;

	} else {
		return false;
	}
}

Sori::~Sori() {

}