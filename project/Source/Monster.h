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
	Monster(const std::string& _name, int _hp, std::vector<Skill> _skills);
	~Monster();
	void Update() override;
	void Draw() override;

	void TakeDamege(int damage);
	void Attack(Monster& target, std::string& skillName);

	bool IsDead() const;

	std::string& GetName()const;
	int GetHP()const;
	std::vector<Skill>& GetSkills();

private:
	std::string name;	//���O
	int currentHP;		//���݂�HP
	int maxHP;			//MAXHP
	std::vector<Skill> skills;

	//�f�o�b�O�p
	std::string attackMessage;
	int attackMessageTimer = 0;
};