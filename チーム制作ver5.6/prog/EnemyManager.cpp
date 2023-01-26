//-----------------------------------------------------------------------------
// @brief  ��Q���}�l�[�W���[.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "EnemyManager.h"
#include "EnemyBase.h"
#include "CrowEnemy.h"
#include "DramEnemy.h"

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
EnemyManager::EnemyManager()
	: crowModelSourceHandle(-1)
	, dramModelSourceHandle(-1)
{
	for (int i = 0; i < EnemyNum; i++)
	{
			enemys[i] = NULL;
	}
}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
EnemyManager::~EnemyManager()
{
	// �����Ȃ�.
}

//-----------------------------------------------------------------------------
// @brief  ��Q������.
//-----------------------------------------------------------------------------
void EnemyManager::CreateEnemys()
{
	crowModelSourceHandle = MV1LoadModel("data/enemy/obstructFloat.pmx");
	dramModelSourceHandle = MV1LoadModel("data/enemy/obstructStatic.pmd");
	

	// ��Q���̔z�u�}�f�[�^�Ƃ��Ă�linemap��p�ӂ���.
	int enemyDisposition[EnemyNum] =
	{ 0,0,0,0,1,0,0,0,0,2,0,0,0,0,1,0,0,1,0,0,2,0,0,0,1,0,0,0,0,2,
	0,0,0,0,1,0,0,2,0,2,0,0,0,0,1,1,0,2,0,0 };
	int crowSpeedY[EnemyNum] =
	{ 0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,3,
	0,0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,4,0,0 };

	for (int i = 0; i < EnemyNum; i++)
	{
		int nowLine = enemyDisposition[i];
		int nowCrowSpeedY = crowSpeedY[i];

		// linemap�ɓ����Ă��鐔�l�ɂ���ď�Q���̎�ނ����肷��
		if (nowLine == 1)
		{
			enemys[i] = new DramEnemy(dramModelSourceHandle);
			
		}
		else if (nowLine == 2)
		{
			enemys[i] = new CrowEnemy(crowModelSourceHandle,nowCrowSpeedY);	
		}
		else
		{
			enemys[i] = NULL;
		}

		// �ʒu�̏�����.
		if (enemys[i] != NULL)
		{
			if (nowLine == 1)
			{
				enemys[i]->SetPos(
					VGet((ENEMY_SPACE_W * i) - (ENEMY_SPACE_W * 0.5f), 0.0f, -5.0f));		//���A�c�A���s��
				
				enemys[i]->SetRotate(
					VGet(90.0f * DX_PI_F / 180.0f, 0.0f, 0.0f));		//XYZ

			}

			if (nowLine == 2)
			{
				enemys[i]->SetPos(
					VGet((ENEMY_SPACE_W * i) - (ENEMY_SPACE_W * 0.5f), 50.0f, 0));
				enemys[i]->SetRadSpeed(
					nowCrowSpeedY);
			}
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  ��Q���폜.
//-----------------------------------------------------------------------------
void EnemyManager::DestroyEnemys()
{

	for (int i = 0; i < EnemyNum; i++)
	{
		if (enemys[i] != NULL)
		{
			delete(enemys[i]);
			enemys[i] = NULL;
		}
	}
	MV1DeleteModel(dramModelSourceHandle);
	MV1DeleteModel(crowModelSourceHandle);
}

//-----------------------------------------------------------------------------
// @brief  �X�V.
//-----------------------------------------------------------------------------
void EnemyManager::Update()
{
	for (int i = 0; i < EnemyNum; i++)
	{
		if (enemys[i] != NULL)
		{
			enemys[i]->Update();
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void EnemyManager::Draw()
{
	for (int i = 0; i < EnemyNum; i++)
	{
		if (enemys[i] != NULL)
		{
			enemys[i]->Draw();
		}
	}
}

//-----------------------------------------------------------------------------
// @brief  �w��ԍ��̏�Q�����擾.
//-----------------------------------------------------------------------------
EnemyBase* EnemyManager::GetEnemy(int eneNum)
{
	return enemys[eneNum];
}
