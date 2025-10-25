#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <iostream>
#include "MonsterDataBase.h"


class Enemy : public GameObject
{
public:
	Enemy(MonsterDataBase& db);
	~Enemy();
	void Update() override;
	void Draw() override;

	Monster* GetActiveMonster();
	void SwichMonster();
	void SkillSelect();
private:
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> reserveMonsters;	//控えのモンスター




	//描画用
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
