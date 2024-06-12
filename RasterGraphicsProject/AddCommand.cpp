#include "AddCommand.h"
#include "TransformableImageFactory.h"

void AddCommand::execute() const
{
	size_t length = sessionPtr->images.getSize();
	for (size_t i = 0; i < length; i++)
	{
		if (sessionPtr->images[i].get()->getName() == fileName)
		{
			// Don't add if already added!
			return;
		}
	}

	PolymorphicPtr<TransformableImage> image = TransformableImageFactory::createImageFromFile(fileName);
	sessionPtr->images.pushBack(image);
}

AddCommand::AddCommand(Session* sessionPtr, String fileName) : UndoCommand(sessionPtr), fileName(fileName)
{
	
}

Command* AddCommand::clone() const
{
	return new AddCommand(*this);
}

void AddCommand::undo() const
{

}
