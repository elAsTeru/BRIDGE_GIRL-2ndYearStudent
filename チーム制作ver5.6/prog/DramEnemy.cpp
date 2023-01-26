#include "DramEnemy.h"

#define _USE_MATH_DEFINES
#include <math.h>


DramEnemy::DramEnemy(int sourceModelHandle)
	: EnemyBase(sourceModelHandle)
{
	pos = VGet(0, 0, 0);
	rotate = VGet(0.0f, 0.0f, 0.0f);
	hitRadius = 7.0f;
}

DramEnemy::~DramEnemy(){}

void DramEnemy::Update()
{
	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	MV1SetRotationXYZ(modelHandle, rotate);
}