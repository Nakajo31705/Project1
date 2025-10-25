#pragma once
#include "MonsterDataBase.h"

inline double GetTypeEffective(MonsterType attackType, MonsterType defendType)
{
	//タイプ相性表
	static const double typeChart[5][5] =
	{
		//受ける側のタイプ
		// 炎  水   草   光   闇
		{ 1.0, 0.5, 2.0, 1.0, 1.0 }, // 炎
		{ 2.0, 1.0, 0.5, 1.0, 1.0 }, // 水
		{ 0.5, 2.0, 1.0, 1.0, 1.0 }, // 草
		{ 1.0, 1.0, 1.0, 1.0, 2.0 }, // 光
		{ 1.0, 1.0, 1.0, 2.0, 1.0 }, // 闇
									 //攻撃側のタイプ
	};

	return typeChart[int(attackType)][int(defendType)];
}

inline std::string GetEffectiveMessage(double rate)
{
	if (rate > 1.0) return "効果は抜群！";
	if (rate < 1.0) return "効果はいまひとつ・・・";
}