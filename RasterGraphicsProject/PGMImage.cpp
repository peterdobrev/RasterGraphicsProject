#include "PGMImage.h"

void PGMImage::makeNegative()
{
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i] = UINT8_MAX - data[i];
	}
}

void PGMImage::makeMonochrome()
{
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i] = data[i] >= UINT8_MAX / 2 ? UINT8_MAX : 0;
	}
}

void PGMImage::makeGreyscale()
{
	// No changes to image
}

void PGMImage::applyRotation()
{
	switch (direction)
	{
	case RotatableObject::Direction::top:
		break;
	case RotatableObject::Direction::left:
		break;
	case RotatableObject::Direction::bottom:
		break;
	case RotatableObject::Direction::right:
		break;
	default:
		break;
	}
}
