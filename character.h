#pragma once

//�e�p�����[�^�̊�l
#define NORMAL_MAX_SPEED 1
#define NORMAL_MOVE_ACCEL 1
#define NORMAL_HANDLING 1
#define NORMAL_DEFENSE 1
#define NORMAL_SPIN_NUM 1


class Character {
protected:
	float maxSpeed = 0;			//�ő呬�x
	float moveAccel = 0;		//�������\
	float handling = 0;			//�n���h�����O���\
	float defense = 0;			//�e���ϐ�
	int	spinNum = 0;			//�X�s������
public:
	Character(){}
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
		maxSpeed = NORMAL_MAX_SPEED * 1.04;
		moveAccel = NORMAL_MOVE_ACCEL * 1.08;
		handling = NORMAL_HANDLING * 0.90;
		defense = NORMAL_DEFENSE * 1.10;
	  //spinNum= NORMAL_SPIN_NUM
	}
	void Draw(){}
};

class Bear :public Character {
public:
	Bear(){
		maxSpeed = NORMAL_MAX_SPEED * 1.02;
		moveAccel = NORMAL_MOVE_ACCEL * 1.04;
		handling = NORMAL_HANDLING * 0.92;
		defense = NORMAL_DEFENSE * 1.06;
	  //spinNum= NORMAL_SPIN_NUM
	}
	void Draw(){}
};

class Dog :public Character {
public:
	Dog(){
		maxSpeed = NORMAL_MAX_SPEED * 1.00;
		moveAccel = NORMAL_MOVE_ACCEL * 1.00;
		handling = NORMAL_HANDLING * 0.94;
		defense = NORMAL_DEFENSE * 1.00;
	  //spinNum= NORMAL_SPIN_NUM
	}
	void Draw(){}
};

class Rabbit :public Character {
public:
	Rabbit(){
		maxSpeed = NORMAL_MAX_SPEED * 0.96;
		moveAccel = NORMAL_MOVE_ACCEL * 0.96;
		handling = NORMAL_HANDLING * 0.96;
		defense = NORMAL_DEFENSE * 0.90;
	  //spinNum= NORMAL_SPIN_NUM
	}
	void Draw(){}
};

class Hamster :public Character {
public:
	Hamster(){
		maxSpeed = NORMAL_MAX_SPEED * 0.94;
		moveAccel = NORMAL_MOVE_ACCEL * 0.88;
		handling = NORMAL_HANDLING * 1.00;
		defense = NORMAL_DEFENSE * 0.74;
	  //spinNum= NORMAL_SPIN_NUM
	}
	void Draw(){}
};


//�����ɑ̏d�����ăL�����N�^�[��Ԃ��֐�
Character SetCharacter(float weight);