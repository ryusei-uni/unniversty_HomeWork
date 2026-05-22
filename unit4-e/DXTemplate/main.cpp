#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    int x = 0;
    int y = 0;
    int w = 640;
    int h = 480;
    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        if (CheckHitKey(KEY_INPUT_LEFT) == 1) x -= 2;
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) x += 2;
        if (CheckHitKey(KEY_INPUT_UP) == 1) y -= 2;
        if (CheckHitKey(KEY_INPUT_DOWN) == 1) y += 2;
        
        if (CheckHitKey(KEY_INPUT_R) == 1) {
            x = 0;
            y = 0;
        }

       
        DrawCircle(x + w / 2, y + h / 2,50,GetColor(255,255,0),TRUE);
        DrawString(50,50,"‚±‚ñ‚É‚¿‚Í", GetColor(0, 0, 0), TRUE);

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}