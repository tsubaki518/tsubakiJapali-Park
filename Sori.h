#pragma once
#include"character.h"
#include"Figure.h"
#include"XFile.h"
#include"Particle.h"

class NPC;

class Sori {
private:
	bool isBoundRight = false;  //右に跳ね返る判定
	bool isBoundLeft = false;   //左に跳ね返る判定
	int boundCount = 0;
	int weight[2];//体重

	//氷が削れるパーティクル
	ShaveIce shaveIce[2];

	//紙吹雪
	Confetti confetti;

	void Move();		//移動処理
	void Friction();	//摩擦
	void SlideDown();	//斜面で滑り落ちる
	void Bound();		//壁に当たると跳ね返る
	void Spin();
	void SpeedAccel();		 //加速床に当たった時の処理
	void CentrifugalForce(); //遠心力
	void SetCollisionTransform(); //当たり判定の情報を入れる
	void CharacterTouch(); //キャラクターがプレイヤーにくっつく
	void ReceiveSpinMove(); //敵のスピンが当たった時に吹っ飛ぶ

	//引数に体重を入れてキャラクターをセットする
	void SetCharacter(float weight1, float weight2);
public:
	bool isMoveSound=false;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 position;
	D3DXVECTOR3 scale = { 50,50,50 };
	D3DXVECTOR3 spinRot;
	int spinCount = 0;
	float slidCount = 0;
	float slidSpeed = 0;
	bool isReceiveMoveForward = false; //吹っ飛ぶ方向を判定
	bool isReceiveMoveLeft = false;		//吹っ飛ぶ方向を判定
	bool isReceiveMoveRight = false;	//吹っ飛ぶ方向を判定
	bool isSpin = false;			//スピン判定 スピン中はtrue
	bool isHitRightWall = false;	//右壁に当たった判定
	bool isHitLeftWall = false;		//左壁に当たった判定
	bool isHitSpeedAccelBoard = false;
	bool isGoalGround = false;		//ゴールに到達判定
	bool isWallSpeedAccel = false;
	bool isNPCcollision = false;
	bool isChangeRank = false;
	float speed;					//現在の速度
	D3DXVECTOR3 rightSpeed = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 leftSpeed = D3DXVECTOR3(0, 0, 0);
	float maxSpeed;				   //最高速
	D3DXVECTOR3 receiveSpinSpeed;    //敵のスピンが当たった時の吹っ飛ぶ移動量(絶対値)
	D3DXVECTOR3 spinMoveDirection;     //スピン中の移動方向
	D3DXVECTOR3 spinMoveDirectionRight;//スピン中の跳ね返る方向
	D3DXVECTOR3 beforRotation;		   //スピン前の角度を取得して何回回転するか判定するために使う
	D3DXVECTOR3 centrifugalDirection; //遠心力の向き
	D3DXVECTOR3 centrifugalRotation;  //遠心力の向きを取得するための角度
	float speedAccel = 0;		//加速床に当たったときに加速する速度
	XFile bobsled;				  //モデルデータ(ソリ)
	Character *character[2];	  //キャラクター 要素番号0が1P　要素番号1が2P
	Collider3D collisoin;		 //ソリの当たり判定を入れる
	Collider3D rightCollider; //右側の当たり判定
	Collider3D leftCollider; //左側の当たり判定
	Collider3D forwardCollider;
	Collider3D backCollider;
	Collider3D objCollider;

	Sori();

	//Init()の引数
	//weight1は1Pの体重を入れる
	//weight2は2Pの体重を入れる
	void Init(float weight1, float weight2);

	void Update();
	void Draw();
	void UnInit();
	~Sori();

	void DrawCharacterIcon();
	void DrawParticle();

	//当たり判定
	bool CollisionWall(Collider3D c);
	bool Collision(Collider3D c);
	bool CollisionGoal(Collider3D c);
	bool AccelFloorCollision(Collider3D c);

	//NPCとの当たり判定
	bool CollisionRight(NPC c);
	bool CollisionLeft(NPC c);
	bool CollisionBack(NPC c);

	D3DXVECTOR3 GetForward(); //正面を取得
	D3DXVECTOR3 GetRight();  //右側取得
	D3DXVECTOR3 GetUp();    //上取得
};