#include "LogManager.h"

void LogManager::AddLog(const std::string& text, int displayMs, int x, int y)
{
	int now = GetNowCount();
	logs.push_back({ text, now + displayMs, x, y });
}

void LogManager::DrawLogs()
{
	int now = GetNowCount();

	logs.erase(std::remove_if(logs.begin(), logs.end(), [&](const LogEntry& entry)
		{return entry.expireCount < now;}), logs.end());

	for (const auto& log : logs)
	{
		DrawString(log.x, log.y, log.text.c_str(), GetColor(255, 255, 255));
	}
}
