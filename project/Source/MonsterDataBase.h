#pragma once
#include "Monster.h"
#include "Skill.h"
#include <unordered_map>

enum class MonsterType
{
	Fire,
	Water,
	Grass,
	Light,
	Dark,
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
	std::vector<Monster> monsterList;							//�����X�^�[�̃��X�g
	std::vector<Skill> skillList;								//�X�L���̃��X�g
	std::unordered_map<std::string, int> monsterHP;				//�����X�^�[���Ƃ�HP
	std::unordered_map<std::string, int> skillPower;			//�Z���Ƃ̈З�
	std::unordered_map<std::string, MonsterType> type;			//�����X�^�[���Ƃ̃^�C�v

	void InitializeMonsters();
	void InitializeSkills();
};