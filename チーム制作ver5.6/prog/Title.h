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
	// 読み込みフラグ
	bool rodeFlag;
	// 削除フラグ
	bool deleteFlag;
	unsigned int Cr;
	Player* player;
	Camera* camera;
	Bridge* bridge;
	int startFont;//「スペースを押すとスタート」用のフォントサイズ
	int TitleFont;//「タイトル」用のフォントサイズ
	int SPACEImg;

	float ExpansionRate;
	float changeCode;
};
#endif // !_TITLE_H_
