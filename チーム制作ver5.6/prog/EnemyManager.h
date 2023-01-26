#pragma once
//-----------------------------------------------------------------------------
// @brief  ��Q���}�l�[�W���[.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

class EnemyBase;

// ��Q���̐�.
const int EnemyNum = 50;

#define ENEMY_SPACE_D 20.0f // ��Q���̏c�Ԋu.
#define ENEMY_SPACE_W 20.0f // ��Q���̉��Ԋu.

class EnemyManager final
{
public:
	EnemyManager();				// �R���X�g���N�^.
	~EnemyManager();				// �f�X�g���N�^.

	void CreateEnemys();			// ��Q������.
	void DestroyEnemys();		// ��Q���폜.

	void Update();					// �X�V.
	void Draw();					// �`��.
	 
	// �w��ԍ��̏�Q�����擾.
	EnemyBase* GetEnemy(int eneNum);

private:
	EnemyBase* enemys[EnemyNum];

	int crowModelSourceHandle;		// ���V���f���̑�{�̃n���h��.
	int dramModelSourceHandle;	// �Î~���f���̑�{�̃n���h��.

//protected:
//	VECTOR rota;
};

#endif // _ENEMY_MANAGER_H_