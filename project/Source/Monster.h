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
	std::string name;	//名前
	int currentHP;		//現在のHP
	int maxHP;			//MAXHP
	SkillList skillList;//スキルリストから技の威力を取得

	//デバッグ用
	std::string attackMessage;
	int attackMessageTimer = 0;
};