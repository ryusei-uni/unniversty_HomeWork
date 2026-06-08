#include "DXlib.h"
#include <string.h>

void drawRandomStar(int,int);
void framesCount(void);
int  hitcacl(double, double, double, double, double,int);
int Esc(int);
int currentMouse = 0; 
int prevMouse = 0;        
int  cw, ch, w, h, life;
int PushStartTime = 0;
int EscapeProgress = 0;



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	w = 1920;
	h = 1080;
	cw = w / 2;
	ch = h / 2;
	ChangeWindowMode(TRUE);
	SetGraphMode(w,h,32);

	int MouseX, MouseY;
	
	



	//ChangeWindowMode(TRUE);
	//SetGraphMode(640, 480, 32);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		return -1;			// エラーが起きたら直ちに終了

	// マウスを表示状態にする
	ChangeWindowMode(TRUE);
	
	SetMouseDispFlag(TRUE);


	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0) {
		
		ClearDrawScreen();
		GetMousePoint(&MouseX, &MouseY);
		
		framesCount();
		drawRandomStar(MouseX,MouseY);
		if (Esc(2500) == 1) break;

		ScreenFlip();
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}



void drawRandomStar(int MouseX,int MouseY) {
	static int frame = 0;
	static int x = cw;
	static int y = ch;
	static int R = 255;
	static int G = 255;
	static int B = 255;
	static int range = 1050;
	static int objectcount = 0;
	frame++;
	if (frame >= 120 || hitcacl(x, y, range, MouseX, MouseY,objectcount) == 0) {          // 更新間隔は自分で変えてよい
		x = GetRand(w-1);
		y = GetRand(h-1);
		R = 255- GetRand(200);
		G = 255 - GetRand(200);
		B = 255 - GetRand(200);
		range = 200 - GetRand(150);
		frame = 0;
		objectcount++;
	}
	DrawCircle(x, y, range, GetColor(R, G, B), TRUE);   // 図形は自分で変える
	hitcacl(x,y,range,MouseX,MouseY,objectcount);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "オブジェクトカウント: %d", objectcount);
}


void framesCount(void) {
	int  no_static = 0;      // 毎フレーム 0 に初期化される → 常に 1
	no_static++;

	static int with_static = 0;  // 前のフレームの値が保持される → 1, 2, 3...
	with_static++;

	DrawFormatString(10, 10, GetColor(255, 255, 255), "staticなし: %d", no_static);
	DrawFormatString(10, 40, GetColor(255, 255, 0), "staticあり: %d", with_static);
}

int hitcacl(double cx, double cy, double r, double hx, double hy,int object_count) {
	int StringCr, BoxCr;

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);

	prevMouse = currentMouse;
	currentMouse = GetMouseInput();

	static int frame = 0;
	static int scoreframe = 0;
	static int hit = 0;
	char score[50];
	int ColorHitJudge;
	// 距離の2乗と半径の2乗を計算
	double dx = hx - cx;
	double dy = hy - cy;
	double distance_sq = dx * dx + dy * dy;
	double radius_sq = r * r;

	if (distance_sq <= radius_sq ) {
		if ((currentMouse & MOUSE_INPUT_LEFT) && !(prevMouse & MOUSE_INPUT_LEFT)) {
			hit +=1;
			scoreframe = frame;
			frame = 0;
			return 0;
		}
		frame++;
	}
	if (hit >= object_count) {
		strcpy_s(score, sizeof(score) , "good");
		ColorHitJudge = GetColor(0, 255, 0);
	}
	else {
		strcpy_s(score, sizeof(score), "bad");
		ColorHitJudge = GetColor(255, 0, 0);
	}
	DrawFormatString(0, 190,ColorHitJudge ,score);

	DrawFormatString(0, 100, StringCr, "クリックせずにマウスの乗っているフレーム：%d",frame);
	DrawFormatString(0, 130, StringCr, "マウスの乗っているフレーム一つ前の：%d", scoreframe);
	DrawFormatString(10, 70, GetColor(255, 0, 0), "ヒット数：%d", hit);
	return 1;
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