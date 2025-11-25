#pragma once
#include "../Library/GameObject.h"
#include "DxLib.h"
#include <string>
#include <vector>

struct LogMessage
{
	std::string text;
	int x, y;			//描画する座標
	int duration;		//表示時間
	int startTime;		//開始時間(GetNowCount)
};

class LogManager : public GameObject
{
public:
	void AddLog(const std::string& text, int x, int y, int duration);
	void Update() override;
	void Draw() override;
private:
	std::vector<LogMessage> logs;
};