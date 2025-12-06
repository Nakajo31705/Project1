#include "CardDataBase.h"

CardDataBase::CardDataBase()
{
	Initialize();
}

/// <summary>
/// カードを初期化してm_cardsに保存
/// </summary>
void CardDataBase::Initialize()
{
	/*
	ID
	名前
	カードの種類
	属性
	効果の情報
	説明文
	*/

	//1
	m_cards.push_back
	({
		1,
		"攻撃力UP",
		CardType::Buff,
		0,
		{{CardEffect::AttackUP,1.2f, 2, 0}},
		"自分の攻撃力が2ターン20%上昇する"
	});

	//2
	m_cards.push_back
	({
		2,
		"攻撃力Down",
		CardType::Debuff,
		0,
		{{CardEffect::AttackDowm,1.2f, 1, 0}},
		"相手の攻撃力が1ターン20%ダウンする"
	});

	//3
	m_cards.push_back
	({
		3,
		"回復",
		CardType::Heal,
		0,
		{{CardEffect::Heal,20.0f, 0, 0}},
		"HPを20回復する"
	});

	//4
	m_cards.push_back
	({
		4,
		"炎属性付与",
		CardType::Emchant,
		1,
		{{CardEffect::AddType,0, 1, 1}},
		"技に炎属性を付与する(1ターン継続)"
	});

	//5
	m_cards.push_back
	({
		5,
		"雷属性付与",
		CardType::Emchant,
		2,
		{{CardEffect::AddType,0, 1, 2}},
		"技に雷属性を付与する(１ターン継続)"
		});
}

/// <summary>
/// カードのIDを取得
/// </summary>
/// <param name="id"></param>
/// <returns></returns>
const CardData* CardDataBase::GetCardID(int id) const
{
	for (const auto& card : m_cards)
	{
		if (card.id == id)
			return &card;
	}
	return nullptr;
}

/// <summary>
/// カードをすべて取得
/// </summary>
/// <returns></returns>
const std::vector<CardData>& CardDataBase::GetAllCards() const
{
	return m_cards;
}
