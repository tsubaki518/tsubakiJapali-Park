#include"character.h"



//各キャラクターの初期化
void Character::Init(){
}
void Elephant::Init() {
	
}
void Bear::Init() {
	model.LoadMesh("asset/model/Bear/bear.x", "asset/model/Bear/bearuv.jpg");
}
void Dog::Init() {

}
void Rabbit::Init() {

}
void Hamster::Init() {

}


//各キャラクターの描画処理
void Character::Draw() {

}
void Elephant::Draw() {

}
void Bear::Draw() {
	model.RenderParactice();
}
void Dog::Draw() {

}
void Rabbit::Draw() {

}
void Hamster::Draw() {

}


//各キャラクターの終了処理
void Character::UnInit() {

}
void Elephant::UnInit() {

}
void Bear::UnInit() {
	model.CleanUp();
}
void Dog::UnInit() {

}
void Rabbit::UnInit() {

}
void Hamster::UnInit() {

}


//ifでweightに値の範囲を指定してreturnさせるキャラを決める
Character SetCharacter(float weight) {

	Character character;
	Elephant elephant;			//80kg以上
	Bear bear;					//70～79kg
	Dog dog;					//60～69kg
	Rabbit rabbit;				//50～59kg
	Hamster hamster;			//49kg以下
	


	//キャラの選定
	if (weight >= 80)
	{
		return elephant;
	}
	else if (weight >= 70 && weight <= 79)
	{
		return bear;
	}
	else if (weight >= 60 && weight <= 69)
	{
		return dog;
	}
	else if (weight >= 50 && weight <= 59)
	{
		return rabbit;
	}
	else if (weight <= 49)
	{
		return hamster;
	}

	//条件に当てはまらない場合characterをreturnさせる
	return character;

}


//最高速維持でｼﾁｮｳﾘﾂ（スコア）を加点
float Character::GetMaxSpeed() {
	return maxSpeed;
}

float Elephant::GetMaxSpeed() {
	return maxSpeed;
}

float Bear::GetMaxSpeed() {
	return maxSpeed;
}

float Dog::GetMaxSpeed() {
	return maxSpeed;
}

float Rabbit::GetMaxSpeed() {
	return maxSpeed;
}

float Hamster::GetMaxSpeed() {
	return maxSpeed;
}