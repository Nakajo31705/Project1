#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "KeyInput.h"
#include "LogManager.h"
#include "ActionRequest.h"

class MonsterDataBase;
class CardDataBase;
class CardManager;
class PlayerManager;
class Monster;
class Skill;
class PlayerTurnState;

class Enemy;

class Player : public GameObject
{
public:
	Player(MonsterDataBase& db, LogManager* log);
	~Player();
	void Update() override;
	void Draw() override;

	//バトル場のモンスターを取得
	Monster* GetActiveMonster();

	//モンスターのチェンジ処理
	void SwitchMonster();

	//-----スキル選択-----//
	
	//スキルの選択処理
	void SkillSelect();

	//スキル選択の終了フラグを取得
	bool GetSkillSelectEnd() const { return skillSelectEnd; }

	bool SetSkillSelectEnd(bool select) { skillSelectEnd = select; }

	Skill* GetSelectedSkill();

	void SetTurnState(PlayerTurnState* pts);

	//-----カード選択-----//
	
	//カードの選択処理
	void CardSelect();

	//-----描画系-----//
	void SetLogManager(LogManager& log) { logManager = &log; }

	//-----Setter-----//
	void SetPlayerManager(PlayerManager* playerManager);

private:
	//モンスター
	int activeMonsterIndex = -1;			//バトル場のモンスター
	std::vector<Monster> monsters;			//自分のモンスター
	int selected = 0;						//PlayerTurnで選択されたメニューインデックスを保持

	//スキル
	int selectSkillIndex = 0;				//選択中のスキル番号
	int selectedSkillIndex;					//選択したスキル番号

	//行動確認
	bool skillSelectEnd = false;			//スキル選択終了フラグ
	bool monsterChangeEnd = false;			//モンスター交換の終了フラグ
	bool cardSelectEnd = false;				//カードの選択終了フラグ
	PlayerTurnState* turnState;
	PlayerManager* pm;
	

	//カード
	CardManager* cardManager;
	CardDataBase* CDB;
	int selectedCard;
	int selectCardIndex = 0;


	//描画用＆UI操作
	KeyInput input;							//キーボード入力管理
	LogManager* logManager;					//ログの出力
	bool startMonsterLog = false;
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 100;
	int defDrawY = 100;

	Enemy* enemy;
};
