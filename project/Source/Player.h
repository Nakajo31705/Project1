#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "MonsterDataBase.h"


class Player : public GameObject
{
public:
	Player(MonsterDataBase& db);
	~Player();
	void Update() override;
	void Draw() override;

	Monster* GetActiveMonster();
	void SwitchMonster(int index);

private:
	std::vector<Monster> monsters;
	Monster* activeMoster;
	std::vector<Monster> reserveMonsters;

	int selectedSkillIndex = 0;		//�I�𒆂̃X�L���ԍ�
	bool isSelectingSkill = false;	//�X�L���I�𒆂��m�F�p�t���O
};
