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
	log->AddLog("プレイヤーのターン", defDrawX, defDrawY, 1000);
	subState = PlayerSubState::MenuSelect;
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
	case PlayerSubState::WaitPhase:
		if (--waitFrame <= 0)
		{
			subState = PlayerSubState::Done;
		}
		break;
	case PlayerSubState::Done:
		Exit();
		break;
	case PlayerSubState::WaitDone:
		if (--waitFrame <= 0)
		{
			tm->SetPhase(TurnPhase::ENEMY_TURN);
			myTurn = false;
		}
		break;
	}
}

/// <summary>
/// プレイヤーのターンが終了するときに呼ぶ
/// </summary>
void PlayerTurnState::Exit()
{
	//ターン終了にエネミーのターンにする
	log->AddLog("プレイヤーのターン終了", defDrawX, defDrawY, 1000);
	subState = PlayerSubState::WaitDone;
	waitFrame = 120; //2秒待機
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void PlayerTurnState::SelectEnd()
{
	waitFrame = 120; //2秒待機
	subState = PlayerSubState::WaitPhase;
}
