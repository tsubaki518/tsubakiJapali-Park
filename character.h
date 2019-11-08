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

class Mouse :public Character {
public:
	Mouse(){}
	void Draw(){}
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

class Rabbit :public Character {
public:
	Rabbit(){}
	void Draw(){}
};

class Dog :public Character {
public:
	Dog(){}
	void Draw(){}
};


//引数に体重を入れてキャラクターを返す関数
Character SetCharacter(float weight);