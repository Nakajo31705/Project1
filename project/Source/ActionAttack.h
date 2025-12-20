#pragma once
#include "Action.h"
#include "Monster.h"

using MonsterID = int;

class ActionAttack : public Action
{
public:
	ActionAttack(MonsterID attacker, MonsterID target, double value)
		: attacker(attacker), target(target), buffValue(value) {}

private:
	MonsterID attacker;
	MonsterID target;
	double buffValue = 1.0f;
};