#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"

void Obstacle::Init() {
	isBroken = false;
	cube.scale = D3DXVECTOR3(1.5f, 2, 1.5f);
}
void Obstacle::Update() {
	BoxCollider boxCollider;
	cube.position = positopn;
	cube.rotation = rotation;
	bool isHit = boxCollider.Collider(cube.collider, GetPlayer().objCollider);
	if (isHit == true) {
		isBroken = true;
	}

	if (isBroken == true) {
		positopn += GetPlayer().GetForward()*2;
		positopn.y += 0.2f;
	}
}
void Obstacle::Draw() {
	cube.Draw(TEXTURE_INDEX_MAX);
}
void Obstacle::UnInit() {

}