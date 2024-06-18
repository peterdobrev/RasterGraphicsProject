#include "PPMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

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
	ImageDataLoader::loadPPMData(*this);
}

void PPMImage::saveData()
{
	confirmChanges();
	ImageDataSaver::savePPMData(*this);
}

void PPMImage::clearData()
{
	data = Vector<Pixel>();
	width = 0;
	height = 0;
}

const Vector<Pixel>& PPMImage::getData() const
{
	return data;
}

PPMImage* PPMImage::clone() const
{
	return new PPMImage(*this);
}

PPMImage::PPMImage(String name)
	: TransformableImage(name) {}

PPMImage::PPMImage(Vector<Pixel> data, String name, unsigned width, unsigned height)
	: TransformableImage(name, width, height), data(data) {}
