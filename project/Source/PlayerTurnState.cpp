#include "PlayerTurnState.h"

PlayerTurnState::PlayerTurnState(GameManager* gm, PlayerManager* pm, LogManager* lm)
	:gm(gm), pm(pm), log(lm)
{
	cmd = pm->Menu();
	subState = PlayerSubState::MenuSelect;
}

/// <summary>
/// プレイヤーのターンが開始したときに呼ぶ
/// </summary>
void PlayerTurnState::Enter()
{
	myTurn = true;
	log->AddLog("プレイヤーのターン", 100, 200, 1000);
}

void PlayerTurnState::Update()
{
	//ターンの切り替え
	if (!myTurn) return;
	switch (subState)
	{
	case PlayerSubState::MenuSelect:
		cmd = pm->Menu();
		if (cmd == MenuCommand::SkillSelect)
		{
			subState = PlayerSubState::SkillSelect;
		}
		else if (cmd == MenuCommand::MonsterSwitch)
		{
			subState = PlayerSubState::MonsterSelect;
		}
		else if (cmd == MenuCommand::CardSelect)
		{
			subState = PlayerSubState::CardSelect;
		}
		break;
	case PlayerSubState::SkillSelect:
		pm->SkillSelect();
		break;
	case PlayerSubState::MonsterSelect:
		pm->SwitchMonster();
		break;
	case PlayerSubState::CardSelect:
		pm->CardSelect();
		break;
	case PlayerSubState::Done:
		gm->ChangeState(gm->GetEnemyTurn());
		Exit();
		break;
	}
}

/// <summary>
/// プレイヤーのターンが終了するときに呼ぶ
/// </summary>
void PlayerTurnState::Exit()
{
	//ターン終了にエネミーのターンにする
	log->AddLog("プレイヤーのターン終了", 100, 200, 1000);
	myTurn = false;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void PlayerTurnState::SelectEnd()
{
	subState = PlayerSubState::Done;
}
