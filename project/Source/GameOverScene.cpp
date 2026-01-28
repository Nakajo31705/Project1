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
		SceneManager::ChangeScene("TitleScene");
	}
}

void GameOverScene::Draw()
{
	DrawString(640, 100, "ゲームオーバー", GetColor(255, 0, 0));
	DrawString(640, 400, "[T]キーを押してタイトルへ", GetColor(255, 255, 255));
}
