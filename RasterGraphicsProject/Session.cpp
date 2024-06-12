#include "Session.h"
#include <iostream>
#include "Command.h"

void Session::execute()
{
	size_t length = commands.getSize();
	for (size_t i = 0; i < length; i++)
	{
		commands[i].get()->execute();
	}
}

void Session::print() const
{
	size_t imagesLength = images.getSize();
	size_t commandsLength = commands.getSize();

	std::cout << "Name of images in the session: ";
	for (size_t i = 0; i < imagesLength; i++)
	{
		std::cout << images[i]->getName() << " ";
	}
	std::cout << std::endl;
	std::cout << "Pending transformations: ";
	for (size_t i = 0; i < commandsLength; i++)
	{
		// print transformations	
	}
}

Session::Session(Vector<PolymorphicPtr<TransformableImage>> images, Vector<PolymorphicPtr<Command>> commands)
	: images(images), commands(commands), id(0)
{

}
