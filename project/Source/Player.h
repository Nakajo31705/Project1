#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "KeyInput.h"
#include "LogManager.h"
#include "ActionRequest.h"

class MonsterDataBase;
class PlayerManager;
class Monster;
class Skill;
class PlayerTurnState;

class Player : public GameObject
{
public:
	Player(MonsterDataBase& db, LogManager* log,PlayerManager* pm);
	~Player();
	void Update() override;
	void Draw() override;

	//バトル場のモンスターを取得
	Monster* GetActiveMonster();

	//モンスターのチェンジ処理
	void SwitchMonster();
	void DeadMonsterSwitch();

	int FindNextAliveMonsterIndex();

	//-----スキル選択-----//
	
	//スキルの選択処理
	void SkillSelect();

	//スキル選択の終了フラグを取得
	bool GetSkillSelectEnd() const { return skillSelectEnd; }

	bool SetSkillSelectEnd(bool select) { skillSelectEnd = select; }

	Skill* GetSelectedSkill();

	//-----描画系-----//
	void SetLogManager(LogManager& log) { logManager = &log; }

	//-----Setter-----//
	void SetPlayerManager(PlayerManager* playerManager);
	void SetTurnState(PlayerTurnState* state);

	//-----初期化-----//
	void ResetPlayer();

private:
	//ポインタで保持
	PlayerTurnState* turnState;
	PlayerManager* pm;

	//モンスター
	int activeMonsterIndex = -1;			//バトル場のモンスター
	std::vector<Monster> monsters;			//自分のモンスター
	int selected = 0;						//PlayerTurnで選択されたメニューインデックスを保持

	//スキル
	int selectSkillIndex = 0;				//選択中のスキル番号
	int selectedSkillIndex;					//選択したスキル番号

	//行動確認フラグ
	bool skillSelectEnd = false;			//スキル選択終了フラグ
	bool monsterChangeEnd = false;			//モンスター交換の終了フラグ
	

	//描画用＆UI操作
	KeyInput input;							//キーボード入力管理
	LogManager* logManager;					//ログの出力
	bool startMonsterLog = false;
	int yOffset = 30;
	int monsterDrawX = 1000;
	int monsterDrawY = 500;
	int defDrawX = 560;
	int defDrawY = 600;
};
