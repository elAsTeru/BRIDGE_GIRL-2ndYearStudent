#include"Sound.h"
Sound::Sound()
{
	NeutralBGM = LoadSoundMem("data/sound/ネオロック73.mp3");
	GameClearBGM = LoadSoundMem("data/sound/clear.mp3");
	GameOverBGM = LoadSoundMem("data/sound/gameover.mp3");
	pressSpace=LoadSoundMem("data/sound/魔王魂 効果音 システム37.mp3");
	TitleBGM=LoadSoundMem("data/sound/魔王魂  8bit01.mp3");

	ChangeVolumeSoundMem(255 * 80 / 100, NeutralBGM);
	ChangeVolumeSoundMem(255 * 80 / 100, GameClearBGM);
	ChangeVolumeSoundMem(255 * 80 / 100, GameOverBGM);

}

Sound::~Sound()
{
	InitSoundMem();
	DeleteSoundMem(NeutralBGM);
	DeleteSoundMem(GameClearBGM);
	DeleteSoundMem(GameOverBGM);
	DeleteSoundMem(pressSpace);
	DeleteSoundMem(TitleBGM);

}

void Sound::soundPlay(int playNumber)
{
	//今流れているBGMを止める
	StopSoundMem(NowBGM);
	//Sceneによって流れるBGMが変わる
	if (playNumber == eScene_Title)
	{
		PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP);
		NowBGM = TitleBGM;
	}
	if (playNumber == eScene_Game)
	{
		PlaySoundMem(NeutralBGM, DX_PLAYTYPE_LOOP);
		NowBGM = NeutralBGM;
	}
	if (playNumber == eScene_GameClear)
	{
		PlaySoundMem(GameClearBGM, DX_PLAYTYPE_BACK);
		NowBGM = GameClearBGM;
	}
	if (playNumber == eScene_GameOver)
	{
		PlaySoundMem(GameOverBGM, DX_PLAYTYPE_BACK);
		NowBGM = GameOverBGM;
	}
	if (playNumber== eScene_Menu)
	{
		PlaySoundMem(pressSpace, DX_PLAYTYPE_BACK);
	}
}
