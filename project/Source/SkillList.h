#pragma once
#include <vector>
#include "Skill.h"

class SkillList
{
public:
	SkillList();
	int GetPower(const std::string& skillName) const;
private:
	std::vector<Skill> skills;
};