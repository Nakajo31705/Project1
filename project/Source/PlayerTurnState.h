#pragma once
#include "TurnState.h"
#include "PlayerManager.h"
#include "MenuCommand.h"
#include "ActionRequest.h"

class Player;
class TurnManager;
class Monster;

enum class PlayerSubState
{
	MenuSelect,		//メニュー選択
	SkillSelect,	//技選択
	MonsterSelect,	//モンスター選択
	CardSelect,		//カード選択
	Done,			//ターン終了
	WaitDone,
	WaitPhase
};

class PlayerTurnState : public TurnState
{
public:
	PlayerTurnState(TurnManager* tm, PlayerManager* pm, LogManager* lm,Player* player);
	void Enter() override;
	void Update() override;
	void Exit() override;

	void SelectEnd();

private:
	//初期化
	LogManager* log;
	PlayerSubState subState;
	MenuCommand cmd;
	ActionRequest req;

	//ポインタで保持
	Player* player;
	TurnManager* tm;
	PlayerManager* pm;
	Monster* monster;

	bool myTurn = false;	//自分のターンかどうか
	int waitFrame = 0;		//選択後の待機フレーム
	int defDrawX = 300;
	int defDrawY = 600;
};