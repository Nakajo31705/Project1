#pragma once
#include "../Library/SceneBase.h"
#include "MonsterDataBase.h"
#include "LogManager.h"

class Player;
class Enemy;

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
	Player* player;
	Enemy* enemy;
};
