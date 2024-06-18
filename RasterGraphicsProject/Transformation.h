#pragma once
#include "UndoCommand.h"
class Transformation : public UndoCommand
{
public:
	virtual Transformation* clone() const override = 0;
	Transformation(Session* sessionPtr);
};

