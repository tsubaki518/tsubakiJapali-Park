#pragma once
#include <Windows.h>
#include "mydirect3d.h"
#include <d3dx9.h>
#include"XFile.h"

//�e�p�����[�^�̊�l
#define NORMAL_MAX_SPEED 0.5f
#define NORMAL_MOVE_ACCEL 0.001f
#define NORMAL_HANDLING 0.05f
#define NORMAL_DEFENSE 1.0f
#define NORMAL_SPIN_NUM 1.0f


//�N���X��`
class Character {
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale;
	float inputRotZ = 0;;
	float maxSpeed = 0.0f;		//�ő呬�x
	float moveAccel = 0.0f;		//�������\
	float handling = 0.0f;		//�n���h�����O���\
	float defense = 0.0f;		//�e���ϐ�
	int	spinNum = 0;			//�X�s������
	D3DXCOLOR color;			//�L�����N�^�[�J���[
	XFile model;				//���f���f�[�^

	Character(){}
	virtual void Init();
	virtual float GetMaxSpeed();	//�ō����ێ�_�X�R�A���_
	virtual void Draw();
	virtual void UnInit();


};


//�e�L�����N�^�̃p�����[�^
class Elephant :public Character {
public:
	Elephant(){
		maxSpeed = NORMAL_MAX_SPEED * 1.04f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.08f;
		handling = NORMAL_HANDLING * 0.90f;
		defense = NORMAL_DEFENSE * 1.10f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 0.3f,0.6f,1,1 };			//�������F
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Bear :public Character {
public:
	Bear(){
		maxSpeed = NORMAL_MAX_SPEED * 1.02f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.04f;
		handling = NORMAL_HANDLING * 0.92f;
		defense = NORMAL_DEFENSE * 1.06f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,0.7f,0,1 };				//�^�ÐF
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Dog :public Character {
public:
	Dog(){
		maxSpeed = NORMAL_MAX_SPEED * 1.00f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.00f;
		handling = NORMAL_HANDLING * 0.94f;
		defense = NORMAL_DEFENSE * 1.00f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,0.2f,0.3f,1 };			//�����̐ԐF
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Rabbit :public Character {
public:
	Rabbit(){
		maxSpeed = NORMAL_MAX_SPEED * 0.96f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.96f;
		handling = NORMAL_HANDLING * 0.96f;
		defense = NORMAL_DEFENSE * 0.90f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 1,1,1,1 };				//�����̔��F
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};

class Hamster :public Character {
public:
	Hamster(){
		maxSpeed = NORMAL_MAX_SPEED * 0.94f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.88f;
		handling = NORMAL_HANDLING * 1.00f;
		defense = NORMAL_DEFENSE * 0.74f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 0.5f,0.9f,0.9f,1 };		//���̑��ȐF
	}
	void Init();
	void Draw();
	float GetMaxSpeed();
	void UnInit();
};


