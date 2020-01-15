#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"

static int frameCount = 0;

void Obstacle::Init() {
	isBroken = false;
	cube.scale = D3DXVECTOR3(1.5f, 2, 1.5f);
	frameCount = 0;
}
void Obstacle::Update() {
	BoxCollider boxCollider;

	cube.position = position;
	cube.rotation = rotation;

	//衝突判定
	bool isHit = boxCollider.Collider(cube.collider, GetPlayer()->objCollider);

	//ゲーム開始時に最初のフレームだけpositionがバグるので1フレーム目だけ処理しない
	if (isHit == true && frameCount >0) {
		isBroken = true;

		//スピン中は減速しない
		if (GetPlayer()->isSpin == false) {
			GetPlayer()->speed *= 0.5f;
			GetPlayer()->speedAccel *= 0.5f;
			GetPlayer()->slidCount *= 0.5f;
		}
	}

	//吹っ飛び処理
	if (isBroken == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetPlayer()->position - position);
		position += moveDirection *2;
		position.y += 0.2f;
	}

	frameCount++;
}
void Obstacle::Draw() {
	cube.Draw(TEXTURE_INDEX_MAX);
}
void Obstacle::UnInit() {

}