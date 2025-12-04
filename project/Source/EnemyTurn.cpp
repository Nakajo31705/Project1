#include "EnemyTurn.h"
#include "PlayerTurn.h"
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
	selected = 0;
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
	gameManager->ChangeState(gameManager->GetPlayerTurn());
	myTurn = false;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void EnemyTurn::SelectEnd()
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
void EnemyTurn::Menu()
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

