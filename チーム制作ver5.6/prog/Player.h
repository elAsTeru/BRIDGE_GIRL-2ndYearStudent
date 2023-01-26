#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "DxLib.h"

class EnemyBase;

class Player final
{
public:
	Player();				// �R���X�g���N�^.
	~Player();				// �f�X�g���N�^.

	void Draw();					// �`��.
	void Update();

	// �Փˏ���.
	void OnHitObstruct(EnemyBase& obstruct);

	// ���f���n���h���̎擾.
	int GetModelHandle() { return modelHandle; }

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }	
	void SetPos(const VECTOR set) { pos = set; }	

	void jump();									//�W�����v���Ă鎞�d�͂�������A���n����ƃt���O�֌W�̃��Z�b�g	

	void PlayAnim();								//anime�Đ��p�̊֐�
	void attachAnim(int animPlay);					//�A�j���[�V�����̃A�^�b�`
	void titleanim();
	void Endanim(int gameState);
	void stopSound();

	void playerInit();								//�v���C���[�̏�Ԃ�������

	float GetHitRadius() { return hitRadius; }		// �����蔻�蔼�a�̎擾.


private:
	float	hitRadius;				// �����蔻��̔��a.
	int		modelHandle;			// ���f���n���h��.
	VECTOR	pos;					// �|�W�V����.
	bool	jumpFlag;				//�W�����v�̃t���O 
	float	animTotal;				//�A�j���[�V�����̑��Đ�����
	float	animNowTime;			//�A�j���[�V�����̌��݂̍Đ�����
	int		animIndex;				//�A�j���[�V�����̃C���f�b�N�X
	bool	stateRun;				//�����Ă����Ԃ��ۂ��̃t���O
	VECTOR  mVelocity;				//�����x
	bool	playerDebugFlag ;		//�f�o�b�O����\������Ƃ��̃t���O
	bool Titleflag = false;//�^�C�g�����̃A�j���؂�ւ��悤�̃t���O
	bool damegeFlag = false;//�_���[�W���󂯂����̃t���O
	int jumpSoundHandle;
	int runSound;
};
#endif // !_PLAYER_H_