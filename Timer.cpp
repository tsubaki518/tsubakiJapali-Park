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

//時間の計測
void TimerUpdate() {
 end = clock();
 byou = (end - start) / (double)CLOCKS_PER_SEC ;
 if (byou >= 60) {
	 start = clock();
	 byou = 0;
	 hun++;
 }
}

//引数で指定した座標に時間を表示する
void TimerDraw(float x, float y) {
	DebugFont_Draw((int)x,(int)y,"%d分%0.3lf秒", hun,(float)byou);
}