#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const Monster& _monster, const std::vector<Skill>& _skills)
	:enemyMonster(_monster), enemySkills(_skills) {}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	std::cout << "モンスター名:" << enemyMonster.GetName() << ",HP: " << enemyMonster.GetHP() << "\n";
	for (const auto& skill : enemySkills)
	{
		std::cout << "スキル: " << skill.GetName() << "(威力: " << skill.GetPower() << ")\n";
	}
}