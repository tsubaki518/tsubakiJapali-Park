#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
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
	XFile bobsled;	//モデルデータ

	bool isSpin = false;
	bool isHitRightWall = false;
	bool isHitLeftWall = false;
	float speed;
	float maxSpeed=1;
	Character character[2];
	Collider3D collisoin;

	Sori();
	void Init();
	void Update();
	void Draw();
	void UnInit();
	~Sori();

	//斜め判定
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
};