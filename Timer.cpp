#include"Timer.h"
#include<time.h>
#include"debug_font.h"
#include"ImageNumber.h"
#include<d3dx9.h>
#include"common.h"
#include<math.h>
double byou;
float hun;
float seisuu;
float syousuu;

static clock_t start, end;


void TimerInit() 
{
	 start = clock();
	 hun = 0;
	 byou = 0;
	 syousuu = 0;
	 seisuu = 0;
}

//���Ԃ̌v��
void TimerUpdate() {
	end = clock();
	byou = (end - start) / (double)CLOCKS_PER_SEC;
	if (byou >= 60) {
		start = clock();
		byou = 0;
		hun++;
	}
	syousuu = byou - (int)byou;
	seisuu = (int)byou;
	
	syousuu *= 100;
 
}

//�����Ŏw�肵�����W�Ɏ��Ԃ�\������
void TimerDraw(float x, float y) {
	//�����̕\��
	if (syousuu < 10) {
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 12 * 11 + 200, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), 0);
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 12 * 10.98 + 400, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), (int)syousuu);

	}
	else if (syousuu >= 10) {
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 12 * 11 + 400, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), (int)syousuu);
	}
	//�b�̕\��
	if (byou < 10) {
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 11.79* 10.6, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), 0);
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 11.79 * 10.8, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), (int)seisuu);
	}
	else if (byou >= 10)
	{
		ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 11.79 * 10.8, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), (int)seisuu);
	}

	//���̕\��
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 5 / 12 * 10.5, SCREEN_HEIGHT * 5 / 20), D3DXVECTOR2(0.2, 0.2), (int)hun);

}

float GetTime() {
	return hun * 60 + byou + syousuu / 100;
}

float Getsyousuu() {
	return syousuu;
}