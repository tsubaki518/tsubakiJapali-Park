#include"character.h"

void Character::Draw() {

}


//ifでweightに値の範囲を指定してreturnさせるキャラを決める
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//80kg以上
	Bear bear;					//70〜79kg
	Dog dog;					//60〜69kg
	Rabbit rabbit;				//50〜59kg
	Hamster hamster;			//49kg以下
	

	//--------------------------------
	//    ここでキャラを決定する
	//-------------------------------

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

	//---------------------------------


	//条件に当てはまらない場合characterをreturnさせる
	return character;
}