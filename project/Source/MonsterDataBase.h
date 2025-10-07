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
	std::vector<Monster> monsterList;				//�����X�^�[�̃��X�g
	std::vector<Skill> skillList;					//�X�L���̃��X�g
	std::unordered_map<std::string, int> monsterHP;	//�����X�^�[���Ƃ�HP
	std::unordered_map<std::string, int> skillPower;//�Z���Ƃ̈З�

	void InitializeMonsters();
	void InitializeSkills();
};