#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(const std::string& _name, int _hp)
	:name(_name), hp(_hp){}

Monster::~Monster()
{
}

void Monster::Update()
{
}

void Monster::Draw()
{
	////�����X�^�[��HP��\��
	//std::string monsterInfo = name + "[" + std::to_string(currentHP) + "/" + std::to_string(maxHP) + "]";
	//DrawString(100, 100, monsterInfo.c_str(), GetColor(255, 255, 255));

	//if (attackMessageTimer > 0)
	//{
	//	DrawString(100, 120, attackMessage.c_str(), GetColor(255, 255, 255));
	//	attackMessageTimer--;
	//}
}

//�_���[�W���󂯂��Ƃ��̏���
void Monster::TakeDamege(int damage)
{
	/*currentHP -= damage;
	if (currentHP < 0)
	{
		currentHP = 0;
	}

	std::string nameInfo = name + "[" + std::to_string(currentHP) + "/" + std::to_string(maxHP) + "]";
	DrawString(100, 100, nameInfo.c_str(), GetColor(255, 255, 255));*/
}

//�U���̏���
void Monster::Attack(Monster& target, std::string& skillName)
{
	/*int attackPower = skillList.GetPower(skillName);
	
	attackMessage = name + "��" + skillName + "!";
	attackMessageTimer = 60;

	target.TakeDamege(attackPower);*/
}

void Monster::AddSkill(const Skill& skill)
{
	skills.push_back(skill);
}

const std::string& Monster::GetName() const
{
	return name;
}

////���S�m�F
//bool Monster::IsDead() const
//{
//	/*return currentHP <= 0;*/
//}
