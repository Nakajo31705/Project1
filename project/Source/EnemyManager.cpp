#include "EnemyManager.h"
#include "GameManager.h"
#include "Enemy.h"
#include "ActionRequest.h"
#include <cassert>

EnemyManager::EnemyManager()
{
}

void EnemyManager::Update()
{
}

/// <summary>
/// ゲームマネージャーのログマネージャーをセット
/// </summary>
void EnemyManager::SetLogManager(LogManager& logManager)
{
	assert(enemy != nullptr);
	enemy->SetLogManager(logManager);
}

/// <summary>
/// メニューの選択
/// </summary>
MenuCommand EnemyManager::Menu()
{
	if (selected == 0)
	{
		log->AddLog("カードを選択", 100, 100, 1000);
		return MenuCommand::CardSelect;
	}
	else if (selected == 1)
	{
		log->AddLog("技を選択", 100, 100, 1000);
		return MenuCommand::SkillSelect;
	}
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

