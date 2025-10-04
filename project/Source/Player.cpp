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
	/*std::cout << "モンスター名:" << myMonster.GetName() << ",HP: " << myMonster.GetHP() << "\n";
	for (const auto& skill : mySkills)
	{
		std::cout << "スキル: " << skill.GetName() << "(威力: " << skill.GetPower() << ")\n";
	}*/
}

void Player::IsDead()
{
}
