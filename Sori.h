#pragma once
#include"character.h"

class Sori {
public:
	float speed;
	Character character[2];

	Sori();
	void Update();
	void Draw();
	~Sori();
};