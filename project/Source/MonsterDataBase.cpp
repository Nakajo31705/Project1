#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//データベースを初期化
	MonsterList monsterList;
	SkillList skillList;

	//モンスターの情報を取り出す
	std::vector<Monster> playerMonster = {
		Monster ("炎の精霊",monsterList.GetHP("炎の精霊")),
	};

	std::vector<Skill>playerSkills = {
		Skill("炎攻撃", skillList.GetPower("炎攻撃")),
	};

	//モンスターと技の情報を渡す
	Player player(playerMonster, playerSkills);



	//エネミーのモンスター
	std::vector<Monster> enemyMonster = {
		Monster("水の精霊", monsterList.GetHP("水の精霊")),
	};

	std::vector<Skill>enemySkills = {
		Skill("水攻撃", skillList.GetPower("水攻撃")),
	};

	Enemy enemy(enemyMonster, enemySkills);
}
