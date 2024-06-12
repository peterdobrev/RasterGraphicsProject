#pragma once
#include "UndoCommand.h"
class GreyscaleCommand : public UndoCommand
{
public:
	GreyscaleCommand(Session* sessionPtr);
	virtual void execute() const override;
	virtual Command* clone() const override;
	void undo() const override;
};

