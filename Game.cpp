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
#include"debug_font.h"
#include"Light.h"

#define CUBE_NUM 5

using namespace std;
vector <Cube> cube;
Camera camera;
Sori sori;




void GameInit() {

	sori.cube.position.y = 11;

	for (int i = 0; i < CUBE_NUM; i++) {
		cube.push_back(Cube());
	}

	cube[0].position.x = 0;
	cube[0].position.z = 0;
	cube[0].scale.x = 10;
	cube[0].scale.z = 10;

	cube[1].position.x = -9;
	cube[1].position.y = 2;
	cube[1].scale.x = 10;
	cube[1].scale.z = 10;
	cube[1].rotation.z = -0.5f;

	cube[2].position.z = 9;
	cube[2].position.y = -2.3f;
	cube[2].scale.x = 10;
	cube[2].scale.z = 10;
	cube[2].rotation.x = 0.5f;

	cube[3].position.x = 9;
	cube[3].position.y = 2;
	cube[3].scale.x = 10;
	cube[3].scale.z = 10;
	cube[3].rotation.z = 0.5f;

	cube[4].position.z = 17;
	cube[4].position.y = -6.7f;
	cube[4].scale.x = 10;
	cube[4].scale.z = 10;
	cube[4].rotation.x = 0.5f;
	cube[4].rotation.y = 0.1f;
	cube[4].rotation.z = 0.05f;
}
void GameUpdate() {

	sori.Update();
	

	//カメラ追従
	{
		camera.eye.x = sinf(sori.cube.rotation.y)*-10 + sori.cube.position.x;
		camera.eye.y = -sinf(sori.cube.rotation.x)*-5 + sori.cube.position.y+5;
		camera.eye.z = cosf(sori.cube.rotation.y)*-10 + sori.cube.position.z;

		camera.at = sori.cube.position;

		camera.up = sori.cube.GetUp();
	}
}

void GameDraw() {
	camera.SetCamera();

	//Cube描画
	for (int i = 0; i < (int)cube.size(); i++) {
		cube[i].Draw(TEXTURE_INDEX_ICE);
	}


	bool isGround = false;
	//ソリとCubeの当たり判定
	for (int i = 0; i < (int)cube.size(); i++) {
		if (sori.Collision2(cube[i].collider)) {
			//sori.cube.position.y += 0.05f;
			isGround = true;
			break;
		} else {
			isGround = false;
		}
	}
	if (isGround == false) {
		sori.cube.position.y -= 0.1f;
	}

	//そりの描画
	sori.Draw();

}

void GameUnInit() {

}