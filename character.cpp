#include"character.h"

void Character::Draw() {

}


//if��weight�ɒl�͈̔͂��w�肵��return������L���������߂�
Character SetCharacter(float weight) {
	Character character;
	Elephant elephant;			//90kg�ȏ�
	Bear bear;					//70�`89kg
	Dog dog;					//60�`69kg
	Rabbit rabbit;				//50�`59kg
	Mouse mouse;				//49kg�ȉ�
	

	//--------------------------------
	//    �����ŃL���������肷��
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


	//�����ɓ��Ă͂܂�Ȃ��ꍇcharacter��return������
	return character;
}