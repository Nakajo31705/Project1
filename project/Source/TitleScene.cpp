#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_P)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
	if (CheckHitKey(KEY_INPUT_O)) {
		SceneManager::ChangeScene("GameOver");
	}
	if (CheckHitKey(KEY_INPUT_I)) {
		SceneManager::ChangeScene("GameClear");
	}
}


void TitleScene::Draw()
{
	extern const char* Version();
	DrawString(0, 20, Version(), GetColor(255,255,255));
	DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	DrawString(500, 400, "[P]キーを押してスタート", GetColor(255, 255, 255));
}
