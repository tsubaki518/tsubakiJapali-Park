#include"Game.h"
#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"input.h"
#include"Grid.h"
#include"Camera.h"
#include"Figure.h"
#include"Collision.h"
#include<vector>
#include"main.h"

using namespace std;
vector <Cube> cube;
Camera camera;

void GameInit() {
	for (int i = 0; i < 4; i++) {
		cube.push_back(Cube());
	}
	cube[0].position.y = 10;
	cube[0].scale.z = 2;

	cube[1].position.y = 0;
	cube[1].scale.x = 10;
	cube[1].scale.z = 10;

	cube[3].position.z = 15;
	cube[3].scale.x = 10;
	cube[3].scale.z = 10;
	cube[3].rotation.z = 0.5f;
}
void GameUpdate() {
	//“ü—Í
	{
		if (Keyboard_IsPress(DIK_W)) {
			cube[0].position += cube[0].GetForward() / 10;
		} else if (Keyboard_IsPress(DIK_S)) {
			cube[0].position -= cube[0].GetForward() / 10;
		}
		if (Keyboard_IsPress(DIK_D)) {
			cube[0].rotation.y += 0.02f;
		} else if (Keyboard_IsPress(DIK_A)) {
			cube[0].rotation.y -= 0.02f;
		}
		if (Keyboard_IsPress(DIK_UP)) {
			cube[0].position.y += 0.1f;
		} else if (Keyboard_IsPress(DIK_DOWN)) {
			cube[0].position.y -= 0.1f;
		}
		if (Keyboard_IsPress(DIK_RIGHT)) {
			cube[0].position += cube[0].GetRight() / 10;
		} else if (Keyboard_IsPress(DIK_LEFT)) {
			cube[0].position -= cube[0].GetRight() / 10;
		}
		if (Keyboard_IsPress(DIK_SPACE)) {
			cube[0].position.y += 0.2f;
		}
	}
	BoxCollider collider;
	BoxCollider2 collider2;
	if (!collider.Collider(cube[0].collider, cube[1].collider) && !collider2.Collider(cube[0].collider, cube[3].collider)) {
		cube[0].position.y -= 0.1f;
	}


	//ƒJƒƒ‰’Ç]
	camera.eye.x = sinf(cube[0].rotation.y)*-10 + cube[0].position.x;
	camera.eye.y = cube[0].position.y + 3;
	camera.eye.z = cosf(cube[0].rotation.y)*-10 + cube[0].position.z;

	camera.at = cube[0].position;

	camera.up.x = cube[0].position.x;
	camera.up.y = cube[0].position.y + 1;
	camera.up.z = cube[0].position.z;
}

void GameDraw() {
	camera.SetCamera();
	//Cube•`‰æ
	cube[0].Draw(TEXTURE_INDEX_CEMENT);
	cube[1].Draw(TEXTURE_INDEX_ICE);
	cube[3].Draw(TEXTURE_INDEX_ICE);
}

void GameUnInit() {

}