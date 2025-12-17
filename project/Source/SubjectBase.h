#pragma once
#include "Subject.h"

class SubjectBase : public Subject
{
public:
	void AddObserver(Observer* observer) override;
	void RemoveObserver(Observer* observer) override;
	virtual void Notify(int index) override;
	virtual void Notify(const std::string& message) override;

private:
	std::vector<Observer*> observers;
};
