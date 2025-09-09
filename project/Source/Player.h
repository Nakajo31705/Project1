#pragma once
#include "../Library/GameObject.h"
#include "Monster.h"

class Player : GameObject
{
	Player();
	~Player();
	void Update();
	void Draw();

	void IsDead();
};
