#include "GameManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "TurnManager.h"
#include "Monster.h"
#include "Player.h"
#include "Enemy.h"
#include "Skill.h"

GameManager::GameManager()
{
	playerManager = new PlayerManager(this);
	enemyManager = new EnemyManager(this);
	player = new Player(MDB, &log, playerManager);
	enemy = new Enemy(MDB, &log, enemyManager);
	turnManager = new TurnManager(
		this,
		playerManager,
		enemyManager,
		player,
		enemy,
		&log
	);
	playerManager->SetPlayer(player);
	enemyManager->SetEnemy(enemy);
	player->SetTurnState(turnManager->GetPlayerTurnState());
	enemy->SetTurnState(turnManager->GetEnemyTurnState());

	King = LoadGraph("data/textures/King.png");
}

GameManager::~GameManager()
{
	delete playerManager;
	delete enemyManager;
	delete player;
	delete enemy;
	delete turnManager;
}

void GameManager::Update()
{
	log.Update();
	if (turnManager)
		turnManager->Update();
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
/// モンスターに対して攻撃アクションを実行
/// </summary>
void GameManager::ActionAttack(Skill& skill)
{
	Monster* attacker = playerManager->GetActiveMonster();
	Monster* target = enemyManager->GetActiveMonster();

	if (!attacker || !target) return;

	target->TakeDamage(skill.GetPower());
}
