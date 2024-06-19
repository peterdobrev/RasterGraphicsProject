#pragma once
#include "Command.h"
class PrintCommand :
    public Command
{
public:
    PrintCommand(Session* sessionPtr);

    virtual void execute() const override;
    virtual Command* clone() const override;
    virtual void printFeedback() const override;
    void printInfo() const override;
};

