#include "Enemy.h"

Enemy::Enemy(MonsterDataBase& db)
{
	//プレイヤーが使用するモンスターを指定
	std::vector<std::string> monsterNames = { "草の精霊", "光の精霊" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//技を設定
		if (name == "草の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("草攻撃", db.GetSkillPower("草攻撃")));
			skills.push_back(Skill("水攻撃", db.GetSkillPower("水攻撃")));
			monster.SetSkills(skills);
		}

		else if (name == "光の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("光攻撃", db.GetSkillPower("光攻撃")));
			skills.push_back(Skill("炎攻撃", db.GetSkillPower("炎攻撃")));
			monster.SetSkills(skills);
		}

		//控えのリストにモンスターを追加
		reserveMonsters.push_back(monster);
	}

	//控えリストの最初のモンスターをバトル場に設定
	if (!reserveMonsters.empty())
	{
		activeMonster = &reserveMonsters[0];
	}
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
	if (activeMonster) {
		std::string msg = activeMonster->GetName() + std::string("をバトル場にだした\n");
		DrawString(defDraw, defDraw, msg.c_str(), GetColor(255, 255, 255));
	}
	else {
		DrawString(defDraw, defDraw, "activeMonsterがNullです。", GetColor(255, 255, 255));
	}
}

Monster* Enemy::GetActiveMonster()
{
	return activeMonster;
}

void Enemy::SwichMonster()
{
}

void Enemy::SkillSelect()
{
}