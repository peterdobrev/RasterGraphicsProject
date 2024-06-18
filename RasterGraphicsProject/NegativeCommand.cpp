#include "NegativeCommand.h"

void NegativeCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->makeNegative();
	}

	sessionPtr->popBackTransformation();
}

void NegativeCommand::print() const
{
	std::cout << "Negative";
}

Transformation* NegativeCommand::clone() const
{
	return new NegativeCommand(*this);
}

NegativeCommand::NegativeCommand(Session* sessionPtr) : Transformation(sessionPtr) {}