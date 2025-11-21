#pragma once
#include "../Library/SceneBase.h"
#include "MonsterDataBase.h"
#include "LogManager.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	//モンスターデータベース
	MonsterDataBase MDB;
	LogManager logManager;
};
