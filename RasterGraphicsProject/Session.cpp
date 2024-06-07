#include "Session.h"
#include <iostream>

void Session::print() const
{
	size_t imagesLength = images.getSize();
	size_t commandsLength = commands.getSize();

	std::cout << "Name of images in the session: ";
	for (size_t i = 0; i < imagesLength; i++)
	{
		std::cout << (*images[i])->getName() << " ";
	}
	std::cout << std::endl;
	std::cout << "Pending transformations: ";
	for (size_t i = 0; i < commandsLength; i++)
	{
		std::cout << 
	}
}
