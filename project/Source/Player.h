#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "LogManager.h"
#include "CardManager.h"
#include "MonsterDataBase.h"
#include "CardDataBase.h"
#include "KeyInput.h"
#include "SubjectBase.h"


class Player : public GameObject, public SubjectBase
{
public:
	Player(MonsterDataBase& db);
	~Player();
	void Update() override;
	void Draw() override;

	//バトル場のモンスターを取得
	Monster* GetActiveMonster();

	//モンスターのチェンジ処理
	void SwitchMonster();

	//スキルの選択処理
	void SkillSelect();

	//カードの選択処理
	void CardSelect();

	//変数の受け取り用
	void SetSelected(int value) { selected = value; }
	int GetSelected() const { return selected; }

private:
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> monsters;			//自分のモンスター
	int selectMonsterIndex = 0;				//選択中のモンスターインデックス
	Monster* selectedMonster = nullptr;		//選択したモンスター
	int selected = 0;						//PlayerTurnで選択されたメニューインデックスを保持

	int selectSkillIndex = 0;				//選択中のスキル番号
	Skill* selectedSkill = nullptr;			//選択したスキル
	KeyInput input;							//キーボード入力管理

	//カード系
	CardManager* cardManager;
	int selectCardIndex = 0;
	const CardData* selectedCard;



	//描画用
	LogManager logManager;
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 100;
};
