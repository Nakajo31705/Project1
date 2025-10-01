#pragma once
#include <vector>
#include "Monster.h"
#include "Skill.h"

class Enemy
{
public:
	Enemy(const Monster& _monster, const std::vector<Skill>& _skills);
	void Update();
	void Draw();
private:
	Monster enemyMonster;
	std::vector<Skill> enemySkills;
};
