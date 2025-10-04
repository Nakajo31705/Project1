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
	std::vector<Monster> monsterList;				//�����X�^�[�̃��X�g
	std::unordered_map<std::string, int> monsterHP;	//�����X�^�[���Ƃ�HP
	std::unordered_map<std::string, int> skillPower;//�Z���Ƃ̈З�

	void InitializeMonsters();
	void InitializeSkills();
};