#pragma once
#include "Command.h"
class MonochromeCommand : public Command
{
public:
	MonochromeCommand();
	void execute(Session& session) const override;
};

