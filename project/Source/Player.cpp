#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//�v���C���[���g�p���郂���X�^�[���w��
	std::vector<std::string> monsterNames = { "���̐���", "���̐���" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name));

		//�����X�^�[���ƂɋZ��ݒ�
		if (name == "���̐���")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			monster.SetSkills(skills);
		}

		else if (name == "���̐���")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("���U��", db.GetSkillPower("���U��")));
			skills.push_back(Skill("�ōU��", db.GetSkillPower("�ōU��")));
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

Player::~Player()
{
}

void Player::Update()
{
	
}

void Player::Draw()
{
	if (activeMonster) {
		std::string msg = activeMonster->GetName() + std::string("���o�g����ɂ�����\n");
		DrawString(defDraw, defDraw, msg.c_str(), GetColor(255, 255, 255));
	}
	else {
		DrawString(defDraw, defDraw, "activeMonster��Null�ł��B", GetColor(255, 255, 255));
	}
}

Monster* Player::GetActiveMonster()
{
	return activeMonster;
}

void Player::SwitchMonster()
{
	//�T���̃����X�^�[�̕\��
	for (int i = 0; i < reserveMonsters.size(); i++)
	{
		const Monster& monster = reserveMonsters[i];
		if (i == selectMonsterIndex)
		{
			DrawString(monsterDrawX, monsterDrawY + i * yOffset, "��", GetColor(255, 255, 0));
			DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, monster.GetName().c_str(), GetColor(255, 255, 0));
		}
		else
		{
			DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, monster.GetName().c_str(), GetColor(255, 255, 255));
		}
	}

	//�L�[���͂̔���
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		selectMonsterIndex--;
		if (selectMonsterIndex < 0) selectMonsterIndex = reserveMonsters.size() - 1;
		WaitTimer(150);
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		selectMonsterIndex++;
		if (selectMonsterIndex >= reserveMonsters.size()) selectMonsterIndex = 0;
		WaitTimer(150);
	}

	//����̏���
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		selectedMonster = &reserveMonsters[selectMonsterIndex];
		DrawString(defDraw, defDraw, (selectedMonster->GetName() + "��I��\n").c_str(), GetColor(255, 255, 255));
		WaitTimer(500);
	}

	if (selectedMonster != nullptr && activeMonster != nullptr)
	{
		//�o�g����̃����X�^�[���T���ɖ߂�
		reserveMonsters.push_back(*activeMonster);

		//�T������I�񂾃����X�^�[���폜
		reserveMonsters.erase(reserveMonsters.begin() + selectMonsterIndex);

		//�I�񂾃����X�^�[���o�g����ɐݒ�
		activeMonster = selectedMonster;

		//�C���f�b�N�X���Z�b�g
		selectMonsterIndex = 0;

		DrawString(defDraw, defDraw, (activeMonster->GetName() + "���o�g����ɏo����!\n").c_str(), GetColor(255, 255, 255));
		WaitTimer(500);
	}
}

void Player::SkillSelect()
{
	if (activeMonster != nullptr)
	{
		//�o�g����̃����X�^�[���g�p�ł���Z��\��
		std::vector<Skill> skills = activeMonster->GetSkills();
		for (int i = 0; skills.size(); i++)
		{
			const Skill& activeMonsterSkills = skills[i];
			if (i == selectSkillIndex)
			{
				DrawString(monsterDrawX, monsterDrawY + i * yOffset, "��", GetColor(255, 255, 0));
				DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, activeMonsterSkills.GetName().c_str(), GetColor(255, 255, 0));
			}
			else
			{
				DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, activeMonsterSkills.GetName().c_str(), GetColor(255, 255, 255));
			}
		}

		//�L�[���͂̔���
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			selectSkillIndex--;
			if (selectSkillIndex < 0) selectSkillIndex = skills.size() - 1;
			WaitTimer(150);
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			selectSkillIndex++;
			if (selectSkillIndex >= skills.size()) selectSkillIndex = 0;
			WaitTimer(150);
		}

		//����̏���
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			selectedSkill = &skills[selectSkillIndex];
			DrawString(defDraw, defDraw, (selectedSkill->GetName() + "��I��\n").c_str(), GetColor(255, 255, 255));
			WaitTimer(500);
		}
	}
	else
	{
		DrawString(10, 10, "�o�g����̃����X�^�[���ݒ肳��Ă��܂���B\n", GetColor(255, 255, 255));
	}
}


