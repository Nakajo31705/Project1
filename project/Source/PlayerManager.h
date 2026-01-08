#pragma once
#include "Player.h"
#include "Monster.h"
#include "Skill.h"
#include "TurnState.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "ActionRequest.h"
#include "MenuCommand.h"

class GameManager;

class PlayerManager
{
public:
	PlayerManager();
	void Update();
	void SetPlayer(Player* p) { player = p; }

	//-----行動選択関数-----//
	void SkillSelect() { return player->SkillSelect(); }
	void SwitchMonster() { return player->SwitchMonster(); }
	void CardSelect() { return player->CardSelect(); }

	//メニュー
	MenuCommand Menu();
	void SetLogManager(LogManager& logManager);

	//攻撃のリクエスト
	ActionRequest RequestAttack();
	
	//バトル場のモンスターを取得(エネミー側のターゲット取得用)
	Monster* GetActiveMonster();
private:
	//初期化
	LogManager log;
	KeyInput input;

	//ポインタで保持
	GameManager* gm;
	Player* player = nullptr;

	int selected = 0;		//メニュー選択用

	//描画位置
	int defDrawX = 100;
	int defDrawY = 100;
	int menuDrawX = 1100;
	int menuDrawY = 500;
};