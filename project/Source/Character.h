#pragma once
#include <string>

class Character
{
public:
	Character(const std::string& name, int maxHP);
	virtual ~Character() = default;

	//–¼‘O‚Ìæ“¾
	const std::string& GetName() const { return name; }

	//Å‘åHP‚Ìæ“¾
	int GetMaxHP() const { return maxHP; }

	//Œ»İ‚ÌHP‚Ìæ“¾
	int GetCurrentHP() const { return currentHP; }

	//UŒ‚‚ğó‚¯‚éˆ—
	virtual void TakeDamage(int damage);

	//UŒ‚—Í‚ğ‚ ‚°‚éˆ—
	virtual void AddBuff(float value, int duration);

	//UŒ‚—Í‚ğ‰º‚°‚éˆ—
	virtual void AddDebuff(float value, int duration);

	//‰ñ•œ‚·‚éˆ—
	virtual void AddHeal(float amount);

	//‘®«‚ğ•t—^‚·‚éˆ—
	virtual void AddEmchant(int duration, int type);

	//ƒ_ƒ[ƒWƒƒO
	virtual void OnDamageLog(int damage) = 0;

	//UŒ‚ƒƒO
	virtual void OnAttackLog(const std::string& skillName, const std::string& targetName) = 0;
private:
	std::string name;
	int maxHP;
	int currentHP;
};