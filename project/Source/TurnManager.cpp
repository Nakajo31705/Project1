#include "TurnManager.h"
#include "TurnState.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "Player.h"
#include "Enemy.h"
#include "LogManager.h"

TurnManager::TurnManager(
	GameManager* gm,
	PlayerManager* pm,
	EnemyManager* en,
	Player* p,
	Enemy* e,
	LogManager* log)
	: playerTurn(this, pm, log, p),
	enemyTurn(this, en, log, e),
	currentState(nullptr),
	log(log)
{
	SetPhase(TurnPhase::PLAYER_TURN);
}

void TurnManager::Update()
{
	if (currentState)
		currentState->Update();

	if (phase == TurnPhase::END)
	{
		UpdateEndPhase();
	}

}

void TurnManager::UpdateEndPhase()
{
	log->AddLog("Enterキーを押して次のターンへ進む", 560, 500, 1000);

	if (input.isJustReleased(KEY_INPUT_RETURN))
	{
		SetPhase(TurnPhase::START);
	}
}

/// <summary>
/// ターンの状態を変更する関数
/// </summary>
/// <param name="newState"></param>
void TurnManager::ChangeState(TurnState* newState)
{
	if (currentState)
		currentState->Exit();

	currentState = newState;

	if (currentState)
		currentState->Enter();
}

/// <summary>
/// 状態を設定する関数
/// </summary>
/// <param name="phase"></param>
void TurnManager::SetPhase(TurnPhase nextPhase)
{
	if (phase == nextPhase) return;

	phase = nextPhase;

	switch (phase)
	{
	case TurnPhase::START:
		SetPhase(TurnPhase::PLAYER_TURN);
		break;
	case TurnPhase::PLAYER_TURN:
		ChangeState(&playerTurn);
		break;
	case TurnPhase::ENEMY_TURN:
		ChangeState(&enemyTurn);
		break;
	case TurnPhase::END:
		break;
	}
}

/// <summary>
/// 現在のターンを取得する関数
/// </summary>
/// <returns></returns>
TurnPhase TurnManager::GetPhase()
{
	return phase;
}

/// <summary>
/// プレイヤーのターンの状態をしゅとくする関数
/// </summary>
/// <returns></returns>
PlayerTurnState* TurnManager::GetPlayerTurnState()
{
	return &playerTurn;
}

/// <summary>
/// エネミーのターンの状態を取得する関数
/// </summary>
/// <returns></returns>
EnemyTurnState* TurnManager::GetEnemyTurnState()
{
	return &enemyTurn;
}
