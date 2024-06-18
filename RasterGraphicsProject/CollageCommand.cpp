#include "CollageCommand.h"
#include "TransformableImageFactory.h"

void CollageCommand::execute() const
{
	PolymorphicPtr<TransformableImage> image1, image2;
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		if (imagePath1 == sessionPtr->getImageAtIndex(i).get()->getName())
		{
			image1 = sessionPtr->getImageAtIndex(i);
		}

		if (imagePath2 == sessionPtr->getImageAtIndex(i).get()->getName())
		{
			image2 = sessionPtr->getImageAtIndex(i);
		}
	}

	if (!image1.get() || !image2.get())
	{
		throw "Cannot make collage from selected images! Images are not loaded!";
	}
}

void CollageCommand::print() const
{
	std::cout << "Collage " << imagePath1 << " " << imagePath2 << " " << outImagePath;
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

PolymorphicPtr<TransformableImage> CollageCommand::createCollagedImage(
	PolymorphicPtr<TransformableImage> image1, PolymorphicPtr<TransformableImage> image2)
{
	image1.get()->save();
	image2.get()->save();

	switch (direction)
	{
	default:
	case CollageCommand::horizontal:
		if (image1.get()->getHeight() != image2.get()->getHeight())
		{
			throw std::exception("Error! Can't make a collage!");
		}
		break;
	case CollageCommand::vertical:
		if (image1.get()->getWidth() != image2.get()->getWidth())
		{
			throw std::exception("Error! Can't make a collage!");
		}
		break;
	}

	throw "not implemented";
}
