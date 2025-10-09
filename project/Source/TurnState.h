#pragma once

class TurnState
{
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
	virtual ~TurnState() = default;
};
