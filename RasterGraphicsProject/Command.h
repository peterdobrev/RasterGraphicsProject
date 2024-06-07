#pragma once
#include "Session.h"
class Command
{
	virtual void execute(Session& session) const = 0;
	~Command() = default;
};

