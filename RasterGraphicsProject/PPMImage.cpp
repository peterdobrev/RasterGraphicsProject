#include "PPMImage.h"

void PPMImage::applyMonochrome()
{
	if (isMonochrome) return;

	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeMonochrome();
	}
	isMonochrome = true;
}

void PPMImage::applyGreyscale()
{
	if (isGreyscale) return;

	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeGreyscale();
	}
	isGreyscale = true;
}

void PPMImage::applyNegative()
{
	if (isNegative)
	{
		size_t length = data.getSize();
		for (size_t i = 0; i < length; i++)
		{
			data[i].makeNegative();
		}
	}
}

void PPMImage::applyRotation()
{
}

void PPMImage::loadData()
{
}

void PPMImage::saveData()
{
}

void PPMImage::clearData()
{
}

PPMImage* PPMImage::clone() const
{
	return new PPMImage(*this);
}
