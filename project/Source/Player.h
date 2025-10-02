#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "Monster.h"
#include "Skill.h"


class Player : GameObject
{
public:
	Player(const std::vector<Monster>& _monster, const std::vector<Skill>& _skills);
	~Player();
	void Update();
	void Draw();

	void IsDead();

private:
	std::vector<Monster> myMonster;
	std::vector<Skill> mySkills;
};
