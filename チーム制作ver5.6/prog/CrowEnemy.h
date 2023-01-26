#ifndef _CROW_ENEMY_H_
#define _CROW_ENEMY_H_

#include "EnemyBase.h"

class CrowEnemy : public EnemyBase
{
public:
	CrowEnemy(int sourceModelHandle, int radFirstSpeed);				// コンストラクタ.
	virtual ~CrowEnemy();				// デストラクタ.
	void Update();
	int radSpeed;						// 速度格納用変数
private:
	float rad;								// sin移動用のラジアン関数.
	int radFirstSpeed;				// radによる上下移動の初速
};

#endif	// _CROW_ENEMY_H_