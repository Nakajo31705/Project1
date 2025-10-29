#include "Enemy.h"

Enemy::Enemy(MonsterDataBase& db)
{
	//�v���C���[���g�p���郂���X�^�[���w��
	std::vector<std::string> monsterNames = { "���̐���", "���̐���" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name),db.GetMonsterType(name));

		//�Z��ݒ�
		if (name == "���̐���")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��"),MonsterType::Grass));
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��"),MonsterType::Water));
			monster.SetSkills(skills);
		}

		else if (name == "���̐���")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��"),MonsterType::Light));
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��"),MonsterType::Fire));
			monster.SetSkills(skills);
		}

		//�T���̃��X�g�Ƀ����X�^�[��ǉ�
		reserveMonsters.push_back(monster);
	}

	//�T�����X�g�̍ŏ��̃����X�^�[���o�g����ɐݒ�
	if (!reserveMonsters.empty())
	{
		activeMonster = &reserveMonsters[0];
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
	if (activeMonster) {
		std::string msg = activeMonster->GetName() + std::string("���o�g����ɂ�����\n");
		DrawString(defDraw, defDraw, msg.c_str(), GetColor(255, 255, 255));
	}
	else {
		DrawString(defDraw, defDraw, "activeMonster��Null�ł��B", GetColor(255, 255, 255));
	}
}

Monster* Enemy::GetActiveMonster()
{
	return activeMonster;
}

void Enemy::SwichMonster()
{
}

void Enemy::SkillSelect(Monster* player, Monster* enemy)
{
	//�G�l�~�[�̃X�L���擾
	std::vector<Skill> enemySkills = GetActiveMonster()->GetSkills();

	//�v���C���[�̃o�g����̃����X�^�[�̃^�C�v���擾
	auto playerActiveMonster = playerMonster->GetActiveMonster()->GetType();


}

/*
	�U����
	TypeEffective�̃^�C�v�����\���g���ăX�R�A�������s����������
	�Z�̃^�C�v�Ƒ���̃����X�^�[�̃^�C�v�Ŕ�r
	���]�T������Ώ�ɍō��l�̃X�R�A�̍U���ł͂Ȃ����܂ɈႤ�Z������悤�Ƀ����_����������������

	�����X�^�[����
	�������^�C�v�����\���g���ăX�R�A�������s����������
	����̃����X�^�[�̃^�C�v���݂čU��������
	�������͏�̃����X�^�[�����񂾂Ƃ��̂�
*/