#pragma once
#include "UndoCommand.h"
#include "String.h"
class AddCommand : public UndoCommand
{
public:
	void execute() const override;
	AddCommand(Session* sessionPtr, String fileName);
	virtual Command* clone() const override;
	void undo() const override;
private:
	String fileName;
};

