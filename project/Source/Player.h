#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "MonsterDataBase.h"


class Player : public GameObject
{
public:
	Player(MonsterDataBase& db);
	~Player();
	void Update();
	void Draw();

private:
	std::vector<Monster> monsters;
};
