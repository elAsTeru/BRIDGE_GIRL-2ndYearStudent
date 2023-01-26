#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_
#include "Game.h"
#include "Title.h"
#include"Gameclear.h"
#include"GameOver.h"
#include"Sound.h"
typedef enum {
    eScene_Title,    //�ݒ���
    eScene_Menu,     //���j���[���
    eScene_Game,     //�Q�[�����
    eScene_GameClear,     //�Q�[�����
    eScene_GameOver,     //�Q�[�����
} eScene;

static eScene Scene;    //�V�[���Ǘ��ϐ�
// ���� nextScene �ɃV�[����ύX����
void SceneMgr_ChangeScene(eScene nextScene);

class SceneMgr
{
public:
    SceneMgr();
    ~SceneMgr();

    //�X�V
    void SceneMgr_Update();

    //�`��
    void SceneMgr_Draw();
private:
    Game* game = new Game();
    Title* title = new Title();
    Gameclear* GameC = new Gameclear;
    GameOver* GameO = new GameOver;
    Sound* sound = new Sound;
    int loadImg;    //��ʑJ�ڎ���loading�摜�̃n���h��
    int BackScene;//�ЂƂ܂���Scene
    bool soundFlag;//�T�E���h��~�p�̃t���O
};
#endif // !_SCENEMGR_H_
