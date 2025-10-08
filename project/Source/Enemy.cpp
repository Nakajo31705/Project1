#include "Enemy.h"

Enemy::Enemy(MonsterDataBase& db)
{
	//ƒvƒŒƒCƒ„[‚ªg—p‚·‚éƒ‚ƒ“ƒXƒ^[‚ğw’è
	std::vector<std::string> monsterNames = { "‘‚Ì¸—ì", "Œõ‚Ì¸—ì" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//‹Z‚ğİ’è
		if (name == "‘‚Ì¸—ì")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("‘UŒ‚", db.GetSkillPower("‘UŒ‚")));
			skills.push_back(Skill("…UŒ‚", db.GetSkillPower("…UŒ‚")));
			monster.SetSkills(skills);
		}

		else if (name == "Œõ‚Ì¸—ì")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("ŒõUŒ‚", db.GetSkillPower("ŒõUŒ‚")));
			skills.push_back(Skill("‰ŠUŒ‚", db.GetSkillPower("‰ŠUŒ‚")));
			monster.SetSkills(skills);
		}

		monsters.push_back(monster);
	}
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
}