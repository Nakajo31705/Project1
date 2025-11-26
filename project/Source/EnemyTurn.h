#pragma once
#include "TurnState.h"
#include "GameManager.h"

enum class EnemySubState
{
	MenuSelect,
	SkillSelect,
	CardSelect,
	Done
};

class EnemyTurn : public TurnState
{
public:
	EnemyTurn(GameManager* gm);
	void Enter() override;
	void Update() override;
	void Exit() override;

	void Menu();

private:
	GameManager* gameManager;
	Player* player;
	Enemy* enemy;
	EnemySubState subState = EnemySubState::MenuSelect;

	int defDraw = 100;
};
