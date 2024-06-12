#include "PBMImage.h"


void PBMImage::applyNegative()
{
	if (isNegative)
	{
		for (size_t i = 0; i < width * height; i++)
		{
			data.getBit(i) ? data.turnOffBit(i) : data.turnOnBit(i);
		}
	}
}

void PBMImage::applyMonochrome()
{
	// No changes to the image
}

void PBMImage::applyGreyscale()
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

TransformableImage* PBMImage::clone() const
{
	return new PBMImage(*this);
}

void PBMImage::loadData()
{
}

void PBMImage::saveData()
{
}

void PBMImage::clearData()
{
}


