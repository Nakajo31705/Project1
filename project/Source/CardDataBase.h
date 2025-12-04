#pragma once
#include <string>
#include <vector>

//カードの効果
enum class CardEffect
{
	AttackUP,			//攻撃力UP
	AttackDowm,			//攻撃力Down
	Heal,				//回復
	AddType,			//属性付与
	None				//無し
};

//効果の情報
struct EffectInfo
{
	CardEffect efect;	//効果の種類
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
	Emchant				//属性付与
};

//カードのデータ
struct CardData
{
	int id;							//ID
	std::string name;				//カードの名前
	CardType cardType;				//カードの種類
	int type;						//属性
	std::vector<EffectInfo> info;	//効果の情報
	std::string description;		//説明文

};

class CardDataBase
{
public:
	CardDataBase();

	//初期化用
	void Initialize();

	//指定したIDのカードデータを取得
	const CardData* GetCardID(int id) const;

	//データベースに登録しているカードを全て取得
	const std::vector<CardData>& GetAllCards() const;

private:
	std::vector<CardData> m_cards;
};
