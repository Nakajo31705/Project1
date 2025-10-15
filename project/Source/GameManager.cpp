#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	if (currentState)
		currentState->Update();
}

void GameManager::Draw()
{
}

void GameManager::ChangeState(TurnState* newState)
{
	if (currentState)
	{
		currentState->Exit();
		delete currentState;
	}
		
	currentState = newState;
	if (currentState)
		currentState->Enter();
}
