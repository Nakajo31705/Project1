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
	currentState(nullptr)
{
	SetPhase(TurnPhase::PLAYER_TURN);
}

void TurnManager::Update()
{
	if (currentState)
		currentState->Update();
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
		SetPhase(TurnPhase::START);
		/*死亡判定を確認
		死んでいないならStartへ
		死んでいるならゲーム終了*/
		break;
	}
}

PlayerTurnState* TurnManager::GetPlayerTurnState()
{
	return &playerTurn;
}

EnemyTurnState* TurnManager::GetEnemyTurnState()
{
	return &enemyTurn;
}
