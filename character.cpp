#include"character.h"



//�e�L�����N�^�[�̏�����
void Character::Init(){
}
void Elephant::Init() {
	
}
void Bear::Init() {
	model = new XFile();
	model->LoadMesh("asset/model/Bear/bear.x", "asset/model/Bear/bearuv.jpg");
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
	model->RenderParactice();
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
	model->CleanUp();
	delete model;
}
void Dog::UnInit() {

}
void Rabbit::UnInit() {

}
void Hamster::UnInit() {

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