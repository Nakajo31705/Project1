#pragma once
#include "TurnState.h"
#include "GameManager.h"
#include "Enemy.h"

class EnemyTurn : public TurnState
{
public:
	EnemyTurn(GameManager* gm);
	void Enter() override;
	void Update() override;
	void Exit() override;

private:
	GameManager* gameManager;

	int defDraw = 100;
};
