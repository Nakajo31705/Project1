#pragma once
#include "../Library/GameObject.h"
#include <DxLib.h>
#include <array>

class KeyInput : GameObject
{
public:
	KeyInput()
	{
		now.fill(0);
		prev.fill(0);
	}

	void Update()
	{
		prev = now;
		GetHitKeyStateAll(now.data());
	}

	//¡‰Ÿ‚µ‚Ä‚é‚©
	bool isPressed(int key) const
	{
		return now[key] != 0;
	}

	//‰Ÿ‚³‚ê‚½uŠÔ
	bool isJustPressed(int key) const
	{
		return (now[key] != 0) && (prev[key] == 0);
	}

	//—£‚³‚ê‚½uŠÔ
	bool isJustReleased(int key) const
	{
		return (now[key] == 0) && (prev[key] != 0);
	}


private:
	std::array<char, 256> now;
	std::array<char, 256> prev;
};
