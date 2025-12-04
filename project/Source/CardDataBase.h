#pragma once
#include <string>
#include <vector>

//カードの効果
enum class CardEfect
{
	AttackUP,
	DefenseUP,
	Heal,
	AddType,
	None
};

//効果の情報
struct EffectInfo
{
	CardEfect efect;
	float value;
	int duration;
	int type;
};

//カードの種類
enum class CardType
{
	Buff,
	Heal,
	Emchant
};

//カードのデータ
struct CardData
{
	int id;							//ID
	std::string name;				//カードの名前
	CardType cardType;				//カードの種類
	int type;						//属性
	std::vector<EffectInfo> info;	//効果の情報
	std::string description;		//説明文

};

class CardDataBase
{
	CardDataBase();

};
