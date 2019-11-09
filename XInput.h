#pragma once
#define JYOSTHICK_LIMIT 32767

//���update�ŌĂ�
void XinputUpdate();


//�{�^���������Ă����true��Ԃ�
bool XinputPressButton(int buttonType);

//�{�^�����������u��true��Ԃ�
bool XinputPressButtonDown(int buttonType);



//-1�`1�̒l��Ԃ�  ���S��0
float XinputLeftJoystickX();
float XinputLeftJoystickY();

float XinputRightJoystickX();
float XinputRightJoystickY();


enum ControllerButtonType {
	//                  �{�^���̎��    
	A_BUTTON,			//A�{�^��        
	B_BUTTON,			//B�{�^��         
	X_BUTTON,			//X�{�^��         
	Y_BUTTON,			//Y�{�^��         
	UP_BUTTON,			//�\���{�^����    
	DOWN_BUTTON,		//�\���{�^����    
	LEFT_BUTTON,		//�\���{�^���E    
	RIGHT_BUTTON,		//�\���{�^����    
	START_BUTTON,		//start�{�^��   
	BACK_BUTTON,        //back�{�^��
	RIGHTSTICK_BUTTON,  //�E�X�e�B�b�N�̉�������
	LEFTSTICK_BUTTON,   //���X�e�B�b�N�̉�������
	RB_BUTTON,          //RB�{�^��
	LB_BUTTON,          //LB�{�^��
	ButtonMax
};
