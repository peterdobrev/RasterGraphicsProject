#include "PrintCommand.h"

PrintCommand::PrintCommand(Session* sessionPtr)
    : Command(sessionPtr)
{
}

void PrintCommand::execute() const
{
    sessionPtr->printFeedback();
    std::cout << std::endl;
}

Command* PrintCommand::clone() const
{
    return new PrintCommand(*this);
}

void PrintCommand::printFeedback() const
{
    std::cout << "Print command executed!";
}

void PrintCommand::printInfo() const
{
    std::cout << "Print";
}
