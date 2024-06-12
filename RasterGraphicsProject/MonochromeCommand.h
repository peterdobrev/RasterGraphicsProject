#pragma once
#include "UndoCommand.h"
class MonochromeCommand : public UndoCommand
{
public:
	MonochromeCommand(Session* sessionPtr);
	void execute() const override;
	virtual Command* clone() const override;
	void undo() const override;
};

