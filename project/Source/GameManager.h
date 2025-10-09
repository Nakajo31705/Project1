#pragma once
#include "../Library/GameObject.h"
#include "TurnState.h"
#include "Player.h"
#include "Enemy.h"


class GameManager : public GameObject
{
public:
	GameManager();
	~GameManager();
	void Update() override;
	void Draw() override;

	void ChangeState(TurnState* newState);
private:
	TurnState* currentState = nullptr;
};
