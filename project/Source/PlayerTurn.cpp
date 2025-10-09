#include "PlayerTurn.h"

PlayerTurn::PlayerTurn(GameManager* gm)
	:gameManager(gm) {
}

void PlayerTurn::Enter()
{
	DrawString(100, 100, "�v���C���[�̃^�[��", GetColor(255, 255, 255));
}

void PlayerTurn::Update()
{
	switch (subState)
	{
	case PlayerSubState::MenuSelect:
		Menu();
		break;
	case PlayerSubState::SkillSelect:
		break;
	case PlayerSubState::MonsterSelect:
		break;
	case PlayerSubState::Done:
		//�s���������͂���Ȋ����ŏ���
	// gamaManager->ChangeState(new EnemyTurn(gameManager));
		break;
	}
}

void PlayerTurn::Exit()
{
	DrawString(100, 100, "�v���C���[�̃^�[���I��", GetColor(255, 255, 255));
}

void PlayerTurn::Menu()
{
	const int MENU_NUM = 2;
	const char* menu[MENU_NUM] = { "�Z��I��", "�����X�^�[������" };

	//���j���[�̕\��
	for (int i = 0; i < MENU_NUM; i++)
	{
		if (i == selected)
		{
			//���\��
			DrawString(1300, 500 + i * 30, "��", GetColor(255, 255, 0));
			DrawString(1320, 500 + i * 30, menu[i], GetColor(255, 255, 0));
		}
		else
		{
			DrawString(1320, 500 + i * 30, menu[i], GetColor(255, 255, 255));
		}
	}

	//�L�[�̓��͔���(���j���[)
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		selected--;
		if (selected < 0) selected = MENU_NUM - 1;
		WaitTimer(150);	//�L�[���s�[�g�΍�
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		selected++;
		if (selected >= MENU_NUM) selected = 0;
		WaitTimer(150);	//�L�[���s�[�g�΍�
	}

	//�R�}���h����̏���(���j���[)
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		if (selected == 0)
		{
			DrawString(100, 200, "�Z��I��", GetColor(255, 255, 255));
		}
		else if (selected == 1)
		{
			DrawString(100, 200, "�����X�^�[������", GetColor(255, 255, 255));
		}
		WaitTimer(500);
	}
}

void PlayerTurn::SkillSelect()
{
}

void PlayerTurn::MonsterSelect()
{
}