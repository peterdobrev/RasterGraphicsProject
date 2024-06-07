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

	void execute(Session& session) const override;
	CollageCommand(Direction direction, String image1, String image2);
private:
	String image1;
	String image2;
	Direction direction;
};

