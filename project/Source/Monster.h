#pragma once
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include <vector>
#include "Skill.h"

class Monster : public GameObject
{
public:
	Monster();
	Monster(const std::string& _name, int _hp);
	~Monster();
	void Update() override;
	void Draw() override;

	void TakeDamege(int damage);
	void Attack(Monster& target, std::string& skillName);
	void AddSkill(const Skill& skill);
	const std::string& GetName() const;

	bool IsDead() const;

private:
	std::string name;	//名前
	int hp;
	std::vector<Skill> skills;

	//デバッグ用
	std::string attackMessage;
	int attackMessageTimer = 0;
};