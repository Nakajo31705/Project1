#include "Monster.h"

Monster::Monster(std::string name, int maxHP, int power, MonsterType type)
	:Character(name, maxHP, power), type(type) {}

void Monster::Update()
{
}

void Monster::Draw()
{
}

/// <summary>
/// ダメージを受けたときのログ
/// </summary>
/// <param name="damage"></param>
void Monster::OnDamageLog(int damage)
{
	std::string logDamage = GetName() + "は" + std::to_string(damage) + "のダメージを受けた！";
	log.AddLog(logDamage.c_str(), 560, 500, 1000);
}

/// <summary>
/// 攻撃をした時のログ
/// </summary>
/// <param name="skillName"></param>
/// <param name="targetName"></param>
void Monster::OnAttackLog(const std::string& skillName, const std::string& targetName)
{
	std::string logAttack = GetName() + "は" + targetName + "に" + skillName + "の攻撃をした！";
	log.AddLog(logAttack.c_str(), 100, 100, 1000);
}

/// <summary>
/// モンスターの使用できる技を取得
/// </summary>
/// <returns></returns>
const std::vector<Skill>& Monster::GetSkills() const
{
	return skills;
}

/// <summary>
/// モンスターが使用できる技を渡す
/// </summary>
/// <param name="_skills"></param>
void Monster::SetSkills(const std::vector<Skill>& _skills)
{
	skills = _skills;
}

/// <summary>
/// モンスターの属性を取得
/// </summary>
/// <returns></returns>
MonsterType Monster::GetType() const
{
	return type;
}


