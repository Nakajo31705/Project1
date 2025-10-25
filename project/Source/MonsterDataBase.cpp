#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//�f�[�^�x�[�X��������
	InitializeMonsters();
	InitializeSkills();
}

//�����X�^�[��HP���擾����֐�
int MonsterDataBase::GetMonsterHP(const std::string& monsterName) const
{
	auto it = monsterHP.find(monsterName);
	if (it != monsterHP.end())
	{
		return it->second;
	}
	//���O��������Ȃ��ꍇ��0��Ԃ�
	return 0;
}

//�Z�̈З͂��擾����֐�
int MonsterDataBase::GetSkillPower(const std::string& skillName) const
{
	auto it = skillPower.find(skillName);
	if (it != skillPower.end())
	{
		return it->second;
	}
	//���O��������Ȃ��ꍇ��0��Ԃ�
	return 0;
}

//���X�g���擾����֐�
std::vector<Monster> MonsterDataBase::GetMonsters() const
{
	return monsterList;
}

std::vector<Skill> MonsterDataBase::GetSkills() const
{
	return skillList;
}

MonsterType MonsterDataBase::GetMonsterType(const std::string& monsterName) const
{
	auto it = type.find(monsterName);
	if (it != type.end())
	{
		return it->second;
	}
	//���O��������Ȃ��ꍇ��None��Ԃ�
	return MonsterType::None;
}

inline std::string MonsterDataBase::MonsterTypeToString(MonsterType type) const
{
	switch (type)
	{
	case MonsterType::Fire: return "��";
	case MonsterType::Water: return "��";
	case MonsterType::Grass: return "��";
	case MonsterType::Light: return "��";
	case MonsterType::Dark: return "��";
	default: return "�^�C�v����";
	}
}

inline MonsterType MonsterDataBase::StringToMonsterType(const std::string& typeStr) const
{
	if (typeStr == "��") return MonsterType::Fire;
	if (typeStr == "��") return MonsterType::Water;
	if (typeStr == "��") return MonsterType::Grass;
	if (typeStr == "��") return MonsterType::Light;
	if (typeStr == "��") return MonsterType::Dark;
	return MonsterType::None;
}

void MonsterDataBase::InitializeMonsters()
{
	//�����X�^�[��HP��ݒ�
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["�ł̐���"] = 100;

	//�����X�^�[�̃^�C�v��ݒ�
	type["���̐���"] = MonsterType::Fire;
	type["���̐���"] = MonsterType::Water;
	type["���̐���"] = MonsterType::Grass;
	type["���̐���"] = MonsterType::Light;
	type["�ł̐���"] = MonsterType::Dark;


	//�����X�^�[�����X�g�ɒǉ�
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"], MonsterType::Fire));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"], MonsterType::Water));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"], MonsterType::Grass));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"], MonsterType::Light));
	monsterList.push_back(Monster("�ł̐���", monsterHP["�ł̐���"], MonsterType::Dark));
}

void MonsterDataBase::InitializeSkills()
{
	//�Z�̈З͂�ݒ�
	skillPower["���U��"] = 20;
	skillPower["���U��"] = 20;
	skillPower["���U��"] = 20;
	skillPower["���U��"] = 20;
	skillPower["�ōU��"] = 20;

	//�Z�����X�g�ɒǉ�
	skillList.push_back(Skill("���U��", skillPower["���U��"]));
	skillList.push_back(Skill("���U��", skillPower["���U��"]));
	skillList.push_back(Skill("���U��", skillPower["���U��"]));
	skillList.push_back(Skill("���U��", skillPower["���U��"]));
	skillList.push_back(Skill("�ōU��", skillPower["�ōU��"]));
}
