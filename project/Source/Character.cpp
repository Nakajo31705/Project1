#include "Character.h"

Character::Character(const std::string& name, int maxHP)
	: name(name), maxHP(maxHP), currentHP(maxHP) {}

void Character::TakeDamage(int damage)
{
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

void Character::Heal(int amount)
{
	currentHP += amount;
	if (currentHP > maxHP) currentHP = maxHP;
}