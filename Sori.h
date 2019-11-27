#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
class Sori {
private:
	bool isBoundRight = false;
	bool isBoundLeft = false;
	int boundCount = 0;
	D3DXVECTOR3 spinMoveDirection;
	D3DXVECTOR3 beforRotation;

	void Move();
	void Friction();
	void SlideDown();
	void Bound();
	void Spin();

	//引数に体重を入れてキャラクターをセットする
	void SetCharacter(float weight1, float weight2);
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	bool isSpin = false;
	bool isHitRightWall = false;
	bool isHitLeftWall = false;
	float speed;
	float maxSpeed=1;
	XFile *bobsled;		//モデルデータ(ソリ)
	Character *character[2];
	Collider3D collisoin;

	Sori();

	//Init()の引数
	//weight1は1Pの体重を入れる
	//weight2は2Pの体重を入れる
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	~Sori();

	//斜め判定
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);


	D3DXVECTOR3 GetForward(); //正面を取得
	D3DXVECTOR3 GetRight();  //右側取得
	D3DXVECTOR3 GetUp();    //上取得
};