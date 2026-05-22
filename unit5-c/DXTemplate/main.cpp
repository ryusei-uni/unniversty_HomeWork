#include "DxLib.h"
#include <cmath>
#define DS 6

// 弾の描画関数
int d1(int x, int y, int r) {
    DrawCircle(x, y, r, GetColor(0, 255, 0), 1);
    DrawCircle(x, y, r + 3, GetColor(0, 255, 0), 0);
    DrawCircle(x, y, r - 1, GetColor(255, 255, 255), 1);
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    // アルファチャンネル付きのスクリーンを作成
    int tempScreen = MakeScreen(640, 480, TRUE);
    int maskScreen = MakeScreen(640, 480, TRUE);

    int MouseX, MouseY;
    int StringCr = GetColor(255, 255, 255);
    SetMouseDispFlag(TRUE);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 1. 画面全体の消去
        ClearDrawScreen();

        // 2. マスクの作成（表示したい領域を白(255,255,255)で塗る）
        SetDrawScreen(maskScreen);
        ClearDrawScreen();
        // プレイ領域（10,10から400,470）だけを表示対象にする
        DrawBox(10, 10, 400, 470, GetColor(255, 255, 255), TRUE);

        // 3. 弾幕の描画（tempScreenに対して行う）
        SetDrawScreen(tempScreen);
        ClearDrawScreen();
        SetDrawArea(10, 10, 400, 470);

        for (int i = 0; i < 30; i++) {
            // 元の描画ロジック
            d1(71 - 20 + 15, i * 22, DS);
            d1(141 - 20 + 15, i * 22, DS);
            d1(180 + 39 + 20 + 15, i * 22, DS);
            d1(180 + 111 + 20 + 15, i * 22, DS);
            d1(i * 22, 65 - 10, DS);
            d1(i * 22, 133 - 10, DS);
            d1(i * 22, 188 - 20 - 10, DS);
            d1(i * 22, 243 - 40 - 10, DS);
            d1(i * 22, 311 - 20 - 10, DS);
            d1(i * 22, 365, DS);
        }
        SetDrawArea(0, 0, 640, 480);
        // 4. メイン画面への描画
        SetDrawScreen(DX_SCREEN_BACK);

        // 背景の描画
        DrawBox(0, 0, 640, 480, GetColor(40, 39, 57), TRUE); // 背景色
        DrawBox(10, 10, 400, 470, GetColor(80, 0, 1), TRUE);  // プレイ領域背景

        // マスクを適用して弾幕を描画
        DrawGraph(0, 0, tempScreen, TRUE);
        SetBlendGraphParam(-1, 0, 0, FALSE); // 設定をリセット

        // UI（右側の文字など）の描画
        DrawString(410, 40, "最高得点", GetColor(169, 169, 197));
        DrawString(410, 70, "得点", GetColor(245, 245, 240));
        DrawString(410, 130, "Player", GetColor(107, 77, 77));
        DrawString(469, 130, "★★★★★", GetColor(163, 59, 58));
        DrawString(410, 160, "Bomb", GetColor(210, 230, 210));
        DrawString(469, 160, "★★★", GetColor(210, 230, 210));
        DrawString(410, 220, "Power", GetColor(133, 77, 4));
        DrawBox(460, 220, 600, 240, GetColor(165, 165, 193), TRUE);
        DrawString(410, 250, "Graze", GetColor(46, 131, 76));
        DrawString(410, 280, "点", GetColor(92, 91, 105));
        DrawCircle(510, 380, 60, GetColor(170, 7, 20), TRUE);
        DrawCircle(510, 380, 48, GetColor(40, 39, 57), TRUE);

        GetMousePoint(&MouseX, &MouseY);
        DrawFormatString(0, 0, StringCr, "座標Ｘ %d　　座標Ｙ %d", MouseX, MouseY);

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}