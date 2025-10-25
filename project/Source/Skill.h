#pragma once
#include <string>
#include "MonsterDataBase.h"

class Skill
{
public:
	Skill(const std::string& _name, int _power, MonsterType _type);
	int GetPower() const;
	std::string GetName() const;
private:
	std::string name;		//‹Z–¼
	int power;				//ˆĞ—Í
	MonsterType type;		//‘®«
};