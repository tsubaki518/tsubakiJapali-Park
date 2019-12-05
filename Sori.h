#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
class Sori {
private:
	float speedAccel = 0;		//加速床に当たったときに加速する速度
	bool isBoundRight = false;  //右に跳ね返る判定
	bool isBoundLeft = false;   //左に跳ね返る判定
	int boundCount = 0;
	D3DXVECTOR3 spinMoveDirection;     //スピン中の移動方向
	D3DXVECTOR3 spinMoveDirectionRight;//スピン中の跳ね返る方向
	D3DXVECTOR3 beforRotation;		   //スピン前の角度を取得して何回回転するか判定するために使う
	D3DXVECTOR3 centrifugalDirection; //遠心力の向き
	D3DXVECTOR3 centrifugalRotation;  //遠心力の向きを取得するための角度

	void Move();		//移動処理
	void Friction();	//摩擦
	void SlideDown();	//斜面で滑り落ちる
	void Bound();		//壁に当たると跳ね返る
	void Spin();
	void SpeedAccel();		 //加速床に当たった時の処理
	void CentrifugalForce(); //遠心力
	void SetCollisionTransform(); //当たり判定の情報を入れる
	void CharacterTouch(); //キャラクターがプレイヤーにくっつく

	//引数に体重を入れてキャラクターをセットする
	void SetCharacter(float weight1, float weight2);
public:
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	D3DXVECTOR3 spinRot;
	bool isSpin = false;			//スピン判定 スピン中はtrue
	bool isHitRightWall = false;	//右壁に当たった判定
	bool isHitLeftWall = false;		//左壁に当たった判定
	bool isHitSpeedAccelBoard = false;
	bool isGoalGround = false;		//ゴールに到達判定
	float speed;					//現在の速度
	float maxSpeed;				   //最高速
	XFile bobsled;				  //モデルデータ(ソリ)
	Character *character[2];	  //キャラクター 要素番号0が1P　要素番号1が2P
	Collider3D collisoin;		 //ソリの当たり判定を入れる

	Sori();

	//Init()の引数
	//weight1は1Pの体重を入れる
	//weight2は2Pの体重を入れる
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	void LoadModel();
	~Sori();

	//当たり判定
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);
	void AccelFloorCollision(Collider3D c);

	D3DXVECTOR3 GetForward(); //正面を取得
	D3DXVECTOR3 GetRight();  //右側取得
	D3DXVECTOR3 GetUp();    //上取得
};