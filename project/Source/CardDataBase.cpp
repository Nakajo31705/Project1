#include "CardDataBase.h"

CardDataBase::CardDataBase()
{
	Initialize();
}

void CardDataBase::Initialize()
{
	/*
	ID
	–¼‘O
	ƒJ[ƒh‚Ìí—Ş
	‘®«
	Œø‰Ê‚Ìî•ñ
	à–¾•¶
	*/

	//1
	m_cards.push_back
	({
		1,
		"UŒ‚—ÍUP",
		CardType::Buff,
		0,
		{{CardEffect::AttackUP,1.2f, 2, 0}},
		"©•ª‚ÌUŒ‚—Í‚ª2ƒ^[ƒ“20%ã¸‚·‚é"
	});

	//2
	m_cards.push_back
	({
		2,
		"UŒ‚—ÍDown",
		CardType::Debuff,
		0,
		{{CardEffect::AttackDowm,1.2f, 1, 0}},
		"‘Šè‚ÌUŒ‚—Í‚ª1ƒ^[ƒ“20%ƒ_ƒEƒ“‚·‚é"
	});

	//3
	m_cards.push_back
	({
		3,
		"‰ñ•œ",
		CardType::Heal,
		0,
		{{CardEffect::Heal,20.0f, 0, 0}},
		"HP‚ğ20‰ñ•œ‚·‚é"
	});

	//4
	m_cards.push_back
	({
		4,
		"‰Š‘®«•t—^",
		CardType::Emchant,
		1,
		{{CardEffect::AddType,0, 1, 1}},
		"‹Z‚É‰Š‘®«‚ğ•t—^‚·‚é(1ƒ^[ƒ“Œp‘±)"
	});

	//5
	m_cards.push_back
	({
		5,
		"—‹‘®«•t—^",
		CardType::Emchant,
		2,
		{{CardEffect::AddType,0, 1, 2}},
		"‹Z‚É—‹‘®«‚ğ•t—^‚·‚é(‚Pƒ^[ƒ“Œp‘±)"
		});
}

const CardData* CardDataBase::GetCardID(int id) const
{
	for (const auto& card : m_cards)
	{
		if (card.id == id)
			return &card;
	}
	return nullptr;
}

const std::vector<CardData>& CardDataBase::GetAllCards() const
{
	return m_cards;
}
