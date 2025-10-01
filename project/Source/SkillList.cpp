#include "SkillList.h"

SkillList::SkillList()
{
	//�Z�����X�g�ɒǉ�
	skills.emplace_back("���U��", 100);
	skills.emplace_back("���U��", 100);
	skills.emplace_back("���U��", 100);
	skills.emplace_back("���U��", 100);
	skills.emplace_back("�ōU��", 100);
}

//�ǉ������Z�̖��O����З͂��擾
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
