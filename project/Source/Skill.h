#pragma once
#include <string>

class Skill
{
public:
	Skill(const std::string& _name, int _power);
	int GetPower() const;
	std::string GetName() const;
private:
	std::string name;	//‹Z–¼
	int power;		//ˆÐ—Í
};