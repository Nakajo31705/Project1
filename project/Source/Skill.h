#pragma once
#include <string>

enum class MonsterType;

class Skill
{
public:
	Skill(const std::string& _name, int _power, MonsterType _type);

	//威力を取得
	int GetPower() const;

	//技の威力を変更
	//void SetPower(int chnagedPower);

	//名前を取得
	std::string GetName() const;

	//タイプを取得
	MonsterType GetType() const;
private:
	std::string name;		//技名
	int power;				//威力
	MonsterType type;		//属性
};