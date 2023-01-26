#include "Game.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Camera.h"
#include "bridge.h"
#include "SceneMgr.h"
#include "HitCheck.h"


#include "EffekseerForDXLib.h"

#define LIMITTIME 60
Game::Game()
{
	rodeFlag   = TRUE;
	deleteFlag = FALSE;	
}
Game::~Game()
{
}
void Game::Update()
{
	Effekseer_Sync3DSetting();
	//呼び出しが一度目の時
	if (firstCall == false)
	{
		//カウント開始
		startCount = GetNowCount();
		//呼び出しフラフを立てる
		firstCall = true;
		//アニメーションをつける
		player->attachAnim(1);
		PlaySoundMem(startCountSound, DX_PLAYTYPE_BACK);

	}
	//時間を秒に直す
	Time = (GetNowCount() - startCount) / 1000;
	//三秒カウントがおわっていないかつカウントダウンフラグが立っていない
	if (3 - Time >= 0 && callend == false)
	{

		// 描画.
		bridge->Draw(player->GetPos());
		camera->GetPos(*player);
		player->Draw();
		//プレイヤーたちの描画に対して黒の透過画像をブレンドする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, blackback, FALSE);
		//ブレンド終わり
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		if ((3 - Time)>0)
		{
			//カウントダウン
			DrawFormatStringToHandle(590, 400, RedCode, TimeFont, "%d", 3 - Time);
		}
		else 
		{
			//カウントダウン
			DrawFormatStringToHandle(490, 400, RedCode, TimeFont, "START");
		}

		DrawGraph(0, 600, Description, true);
	}
	//ゲーム中にカウントダウンをしないための処理
	else if (3 - Time < 0 && callend != true)
	{
		//ゲームオーバーのためのカウント開始
		startCount = GetNowCount();
		//今後呼び出さないためのフラグを立てる
		callend = true;
	}
	
	// シーンがゲームかウインドウが閉じられるまでループ
	if (ProcessMessage() == 0 && (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && Scene == 0) && callend == true)
	{


		// プレイヤー行動
		player->Update();

		// 橋の処理
		bridge->Update();



		// 障害物制御.
		enemy->Update();



		HitChecker::Check(*player, *enemy);
		//クリア判定
		clear = player->GetPos();
		
		if (clear.x >= 1100)
		{
			endFlag = 1;
			player->stopSound();




			if (oneplay==false)
			{
				// エフェクトを再生する
				playingEffectHandle = PlayEffekseer3DEffect(effectResourceHandle);
				oneplay = true;
			}
			// 再生中のエフェクトを移動する。
			SetPosPlayingEffekseer3DEffect(playingEffectHandle, clear.x+5, clear.y+15, 0);
			// Effekseerにより再生中のエフェクトを更新する。
			UpdateEffekseer3D();


			
		}
		//時間制限が来たらゲームオーバー
		if (startCount + (LIMITTIME * 1000) <= GetNowCount())
		{
			endFlag = 2;
			player->stopSound();
		}
		if (fadeNum>=255)
		{
			if (endFlag==1)
			{
				SceneMgr_ChangeScene(eScene_GameClear);
			}
			if (endFlag == 2)
			{
				SceneMgr_ChangeScene(eScene_GameOver);
			}
			deleteFlag = TRUE;
		}

	}
}
void Game::Loop()
{
	if (ProcessMessage() == 0 && (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && Scene == 0) && callend == true)
	{
		// カメラ位置
		camera->GetPos(*player);
		// 橋の描画
		bridge->Draw(player->GetPos());

		
		// プレイヤー描画.
		player->Draw();

		//　敵描画
		enemy->Draw();

		// Effekseerにより再生中のエフェクトを描画する。
		DrawEffekseer3D();


		//制限時間画像の表示
		DrawRotaGraph(timerImgX, timerImgY, timerImgExtRate, timerImgAngle, timerImg, true, false);

		//DrawFormatStringToHandle(0, 0, WhiteCode, TimeFont, "TIME:");
		if (60 - Time >= 10)
		{
			//xが250なのはTIME:の部分の座標考慮
			DrawFormatStringToHandle(timerImgX + 35, timerImgY - 15, WhiteCode, CountDownFont, "%d", 60 - Time);
		}
		else
		{
			DrawFormatStringToHandle(timerImgX + 35, timerImgY - 15, RedCode, CountDownFont, "%d", 60 - Time);
		}

		//デンディング分岐のフラグとゴール時のエフェクト再生が終わっていたら
		if (endFlag!=0 && IsEffekseer3DEffectPlaying(playingEffectHandle)== -1)
		{
			fadeNum += 10;
			if (fadeNum <= 255)
			{
				//黒背景でフェードアウト
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, fadeNum);
				DrawGraph(0, 0, blackback, FALSE);
			}
		}
		
	}
}

