#pragma once
#include "String.h"
#include "Command.h"
class AddCommand : public Command
{
public:
	void execute() const override;
	void print() const override;
	AddCommand(Session* sessionPtr, String fileName);
	virtual Command* clone() const override;
private:
	String fileName;
};

