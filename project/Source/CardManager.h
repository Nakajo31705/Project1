#pragma once
#include "CardDataBase.h"
#include "Character.h"

class CardManager
{
public:
	void UseCard(int id, Character* user, Character* target);
private:
	CardDataBase& cardDB;
};
