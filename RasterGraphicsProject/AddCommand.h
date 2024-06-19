#pragma once
#include "String.h"
#include "Command.h"
class AddCommand : public Command
{
public:
	void execute() const override;
	void printFeedback() const override;
	virtual void printInfo() const override;
	AddCommand(Session* sessionPtr, String fileName);
	virtual Command* clone() const override;
private:
	String fileName;
};

