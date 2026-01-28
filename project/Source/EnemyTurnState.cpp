#include "EnemyTurnState.h"
#include "TurnManager.h"
#include "Enemy.h"


EnemyTurnState::EnemyTurnState(TurnManager* tm, EnemyManager* em, LogManager* lm, Enemy* enemy)
	:tm(tm), em(em), log(lm), enemy(enemy)
{
	cmd = em->Menu();
	subState = EnemySubState::MenuSelect;
}

void EnemyTurnState::Enter()
{
	enemy->ResetEnemy();
	log->AddLog("エネミーのターン", defDrawX, defDrawY, 1000);
	subState = EnemySubState::MenuSelect;
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
	case EnemySubState::WaitSkill:
		if (--waitFrame <= 0)
		{
			subState = EnemySubState::Done;
		}
		break;
	case EnemySubState::Done:
		Exit();
		break;
	case EnemySubState::WaitDone:
		if (--waitFrame <= 0)
		{
			tm->SetPhase(TurnPhase::END);
			myTurn = false;
		}
		break;
	}
}

void EnemyTurnState::Exit()
{
	log->AddLog("エネミーのターン終了", defDrawX, defDrawY, 1000);
	waitFrame = 120; //2秒待機
	subState = EnemySubState::WaitDone;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void EnemyTurnState::SelectEnd()
{
	waitFrame = 120; //2秒待機
	subState = EnemySubState::WaitSkill;
}
