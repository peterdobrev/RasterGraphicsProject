#pragma once
#include "Transformation.h"
class MonochromeCommand : public Transformation
{
public:
	MonochromeCommand(Session* sessionPtr);

	void execute() const override;
	void printFeedback() const override;
	void printInfo() const override;
	void undo() const override;

	virtual Transformation* clone() const override;
};

