#include "EnemyTurnState.h"

EnemyTurnState::EnemyTurnState(GameManager* gm, EnemyManager* em, LogManager* lm)
	:gm(gm), em(em), log(lm)
{
	cmd = em->Menu();
	subState = EnemySubState::MenuSelect;
}

void EnemyTurnState::Enter()
{
	log->AddLog("エネミーのターン", 100, 250, 1000);
	WaitTimer(1100);
	myTurn = true;
}

void EnemyTurnState::Update()
{
	//ターンの切り替え
	if (!myTurn) return;
	switch (subState)
	{
	case EnemySubState::MenuSelect:
		cmd = em->Menu();
		if (cmd == MenuCommand::SkillSelect)
		{
			subState = EnemySubState::SkillSelect;
		}
		break;
	case EnemySubState::SkillSelect:
		em->SkillSelect();
		break;
	case EnemySubState::Done:
		gm->ChangeState(gm->GetPlayerTurn());
		Exit();
		break;
	}
}

void EnemyTurnState::Exit()
{
	log->AddLog("エネミーのターン終了", 100, 200, 1000);
	WaitTimer(1100);
	myTurn = false;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void EnemyTurnState::SelectEnd()
{
	subState = EnemySubState::Done;
}
