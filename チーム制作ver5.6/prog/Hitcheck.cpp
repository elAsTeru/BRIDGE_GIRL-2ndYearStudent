#include "HitCheck.h"
#include "Player.h"
#include "EnemyManager.h"
#include "EnemyBase.h"

void HitChecker::Check(Player& player, EnemyManager& EnemyManager)
{
	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player.GetPos().x, player.GetPos().y + 10, player.GetPos().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < EnemyNum; i++)
		{
			EnemyBase* enemy = EnemyManager.GetEnemy(i);
			if (enemy != NULL)
			{
				VECTOR yZeroEnemy = VGet(enemy->GetPos().x, enemy->GetPos().y, enemy->GetPos().z);

				// お互いのポジションと半径の距離が重なったら当たっていることになる.
				VECTOR playerToObs = VSub(yZeroEnemy, yZeroPlayer);
				//printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);
				if (VSize(playerToObs) < player.GetHitRadius() + enemy->GetHitRadius())
				{
					//printfDx("Hit!");
					player.OnHitObstruct(*enemy);
					isHit = true;
					break;
				}
			}
		}
		// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.
		if (isHit)
		{
			yZeroPlayer = VGet(player.GetPos().x, player.GetPos().y + 10, player.GetPos().z);
			break;
		}
	}
}