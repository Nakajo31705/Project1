#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "LogManager.h"
#include "CardManager.h"
#include "MonsterDataBase.h"
#include "CardDataBase.h"
#include "KeyInput.h"
#include "SubjectBase.h"
#include "ActionAttack.h"

class Player : public GameObject
{
public:
	Player(MonsterDataBase& db);
	~Player();
	void Update() override;
	void Draw() override;

	//バトル場のモンスターを取得
	int GetActiveMonster();

	//モンスターのチェンジ処理
	void SwitchMonster();

	//////////////////////////////////
	/*----------スキル選択----------*/
	//////////////////////////////////
	
	//スキルの選択処理
	void SkillSelect();

	//スキル選択の終了フラグを取得
	bool GetSkillSelectEnd() const { return skillSelectEnd; }

	bool SetSkillSelectEnd(bool select) { skillSelectEnd = select; }

	Skill* GetSelectedSkill() const { return selectedSkill; }

	//////////////////////////////////
	/*----------カード選択----------*/
	//////////////////////////////////
	
	//カードの選択処理
	void CardSelect();


	//変数の受け取り用
	void SetSelected(int value) { selected = value; }
	int GetSelected() const { return selected; }

private:
	int activeMonsterIndex = -1;					//バトル場のモンスター
	std::vector<Monster> monsters;			//自分のモンスター
	int selectMonsterIndex = 0;				//選択中のモンスターインデックス
	Monster* selectedMonster = nullptr;		//選択したモンスター
	int selected = 0;						//PlayerTurnで選択されたメニューインデックスを保持

	int selectSkillIndex = 0;				//選択中のスキル番号
	Skill* selectedSkill = nullptr;			//選択したスキル
	KeyInput input;							//キーボード入力管理

	bool skillSelectEnd = false;			//スキル選択の終了フラグ

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
