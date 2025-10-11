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

private:
	Monster* activeMonster;					//�o�g����̃����X�^�[
	std::vector<Monster> reserveMonsters;	//�T���̃����X�^�[
	int selectMonsterIndex = 0;				//�I�𒆂̃����X�^�[�C���f�b�N�X
	Monster* selectedMonster = nullptr;	//�I�����������X�^�[

	int selectedSkillIndex = 0;		//�I�𒆂̃X�L���ԍ�
	bool isSelectingSkill = false;	//�X�L���I�𒆂��m�F�p�t���O

	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
