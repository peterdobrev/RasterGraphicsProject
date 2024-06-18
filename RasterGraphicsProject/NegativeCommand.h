#pragma once
#include "Transformation.h"
class NegativeCommand : public Transformation
{
public:
    NegativeCommand(Session* sessionPtr);

    void execute() const override;
    void print() const override;
    // undo remains as the default

    virtual Transformation* clone() const override;
};
