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

#define CUBE_NUM 2

using namespace std;
vector <Cube> cube;
Camera camera;
Sori sori;

void GameInit() {
	for (int i = 0; i < CUBE_NUM; i++) {
		cube.push_back(Cube());
	}
	cube[0].position.y = 0;
	cube[0].scale.x = 10;
	cube[0].scale.z = 10;

	cube[1].position.z = 15;
	cube[1].scale.x = 10;
	cube[1].scale.z = 10;
	cube[1].rotation.z = 0.5f;
	//cube[1].rotation.x = 0.5f;
}
void GameUpdate() {

	sori.Update();
	//ƒ\ƒŠ‚Ì“–‚½‚è”»’è
	if (!sori.Collision2(cube[1].collider) && !sori.Collision(cube[0].collider)) {
		sori.cube.position.y -= 0.1f;
	}

	//ƒJƒƒ‰’Ç]
	{
		camera.eye.x = sinf(sori.cube.rotation.y)*-10 + sori.cube.position.x;
		camera.eye.y = sori.cube.position.y + 3;
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
	cube[0].Draw(TEXTURE_INDEX_ICE);
	cube[1].Draw(TEXTURE_INDEX_ICE);

	//‚»‚è‚Ì•`‰æ
	sori.Draw();

}

void GameUnInit() {

}