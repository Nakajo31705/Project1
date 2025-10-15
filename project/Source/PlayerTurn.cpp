#include "PlayerTurn.h"

PlayerTurn::PlayerTurn(GameManager* gm)
	:gameManager(gm)
{
	
}

void PlayerTurn::Enter()
{
	DrawString(defDraw, defDraw, "�v���C���[�̃^�[��", GetColor(255, 255, 255));
}

void PlayerTurn::Update()
{
	switch (subState)
	{
	case PlayerSubState::MenuSelect:
		Menu();
		break;
	case PlayerSubState::SkillSelect:
		player->SkillSelect();
		break;
	case PlayerSubState::MonsterSelect:
		player->SwitchMonster();
		break;
	case PlayerSubState::Done:
		gameManager->ChangeState(new EnemyTurn(gameManager));
		break;
	}
}

void PlayerTurn::Exit()
{
	DrawString(defDraw, defDraw, "�v���C���[�̃^�[���I��", GetColor(255, 255, 255));
}

void PlayerTurn::Menu()
{
	const int MENU_NUM = 2;
	const char* menu[MENU_NUM] = { "�Z��I��", "�����X�^�[������" };
	int yOffset = 30;

	//���j���[�̕\��
	for (int i = 0; i < MENU_NUM; i++)
	{
		if (i == selected)
		{
			//���\��
			DrawString(menuDrawX, menuDrawY + i * yOffset, "��", GetColor(255, 255, 0));
			DrawString(menuDrawX+20, menuDrawY + i * yOffset, menu[i], GetColor(255, 255, 0));
		}
		else
		{
			DrawString(menuDrawX+20, menuDrawY + i * yOffset, menu[i], GetColor(255, 255, 255));
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
			DrawString(defDraw, defDraw*2, "�Z��I��", GetColor(255, 255, 255));
			subState = PlayerSubState::SkillSelect;
			
		}
		else if (selected == 1)
		{
			DrawString(defDraw, defDraw*2, "�����X�^�[������", GetColor(255, 255, 255));
			subState = PlayerSubState::MonsterSelect;
		}
		WaitTimer(500);
	}
}