#include<stdio.h>
#include"Timer.h"
#include<time.h>
#include"debug_font.h"
double jikan;
static clock_t start, end;
	

void TimerInit() {
	 start = clock();
  
	

	
	

}

//���Ԃ̌v��
void TimerUpdate() {
 end = clock();
 jikan = (end - start) / (double)CLOCKS_PER_SEC ;

}

 

	


//�����Ŏw�肵�����W�Ɏ��Ԃ�\������
void TimerDraw(float x, float y) {
	DebugFont_Draw((int)x,(int)y,"%0.3lf",(float)jikan);
}