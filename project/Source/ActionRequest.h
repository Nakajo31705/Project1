#pragma once

class Monster;
class Skill;

// 行動リクエスト構造体
struct ActionRequest
{
	Monster* attacker;	// バトル場のモンスター
	Skill* skill;		// 選択したスキル
};