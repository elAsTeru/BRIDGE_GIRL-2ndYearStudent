#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	// ポジションの取得
	void GetPos(const Player& player);
	void Titlecamera(const Player& player);
	void GameEndCamera(const Player& player);
private:
	VECTOR	pos;			// ポジション
	VECTOR  ScreenPos;
};
#endif // !_CAMERA_H_