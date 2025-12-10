#include "CardManager.h"
#include "Character.h"

void CardManager::UseCard(int id, Character* user, Character* target)
{
	const CardData* card = cardDB.GetCardID(id);
	if (!card) return;

	for (const auto& effect : card->effects)
	{
		switch (effect.effect)
		{
		case CardEffect::AttackUP:
			float val = effect.value;
			user->AddBuff(val);
			break;
		case CardEffect::AttackDown:
			float val = effect.value;
			target->AddDebuff(val);
			break;
		case CardEffect::Heal:
			float val = effect.value;
			user->AddHeal(val);
			break;
		case CardEffect::AddEnchant:
			int dura = effect.duration;
			int type = effect.type;
			user->AddEnchant(dura, type);
			break;
		default:
			log.AddLog("そのカードは使えません", 100, 100, 1000);
			break;
		}
	}
}
