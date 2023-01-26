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
	//�Ăяo������x�ڂ̎�
	if (firstCall == false)
	{
		//�J�E���g�J�n
		startCount = GetNowCount();
		//�Ăяo���t���t�𗧂Ă�
		firstCall = true;
		//�A�j���[�V����������
		player->attachAnim(1);
		PlaySoundMem(startCountSound, DX_PLAYTYPE_BACK);

	}
	//���Ԃ�b�ɒ���
	Time = (GetNowCount() - startCount) / 1000;
	//�O�b�J�E���g��������Ă��Ȃ����J�E���g�_�E���t���O�������Ă��Ȃ�
	if (3 - Time >= 0 && callend == false)
	{

		// �`��.
		bridge->Draw(player->GetPos());
		camera->GetPos(*player);
		player->Draw();
		//�v���C���[�����̕`��ɑ΂��č��̓��߉摜���u�����h����
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, blackback, FALSE);
		//�u�����h�I���
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

		if ((3 - Time)>0)
		{
			//�J�E���g�_�E��
			DrawFormatStringToHandle(590, 400, RedCode, TimeFont, "%d", 3 - Time);
		}
		else 
		{
			//�J�E���g�_�E��
			DrawFormatStringToHandle(490, 400, RedCode, TimeFont, "START");
		}

		DrawGraph(0, 600, Description, true);
	}
	//�Q�[�����ɃJ�E���g�_�E�������Ȃ����߂̏���
	else if (3 - Time < 0 && callend != true)
	{
		//�Q�[���I�[�o�[�̂��߂̃J�E���g�J�n
		startCount = GetNowCount();
		//����Ăяo���Ȃ����߂̃t���O�𗧂Ă�
		callend = true;
	}
	
	// �V�[�����Q�[�����E�C���h�E��������܂Ń��[�v
	if (ProcessMessage() == 0 && (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && Scene == 0) && callend == true)
	{


		// �v���C���[�s��
		player->Update();

		// ���̏���
		bridge->Update();



		// ��Q������.
		enemy->Update();



		HitChecker::Check(*player, *enemy);
		//�N���A����
		clear = player->GetPos();
		
		if (clear.x >= 1100)
		{
			endFlag = 1;
			player->stopSound();




			if (oneplay==false)
			{
				// �G�t�F�N�g���Đ�����
				playingEffectHandle = PlayEffekseer3DEffect(effectResourceHandle);
				oneplay = true;
			}
			// �Đ����̃G�t�F�N�g���ړ�����B
			SetPosPlayingEffekseer3DEffect(playingEffectHandle, clear.x+5, clear.y+15, 0);
			// Effekseer�ɂ��Đ����̃G�t�F�N�g���X�V����B
			UpdateEffekseer3D();


			
		}
		//���Ԑ�����������Q�[���I�[�o�[
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
		// �J�����ʒu
		camera->GetPos(*player);
		// ���̕`��
		bridge->Draw(player->GetPos());

		
		// �v���C���[�`��.
		player->Draw();

		//�@�G�`��
		enemy->Draw();

		// Effekseer�ɂ��Đ����̃G�t�F�N�g��`�悷��B
		DrawEffekseer3D();


		//�������ԉ摜�̕\��
		DrawRotaGraph(timerImgX, timerImgY, timerImgExtRate, timerImgAngle, timerImg, true, false);

		//DrawFormatStringToHandle(0, 0, WhiteCode, TimeFont, "TIME:");
		if (60 - Time >= 10)
		{
			//x��250�Ȃ̂�TIME:�̕����̍��W�l��
			DrawFormatStringToHandle(timerImgX + 35, timerImgY - 15, WhiteCode, CountDownFont, "%d", 60 - Time);
		}
		else
		{
			DrawFormatStringToHandle(timerImgX + 35, timerImgY - 15, RedCode, CountDownFont, "%d", 60 - Time);
		}

		//�f���f�B���O����̃t���O�ƃS�[�����̃G�t�F�N�g�Đ����I����Ă�����
		if (endFlag!=0 && IsEffekseer3DEffectPlaying(playingEffectHandle)== -1)
		{
			fadeNum += 10;
			if (fadeNum <= 255)
			{
				//���w�i�Ńt�F�[�h�A�E�g
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
		UpkeyImg = LoadGraph("data/img/SPACE�L�[.png");
		WhiteCode = GetColor(255, 255, 255);
		blackback = LoadGraph("data/img/blackback.png");
		Description = LoadGraph("data/img/���� (2).png");
		startCountSound = LoadSoundMem("data/sound/�X�^�[�g���̃J�E���g�_�E����.mp3");
		Time = 0;
		startCount = 0;


		// effecseer�֘A
		/////////////////////////////////////////////////////////////////////////////////////////
		// Effekseer������������B
		// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
		SetUseDirect3DVersion(DX_DIRECT3D_11);
		if (Effekseer_Init(8000) == -1)
		{
			DxLib_End();
		}
		// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
		// Effekseer���g�p����ꍇ�͕K���ݒ肷��B
		SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
		// �G�t�F�N�g���\�[�X��ǂݍ��ށB
		// �ǂݍ��ގ��ɑ傫�����w�肷��B
		effectResourceHandle = LoadEffekseerEffect("data/test/starGoal.efkefc", 5.0f);
		// Z�o�b�t�@��L���ɂ���B
		// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
		SetUseZBuffer3D(TRUE);

		// Z�o�b�t�@�ւ̏������݂�L���ɂ���B
		// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
		SetWriteZBuffer3D(TRUE);

		/////////////////////////////////////////////////////////////////////////////////////////

		rodeFlag = FALSE;
	}
}
void Game::Delete()
{
	if (deleteFlag == TRUE)
	{
		// �G�l�~�[�̉��
		enemy->DestroyEnemys();
		// �N���X�̉��
		delete(player);
		delete(enemy);
		delete(camera);
		delete(bridge);
		// �摜�̍폜
		DeleteGraph(UpkeyImg);
		DeleteGraph(Description);
		DeleteGraph(blackback);
		DeleteGraph(whiteback);
		DeleteGraph(timerImg);
		// �t�H���g�̍폜
		DeleteFontToHandle(TimeFont);
		DeleteFontToHandle(CountDownFont);
		// SE�EBGM�̍폜
		DeleteSoundMem(startCountSound);


		DeleteEffekseerEffect(effectResourceHandle);
		// Effekseer���I������B
		Effkseer_End();

		rodeFlag   = TRUE;
		deleteFlag = FALSE;
	}
}