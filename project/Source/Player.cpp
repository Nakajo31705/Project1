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

		reserveMonsters.push_back(monster);
	}

	//最初のモンスターをバトル場に設定
	if (!reserveMonsters.empty())
	{
		activeMonster = &reserveMonsters[0];
	}
}

Player::~Player()
{
	if (activeMonster != nullptr)
		delete activeMonster;
		activeMonster = nullptr;
}

void Player::Update()
{
	if (activeMonster) {
		std::string msg = activeMonster->GetName() + std::string("をバトル場にだした");
		DrawString(defDraw, defDraw, msg.c_str(), GetColor(255, 255, 255));
	}
	else{
		DrawString(defDraw, defDraw, "activeMonsterがnullです。", GetColor(255, 255, 255));
	}
	
	
}

void Player::Draw()
{
}

Monster* Player::GetActiveMonster()
{
	return nullptr;
}

void Player::SwitchMonster()
{
	int yOffset = 30;

	//控えのモンスターの表示
	for (int i = 0; i < reserveMonsters.size(); i++)
	{
		const Monster& monster = reserveMonsters[i];
		if (i == selectMonsterIndex)
		{
			DrawString(monsterDrawX, monsterDrawY + i * yOffset, "→", GetColor(255, 255, 0));
			DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, monster.GetName().c_str(), GetColor(255, 255, 0));
		}
		else
		{
			DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, monster.GetName().c_str(), GetColor(255, 255, 255));
		}
	}

	//キー入力の判定
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		selectMonsterIndex--;
		if (selectMonsterIndex < 0) selectMonsterIndex = reserveMonsters.size() - 1;
		WaitTimer(150);
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		selectMonsterIndex++;
		if (selectMonsterIndex >= reserveMonsters.size()) selectMonsterIndex = 0;
		WaitTimer(150);
	}

	//決定の処理
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		selectedMonster = &reserveMonsters[selectMonsterIndex];
		DrawString(defDraw, defDraw, (selectedMonster->GetName() + "を選択").c_str(), GetColor(255, 255, 255));
		WaitTimer(500);
	}

	if (selectedMonster != nullptr && activeMonster != nullptr)
	{
		//バトル場のモンスターを控えに戻す
		reserveMonsters.push_back(*activeMonster);

		//控えから選んだモンスターを削除
		reserveMonsters.erase(reserveMonsters.begin() + selectMonsterIndex);

		//選んだモンスターをバトル場に設定
		activeMonster = selectedMonster;

		//インデックスリセット
		selectMonsterIndex = 0;

		DrawString(defDraw, defDraw, (activeMonster->GetName() + "をバトル場に出した!").c_str(), GetColor(255, 255, 255));
		WaitTimer(500);
	}
}
