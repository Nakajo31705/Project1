#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "Monster.h"
#include "Skill.h"


class Player : GameObject
{
public:
	Player(const std::vector<Monster>& _monster);
	~Player();
	void Update();
	void Draw();

	void IsDead();

	Monster& GetActiveMonster();
	void SwitchMonster(int newIndex);

private:
	std::vector<Monster> myMonster;	//���ׂẴ����X�^�[
	std::vector<Skill> mySkills;	//�g����X�L��
	int activeIndex;				//���݃o�g�����̃����X�^�[
};
