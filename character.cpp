#include"character.h"

void Character::Draw() {

}


//if��weight�ɒl�͈̔͂��w�肵��return������L���������߂�
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//80kg�ȏ�
	Bear bear;					//70�`79kg
	Dog dog;					//60�`69kg
	Rabbit rabbit;				//50�`59kg
	Hamster hamster;			//49kg�ȉ�
	

	//--------------------------------
	//    �����ŃL���������肷��
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


	//�����ɓ��Ă͂܂�Ȃ��ꍇcharacter��return������
	return character;
}