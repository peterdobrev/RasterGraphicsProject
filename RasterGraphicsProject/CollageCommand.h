	#pragma once
#include "Command.h"
#include "Image.h"
#include "String.h"
class CollageCommand : public Command
{
public:
	enum Direction
	{
		horizontal,
		vertical
	};

	void execute() const override;
	CollageCommand(Session* sessionPtr, Direction direction, String imagePath1, String imagePath2, String outImagePath);
	virtual Command* clone() const override;
private:
	String imagePath1;
	String imagePath2;
	String outImagePath;
	Direction direction;
};

