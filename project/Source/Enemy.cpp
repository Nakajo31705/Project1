#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::vector<Monster>& _monster)
	:enemyMonster(_monster){}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	/*std::cout << "モンスター名:" << enemyMonster.GetName() << ",HP: " << enemyMonster.GetHP() << "\n";
	for (const auto& skill : enemySkills)
	{
		std::cout << "スキル: " << skill.GetName() << "(威力: " << skill.GetPower() << ")\n";
	}*/
}