#pragma once
#include "../Library/SceneBase.h"

class GameClearScene : public SceneBase
{
public:
	GameClearScene();
	~GameClearScene();
	void Update() override;
	void Draw() override;
};