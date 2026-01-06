#include "EnemyManager.h"
#include "GameManager.h"

EnemyManager::EnemyManager()
{
	subState = EnemySubState::MenuSelect;
}

/// <summary>
/// エネミーのターンが開始した時に呼ぶ
/// </summary>
void EnemyManager::Enter()
{
	log.AddLog("エネミーのターン", 100, 200, 1000);
	selected = 0;
	myTurn = true;
}

void EnemyManager::Update()
{
	//ターンの切り替え
	if (!myTurn) return;
	switch (subState)
	{
	case EnemySubState::MenuSelect:
		Menu();
		break;
	case EnemySubState::SkillSelect:
		enemy->SkillSelect(monster, GetActiveMonster());
		break;
	case EnemySubState::CardSelect:
		enemy->CardSelect();
		break;
	case EnemySubState::Done:
		Exit();
		break;
	}
}

/// <summary>
/// エネミーのターンが終了したときに呼ぶ
/// </summary>
void EnemyManager::Exit()
{
	DrawString(defDraw, defDraw, "エネミーのターン終了", GetColor(255, 255, 255));
	//あとでgm->ChangeState(gm->GetPlayerTurn());
	myTurn = false;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void EnemyManager::SelectEnd()
{
	playCount++;

	if (playCount >= 2)
	{
		subState = EnemySubState::Done;
		playCount = 0;
	}
	else
	{
		subState = EnemySubState::MenuSelect;
		selected = 1;
		WaitTimer(1000);
	}

}

/// <summary>
/// メニューの選択
/// </summary>
void EnemyManager::Menu()
{
	if (selected == 0)
	{
		log.AddLog("カードを選択", 100, 100, 1000);
		subState = EnemySubState::CardSelect;
	}
	else if (selected == 1)
	{
		log.AddLog("技を選択", 100, 100, 1000);
		subState = EnemySubState::SkillSelect;
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

