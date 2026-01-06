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

	//メニュー
	void Menu();

	//自分のターンかどうか取得
	bool GetTurn() { return myTurn; }

	//攻撃のリクエスト
	ActionRequest RequestAttack();

	//バトル場のモンスターを取得(プレイヤー側のターゲット取得用)
	Monster* GetActiveMonster();

private:
	//初期化
	LogManager log;
	EnemySubState subState;

	//ポインタで保持
	GameManager* gm;
	Enemy* enemy;
	Monster* monster;

	bool myTurn = false;	//自分のターンかどうか
	int playCount = 0;		//自分のターンで何回行動したかカウント
	int selected;			//メニュー選択用

	//描画位置
	int defDraw = 100;		
};
