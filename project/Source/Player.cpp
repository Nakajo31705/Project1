#include <iostream>
#include "Player.h"

Player::Player(const std::vector<Monster>& _monster)
	: myMonster(_monster) {}

Player::~Player()
{
}

void Player::Update()
{
	
}

void Player::Draw()
{
	/*std::cout << "モンスター名:" << myMonster.GetName() << ",HP: " << myMonster.GetHP() << "\n";
	for (const auto& skill : mySkills)
	{
		std::cout << "スキル: " << skill.GetName() << "(威力: " << skill.GetPower() << ")\n";
	}*/
}

void Player::IsDead()
{
}
