#include "DxLib.h"

void drawBackground(void) {
    // 背景
    DrawBox(0, 0, 640, 480, GetColor(20, 20, 60), TRUE);
    DrawString(240, 20, "PJ2 ゲーム", GetColor(255, 255, 255));
}

void drawPlayer(int PX, int PY) {
    // プレイヤー
    DrawCircle(PX, PY, 20, GetColor(100, 200, 255), TRUE);

}

void drawObject(void) {
    // オブジェクト
    DrawCircle(200, 150, 10, GetColor(255, 255, 0), TRUE);
    DrawCircle(400, 300, 10, GetColor(255, 255, 0), TRUE);
}

void controlPlayer() {
    if (CheckHitKey(KEY_INPUT_RIGHT) && 640 > player_x)player_x += 2;
    if (CheckHitKey(KEY_INPUT_LEFT) && 0 < player_x)player_x -= 2;
    if (CheckHitKey(KEY_INPUT_UP) && 0 < player_y)player_y -= 2;
    if (CheckHitKey(KEY_INPUT_DOWN) && 480 > player_y)player_y += 2;
}