#pragma once
#include "../Library/GameObject.h"
#include "TurnState.h"
#include "CardManager.h"
#include "KeyInput.h"

class PlayerManager;
class EnemyManager;
class Monster;
class PlayerTurnState;
class EnemyTurnState;

struct ActionRequest;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	//情報に合わせてターンを切り替える
	void ResolveTurn();

	//ターゲットの取得
	Monster& GetPlayerTarget();
	Monster& GetEnemyTarget();

	void ActionAttack(ActionRequest& req, Monster& target);

	//ターンの切り替え
	void ChangeState(TurnState* newState);
	TurnState* GetPlayerTurn();
	TurnState* GetEnemyTurn();

private:
	//初期化
	KeyInput input;
	LogManager log;

	//ポインタで保持
	PlayerManager* playerManager;	//プレイヤー
	EnemyManager* enemyManager;		//エネミー
	Monster* monster;				//モンスター

	//ターン管理
	TurnState* currentState = nullptr;
	PlayerTurnState* playerTurn;
	EnemyTurnState* enemyTurn;

	CardManager* cardManager;
	bool turnEnd = false;
};
