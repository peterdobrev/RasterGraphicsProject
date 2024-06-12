#include "PGMImage.h"

void PGMImage::applyMonochrome()
{
	if (isMonochrome) return;

	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i] = data[i] >= UINT8_MAX / 2 ? UINT8_MAX : 0;
	}

	isMonochrome = true;
}

void PGMImage::applyGreyscale()
{
	// No changes to image
}

void PGMImage::applyNegative()
{
	if (isNegative)
	{
		size_t length = data.getSize();
		for (size_t i = 0; i < length; i++)
		{
			data[i] = UINT8_MAX - data[i];
		}
	}
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

void PGMImage::loadData()
{
}

void PGMImage::saveData()
{
}

void PGMImage::clearData()
{
}

PGMImage* PGMImage::clone() const
{
	return new PGMImage(*this);
}
