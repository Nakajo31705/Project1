#pragma once
#include "../Library/GameObject.h"
#include "TurnState.h"
#include "Player.h"
#include "Enemy.h"

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	void ChangeState(TurnState* newState);
	void ChangeTurn();
private:
	TurnState* currentState = nullptr;
	TurnState* playerTurn;
	TurnState* enemyTurn;
};
