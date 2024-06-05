#include "PBMImage.h"

void PBMImage::makeNegative()
{
	for (size_t i = 0; i < width * height; i++)
	{
		data.getBit(i) ? data.turnOffBit(i) : data.turnOnBit(i);
	}
}

void PBMImage::makeMonochrome()
{
	// No changes to the image
}

void PBMImage::makeGreyscale()
{
	// No changes to the image
}

void PBMImage::applyRotation()
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


