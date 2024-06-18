#include "AddCommand.h"
#include "TransformableImageFactory.h"

void AddCommand::execute() const
{
	size_t length = sessionPtr->getImagesCount();
	for (size_t i = 0; i < length; i++)
	{
		if (sessionPtr->getImageAtIndex(i).get()->getName() == fileName)
		{
			// Don't add if already added!
			return;
		}
	}

	PolymorphicPtr<TransformableImage> image = TransformableImageFactory::createImageFromFile(fileName);
	sessionPtr->addImage(image);
}

void AddCommand::print() const
{
	std::cout << "Add " << fileName;
}

AddCommand::AddCommand(Session* sessionPtr, String fileName) : Command(sessionPtr), fileName(fileName)
{
		
}

Command* AddCommand::clone() const
{
	return new AddCommand(*this);
}

