#pragma once
#include "../Library/GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "KeyInput.h"
#include "CardManager.h"

class PlayerTurn;
class EnemyTurn;
class TurnState;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	//ターンの切り替え
	void ChangeState(TurnState* newState);

	//エネミーターンの取得
	EnemyTurn* GetEnemyTurn() const { return enemyTurn; }

	//プレイヤーターンの取得
	PlayerTurn* GetPlayerTurn() const { return playerTurn; }

	//現在のターンステートの取得
	bool GetTurnEnded() const { return turnEnd; }

	void CardSelect(int index);
private:
	Player* player;
	Enemy* enemy;
	EnemyTurn* enemyTurn = nullptr;
	PlayerTurn* playerTurn = nullptr;
	TurnState* currentState = nullptr;
	CardManager* cardManager;
	KeyInput input;
	bool turnEnd = false;
};
