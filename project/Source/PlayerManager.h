#pragma once
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "TurnState.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "ActionRequest.h"

class GameManager;

enum class PlayerSubState
{
	MenuSelect,		//メニュー選択
	SkillSelect,	//技選択
	MonsterSelect,	//モンスター選択
	CardSelect,		//カード選択
	Done			//ターン終了
};

class PlayerManager : public TurnState
{
public:
	PlayerManager();
	void Enter() override;
	void Update() override;
	void Exit() override;
	void SelectEnd();
	void SetPlayer(Player* p) { player = p; }

	//メニュー
	void Menu();
	bool GetTurn(){return myTurn;}

	//攻撃のリクエスト
	ActionRequest RequestAttack();
	
	//バトル場のモンスターを取得(エネミー側のターゲット取得用)
	Monster* GetActiveMonster();
private:
	Player* player = nullptr;
	Monster* monsster;


	PlayerSubState subState = PlayerSubState::MenuSelect;
	int playCount = 0;
	int selected = 0;



	LogManager log;
	KeyInput input;
	int defDrawX = 100;
	int defDrawY = 100;
	int menuDrawX = 1100;
	int menuDrawY = 500;
};