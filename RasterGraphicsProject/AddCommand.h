#pragma once
#include "Command.h"
#include "String.h"
class AddCommand : public Command
{
	void execute() const override;

private:
	String fileName;
};

