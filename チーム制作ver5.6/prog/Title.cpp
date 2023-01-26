#include "DxLib.h"
#include "Title.h"
#include "SceneMgr.h"


Title::Title()
{
    rodeFlag   = TRUE;
    deleteFlag = FALSE;
}
Title::~Title()
{
}
void Title::Update()
{
    if (CheckHitKey(KEY_INPUT_SPACE))
    { 
        SceneMgr_ChangeScene(eScene_Game);
        deleteFlag = TRUE;
    }

}
void Title::Draw()
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
    //アニメの呼び出しと描画
    player->titleanim();
    bridge->Draw(player->GetPos());
    player->Draw();
    //カメラ呼び出し
    camera->Titlecamera(*player);
    DrawExtendGraph(700 - (int)ExpansionRate, 500 - (int)ExpansionRate, 825 + (int)ExpansionRate, 550 + (int)ExpansionRate, SPACEImg, false);
    DrawStringToHandle(705, 105, "BRIDGE GIRL", GetColor(0, 0, 0), TitleFont);
    DrawStringToHandle(700, 100, "BRIDGE GIRL", Cr, TitleFont);

    DrawStringToHandle(700 + 125, 500, " ゲーム開始", Cr, startFont);
}
void Title::Rode()
{
    if (rodeFlag == TRUE)
    {
        player = new Player();
        camera = new Camera();
        bridge = new Bridge();
    
        Cr = GetColor(255, 255, 255);
        startFont = CreateFontToHandle(NULL, 50, 5);
        TitleFont = CreateFontToHandle(NULL, 100, 10);
        ExpansionRate = 0;
        changeCode = 0.3f;
        SPACEImg = LoadGraph("data/img/SPACEキー.png");

        rodeFlag = FALSE;
    }
}
void Title::Delete()
{
    if (deleteFlag == TRUE)
    {
        delete(player);
        delete(camera);
        delete(bridge);
        DeleteGraph(SPACEImg);

        rodeFlag   = TRUE;
        deleteFlag = FALSE;
    }
}