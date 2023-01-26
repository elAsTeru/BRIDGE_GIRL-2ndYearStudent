//-----------------------------------------------------------------------------
// @brief  障害物基底クラス.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "EnemyBase.h"

#define USE_MODEL_DUPLICATE 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
EnemyBase::EnemyBase(int sourceModelHandle)
	: modelHandle(-1)
	, pos(VGet(0.0f, 0.0f, 0.0f))
	, rotate(VGet(0.0f, 0.0f, 0.0f))
	, radSpeed(0.0f)
	, move(VGet(0.0f, 0.0f, 0.0f))
	, hitRadius(5.0f)
{
	// ３Ｄモデルの読み込み
#if USE_MODEL_DUPLICATE
	modelHandle = MV1DuplicateModel(sourceModelHandle);
	if (modelHandle < 0)
	{
		printfDx("データ読み込みに失敗. sourceId:%d", sourceModelHandle);
	}
#else
	modelHandle = MV1LoadModel("data/model/enemy/obstructStatic.pmd");
	if (modelHandle < 0)
	{
		printfDx("ObstructStatic:データ読み込みに失敗");
	}
#endif

}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
EnemyBase::~EnemyBase()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
}
//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void EnemyBase::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);

	// デバッグあたり判定.
	//DrawSphere3D(pos, hitRadius, 5, 0x00ffff, 0x00ffff, false);
}