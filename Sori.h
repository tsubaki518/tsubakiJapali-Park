#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
class Sori {
private:
	bool isBoundRight = false;
	bool isBoundLeft = false;
	int boundCount = 0;
	D3DXVECTOR3 spinMoveDirection;
	D3DXVECTOR3 beforRotation;

	void Move();
	void Friction();
	void SlideDown();
	void Bound();
	void Spin();

	//�����ɑ̏d�����ăL�����N�^�[���Z�b�g����
	void SetCharacter(float weight1, float weight2);
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	bool isSpin = false;
	bool isHitRightWall = false;
	bool isHitLeftWall = false;
	float speed;
	float maxSpeed=1;
	XFile *bobsled;		//���f���f�[�^(�\��)
	Character *character[2];
	Collider3D collisoin;

	Sori();

	//Init()�̈���
	//weight1��1P�̑̏d������
	//weight2��2P�̑̏d������
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	~Sori();

	//�΂ߔ���
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);


	D3DXVECTOR3 GetForward(); //���ʂ��擾
	D3DXVECTOR3 GetRight();  //�E���擾
	D3DXVECTOR3 GetUp();    //��擾
};