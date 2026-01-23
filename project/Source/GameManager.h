#pragma once
#include "../Library/GameObject.h"
#include "TurnState.h"
#include "KeyInput.h"
#include "LogManager.h"
#include "MonsterDataBase.h"

class PlayerManager;
class EnemyManager;
class CardManager;
class Monster;
class PlayerTurnState;
class EnemyTurnState;
class Player;
class Enemy;
class Skill;

struct ActionRequest;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;
	LogManager& GetLogManager();

	//ターゲットの取得
	Monster& GetPlayerTarget();
	Monster& GetEnemyTarget();

	void ActionAttack(Skill& skill);

	//ターンの切り替え
	void ChangeState(TurnState* newState);
	TurnState* GetPlayerTurn();
	TurnState* GetEnemyTurn();
private:
	//初期化
	KeyInput input;
	LogManager log;
	MonsterDataBase MDB;
	int King;

	//ポインタで保持
	Player* player;					//プレイヤー
	Enemy* enemy;					//エネミー
	PlayerManager* playerManager;	//プレイヤーマネージャー
	EnemyManager* enemyManager;		//エネミーマネージャー
	Monster* monster;				//モンスター

	//ターン管理
	TurnState* currentState = nullptr;
	PlayerTurnState* playerTurn;
	EnemyTurnState* enemyTurn;

	CardManager* cardManager;
	bool turnEnd = false;
};
