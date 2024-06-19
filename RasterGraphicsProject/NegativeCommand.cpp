#include "NegativeCommand.h"

void NegativeCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->makeNegative();
	}
}

void NegativeCommand::printFeedback() const
{
	std::cout << "Negative command executed!";
}

void NegativeCommand::printInfo() const
{
	std::cout << "Negative";
}

void NegativeCommand::undo() const
{
	execute();
	sessionPtr->popBackTransformation();
}

Transformation* NegativeCommand::clone() const
{
	return new NegativeCommand(*this);
}

NegativeCommand::NegativeCommand(Session* sessionPtr) : Transformation(sessionPtr) {}