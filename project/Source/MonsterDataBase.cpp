#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//�f�[�^�x�[�X��������
	MonsterList monsterList;
	SkillList skillList;

	//�����X�^�[�̏������o��
	std::vector<Monster> playerMonster = {
		Monster("���̐���",monsterList.GetHP("���̐���"),{
			Skill("���U��", skillList.GetPower("���U��"))
	}),
		Monster("���̐���",monsterList.GetHP("���̐���"),{
			Skill("���U��", skillList.GetPower("���U��"))
	}),
	};

	//�����X�^�[�ƋZ�̏���n��
	Player player(playerMonster);



	//�G�l�~�[�̃����X�^�[
	std::vector<Monster> enemyMonster = {
		Monster("���̐���", monsterList.GetHP("���̐���")),
	};

	std::vector<Skill>enemySkills = {
		Skill("���U��", skillList.GetPower("���U��")),
	};

	Enemy enemy(enemyMonster, enemySkills);
}
