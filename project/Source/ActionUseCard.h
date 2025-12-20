#pragma once
#include "Action.h"
#include "Monster.h"
#include "CardManager.h"

class ActionUseCard : Action
{
public:
	ActionUseCard(int index, Monster* user, Monster* target)
		: index(index),user(user), target(target){}

private:
	int index;
	Monster* user;
	Monster* target;
	CardManager* cardM;
};