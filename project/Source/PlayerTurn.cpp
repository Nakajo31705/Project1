#include "PlayerTurn.h"

PlayerTurn::PlayerTurn(GameManager* gm)
	:gameManager(gm)
{
	player = FindGameObject<Player>();
}

void PlayerTurn::Enter()
{
	myTurn = true;
	DrawString(defDraw, defDraw, "プレイヤーのターン", GetColor(255, 255, 255));
}

void PlayerTurn::Update()
{
	if (!myTurn) return;
	switch (subState)
	{
	case PlayerSubState::MenuSelect:
		Menu();
		break;
	case PlayerSubState::SkillSelect:
		player->SkillSelect();
		break;
	case PlayerSubState::MonsterSelect:
		player->SwitchMonster();
		break;
	case PlayerSubState::Done:
		gameManager->ChangeTurn();
		myTurn = false;
		break;
	}
}

void PlayerTurn::Exit()
{
	DrawString(defDraw, defDraw, "プレイヤーのターン終了", GetColor(255, 255, 255));
}

void PlayerTurn::Menu()
{
	const int MENU_NUM = 2;
	const char* menu[MENU_NUM] = { "技を選択", "モンスターを交換" };
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
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		if (selected == 0)
		{
			DrawString(defDraw, defDraw*2, "技を選択", GetColor(255, 255, 255));
			subState = PlayerSubState::SkillSelect;
			
		}
		else if (selected == 1)
		{
			player->SetSelected(selected);
			DrawString(defDraw, defDraw*2, "モンスターを交換", GetColor(255, 255, 255));
			subState = PlayerSubState::MonsterSelect;
		}
		WaitTimer(500);
	}
}