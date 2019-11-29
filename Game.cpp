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
#include"Rating.h"
#include"Timer.h"
#include"XFile.h"
#include"Animation.h"
#include"main.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
static bool isAnimatioin=false;
static bool isChangeScene = false;

//UI�̕`��
void UIDraw();


void GameInit() {
	isChangeScene = false;
	isAnimatioin = false;

	//�̏d�����ƂɃL�����N�^�[��ݒ肷��
	sori.Init(72, 55);

	//�X�e�[�W������
	StageInit();

	//������������
	RatingInit();

	//�A�j���[�V�����̏�����
	startAnimation.Init();
	goalAnimation.Init();

	//�^�C��������
	TimerInit();

	//�v���C���[�̏����ʒu
	sori.position = D3DXVECTOR3(0, -2.5f, 0);
	sori.rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0, 0);

}

void GameUpdate() {
	if (isAnimatioin == false) {
		RatingUpdate(sori);
		sori.Update();
		TimerUpdate();
		GameCollision();
	}

	if (isChangeScene == true) {
		SetScene(RESULT);
	}
}

void GameDraw() {

	//����̕`��
	sori.Draw();

	RatingDraw();
	//�J�����Ǐ]
	camera.SetCamera(sori);
	TimerDraw(1,1);
	//�X�e�[�W�̕`��
	StageDraw();


	//UI��`�悷��
	//UI�̕`��͂��̊֐����ł��
	UIDraw();


}

void GameUnInit() {

	sori.UnInit();
}


void GameCollision() {

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
	if (isGround == false && sori.isGoalGround==false) {
		sori.position.y -= 0.1f;
	}

	//�\���ƉE�̕ǂ̓����蔻��
	for (int i = 0; i < GetRightWallNum(); i++) {
		if (sori.CollisionWall(GetRightWall(i).collider)) {
			sori.isHitRightWall = true;
			break;
		} else {
			sori.isHitRightWall = false;
		}
	}

	//�\���ƍ��̕ǂ̓����蔻��
	for (int i = 0; i < GetLeftWallNum(); i++) {
		if (sori.CollisionWall(GetLeftWall(i).collider)) {
			sori.isHitLeftWall = true;
			break;
		} else {
			sori.isHitLeftWall = false;
		}
	}

	//�\���ƍ��̕ǂ̓����蔻��
	if (sori.CollisionWall(GetGoalCube().collider)) {
		sori.speed = 0;
		sori.isGoalGround = true;
	}

	//�������̓����蔻��
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		sori.AccelFloorCollision(GetAccelSpeedCube(i).collider);
	}


	
}

void UIDraw() {
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
	}
	isAnimatioin = startAnimation.Draw();
}