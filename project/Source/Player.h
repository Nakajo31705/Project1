#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "Monster.h"
#include "Skill.h"


class Player : GameObject
{
public:
	Player(const Monster& _monster, const std::vector<Skill>& _skills);
	~Player();
	void Update();
	void Draw();

	void IsDead();

private:
	Monster myMonster;
	std::vector<Skill> mySkills;
};
