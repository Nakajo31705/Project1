#include "MonsterList.h"

MonsterList::MonsterList()
{
    //�����X�^�[�����X�g�ɒǉ�
    monsters.emplace_back("���̐���", 100);
    monsters.emplace_back("���̐���", 100);
    monsters.emplace_back("���̐���", 100);
    monsters.emplace_back("���̐���", 100);
    monsters.emplace_back("�ł̐���", 100);
}

//�����X�^�[�̖��O����HP���擾
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
