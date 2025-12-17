#include "PlayerTurn.h"
#include "GameManager.h"
#include "EnemyTurn.h"

PlayerTurn::PlayerTurn(GameManager* gm)
	:gameManager(gm)
{
	player = FindGameObject<Player>();
}

/// <summary>
/// プレイヤーのターンが開始したときに呼ぶ
/// </summary>
void PlayerTurn::Enter()
{
	myTurn = true;
	log.AddLog("プレイヤーのターン", 100, 200, 1000);
}

void PlayerTurn::Update()
{
	//ターンの切り替え
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
	case PlayerSubState::CardSelect:
		player->CardSelect();
		break;
	case PlayerSubState::Done:
		Exit();
		break;
	}
}

/// <summary>
/// プレイヤーのターンが終了するときに呼ぶ
/// </summary>
void PlayerTurn::Exit()
{
	//ターン終了にエネミーのターンにする
	log.AddLog("プレイヤーのターン終了", 100, 200, 1000);
	gameManager->ChangeState(gameManager->GetEnemyTurn());
	myTurn = false;
}

/// <summary>
/// 自分のターンで何回行動したかカウントする関数
/// 2回行動したらターン終了
/// </summary>
void PlayerTurn::SelectEnd()
{
	playCount++;

	if (playCount >= 2)
	{
		subState = PlayerSubState::Done;
		playCount = 0;
	}
	else
	{
		subState = PlayerSubState::MenuSelect;
		WaitTimer(1000);
	}
		
}

/// <summary>
/// メニューの選択画面
/// </summary>
void PlayerTurn::Menu()
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
		player->SetSelected(selected);
		if (selected == 0)
		{
			DrawString(defDrawX, defDrawY*2, "技を選択", GetColor(255, 255, 255));
			WaitTimer(150);
			subState = PlayerSubState::SkillSelect;
		}
		else if (selected == 1)
		{
			DrawString(defDrawX, defDrawY*2, "モンスターを交換", GetColor(255, 255, 255));
			WaitTimer(150);
			subState = PlayerSubState::MonsterSelect;
		}
		else if (selected == 2)
		{
			DrawString(defDrawX, defDrawY * 2, "カードの選択", GetColor(255, 255, 255));
			WaitTimer(150);
			subState = PlayerSubState::CardSelect;
		}
	}
}