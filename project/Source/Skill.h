#pragma once
#include <string>

class Skill
{
public:
	Skill(std::string _skillName, int _attackPower);
	std::string GetName() const { return skillName; }
	int GetPower() const { return attackPower; }
private:
	std::string skillName;	//‹Z–¼
	int attackPower;		//ˆÐ—Í
};