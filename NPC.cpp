#include"NPC.h"
#include"texture.h"
#include"input.h"
#include"debug_font.h"
#include<time.h>
#include<stdlib.h>
#include"Sori.h"
#include"Game.h"
#include<math.h>

#define CHARACTER_ROTATION_SPEED 0.1f
#define SPIN_NUM 4
#define SPIN_SPEED 1.0f
#define ACCEL_FLOOR_ACCEL_SPEED 0.3f
#define CENTRIFUGAL_FORCE 0.035f
#define MOVE_PROBABILITY 5
#define MOVE_HORIZON_COUNT 150

NPC::NPC() {
	
}

void NPC::Init(float weight1, float weight2) {

	//�L�����N�^�[���Z�b�g����
	SetCharacter(weight1, weight2);
	character[1]->Init();
	character[0]->Init();
	bobsled.Init("asset/model/Bobsled/bobuv2.x", "asset/model/Bobsled/bobuv2.jpg");


	//------------------�X�s�[�h�Ȃǂ̃p�����[�^�̏�����----------------------------//
	//�ō����̐ݒ�
	maxSpeed = (character[0]->maxSpeed + character[1]->maxSpeed) / 2;

	speedAccel = 0;//�������ɓ��������Ƃ��ɉ������鑬�x������������

	//�v���C���[�̏����ʒu
	position = D3DXVECTOR3(-0.5f, -10.10f, 2);
	rotation = D3DXVECTOR3(10.00f*3.141592f / 180, 0, 0);
	isGoalGround = false;
	isSpin = false;

	//���S�͏�����
	centrifugalDirection = D3DXVECTOR3(0, 0, 0);

	//�L�����N�^�[�̏�������
	CharacterTouch();

	speed = 0;
	spinRot = D3DXVECTOR3(0, 0, 0);

	moveHorizonCount = 0;
	isMoveLeft = false;
	isMoveRight = false;
}
void NPC::Update() {
	//�����蔻��̏�������
	SetCollisionTransform();

	//�L�����N�^�[���\���ɒǏ]������
	CharacterTouch();

	//�ړ�����
	MoveForward();
	MoveHorizon();

	//�X�s������
	Spin();

	//���C
	Friction();

	//�Ζʂɏ���Ă����犊��
	SlideDown();

	//�ǂɓ��������璵�˕Ԃ�
	Bound();

	//������
	SpeedAccel();

	//���S��
	CentrifugalForce();

	//�G�̃X�s���ɓ��������琁�����
	ReceiveSpinMove();

	//�v���C���[�����苗���ȏ㗣��Ȃ��悤�ɂ���
	SearchDistance();

	//�X������p�[�e�B�N��
	shaveIce[0].Update(GetRight()*0.5f + position - GetForward(), rotation, GetForward(), speed * 50);
	shaveIce[1].Update(-GetRight()*0.5f + position - GetForward(), rotation, GetForward(), speed * 50, -1);
}
void NPC::Draw() {
	//�\���p�̍s����쐬
	{
		D3DXMATRIX g_mtxWorld;
		D3DXMATRIX mtxScl;
		D3DXMATRIX mtxRot;
		D3DXMATRIX spinMtxRot;
		D3DXMATRIX mtxTrs;
		LPDIRECT3DDEVICE9	g_pd3dDevice;
		g_pd3dDevice = MyDirect3D_GetDevice();


		// ���[���h�ϊ�
		//���[���h�s���P�ʍs��֏�����
		D3DXMatrixIdentity(&g_mtxWorld);

		//�X�P�[���s����쐬�����[���h�s��֍���
		D3DXMatrixScaling(&mtxScl, scale.x, scale.y, scale.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxScl);

		//�X�s���p�̉�]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&spinMtxRot, spinRot.y, spinRot.x, spinRot.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &spinMtxRot);

		//��]�s����쐬�����[���h�s��֍���
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxRot);

		//���s�s��
		D3DXMatrixTranslation(&mtxTrs, position.x, position.y, position.z);
		D3DXMatrixMultiply(&g_mtxWorld, &g_mtxWorld, &mtxTrs);


		//���[���h�}�g���N�X��ݒ�
		g_pd3dDevice->SetTransform(D3DTS_WORLD, &g_mtxWorld);
	}

	//�\���̕`��
	bobsled.Draw();

	//�L�����N�^�[�̕`��
	character[0]->Draw();
	character[1]->Draw();

	//�X������p�[�e�B�N��
	shaveIce[0].Draw();
	shaveIce[1].Draw();

}
void NPC::UnInit() {
	for (int i = 0; i < 2; i++) {
		character[i]->UnInit();
		delete character[i];
	}
	bobsled.UnInit();


	//�p�[�e�B�N��
	shaveIce[0].UnInit();
	shaveIce[1].UnInit();
}

