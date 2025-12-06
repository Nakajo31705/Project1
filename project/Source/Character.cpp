#include "Character.h"

Character::Character(const std::string& name, int maxHP)
	: name(name), maxHP(maxHP), currentHP(maxHP) {}

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
/// 攻撃力をあげる関数
/// </summary>
/// <param name="value">効果量</param>
/// <param name="duration">効果時間</param>
void Character::AddBuff(float value, int duration)
{

}

/// <summary>
/// 攻撃力を下げる関数
/// </summary>
/// <param name="value">効果量</param>
/// <param name="duration">効果時間</param>
void Character::AddDebuff(float value, int duration)
{
}

/// <summary>
/// 回復をする関数
/// </summary>
/// <param name="amount">効果量</param>
void Character::AddHeal(float amount)
{
	currentHP += amount;
	if (currentHP > maxHP) currentHP = maxHP;
}

/// <summary>
/// 属性を付与する関数
/// </summary>
/// <param name="duration">効果時間</param>
/// <param name="type">タイプ</param>
void Character::AddEmchant(int duration, int type)
{
}