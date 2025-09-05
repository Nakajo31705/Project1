#pragma once
#include "DxLib.h"
#include "../Library/GameObject.h"
#include <string>

class Monster : public GameObject
{
public:
	Monster(const std::string& _name, int _maxHP);
	~Monster();
	void Update() override;
	void Draw() override;

	void TakeDamege(int damage);
	void Attack(Monster& target);

	bool IsDead() const;
	const std::string& GetName();

private:
	std::string name;	//ñºëO
	int currentHP;		//åªç›ÇÃHP
	int maxHP;			//MAXHP
	int attackPower;	//çUåÇóÕ
};