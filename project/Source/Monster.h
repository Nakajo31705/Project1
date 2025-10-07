#pragma once
#include <iostream>
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include <vector>
#include "Skill.h"

class Monster : public GameObject
{
public:
	Monster(std::string _name, int _maxHP);
	~Monster();
	void Update() override;
	void Draw() override;

	void Attack(Monster& target, const Skill& _skill);
	void TakeDamage(int _damage);

	std::string GetName() const;
	int GetCurrentHP() const;
	void SetSkills(const std::vector<Skill>& _skills);
	const std::vector<Skill>& GetSkills() const;

private:
	std::string name;
	int maxHP;
	int currentHP;

	std::vector<Skill> skills;

};