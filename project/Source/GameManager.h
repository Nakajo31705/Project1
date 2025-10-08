#pragma once
#include "../Library/GameObject.h"
#include "Player.h"
#include "Enemy.h"


class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;
private:
	enum BattleState
	{
		Start,
		Player,
		Enemy,
		Change,
		Wait,
		Win,
		Lose
	};

	BattleState currentTurn;
	BattleState nextTurn;
};
