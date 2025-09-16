#pragma once
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include "SkillList.h"

class Monster : public GameObject
{
public:
	Monster();
	~Monster();
	void Update() override;
	void Draw() override;

	void TakeDamege(int damage);
	void Attack(Monster& target, std::string& skillName);

	bool IsDead() const;

private:
	std::string name;	//���O
	int currentHP;		//���݂�HP
	int maxHP;			//MAXHP
	SkillList skillList;//�X�L�����X�g����Z�̈З͂��擾

	//�f�o�b�O�p
	std::string attackMessage;
	int attackMessageTimer = 0;
};