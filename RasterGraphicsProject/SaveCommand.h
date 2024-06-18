#pragma once
#include "Command.h"
class SaveCommand : public Command
{
public:
	SaveCommand(Session* sessionPtr);
	// Inherited via Command
	virtual void execute() const override;
	virtual Command* clone() const override;
	virtual void print() const override;
};

