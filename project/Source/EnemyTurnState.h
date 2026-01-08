#pragma once
#include "TurnState.h"
#include "GameManager.h"
#include "EnemyManager.h"
#include "MenuCommand.h"

enum class EnemySubState
{
	MenuSelect,
	SkillSelect,
	CardSelect,
	Done
};

class EnemyTurnState : public TurnState
{
public:
	EnemyTurnState(GameManager* gm, EnemyManager* em);
	void Enter() override;
	void Update() override;
	void Exit() override;
	void SetLogManager();

	void SelectEnd();

private:
	//初期化
	EnemySubState subState;
	MenuCommand cmd;

	//ポインタで保持
	GameManager* gm;
	EnemyManager* em;
	LogManager* log;

	bool myTurn = false;	//自分のターンかどうか
	int playCount = 0;		//自分のターンで何回行動したかカウント
};