#pragma once
#include "Command.h"
class GreyscaleCommand : public Command
{
public:
	GreyscaleCommand();
	virtual void execute(Session& session) const override;
};

