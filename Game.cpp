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

	bool isGround = false;
	//�\����Cube(��)�̓����蔻��
	for (int i = 0; i < GetCubeNum(); i++) {
		if (sori.Collision(GetCube(i).collider)) {
			isGround = true;
			break;
		} else {
			isGround = false;
		}
	}
	if (isGround == false) {
		sori.cube.position.y -= 0.1f;
	}

	//�\���ƉE�̕ǂ̓����蔻��
	for (int i = 0; i < GetRightWallNum(); i++) {
		if (sori.CollisionWall(GetRightWall(i).collider)) {
			sori.canMoveRight = false;
			break;
		} else {
			sori.canMoveRight = true;
		}
	}

	//�\���ƍ��̕ǂ̓����蔻��
	for (int i = 0; i < GetLeftWallNum(); i++) {
		if (sori.CollisionWall(GetLeftWall(i).collider)) {
			sori.canMoveLeft = false;
			break;
		} else {
			sori.canMoveLeft = true;
		}
	}
	
}

void GameDraw() {
	//�J�����Ǐ]
	camera.SetCamera(sori);

	//�X�e�[�W�̕`��
	StageDraw();

	//����̕`��
	sori.Draw();



}

void GameUnInit() {

}