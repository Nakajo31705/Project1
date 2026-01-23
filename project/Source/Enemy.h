#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <iostream>
#include <random>
#include "MonsterDataBase.h"
#include "LogManager.h"

class EnemyTurnState;
class EnemyManager;

class Enemy : public GameObject
{
public:
	Enemy(MonsterDataBase& db, LogManager* log, EnemyManager* em);
	~Enemy();
	void Update() override;
	void Draw() override;

	Monster* GetActiveMonster();
	Skill* GetSelectedSkill();
	void SkillSelect();

	void SetTurnState(EnemyTurnState* ets);

private:
	int activeMonsterIndex;					//バトル場のモンスター
	std::vector<Monster> monsters;			//控えのモンスター
	Skill* selectedSkill = nullptr;			//選択したスキル
	EnemyTurnState* turnState;
	EnemyManager* em;


	//描画用
	LogManager* logManager;					//ログ表示用
	bool startMonsterLog = false;
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 150;
};
