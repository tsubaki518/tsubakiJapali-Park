#include"Rating.h"
#include"debug_font.h"
#include"ImageNumber.h"
#include <time.h>

float rating;

//秒間処理
static clock_t start, end;
static int timer;

static bool sorispin = false;//スピン判定
static bool hitcrimp = false;//障害物当たる
static int cnt;//2秒間カウント

//視聴率の初期化
void RatingInit() {
	rating = 50.0f;
	start = clock();
	sorispin = false;
	cnt = 0;
	end = clock();
}

//視聴率の計測
void RatingUpdate(Sori sori) {
	//スピン判定挿入
	if (sori.isSpin == true) {
		sorispin = true;
	}
	//障害物当たる挿入
	if ((sori.isHitLeftWall == true) || (sori.isHitRightWall == true)) {
		hitcrimp = true;
	}

	
	
	//1秒間判定(ホールド)
	end = clock();
	if ((end - start) / (int)CLOCKS_PER_SEC >= 1) {
		start = clock();//スタートの時間を初期化
		cnt += 1;

		//自機が高スピードを維持し続ける。80%以上の時
		if (sori.speed >= sori.maxSpeed*0.8) {
			rating += 5.0f;
			cnt = 0;
		}
		
		//加点が無い状態が2秒以上継続。
		if (cnt >= 2.0f) {
			rating -= 1.0f;
			cnt = 0;
		}

		/*
		//自分の順位が3位以上の間。
		if () {

		}
		*/
		//自機がスピンをしている。
		if (sorispin == true) {
			rating += 6.0f;
			sorispin = false;
			cnt = 0;
		}
		
	}
	
	//その場判定(トリガー)
	//自機が障害物にぶつかる。
	if (hitcrimp == true) {
		rating += 0.5f;
		hitcrimp = false;
		cnt = 0;
	}

	/*
	//自機が他機体にぶつかる。
	if () {
	rating += 0.1f;
	cnt = 0;
	}


	//他のプレイヤーが脱落する。
	if () {
	rating += 5.0f;
	cnt = 0;
	}

	//自分の順位が繰り上がる。
	if () {
	rating += 3.0f;
	cnt = 0;
	}
	*/

	//最大
	if (rating >= 9999.0f) {
		rating = 9999.0f;
	}
	//最小
	if (rating < 50.0f) {
		rating = 50.0f;
	}
}

//引数で指定した座標に視聴率を表示する
void RatingDraw() {
	Sprite_SetColor(D3DCOLOR_RGBA(0, 255, 0, 255));
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 20 / 3 / 100 * 94, SCREEN_HEIGHT * 20 / 3 / 11), D3DXVECTOR2(0.15f, 0.15f), (int)rating / 10);
	ImageNumberDraw(D3DXVECTOR2(SCREEN_WIDTH * 10 / 100 * 96, SCREEN_HEIGHT * 10 / 10), D3DXVECTOR2(0.1f, 0.1f), (int)rating % 10);
}

float GetRating() {
	return rating;
}