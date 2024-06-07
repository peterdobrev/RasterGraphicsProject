#pragma once
#include "Command.h"
#include "String.h"
class AddCommand : public Command
{
public:
	void execute(Session& session) const override;
	AddCommand(String fileName);
private:
	String fileName;
};

