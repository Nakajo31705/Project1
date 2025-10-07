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

void MonsterDataBase::InitializeMonsters()
{
	//�����X�^�[�̃f�[�^�ݒ�
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["���̐���"] = 100;
	monsterHP["�ł̐���"] = 100;

	//�����X�^�[�����X�g�ɒǉ�
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"]));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"]));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"]));
	monsterList.push_back(Monster("���̐���", monsterHP["���̐���"]));
	monsterList.push_back(Monster("�ł̐���", monsterHP["�ł̐���"]));
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
