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
	void SwitchMonster();
	void SkillSelect();

private:
	Monster* activeMonster;					//�o�g����̃����X�^�[
	std::vector<Monster> reserveMonsters;	//�T���̃����X�^�[
	int selectMonsterIndex = 0;				//�I�𒆂̃����X�^�[�C���f�b�N�X
	Monster* selectedMonster = nullptr;		//�I�����������X�^�[

	std::vector<Skill> activeMonsterSKills;	//�o�g����̃����X�^�[�̃X�L��
	int selectSkillIndex = 0;				//�I�𒆂̃X�L���ԍ�
	Skill* selectedSkill = nullptr;			//�I�������X�L��

	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
