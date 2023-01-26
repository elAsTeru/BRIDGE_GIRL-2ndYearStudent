#pragma once
#ifndef _HITCHECK_H_
#define _HITCHECK_H_

class EnemyManager;
class Player;

class HitChecker
{
public:
	static void Check(Player& player, EnemyManager& enemyManager);
};
#endif // !_HITCHECK_H_