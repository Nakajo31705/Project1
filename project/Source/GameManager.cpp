#include "GameManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "Monster.h"
#include "PlayerTurnState.h"
#include "Player.h"
#include "EnemyTurnState.h"
#include "Enemy.h"
#include "Player.h"

GameManager::GameManager()
{
	playerManager = new PlayerManager();
	enemyManager = new EnemyManager();
	playerManager->SetPlayer(FindGameObject<Player>());
	enemyManager->SetEnemy(FindGameObject<Enemy>());
	playerTurn = new PlayerTurnState(this,playerManager);
	enemyTurn = new EnemyTurnState(this, enemyManager);
	playerManager->SetTurnState(playerTurn);

	//ログ表示用
	playerManager->SetLogManager(log);
	enemyManager->SetLogManager(log);

	//プレイヤーのターンから開始
	currentState = nullptr;
	ChangeState(playerTurn);

	King = LoadGraph("data/textures/King.png");
}

GameManager::~GameManager()
{
	delete playerManager;
	delete enemyManager;
	delete playerTurn;
	delete enemyTurn;
}

void GameManager::Update()
{
	log.Update();

	if (currentState)
		currentState->Update();
}

void GameManager::Draw()
{
	if (!playerManager|| !enemyManager) return;

	//バトル場のモンスターの情報を表示
	Monster* p = playerManager->GetActiveMonster();
	Monster* e = enemyManager->GetActiveMonster();

	if (!p || !e)
	{
		DrawString(100, 500, "モンスター準備中", GetColor(255, 255, 255));
	}
	else
	{
		DrawFormatString(100, 500, GetColor(255, 255, 255), "%s【 HP:%d】", p->GetName().c_str(), p->GetCurrentHP());
		DrawFormatString(910, 180, GetColor(255, 255, 255), "%s 【HP:%d】", e->GetName().c_str(), e->GetCurrentHP());
	}

	log.Draw();

	DrawGraph(850, 200, King, TRUE);

}

LogManager& GameManager::GetLogManager()
{
	return log;
}


/// <summary>
/// プレイヤーのターゲットとなるモンスターを取得
/// </summary>
/// <returns>ターゲットを返す</returns>
Monster& GameManager::GetPlayerTarget()
{
	return *enemyManager->GetActiveMonster();
}

/// <summary>
/// エネミーのターゲットとなるモンスターを取得
/// </summary>
/// <returns>ターゲットを返す</returns>
Monster& GameManager::GetEnemyTarget()
{
	return *playerManager->GetActiveMonster();
}

/// <summary>
/// モンスターに対して攻撃アクションを実行
/// </summary>
/// <param name="req">行動のリクエスト</param>
/// <param name="target">攻撃対象のモンスター</param>
void GameManager::ActionAttack(ActionRequest& req, Monster& target)
{
	req.attacker->Attack(*req.target, *req.skill);
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

TurnState* GameManager::GetPlayerTurn()
{
	return playerTurn;
}

TurnState* GameManager::GetEnemyTurn()
{
	return enemyTurn;
}
