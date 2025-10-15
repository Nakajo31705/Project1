#include "EnemyTurn.h"

EnemyTurn::EnemyTurn(GameManager* gm)
	:gameManager(gm) {
}


void EnemyTurn::Enter()
{
	DrawString(defDraw, defDraw, "�G�l�~�[�̃^�[��", GetColor(255, 255, 255));
}

void EnemyTurn::Update()
{
}

void EnemyTurn::Exit()
{
	DrawString(defDraw, defDraw, "�G�l�~�[�̃^�[���I��", GetColor(255, 255, 255));
}

