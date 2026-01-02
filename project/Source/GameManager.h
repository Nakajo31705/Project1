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

private:
	PlayerManager* playerManager;	//プレイヤー
	EnemyManager* enemyManager;		//エネミー
	Monster* monster;				//モンスター


	TurnState* currentState = nullptr;
	CardManager* cardManager;
	KeyInput input;
	bool turnEnd = false;
};
