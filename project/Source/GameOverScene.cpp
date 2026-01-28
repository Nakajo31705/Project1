#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void GameOverScene::Draw()
{
	DrawString(550, 300, "ゲームオーバー", GetColor(255, 0, 0));
	DrawString(500, 400, "[T]キーを押してタイトルへ", GetColor(255, 255, 255));
}
