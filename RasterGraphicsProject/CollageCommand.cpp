#include "CollageCommand.h"

void CollageCommand::execute() const
{
	PolymorphicPtr<TransformableImage> image1, image2;
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (imagePath1 == sessionPtr->images[i].get()->getName())
		{
			image1 = sessionPtr->images[i];
		}

		if (imagePath2 == sessionPtr->images[i].get()->getName())
		{
			image2 = sessionPtr->images[i];
		}
	}

	if (!image1.get() || !image2.get())
	{
		throw "Cannot make collage from selected images! Images are not loaded!";
	}

	throw "NOT implementED!";
}

CollageCommand::CollageCommand(Session* sessionPtr, Direction direction, String imagePath1, String imagePath2, String outImagePath) 
	: Command(sessionPtr), direction(direction), imagePath1(imagePath1), 
	imagePath2(imagePath2), outImagePath(outImagePath)
{
}

Command* CollageCommand::clone() const
{
	return new CollageCommand(*this);
}
