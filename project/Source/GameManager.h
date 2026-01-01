#pragma once
#include "../Library/GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TurnState.h"
#include "KeyInput.h"
#include "CardManager.h"

class PlayerTurn;
class EnemyTurn;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	//ターンの切り替え
	void ChangeState(TurnState* newState);

	//-----取得系-----//

	//プレイヤーの取得
	Player* GetPlayer() { return player; }

	//エネミーの取得
	Enemy* GetEnemy() { return enemy; }

	//モンスターリストの取得
	Monster* GetMonstser() { return monster; }

private:
	Player* player;				//プレイヤー
	Enemy* enemy;				//エネミー
	Monster* monster;			//モンスターリスト

	//-----ターン系-----//
	std::unique_ptr<PlayerTurn> playerTurn;	//プレイヤーターン
	std::unique_ptr<EnemyTurn> enemyTurn;	//エネミーターン
	TurnState* currentState = nullptr;


	CardManager* cardManager;
	KeyInput input;
	bool turnEnd = false;
	std::vector<Action*> actionQueue;

};
