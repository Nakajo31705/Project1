#include "EnemyTurn.h"
#include "GameManager.h"

EnemyTurn::EnemyTurn(GameManager* gm)
	:gameManager(gm) {
}

/// <summary>
/// エネミーのターンが開始した時に呼ぶ
/// </summary>
void EnemyTurn::Enter()
{
	log.AddLog("エネミーのターン", 100, 200, 1000);
	myTurn = true;
}

void EnemyTurn::Update()
{
	//ターンの切り替え
	if (!myTurn) return;
	switch (subState)
	{
	case EnemySubState::MenuSelect:
		Menu();
		break;
	case EnemySubState::SkillSelect:
		enemy->SkillSelect(player->GetActiveMonster(),enemy->GetActiveMonster());
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
void EnemyTurn::Exit()
{
	DrawString(defDraw, defDraw, "エネミーのターン終了", GetColor(255, 255, 255));
	//gameManager->ChangeState(gameManager->GetPlayerTurn());
	myTurn = false;
}

/// <summary>
/// メニューの選択
/// </summary>
void EnemyTurn::Menu()
{
}

