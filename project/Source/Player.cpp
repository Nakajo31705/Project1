#include <iostream>
#include "Player.h"

Player::Player(const Monster& _monster, const std::vector<Skill>& _skills)
	: myMonster(_monster), mySkills(_skills) {}

Player::~Player()
{
}

void Player::Update()
{
	
}

void Player::Draw()
{
	std::cout << "モンスター名:" << myMonster.GetName() << ",HP: " << myMonster.GetHP() << "\n";
	for (const auto& skill : mySkills)
	{
		std::cout << "スキル: " << skill.GetName() << "(威力: " << skill.GetPower() << ")\n";
	}
}

void Player::IsDead()
{
}
