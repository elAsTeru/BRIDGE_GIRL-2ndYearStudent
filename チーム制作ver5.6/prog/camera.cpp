#include "Player.h"
#include "Camera.h"


// コンストラクタ
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(4.0f, 600.0f);

	pos = VGet(0.0f, 0.0f, 0.0f);
	ScreenPos = VGet(0.0f, 0.0f, 0.0f);
}

// デストラクタ
Camera::~Camera()
{
	// 処理なし.
}

void Camera::GetPos(const Player& player)
{
	pos = VGet(player.GetPos().x + 20.0f, player.GetPos().y + 30.0f, player.GetPos().z + -60.0f);
	ScreenPos = VGet(player.GetPos().x + 20.0f, player.GetPos().y + 5.0f, player.GetPos().z + 0.0f);
	//ScreenPos = VGet(0.0f, player.GetPos().y + 15.0f, player.GetPos().z + 10.0f);
	SetCameraPositionAndTarget_UpVecY(pos, ScreenPos);
}
//タイトルのカメラ
void Camera::Titlecamera(const Player& player)
{
	pos = VGet(player.GetPos().x - 10.0f, player.GetPos().y+15, player.GetPos().z-3);
	ScreenPos = VGet(player.GetPos().x + 20.0f, player.GetPos().y + 15.0f, player.GetPos().z + 0.0f);
	//ScreenPos = VGet(0.0f, player.GetPos().y + 15.0f, player.GetPos().z + 10.0f);
	SetCameraPositionAndTarget_UpVecY(pos, ScreenPos);
}

//Gameclear,GameOverで呼び出されるカメラ
void Camera::GameEndCamera(const Player& player)
{
	pos = VGet(player.GetPos().x + 13.0f, player.GetPos().y + 15, player.GetPos().z + 5);
	ScreenPos = VGet(player.GetPos().x-15.0f, player.GetPos().y + 15.0f, player.GetPos().z - 20.0f);
	//ScreenPos = VGet(0.0f, player.GetPos().y + 15.0f, player.GetPos().z + 10.0f);
	SetCameraPositionAndTarget_UpVecY(pos, ScreenPos);
}