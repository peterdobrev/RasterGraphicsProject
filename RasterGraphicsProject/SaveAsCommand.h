#pragma once
#include "SaveCommand.h"
#include "String.h"
class SaveAsCommand : public SaveCommand
{
public:
	SaveAsCommand(Session* sessionPtr, const String& fileName);
	// Inherited via Command
	virtual void execute() const override;
	virtual Command* clone() const override;
	virtual void print() const override;
private:
	String fileName;
};

