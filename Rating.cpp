#include"Rating.h"
#include"debug_font.h"
#include <time.h>

float rating;

//秒間処理
static clock_t start,timer, end;

static bool sorispin = false;//スピン判定
static bool hitcrimp = false;//障害物当たる
static int cnt;//2秒間カウント

//視聴率の初期化
void RatingInit() {
	rating = 5.0f;
	start = NULL;
	sorispin = false;
	cnt = 0;
}

//視聴率の計測
void RatingUpdate(Sori sori) {
	//秒間スタート
	if (start == NULL) {
		start = clock();
		timer = 1 * CLOCKS_PER_SEC + clock();
	}
	
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
	if (end - start >= timer) {
		start += timer;
		cnt += 1;

		//自機が高スピードを維持し続ける。80%以上の時
		if (sori.speed >= sori.maxSpeed*0.8) {
			rating += 0.5f;
			cnt = 0;
		}
		
		//加点が無い状態が2秒以上継続。
		if (cnt >= 2) {
			rating -= 0.1f;
		}

		/*
		//自分の順位が3位以上の間。
		if () {

		}
		*/
		//自機がスピンをしている。
		if (sorispin == true) {
			rating += 0.6f;
			sorispin = false;
			cnt = 0;
		}
		
	}
	
	//その場判定(トリガー)
	//自機が障害物にぶつかる。
	if (hitcrimp == true) {
		rating += 0.05f;
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
	//最大最小
	if (rating >= 200) {
		rating = 200;
	}
	if (rating < 5) {
		rating = 5.0f;
	}
}

//引数で指定した座標に視聴率を表示する
void RatingDraw() {
	DebugFont_Draw(1, 250, "視聴率%0.2lf%%", rating);
}