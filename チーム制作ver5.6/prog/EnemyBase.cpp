//-----------------------------------------------------------------------------
// @brief  ��Q�����N���X.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "EnemyBase.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  �R���X�g���N�^.
//-----------------------------------------------------------------------------
EnemyBase::EnemyBase(int sourceModelHandle)
	: modelHandle(-1)
	, pos(VGet(0.0f, 0.0f, 0.0f))
	, rotate(VGet(0.0f, 0.0f, 0.0f))
	, radSpeed(0.0f)
	, move(VGet(0.0f, 0.0f, 0.0f))
	, hitRadius(5.0f)
{
	// �R�c���f���̓ǂݍ���
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("�f�[�^�ǂݍ��݂Ɏ��s. sourceId:%d", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("data/model/enemy/obstructStatic.pmd");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:�f�[�^�ǂݍ��݂Ɏ��s");
	}
#endif

}

//-----------------------------------------------------------------------------
// @brief  �f�X�g���N�^.
//-----------------------------------------------------------------------------
EnemyBase::~EnemyBase()
{
	// ���f���̃A�����[�h.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  �`��.
//-----------------------------------------------------------------------------
void EnemyBase::Draw()
{
	// �R�c���f���̕`��
	MV1DrawModel(modelHandle);

	// �f�o�b�O�����蔻��.
	//DrawSphere3D(pos, hitRadius, 5, 0x00ffff, 0x00ffff, false);
}