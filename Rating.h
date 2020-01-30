#pragma once
#include"Sori.h"

//視聴率の初期化
void RatingInit();

//視聴率の計測
void RatingUpdate(Sori sori);

//引数で指定した座標に視聴率を表示する
void RatingDraw();

//引数は％で表示する数字
void OVER_MESSAGE(int num);

float GetRating();