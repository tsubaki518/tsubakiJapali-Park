#pragma once
#include <Windows.h>
#include "mydirect3d.h"
#include <d3dx9.h>


//�e�p�����[�^�̊�l
#define NORMAL_MAX_SPEED 0.5f
#define NORMAL_MOVE_ACCEL 0.001f
#define NORMAL_HANDLING 0.05f
#define NORMAL_DEFENSE 1.0f
#define NORMAL_SPIN_NUM 1.0f


//�N���X��`
class Character {
public:
	float maxSpeed = 0.0f;		//�ő呬�x
	float moveAccel = 0.0f;		//�������\
	float handling = 0.0f;		//�n���h�����O���\
	float defense = 0.0f;		//�e���ϐ�
	int	spinNum = 0;			//�X�s������
	D3DXCOLOR color;			//�L�����N�^�[�J���[

	Character(){}
	virtual float GetMaxSpeed();	//�ō����ێ�_�X�R�A���_
	virtual void Draw();

	Character operator=(Character c) {
		maxSpeed = c.maxSpeed;
		moveAccel = c.moveAccel;
		handling = c.handling;
		defense = c.defense;
		spinNum = c.spinNum;
		color = c.color;
		return *this;
	}
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
		color = { 71,163,255,255 };		//�������F
	}
	void Draw(){}
	float GetMaxSpeed();
};

class Bear :public Character {
public:
	Bear(){
		maxSpeed = NORMAL_MAX_SPEED * 1.02f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.04f;
		handling = NORMAL_HANDLING * 0.92f;
		defense = NORMAL_DEFENSE * 1.06f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 255,182,0,255 };		//�^�ÐF
	}
	void Draw(){}
	float GetMaxSpeed();
};

class Dog :public Character {
public:
	Dog(){
		maxSpeed = NORMAL_MAX_SPEED * 1.00f;
		moveAccel = NORMAL_MOVE_ACCEL * 1.00f;
		handling = NORMAL_HANDLING * 0.94f;
		defense = NORMAL_DEFENSE * 1.00f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 255,255,255,255 };	//�����F
	}
	void Draw(){}
	float GetMaxSpeed();
};

class Rabbit :public Character {
public:
	Rabbit(){
		maxSpeed = NORMAL_MAX_SPEED * 0.96f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.96f;
		handling = NORMAL_HANDLING * 0.96f;
		defense = NORMAL_DEFENSE * 0.90f;
	  //spinNum= NORMAL_SPIN_NUM;
		color = { 247,140,124,255 };	//�����̐ԐF
	}
	void Draw(){}
	float GetMaxSpeed();
};

class Hamster :public Character {
public:
	Hamster(){
		maxSpeed = NORMAL_MAX_SPEED * 0.94f;
		moveAccel = NORMAL_MOVE_ACCEL * 0.88f;
		handling = NORMAL_HANDLING * 1.00f;
		defense = NORMAL_DEFENSE * 0.74f;
	  //spinNum= NORMAL_SPIN_NUM;
	  //�����ݒ�
		color = { 0,0,0,255 };			//
	}
	void Draw(){}
	float GetMaxSpeed();
};


//�����ɑ̏d�����ăL�����N�^�[��Ԃ��֐�
Character SetCharacter(float weight);