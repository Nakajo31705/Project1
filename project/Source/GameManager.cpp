#include "GameManager.h"
#include "PlayerTurn.h"
#include "EnemyTurn.h"
#include "TurnState.h"

GameManager::GameManager()
{
	playerTurn = new PlayerTurn(this);
	enemyTurn = new EnemyTurn(this);
	playerTurn->Enter();
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	if (currentState)
		currentState->Update();
}

void GameManager::Draw()
{
}

void GameManager::ChangeState(TurnState* newState)
{
	if (currentState)
	{
		currentState->Exit();
	}
		
	currentState = newState;

	if (currentState)
		currentState->Enter();
}
