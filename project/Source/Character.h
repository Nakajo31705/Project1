#pragma once
#include <string>

class Character
{
public:
	Character(const std::string& name, int maxHP);
	virtual ~Character() = default;

	//名前の取得
	const std::string& GetName() const { return name; }

	//最大HPの取得
	int GetMaxHP() const { return maxHP; }

	//現在のHPの取得
	int GetCurrentHP() const { return currentHP; }

	//攻撃を受ける処理
	virtual void TakeDamage(int damage);

	//回復する処理
	virtual void Heal(int amount);

	//ダメージログ
	virtual void OnDamageLog(int damage) = 0;

	//攻撃ログ
	virtual void OnAttackLog(const std::string& skillName, const std::string& targetName) = 0;
private:
	std::string name;
	int maxHP;
	int currentHP;
};