#ifndef _ENEMY_BASE_H_
#define _ENEMY_BASE_H_

#include "DxLib.h"

class EnemyBase
{
public:
	EnemyBase(int sourceModelHandle);	// �R���X�g���N�^.
	virtual ~EnemyBase();				// �f�X�g���N�^.

	virtual void Update() = 0;				// �X�V.
	virtual void Draw();					// �`��.

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }
	void SetPos(const VECTOR set) { pos = set; }
	void SetRotate(const VECTOR set) { rotate = set; }
	void SetRadSpeed(const float set) { radSpeed = set; }
	float GetHitRadius() { return hitRadius; }

protected:
	int		modelHandle;					// ���f���n���h��
	VECTOR	pos;							// �|�W�V����
	VECTOR	rotate;							// ��]
	VECTOR	move;							// �ړ�
	float	radSpeed;
	float	hitRadius;						// �����蔻��̔��a
};

#endif // _ENEMY_BASE_H_