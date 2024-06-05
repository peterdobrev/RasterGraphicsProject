#include "PPMImage.h"

void PPMImage::makeNegative()
{
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeNegative();
	}
}

void PPMImage::makeMonochrome()
{
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeMonochrome();
	}
}

void PPMImage::makeGreyscale()
{
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeGreyscale();
	}
}
