#pragma once
#include "Transformation.h"
class NegativeCommand : public Transformation
{
public:
    NegativeCommand(Session* sessionPtr);

    void execute() const override;
    void printFeedback() const override;
    void printInfo() const override;
    void undo() const override;

    virtual Transformation* clone() const override;
};
