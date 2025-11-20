#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//データベースを初期化
	InitializeMonsters();
	InitializeSkills();
}

/// <summary>
/// モンスターのHPを取得する関数
/// </summary>
/// <param name="monsterName"></param>
/// <returns>モンスターの名前を書いてHPを取得</returns>
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

/// <summary>
/// 技の威力を取得する関数
/// </summary>
/// <param name="skillName"></param>
/// <returns>技の名前を書いて威力を取得</returns>
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

/// <summary>
/// モンスターのリストを取得する関数
/// </summary>
/// <returns></returns>
std::vector<Monster> MonsterDataBase::GetMonsters() const
{
	return monsterList;
}

/// <summary>
/// スキルのリストを取得する関数
/// </summary>
/// <returns></returns>
std::vector<Skill> MonsterDataBase::GetSkills() const
{
	return skillList;
}

/// <summary>
/// モンスターのタイプを取得する関数
/// </summary>
/// <param name="monsterName"></param>
/// <returns>モンスターの名前を書いてタイプを取得</returns>
MonsterType MonsterDataBase::GetType(const std::string& monsterName) const
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
	case MonsterType::Physical: return "物理";
	case MonsterType::Magic: return "魔法";
	default: return "タイプ無し";
	}
}

inline MonsterType MonsterDataBase::StringToMonsterType(const std::string& typeStr) const
{
	if (typeStr == "物理") return MonsterType::Physical;
	if (typeStr == "魔法") return MonsterType::Magic;
	return MonsterType::None;
}

void MonsterDataBase::InitializeMonsters()
{
	//モンスターのHPを設定
	monsterHP["剣士"] = 100;
	monsterHP["魔法使い"] = 100;
	monsterHP["魔王"] = 300;

	//モンスターのタイプを設定
	type["物理"] = MonsterType::Physical;
	type["魔法"] = MonsterType::Magic;
}

void MonsterDataBase::InitializeSkills()
{
	//技の威力を設定
	skillPower["斬撃"] = 20;
	skillPower["魔法"] = 20;

	//技をリストに追加
	skillList.push_back(Skill("斬撃", skillPower["斬撃"], type["物理"]));
	skillList.push_back(Skill("魔法", skillPower["魔法"], type["魔法"]));
}
