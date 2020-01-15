#include"Obstacle.h"
#include"Game.h"
#include"Collision.h"
#include"debug_font.h"

int a = 0;

void Obstacle::Init() {
	isBroken = false;
	cube.scale = D3DXVECTOR3(1.5f, 2, 1.5f);
	a = 0;
}
void Obstacle::Update() {
	BoxCollider boxCollider;
	cube.position = position;
	cube.rotation = rotation;
	bool isHit = boxCollider.Collider(cube.collider, GetPlayer()->objCollider);
	if (isHit == true && a>0) {
		isBroken = true;
		GetPlayer()->speed *= 0.5f;
		GetPlayer()->speedAccel *= 0.5f;
		GetPlayer()->slidCount *= 0.5f;
	}

	if (isBroken == true) {
		position += GetPlayer()->GetForward()*2;
		position.y += 0.2f;
	}

	a++;
}
void Obstacle::Draw() {
	cube.Draw(TEXTURE_INDEX_MAX);
}
void Obstacle::UnInit() {

}