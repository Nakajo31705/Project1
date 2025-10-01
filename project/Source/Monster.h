#pragma once
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>

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

	bool IsDead() const;

	std::string GetName()const { return name; }
	int GetHP()const { return currentHP; }

private:
	std::string name;	//���O
	int currentHP;		//���݂�HP
	int maxHP;			//MAXHP

	//�f�o�b�O�p
	std::string attackMessage;
	int attackMessageTimer = 0;
};