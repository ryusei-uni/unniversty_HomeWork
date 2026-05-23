#include "dxlib.h"
#include <stdbool.h>
#include <stdio.h>
#define defelt_pseed 2
#define Jumpforce 3
#define Gravity 1//1
#define Dlife 3
int charSize = 256 / 4;
const double offset_w = charSize / 2;
const double offset_h = charSize / 2;
double JumpPower, px, py, PSpeed = 2;
int  cw,ch,w,h,life; 
int PushStartTime = 0;
int EscapeProgress = 0;





	/*bool judgeGameAreaScreen(double px, double py, int game_areaW, int game_areaH) {
	const double offset = 32.0;

	return px >= -offset &&
		py >= -offset &&
		px <= (game_areaW - offset) &&
		py <= (game_areaH - offset);
	}*/


bool judgeObjectArea(double px, double py, int ObjectX, int ObjectY, int ObjectW, int ObjectH) {
	const double offset = 32.0;
	return  ObjectX <= px + offset && px + offset <= ObjectW &&
		ObjectY <= py + offset && py + offset <= ObjectH;
}

//ライフが0以下の場合ゲームオーバー、ゲームオーバーでTUREを返す
bool judgeGameOver(int life) {
	


	if (life <= 0 ) return TRUE;
	return FALSE;
}

void Wall(int x,int y, int w, int h,bool damege) {
	int Color = GetColor(255, 255, 255);
	if (damege) Color = GetColor(255,0,0);
	DrawBox(x, y, w, h,Color,TRUE);
}

void Object(double px, double py, int ObjectX, int ObjectY, int ObjectW, int ObjectH) {
	Wall(ObjectX, ObjectY, ObjectW, ObjectH, judgeObjectArea(px, py, ObjectX, ObjectY, ObjectW, ObjectH));
	
}
//コントロール再起
 /*void ReGameAreaEnd(int px, int game_areaW) {
	const double offset = 32.0;

	if (px < -offset) px += 1;
	if (px > game_areaW -offset) px -= 1;
	}*/

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


//キャラクターを画面外に行けなくする（プレイヤー操作のみ）
// X座標を画面内に戻して返す関数
double GameAreaResetX(double px, int game_areaW) {

	if (px < -offset_w) return -offset_w;
	if (px > game_areaW - charSize + offset_w) return game_areaW - charSize + offset_w;
	return px;
}

// Y座標を画面内に戻して返す関数
double GameAreaResetY(double py, int game_areaH) {
	
	if (py < -offset_h) return -offset_h;

	//if (py > game_areaH - charSize + offset_h) return game_areaH - charSize + offset_h;
	return py;
}
//void Control(){
//	if (CheckHitKey(KEY_INPUT_LSHIFT)) PSpeed /= PSpeed ; else PSpeed = defelt_pseed;
//	if (CheckHitKey(KEY_INPUT_LEFT)&&judgeGameAreaScreen(px,py,w,h)) px -= PSpeed;
//	if (CheckHitKey(KEY_INPUT_RIGHT) && judgeGameAreaScreen(px, py, w, h)) px += PSpeed;
//	if (CheckHitKey(KEY_INPUT_SPACE)&& judgeGameAreaScreen(px, py, w, h)) py = py -Jumpforce;
//	if (CheckHitKey(KEY_INPUT_UP) && judgeGameAreaScreen(px, py, w, h)) py -= PSpeed;
//	if (CheckHitKey(KEY_INPUT_DOWN) && judgeGameAreaScreen(px, py, w, h)) py += PSpeed;
//
//
//	
//}
//自機コントロール
void Control() {
	int charSize = 256 / 4;
	const double offset_h = 32.0; // 自機の縦幅 (256/4)

	if (CheckHitKey(KEY_INPUT_LSHIFT)) PSpeed /= PSpeed; else PSpeed = defelt_pseed;
	if (CheckHitKey(KEY_INPUT_LEFT))  px -= PSpeed;
	if (CheckHitKey(KEY_INPUT_RIGHT)) px += PSpeed;
	if (CheckHitKey(KEY_INPUT_SPACE)) py -= Jumpforce;

	//if (CheckHitKey(KEY_INPUT_UP))    py -= PSpeed;
	//if (CheckHitKey(KEY_INPUT_DOWN))  py += PSpeed;
	px = GameAreaResetX(px, w);
	py = GameAreaResetY(py, h);

	/*if (CheckHitKey(KEY_INPUT_DOWN)&& (py > h - charSize + offset_h)) {
		py = h - charSize + offset_h;
	}*/

}

//キャラクターを画面外に行けなくする（プレイヤー操作のみ）
//void GameAreaResets(double* px, double* py, int game_areaW, int game_areaH) {
//	const double offset = 32.0; // 画像の左上を基準にする場合は0.0、中央基準なら調整
//	int charSize = 256 / 4;    // 描画しているサイズ (64)
//
//	// X座標の制限
//	if (*px  < -offset) {
//		*px  = -offset;
//	}
//	if (*px > game_areaW - charSize + offset) {
//		*px = game_areaW - charSize + offset;
//	}
//
//	// Y座標の制限（上下も同様に制御する場合）
//	if (*py < -offset) {
//		*py = -offset;
//	}
//	if (*py > game_areaH - charSize + offset) {
//		*py = game_areaH - charSize + offset;
//	}
//}


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

	int PGraph = LoadGraph(".\\image\\256_jiki_31.bmp");
	
	SetDrawScreen(DX_SCREEN_BACK);

	//メインループ
	while (ProcessMessage() == 0) {
		DrawBox(-10, -10, 500, 500,GetColor(255,255,255),TRUE);
		Control();
		py += Gravity;
		/*ReGameAreaEnd(px, w);*/
		ClearDrawScreen();
		
		DrawExtendGraph(px,py,	px+256/4, py + 256 / 4, PGraph, TRUE);
		
		Object(px,py,50,50,100,100);

		if (Esc(2500) == 1) break;



		ScreenFlip();

		
	}

	

	// ＤＸライブラリ使用の終了
	DxLib_End();

	// ソフトの終了
	return 0;
}