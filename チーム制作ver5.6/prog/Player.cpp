#include "Player.h"
#include"CrowEnemy.h"
#include "DramEnemy.h"

#define PLAYER_JUMP_POWER			1.5f		// ジャンプ力
#define PLAYER_GRAVITY				0.07f		// 重力
#define PLAYER_X_VELOCITY				1.0f		// x軸ベース速度
// コンストラクタ
Player::Player()
	: modelHandle(1)
	, hitRadius(5.0f)
	, animIndex(0)
	, animTotal(0)
{
	// ３Ｄモデルの読み込み
	modelHandle = MV1LoadModel("data/結月ゆかり_純_ver1.0/結月ゆかり_純.pmd");
	jumpSoundHandle = LoadSoundMem("data/sound/se_jump1.mp3");
	runSound = LoadSoundMem("data/sound/run_ver.2.mp3");
	//位置初期化
	pos = VGet(0.0f, 0.0f, 0.0f);
	//加速度初期化
	mVelocity = VGet(0.0f, 0.0f, 0.0f);
	//アニメの再生時間を初期化
	animNowTime = 0;
	//ジャンプのフラグの初期化
	jumpFlag = false;
	//走っている状態か否かのフラグの初期化
	stateRun = false;
	//デバッグ情報を表示するときのフラグの初期化
	playerDebugFlag = false;
	//x軸の加速度設定
	mVelocity.x = PLAYER_X_VELOCITY;
	ChangeVolumeSoundMem(255 * 80 / 100, jumpSoundHandle);

}

// デストラクタ
Player::~Player()
{
	// モデルのアンロード.
	MV1DeleteModel(modelHandle);
	DeleteSoundMem(jumpSoundHandle);
	DeleteSoundMem(runSound);

	
}


// 描画
void Player::Draw()
{

	// ３Dモデルのポジション設定
	MV1SetPosition(modelHandle, pos);

	// 3Ⅾモデルの回転
	MV1SetRotationXYZ(modelHandle, VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0f));

	// ３Ｄモデルの描画
	MV1DrawModel(modelHandle);

	VECTOR posi = pos;
	posi.y += 10;
	// デバッグあたり判定.
	//DrawSphere3D(posi, hitRadius, 5, 0x00ffff, 0x00ffff, false);
}

void Player::Update()
{
	//直前に走り状態でなければ
	if (stateRun == false&&damegeFlag!=true)
	{
		//走りモーションをアタッチ
		attachAnim(3);
		stopSound();
		//現在を走り状態にする
		stateRun = true;
		PlaySoundMem(runSound, DX_PLAYTYPE_LOOP);
	}
	//デバッグ情報切り替え
	if (CheckHitKey(KEY_INPUT_0) == 1)
	{
		if (playerDebugFlag == false)
		{
			playerDebugFlag = true;
		}
		else if (playerDebugFlag == true)
		{
			playerDebugFlag = false;
		}
	}
	//プレイヤーの位置初期化
	if (CheckHitKey(KEY_INPUT_9) == 1)
	{
		playerInit();
	}
	//情報表示
	if (playerDebugFlag==true)
	{
		DrawFormatString(0, 0, (0, 0, 0), "pos.yの値は %.2f です", pos.y);
		DrawFormatString(0, 25, (0, 0, 0), "mVelocity.yの値は %.2f です", mVelocity.y);
		DrawFormatString(0, 50, (0, 0, 0), "jumpflagの値は %d です", jumpFlag);

	}
	//ジャンプ状態でないかつ上ボタンでジャンプ
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && jumpFlag == false)
	{
		//ジャンプフラグを立てる
		jumpFlag = true;
		//上方向の加速度にジャンプパワーを代入
		mVelocity.y = PLAYER_JUMP_POWER;
		//ジャンプモーションをアタッチ
		attachAnim(1);
		animNowTime = 5;
		stopSound();
		PlaySoundMem(jumpSoundHandle, DX_PLAYTYPE_BACK);
		
	}
	//アニメーション再生関数
	PlayAnim();
	//ジャンプ中重力
	jump();
	//縦加速度の代入
	pos.y += mVelocity.y;
	//横加速度の代入
	pos.x += mVelocity.x;
}



