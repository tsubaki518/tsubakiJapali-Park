#pragma once
#include"character.h"
#include"Figure.h"

class Sori {
private:
	void Move();
	void Friction();
	void SlideDown();
public:
	Cube cube;	//モデルが無いため仮でCube

	bool canMoveRight = true;
	bool canMoveLeft = true;
	float speed;
	float maxSpeed=1;
	Character character[2];

	Sori();
	void Update();
	void Draw();
	bool CollisionWall(Collider3D c);
	~Sori();

	//斜め判定
	bool Collision(Collider3D c);
};