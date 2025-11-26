#pragma once
#include "../Library/GameObject.h"
#include "Player.h"
#include "Enemy.h"

class PlayerTurn;
class EnemyTurn;
class TurnState;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	void ChangeState(TurnState* newState);
	EnemyTurn* GetEnemyTurn() const { return enemyTurn; }
	PlayerTurn* GetPlayerTurn() const { return playerTurn; }
private:
	EnemyTurn* enemyTurn = nullptr;
	PlayerTurn* playerTurn = nullptr;
	TurnState* currentState = nullptr;
};
