#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const Monster& _monster, const std::vector<Skill>& _skills)
	:enemyMonster(_monster), enemySkills(_skills) {}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	std::cout << "�����X�^�[��:" << enemyMonster.GetName() << ",HP: " << enemyMonster.GetHP() << "\n";
	for (const auto& skill : enemySkills)
	{
		std::cout << "�X�L��: " << skill.GetName() << "(�З�: " << skill.GetPower() << ")\n";
	}
}