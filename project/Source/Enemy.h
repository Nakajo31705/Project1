#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <iostream>
#include <random>
#include "MonsterDataBase.h"
#include "LogManager.h"
#include "ActionAttack.h"

class Player;

class Enemy : public GameObject
{
public:
	Enemy(MonsterDataBase& db);
	~Enemy();
	void Update() override;
	void Draw() override;

	Monster* GetActiveMonster();
	Skill* GetSelectedSkill();
	void SkillSelect(Monster* player, Monster* enemy);
	void CardSelect();

private:
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> monsters;			//控えのモンスター
	Skill* selectedSkill = nullptr;			//選択したスキル


	//描画用
	LogManager logManager;					//ログ表示用
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 150;
};
