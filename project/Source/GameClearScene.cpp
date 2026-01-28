#include "GameClearScene.h"

GameClearScene::GameClearScene()
{
}

GameClearScene::~GameClearScene()
{
}

void GameClearScene::Update()
{
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void GameClearScene::Draw()
{
	DrawString(550, 300, "ゲームクリア！！", GetColor(0, 255, 255));
	DrawString(500, 350, "[ESC]キーを押してゲーム終了", GetColor(255, 255, 255));
	DrawString(500, 400, "[T]キーを押してタイトルへ", GetColor(255, 255, 255));
}
