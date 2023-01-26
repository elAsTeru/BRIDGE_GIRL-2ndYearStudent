#include "DxLib.h"
#include "SceneMgr.h"
#define LIMITTIME 60


SceneMgr::SceneMgr()
{
    loadImg = LoadGraph("data/img/LOADING.png");
    soundFlag = false;
    
}
SceneMgr::~SceneMgr()
{
    delete(game);
    delete(GameC);
    delete(title);
    DeleteGraph(loadImg);
}

//更新
void SceneMgr::SceneMgr_Update() {

    //前のSceneを保存
    BackScene = Scene;
    if (soundFlag == false)
    {
        //音を鳴らしてフラグを立てる
        sound->soundPlay(Scene);
        soundFlag = true;
    }
    //シーンによって処理を分岐
    //現在の画面がメニューなら
    //メニュー画面の更新処理をする
    //以下略
    switch (Scene) {       
    case eScene_Title:     
        title->Rode();
        title->Update();
        title->Delete();
        break; 

    case eScene_Game:
        game->Rode();
        game->Update();
        game->Delete();
        break;


    case eScene_GameClear:
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            //初期化と画面遷移
            SceneMgr_ChangeScene(eScene_Title);
            game->GameInit();
            GameC->GCInit();
        }
        break;


    case eScene_GameOver:
        if (CheckHitKey(KEY_INPUT_SPACE) )
        {
            //初期化と画面遷移
            SceneMgr_ChangeScene(eScene_Title);
            game->GameInit();
            GameO->GOInit();
        }
        break;
    }


    //入力を止めるために0.5秒時間を挟む
    if (BackScene!=Scene&&BackScene!= eScene_Game)
    {
        DrawGraph(0, 0, loadImg, false);
        ScreenFlip();
        sound->soundPlay(eScene_Menu);
        WaitTimer(500);
    }
    //前のSceneで流れていた音楽を止めるためのフラグ
    if (BackScene != Scene)
    {
        soundFlag = false;
    }
}

//描画
void SceneMgr::SceneMgr_Draw() {
    switch (Scene) {  
    case eScene_Title:
        title->Rode();
        title->Draw();
        title->Delete();
        break;        
    case eScene_Game:
        game->Rode();
        game->Loop();
        game->Delete();
        break;
    case eScene_GameClear:
        GameC->Draw();
        break;
    
    case eScene_GameOver:
        GameO->Draw();
        break;
    }
}

// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene NextScene) {
    Scene = NextScene;
}