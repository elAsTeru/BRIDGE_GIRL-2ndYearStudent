#include "DxLib.h"
#include "SceneMgr.h"
#define LIMITTIME 60


SceneMgr::SceneMgr()
{
    loadImg = LoadGraph("data/img/LOADING.png");
    soundFlag = false;
    
}
SceneMgr::~SceneMgr()
{
    delete(game);
    delete(GameC);
    delete(title);
    DeleteGraph(loadImg);
}

//�X�V
void SceneMgr::SceneMgr_Update() {

    //�O��Scene��ۑ�
    BackScene = Scene;
    if (soundFlag == false)
    {
        //����炵�ăt���O�𗧂Ă�
        sound->soundPlay(Scene);
        soundFlag = true;
    }
    //�V�[���ɂ���ď����𕪊�
    //���݂̉�ʂ����j���[�Ȃ�
    //���j���[��ʂ̍X�V����������
    //�ȉ���
    switch (Scene) {       
    case eScene_Title:     
        title->Rode();
        title->Update();
        title->Delete();
        break; 

    case eScene_Game:
        game->Rode();
        game->Update();
        game->Delete();
        break;


    case eScene_GameClear:
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            //�������Ɖ�ʑJ��
            SceneMgr_ChangeScene(eScene_Title);
            game->GameInit();
            GameC->GCInit();
        }
        break;


    case eScene_GameOver:
        if (CheckHitKey(KEY_INPUT_SPACE) )
        {
            //�������Ɖ�ʑJ��
            SceneMgr_ChangeScene(eScene_Title);
            game->GameInit();
            GameO->GOInit();
        }
        break;
    }


    //���͂��~�߂邽�߂�0.5�b���Ԃ�����
    if (BackScene!=Scene&&BackScene!= eScene_Game)
    {
        DrawGraph(0, 0, loadImg, false);
        ScreenFlip();
        sound->soundPlay(eScene_Menu);
        WaitTimer(500);
    }
    //�O��Scene�ŗ���Ă������y���~�߂邽�߂̃t���O
    if (BackScene != Scene)
    {
        soundFlag = false;
    }
}

//�`��
void SceneMgr::SceneMgr_Draw() {
    switch (Scene) {  
    case eScene_Title:
        title->Rode();
        title->Draw();
        title->Delete();
        break;        
    case eScene_Game:
        game->Rode();
        game->Loop();
        game->Delete();
        break;
    case eScene_GameClear:
        GameC->Draw();
        break;
    
    case eScene_GameOver:
        GameO->Draw();
        break;
    }
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene NextScene) {
    Scene = NextScene;
}