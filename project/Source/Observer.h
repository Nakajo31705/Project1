#pragma once

class Observer
{
public:
	virtual ~Observer() = default;
	virtual void OnNotify(int index){}
	virtual void OnNotify(const std::string& message) {}
};