NPC::~NPC() {

}


bool NPC::CollisionWall(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition*1.2f;
		return true;

	} else {
		return false;
	}
}
bool NPC::Collision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		rotation = c.rotation;
		if (isSpin == false) {
			rotation = c.rotation;
		}
		return true;

	} else {
		return false;
	}
}
bool NPC::CollisionGoal(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit) {
		position += collider.Collider(collisoin, c).addPosition;
		speed = 0;
		return true;

	} else {
		return false;
	}
}
void NPC::AccelFloorCollision(Collider3D c) {
	BoxCollider2 collider;

	if (collider.Collider(collisoin, c).isHit && isSpin == false) {
		isHitSpeedAccelBoard = true;
	}
}
bool NPC::CollisionRight(Sori c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(rightCollider, c.leftCollider)) {
		position += c.leftSpeed*2.0f;
		return true;
	}
	return false;
}
bool NPC::CollisionLeft(Sori c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(leftCollider, c.rightCollider)) {
		position += c.rightSpeed*2.0f;
		return true;
	}
	return false;
}
bool NPC::CollisionBack(Sori c) {
	BoxCollider2 collider;

	if (collider.CharacterCollider(backCollider, c.forwardCollider)) {
		position += c.GetForward() * (c.speed / 2 + c.speedAccel) + (c.centrifugalDirection*c.speed / 2)*2.0f;
		return true;
	}
	return false;
}


