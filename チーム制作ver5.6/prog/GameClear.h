#pragma once
#ifndef _GAMECLEAR_H_
#define _GAMECLEAR_H_


#include"DxLib.h"
#include "Player.h"
#include "Camera.h"
#include "bridge.h"
//#include"SceneMgr.h"
class Gameclear
{
public:
	Gameclear();
	~Gameclear();  
	void Draw();
	void Update();
	void GCInit();
private:
	int ClearImg;//‰æ‘œƒnƒ“ƒhƒ‹
	Player* player = new Player();
	Camera* camera = new Camera();
	int Font;
	int SPACEImg;
	float ExpansionRate;
	float changeCode;
};


#endif // !_GAMECLEAR_H_

