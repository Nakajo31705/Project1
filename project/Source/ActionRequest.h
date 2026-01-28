#pragma once

class Monster;
class Skill;

// 行動リクエスト構造体
struct ActionRequest
{
	Monster* attacker = nullptr;	// バトル場のモンスター
	Monster* target = nullptr;	//ターゲットのモンスター
	Skill* skill = nullptr;		// 選択したスキル

	void RestRequest()
	{
		attacker = nullptr;
		target = nullptr;
		skill = nullptr;
	}

	void SetRequest(Monster* atk, Monster* tgt, Skill* skl)
	{
		attacker = atk;
		target = tgt;
		skill = skl;
	}

	bool IsValid() const
	{
		return attacker != nullptr && target != nullptr && skill != nullptr;
	}
};


