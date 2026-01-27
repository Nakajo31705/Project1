#include "Enemy.h"
#include "Player.h"
#include "EnemyTurnState.h"
#include <cassert>

Enemy::Enemy(MonsterDataBase& db, LogManager* log,EnemyManager* em)
	:logManager(log), em(em)
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
		activeMonsterIndex = 0;
	}
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!startMonsterLog)
	{
		//ログ表示
		std::string logSwitchMonster = monsters[activeMonsterIndex].GetName() + "をバトル場に出した!\n";
		assert(logManager != nullptr);
		logManager->AddLog(logSwitchMonster.c_str(), defDrawX, defDrawY, 1000);
		startMonsterLog = true;
	}
	else if(monsters.empty())
	{
		DrawString(defDrawX, defDrawY, "控えのモンスターは存在しません。", GetColor(255, 255, 255));
	}
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
	return &monsters[activeMonsterIndex];
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
void Enemy::SkillSelect()
{
	//エネミーのスキル取得
	const auto&  skills = monsters[activeMonsterIndex].GetSkills();
	
	//乱数生成器
	std::random_device rd;
	//ランダムエンジン
	static std::mt19937 gen(rd());
	//インデックス用
	std::uniform_int_distribution<> dis(0, skills.size() - 1);
	
	//ランダムに選択
	selectedSkill = const_cast<Skill*>(&skills[dis(gen)]);
	em->RequestAttack(*GetSelectedSkill());
	WaitTimer(1000);
	turnState->SelectEnd();
}

/// <summary>
/// 選択したものをリセットする関数
/// </summary>
void Enemy::ResetEnemy()
{
	selectedSkill = nullptr;
}

void Enemy::SetTurnState(EnemyTurnState* state)
{
	turnState = state;
}
