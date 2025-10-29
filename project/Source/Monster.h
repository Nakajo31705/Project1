#pragma once
#include <iostream>
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>
#include <vector>
#include "Skill.h"

enum class MonsterType;

class Monster : public GameObject
{
public:
	Monster(std::string _name, int _maxHP, MonsterType _type);
	~Monster();
	void Update() override;
	void Draw() override;

	//�U���̏���
	void Attack(Monster& target, const Skill& _skill);

	//�U�����󂯂鏈��
	void TakeDamage(int _damage);

	//�����X�^�[�����擾
	std::string GetName() const;

	//���݂�HP���擾
	int GetCurrentHP() const;

	//�X�L�����擾
	const std::vector<Skill>& GetSkills() const;

	//�X�L�����Z�b�g
	void SetSkills(const std::vector<Skill>& _skills);

	//�^�C�v���擾
	MonsterType GetType() const;

private:
	std::string name;
	int maxHP;
	int currentHP;
	MonsterType type;

	std::vector<Skill> skills;

};