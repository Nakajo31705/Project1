#pragma once
#include "PlayerTurnState.h"
#include "EnemyTurnState.h"
#include "KeyInput.h"

class TurnState;
class GameManager;
class PlayerManager;
class EnemyManager;
class Player;
class Enemy;
class LogManager;

enum class TurnPhase
{
	START,
	PLAYER_TURN,
	ENEMY_TURN,
	END
};

class TurnManager
{
public:
	TurnManager(
		GameManager* gm,
		PlayerManager* pm,
		EnemyManager* en,
		Player* p,
		Enemy* e,
		LogManager* log
	);
	void Update();
	void UpdateEndPhase();
	void ChangeState(TurnState* newState);
	void SetPhase(TurnPhase nextPhase);
	TurnPhase GetPhase();

	PlayerTurnState* GetPlayerTurnState();
	EnemyTurnState* GetEnemyTurnState();	

private:
	TurnState* currentState = nullptr;
	TurnPhase phase = TurnPhase::START;

	PlayerTurnState playerTurn;
	EnemyTurnState enemyTurn;
	KeyInput input;
	LogManager* log;
};


