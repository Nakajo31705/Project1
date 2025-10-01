#include "MonsterList.h"

MonsterList::MonsterList()
{
    //モンスターをリストに追加
    monsters.emplace_back("炎の精霊", 100);
    monsters.emplace_back("水の精霊", 100);
    monsters.emplace_back("草の精霊", 100);
    monsters.emplace_back("光の精霊", 100);
    monsters.emplace_back("闇の精霊", 100);
}

//モンスターの名前からHPを取得
int MonsterList::GetHP(std::string& name) const
{
    for (const auto& monster : monsters)
    {
        if (monster.GetName() == name)
        {
            return monster.GetHP();
        }
    }
    return 0;
}
