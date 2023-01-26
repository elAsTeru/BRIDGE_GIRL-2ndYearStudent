#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_
#include "Game.h"
#include "Title.h"
#include"Gameclear.h"
#include"GameOver.h"
#include"Sound.h"
typedef enum {
    eScene_Title,    //設定画面
    eScene_Menu,     //メニュー画面
    eScene_Game,     //ゲーム画面
    eScene_GameClear,     //ゲーム画面
    eScene_GameOver,     //ゲーム画面
} eScene;

static eScene Scene;    //シーン管理変数
// 引数 nextScene にシーンを変更する
void SceneMgr_ChangeScene(eScene nextScene);

class SceneMgr
{
public:
    SceneMgr();
    ~SceneMgr();

    //更新
    void SceneMgr_Update();

    //描画
    void SceneMgr_Draw();
private:
    Game* game = new Game();
    Title* title = new Title();
    Gameclear* GameC = new Gameclear;
    GameOver* GameO = new GameOver;
    Sound* sound = new Sound;
    int loadImg;    //画面遷移時のloading画像のハンドル
    int BackScene;//ひとつまえのScene
    bool soundFlag;//サウンド停止用のフラグ
};
#endif // !_SCENEMGR_H_
