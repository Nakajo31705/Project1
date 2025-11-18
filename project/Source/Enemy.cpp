#include "Enemy.h"

Enemy::Enemy(MonsterDataBase& db)
{
	//プレイヤーが使用するモンスターを指定
	std::vector<std::string> monsterNames = { "草の精霊", "光の精霊" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name),db.GetMonsterType(name));

		//技を設定
		if (name == "草の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("草攻撃", db.GetSkillPower("草攻撃"),MonsterType::Physical));
			skills.push_back(Skill("水攻撃", db.GetSkillPower("水攻撃"),MonsterType::Magic));
			monster.SetSkills(skills);
		}

		else if (name == "光の精霊")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("光攻撃", db.GetSkillPower("光攻撃"),MonsterType::Physical));
			skills.push_back(Skill("炎攻撃", db.GetSkillPower("炎攻撃"),MonsterType::Magic));
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

void Enemy::SwichMonster()
{
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

/*
	攻撃面
	TypeEffectiveのタイプ相性表を使ってスコアが高い行動をさせる
	技のタイプと相手のモンスターのタイプで比較
	※余裕があれば常に最高値のスコアの攻撃ではなくたまに違う技をするようにランダム制を持たせたい

	モンスター交換
	同じくタイプ相性表を使ってスコアが高い行動をさせる
	相手のモンスターのタイプをみて攻撃をする
	※交換は場のモンスターが死んだときのみ
*/