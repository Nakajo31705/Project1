#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//モンスターに技を設定＆monstersリストに追加

	//剣士の設定
	Monster swordMan("剣士", db.GetMonsterHP("剣士"), db.GetType("物理"));
	{
		std::vector<Skill> skills;
		skills.push_back(Skill("斬撃", db.GetSkillPower("斬撃"), db.GetType("物理")));
		swordMan.SetSkills(skills);
	}
	monsters.push_back(swordMan);

	//魔法使いの設定
	Monster wizard("魔法使い", db.GetMonsterHP("魔法使い"), db.GetType("魔法"));
	{
		std::vector<Skill> skills;
		skills.push_back(Skill("魔法", db.GetSkillPower("魔法"), db.GetType("魔法")));
		wizard.SetSkills(skills);
	}
	monsters.push_back(wizard);

	//控えリストの最初のモンスターをバトル場に設定
	if (!monsters.empty() && activeMonster == nullptr)
	{
		activeMonster = &monsters[0];
	}

	//バトル場に出すモンスターの表示
	if (activeMonster) {
		std::string logFirstMonster = activeMonster->GetName() + std::string("をバトル場にだした\n");
		//DrawString(defDrawX, defDrawY, msg.c_str(), GetColor(255, 255, 255));
		logManager.AddLog(logFirstMonster.c_str(), defDrawX, defDrawY, 1000);
	}
	else {
		DrawString(defDrawX, defDrawY, "activeMonsterがNullです。", GetColor(255, 255, 255));
	}
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
}

/// <summary>
/// バトル場のモンスターを取得
/// </summary>
/// <returns></returns>
Monster* Player::GetActiveMonster()
{
	return activeMonster;
}

/// <summary>
/// バトル場と控えのモンスターを交換 
/// </summary>
void Player::SwitchMonster()
{
	//reserveの先頭をactiveにする
	if (selected == 1 && activeMonster != nullptr)
	{
		//バトル場のモンスターを控えに戻す
		monsters.push_back(*activeMonster);

		//控えのモンスターをバトル場に設定
		if (!monsters.empty())
		{
			//控えの先頭をバトル場に設定
			activeMonster = &monsters.front();

			//控えの先頭を削除
			monsters.erase(monsters.begin());
		}

		//交換終了
		SelectFinished();

		//ログ表示
		std::string logSwitchMonster = activeMonster->GetName() + "をバトル場に出した!\n";
		logManager.AddLog(logSwitchMonster.c_str(), defDrawX, defDrawY, 1000);
	}
}

/// <summary>
/// 技の選択
/// </summary>
void Player::SkillSelect()
{
	if (activeMonster != nullptr)
	{
		//バトル場のモンスターが使用できる技を表示
		std::vector<Skill> skills = activeMonster->GetSkills();
		for (int i = 0; i < skills.size(); i++)
		{
			const Skill& activeMonsterSkills = skills[i];
			if (i == selectSkillIndex)
			{
				DrawString(monsterDrawX, monsterDrawY + i * yOffset, "→", GetColor(255, 255, 0));
				DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, activeMonsterSkills.GetName().c_str(), GetColor(255, 255, 0));
			}
			else
			{
				DrawString(monsterDrawX + 20, monsterDrawY + i * yOffset, activeMonsterSkills.GetName().c_str(), GetColor(255, 255, 255));
			}
		}

		//キー入力の判定
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			selectSkillIndex--;
			if (selectSkillIndex < 0) selectSkillIndex = skills.size() - 1;
			WaitTimer(150);
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			selectSkillIndex++;
			if (selectSkillIndex >= skills.size()) selectSkillIndex = 0;
			WaitTimer(150);
		}

		//決定の処理
		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			selectedSkill = &skills[selectSkillIndex];
			std::string logSkillSelected = selectedSkill->GetName() + "を選択\n";
			logManager.AddLog(logSkillSelected.c_str(), defDrawX, defDrawY, 1000);
			
			//攻撃対象の取得
			Enemy* enemy = FindGameObject<Enemy>();
			Monster* activeEnemyMonster = enemy->GetActiveMonster();
			int index = selectSkillIndex;

			//攻撃対象と攻撃した技を引数として返し攻撃する
			activeMonster->Attack(*activeEnemyMonster, skills[index]);

			//技選択終了
			SelectFinished();
		}
	}
	else
	{
		DrawString(100, 100, "バトル場のモンスターが設定されていません。\n", GetColor(255, 255, 255));
	}
}

/// <summary>
/// カードの選択
/// </summary>
void Player::CardSelect()
{
}

/// <summary>
/// listenerコンテナに追加する関数:
/// 追加されたlistenerはプレイヤーの処理終了の通知を受け取れるようになる
/// </summary>
/// <param name="listener"></param>
void Player::AddListener(PlayerObserver* listener)
{
	listeners.push_back(listener);
}


/// <summary>
/// プレイヤーの選択が終了したことを通知する
/// </summary>
void Player::SelectFinished()
{
	for (auto* l : listeners)
	{
		l->SelectEnd();
	}
}


