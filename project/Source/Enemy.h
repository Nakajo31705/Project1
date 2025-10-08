#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include <iostream>
#include "MonsterDataBase.h"


class Enemy : public GameObject
{
public:
	Enemy(MonsterDataBase& db);
	~Enemy();
	void Update() override;
	void Draw() override;
private:
	std::vector<Monster> monsters;
};
