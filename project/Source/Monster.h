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
	std::string name;	//名前
	int currentHP;		//現在のHP
	int maxHP;			//MAXHP

	//デバッグ用
	std::string attackMessage;
	int attackMessageTimer = 0;
};