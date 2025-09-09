#pragma once
#include <string>

class Skill
{
public:
	Skill(std::string _skillName, int _attackPower);
	std::string name = skillName;
	int power = attackPower;
private:
	std::string skillName;	//‹Z–¼
	int attackPower;		//ˆÐ—Í
};