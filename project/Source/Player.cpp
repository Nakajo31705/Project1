#include <iostream>
#include "Player.h"

Player::Player(MonsterDataBase& db)
{
	//プレイヤーが使用するモンスターを指定
	std::vector<std::string> monsterNames = { "剣士", "魔法使い" };

	for (const auto& name : monsterNames)
	{
		Monster monster(name, db.GetMonsterHP(name),db.GetType(name));

		//モンスターごとに技を設定
		if (name == "剣士")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("斬撃", db.GetSkillPower("斬撃"), MonsterType::Physical));
			monster.SetSkills(skills);
		}

		else if (name == "魔法使い")
		{
			std::vector<Skill> skills;
			skills.push_back(Skill("魔法", db.GetSkillPower("魔法"), MonsterType::Magic));
			monster.SetSkills(skills);
		}

		//控えのリストにモンスターを追加
		reserveMonsters.push_back(monster);
	}

	//控えリストの最初のモンスターをバトル場に設定
	if (!reserveMonsters.empty())
	{
		activeMonster = &reserveMonsters[0];
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

	//バトル場に出すモンスターの表示
	if (activeMonster) {
		std::string msg = activeMonster->GetName() + std::string("をバトル場にだした\n");
		DrawString(defDrawX, defDrawY, msg.c_str(), GetColor(255, 255, 255));
	}
	else {
		DrawString(defDrawX, defDrawY, "activeMonsterがNullです。", GetColor(255, 255, 255));
	}
}

// バトル場のモンスターを取得
Monster* Player::GetActiveMonster()
{
	return activeMonster;
}

void Player::SwitchMonster()
{
	//選んだモンスターじゃなくてreserveの先頭をactiveになるように変更する
	if (selected == 1 && activeMonster != nullptr)
	{
		//バトル場のモンスターを控えに戻す
		reserveMonsters.push_back(*activeMonster);

		//控えのモンスターをバトル場に設定
		if (!reserveMonsters.empty())
		{
			//控えの先頭をバトル場に設定
			activeMonster = &reserveMonsters.front();

			//控えの先頭を削除
			reserveMonsters.erase(reserveMonsters.begin());
		}

		SelectFinished();
		DrawString(defDrawX, defDrawY, (activeMonster->GetName() + "をバトル場に出した!\n").c_str(), GetColor(255, 255, 255));
		WaitTimer(500);
	}
}

void Player::SkillSelect(/*PlayerSubState &state*/)
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
			DrawString(defDrawX, defDrawY, (selectedSkill->GetName() + "を選択\n").c_str(), GetColor(255, 255, 255));
			
			
			Enemy* enemy = FindGameObject<Enemy>();
			Monster* currentEnemyMonster = enemy->GetActiveMonster();
			int typeValue = GetTypeEffective(selectedSkill->GetType(), currentEnemyMonster->GetType());
			currentEnemyMonster->TakeDamage(typeValue * selectedSkill->GetPower());

			SelectFinished();
			WaitTimer(500);
		}
	}
	else
	{
		DrawString(10, 10, "バトル場のモンスターが設定されていません。\n", GetColor(255, 255, 255));
	}
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


