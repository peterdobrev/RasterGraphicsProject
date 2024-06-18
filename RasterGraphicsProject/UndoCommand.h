#pragma once
#include "Command.h"
class UndoCommand :
    public Command
{
public:
    UndoCommand(Session* sessionPtr) : Command(sessionPtr) {}
    virtual UndoCommand* clone() const override = 0;
    virtual void undo() const;
};

