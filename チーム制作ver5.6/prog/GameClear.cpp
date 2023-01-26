#include"Gameclear.h"
Gameclear::Gameclear()
{
	ClearImg = LoadGraph("data/img/勝ち.png");
    Font = CreateFontToHandle(NULL, 50, 5);
    SPACEImg = LoadGraph("data/img/SPACEキー.png");
    ExpansionRate = 0;
    changeCode = 0.3f;
}

Gameclear::~Gameclear()
{
    delete(player);
    delete(camera);
    DeleteGraph(ClearImg);
    DeleteGraph(SPACEImg);
}

void Gameclear::Draw()
{
    ExpansionRate += changeCode;
    if (ExpansionRate >= 3)
    {
        changeCode = -0.3f;
    }
    if (ExpansionRate < 0)
    {
        changeCode = 0.3f;
    }
    //背景描画
    DrawGraph(0, 0, ClearImg, false);
    DrawExtendGraph(30 - (int)ExpansionRate, 650 - (int)ExpansionRate, 30 + 125 + (int)ExpansionRate, 700 + (int)ExpansionRate, SPACEImg, false);
    DrawStringToHandle(30 + 125, 650, " タイトルへ", (0, 0, 0), Font);
    //アニメーション呼び出し
    player->Endanim(0);
    //プレイヤー描画
    player->Draw();
    //カメラ呼び出し
    camera->GameEndCamera(*player);

}

void Gameclear::Update()
{
}
//初期化
void Gameclear::GCInit()
{
    player->playerInit();

}

