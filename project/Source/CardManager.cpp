#include "CardManager.h"

void CardManager::UseCard(int id, Character* user, Character* target)
{
	const CardData* card = cardDB.GetCardID(id);
	if (!card) return;

	for (const auto& effect : card->effects)
	{
		switch(CardEffect::None)
		{
		case CardEffect::AttackUP:
			user->AddBuff(effect.value, effect.duration);
			break;
		case CardEffect::AttackDowm:
				target->AddDebuff(effect.value, effect.duration);
			break;
		case CardEffect::Heal:
			user->AddHeal(effect.value);
			break;
		case CardEffect::AddEnchant:
			user->AddEmchant(effect.duration, effect.type);
	}
}
