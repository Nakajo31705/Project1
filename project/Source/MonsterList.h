#pragma once
#include <vector>
#include "Monster.h"

class MonsterList
{
public:
	MonsterList();
	int GetHP(std::string& name) const;
private:
	std::vector<Monster> monsters;
};
