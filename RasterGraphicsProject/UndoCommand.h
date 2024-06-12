#pragma once
#include "Command.h"
class UndoCommand :
    public Command
{
public:
    UndoCommand(Session* sessionPtr) : Command(sessionPtr) {}
    virtual void undo() const;
};

