
#include"GameOver.h"



GameOver::GameOver()
{
	OverImg= LoadGraph("data/img/負け.png");
    Font = CreateFontToHandle(NULL, 50, 5);
    SPACEImg = LoadGraph("data/img/SPACEキー.png");
    ExpansionRate = 0;
    changeCode = 0.3f;
}

GameOver::~GameOver()
{

    delete(player);
    delete(camera);
    DeleteGraph(OverImg);
    DeleteGraph(SPACEImg);
}



void GameOver::Update()
{
}


void GameOver::Draw()
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
    DrawGraph(0, 0,OverImg, false);
    DrawExtendGraph(30 - (int)ExpansionRate, 650 - (int)ExpansionRate, 30 + 125 + (int)ExpansionRate, 700 + (int)ExpansionRate, SPACEImg, false);
    DrawStringToHandle(30 + 125, 650, " タイトルへ", (0, 0, 0), Font);
    //モーション呼び出し
    player->Endanim(1);
    //プレイヤー描画
    player->Draw();
    //カメラ呼び出し
    camera->GameEndCamera(*player);

}
//初期化
void GameOver::GOInit()
{
    player->playerInit();
}