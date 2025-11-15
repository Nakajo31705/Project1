#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "MonsterDataBase.h"
#include "Enemy.h"


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

	//変数の受け取り用
	void SetSelected(int value) { selected = value; }
	int GetSelected() const { return selected; }

private:
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> reserveMonsters;	//控えのモンスター
	int selectMonsterIndex = 0;				//選択中のモンスターインデックス
	Monster* selectedMonster = nullptr;		//選択したモンスター

	std::vector<Skill> activeMonsterSKills;	//バトル場のモンスターのスキル
	int selectSkillIndex = 0;				//選択中のスキル番号
	Skill* selectedSkill = nullptr;			//選択したスキル

	int selected = 0;

	//描画用
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDraw = 100;
};
