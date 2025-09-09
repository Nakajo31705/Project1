#pragma once
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include "SkillList.h"

class Monster : public GameObject
{
public:
	Monster(const std::string& _name, int _maxHP);
	~Monster();
	void Update() override;
	void Draw() override;

	void TakeDamege(int damage);
	void Attack(Monster& target);

	bool IsDead() const;
	const std::string& GetName();
	void SetSkillName(const std::string& skillName);
	void SetSkillPower()const;

private:
	std::string name;	//���O
	int currentHP;		//���݂�HP
	int maxHP;			//MAXHP
	int attackPower;	//�U����
	SkillList skillList;//�X�L�����X�g����Z�̈З͂��擾
};