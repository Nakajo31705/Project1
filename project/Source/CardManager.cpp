#include "CardManager.h"

void CardManager::UseCard(int id, Character& user, Character* target)
{
	const CardData* card = cardDB.GetCardID(id);
	if (!card) return;

	for (const auto& effect : card->effects)
	{
		switch(effect.type)
		{
		/*case CardEffect::AttackUP:
			user.AddBuff(effect.value, effect.duration);
			break;*/
	}
}
