#include"Timer.h"
#include<time.h>
#include"debug_font.h"
#include"ImageNumber.h"
#include<d3dx9.h>
double byou;
int hun;

static clock_t start, end;


void TimerInit() 
{
	 start = clock();
}

//���Ԃ̌v��
void TimerUpdate() {
 end = clock();
 byou = (end - start) / (double)CLOCKS_PER_SEC ;
 if (byou >= 60) {
	 start = clock();
	 byou = 0;
	 hun++;
 }
}

//�����Ŏw�肵�����W�Ɏ��Ԃ�\������
void TimerDraw(float x, float y) {
	ImageNumberDraw(D3DXVECTOR2(1000, 10), D3DXVECTOR2(0.3,0.3), (int)byou);
	ImageNumberDraw(D3DXVECTOR2(5, 5), D3DXVECTOR2(0.3,0.3), (int)hun);
}