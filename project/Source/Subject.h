#pragma once
#include <vector>
#include <string>
#include "Observer.h"

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void AddObserver(Observer* observer) = 0;
    virtual void RemoveObserver(Observer* observer) = 0;

    //”’l—p
    virtual void Notify(int index) = 0;

    //•¶š—p
    virtual void Notify(const std::string& message) = 0;
};