void Player::jump()
{
	//ジャンプフラグが立っているかの判定
	if (jumpFlag == true)
	{
		//重力をかける
		mVelocity.y -= PLAYER_GRAVITY;
		//ジャンプ前の座標以下になったら
		if (pos.y < 0)
		{
			//フラグを折る
			jumpFlag = false;
			//走り状態になるための準備
			stateRun = false;
			//座標のリセット
			pos.y = 0.0f;
		}
	}
	else
	{
		//ジャンプではないとき縦加速度０
		mVelocity.y = 0;
	}
}
//プレイヤーのアニメーション
void Player::PlayAnim()
{
	if (damegeFlag)
	{
		animNowTime += 1.0f;
		//再生時間を超えたらループ
		if (animNowTime >= 25)
		{
			animNowTime = 25;
		}
	}
	//ジャンプモーションがアタッチされているときの再生
	else if (jumpFlag)
	{
		//0.2ｆづつ再生
		animNowTime += 0.3f;
		//再生時間を超えたらループ
		if (animNowTime >= 30)
		{
			animNowTime = 30;
		}
		
	}
	else
	{
		//0.2ｆづつ再生
		animNowTime += 0.25f;
		//再生時間を超えたらループ
		if (animNowTime >= 16)
		{

			animNowTime = 0;
		}
	}
	//modelhandleをanimNowTime時間のanimindexモーションに動かす
	MV1SetAttachAnimTime(modelHandle, animIndex, animNowTime);
}


void Player::attachAnim(int animPlay)
{
	//アニメーションがアタッチされていたらデタッチ
	if (animIndex != -1)
	{
		MV1DetachAnim(modelHandle, animIndex);
	}
	//アニメーションをモデルハンドルにアタッチ
	animIndex = MV1AttachAnim(modelHandle, animPlay);
	//アタッチしたアニメの総再生時間を出す
	animTotal = MV1GetAnimTotalTime(modelHandle, animIndex);

}
//タイトルに流すアニメーション
void Player::titleanim()
{
	animNowTime += 0.2f;
	//アニメーション切り替えのためのフラグを切り替える
	if (Titleflag==false)
	{
		attachAnim(5);
		if (animNowTime >= 230)
		{

			animNowTime = 0;
			Titleflag = true;
		}
	}
	else
	{
		attachAnim(4);
		if (animNowTime >= 100)
		{

			animNowTime = 0;
			Titleflag = false;
		}
	}
	
	MV1SetAttachAnimTime(modelHandle, animIndex, animNowTime);
}
//GAMEOVER、GAMECLEARの時のアニメーション
void Player::Endanim(int gameState)
{
	animNowTime += 0.5f;
	if (gameState==0)
	{
		attachAnim(7);
		if (animNowTime >= 40)
		{

			animNowTime = 40;
		}
	}
	else
	{
		attachAnim(8);
		if (animNowTime >= 40)
		{

			animNowTime = 40;
		}
	}


	MV1SetAttachAnimTime(modelHandle, animIndex, animNowTime);
}

void Player::playerInit()
{
	//位置初期化
	pos = VGet(0.0f, 0.0f, 0.0f);
	//加速度初期化
	mVelocity = VGet(0.0f, 0.0f, 0.0f);
	//アニメの再生時間を初期化
	animNowTime = 0;
	//ジャンプのフラグの初期化
	jumpFlag = false;
	//走っている状態か否かのフラグの初期化
	stateRun = false;
	//x軸の加速度設定
	mVelocity.x = PLAYER_X_VELOCITY;
	damegeFlag = false;
}

void Player::OnHitObstruct(EnemyBase& obstruct)
{
	//ダメージのフラグが立っていない場合
	if (damegeFlag==false)
	{
		//ダメージのフラグを立てる
		damegeFlag = true;
		//アニメーションアタッチ
		attachAnim(9);
		//進行を止める
		mVelocity.x = 0;
		//アニメーションの再生時間の初期化
		animNowTime = 0;
		stopSound();
	}
	//ダメージを受けたアニメーションが終わり次第位置やフラグの初期化
	if (animNowTime>=25)
	{
		playerInit();
	}
	
	//pos = VAdd(yZeroObstruct, awayVec);
}
void Player::stopSound()
{
	StopSoundMem(runSound);
	StopSoundMem(jumpSoundHandle);
}