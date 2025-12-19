#include "PlayScene.h"
#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "CardDataBase.h"

PlayScene::PlayScene()
{
	new Player(MDB);
	new Enemy(MDB);
	new GameManager();
	new LogManager();
	new KeyInput();

	CardDataBase::Initialize();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	Monster* p = player->GetActiveMonster();
	Monster* e = enemy->GetActiveMonster();

	DrawFormatString(700, 100, GetColor(255, 255, 255), "%s, HP:%d", p->GetName(), p->GetCurrentHP());
	DrawFormatString(700, 120, GetColor(255, 255, 255), "%s, HP:%d", e->GetName(), e->GetCurrentHP());


	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
