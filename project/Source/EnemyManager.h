#pragma once
#include "LogManager.h"
#include "ActionRequest.h"
#include "MenuCommand.h"
#include "Enemy.h"

class GameManager;
class Skill;

class EnemyManager
{
public:
	EnemyManager(GameManager* gm);
	void Update();

	void RequestAttack(Skill& skill);

	//メニュー
	MenuCommand Menu();
	void SetEnemy(Enemy* e) { enemy = e; }

	//-----行動選択関数-----//
	void SkillSelect() { return enemy->SkillSelect(); }

	//自分のターンかどうか取得
	bool GetTurn() { return myTurn; }

	//攻撃のリクエスト
	ActionRequest RequestAttack();

	//バトル場のモンスターを取得(プレイヤー側のターゲット取得用)
	Monster* GetActiveMonster();

	void SetTurnState(EnemyTurnState* ets);
private:
	//ポインタで保持
	GameManager* gm;
	Enemy* enemy;
	Monster* monster;
	LogManager log;

	bool myTurn = false;	//自分のターンかどうか
	int playCount = 0;		//自分のターンで何回行動したかカウント
	int selected;			//メニュー選択用

	//描画位置
	int defDraw = 100;		
};
