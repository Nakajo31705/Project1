#pragma once
#include <string>

class LogManager
{
	LogManager();
	void AddMessage(std::string& text);
	void Update();
	void Draw();
	void NextMessage();
};