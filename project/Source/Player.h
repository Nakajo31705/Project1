#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "MonsterDataBase.h"


class Player : GameObject
{
public:
	Player(MonsterDataBase& db);
	~Player();
	void Update();
	void Draw();
	void IsDead();

private:
	std::vector<Monster> monsters;
};
