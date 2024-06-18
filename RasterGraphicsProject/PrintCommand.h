#pragma once
#include "Command.h"
class PrintCommand :
    public Command
{
public:
    PrintCommand(Session* sessionPtr);

    // Inherited via Command
    virtual void execute() const override;
    virtual Command* clone() const override;
    virtual void print() const override;
};

