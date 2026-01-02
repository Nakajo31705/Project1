#include "GameManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "Monster.h"

GameManager::GameManager()
{
	//あとで治す
	/*ChangeState(playerManager);*/
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

void GameManager::ResolveTurn()
{
	ActionRequest playerReq = playerManager->RequestAttack();
	ActionRequest enemyReq = enemyManager->RequestAttack();

	Monster& playerTarget = GetPlayerTarget();
	Monster& enemyTarget = GetEnemyTarget();

	ActionAttack(playerReq, playerTarget);
	ActionAttack(enemyReq, enemyTarget);
}

Monster& GameManager::GetPlayerTarget()
{
	return *enemyManager->GetActiveMonster();
}

Monster& GameManager::GetEnemyTarget()
{
	return *playerManager->GetActiveMonster();
}

void GameManager::ActionAttack(ActionRequest& req, Monster& target)
{
	req.attacker->Attack(target, *req.skill);
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
