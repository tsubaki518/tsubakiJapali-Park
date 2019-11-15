#pragma once

//�e�p�����[�^�̊�l
#define NORMAL_MAX_SPEED 1.0f
#define NORMAL_MOVE_ACCEL 1.0f
#define NORMAL_HANDLING 1.0f
#define NORMAL_DEFENSE 1.0f
#define NORMAL_SPIN_NUM 1.0f


//�N���X��`
class Character {
protected:
	float maxSpeed = 0.0f;		//�ő呬�x
	float moveAccel = 0.0f;		//�������\
	float handling = 0.0f;		//�n���h�����O���\
	float defense = 0.0f;		//�e���ϐ�
	int	spinNum = 0.0f;			//�X�s������

public:
	Character(){}
	virtual float GetMaxSpeed();	//�ō����ێ�_�X�R�A���_
	virtual void Draw();

	Character operator=(Character c) {
		maxSpeed = c.maxSpeed;
		moveAccel = c.moveAccel;
		handling = c.handling;
		defense = c.defense;
		spinNum = c.spinNum;
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
	}
	void Draw(){}
	float GetMaxSpeed();
};


//�����ɑ̏d�����ăL�����N�^�[��Ԃ��֐�
Character SetCharacter(float weight);