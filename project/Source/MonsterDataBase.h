#pragma once
#include "MonsterList.h"
#include "SkillList.h"
#include "Player.h"
#include "Enemy.h"
#include <unordered_map>

class MonsterDataBase
{
public:
	MonsterDataBase();
	int GetMonsterHP(const std::string& monsterName) const;
	int GetSkillPower(const std::string& skillName) const;
	std::vector<Monster> GetMonsters() const;

private:
	std::vector<Monster> monsterList;				//モンスターのリスト
	std::unordered_map<std::string, int> monsterHP;	//モンスターごとのHP
	std::unordered_map<std::string, int> skillPower;//技ごとの威力

	void InitializeMonsters();
	void InitializeSkills();
};