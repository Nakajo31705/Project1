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
			monster.SetSkills(skills);
		}

		else if (name == "水の精霊")
		{
			//上と処理の内容は一緒でこのまま増やせばパーティを作れる
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
