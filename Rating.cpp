#include"Rating.h"
#include"debug_font.h"

int rating;

//視聴率の初期化
void RatingInit() {
	rating = 0;
}

//視聴率の計測
void RatingUpdate() {
	
	if (rating >= 100) {
		rating = 100;
	}
	else {
		rating += 1;
	}
}

//引数で指定した座標に視聴率を表示する
void RatingDraw() {
	DebugFont_Draw(1, 250, "視聴率%d", rating);
}