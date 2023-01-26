#pragma once
#ifndef _GAMEOVER_H_
#define _GAMEOVER_H_

#include"DxLib.h"
#include "Player.h"
#include "Camera.h"
class GameOver
{
public:
	GameOver();
	~GameOver();

	void GOInit();

	void Update();
	void Draw();
private:
	int OverImg;//‰æ‘œƒnƒ“ƒhƒ‹
	Player* player = new Player();
	Camera* camera = new Camera();
	int Font;
	int SPACEImg;
	float ExpansionRate;
	float changeCode;
};

#endif // !_GAMEOVER_H_


