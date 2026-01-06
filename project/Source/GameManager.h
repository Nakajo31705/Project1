#pragma once
#include "../Library/GameObject.h"
#include "TurnState.h"
#include "KeyInput.h"
#include "CardManager.h"

class PlayerManager;
class EnemyManager;
class Monster;

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
	//この辺修正する-----------------------------------------
	TurnState* GetPlayerTurn() { return playerTurn; }
	TurnState* GetEnemyTurn() { return enemyTurn; }

private:
	//初期化
	KeyInput input;
	LogManager log;

	PlayerManager* playerManager;	//プレイヤー
	EnemyManager* enemyManager;		//エネミー
	Monster* monster;				//モンスター

	TurnState* currentState = nullptr;
	TurnState* playerTurn;
	TurnState* enemyTurn;
	CardManager* cardManager;
	bool turnEnd = false;
};
