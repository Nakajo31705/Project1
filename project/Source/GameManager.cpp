#include "GameManager.h"
#include "PlayerTurn.h"
#include "EnemyTurn.h"

GameManager::GameManager()
{
	playerTurn = std::make_unique<PlayerTurn>(this);
	enemyTurn = std::make_unique<EnemyTurn>(this);
	ChangeState(playerTurn.get());
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

/// <summary>
/// ターンをチェンジする関数
/// </summary>
/// <param name="newState">変更したいステートを入力</param>
void GameManager::ChangeState(TurnState* newState)
{
	if (currentState)
	{
		currentState->Exit();
		turnEnd = true;
	}
		
	currentState = newState;

	if (currentState)
	{
		currentState->Enter();
		turnEnd = false;
	}	
}
