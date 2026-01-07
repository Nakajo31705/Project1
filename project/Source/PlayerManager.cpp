#include "PlayerManager.h"
#include "GameManager.h"

PlayerManager::PlayerManager()
	:selected(0)
{
}

void PlayerManager::Update()
{
	input.Update();
}

/// <summary>
/// メニューの選択画面
/// </summary>
MenuCommand PlayerManager::Menu()
{
	const int MENU_NUM = 3;
	const char* menu[MENU_NUM] = { "技を選択", "モンスターを交換" ,"カードの選択"};
	int yOffset = 30;

	//メニューの表示
	for (int i = 0; i < MENU_NUM; i++)
	{
		if (i == selected)
		{
			//→表示
			DrawString(menuDrawX, menuDrawY + i * yOffset, "→", GetColor(255, 255, 0));
			DrawString(menuDrawX+20, menuDrawY + i * yOffset, menu[i], GetColor(255, 255, 0));
		}
		else
		{
			DrawString(menuDrawX+20, menuDrawY + i * yOffset, menu[i], GetColor(255, 255, 255));
		}
	}

	//キーの入力判定(メニュー)
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		selected--;
		if (selected < 0) selected = MENU_NUM - 1;
		WaitTimer(150);	//キーリピート対策
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		selected++;
		if (selected >= MENU_NUM) selected = 0;
		WaitTimer(150);	//キーリピート対策
	}

	//コマンド決定の処理(メニュー)
	if (input.isJustReleased(KEY_INPUT_RETURN) == 1)
	{
		if (selected == 0)
		{
			log.AddLog("技を選択", defDrawX, defDrawY*2, 1000);
			return MenuCommand::SkillSelect;
		}
		else if (selected == 1)
		{
			log.AddLog("モンスターを交換", defDrawX, defDrawY * 2, 1000);
			return MenuCommand::MonsterSwitch;
		}
		else if (selected == 2)
		{
			log.AddLog("カードの選択", defDrawX, defDrawY * 2, 1000);
			return MenuCommand::CardSelect;
		}
		return MenuCommand::None;
	}
}

/// <summary>
/// 攻撃の情報を取得し、リクエストを作成する
/// </summary>
/// <returns></returns>
ActionRequest PlayerManager::RequestAttack()
{
	ActionRequest request;
	request.attacker = player->GetActiveMonster();
	request.skill = player->GetSelectedSkill();
	return request;
}

/// <summary>
/// バトル場のモンスターを取得する
/// </summary>
/// <returns></returns>
Monster* PlayerManager::GetActiveMonster()
{
	if (!player) return nullptr;
	return player->GetActiveMonster();
}