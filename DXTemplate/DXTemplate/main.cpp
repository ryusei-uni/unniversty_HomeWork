#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0)
    {
        int w = 640;
        int h = 480;

        ClearDrawScreen();

        DrawCircle(w/2,h/2+10,120,GetColor(180,80,0),TRUE);
        DrawCircle(w / 2, h / 2 + 10, 40, GetColor(255,0,0), TRUE);
        DrawCircle(w / 2+82, h / 2 + 10, 40, GetColor(255, 105, 105), TRUE);
        DrawCircle(w / 2-82, h / 2 + 10, 40, GetColor(250, 105, 105), TRUE);
        DrawOval(w/2+30,h/2-60,10,15,GetColor(0,0,0),TRUE);
        DrawOval(w/2-30, h/2 - 60, 10, 15, GetColor(0, 0, 0), TRUE);

        for (int i = 0;i >= 180;i++) {
            DrawPixel();
        }

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}