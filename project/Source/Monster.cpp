#include "Monster.h"

Monster::Monster(std::string _name, int _maxHP,MonsterType _type)
	:name(_name), maxHP(_maxHP), currentHP(_maxHP) , type(_type){}

Monster::~Monster()
{
}

void Monster::Update()
{
}

void Monster::Draw()
{
}

/// <summary>
/// 攻撃の処理
/// </summary>
/// <param name="target"></param>
/// <param name="_skill"></param>
void Monster::Attack(Monster& target, const Skill& _skill)
{
	std::string logAttack = name + "は" + target.GetName() + "に" + _skill.GetName() + "を使った";
	log.AddLog(logAttack.c_str(), 100, 100, 1000);
	target.TakeDamage(_skill.GetPower());
}

/// <summary>
/// ダメージを受ける処理
/// </summary>
/// <param name="_damage"></param>
void Monster::TakeDamage(int _damage)
{
	currentHP -= _damage;
	if (currentHP < 0) currentHP = 0;
	std::string logTakeDamage = name + "は" + std::to_string(_damage) + "のダメージを受けた";
	log.AddLog(logTakeDamage.c_str(), 100, 100, 1000);
}

/// <summary>
/// モンスターの名前を取得
/// </summary>
/// <returns></returns>
std::string  Monster::GetName() const
{
	return name;
}

/// <summary>
/// モンスターの現在のHPを取得
/// </summary>
/// <returns></returns>
int Monster::GetCurrentHP() const
{
	return currentHP;
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


