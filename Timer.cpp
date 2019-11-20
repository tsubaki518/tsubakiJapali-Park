#include"Timer.h"
#include<time.h>
#include"debug_font.h"
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
	DebugFont_Draw((int)x,(int)y,"%d��%0.3lf�b", hun,(float)byou);
}