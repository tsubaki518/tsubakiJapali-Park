#pragma once
#include"character.h"
#include"Figure.h"

class Sori {
private:
	bool isGround = false;
public:
	Cube cube;	//モデルが無いため仮でCube

	float speed;
	Character character[2];

	Sori();
	void Update();
	void Draw();
	bool Collision(Collider3D c);
	~Sori();

	//斜め判定のデバッグ用	
	bool Collision2(Collider3D c);
};