#pragma once
#include "GameManager.h"
#include "TurnState.h"
#include "Player.h"

enum class PlayerSubState
{
	MenuSelect,		//���j���[�I��
	SkillSelect,	//�Z�I��
	MonsterSelect,	//�����X�^�[�I��
	Done			//�^�[���I��
};


class PlayerTurn : public TurnState
{
public:
	PlayerTurn(GameManager* gm);
	void Enter() override;
	void Update() override;
	void Exit() override;

	//���j���[
	void Menu();
	void SkillSelect();
	void MonsterSelect();

private:
	GameManager* gameManager;
	int selected = 0;
	PlayerSubState subState = PlayerSubState::MenuSelect;

	int defDraw = 100;
	int menuDrawX = 1300;
	int menuDrawY = 500;
};


