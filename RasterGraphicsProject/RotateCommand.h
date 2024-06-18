#pragma once
#include "Transformation.h"
class RotateCommand : public Transformation
{
public:
	enum class Direction
	{
		left,
		right
	};

	RotateCommand(Session* sessionPtr, Direction direction);

	void execute() const override;
	void print() const override;
	void undo() const override;

	virtual Transformation* clone() const override;

private:
	Direction direction;
};

