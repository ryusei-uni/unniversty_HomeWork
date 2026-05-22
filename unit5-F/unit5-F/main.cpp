#include "dxlib.h"
#include <stdbool.h>
#include <stdio.h>

#define PSpeed 2
#define Gravity 0//0.01
#define Jumpforce 6
double JumpPower;
int  cw,ch,w,h,px,py; 
int PushStartTime = 0;
int EscapeProgress = 0;

boolean judgeGameAreaScreen(double px, double py,int game_areaW,int game_areaH,int model_sizeW,int model_sizeH) {
	if (0-model_sizeW/4 < px &&0 -model_sizeH/4 < py && px < game_areaW && py < game_areaH) return TRUE;
	else FALSE;
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
//自機コントロール
void Control(){

	if (CheckHitKey(KEY_INPUT_LEFT)&&judgeGameAreaScreen(px,py,640,480,256,256)) px -= PSpeed;
	if (CheckHitKey(KEY_INPUT_RIGHT) && judgeGameAreaScreen(px, py, 640, 480, 256, 256)) px += PSpeed;
	if (CheckHitKey(KEY_INPUT_UP) && judgeGameAreaScreen(px, py, 640, 480, 256, 256)) py -= PSpeed;
	//if (CheckHitKey(KEY_INPUT_SPACE)&&judgeGameAreaScreen(px,py,640,480,256,256)) py -= PSpeed;
	if (CheckHitKey(KEY_INPUT_DOWN) && judgeGameAreaScreen(px, py, 640, 480, 256, 256)) py += PSpeed;


	
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 16);
	SetWaitVSyncFlag(TRUE);
	if (DxLib_Init() == -1)	return -1;// ＤＸライブラリ初期化処理		// エラーが起きたら直ちに終了
	w = 640;
	h = 480;
	cw = w / 2;
	ch = h / 2;

	int PGraph = LoadGraph(".\\image\\player.bmp");
	
	SetDrawScreen(DX_SCREEN_BACK);

	//メインループ
	while (ProcessMessage() == 0) {
		DrawBox(-10, -10, 500, 500,GetColor(255,255,255),TRUE);
		py -= JumpPower;
		JumpPower -= Gravity;

		Control();
		ClearDrawScreen();
		
		DrawExtendGraph(px,py,	px+256/4, py + 256 / 4, PGraph, TRUE);
	

		if (Esc(2500) == 1) break;

		ScreenFlip();

		
	}

	// ＤＸライブラリ使用の終了
	DxLib_End();

	// ソフトの終了
	return 0;
}