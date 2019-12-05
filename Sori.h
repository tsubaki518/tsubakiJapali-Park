#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
class Sori {
private:
	float speedAccel = 0;		//�������ɓ��������Ƃ��ɉ������鑬�x
	bool isBoundRight = false;  //�E�ɒ��˕Ԃ锻��
	bool isBoundLeft = false;   //���ɒ��˕Ԃ锻��
	int boundCount = 0;
	D3DXVECTOR3 spinMoveDirection;     //�X�s�����̈ړ�����
	D3DXVECTOR3 spinMoveDirectionRight;//�X�s�����̒��˕Ԃ����
	D3DXVECTOR3 beforRotation;		   //�X�s���O�̊p�x���擾���ĉ����]���邩���肷�邽�߂Ɏg��
	D3DXVECTOR3 centrifugalDirection; //���S�͂̌���
	D3DXVECTOR3 centrifugalRotation;  //���S�͂̌������擾���邽�߂̊p�x

	void Move();		//�ړ�����
	void Friction();	//���C
	void SlideDown();	//�ΖʂŊ��藎����
	void Bound();		//�ǂɓ�����ƒ��˕Ԃ�
	void Spin();
	void SpeedAccel();		 //�������ɓ����������̏���
	void CentrifugalForce(); //���S��
	void SetCollisionTransform(); //�����蔻��̏�������
	void CharacterTouch(); //�L�����N�^�[���v���C���[�ɂ�����

	//�����ɑ̏d�����ăL�����N�^�[���Z�b�g����
	void SetCharacter(float weight1, float weight2);
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	D3DXVECTOR3 spinRot;
	bool isSpin = false;			//�X�s������ �X�s������true
	bool isHitRightWall = false;	//�E�ǂɓ�����������
	bool isHitLeftWall = false;		//���ǂɓ�����������
	bool isHitSpeedAccelBoard = false;
	bool isGoalGround = false;		//�S�[���ɓ��B����
	float speed;					//���݂̑��x
	float maxSpeed;				   //�ō���
	XFile bobsled;				  //���f���f�[�^(�\��)
	Character *character[2];	  //�L�����N�^�[ �v�f�ԍ�0��1P�@�v�f�ԍ�1��2P
	Collider3D collisoin;		 //�\���̓����蔻�������

	Sori();

	//Init()�̈���
	//weight1��1P�̑̏d������
	//weight2��2P�̑̏d������
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	void LoadModel();
	~Sori();

	//�����蔻��
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);
	void AccelFloorCollision(Collider3D c);

	D3DXVECTOR3 GetForward(); //���ʂ��擾
	D3DXVECTOR3 GetRight();  //�E���擾
	D3DXVECTOR3 GetUp();    //��擾
};