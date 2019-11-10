#include"Game.h"
#include <Windows.h>
#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include <d3dx9.h>
#include"input.h"
#include"Camera.h"
#include<vector>
#include"main.h"
#include"Sori.h"
#include"Figure.h"

#define CUBE_NUM 5

using namespace std;
vector <Cube> cube;
Camera camera;
Sori sori;

void GameInit() {
	for (int i = 0; i < CUBE_NUM; i++) {
		cube.push_back(Cube());
	}
	cube[0].position.y = 10;
	cube[0].scale.x = 10;
	cube[0].scale.z = 10;

	cube[1].position.x = -9;
	cube[1].position.y = 12;
	cube[1].scale.x = 10;
	cube[1].scale.z = 10;
	cube[1].rotation.z = -0.5f;

	cube[2].position.z = 9;
	cube[2].position.y = -2.3f+10;
	cube[2].scale.x = 10;
	cube[2].scale.z = 10;
	cube[2].rotation.x = 0.5f;

	cube[3].position.y = 10;
	cube[3].position.z = 25;
	cube[3].scale.x = 10;
	cube[3].scale.z = 10;
	cube[3].rotation.x = 0.5f;
	cube[3].rotation.z = 0.5f;
	cube[3].rotation.y = 0.8f;

	cube[4].position.x = 9;
	cube[4].position.y = 12;
	cube[4].scale.x = 10;
	cube[4].scale.z = 10;
	cube[4].rotation.z = 0.5f;

	sori.cube.position.y = 11;

}
void GameUpdate() {

	sori.Update();
	bool isGround = false;
	//ƒ\ƒŠ‚Ì“–‚½‚è”»’è
	for (int i = 0; i < (int)cube.size(); i++) {
		if (sori.Collision2(cube[i].collider)) {
			isGround = true;
			break;
		} else {
			isGround = false;
		}
	}
	if (isGround == false) {
		sori.cube.position.y -= 0.1f;
	}

	//ƒJƒƒ‰’Ç]
	{
		camera.eye.x = sinf(sori.cube.rotation.y)*-10 + sori.cube.position.x;
		camera.eye.y = -sinf(sori.cube.rotation.x)*-5 + sori.cube.position.y+5;
		camera.eye.z = cosf(sori.cube.rotation.y)*-10 + sori.cube.position.z;

		camera.at = sori.cube.position;

		camera.up.x = sori.cube.position.x;
		camera.up.y = sori.cube.position.y + 1;
		camera.up.z = sori.cube.position.z;
	}
}

void GameDraw() {
	camera.SetCamera();

	//Cube•`‰æ
	for (int i = 0; i < (int)cube.size(); i++) {
		cube[i].Draw(TEXTURE_INDEX_ICE);
	}
	

	//‚»‚è‚Ì•`‰æ
	sori.Draw();

}

void GameUnInit() {

}