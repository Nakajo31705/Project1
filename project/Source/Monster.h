#pragma once
#include <iostream>
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include <vector>
#include "Skill.h"
#include "LogManager.h"
#include "Character.h"

enum class MonsterType;

class Monster : public GameObject, public Character
{
public:
	Monster(std::string name, int maxHP, MonsterType type);
	void Update() override;
	void Draw() override;

	//攻撃の処理
	void Attack(Monster& target, const Skill& skill);

	//ダメージのログ
	void OnDamageLog(int damage) override;

	//攻撃のログ
	void OnAttackLog(const std::string& skillName, const std::string& targetName) override;

	//スキルを取得
	const std::vector<Skill>& GetSkills() const;

	//スキルをセット
	void SetSkills(const std::vector<Skill>& skills);

	//タイプを取得
	MonsterType GetType() const;

private:
	MonsterType type;
	LogManager log;
	std::vector<Skill> skills;
};