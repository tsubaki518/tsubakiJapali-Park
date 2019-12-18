#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
#include"Particle.h"

class Sori;

class NPC {
private:
	bool isBoundRight = false;  //�E�ɒ��˕Ԃ锻��
	bool isBoundLeft = false;   //���ɒ��˕Ԃ锻��
	int boundCount = 0;
	bool isMoveRight = false;
	bool isMoveLeft = false;
	int moveHorizonCount = 0;

	//�X������p�[�e�B�N��
	ShaveIce shaveIce[2];


	void MoveForward();		//�ړ�����
	void MoveHorizon();
	void Friction();	//���C
	void SlideDown();	//�ΖʂŊ��藎����
	void Bound();		//�ǂɓ�����ƒ��˕Ԃ�
	void Spin();
	void SpeedAccel();		 //�������ɓ����������̏���
	void CentrifugalForce(); //���S��
	void SetCollisionTransform(); //�����蔻��̏�������
	void CharacterTouch(); //�L�����N�^�[���v���C���[�ɂ�����
	void ReceiveSpinMove(); //�G�̃X�s���������������ɐ������

	//�����ɑ̏d�����ăL�����N�^�[���Z�b�g����
	void SetCharacter(float weight1, float weight2);
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	D3DXVECTOR3 spinRot;
	bool isReceiveMoveForward = false; //������ԕ����𔻒�
	bool isReceiveMoveLeft = false;		//������ԕ����𔻒�
	bool isReceiveMoveRight = false;	//������ԕ����𔻒�
	bool isSpin = false;			//�X�s������ �X�s������true
	bool isHitRightWall = false;	//�E�ǂɓ�����������
	bool isHitLeftWall = false;		//���ǂɓ�����������
	bool isHitSpeedAccelBoard = false;
	bool isGoalGround = false;		//�S�[���ɓ��B����
	float speed;					//���݂̑��x
	D3DXVECTOR3 rightSpeed = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 leftSpeed = D3DXVECTOR3(0, 0, 0);
	float maxSpeed;				   //�ō���
	D3DXVECTOR3 receiveSpinSpeed;    //�G�̃X�s���������������̐�����Ԉړ���(��Βl)
	D3DXVECTOR3 spinMoveDirection;     //�X�s�����̈ړ�����
	D3DXVECTOR3 spinMoveDirectionRight;//�X�s�����̒��˕Ԃ����
	D3DXVECTOR3 beforRotation;		   //�X�s���O�̊p�x���擾���ĉ����]���邩���肷�邽�߂Ɏg��
	D3DXVECTOR3 centrifugalDirection; //���S�͂̌���
	D3DXVECTOR3 centrifugalRotation;  //���S�͂̌������擾���邽�߂̊p�x
	float speedAccel = 0;			//�������ɓ��������Ƃ��ɉ������鑬�x
	XFile bobsled;				  //���f���f�[�^(�\��)
	Character *character[2];	  //�L�����N�^�[ �v�f�ԍ�0��1P�@�v�f�ԍ�1��2P
	Collider3D collisoin;		 //�\���̓����蔻�������
	Collider3D rightCollider; //�E���̓����蔻��
	Collider3D leftCollider; //�E���̓����蔻��
	Collider3D forwardCollider;
	Collider3D backCollider;
	NPC();

	//Init()�̈���
	//weight1��1P�̑̏d������
	//weight2��2P�̑̏d������
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	~NPC();

	//�����蔻��
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);
	void AccelFloorCollision(Collider3D c);

	//�v���C���[�Ƃ̓����蔻��
	bool CollisionRight(Sori c);
	bool CollisionLeft(Sori c);
	bool CollisionBack(Sori c);

	D3DXVECTOR3 GetForward(); //���ʂ��擾
	D3DXVECTOR3 GetRight();  //�E���擾
	D3DXVECTOR3 GetUp();    //��擾
};