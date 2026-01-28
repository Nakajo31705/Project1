#pragma once
#include <string>
class GameManager;
#include "Skill.h"
#include "CardManager.h"

class Character
{
public:
	Character(const std::string& name, int maxHP,int power);
	virtual ~Character() = default;
	void Update();

	//–¼‘O‚Ìæ“¾
	virtual const std::string& GetName() const { return name; }

	//Å‘åHP‚Ìæ“¾
	virtual int GetMaxHP() const { return maxHP; }

	//Œ»İ‚ÌHP‚Ìæ“¾
	virtual int GetCurrentHP() const { return currentHP; }

	//Œ»İ‚ÌUŒ‚—Í‚ğæ“¾
	virtual int GetCurrentPower() const { return power; }

	//UŒ‚‚ğó‚¯‚éˆ—
	virtual void TakeDamage(int damage);

	//UŒ‚‚Ìˆ—
	virtual void Attack(Character& target, const Skill& skill);

	virtual bool IsDead();

	////UŒ‚—Í‚ğ‚ ‚°‚éˆ—
	//virtual void AddBuff(float value);

	////UŒ‚—Í‚ğ‰º‚°‚éˆ—
	//virtual void AddDebuff(float value);

	////‰ñ•œ‚·‚éˆ—
	//virtual void AddHeal(float value);

	////‘®«‚ğ•t—^‚·‚éˆ—
	//virtual void AddEnchant( int type);

	//ƒ_ƒ[ƒWƒƒO
	virtual void OnDamageLog(int damage) = 0;

	//UŒ‚ƒƒO
	virtual void OnAttackLog(const std::string& skillName, const std::string& targetName) = 0;

	////Œ»İ‚Ìƒpƒ[‚ğXV
	//virtual void SetCurrentPower(const int _power) { power = _power; }
private:
	GameManager* gameManager;
	
	Skill* skill;
	std::string name;
	int maxHP;
	int currentHP;
	int power;
	bool dead = false;

	//float value;
	//int duration;
	
	bool turnEnd = false;
};