void Game::GameInit()
{
	player->playerInit();
	fadeNum = 0;
	Time = 0;
	callend = false;
	firstCall = false;
	endFlag = 0;
	oneplay =false;
}

void Game::Rode()
{
	if (rodeFlag == TRUE)
	{
		player = new Player();
		enemy  = new EnemyManager();
		camera = new Camera();
		bridge = new Bridge();


		enemy->CreateEnemys();
		TimeFont = CreateFontToHandle("Impact", 100, 10);
		CountDownFont = CreateFontToHandle("Impact", 32, 10);
		timerImg = LoadGraph("data/img/timer.png");
		RedCode = GetColor(255, 0, 0);
		whiteback = LoadGraph("data/img/whiteback.png");
		UpkeyImg = LoadGraph("data/img/SPACEキー.png");
		WhiteCode = GetColor(255, 255, 255);
		blackback = LoadGraph("data/img/blackback.png");
		Description = LoadGraph("data/img/説明 (2).png");
		startCountSound = LoadSoundMem("data/sound/スタート時のカウントダウン音.mp3");
		Time = 0;
		startCount = 0;


		// effecseer関連
		/////////////////////////////////////////////////////////////////////////////////////////
		// Effekseerを初期化する。
		// 引数には画面に表示する最大パーティクル数を設定する。
		SetUseDirect3DVersion(DX_DIRECT3D_11);
		if (Effekseer_Init(8000) == -1)
		{
			DxLib_End();
		}
		// フルスクリーンウインドウの切り替えでリソースが消えるのを防ぐ。
		// Effekseerを使用する場合は必ず設定する。
		SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
		// エフェクトリソースを読み込む。
		// 読み込む時に大きさを指定する。
		effectResourceHandle = LoadEffekseerEffect("data/test/starGoal.efkefc", 5.0f);
		// Zバッファを有効にする。
		// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
		SetUseZBuffer3D(TRUE);

		// Zバッファへの書き込みを有効にする。
		// Effekseerを使用する場合、2DゲームでもZバッファを使用する。
		SetWriteZBuffer3D(TRUE);

		/////////////////////////////////////////////////////////////////////////////////////////

		rodeFlag = FALSE;
	}
}
void Game::Delete()
{
	if (deleteFlag == TRUE)
	{
		// エネミーの解放
		enemy->DestroyEnemys();
		// クラスの解放
		delete(player);
		delete(enemy);
		delete(camera);
		delete(bridge);
		// 画像の削除
		DeleteGraph(UpkeyImg);
		DeleteGraph(Description);
		DeleteGraph(blackback);
		DeleteGraph(whiteback);
		DeleteGraph(timerImg);
		// フォントの削除
		DeleteFontToHandle(TimeFont);
		DeleteFontToHandle(CountDownFont);
		// SE・BGMの削除
		DeleteSoundMem(startCountSound);


		DeleteEffekseerEffect(effectResourceHandle);
		// Effekseerを終了する。
		Effkseer_End();

		rodeFlag   = TRUE;
		deleteFlag = FALSE;
	}
}