#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//�f�[�^�x�[�X��������
	MonsterList monsterList;
	SkillList skillList;

	//�v���C���[�̃����X�^�[
	//�����X�^�[�̏������o��
	std::string playerMonsterName = "���̐���";
	int playerHP = monsterList.GetHP(playerMonsterName);
	Monster playerMonster(playerMonsterName, playerHP);

	std::vector<Skill>playerSkills = {
		Skill("���U��", skillList.GetPower("���U��")),
	};

	//�����X�^�[�ƋZ�̏���n��
	Player player(playerMonster, playerSkills);

	//�G�l�~�[�̃����X�^�[
	std::string enemyMonsterName = "���̐���";
	int enemyHP = monsterList.GetHP(enemyMonsterName);
	Monster enemyMonster(enemyMonsterName, enemyHP);

	std::vector<Skill>enemySkills = {
		Skill("���U��", skillList.GetPower("���U��")),
	};

	//����n��
	Enemy enemy(enemyMonster, enemySkills);
}
