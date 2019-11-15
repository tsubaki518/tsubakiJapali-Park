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
#include"Stage.h"

Camera camera;
Sori sori;




void GameInit() {

	sori.cube.position.y = 11;
	StageInit();

}
void GameUpdate() {

	sori.Update();
	
}

void GameDraw() {
	//ƒJƒƒ‰’Ç]
	camera.SetCamera(sori);


	StageDraw();

	bool isGround = false;
	//ƒ\ƒŠ‚ÆCube‚Ì“–‚½‚è”»’è
	for (int i = 0; i < GetCubeNum(); i++) {
		if (sori.Collision2(GetCube(i).collider)) {
			isGround = true;
			break;
		} else {
			isGround = false;
		}
	}
	if (isGround == false) {
		sori.cube.position.y -= 0.1f;
	}

	//‚»‚è‚Ì•`‰æ
	sori.Draw();

}

void GameUnInit() {

}