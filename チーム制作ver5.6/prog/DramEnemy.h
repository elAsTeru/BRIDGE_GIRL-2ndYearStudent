#ifndef _DRAM_ENEMY_H_
#define _DRAM_ENEMY_H_

#include "EnemyBase.h"

class DramEnemy:public EnemyBase
{
public:
	DramEnemy(int sourceModelHandle);				// コンストラクタ.
	virtual ~DramEnemy();				// デストラクタ.

	void Update();
private:
	float rad;								// sin移動用のラジアン関数.
};

#endif // _OBSTACLE_BASE_H_
