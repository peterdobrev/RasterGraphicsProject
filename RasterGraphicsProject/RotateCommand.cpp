#include "RotateCommand.h"

RotateCommand::RotateCommand(Session* sessionPtr, Direction direction) : Transformation(sessionPtr), direction(direction)
{
}

void RotateCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		if (direction == Direction::left)
			sessionPtr->getImageAtIndex(i).get()->rotateLeft();
		else
			sessionPtr->getImageAtIndex(i).get()->rotateRight();
	}
}

void RotateCommand::printFeedback() const
{
	std::cout << "Rotate ";
	if (direction == Direction::left)
		std::cout << "left";
	else
		std::cout << "right";
	std::cout << " command executed!";
}

void RotateCommand::printInfo() const
{
	std::cout << "Rotate ";
	if (direction == Direction::left)
		std::cout << "left";
	else
		std::cout << "right";
}

Transformation* RotateCommand::clone() const
{
	return new RotateCommand(*this);
}

void RotateCommand::undo() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		if (direction == Direction::left)
			sessionPtr->getImageAtIndex(i).get()->rotateRight();
		else
			sessionPtr->getImageAtIndex(i).get()->rotateLeft();
	}

	sessionPtr->popBackTransformation();
}
