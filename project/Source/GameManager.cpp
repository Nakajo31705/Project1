#include "GameManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "TurnManager.h"
#include "Monster.h"
#include "Player.h"
#include "Enemy.h"
#include "Skill.h"
#include <string>

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

	castel = LoadGraph("data/textures/castel.png");
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
	DrawExtendGraph(0, 0, 1280, 450, castel, TRUE);
	DrawGraph(850, 150, King, TRUE);

	if (!playerManager|| !enemyManager) return;

	//バトル場のモンスターの情報を表示
	Monster* p = playerManager->GetActiveMonster();
	Monster* e = enemyManager->GetActiveMonster();

	if (!p || !e)
	{
		DrawString(defDrawX, defDrawY, "モンスター準備中", GetColor(255, 255, 255));
	}
	else
	{
		DrawFormatString(250, 100, GetColor(255, 255, 255), "%s【 HP:%d】", p->GetName().c_str(), p->GetCurrentHP());
		DrawFormatString(915, 100, GetColor(255, 255, 255), "%s 【HP:%d】", e->GetName().c_str(), e->GetCurrentHP());
	}

	log.Draw();
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
	if (turnManager->GetPhase() == TurnPhase::PLAYER_TURN)
	{
		attacker = playerManager->GetActiveMonster();
		target = enemyManager->GetActiveMonster();
	}
	else if (turnManager->GetPhase() == TurnPhase::ENEMY_TURN)
	{
		attacker = enemyManager->GetActiveMonster();
		target = playerManager->GetActiveMonster();
	}

	if (!attacker || !target) return;

	target->TakeDamage(skill.GetPower());

	//ログの表示
	if (target->IsDead())
	{
		std::string defeatLog = target->GetName() + "は倒れた！";
		log.AddLog(defeatLog, defDrawX, defDrawY, 1000);
		player->DeadMonsterSwitch();
	}
	else
	{
		target->OnDamageLog(skill.GetPower());
	}
}
