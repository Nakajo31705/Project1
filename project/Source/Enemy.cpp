#include "Enemy.h"

Enemy::Enemy(MonsterDataBase& db)
{
	//エネミーが使用するモンスターを指定
	std::vector<std::string> monsterNames = { "魔王"};

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name),db.GetType(name));

		//技を設定
		if (name == "魔王")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("斬撃", db.GetSkillPower("斬撃"),db.GetType("物理")));
			skills.push_back(Skill("魔法", db.GetSkillPower("魔法"),db.GetType("魔法")));
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
	//SkillSelect(playerMonster->GetActiveMonster(), GetActiveMonster());
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
		DrawString(defDrawX, defDrawY, msg.c_str(), GetColor(255, 255, 255));
	}
	else {
		DrawString(defDrawX, defDrawY, "activeMonsterがNullです。", GetColor(255, 255, 255));
	}
}

Monster* Enemy::GetActiveMonster()
{
	return activeMonster;
}

void Enemy::SkillSelect(Monster* player, Monster* enemy)
{
	//エネミーのスキル取得
	std::vector<Skill> enemySkills = enemy->GetSkills();

	//プレイヤーのバトル場のモンスターのタイプを取得
	auto playerActiveMonster = player->GetType();

	//技の数の分だけスコアを格納するサイズを代入
	skillScore.resize(enemySkills.size());
	double max = 0;
	int maxSkillIndex = 0;

	for (int i = 0; i < enemySkills.size(); i++) {
		double value = GetTypeEffective(enemySkills[i].GetType(), playerActiveMonster);
		value *= enemySkills[i].GetPower();
		if (max < value) {
			max = value;
			maxSkillIndex = i;
		}
	}

	//enemySkills[maxSkillIndex];
}