#include "Monster.h"

Monster::Monster(std::string _name, int _maxHP)
	:name(_name), maxHP(_maxHP), currentHP(_maxHP) {}

Monster::~Monster()
{
}

void Monster::Update()
{
}

void Monster::Draw()
{
}

void Monster::Attack(Monster& target, const Skill& _skill)
{
	std::cout << name << "��" << target.GetName() << "��" << _skill.GetName() << "���g����\n";
	target.TakeDamage(_skill.GetPower());
}

void Monster::TakeDamage(int _damage)
{
	currentHP -= _damage;
	if (currentHP < 0) currentHP = 0;
	std::cout << name << "��" << _damage << "�̃_���[�W���󂯂�\n";
}

std::string  Monster::GetName() const
{
	return name;
}

int Monster::GetCurrentHP() const
{
	return currentHP;
}

const std::vector<Skill>& Monster::GetSkills() const
{
	return skills;
}

void Monster::SetSkills(const std::vector<Skill>& _skills)
{
	skills = _skills;
}


