#pragma once
#include "../Library/GameObject.h"

class GameManager;
class TurnState
{
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
	virtual ~TurnState() = default;
};
