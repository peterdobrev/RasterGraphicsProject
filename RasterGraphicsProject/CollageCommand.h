	#pragma once
#include "Command.h"
#include "Image.h"
class CollageCommand : public Command
{
public:
	void execute() const override;
protected:
	enum Direction
	{
		horizontal,
		vertical
	};
private:
	Image* image1;
	Image* image2;
};

