#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::vector<Monster>& _monster)
	:enemyMonster(_monster){}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	/*std::cout << "�����X�^�[��:" << enemyMonster.GetName() << ",HP: " << enemyMonster.GetHP() << "\n";
	for (const auto& skill : enemySkills)
	{
		std::cout << "�X�L��: " << skill.GetName() << "(�З�: " << skill.GetPower() << ")\n";
	}*/
}