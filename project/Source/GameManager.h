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
class Player;
class Enemy;
class Skill;
class TurnManager;

struct ActionRequest;

class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;
	LogManager& GetLogManager();

	void ActionAttack(Skill& skill);
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
	TurnManager* turnManager;		//ターンマネージャー
};
