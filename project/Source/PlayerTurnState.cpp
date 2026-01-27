#include "PlayerTurnState.h"
#include "Player.h"
#include "TurnManager.h"

PlayerTurnState::PlayerTurnState(TurnManager* tm, PlayerManager* pm, LogManager* lm,Player* player)
	:tm(tm), pm(pm), log(lm), player(player)
{
	cmd = pm->Menu();
	subState = PlayerSubState::MenuSelect;
}

/// <summary>
/// プレイヤーのターンが開始したときに呼ぶ
/// </summary>
void PlayerTurnState::Enter()
{
	player->ResetPlayer();
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
	case PlayerSubState::Done:
		Exit();
		tm->SetPhase(TurnPhase::ENEMY_TURN);
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
	subState = PlayerSubState::MenuSelect;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void PlayerTurnState::SelectEnd()
{
	subState = PlayerSubState::Done;
}
