#pragma once
#include "DxLib.h"
#include <string>
#include <vector>
#include <algorithm>

struct LogEntry
{
	std::string text;
	int expireCount;	//GetNowCount()の終了タイム
	int x, y;			//描画する座標
};

class LogManager
{
public:
	void AddLog(const std::string& text, int displayMs, int x = 100, int y = 100);
	void DrawLogs();

private:
	std::vector<LogEntry> logs;
};