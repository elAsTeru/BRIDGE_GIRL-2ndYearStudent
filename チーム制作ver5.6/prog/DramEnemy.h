#ifndef _DRAM_ENEMY_H_
#define _DRAM_ENEMY_H_

#include "EnemyBase.h"

class DramEnemy:public EnemyBase
{
public:
	DramEnemy(int sourceModelHandle);				// �R���X�g���N�^.
	virtual ~DramEnemy();				// �f�X�g���N�^.

	void Update();
private:
	float rad;								// sin�ړ��p�̃��W�A���֐�.
};

#endif // _OBSTACLE_BASE_H_
