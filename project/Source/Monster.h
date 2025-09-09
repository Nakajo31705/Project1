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
	std::string name;	//名前
	int currentHP;		//現在のHP
	int maxHP;			//MAXHP
	int attackPower;	//攻撃力
	SkillList skillList;//スキルリストから技の威力を取得
};