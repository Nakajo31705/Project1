#pragma once
#include <string>
#include <vector>

/// <summary>
/// カードの効果
/// 1.効果量
/// 2.効果時間
/// 3.タイプ
/// </summary>
enum class CardEffect
{
	AttackUP,			//攻撃力UP
	AttackDown,			//攻撃力Down
	Heal,				//回復
	AddEnchant,			//属性付与
	None				//無し
};

//効果の情報
struct EffectInfo
{
	CardEffect effect;	//効果の種類
	float value;		//効果量(攻撃力や回復力)
	int duration;		//効果時間(何ターンなど)
	int type;			//タイプ(数値でタイプを設定)
};

//カードの種類
enum class CardType
{
	Buff,				//バフ
	Debuff,				//デバフ
	Heal,				//回復
	Enchant				//属性付与
};

//カードのデータ
struct CardData
{
	int id;							//ID
	std::string name;				//カードの名前
	CardType cardType;				//カードの種類
	int type;						//属性
	std::vector<EffectInfo> effects;//効果の情報
	std::string description;		//説明文

};

class CardDataBase
{
public:
	CardDataBase();

	//初期化用
	static void Initialize();

	//指定したIDのカードデータを取得
	static const CardData* GetCardID(int id);

	//データベースに登録しているカードを全て取得
	static const std::vector<CardData>& GetAllCards();

private:
	static std::vector<CardData> m_cards;
};
