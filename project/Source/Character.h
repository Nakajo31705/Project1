#pragma once
#include <string>
#include "GameManager.h"
#include "Skill.h"

class Character
{
public:
	Character(const std::string& name, int maxHP,int power);
	virtual ~Character() = default;
	void Update();

	//–¼‘O‚Ìæ“¾
	const std::string& GetName() const { return name; }

	//Å‘åHP‚Ìæ“¾
	int GetMaxHP() const { return maxHP; }

	//Œ»İ‚ÌHP‚Ìæ“¾
	int GetCurrentHP() const { return currentHP; }

	//Œ»İ‚ÌUŒ‚—Í‚ğæ“¾
	int GetCurrentPower() const { return power; }

	//UŒ‚‚ğó‚¯‚éˆ—
	virtual void TakeDamage(int damage);

	//UŒ‚—Í‚ğ‚ ‚°‚éˆ—
	virtual void AddBuff(float value, int duration);

	//UŒ‚—Í‚ğ‰º‚°‚éˆ—
	virtual void AddDebuff(float value, int duration);

	//‰ñ•œ‚·‚éˆ—
	virtual void AddHeal(float amount);

	//‘®«‚ğ•t—^‚·‚éˆ—
	virtual void AddEnchant(int duration, int type);

	//ƒ_ƒ[ƒWƒƒO
	virtual void OnDamageLog(int damage) = 0;

	//UŒ‚ƒƒO
	virtual void OnAttackLog(const std::string& skillName, const std::string& targetName) = 0;
private:
	GameManager* gameManager;
	Skill* skill;
	std::string name;
	int maxHP;
	int currentHP;
	int power;
	
	bool turnEnd = false;
};