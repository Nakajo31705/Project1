#include "Skill.h"
#include "Monster.h"

Skill::Skill(const std::string& _name, int _power, MonsterType _type)
   : name(_name), power(_power), type(_type)
{
}

//‹Z‚ÌˆĞ—Í‚ğæ“¾
int Skill::GetPower() const
{
    return 0;
}

//‹Z‚ÌˆĞ—Í‚ğ•ÏX
//void Skill::SetPower(int changedPower)
//{
//    power = changedPower;
//}

//‹Z‚Ì–¼‘O‚ğæ“¾
std::string Skill::GetName() const
{
    return name;
}

//‹Z‚Ìƒ^ƒCƒv‚ğæ“¾
MonsterType Skill::GetType() const
{
    return type;
}


