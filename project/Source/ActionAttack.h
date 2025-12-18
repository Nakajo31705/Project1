#pragma once
#include "Action.h"
#include "Monster.h"

class ActionAttack : public Action
{
public:
	ActionAttack(Monster* attacker, Monster* target)
		: attacker(attacker), target(target) {}
	void Execute() override;

private:
	Monster* attacker;
	Monster* target;
};