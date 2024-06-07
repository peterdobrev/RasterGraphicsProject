#pragma once
#include "Command.h"
class RotateCommand : public Command
{
public:
	enum class Direction
	{
		left,
		right
	};

	RotateCommand(Direction direction);
	void execute(Session& session) const override;
protected:
private:
	Direction direction;
};

