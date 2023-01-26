#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_


#include"DxLib.h"
class Sound
{
public:
	Sound();
	~Sound();
	void soundPlay(int playNumber);
	void playerSound(int playNumber);
private:
	typedef enum {
		eScene_Title,    //設定画面
		eScene_Menu,     //メニュー画面
		eScene_Game,		//ゲーム画面
		eScene_GameClear,     //ゲーム画面
		eScene_GameOver,     //ゲーム画面
	} eScene;
	int NeutralBGM;		//eScene_Game,	　のBGM
	int GameClearBGM;	//eScene_GameClearのBGM
	int GameOverBGM;	//eScene_GameOver,のBGM
	int NowBGM;//今流れているBGM
	int pressSpace;//選択音
	int TitleBGM;

};						
#endif // !_SOUND_H_
