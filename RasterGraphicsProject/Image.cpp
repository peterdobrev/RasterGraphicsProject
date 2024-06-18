#include "Image.h"

const String& Image::getName() const
{
	return name;
}

unsigned Image::getWidth() const
{
	return width;
}

unsigned Image::getHeight() const
{
	return height;
}

void Image::setName(const String& newName)
{
	name = newName;
}
