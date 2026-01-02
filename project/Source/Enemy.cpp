#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(MonsterDataBase& db)
{
	Monster demonKing("魔王", db.GetMonsterHP("魔王"), db.GetMonsterPower("魔王"), db.GetType("物理"));
	{
		std::vector<Skill> skills;
		skills.push_back(Skill("斬撃", db.GetSkillPower("斬撃"), db.GetType("物理")));
		skills.push_back(Skill("魔法", db.GetSkillPower("魔法"), db.GetType("魔法")));
		demonKing.SetSkills(skills);
	}

	monsters.push_back(demonKing);

	//控えリストの最初のモンスターをバトル場に設定
	if (!monsters.empty())
	{
		activeMonster = &monsters.front();

		//ログ表示
		std::string logSwitchMonster = activeMonster->GetName() + "をバトル場に出した!\n";
		logManager.AddLog(logSwitchMonster.c_str(), defDrawX, defDrawY, 1000);
	}
	else {
		DrawString(defDrawX, defDrawY, "控えのモンスターは存在しません。", GetColor(255, 255, 255));
	}	
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{

}

void Enemy::Draw()
{
}

/// <summary>
/// エネミーのバトル場のモンスターを取得
/// </summary>
/// <returns></returns>
Monster* Enemy::GetActiveMonster()
{
	return activeMonster;
}

Skill* Enemy::GetSelectedSkill()
{
	return selectedSkill;
}

/// <summary>
/// エネミーのスキル選択の処理
/// (現在はランダムでやっている後で修正予定)
/// </summary>
/// <param name="player"></param>
/// <param name="enemy"></param>
void Enemy::SkillSelect(Monster* player, Monster* enemy)
{
	//エネミーのスキル取得
	std::vector<Skill> skills = enemy->GetSkills();
	
	//乱数生成器
	std::random_device rd;
	//ランダムエンジン
	static std::mt19937 gen(rd());
	//インデックス用
	std::uniform_int_distribution<> dis(0, skills.size() - 1);
	
	//ランダムに選択
	selectedSkill = &skills[dis(gen)];
}

/// <summary>
/// エネミーのカードの選択
/// </summary>
void Enemy::CardSelect()
{
}
