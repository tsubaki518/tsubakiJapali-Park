#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<dxerr.h>
#include<stdlib.h>
#include<Xinput.h>
#include<dinput.h>
#include"XInput.h"
#pragma comment(lib, "Xinput.lib")
#pragma comment (lib, "dinput8.lib") 
#pragma comment (lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxerr.lib")

XINPUT_STATE state;

bool isPressDown[ButtonMax];


void XinputUpdate() {

	//コントローラーの状態を取得

	ZeroMemory(&state, sizeof(XINPUT_STATE));

	DWORD dwResult = XInputGetState(0, &state);

	if (dwResult == ERROR_SUCCESS)
	{
		//接続されている
	} else
	{
		//接続されていない
	}

}


//ボタン
bool XinputPressButton(int buttonTyoe) {

	switch (buttonTyoe) {
		case A_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_A) {
				return true;

			} else {
				return false;
			}
		break;

		case B_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_B) {
				return true;

			} else {
				return false;
			}
			break;

		case X_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_X) {
				return true;

			} else {
				return false;
			}
			break;

		case Y_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_Y) {
				return true;

			} else {
				return false;
			}
			break;

		case UP_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_UP) {
				return true;

			} else {
				return false;
			}
			break;

		case DOWN_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_DOWN) {
				return true;

			} else {
				return false;
			}
			break;

		case LEFT_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_LEFT) {
				return true;

			} else {
				return false;
			}
			break;

		case RIGHT_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_RIGHT) {
				return true;

			} else {
				return false;
			}
			break;

		case START_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_START) {
				return true;

			} else {
				return false;
			}
			break;

		case BACK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_BACK) {
				return true;

			} else {
				return false;
			}
			break;

		case RIGHTSTICK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_RIGHT_THUMB) {
				return true;

			} else {
				return false;
			}
			break;

		case LEFTSTICK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_LEFT_THUMB) {
				return true;

			} else {
				return false;
			}
			break;

		case RB_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_RIGHT_SHOULDER) {
				return true;

			} else {
				return false;
			}
			break;

		case LB_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_LEFT_SHOULDER) {
				return true;

			} else {
				return false;
			}
			break;

		default:
			return false;
			break;
	}
}
bool XinputPressButtonDown(int buttonType) {
	switch (buttonType) {
		case A_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_A) {
				if (isPressDown[A_BUTTON] == true) {
					isPressDown[A_BUTTON] = false;
					return true;
				} else {
					isPressDown[A_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[A_BUTTON] = true;
				return false;
			}
			break;

		case B_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_B) {
				if (isPressDown[B_BUTTON] == true) {
					isPressDown[B_BUTTON] = false;
					return true;
				} else {
					isPressDown[B_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[B_BUTTON] = true;
				return false;
			}
			break;

		case X_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_X) {
				if (isPressDown[X_BUTTON] == true) {
					isPressDown[X_BUTTON] = false;
					return true;
				} else {
					isPressDown[X_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[X_BUTTON] = true;
				return false;
			}
			break;

		case Y_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_Y) {
				if (isPressDown[Y_BUTTON] == true) {
					isPressDown[Y_BUTTON] = false;
					return true;
				} else {
					isPressDown[Y_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[Y_BUTTON] = true;
				return false;
			}
			break;

		case UP_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_UP) {
				if (isPressDown[UP_BUTTON] == true) {
					isPressDown[UP_BUTTON] = false;
					return true;
				} else {
					isPressDown[UP_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[UP_BUTTON] = true;
				return false;
			}
			break;

		case DOWN_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_DOWN) {
				if (isPressDown[DOWN_BUTTON] == true) {
					isPressDown[DOWN_BUTTON] = false;
					return true;
				} else {
					isPressDown[DOWN_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[DOWN_BUTTON] = true;
				return false;
			}
			break;

		case LEFT_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_LEFT) {
				if (isPressDown[LEFT_BUTTON] == true) {
					isPressDown[LEFT_BUTTON] = false;
					return true;
				} else {
					isPressDown[LEFT_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[LEFT_BUTTON] = true;
				return false;
			}
			break;

		case RIGHT_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_DPAD_RIGHT) {
				if (isPressDown[RIGHT_BUTTON] == true) {
					isPressDown[RIGHT_BUTTON] = false;
					return true;
				} else {
					isPressDown[RIGHT_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[RIGHT_BUTTON] = true;
				return false;
			}
			break;

		case START_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_START) {
				if (isPressDown[START_BUTTON] == true) {
					isPressDown[START_BUTTON] = false;
					return true;
				} else {
					isPressDown[START_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[START_BUTTON] = true;
				return false;
			}
			break;

		case BACK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_BACK) {
				if (isPressDown[BACK_BUTTON] == true) {
					isPressDown[BACK_BUTTON] = false;
					return true;
				} else {
					isPressDown[BACK_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[BACK_BUTTON] = true;
				return false;
			}
			break;

		case RIGHTSTICK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_RIGHT_THUMB) {
				if (isPressDown[RIGHTSTICK_BUTTON] == true) {
					isPressDown[RIGHTSTICK_BUTTON] = false;
					return true;
				} else {
					isPressDown[RIGHTSTICK_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[RIGHTSTICK_BUTTON] = true;
				return false;
			}
			break;

		case LEFTSTICK_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_LEFT_THUMB) {
				if (isPressDown[LEFTSTICK_BUTTON] == true) {
					isPressDown[LEFTSTICK_BUTTON] = false;
					return true;
				} else {
					isPressDown[LEFTSTICK_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[LEFTSTICK_BUTTON] = true;
				return false;
			}
			break;

			case RB_BUTTON:
			if (state.Gamepad.wButtons&XINPUT_GAMEPAD_RIGHT_SHOULDER) {
				if (isPressDown[RB_BUTTON] == true) {
					isPressDown[RB_BUTTON] = false;
					return true;
				} else {
					isPressDown[RB_BUTTON] = false;
					return false;
				}

			} else {
				isPressDown[RB_BUTTON] = true;
				return false;
			}
			break;

			case LB_BUTTON:
				if (state.Gamepad.wButtons&XINPUT_GAMEPAD_LEFT_SHOULDER) {
					if (isPressDown[LB_BUTTON] == true) {
						isPressDown[LB_BUTTON] = false;
						return true;
					} else {
						isPressDown[LB_BUTTON] = false;
						return false;
					}

				} else {
					isPressDown[LB_BUTTON] = true;
					return false;
				}
				break;
		default:
			return false;
			break;
	}

}


//ジョイスティック
float XinputLeftJoystickX() {
	float thumbLX= state.Gamepad.sThumbLX;

	if (thumbLX <= -JYOSTHICK_LIMIT) {
		thumbLX = -JYOSTHICK_LIMIT;

	} else if (thumbLX >= JYOSTHICK_LIMIT) {
		thumbLX = JYOSTHICK_LIMIT;
	}

	return thumbLX / JYOSTHICK_LIMIT;
}
float XinputLeftJoystickY() {
	float thumbLY = state.Gamepad.sThumbLY;

	if (thumbLY <= -JYOSTHICK_LIMIT) {
		thumbLY = -JYOSTHICK_LIMIT;

	} else if (thumbLY >= JYOSTHICK_LIMIT) {
		thumbLY = JYOSTHICK_LIMIT;
	}

	return thumbLY / JYOSTHICK_LIMIT;
}

float XinputRightJoystickX() {
	float thumbRX = state.Gamepad.sThumbRX;

	if (thumbRX <= -JYOSTHICK_LIMIT) {
		thumbRX = -JYOSTHICK_LIMIT;

	} else if (thumbRX >= JYOSTHICK_LIMIT) {
		thumbRX = JYOSTHICK_LIMIT;
	}

	return thumbRX / JYOSTHICK_LIMIT;
}
float XinputRightJoystickY() {
	float thumbRY = state.Gamepad.sThumbRY;

	if (thumbRY <= -JYOSTHICK_LIMIT) {
		thumbRY = -JYOSTHICK_LIMIT;

	} else if (thumbRY >= JYOSTHICK_LIMIT) {
		thumbRY = JYOSTHICK_LIMIT;
	}

	return thumbRY / JYOSTHICK_LIMIT;
}
