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
	/*std::cout << "�����X�^�[��:" << myMonster.GetName() << ",HP: " << myMonster.GetHP() << "\n";
	for (const auto& skill : mySkills)
	{
		std::cout << "�X�L��: " << skill.GetName() << "(�З�: " << skill.GetPower() << ")\n";
	}*/
}

void Player::IsDead()
{
}
