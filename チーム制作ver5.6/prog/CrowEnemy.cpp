#include "CrowEnemy.h"

#define _USE_MATH_DEFINES
#include <math.h>

CrowEnemy::CrowEnemy(int sourceModelHandle, int radFirstSpeed)
	: EnemyBase(sourceModelHandle)
	, radFirstSpeed(radFirstSpeed)
{
	pos = VGet(0, 0, 0);
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 50.0f));
	rad = 0;
	radSpeed = radFirstSpeed;
	hitRadius = 5.0f;
}

CrowEnemy::~CrowEnemy(){}

void CrowEnemy::Update()
{
	rad += static_cast<float>((M_PI / 180) * radSpeed);

	pos.y = 15.0f + sinf(rad)*10;				//高さが変わる

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);
}