#pragma once
#ifndef _GAME_H_
#define _GAME_H_


#include "Player.h"
#include "Camera.h"
#include "bridge.h"
#include "EnemyManager.h"

class Game
{
public:
	Game();
	~Game();
	void Rode();
	void Delete();
	void Update();
	void Loop();
	void GameInit();
	void TimeGet(int GTime) { Time = GTime; };
private:
	//
	bool rodeFlag;
	//
	bool deleteFlag;
	// 各生成
	Player* player;
	EnemyManager* enemy;
	Camera* camera;
	Bridge* bridge;
	int Time;//時間制限表示用の受け取り変数
	int TimeFont;//カウントダウン表示用のフォントサイズ
	int CountDownFont;	//時間制限用のフォントサイズ
	int timerImg;//時間制限用の画像
	int timerImgX = 1100, timerImgY = 40;		//時間制限用画像の座標
	float timerImgExtRate = 0.1f;				//時間制限用画像のサイズ倍率
	float timerImgAngle = 0.0f;			//時間制限用画像の回転
	int RedCode;//赤のカラーコード
	int WhiteCode;//赤のカラーコード
	int  fadeNum = 0;//フェードアウト用の変数
	int whiteback;//フェードアウト用の画像ハンドル
	int UpkeyImg;//上キー画像
	int blackback;//フェードアウト用の画像ハンドル
	int startCount;//制限時間のカウント開始タイミング
	bool callend = false;
	bool firstCall = false;
	int Description;
	int  endFlag = 0;//0 ふらぐなし	1　クリア　2　ゲームオーバー
	int startCountSound;//カウントダウン用ハンドル
	int effectResourceHandle;
	bool oneplay = false;
	float position_x = 1100.0f;
	float position_y = 0.0f;
	int playingEffectHandle = -1;
	VECTOR clear;
};
#endif // !_GAME_H_