#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class EnemyBase;

class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Draw();					// 描画.
	void Update();

	// 衝突処理.
	void OnHitObstruct(EnemyBase& obstruct);

	// モデルハンドルの取得.
	int GetModelHandle() { return modelHandle; }

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }	
	void SetPos(const VECTOR set) { pos = set; }	

	void jump();									//ジャンプしてる時重力をかける、着地するとフラグ関係のリセット	

	void PlayAnim();								//anime再生用の関数
	void attachAnim(int animPlay);					//アニメーションのアタッチ
	void titleanim();
	void Endanim(int gameState);
	void stopSound();

	void playerInit();								//プレイヤーの状態を初期化

	float GetHitRadius() { return hitRadius; }		// あたり判定半径の取得.


private:
	float	hitRadius;				// あたり判定の半径.
	int		modelHandle;			// モデルハンドル.
	VECTOR	pos;					// ポジション.
	bool	jumpFlag;				//ジャンプのフラグ 
	float	animTotal;				//アニメーションの総再生時間
	float	animNowTime;			//アニメーションの現在の再生時間
	int		animIndex;				//アニメーションのインデックス
	bool	stateRun;				//走っている状態か否かのフラグ
	VECTOR  mVelocity;				//加速度
	bool	playerDebugFlag ;		//デバッグ情報を表示するときのフラグ
	bool Titleflag = false;//タイトル時のアニメ切り替えようのフラグ
	bool damegeFlag = false;//ダメージを受けた時のフラグ
	int jumpSoundHandle;
	int runSound;
};
#endif // !_PLAYER_H_