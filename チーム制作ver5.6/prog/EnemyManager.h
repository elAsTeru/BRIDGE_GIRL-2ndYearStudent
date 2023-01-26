#pragma once
//-----------------------------------------------------------------------------
// @brief  障害物マネージャー.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#ifndef _ENEMY_MANAGER_H_
#define _ENEMY_MANAGER_H_

class EnemyBase;

// 障害物の数.
const int EnemyNum = 50;

#define ENEMY_SPACE_D 20.0f // 障害物の縦間隔.
#define ENEMY_SPACE_W 20.0f // 障害物の横間隔.

class EnemyManager final
{
public:
	EnemyManager();				// コンストラクタ.
	~EnemyManager();				// デストラクタ.

	void CreateEnemys();			// 障害物生成.
	void DestroyEnemys();		// 障害物削除.

	void Update();					// 更新.
	void Draw();					// 描画.
	 
	// 指定番号の障害物を取得.
	EnemyBase* GetEnemy(int eneNum);

private:
	EnemyBase* enemys[EnemyNum];

	int crowModelSourceHandle;		// 浮遊モデルの大本のハンドル.
	int dramModelSourceHandle;	// 静止モデルの大本のハンドル.

//protected:
//	VECTOR rota;
};

#endif // _ENEMY_MANAGER_H_