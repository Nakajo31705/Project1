#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//�v���C���[���g�p���郂���X�^�[���w��
	std::vector<std::string> monsterNames = { "���̐���", "���̐���" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//�Z��ݒ�
		if (name == "���̐���")
		{
		}
	}
}

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
