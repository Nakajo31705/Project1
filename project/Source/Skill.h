#pragma once
#include <string>

enum class MonsterType;

class Skill
{
public:
	Skill(const std::string& _name, int _power, MonsterType _type);

	//�З͂��擾
	int GetPower() const;

	//���O���擾
	std::string GetName() const;

	//�^�C�v���擾
	MonsterType GetType() const;
private:
	std::string name;		//�Z��
	int power;				//�З�
	MonsterType type;		//����
};