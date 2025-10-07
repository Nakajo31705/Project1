#pragma once
#include "Monster.h"
#include "Skill.h"
#include <unordered_map>

class MonsterDataBase
{
public:
	MonsterDataBase();
	int GetMonsterHP(const std::string& monsterName) const;
	int GetSkillPower(const std::string& skillName) const;
	std::vector<Monster> GetMonsters() const;
	std::vector<Skill> GetSkills() const;

private:
	std::vector<Monster> monsterList;				//モンスターのリスト
	std::vector<Skill> skillList;					//スキルのリスト
	std::unordered_map<std::string, int> monsterHP;	//モンスターごとのHP
	std::unordered_map<std::string, int> skillPower;//技ごとの威力

	void InitializeMonsters();
	void InitializeSkills();
};