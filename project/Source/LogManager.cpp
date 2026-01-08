#include "LogManager.h"

void LogManager::AddLog(const std::string& text, int x, int y, int duration)
{
	LogMessage msg;
	msg.text = text;
	msg.x = x;
	msg.y = y;
	msg.duration = duration;
	msg.startTime = GetNowCount();

	logs.push_back(msg);
}

void LogManager::Update()
{
	int now = GetNowCount();

	//—LŒøŠúŒÀ‚ð‰ß‚¬‚½‚çƒƒO‚ðíœ
	logs.erase(std::remove_if(logs.begin(), logs.end(),
		[&](const LogMessage& msg)
		{
			return now - msg.startTime > msg.duration;
		}
	),
		logs.end()
	);
}

void LogManager::Draw()
{
	for (const auto& msg : logs)
	{
		DrawString(msg.x, msg.y, msg.text.c_str(), GetColor(255, 255, 255));
	}
}