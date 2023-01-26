#pragma once
#ifndef _TITLE_H_
#define _TITLE_H_


#include "Player.h"
#include "Camera.h"
#include "bridge.h"

class Title
{
public:
	Title();
	~Title();

	void Rode();
	void Delete();
	void Update();
	void Draw();
	//bool judTitle() {return flag};
private:
	// �ǂݍ��݃t���O
	bool rodeFlag;
	// �폜�t���O
	bool deleteFlag;
	unsigned int Cr;
	Player* player;
	Camera* camera;
	Bridge* bridge;
	int startFont;//�u�X�y�[�X�������ƃX�^�[�g�v�p�̃t�H���g�T�C�Y
	int TitleFont;//�u�^�C�g���v�p�̃t�H���g�T�C�Y
	int SPACEImg;

	float ExpansionRate;
	float changeCode;
};
#endif // !_TITLE_H_
