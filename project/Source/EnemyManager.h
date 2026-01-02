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

	//攻撃のリクエスト
	ActionRequest RequestAttack();
	//バトル場のモンスターを取得(プレイヤー側のターゲット取得用)
	Monster* GetActiveMonster();

private:
	Enemy* enemy;
	Monster* monsster;

	EnemySubState subState = EnemySubState::MenuSelect;


	int playCount = 0;
	int selected;
	LogManager log;
	int defDraw = 100;
};
