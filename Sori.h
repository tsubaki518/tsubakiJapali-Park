#pragma once
#include"character.h"
#include"Figure.h"

class Sori {
private:
	bool isGround = false;
public:
	Cube cube;	//���f�����������߉���Cube

	float speed;
	Character character[2];

	Sori();
	void Update();
	void Draw();
	bool Collision(Collider3D c);
	~Sori();

	//�΂ߔ���̃f�o�b�O�p	
	bool Collision2(Collider3D c);
};