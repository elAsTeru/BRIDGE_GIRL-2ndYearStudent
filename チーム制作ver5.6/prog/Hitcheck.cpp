#include "HitCheck.h"
#include "Player.h"
#include "EnemyManager.h"
#include "EnemyBase.h"

void HitChecker::Check(Player& player, EnemyManager& EnemyManager)
{
	// Z����X���̓񎟌����W�Ƃ��Ă����蔻����s��.
	VECTOR yZeroPlayer = VGet(player.GetPos().x, player.GetPos().y + 10, player.GetPos().z);
	bool isHit = true;

	// ��x�ł��Ԃ�������ʒu���ς��̂Ńq�b�g�v�Z�����Ȃ���.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < EnemyNum; i++)
		{
			EnemyBase* enemy = EnemyManager.GetEnemy(i);
			if (enemy != NULL)
			{
				VECTOR yZeroEnemy = VGet(enemy->GetPos().x, enemy->GetPos().y, enemy->GetPos().z);

				// ���݂��̃|�W�V�����Ɣ��a�̋������d�Ȃ����瓖�����Ă��邱�ƂɂȂ�.
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
		// �q�b�g���Ă���v�Z���Ȃ���+�񎟌����W�Ƃ��Ẵv���C���[�̈ʒu���X�V.
		if (isHit)
		{
			yZeroPlayer = VGet(player.GetPos().x, player.GetPos().y + 10, player.GetPos().z);
			break;
		}
	}
}