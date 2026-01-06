#pragma once
#include "TurnState.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "MenuCommand.h"

enum class PlayerSubState
{
	MenuSelect,		//メニュー選択
	SkillSelect,	//技選択
	MonsterSelect,	//モンスター選択
	CardSelect,		//カード選択
	Done			//ターン終了
};

class PlayerTurnState : public TurnState
{
public:
	PlayerTurnState(GameManager* gm, PlayerManager* pm);
	void Enter() override;
	void Update() override;
	void Exit() override;

	void SelectEnd();

private:
	//初期化
	LogManager log;
	PlayerSubState subState;
	MenuCommand cmd;

	//ポインタで保持
	GameManager* gm;
	PlayerManager* pm;

	bool myTurn = false;	//自分のターンかどうか
	int playCount = 0;		//自分のターンで何回行動したかカウント
};