#include "SaveCommand.h"

SaveCommand::SaveCommand(Session* sessionPtr)
    : Command(sessionPtr)
{
}

void SaveCommand::execute() const
{
    size_t length = sessionPtr->getImagesCount();
    for (size_t i = 0; i < length; i++)
    {
        sessionPtr->getImageAtIndex(i)->save();
    }

    sessionPtr->clearTransformations();
}

Command* SaveCommand::clone() const
{
    return nullptr;
}

void SaveCommand::print() const
{
    std::cout << "Save";
}
