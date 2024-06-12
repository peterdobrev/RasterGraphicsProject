#include "GreyscaleCommand.h"

GreyscaleCommand::GreyscaleCommand(Session* sessionPtr) : UndoCommand(sessionPtr) {}

void GreyscaleCommand::execute() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->images[i].get()->makeGreyscale();
	}
}

Command* GreyscaleCommand::clone() const
{
	return new GreyscaleCommand(*this);
}

void GreyscaleCommand::undo() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->images[i].get()->undoGreyscale();
	}
}

