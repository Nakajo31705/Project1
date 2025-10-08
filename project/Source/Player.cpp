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
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			monster.SetSkills(skills);
		}

		else if (name == "���̐���")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			skills.push_back(Skill("�ōU��", db.GetSkillPower("�ōU��")));
			monster.SetSkills(skills);
		}

		monsters.push_back(monster);
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
}
