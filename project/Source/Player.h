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
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> reserveMonsters;	//控えのモンスター
	int selectMonsterIndex = 0;				//選択中のモンスターインデックス
	Monster* selectedMonster = nullptr;		//選択したモンスター

	std::vector<Skill> activeMonsterSKills;	//バトル場のモンスターのスキル
	int selectSkillIndex = 0;				//選択中のスキル番号
	Skill* selectedSkill = nullptr;			//選択したスキル

	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
