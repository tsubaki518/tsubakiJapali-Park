#pragma once

class Character {
protected:
	float moveAccel=0;
	float rotateSpeed=0;
public:
	Character(){}
	virtual void Draw();

	Character operator=(Character c) {
		moveAccel = c.moveAccel;
		rotateSpeed = c.rotateSpeed;

		return *this;
	}
};


class Elephant :public Character {
public:
	Elephant(){}
	void Draw(){}
};

class Bear :public Character {
public:
	Bear(){}
	void Draw(){}
};

class Dog :public Character {
public:
	Dog(){}
	void Draw(){}
};

class Rabbit :public Character {
public:
	Rabbit(){}
	void Draw(){}
};

class Hamster :public Character {
public:
	Hamster(){}
	void Draw(){}
};


//引数に体重を入れてキャラクターを返す関数
Character SetCharacter(float weight);