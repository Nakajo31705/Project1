#include "EnemyTurn.h"

EnemyTurn::EnemyTurn(GameManager* gm)
	:gameManager(gm) {
}


void EnemyTurn::Enter()
{
	DrawString(defDraw, defDraw, "エネミーのターン", GetColor(255, 255, 255));
}

void EnemyTurn::Update()
{
}

void EnemyTurn::Exit()
{
	DrawString(defDraw, defDraw, "エネミーのターン終了", GetColor(255, 255, 255));
}

