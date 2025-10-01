#include "SkillList.h"

SkillList::SkillList()
{
	//‹Z‚ğƒŠƒXƒg‚É’Ç‰Á
	skills.emplace_back("‰ŠUŒ‚", 100);
	skills.emplace_back("…UŒ‚", 100);
	skills.emplace_back("‘UŒ‚", 100);
	skills.emplace_back("ŒõUŒ‚", 100);
	skills.emplace_back("ˆÅUŒ‚", 100);
}

//’Ç‰Á‚µ‚½‹Z‚Ì–¼‘O‚©‚çˆĞ—Í‚ğæ“¾
int SkillList::GetPower(const std::string& skillName) const
{
	for (const auto& skill : skills)
	{
		if (skill.GetName() == skillName)
		{
			return skill.GetPower();
		}
	}
	return 0;
}
