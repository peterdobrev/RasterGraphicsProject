#pragma once
#include "UndoCommand.h"
class NegativeCommand : public UndoCommand
{
public:
    NegativeCommand(Session* sessionPtr);
    void execute() const override;
    virtual Command* clone() const override;
    // undo remains as the default
};

