#pragma once
#include "TurnState.h"
#include "GameManager.h"
#include  "EnemyManager.h"

class EnemyTurnState : public TurnState
{
public:
	EnemyTurnState(GameManager* gm, EnemyManager* em);
	void Enter() override;
	void Update() override;
	void Exit() override;

private:
	//初期化
	LogManager log;
	EnemySubState subState;

	//ポインタで保持
	GameManager* gm;
	EnemyManager* em;

	bool myTurn = false;	//自分のターンかどうか
	int playCount = 0;		//自分のターンで何回行動したかカウント
};