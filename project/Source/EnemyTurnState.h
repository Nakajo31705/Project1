#pragma once
#include "TurnState.h"
#include "EnemyManager.h"
#include "MenuCommand.h"
#include "LogManager.h"

class TurnManager;
class Enemy;

enum class EnemySubState
{
	MenuSelect,
	SkillSelect,
	WaitSkill,
	WaitDone,
	Done
};

class EnemyTurnState : public TurnState
{
public:
	EnemyTurnState(TurnManager* tm, EnemyManager* em,LogManager* lm, Enemy* enemy);
	void Enter() override;
	void Update() override;
	void Exit() override;

	void SelectEnd();

private:
	//初期化
	EnemySubState subState;
	MenuCommand cmd;

	//ポインタで保持
	TurnManager* tm;
	EnemyManager* em;
	LogManager* log;
	Enemy* enemy;

	bool myTurn = false;	//自分のターンかどうか
	int waitFrame = 0;		//技選択後の待機フレーム
	int defDrawX = 300;
	int defDrawY = 650;
};