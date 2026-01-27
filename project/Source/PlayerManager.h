#pragma once
#include "TurnState.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "ActionRequest.h"
#include "MenuCommand.h"

class Player;
class Monster;
class Skill;
class GameManager;
class EnemyManager;
class PlayerTurnState;
class Enemy;

class PlayerManager
{
public:
	PlayerManager(GameManager* gm);
	void Update();
	void SetPlayer(Player* p) { player = p; }

	//-----行動選択関数-----//
	void SkillSelect();
	void SwitchMonster();

	//メニュー
	MenuCommand Menu();

	//攻撃のリクエスト
	void RequestAttack(Skill& skill);
	
	//バトル場のモンスターを取得(エネミー側のターゲット取得用)
	Monster* GetActiveMonster();
	Monster& GetTarget();
private:
	//初期化
	LogManager log;
	KeyInput input;

	//ポインタで保持
	GameManager* gm;
	Player* player = nullptr;
	EnemyManager* enemyManager;

	int selected = 0;		//メニュー選択用

	//描画位置
	int defDrawX = 100;
	int defDrawY = 100;
	int menuDrawX = 1100;
	int menuDrawY = 500;
};