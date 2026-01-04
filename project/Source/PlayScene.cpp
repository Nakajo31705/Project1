#include "PlayScene.h"
#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "LogManager.h"
#include "KeyInput.h"
#include "CardDataBase.h"

PlayScene::PlayScene()
{
	Player::Player(MDB);
	Enemy::Enemy(MDB);
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
	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
