#pragma once
#include "Transformation.h"
class GreyscaleCommand : public Transformation
{
public:
	GreyscaleCommand(Session* sessionPtr);
	
	virtual void execute() const override;
	virtual void print() const override;
	void undo() const override;

	virtual Transformation* clone() const override;

};

