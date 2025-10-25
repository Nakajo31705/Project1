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

MonsterType MonsterDataBase::GetMonsterType(const std::string& monsterName) const
{
	auto it = type.find(monsterName);
	if (it != type.end())
	{
		return it->second;
	}
	//名前が見つからない場合はNoneを返す
	return MonsterType::None;
}

inline std::string MonsterDataBase::MonsterTypeToString(MonsterType type) const
{
	switch (type)
	{
	case MonsterType::Fire: return "炎";
	case MonsterType::Water: return "水";
	case MonsterType::Grass: return "草";
	case MonsterType::Light: return "光";
	case MonsterType::Dark: return "闇";
	default: return "タイプ無し";
	}
}

inline MonsterType MonsterDataBase::StringToMonsterType(const std::string& typeStr) const
{
	if (typeStr == "炎") return MonsterType::Fire;
	if (typeStr == "水") return MonsterType::Water;
	if (typeStr == "草") return MonsterType::Grass;
	if (typeStr == "光") return MonsterType::Light;
	if (typeStr == "闇") return MonsterType::Dark;
	return MonsterType::None;
}

void MonsterDataBase::InitializeMonsters()
{
	//モンスターのHPを設定
	monsterHP["炎の精霊"] = 100;
	monsterHP["水の精霊"] = 100;
	monsterHP["草の精霊"] = 100;
	monsterHP["光の精霊"] = 100;
	monsterHP["闇の精霊"] = 100;

	//モンスターのタイプを設定
	type["炎の精霊"] = MonsterType::Fire;
	type["水の精霊"] = MonsterType::Water;
	type["草の精霊"] = MonsterType::Grass;
	type["光の精霊"] = MonsterType::Light;
	type["闇の精霊"] = MonsterType::Dark;


	//モンスターをリストに追加
	monsterList.push_back(Monster("炎の精霊", monsterHP["炎の精霊"], MonsterType::Fire));
	monsterList.push_back(Monster("水の精霊", monsterHP["水の精霊"], MonsterType::Water));
	monsterList.push_back(Monster("草の精霊", monsterHP["草の精霊"], MonsterType::Grass));
	monsterList.push_back(Monster("光の精霊", monsterHP["光の精霊"], MonsterType::Light));
	monsterList.push_back(Monster("闇の精霊", monsterHP["闇の精霊"], MonsterType::Dark));
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
