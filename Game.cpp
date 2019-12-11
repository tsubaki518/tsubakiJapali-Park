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
#include"NPC.h"

StartAnimation startAnimation;
GoalAnimation goalAnimation;
Camera camera;
Sori sori;
NPC npc;
static bool isAnimatioin=false;
static bool isChangeScene = false;

//UI�̕`��
void UIDraw();

//������
//�v���C���[�̏����ʒu��Sori�N���X��Init()�֐��ōs��
void GameInit() {
	//�t���O�̏�����
	isChangeScene = false;
	isAnimatioin = false;

	//�̏d�����ƂɃL�����N�^�[��ݒ肷��
	sori.Init(72, 55);//���̊֐����Ńv���C���[�̏����ʒu�����߂�
	npc.Init(55, 72);

	//�X�e�[�W������
	StageInit();

	//������������
	RatingInit();

	//�A�j���[�V�����̏�����
	startAnimation.Init();
	goalAnimation.Init();

	//�^�C��������
	TimerInit();

	camera.Init(sori);

}

void GameUpdate() {
	//�X�^�[�g�A�j���[�V��������Update�������~�߂�
	if (isAnimatioin == false) {
		sori.Update();
		npc.Update();
		RatingUpdate(sori);
		TimerUpdate();
		GameCollision();
	}

	//�V�[���̐؂�ւ�
	if (isChangeScene == true) {
		SetScene(RESULT);
	}
}

void GameDraw() {

	//����̕`��
	sori.Draw();
	npc.Draw();

	//�J�����Ǐ]
	camera.SetCamera(sori);

	//�X�e�[�W�̕`��
	StageDraw();

	//UI��`�悷��
	//UI�̕`��͂��̊֐����ł��
	UIDraw();


}

//�I������
void GameUnInit() {
	sori.UnInit();
	npc.UnInit();
}

//�����蔻��
void GameCollision() {
	const float HIT_CHECK_RANGE = 15;
	D3DXVECTOR3 distance;
	bool isGround = false;
	//�\����Cube(��)�̓����蔻��
	for (int i = 0; i < GetCubeNum(); i++) {
		distance = GetCube(i).position - sori.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x> -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y> -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z> -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.Collision(GetCube(i).collider)) {
				isGround = true;
				break;
			} else {
				isGround = false;
			}
		}
	}
	if (isGround == false && sori.isGoalGround==false) {
		sori.position.y -= 0.1f;
	}

	//�\���ƉE�̕ǂ̓����蔻��
	for (int i = 0; i < GetRightWallNum(); i++) {
		distance = GetRightWall(i).position - sori.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.CollisionWall(GetRightWall(i).collider)) {
				sori.isHitRightWall = true;
				break;
			} else {
				sori.isHitRightWall = false;
			}
		}
	}

	//�\���ƍ��̕ǂ̓����蔻��
	for (int i = 0; i < GetLeftWallNum(); i++) {
		distance = GetLeftWall(i).position - sori.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (sori.CollisionWall(GetLeftWall(i).collider)) {
				sori.isHitLeftWall = true;
				break;
			} else {
				sori.isHitLeftWall = false;
			}
		}
	}

	//�S�[������
	if (sori.CollisionWall(GetGoalCube().collider)) {
		sori.speed = 0;
		sori.isGoalGround = true;
	}

	//�������̓����蔻��
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		distance = GetAccelSpeedCube(i).position - sori.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			sori.AccelFloorCollision(GetAccelSpeedCube(i).collider);
		}
	}


	//////////////////////////////////////////////////////////////////////////////////////////

	bool isGroundNPC = false;
	//�\����Cube(��)�̓����蔻��
	for (int i = 0; i < GetCubeNum(); i++) {
		distance = GetCube(i).position - npc.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.Collision(GetCube(i).collider)) {
				isGroundNPC = true;
				break;
			} else {
				isGroundNPC = false;
			}
		}
	}
	if (isGroundNPC == false && npc.isGoalGround == false) {
		npc.position.y -= 0.1f;
	}

	//�\���ƉE�̕ǂ̓����蔻��
	for (int i = 0; i < GetRightWallNum(); i++) {
		distance = GetRightWall(i).position - npc.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetRightWall(i).collider)) {
				npc.isHitRightWall = true;
				break;
			} else {
				npc.isHitRightWall = false;
			}
		}
	}

	//�\���ƍ��̕ǂ̓����蔻��
	for (int i = 0; i < GetLeftWallNum(); i++) {
		distance = GetLeftWall(i).position - sori.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			if (npc.CollisionWall(GetLeftWall(i).collider)) {
				npc.isHitLeftWall = true;
				break;
			} else {
				npc.isHitLeftWall = false;
			}
		}
	}

	//�S�[������
	if (npc.CollisionWall(GetGoalCube().collider)) {
		npc.speed = 0;
		npc.isGoalGround = true;
	}

	//�������̓����蔻��
	for (int i = 0; i < GetAccelSpeedNum(); i++) {
		distance = GetAccelSpeedCube(i).position - npc.position;//�\���ƃI�u�W�F�N�g�Ƃ̋������v�Z
		const bool isCollisoinRangeX = distance.x > -HIT_CHECK_RANGE && distance.x < HIT_CHECK_RANGE;
		const bool isCollisoinRangeY = distance.y > -HIT_CHECK_RANGE && distance.y < HIT_CHECK_RANGE;
		const bool isCollisoinRangeZ = distance.z > -HIT_CHECK_RANGE && distance.z < HIT_CHECK_RANGE;

		//���͈͓���Cube�����݂���ꍇ�����蔻������s����
		if (isCollisoinRangeX&&isCollisoinRangeY&&isCollisoinRangeZ) {
			npc.AccelFloorCollision(GetAccelSpeedCube(i).collider);
		}
	}

	//NPC�ƃv���C���[�Ƃ̓����蔻��
	npc.CollisionBack(sori);
	npc.CollisionRight(sori);
	npc.CollisionLeft(sori);
	sori.CollisionBack(npc);
	sori.CollisionRight(npc);
	sori.CollisionLeft(npc);
	
	
}

//UI�̕`��
void UIDraw() {

	//Speed�\��
	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	Sprite_Draw(TEXTURE_INDEX_METER, 1170,680, 0, 0, 32, 56);
	

	Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	if (sori.isGoalGround == true) {
		isChangeScene = goalAnimation.Draw();
	}
	isAnimatioin = startAnimation.Draw();

	Sprite_Draw(TEXTURE_INDEX_UI, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//�o�ߎ��ԕ\��
	TimerDraw(1, 1);

	//�������\��
	RatingDraw();

	
}