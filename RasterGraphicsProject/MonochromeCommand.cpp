#include "MonochromeCommand.h"

void MonochromeCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->makeMonochrome();
	}
}

void MonochromeCommand::printFeedback() const
{
	std::cout << "Monochrome command executed!";
}

void MonochromeCommand::printInfo() const
{
	std::cout << "Monochrome";
}

Transformation* MonochromeCommand::clone() const
{
	return new MonochromeCommand(*this);
}

void MonochromeCommand::undo() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		sessionPtr->getImageAtIndex(i).get()->undoMonochrome();
	}

	sessionPtr->popBackTransformation();
}

MonochromeCommand::MonochromeCommand(Session* sessionPtr) : Transformation(sessionPtr) {}