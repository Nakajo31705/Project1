#include "GameManager.h"

GameManager::GameManager()
{
	currentTurn = BattleState::Player;
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	switch (currentTurn)
	{
	case BattleState::Start:
		nextTurn = BattleState::Player;
		break;
	}

	
}

void GameManager::Draw()
{
}
