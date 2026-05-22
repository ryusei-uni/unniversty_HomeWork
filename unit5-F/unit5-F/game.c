#include "dxlib.h"
#include <stdbool.h>
#include <stdio.h>

#define PSpeed 2
#define Gravity 1
#define Jumpforce 3
double JumpPower;
int  cw, ch, w, h, px, py;
int PushStartTime = 0;
int EscapeProgress = 0;

//エリア感知
bool judgeGameAreaScreen(double px, double py, int game_areaW, int game_areaH) {
	const double offset = 32.0;

	return px >= -offset &&
		py >= -offset &&
		px <= (game_areaW - offset) &&
		py <= (game_areaH - offset);
}
// 自機コントロール
void Control() {
	if (CheckHitKey(KEY_INPUT_LEFT) && judgeGameAreaScreen(px, py, w, h)) px -= PSpeed;
	if (CheckHitKey(KEY_INPUT_RIGHT) && judgeGameAreaScreen(px, py, w, h)) px += PSpeed;
	if (CheckHitKey(KEY_INPUT_SPACE) && judgeGameAreaScreen(px, py, w, h)) py = py - Jumpforce;
	//if (CheckHitKey(KEY_INPUT_UP) && judgeGameAreaScreen(px, py, w, h)) py -= PSpeed;
	//if (CheckHitKey(KEY_INPUT_DOWN) && judgeGameAreaScreen(px, py, w, h)) py += PSpeed;



}

//指定の時間ESCを押しているとゲームを閉じる
int Esc(int EscProgressX_size) {
	int EscProgressY_size = 10, EscProgressBar = 50;
	if (CheckHitKey(KEY_INPUT_ESCAPE) && EscapeProgress <= EscProgressX_size)
	{

		if (PushStartTime == 0)
		{
			// キーが押された瞬間の現在時刻（ミリ秒）を記録
			PushStartTime = GetNowCount();
		}
		//バッファ
		if (EscapeProgress > EscProgressX_size)
		{
			EscapeProgress = EscProgressX_size;
		}

		EscapeProgress = GetNowCount() - PushStartTime;
		//進捗ゲージ
		DrawBox(
			(cw - EscProgressBar),
			(ch - EscProgressY_size),
			(cw - EscProgressBar) + (EscapeProgress * EscProgressBar * 2) / EscProgressX_size,
			(ch + EscProgressY_size),
			GetColor(128, 128, 128),
			true
		);
		//進捗ゲージ枠
		DrawBox((cw - EscProgressBar),
			(ch - EscProgressY_size),
			(cw + EscProgressBar),
			(ch + EscProgressY_size),
			GetColor(255, 0, 0),
			false
		);

	}
	//進捗リセット
	else
	{
		EscapeProgress = 0;
		PushStartTime = 0;
	}
	//終了時1を返す
	if (EscapeProgress >= EscProgressX_size)return 1;
	return 0;
}