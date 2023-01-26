#ifndef _CROW_ENEMY_H_
#define _CROW_ENEMY_H_

#include "EnemyBase.h"

class CrowEnemy : public EnemyBase
{
public:
	CrowEnemy(int sourceModelHandle, int radFirstSpeed);				// �R���X�g���N�^.
	virtual ~CrowEnemy();				// �f�X�g���N�^.
	void Update();
	int radSpeed;						// ���x�i�[�p�ϐ�
private:
	float rad;								// sin�ړ��p�̃��W�A���֐�.
	int radFirstSpeed;				// rad�ɂ��㉺�ړ��̏���
};

#endif	// _CROW_ENEMY_H_