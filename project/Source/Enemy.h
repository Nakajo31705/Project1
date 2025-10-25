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
	Monster* activeMonster;					//�o�g����̃����X�^�[
	std::vector<Monster> reserveMonsters;	//�T���̃����X�^�[




	//�`��p
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
