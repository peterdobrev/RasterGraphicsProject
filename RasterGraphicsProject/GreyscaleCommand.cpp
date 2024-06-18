#include "GreyscaleCommand.h"

GreyscaleCommand::GreyscaleCommand(Session* sessionPtr) : Transformation(sessionPtr) {}

void GreyscaleCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->makeGreyscale();
	}
}

void GreyscaleCommand::print() const
{
	std::cout << "Greyscale";
}

Transformation* GreyscaleCommand::clone() const
{
	return new GreyscaleCommand(*this);
}


void GreyscaleCommand::undo() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->undoGreyscale();
	}

	sessionPtr->popBackTransformation();
}

