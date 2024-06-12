#include "MonochromeCommand.h"

void MonochromeCommand::execute() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->images[i].get()->makeMonochrome();
	}
}

Command* MonochromeCommand::clone() const
{
	return new MonochromeCommand(*this);
}

void MonochromeCommand::undo() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->images[i].get()->undoMonochrome();
	}
}

MonochromeCommand::MonochromeCommand(Session* sessionPtr) : UndoCommand(sessionPtr) {}