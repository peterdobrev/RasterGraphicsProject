#pragma once
#include "Transformation.h"
class MonochromeCommand : public Transformation
{
public:
	MonochromeCommand(Session* sessionPtr);

	void execute() const override;
	void print() const override;
	void undo() const override;

	virtual Transformation* clone() const override;
};

