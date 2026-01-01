#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <iostream>
#include <random>
#include "MonsterDataBase.h"
#include "TypeEffective.h"
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

	int GetActiveMonster();
	void SkillSelect(Monster* player, Monster* enemy);
	void CardSelect();

private:
	int activeMonsterIndex;					//バトル場のモンスター
	std::vector<Monster> monsters;			//控えのモンスター


	//描画用
	LogManager logManager;					//ログ表示用
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 150;
};
