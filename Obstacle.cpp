#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"

static int frameCount = 0;

void Obstacle::Init() {
	isBroken = false;
	cube[0].scale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);
	cube[1].scale = D3DXVECTOR3(1.5f, 1.5f, 1.5f)*0.6f;
	frameCount = 0;
}
void Obstacle::Update() {
	BoxCollider boxCollider;

	if (isBroken == false) {
		cube[0].position = position;
		cube[0].rotation = rotation;
		cube[1].position = cube[0].GetUp()*1.4+ cube[0].position;
		cube[1].rotation = rotation;
	}

	//�Փ˔���
	bool isHit = boxCollider.Collider(cube[0].collider, GetPlayer()->objCollider);

	//�Q�[���J�n���ɍŏ��̃t���[������position���o�O��̂�1�t���[���ڂ����������Ȃ�
	if (isHit == true && frameCount >0) {
		isBroken = true;

		//�X�s�����͌������Ȃ�
		if (GetPlayer()->isSpin == false) {
			GetPlayer()->speed *= 0.5f;
			GetPlayer()->speedAccel *= 0.5f;
			GetPlayer()->slidCount *= 0.5f;
		}
	}

	//������я���
	if (isBroken == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetPlayer()->position - cube[0].position);
		cube[0].position += moveDirection *2;

		moveDirection = -(GetPlayer()->position - cube[1].position);
		cube[1].position += moveDirection * 2;
		cube[1].position.y += 0.2f;
	}

	frameCount++;
}
void Obstacle::Draw() {
	cube[0].Draw(TEXTURE_INDEX_MAX);
	cube[1].Draw(TEXTURE_INDEX_MAX);
}
void Obstacle::UnInit() {

}