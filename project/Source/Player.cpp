#include "Player.h"
#include "Monster.h"
#include "MonsterDataBase.h"
#include "Skill.h"
#include "PlayerTurnState.h"
#include <cassert>
#include "PlayScene.h"

#include "Enemy.h"

Player::Player(MonsterDataBase& db, LogManager* log, PlayerManager* pm)
	:logManager(log), pm(pm)
{
	//モンスターに技を設定＆monstersリストに追加
	//剣士の設定
	Monster swordMan("剣士", db.GetMonsterHP("剣士"),db.GetMonsterPower("剣士"), db.GetType("物理"));
	{
		std::vector<Skill> skills;
		skills.push_back(Skill("斬撃", db.GetSkillPower("斬撃"), db.GetType("物理")));
		skills.push_back(Skill("大斬撃", db.GetSkillPower("大斬撃"), db.GetType("物理")));
		swordMan.SetSkills(skills);
	}
	monsters.push_back(swordMan);

	//魔法使いの設定
	Monster wizard("魔法使い", db.GetMonsterHP("魔法使い"), db.GetMonsterPower("魔法使い"), db.GetType("魔法"));
	{
		std::vector<Skill> skills;
		skills.push_back(Skill("魔法", db.GetSkillPower("魔法"), db.GetType("魔法")));
		skills.push_back(Skill("大魔法", db.GetSkillPower("大魔法"), db.GetType("魔法")));
		wizard.SetSkills(skills);
	}
	monsters.push_back(wizard);

	//控えリストの最初のモンスターをバトル場に設定&表示
	if (!monsters.empty())
	{
		activeMonsterIndex = 0;
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
	if (!startMonsterLog)
	{
		std::string logFirstMonster = monsters[activeMonsterIndex].GetName() + "をバトル場にだした\n";
		assert(logManager != nullptr);
		logManager->AddLog(logFirstMonster, defDrawX, defDrawY, 1000);
		startMonsterLog = true;
	}
	else if(monsters.empty())
	{
		DrawString(defDrawX, defDrawY, "控えのモンスターは存在しません。", GetColor(255, 255, 255));
	}
}

/// <summary>
/// バトル場のモンスターを取得
/// </summary>
/// <returns></returns>
Monster* Player::GetActiveMonster()
{
	return &monsters[activeMonsterIndex];
}

/// <summary>
/// 選択した技を取得
/// </summary>
/// <returns></returns>
Skill* Player::GetSelectedSkill()
{
	Monster* monster = GetActiveMonster();
	if (!monster) return nullptr;

	const auto& skills = monster->GetSkills();

	if (selectedSkillIndex < 0 || selectedSkillIndex >= skills.size()) return nullptr;

	return const_cast<Skill*>(&skills[selectedSkillIndex]);
}

/// <summary>
/// バトル場と控えのモンスターを交換 
/// </summary>
void Player::SwitchMonster()
{
	if (monsterChangeEnd)
	{
		logManager->AddLog("モンスターはすでに交換されています。", defDrawX, defDrawY, 1000);
		pm->Menu();
		return;
	}

	int nextIndex = FindNextAliveMonsterIndex();

	if (nextIndex == -1)
	{
		logManager->AddLog("控えのモンスターがいません。", defDrawX, defDrawY, 1000);
		pm->Menu();
		return;
	}
	
	//バトル場のモンスターを入れ替え
	activeMonsterIndex = nextIndex;

	//スキルの選択状態をリセット
	selectSkillIndex = 0;
	selectedSkillIndex = -1;

	//ログ表示
	std::string logSwitchMonster = monsters[activeMonsterIndex].GetName() + "をバトル場に出した!\n";
	logManager->AddLog(logSwitchMonster.c_str(), defDrawX, defDrawY, 1000);

	monsterChangeEnd = true;
	turnState->SelectEnd();
}

/// <summary>
/// モンスターが倒れたときに控えのモンスターと交換
/// </summary>
void Player::DeadMonsterSwitch()
{
	int nextIndex = FindNextAliveMonsterIndex();
	if (nextIndex == -1)
	{
		logManager->AddLog("すべてのモンスターが倒れた!", defDrawX, defDrawY, 1000);
		SceneManager::ChangeScene("GameOverScene");
		return;
	}
	//バトル場のモンスターを入れ替え
	activeMonsterIndex = nextIndex;

	//スキルの選択状態をリセット
	selectSkillIndex = 0;
	selectedSkillIndex = -1;
	//ログ表示
	std::string logSwitchMonster = monsters[activeMonsterIndex].GetName() + "をバトル場に出した!\n";
	logManager->AddLog(logSwitchMonster.c_str(), defDrawX, defDrawY, 1000);
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int Player::FindNextAliveMonsterIndex()
{
	if (monsters.empty()) return -1;

	int size = monsters.size();
	int index = activeMonsterIndex;

	for (int i = 0; i < size; i++)
	{
		index = (index + 1) % size;
		if (!monsters[index].IsDead())
		{
			return index;
		}
	}
	return -1;
}

/// <summary>
/// 技の選択
/// </summary>
void Player::SkillSelect()
{
	if (skillSelectEnd)
	{
		logManager->AddLog("攻撃できるのは1ターンに１度限りです。", defDrawX, defDrawY, 1000);
		pm->Menu();
		return;
	}

	Monster* monster = GetActiveMonster();
	if (!monster) return;

	//バトル場のモンスターが使用できる技を表示
	const auto& skills = monster->GetSkills();
	if (skills.empty()) return;

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
	if (input.isJustReleased(KEY_INPUT_UP) == 1)
	{
		selectSkillIndex--;
		if (selectSkillIndex < 0) selectSkillIndex = skills.size() - 1;
		WaitTimer(150);
	}
	if (input.isJustReleased(KEY_INPUT_DOWN) == 1)
	{
		selectSkillIndex++;
		if (selectSkillIndex >= skills.size()) selectSkillIndex = 0;
		WaitTimer(150);
	}

	//決定の処理
	if (input.isJustReleased(KEY_INPUT_RETURN) == 1)
	{
		selectedSkillIndex = selectSkillIndex;

		std::string logSkillSelected = skills[selectedSkillIndex].GetName() + "を選択\n";
		logManager->AddLog(logSkillSelected.c_str(), defDrawX, defDrawY, 1000);
		pm->RequestAttack(*GetSelectedSkill());
		assert(turnState && "playerTurn is nullptr before calling SelectEnd");
		turnState->SelectEnd();
	}
}

void Player::SetPlayerManager(PlayerManager* playerManager)
{
	pm = playerManager;
}

void Player::SetTurnState(PlayerTurnState* state)
{
	turnState = state;
}

/// <summary>
/// 選択したものをリセット
/// </summary>
void Player::ResetPlayer()
{
	skillSelectEnd = false;
	monsterChangeEnd = false;

	selectSkillIndex = 0;
	selectedSkillIndex = -1;
}
