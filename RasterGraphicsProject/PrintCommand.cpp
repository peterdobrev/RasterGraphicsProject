#include "PrintCommand.h"

PrintCommand::PrintCommand(Session* sessionPtr)
    : Command(sessionPtr)
{
}

void PrintCommand::execute() const
{
    sessionPtr->print();
}

Command* PrintCommand::clone() const
{
    return new PrintCommand(*this);
}

void PrintCommand::print() const
{
    std::cout << "Print";
}
