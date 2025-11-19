#pragma once

class PlayerObserver
{
public:
	virtual ~PlayerObserver() = default;
	virtual void SelectEnd() = 0;
};