#include "MonsterDataBase.h"

MonsterDataBase::MonsterDataBase()
{
	//データベースを初期化
	MonsterList monsterList;
	SkillList skillList;

	//プレイヤーのモンスター
	//モンスターの情報を取り出す
	std::string playerMonsterName = "炎の精霊";
	int playerHP = monsterList.GetHP(playerMonsterName);
	Monster playerMonster(playerMonsterName, playerHP);

	std::vector<Skill>playerSkills = {
		Skill("炎攻撃", skillList.GetPower("炎攻撃")),
	};

	//モンスターと技の情報を渡す
	Player player(playerMonster, playerSkills);

	//エネミーのモンスター
	std::string enemyMonsterName = "水の精霊";
	int enemyHP = monsterList.GetHP(enemyMonsterName);
	Monster enemyMonster(enemyMonsterName, enemyHP);

	std::vector<Skill>enemySkills = {
		Skill("水攻撃", skillList.GetPower("水攻撃")),
	};

	//情報を渡す
	Enemy enemy(enemyMonster, enemySkills);
}
