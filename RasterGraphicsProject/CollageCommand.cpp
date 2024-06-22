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

	image1->loadData();
	image2->loadData();


	PolymorphicPtr<TransformableImage> collage = createCollagedImage(image1, image2);
	collage.get()->saveData();
	sessionPtr->addImage(std::move(collage));
}

void CollageCommand::printFeedback() const
{
	std::cout << "Collage \"" << imagePath1 << "\" with \"" << imagePath2 << "\" and save to \"" << outImagePath << "\" command executed!";
}

void CollageCommand::printInfo() const
{
	std::cout << "Collage \"" << imagePath1 << "\" with \"" << imagePath2 << "\" and save to \"" << outImagePath;
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
	PolymorphicPtr<TransformableImage> image1, PolymorphicPtr<TransformableImage> image2) const
{
	image1.get()->save();
	image2.get()->save();

	switch (direction)
	{
	default:
	case CollageCommand::horizontal:
		return image1.get()->collageHorizontalWith(image2.get(), outImagePath);
	case CollageCommand::vertical:
		return image1.get()->collageVerticalWith(image2.get(), outImagePath);
	}

	return PolymorphicPtr<TransformableImage>();
}
