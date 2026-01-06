#pragma once
#include "Enemy.h"
#include "LogManager.h"
#include "TurnState.h"
#include "ActionRequest.h"

class GameManager;

enum class EnemySubState
{
	MenuSelect,
	SkillSelect,
	CardSelect,
	Done
};

class EnemyManager : public TurnState
{
public:
	EnemyManager();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void SelectEnd();

	void Menu();
	bool GetTurn() { return myTurn; }

	//攻撃のリクエスト
	ActionRequest RequestAttack();
	//バトル場のモンスターを取得(プレイヤー側のターゲット取得用)
	Monster* GetActiveMonster();

private:
	//初期化
	LogManager log;

	GameManager* gm;
	Enemy* enemy;
	Monster* monster;

	EnemySubState subState = EnemySubState::MenuSelect;


	bool myTurn = false;
	int playCount = 0;
	int selected;
	int defDraw = 100;
};
