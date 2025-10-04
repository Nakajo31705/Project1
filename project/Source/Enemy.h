#pragma once
#include <vector>
#include "Monster.h"
#include "Skill.h"

class Enemy
{
public:
	Enemy(const std::vector<Monster>& _monster);
	void Update();
	void Draw();
private:
	std::vector<Monster> enemyMonster;
	std::vector<Skill> enemySkills;
};
