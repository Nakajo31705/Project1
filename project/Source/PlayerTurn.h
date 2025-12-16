#pragma once
#include "TurnState.h"
#include "Player.h"
#include "Enemy.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "Observer.h"

class GameManager;

enum class PlayerSubState
{
	MenuSelect,		//メニュー選択
	SkillSelect,	//技選択
	MonsterSelect,	//モンスター選択
	CardSelect,		//カード選択
	Done			//ターン終了
};


class PlayerTurn : public TurnState,public Observer
{
public:
	PlayerTurn(GameManager* gm);
	void Enter() override;
	void Update() override;
	void Exit() override;
	void SelectEnd();

	//メニュー
	void Menu();
	bool GetTurn(){return myTurn;}

private:
	GameManager* gameManager;
	Player* player;
	int selected = 0;
	PlayerSubState subState = PlayerSubState::MenuSelect;
	int playCount = 0;
	LogManager log;
	KeyInput input;

	int defDrawX = 100;
	int defDrawY = 100;
	int menuDrawX = 1100;
	int menuDrawY = 500;
};