void NPC::MoveForward() {
	bool canMoveRight = isHitRightWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;
	bool canMoveLeft = isHitLeftWall == false && isBoundRight == false && isBoundLeft == false && isSpin == false;

	//���ʂɈړ�
	position += GetForward() * (speed / 2 + speedAccel) + (centrifugalDirection*speed / 2);

	//1P�̈ړ�
	{
			//speed��maxSpeed�𒴂��Ȃ��悤�ɂ���
		if (speed < maxSpeed) {
			speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
		}

	}

	//2P�̈ړ�
	{
		//speed��maxSpeed�𒴂��Ȃ��悤�ɂ���
		if (speed < maxSpeed) {
			speed += (character[0]->moveAccel + character[1]->moveAccel) / 4;
		}
	}
}
void NPC::MoveHorizon() {
	position += rightSpeed;
	position += leftSpeed;
	leftSpeed = D3DXVECTOR3(0, 0, 0);
	rightSpeed = D3DXVECTOR3(0, 0, 0);

	int num = 0;
	if (moveHorizonCount == 0) {
		num = rand() % MOVE_PROBABILITY;
	}
	moveHorizonCount++;

	if (num == 1) {
		isMoveLeft = true;

	} else if (num == 2) {
		isMoveRight = true;
	}

	if (isMoveRight == true) {
		//�E�Ɉړ�
		rightSpeed += GetRight() * ((character[0]->handling + character[1]->handling) / 2);  //GetRight()*�ړ���

		//���E�Ɉړ��������̃L�����N�^�[�̂�����C��
		character[0]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);
		character[1]->position += GetRight() * ((character[0]->handling + character[1]->handling) / 2);


		//�ړ������ɃL�����N�^�[���X��
		if (character[0]->inputRotZ <= 0.8f) {
			character[0]->inputRotZ += CHARACTER_ROTATION_SPEED;
		}
		//�ړ������ɃL�����N�^�[���X��
		if (character[1]->inputRotZ <= 0.8f) {
			character[1]->inputRotZ += CHARACTER_ROTATION_SPEED;
		}

		if (moveHorizonCount == MOVE_HORIZON_COUNT) {
			moveHorizonCount = 0;
			isMoveRight = false;
		}
	}
	if (isMoveLeft == true) {
		//���Ɉړ�
		leftSpeed -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

		//���E�Ɉړ��������̃L�����N�^�[�̂�����C��
		character[0]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);
		character[1]->position -= GetRight() * ((character[0]->handling + character[1]->handling) / 2);

		//�ړ������ɃL�����N�^�[���X��
		if (character[0]->inputRotZ >= -0.8f) {
			character[0]->inputRotZ -= CHARACTER_ROTATION_SPEED;
		}
		if (character[1]->inputRotZ >= -0.8f) {
			character[1]->inputRotZ -= CHARACTER_ROTATION_SPEED;
		}

		if (moveHorizonCount == MOVE_HORIZON_COUNT) {
			moveHorizonCount = 0;
			isMoveLeft = false;
		}
	}
	//���삵�Ă��Ȃ�������L�����N�^�[���X���Ă�̂𒼂�
	for (int i = 0; i < 2; i++) {
		if (character[i]->inputRotZ > 0.05f) {
			character[i]->inputRotZ -= CHARACTER_ROTATION_SPEED / 2;

		} else if (character[i]->inputRotZ < -0.05f) {
			character[i]->inputRotZ += CHARACTER_ROTATION_SPEED / 2;
		}
	}
	if (moveHorizonCount == MOVE_HORIZON_COUNT) {
		moveHorizonCount = 0;
	}
}
void NPC::Friction() {
	if (speed >= 0.001f) {
		speed -= 0.0002f;
	}
}
void NPC::SlideDown() {
	if (GetForward().y < 0) {
		position -= GetForward()*GetForward().y*0.03f;
	}
	if (GetRight().y < 0) {
		position += GetRight()*-GetRight().y*0.03f;
	}
	if (-GetRight().y < 0) {
		position -= GetRight()*GetRight().y*0.03f;
	}
}
void NPC::Bound() {
	//�ǂɓ�����������
	if (isHitLeftWall == true) {
		boundCount = 0;
		isBoundRight = true;
		moveHorizonCount = 0;
	}
	if (isHitRightWall == true) {
		boundCount = 0;
		isBoundLeft = true;
		moveHorizonCount = 0;
	}


	//�ǂɓ����������̈ړ��������擾
	if (isSpin == false) {
		spinMoveDirectionRight = GetRight();
	}

	if (isBoundRight == true && boundCount <= 100) {
		if (isSpin == false) {
			rightSpeed += GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*�ړ���
			rightSpeed.y -= GetRight().y * ((character[0]->handling + character[1]->handling));//���˕Ԃ��Ă�ԂɃX�s������ƃX�e�[�W�O�ɍs���o�O�̑΍�
		} else if (isSpin == true) {
			rightSpeed += spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*�ړ���
			rightSpeed.y -= spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//���˕Ԃ��Ă�ԂɃX�s������ƃX�e�[�W�O�ɍs���o�O�̑΍�
		}
		boundCount++;
	} else {
		isBoundRight = false;
	}
	if (isBoundLeft == true && boundCount <= 100) {
		if (isSpin == false) {
			leftSpeed -= GetRight() * ((character[0]->handling + character[1]->handling));  //GetRight()*�ړ���
			leftSpeed.y += GetRight().y * ((character[0]->handling + character[1]->handling));//���˕Ԃ��Ă�ԂɃX�s������ƃX�e�[�W�O�ɍs���o�O�̑΍�
		} else if (isSpin == true) {
			leftSpeed -= spinMoveDirectionRight * ((character[0]->handling + character[1]->handling));  //GetRight()*�ړ���
			leftSpeed.y += spinMoveDirectionRight.y * ((character[0]->handling + character[1]->handling));//���˕Ԃ��Ă�ԂɃX�s������ƃX�e�[�W�O�ɍs���o�O�̑΍�
		}
		boundCount++;
	} else {
		isBoundLeft = false;
	}
}
void NPC::Spin() {
	int num = rand() % 800;
	if (num == 0) {
		isSpin = true;
		beforRotation = spinRot;
	}

	if (isSpin == true) {
		spinRot.y += SPIN_SPEED;
		if (beforRotation.y + SPIN_NUM * 6.28f < spinRot.y) {
			isSpin = false;
			spinRot.y = 0;
		}
	}
}
void NPC::SpeedAccel() {
	if (isHitSpeedAccelBoard == true && isSpin == false) {
		speedAccel = ACCEL_FLOOR_ACCEL_SPEED;
		isHitSpeedAccelBoard = false;
	}
	if (speedAccel > 0) {
		speedAccel -= 0.0008f;
	}
}
void NPC::CentrifugalForce() {
	D3DXMATRIX matrixWorld;    //���[���h�s��
	D3DXMATRIX centrifugalMtxRot;		   //��]�s��

	if (centrifugalRotation.x > rotation.x) {
		centrifugalRotation.x -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.x < rotation.x) {
		centrifugalRotation.x += CENTRIFUGAL_FORCE;
	}

	if (centrifugalRotation.y > rotation.y) {
		centrifugalRotation.y -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.y < rotation.y) {
		centrifugalRotation.y += CENTRIFUGAL_FORCE;
	}

	if (centrifugalRotation.z > rotation.z) {
		centrifugalRotation.z -= CENTRIFUGAL_FORCE;

	} else if (centrifugalRotation.z < rotation.z) {
		centrifugalRotation.z += CENTRIFUGAL_FORCE;
	}


	//�s���������
	D3DXMatrixIdentity(&matrixWorld);
	D3DXMatrixIdentity(&centrifugalMtxRot);

	//��]�s����쐬
	D3DXMatrixRotationYawPitchRoll(&centrifugalMtxRot, centrifugalRotation.y, centrifugalRotation.x, centrifugalRotation.z);
	D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &centrifugalMtxRot);

	//�s�񂩂��]�������x�N�g�������o��
	centrifugalDirection = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);

}
void NPC::SetCollisionTransform() {
	//���ƕǂ̔���p
	collisoin.position = position;
	collisoin.rotation = rotation;
	collisoin.size.x = 1;
	collisoin.size.y = -1.0f;
	collisoin.size.z = 0;

	//�v���C���[�Ƃ̓����蔻��p
	rightCollider.position = position;
	rightCollider.position.x += 0.4f;
	rightCollider.rotation = rotation;
	rightCollider.size.x = 1.8f;
	rightCollider.size.y = 1;
	rightCollider.size.z = 5;

	leftCollider.position = position;
	leftCollider.position.x -= 0.4f;
	leftCollider.rotation = rotation;
	leftCollider.size.x = 1.8f;
	leftCollider.size.y = 1;
	leftCollider.size.z = 5;

	forwardCollider.position = position;
	forwardCollider.position.z += 2.0f;
	forwardCollider.rotation = rotation;
	forwardCollider.size.x = 1.8f;
	forwardCollider.size.y = 1;
	forwardCollider.size.z = 3;

	backCollider.position = position;
	backCollider.position.z -= 2.0f;
	backCollider.rotation = rotation;
	backCollider.size.x = 1.8f;
	backCollider.size.y = 1;
	backCollider.size.z = 3;

}
void NPC::CharacterTouch() {
	for (int i = 0; i < 2; i++) {
		character[i]->position = GetUp()*1.75f + position;
		character[i]->position -= GetForward()*(float)i + GetForward()*0.3f + GetForward()*0.2f;
		character[i]->rotation = rotation + spinRot;
		character[i]->rotation.z += character[i]->inputRotZ - rotation.z * 2;
	}

}
void NPC::ReceiveSpinMove() {
	if (isReceiveMoveForward == true) {
		position += receiveSpinSpeed;

	}else if (isReceiveMoveRight == true) {
		position += receiveSpinSpeed;
		receiveSpinSpeed.y *= GetRight().y;

	} else if (isReceiveMoveLeft == true) {
		position -= receiveSpinSpeed;
		receiveSpinSpeed.y *= -GetRight().y;
	}
	receiveSpinSpeed *= 0.8f;
	
}
void NPC::SearchDistance() {
	D3DXVECTOR3 distance;
	float vectorLen;
	distance = position - GetPlayerPos();
	vectorLen = pow(distance.x*distance.x + distance.y*distance.y + distance.z*distance.z, 0.5f);

	if (position.y>GetPlayerPos().y&&vectorLen > 15) {
		position = -GetPlayer()->GetForward()*15+GetPlayerPos();
	}
}

