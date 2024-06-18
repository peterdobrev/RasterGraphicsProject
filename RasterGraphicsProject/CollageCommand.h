#pragma once
#include "Command.h"
#include "Image.h"
#include "String.h"
#include "PolymorphicPtr.hpp"
#include "TransformableImage.h"

class CollageCommand : public Command
{
public:
	enum Direction
	{
		horizontal,
		vertical
	};

	void execute() const override;
	void print() const override;
	CollageCommand(Session* sessionPtr, Direction direction, 
		String imagePath1, String imagePath2, String outImagePath);
	virtual Command* clone() const override;
private:
	String imagePath1;
	String imagePath2;
	String outImagePath;
	Direction direction;

	PolymorphicPtr<TransformableImage> createCollagedImage(
		PolymorphicPtr<TransformableImage> image1, PolymorphicPtr<TransformableImage> image2);
};

