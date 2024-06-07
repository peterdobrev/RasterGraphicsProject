#pragma once
#include "Command.h"
class NegativeCommand : public Command
{
public:
    NegativeCommand();
    void execute(Session& session) const override;
};

