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
	// �e����
	Player* player;
	EnemyManager* enemy;
	Camera* camera;
	Bridge* bridge;
	int Time;//���Ԑ����\���p�̎󂯎��ϐ�
	int TimeFont;//�J�E���g�_�E���\���p�̃t�H���g�T�C�Y
	int CountDownFont;	//���Ԑ����p�̃t�H���g�T�C�Y
	int timerImg;//���Ԑ����p�̉摜
	int timerImgX = 1100, timerImgY = 40;		//���Ԑ����p�摜�̍��W
	float timerImgExtRate = 0.1f;				//���Ԑ����p�摜�̃T�C�Y�{��
	float timerImgAngle = 0.0f;			//���Ԑ����p�摜�̉�]
	int RedCode;//�Ԃ̃J���[�R�[�h
	int WhiteCode;//�Ԃ̃J���[�R�[�h
	int  fadeNum = 0;//�t�F�[�h�A�E�g�p�̕ϐ�
	int whiteback;//�t�F�[�h�A�E�g�p�̉摜�n���h��
	int UpkeyImg;//��L�[�摜
	int blackback;//�t�F�[�h�A�E�g�p�̉摜�n���h��
	int startCount;//�������Ԃ̃J�E���g�J�n�^�C�~���O
	bool callend = false;
	bool firstCall = false;
	int Description;
	int  endFlag = 0;//0 �ӂ炮�Ȃ�	1�@�N���A�@2�@�Q�[���I�[�o�[
	int startCountSound;//�J�E���g�_�E���p�n���h��
	int effectResourceHandle;
	bool oneplay = false;
	float position_x = 1100.0f;
	float position_y = 0.0f;
	int playingEffectHandle = -1;
	VECTOR clear;
};
#endif // !_GAME_H_