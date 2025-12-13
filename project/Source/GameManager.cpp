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

/// <summary>
/// 選択されたカードを使用する関数
/// </summary>
/// <param name="index">選択された番号を使用</param>
void GameManager::CardSelect(int index)
{
	cardManager->UseCard(index, player->GetActiveMonster(), enemy->GetActiveMonster());
}
