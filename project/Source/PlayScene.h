#pragma once
#include "../Library/SceneBase.h"
#include "MonsterDataBase.h"

/// <summary>
/// �Q�[���v���C�̃V�[���𐧌䂷��
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;

private:
	//�����X�^�[�f�[�^�x�[�X
	MonsterDataBase MDB;
};
