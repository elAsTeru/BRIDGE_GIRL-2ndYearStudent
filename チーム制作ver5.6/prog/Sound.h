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
		eScene_Title,    //�ݒ���
		eScene_Menu,     //���j���[���
		eScene_Game,		//�Q�[�����
		eScene_GameClear,     //�Q�[�����
		eScene_GameOver,     //�Q�[�����
	} eScene;
	int NeutralBGM;		//eScene_Game,	�@��BGM
	int GameClearBGM;	//eScene_GameClear��BGM
	int GameOverBGM;	//eScene_GameOver,��BGM
	int NowBGM;//������Ă���BGM
	int pressSpace;//�I����
	int TitleBGM;

};						
#endif // !_SOUND_H_
