#pragma once
#include "UndoCommand.h"
class RotateCommand : public UndoCommand
{
public:
	enum class Direction
	{
		left,
		right
	};

	RotateCommand(Session* sessionPtr, Direction direction);
	void execute() const override;
	virtual Command* clone() const override;
	void undo() const override;
protected:
private:
	Direction direction;
};

