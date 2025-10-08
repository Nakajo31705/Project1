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

	//攻撃の処理
	void Attack(Monster& target, const Skill& _skill);

	//攻撃を受ける処理
	void TakeDamage(int _damage);

	//モンスター名を取得
	std::string GetName() const;

	//現在のHPを取得
	int GetCurrentHP() const;

	//スキルを取得
	const std::vector<Skill>& GetSkills() const;

	//スキルをセット
	void SetSkills(const std::vector<Skill>& _skills);

private:
	std::string name;
	int maxHP;
	int currentHP;

	std::vector<Skill> skills;

};