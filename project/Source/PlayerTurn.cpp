#include "PlayerTurn.h"

PlayerTurn::PlayerTurn(GameManager* gm)
	:gameManager(gm) {
}

void PlayerTurn::Enter()
{
	DrawString(100, 100, "プレイヤーのターン", GetColor(255, 255, 255));
}

void PlayerTurn::Update()
{
	switch (subState)
	{
	case PlayerSubState::MenuSelect:
		Menu();
		break;
	case PlayerSubState::SkillSelect:
		break;
	case PlayerSubState::MonsterSelect:
		break;
	case PlayerSubState::Done:
		//行動完了時はこんな感じで書く
	// gamaManager->ChangeState(new EnemyTurn(gameManager));
		break;
	}
}

void PlayerTurn::Exit()
{
	DrawString(100, 100, "プレイヤーのターン終了", GetColor(255, 255, 255));
}

void PlayerTurn::Menu()
{
	const int MENU_NUM = 2;
	const char* menu[MENU_NUM] = { "技を選択", "モンスターを交換" };

	//メニューの表示
	for (int i = 0; i < MENU_NUM; i++)
	{
		if (i == selected)
		{
			//→表示
			DrawString(1300, 500 + i * 30, "→", GetColor(255, 255, 0));
			DrawString(1320, 500 + i * 30, menu[i], GetColor(255, 255, 0));
		}
		else
		{
			DrawString(1320, 500 + i * 30, menu[i], GetColor(255, 255, 255));
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
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		if (selected == 0)
		{
			DrawString(100, 200, "技を選択", GetColor(255, 255, 255));
		}
		else if (selected == 1)
		{
			DrawString(100, 200, "モンスターを交換", GetColor(255, 255, 255));
		}
		WaitTimer(500);
	}
}

void PlayerTurn::SkillSelect()
{
}

void PlayerTurn::MonsterSelect()
{
}