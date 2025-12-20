#pragma once
#include <functional>

class Action
{
public:
	virtual ~Action() = default;


	bool SetSelectEnd(bool end)
	{
		selectEnd = end;
		return selectEnd;
	}
	bool GetSelectEnd() const { return selectEnd; }

protected:
	bool selectEnd;
};