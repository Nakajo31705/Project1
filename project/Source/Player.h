#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "LogManager.h"
#include "CardManager.h"
#include "MonsterDataBase.h"
#include "CardDataBase.h"
#include "Enemy.h"
#include "PlayerObserver.h"
#include "KeyInput.h"


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
	void CardSelect();
	void AddListener(PlayerObserver* listener);
	void SelectedCard();

	//変数の受け取り用
	void SetSelected(int value) { selected = value; }
	int GetSelected() const { return selected; }

private:
	Enemy enemy;
	Monster* activeMonster;					//バトル場のモンスター
	std::vector<Monster> monsters;			//自分のモンスター
	int selectMonsterIndex = 0;				//選択中のモンスターインデックス
	Monster* selectedMonster = nullptr;		//選択したモンスター
	int selected = 0;						//PlayerTurnで選択されたメニューインデックスを保持

	int selectSkillIndex = 0;				//選択中のスキル番号
	Skill* selectedSkill = nullptr;			//選択したスキル
	std::vector<PlayerObserver*> listeners;	//オブザーバーリスト
	KeyInput input;							//キーボード入力管理

	void SelectFinished();					//選択終了の通知

	//カード系
	CardManager* cardManager;
	CardDataBase* cardDB;
	int selectCardIndex = 0;
	CardData* selectedCard = nullptr;


	//描画用
	LogManager logManager;
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 100;
};
