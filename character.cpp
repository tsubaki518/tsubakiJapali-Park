#include"character.h"



//�e�L�����N�^�[�̏�����
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


//�e�L�����N�^�[�̕`�揈��
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


//�e�L�����N�^�[�̏I������
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


//if��weight�ɒl�͈̔͂��w�肵��return������L���������߂�
Character SetCharacter(float weight) {

	Character character;
	Elephant elephant;			//80kg�ȏ�
	Bear bear;					//70�`79kg
	Dog dog;					//60�`69kg
	Rabbit rabbit;				//50�`59kg
	Hamster hamster;			//49kg�ȉ�
	


	//�L�����̑I��
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

	//�����ɓ��Ă͂܂�Ȃ��ꍇcharacter��return������
	return character;

}


//�ō����ێ��ż����i�X�R�A�j�����_
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