#include "EnemyManager.h"
#include "GameManager.h"
#include "Enemy.h"
#include "ActionRequest.h"
#include <cassert>

EnemyManager::EnemyManager()
{
	SetEnemy(FindGameObject<Enemy>());
}

void EnemyManager::Update()
{
}


/// <summary>
/// メニューの選択
/// </summary>
MenuCommand EnemyManager::Menu()
{
		log.AddLog("技を選択", 100, 100, 1000);
		WaitTimer(1100);
		return MenuCommand::SkillSelect;
}

/// <summary>
/// 攻撃の情報を取得し、リクエストを作成する
/// </summary>
/// <returns></returns>
ActionRequest EnemyManager::RequestAttack()
{
	ActionRequest request;
	request.attacker = enemy->GetActiveMonster();
	request.skill = enemy->GetSelectedSkill();
	return request;
}

/// <summary>
/// バトル場のモンスターを取得
/// </summary>
/// <returns></returns>
Monster* EnemyManager::GetActiveMonster()
{
	if (!enemy) return nullptr;
	return enemy->GetActiveMonster();
}

void EnemyManager::SetTurnState(EnemyTurnState* ets)
{
	enemy->SetTurnState(ets);
}

