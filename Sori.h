#pragma once
#include"character.h"
#include"Figure.h"

class Sori {
private:
	void Move();
	void Friction();
	void SlideDown();
public:
	Cube cube;	//���f�����������߉���Cube

	bool isSpin = false;
	bool isHitRightWall = true;
	bool isHitLeftWall = true;
	float speed;
	float maxSpeed=1;
	Character character[2];

	Sori();
	void Update();
	void Draw();
	bool CollisionWall(Collider3D c);
	~Sori();

	//�΂ߔ���
	bool Collision(Collider3D c);
};