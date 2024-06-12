#include "RotateCommand.h"

RotateCommand::RotateCommand(Session* sessionPtr, Direction direction) : UndoCommand(sessionPtr), direction(direction)
{
}

void RotateCommand::execute() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (direction == Direction::left)
			sessionPtr->images[i].get()->rotateLeft();
		else
			sessionPtr->images[i].get()->rotateRight();
	}
}

Command* RotateCommand::clone() const
{
	return new RotateCommand(*this);
}

void RotateCommand::undo() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (direction == Direction::left)
			sessionPtr->images[i].get()->rotateRight();
		else
			sessionPtr->images[i].get()->rotateLeft();
	}
}