//if��weight�ɒl�͈̔͂��w�肵�ăZ�b�g����L���������߂�
void NPC::SetCharacter(float weight1, float weight2) {

	//�L�����̑I��
	if (weight1 >= 80)
	{
		character[0] = new Elephant();

	} else if (weight1 >= 70 && weight1 <= 79)
	{
		character[0] = new Bear();
	} else if (weight1 >= 60 && weight1 <= 69)
	{
		character[0] = new Dog();
	} else if (weight1 >= 50 && weight1 <= 59)
	{
		character[0] = new Rabbit();
	} else if (weight1 <= 49)
	{
		character[0] = new Hamster();
	}


	if (weight2 >= 80)
	{
		character[1] = new Elephant;

	} else if (weight2 >= 70 && weight2 <= 79)
	{
		character[1] = new Bear;
	} else if (weight2 >= 60 && weight2 <= 69)
	{
		character[1] = new Dog;
	} else if (weight2 >= 50 && weight2 <= 59)
	{
		character[1] = new Rabbit;
	} else if (weight2 <= 49)
	{
		character[1] = new Hamster;
	}

}

D3DXVECTOR3 NPC::GetForward() {
	D3DXMATRIX matrixWorld;    //���[���h�s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._31, matrixWorld._32, matrixWorld._33);
	}
	return direction;
}
D3DXVECTOR3 NPC::GetRight() {
	D3DXMATRIX matrixWorld;    //���_�̍s��
	D3DXMATRIX mtxRot;
	D3DXVECTOR3 direction;
	direction.x = 1;
	direction.y = 0;
	direction.z = 0;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._11, matrixWorld._12, matrixWorld._13);
	}
	return direction;
}
D3DXVECTOR3 NPC::GetUp() {
	D3DXMATRIX matrixWorld;    //���_�̍s��
	D3DXMATRIX mtxRot;		   //��]�s��
	D3DXVECTOR3 direction;
	direction.x = 0;
	direction.y = 1;
	direction.z = 0;

	{
		//�s���������
		D3DXMatrixIdentity(&matrixWorld);
		D3DXMatrixIdentity(&mtxRot);

		//��]�s����쐬
		D3DXMatrixRotationYawPitchRoll(&mtxRot, rotation.y, rotation.x, rotation.z);
		D3DXMatrixMultiply(&matrixWorld, &matrixWorld, &mtxRot);

		//�s�񂩂��]�������x�N�g�������o��
		direction = D3DXVECTOR3(matrixWorld._21, matrixWorld._22, matrixWorld._23);
	}
	return direction;
}