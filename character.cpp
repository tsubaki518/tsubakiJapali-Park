#include"character.h"

void Character::Draw() {

}


//ifでweightに値の範囲を指定してreturnさせるキャラを決める
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//90kg以上
	Bear bear;					//70〜89kg
	Dog dog;					//60〜69kg
	Rabbit rabbit;				//50〜59kg
	Mouse mouse;				//49kg以下
	

	//--------------------------------
	//    ここでキャラを決定する
	//-------------------------------

	if (weight <= 90)
	{
		return elephant;
	}
	else if (weight >= 89)
	{
		return bear;
	}
	else if (weight >= 69)
	{
		return dog;
	}
	else if (weight >= 59)
	{
		return rabbit;
	}
	else if (weight >= 49)
	{
		return mouse;
	}

	//---------------------------------


	//条件に当てはまらない場合characterをreturnさせる
	return character;
}