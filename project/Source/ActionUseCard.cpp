#include "ActionUseCard.h"

void ActionUseCard::Execute()
{
	cardManager->UseCard(index, player->GetActiveMonster(), enemy->GetActiveMonster());
}