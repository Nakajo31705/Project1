#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//データベースを初期化
	InitializeMonsters();
	InitializeSkills();
}

//モンスターのHPを取得する関数
int MonsterDataBase::GetMonsterHP(const std::string& monsterName) const
{
	auto it = monsterHP.find(monsterName);
	if (it != monsterHP.end())
	{
		return it->second;
	}
	//名前が見つからない場合は0を返す
	return 0;
}

//技の威力を取得する関数
int MonsterDataBase::GetSkillPower(const std::string& skillName) const
{
	auto it = skillPower.find(skillName);
	if (it != skillPower.end())
	{
		return it->second;
	}
	//名前が見つからない場合は0を返す
	return 0;
}

//リストを取得する関数
std::vector<Monster> MonsterDataBase::GetMonsters() const
{
	return monsterList;
}

std::vector<Skill> MonsterDataBase::GetSkills() const
{
	return skillList;
}

void MonsterDataBase::InitializeMonsters()
{
	//モンスターのデータ設定
	monsterHP["炎の精霊"] = 100;
	monsterHP["水の精霊"] = 100;
	monsterHP["草の精霊"] = 100;
	monsterHP["光の精霊"] = 100;
	monsterHP["闇の精霊"] = 100;

	//モンスターをリストに追加
	monsterList.push_back(Monster("炎の精霊", monsterHP["炎の精霊"]));
	monsterList.push_back(Monster("水の精霊", monsterHP["水の精霊"]));
	monsterList.push_back(Monster("草の精霊", monsterHP["草の精霊"]));
	monsterList.push_back(Monster("光の精霊", monsterHP["光の精霊"]));
	monsterList.push_back(Monster("闇の精霊", monsterHP["闇の精霊"]));
}

void MonsterDataBase::InitializeSkills()
{
	//技の威力を設定
	skillPower["炎攻撃"] = 20;
	skillPower["水攻撃"] = 20;
	skillPower["草攻撃"] = 20;
	skillPower["光攻撃"] = 20;
	skillPower["闇攻撃"] = 20;

	//技をリストに追加
	skillList.push_back(Skill("炎攻撃", skillPower["炎攻撃"]));
	skillList.push_back(Skill("水攻撃", skillPower["水攻撃"]));
	skillList.push_back(Skill("草攻撃", skillPower["草攻撃"]));
	skillList.push_back(Skill("光攻撃", skillPower["光攻撃"]));
	skillList.push_back(Skill("闇攻撃", skillPower["闇攻撃"]));
}
