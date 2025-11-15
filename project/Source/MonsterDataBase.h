#pragma once
#include "Monster.h"
#include "Skill.h"
#include <unordered_map>

enum class MonsterType
{

	Physical,
	Magic,
	None
};

class MonsterDataBase
{
public:
	MonsterDataBase();
	int GetMonsterHP(const std::string& monsterName) const;
	int GetSkillPower(const std::string& skillName) const;
	std::vector<Monster> GetMonsters() const;
	std::vector<Skill> GetSkills() const;
	MonsterType GetMonsterType(const std::string& monsterName) const;

	inline std::string MonsterTypeToString(MonsterType type) const;
	inline MonsterType StringToMonsterType(const std::string& typeStr) const;

private:
	std::vector<Monster> monsterList;							//モンスターのリスト
	std::vector<Skill> skillList;								//スキルのリスト
	std::unordered_map<std::string, int> monsterHP;				//モンスターごとのHP
	std::unordered_map<std::string, int> skillPower;			//技ごとの威力
	std::unordered_map<std::string, MonsterType> type;			//モンスターごとのタイプ

	void InitializeMonsters();
	void InitializeSkills();
};