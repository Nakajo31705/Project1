#pragma once
#include "TurnState.h"
#include "Player.h"
#include "Enemy.h"
#include "LogManager.h"

class GameManager;

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
	LogManager log;

	int defDraw = 100;
};
