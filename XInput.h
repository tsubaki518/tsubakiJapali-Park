#pragma once
#define JYOSTHICK_LIMIT 32767

//常にupdateで呼ぶ
void XinputUpdate();


//ボタンを押している間trueを返す
bool XinputPressButton(int buttonType);

//ボタンを押した瞬間trueを返す
bool XinputPressButtonDown(int buttonType);



//-1～1の値を返す  中心が0
float XinputLeftJoystickX();
float XinputLeftJoystickY();

float XinputRightJoystickX();
float XinputRightJoystickY();


enum ControllerButtonType {
	//                  ボタンの種類    
	A_BUTTON,			//Aボタン        
	B_BUTTON,			//Bボタン         
	X_BUTTON,			//Xボタン         
	Y_BUTTON,			//Yボタン         
	UP_BUTTON,			//十字ボタン上    
	DOWN_BUTTON,		//十字ボタン下    
	LEFT_BUTTON,		//十字ボタン右    
	RIGHT_BUTTON,		//十字ボタン左    
	START_BUTTON,		//startボタン   
	BACK_BUTTON,        //backボタン
	RIGHTSTICK_BUTTON,  //右スティックの押し込み
	LEFTSTICK_BUTTON,   //左スティックの押し込み
	RB_BUTTON,          //RBボタン
	LB_BUTTON,          //LBボタン
	ButtonMax
};
