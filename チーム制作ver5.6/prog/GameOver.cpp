
#include"GameOver.h"



GameOver::GameOver()
{
	OverImg= LoadGraph("data/img/����.png");
    Font = CreateFontToHandle(NULL, 50, 5);
    SPACEImg = LoadGraph("data/img/SPACE�L�[.png");
    ExpansionRate = 0;
    changeCode = 0.3f;
}

GameOver::~GameOver()
{

    delete(player);
    delete(camera);
    DeleteGraph(OverImg);
    DeleteGraph(SPACEImg);
}



void GameOver::Update()
{
}


void GameOver::Draw()
{
    ExpansionRate += changeCode;
    if (ExpansionRate >= 3)
    {
        changeCode = -0.3f;
    }
    if (ExpansionRate < 0)
    {
        changeCode = 0.3f;
    }
    //�w�i�`��
    DrawGraph(0, 0,OverImg, false);
    DrawExtendGraph(30 - (int)ExpansionRate, 650 - (int)ExpansionRate, 30 + 125 + (int)ExpansionRate, 700 + (int)ExpansionRate, SPACEImg, false);
    DrawStringToHandle(30 + 125, 650, " �^�C�g����", (0, 0, 0), Font);
    //���[�V�����Ăяo��
    player->Endanim(1);
    //�v���C���[�`��
    player->Draw();
    //�J�����Ăяo��
    camera->GameEndCamera(*player);

}
//������
void GameOver::GOInit()
{
    player->playerInit();
}