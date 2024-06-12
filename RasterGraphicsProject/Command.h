#pragma once
#include "Session.h"
class Command
{
public:
	Command(Session* sessionPtr) : sessionPtr(sessionPtr) {}

	virtual void execute() const = 0;
	virtual Command* clone() const = 0;
	virtual ~Command() = default;

protected:
	Session* sessionPtr;
};

