#pragma once
#include"character.h"
#include"Figure.h"

class Sori {
private:
	bool isBoundRight = false;
	bool isBoundLeft = false;
	int boundCount = 0;

	void Move();
	void Friction();
	void SlideDown();
	void Bound();
public:
	Cube cube;	//���f�����������߉���Cube

	bool isSpin = false;
	bool isHitRightWall = false;
	bool isHitLeftWall = false;
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