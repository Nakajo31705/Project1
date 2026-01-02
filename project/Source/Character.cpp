#include "Character.h"
#include "GameManager.h"

Character::Character(const std::string& name, int maxHP, int power)
	: name(name), maxHP(maxHP), currentHP(maxHP), power(power) {}

void Character::Update()
{
	//あとで
	//turnEnd = gameManager->GetTurnEnded();
}

/// <summary>
/// ダメージを受ける処理
/// </summary>
/// <param name="damage">ダメージの値</param>
void Character::TakeDamage(int damage)
{
	currentHP -= damage;
	if (currentHP < 0) currentHP = 0;
}

/// <summary>
/// 攻撃の処理
/// </summary>
/// <param name="target"></param>
/// <param name="_skill"></param>
void Character::Attack(Character& target, const Skill& skill)
{
	OnAttackLog(skill.GetName(), target.GetName());
	target.TakeDamage(power);
}

/// <summary>
/// 攻撃力をあげる関数
/// </summary>
/// <param name="value">効果量</param>
/// <param name="duration">効果時間</param>
void Character::AddBuff(float value)
{
	int buffSkill = skill->GetPower();
	power  = buffSkill * value;
}

/// <summary>
/// 攻撃力を下げる関数
/// </summary>
/// <param name="value">効果量</param>
/// <param name="duration">効果時間</param>
void Character::AddDebuff(float value)
{
}

/// <summary>
/// 回復をする関数
/// </summary>
/// <param name="amount">効果量</param>
void Character::AddHeal(float value)
{
	currentHP += value;
	if (currentHP > maxHP) currentHP = maxHP;
}

/// <summary>
/// 属性を付与する関数
/// </summary>
/// <param name="duration">効果時間</param>
/// <param name="type">タイプ</param>
void Character::AddEnchant(int type)
{
}