#pragma once
#include "LogManager.h"
#include "CardDataBase.h"
//#include "Character.h"
class Character;
class CardManager
{
public:
	void UseCard(int id, Character* user, Character* target);
private:
	CardDataBase& cardDB;
	LogManager log;
};
