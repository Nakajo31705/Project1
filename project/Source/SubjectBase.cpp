#include "SubjectBase.h"


void SubjectBase::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}

void SubjectBase::RemoveObserver(Observer* observer)
{
	observers.erase(std::remove(observers.begin(), observers.end(),
		observer), observers.end());
}

void SubjectBase::Notify(int index)
{
	for (auto* observer : observers)
	{
		observer->OnNotify(index);
	}
}

void SubjectBase::Notify(const std::string& message)
{
	for (auto* observer : observers)
	{
		observer->OnNotify(message);
	}
}
