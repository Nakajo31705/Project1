#include "Skill.h"
#include "Monster.h"

Skill::Skill(const std::string& _name, int _power, MonsterType _type)
   : name(_name), power(_power), type(_type)
{
}

int Skill::GetPower() const
{
    return 0;
}

std::string Skill::GetName() const
{
    return std::string();
}

MonsterType Skill::GetType() const
{
    return type;
}


