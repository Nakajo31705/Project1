#include "GameManager.h"
#include "PlayerTurn.h"
#include "EnemyTurn.h"
#include "TurnState.h"
GameManager::GameManager()
{
	playerTurn = new PlayerTurn(this);
	enemyTurn = new EnemyTurn(this);
	ChangeState(playerTurn);
}

GameManager::~GameManager()
{
	delete playerTurn;
	delete enemyTurn;

	for (auto action : actionQueue)
		delete action;
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