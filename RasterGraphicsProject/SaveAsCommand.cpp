#include "SaveAsCommand.h"

void SaveAsCommand::execute() const
{
	sessionPtr->getImageAtIndex(0)->setName(fileName);

	SaveCommand::execute();
}

Command* SaveAsCommand::clone() const
{
	return new SaveAsCommand(*this);
}

void SaveAsCommand::print() const
{
	std::cout << "Save As " << fileName;
}

SaveAsCommand::SaveAsCommand(Session* sessionPtr, const String& fileName)
	: SaveCommand(sessionPtr), fileName(fileName)
{}
