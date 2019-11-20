#include<stdio.h>
#include"Timer.h"
#include<time.h>
#include"debug_font.h"
double jikan;
static clock_t start, end;
	

void TimerInit() {
	 start = clock();
  
	

	
	

}

//時間の計測
void TimerUpdate() {
 end = clock();
 jikan = (end - start) / (double)CLOCKS_PER_SEC ;

}

 

	


//引数で指定した座標に時間を表示する
void TimerDraw(float x, float y) {
	DebugFont_Draw((int)x,(int)y,"%0.3lf",(float)jikan);
}