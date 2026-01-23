#include "CardManager.h"
#include "Character.h"

void CardManager::UseCard(int id, Character* user, Character* target)
{
	//const CardData* card = cardDB.GetCardID(id);
	//if (!card) return;

	//for (const auto& effect : card->effects)
	//{
	//	switch (effect.effect)
	//	{
	//	case CardEffect::AttackUP:
	//		user->AddBuff(effect.value);
	//		break;
	//	case CardEffect::AttackDown:
	//		target->AddDebuff(effect.value);
	//		break;
	//	case CardEffect::Heal:
	//		user->AddHeal(effect.value);
	//		break;
	//	case CardEffect::AddEnchant:
	//		user->AddEnchant(effect.type);
	//		break;
	//	default:
	//		log.AddLog("そのカードは使えません", 100, 100, 1000);
	//		break;
	//	}
	//}
}
