#include "Monster.h"

Monster::Monster(const std::string& _name, int _maxHP)
{
	name = _name;
}

Monster::~Monster()
{
}

void Monster::Update()
{
}

void Monster::Draw()
{
}

void Monster::TakeDamege(int damage)
{
	currentHP -= damage;
	if (currentHP < 0)
	{
		currentHP = 0;
	}

	std::string nameInfo = name + "[" + std::to_string(currentHP) + "/" + std::to_string(maxHP) + "]";
	DrawString(100, 100, nameInfo.c_str(), GetColor(255, 255, 255));
}

void Monster::Attack(Monster& target)
{
	std::string attackInfo = name + "‚ÌUŒ‚!";
	DrawString(100, 120, attackInfo.c_str(), GetColor(255, 255, 255));
	target.TakeDamege(attackPower);
}

bool Monster::IsDead() const
{
	return currentHP <= 0;
}

const std::string& Monster::GetName()
{
	return name;
}
