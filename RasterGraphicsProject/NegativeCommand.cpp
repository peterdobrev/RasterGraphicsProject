#include "NegativeCommand.h"

void NegativeCommand::execute() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->images[i].get()->makeNegative();
	}
}

Command* NegativeCommand::clone() const
{
	return new NegativeCommand(*this);
}

NegativeCommand::NegativeCommand(Session* sessionPtr) : UndoCommand(sessionPtr) {}