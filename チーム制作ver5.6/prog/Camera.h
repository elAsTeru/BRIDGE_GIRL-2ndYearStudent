#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	// �|�W�V�����̎擾
	void GetPos(const Player& player);
	void Titlecamera(const Player& player);
	void GameEndCamera(const Player& player);
private:
	VECTOR	pos;			// �|�W�V����
	VECTOR  ScreenPos;
};
#endif // !_CAMERA_H_