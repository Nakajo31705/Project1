#pragma once
#include "MonsterDataBase.h"

inline double GetTypeEffective(MonsterType attackType, MonsterType defendType)
{
	//�^�C�v�����\
	static const double typeChart[5][5] =
	{
		//�󂯂鑤�̃^�C�v
		// ��  ��   ��   ��   ��
		{ 1.0, 0.5, 2.0, 1.0, 1.0 }, // ��
		{ 2.0, 1.0, 0.5, 1.0, 1.0 }, // ��
		{ 0.5, 2.0, 1.0, 1.0, 1.0 }, // ��
		{ 1.0, 1.0, 1.0, 1.0, 2.0 }, // ��
		{ 1.0, 1.0, 1.0, 2.0, 1.0 }, // ��
									 //�U�����̃^�C�v
	};

	return typeChart[int(attackType)][int(defendType)];
}

inline std::string GetEffectiveMessage(double rate)
{
	if (rate > 1.0) return "���ʂ͔��Q�I";
	if (rate < 1.0) return "���ʂ͂��܂ЂƂE�E�E";
}