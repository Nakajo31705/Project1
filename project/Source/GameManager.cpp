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

	//現在のターンを確認し、アクションをリストに格納
	if (currentState == playerTurn)
	{
		actionQueue.push_back(player->SelectAction(enemy->GetActiveMonster()));
	}
	else
	{
		actionQueue.push_back(enemy->SelectAction(player->GetActiveMonster()));
	}

	//リスト内のアクションを実行
	for (auto action : actionQueue)
	{
		action->Execute();
		delete action;
	}
	actionQueue.clear();
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

void GameManager::OnNotify(int index)
{
	CardSelect(index);
}

/// <summary>
/// 選択されたカードを使用する関数
/// </summary>
/// <param name="index">選択された番号を使用</param>
void GameManager::CardSelect(int index)
{
	cardManager->UseCard(index, player->GetActiveMonster(), enemy->GetActiveMonster());
}
