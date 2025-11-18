#pragma once
#include "GameManager.h"
#include "TurnState.h"
#include "EnemyTurn.h"
#include "Player.h"

enum class PlayerSubState
{
	MenuSelect,		//メニュー選択
	SkillSelect,	//技選択
	MonsterSelect,	//モンスター選択
	CardSelect,		//カード選択
	Done			//ターン終了
};


class PlayerTurn : public TurnState
{
public:
	PlayerTurn(GameManager* gm);
	void Enter() override;
	void Update() override;
	void Exit() override;

	//メニュー
	void Menu();

	bool GetTurn(){return myTurn;}

	bool monsterChanged;

private:
	GameManager* gameManager;
	Player* player;
	int selected = 0;
	PlayerSubState subState = PlayerSubState::MenuSelect;

	int defDrawX = 100;
	int defDrawY = 100;
	int menuDrawX = 1100;
	int menuDrawY = 500;
};


