#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//ƒvƒŒƒCƒ„[‚ªg—p‚·‚éƒ‚ƒ“ƒXƒ^[‚ğw’è
	std::vector<std::string> monsterNames = { "‰Š‚Ì¸—ì", "…‚Ì¸—ì" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//‹Z‚ğİ’è
		if (name == "‰Š‚Ì¸—ì")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("‰ŠUŒ‚", db.GetSkillPower("‰ŠUŒ‚")));
			skills.push_back(Skill("ŒõUŒ‚", db.GetSkillPower("ŒõUŒ‚")));
			monster.SetSkills(skills);
		}

		else if (name == "…‚Ì¸—ì")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("…UŒ‚", db.GetSkillPower("…UŒ‚")));
			skills.push_back(Skill("ˆÅUŒ‚", db.GetSkillPower("ˆÅUŒ‚")));
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
