#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//プレイヤーが使用するモンスターを指定
	std::vector<std::string> monsterNames = { "炎の精霊", "水の精霊" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//技を設定
		if (name == "炎の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("炎攻撃", db.GetSkillPower("炎攻撃")));
			skills.push_back(Skill("光攻撃", db.GetSkillPower("光攻撃")));
			monster.SetSkills(skills);
		}

		else if (name == "水の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("水攻撃", db.GetSkillPower("水攻撃")));
			skills.push_back(Skill("闇攻撃", db.GetSkillPower("闇攻撃")));
			monster.SetSkills(skills);
		}

		monsters.push_back(monster);

		//最初のモンスターをバトル場に設定
		if (!reserveMonsters.empty())
		{
			activeMoster = &reserveMonsters[0];
			reserveMonsters.erase(reserveMonsters.begin());
		}
	}
}

Player::~Player()
{
}

void Player::Update()
{
	DrawString(100, 100, (activeMoster->GetName() + "をバトル場に出した").c_str(), GetColor(255, 255, 255));
}

void Player::Draw()
{
}

Monster* Player::GetActiveMonster()
{
	return nullptr;
}

void Player::SwitchMonster(int index)
{
}
