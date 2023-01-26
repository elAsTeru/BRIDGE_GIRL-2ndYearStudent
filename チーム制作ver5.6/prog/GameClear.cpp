#include"Gameclear.h"
Gameclear::Gameclear()
{
	ClearImg = LoadGraph("data/img/����.png");
    Font = CreateFontToHandle(NULL, 50, 5);
    SPACEImg = LoadGraph("data/img/SPACE�L�[.png");
    ExpansionRate = 0;
    changeCode = 0.3f;
}

Gameclear::~Gameclear()
{
    delete(player);
    delete(camera);
    DeleteGraph(ClearImg);
    DeleteGraph(SPACEImg);
}

void Gameclear::Draw()
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
    DrawGraph(0, 0, ClearImg, false);
    DrawExtendGraph(30 - (int)ExpansionRate, 650 - (int)ExpansionRate, 30 + 125 + (int)ExpansionRate, 700 + (int)ExpansionRate, SPACEImg, false);
    DrawStringToHandle(30 + 125, 650, " �^�C�g����", (0, 0, 0), Font);
    //�A�j���[�V�����Ăяo��
    player->Endanim(0);
    //�v���C���[�`��
    player->Draw();
    //�J�����Ăяo��
    camera->GameEndCamera(*player);

}

void Gameclear::Update()
{
}
//������
void Gameclear::GCInit()
{
    player->playerInit();

}

