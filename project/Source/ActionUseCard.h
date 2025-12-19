#pragma once
#include "Action.h"
#include "Monster.h"

class ActionUseCard : Action
{
public:
	ActionUseCard(Monster* user, Monster* target)
		: user(user), target(target){}
	void Execute() override;

private:
	Monster* user;
	Monster* target;
};