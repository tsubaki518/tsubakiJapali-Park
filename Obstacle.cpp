#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"
#include"NPC.h"

void Obstacle::Init() {
	cube[0].scale = D3DXVECTOR3(1.5f, 1.5f, 1.5f);
	cube[1].scale = D3DXVECTOR3(1.5f, 1.5f, 1.5f)*0.6f;
	frameCount = 0;
	isBrokenPlayer = false;
	isBrokenNPC = false;
}
void Obstacle::Update() {
	BoxCollider boxCollider;


	if (isBrokenPlayer == false && isBrokenNPC == false) {
		cube[0].position = position;
		cube[0].rotation = rotation;
		cube[1].position = cube[0].GetUp()*1.2+ cube[0].position;
		cube[1].rotation = rotation;
	}

	//衝突判定
	bool isHitPlayer = boxCollider.Collider(cube[0].collider, GetPlayer()->objCollider);
	bool isHitNPC = boxCollider.Collider(cube[0].collider, GetNPC()->objCollider);

	//ゲーム開始時に最初のフレームだけpositionがバグるので1フレーム目だけ処理しない
	if (frameCount > 0) {
		//プレイヤーに衝突した場合
		if (isHitPlayer == true) {
			isBrokenPlayer = true;

			//スピン中は減速しない
			if (GetPlayer()->isSpin == false) {
				GetPlayer()->speed *= 0.5f;
				GetPlayer()->speedAccel *= 0.5f;
				GetPlayer()->slidCount *= 0.5f;
			}
		}

		//NPCに衝突した場合
		if (isHitNPC == true) {
			isBrokenNPC = true;

			//スピン中は減速しない
			if (GetNPC()->isSpin == false) {
				GetNPC()->speed *= 0.5f;
				GetNPC()->speedAccel *= 0.5f;
				GetNPC()->slidCount *= 0.5f;
			}
		}
	}

	//吹っ飛び処理
	//プレイヤーが当たった場合の吹っ飛び処理
	if (isBrokenPlayer == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetPlayer()->position - cube[0].position);
		cube[0].position += moveDirection *2;

		moveDirection = -(GetPlayer()->position - cube[1].position);
		cube[1].position += moveDirection * 2;
		cube[1].position.y += 0.2f;
	}

	//NPCが当たった場合の吹っ飛び処理
	if (isBrokenNPC == true) {
		D3DXVECTOR3 moveDirection;
		moveDirection = -(GetNPC()->position - cube[0].position);
		cube[0].position += moveDirection * 2;

		moveDirection = -(GetNPC()->position - cube[1].position);
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