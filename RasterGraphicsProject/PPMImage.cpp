#include "PPMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

void PPMImage::applyMonochrome()
{
	if (!isMonochrome) return;

	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeMonochrome(maxNumber);
	}
	isMonochrome = true;
}

void PPMImage::applyGreyscale()
{
	if (!isGreyscale) return;

	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeGreyscale();
	}
	isGreyscale = true;
}

void PPMImage::applyNegative()
{
	if (!isNegative) return;
		
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i].makeNegative(maxNumber);
	}
}

void PPMImage::applyRotation() {
	switch (direction) {
	case Direction::top:
		// No change needed
		break;
	case Direction::left:
		rotate90Degrees();
		break;
	case Direction::bottom:
		rotate180Degrees();
		break;
	case Direction::right:
		rotate270Degrees();
		break;
	default:
		break;
	}
}

void PPMImage::rotate90Degrees()
{
	Vector<ColorModifiablePixel> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			unsigned newDataInd = (width - 1 - x) * height + y;
			unsigned dataInd = y * width + x;
			newData[newDataInd] = data[dataInd];
		}
	}
	std::swap(width, height);
	data = newData;
}

void PPMImage::rotate270Degrees()
{
	Vector<ColorModifiablePixel> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[x * height + (height - 1 - y)] = data[y * width + x];
		}
	}
	std::swap(width, height);
	data = newData;
}


void PPMImage::rotate180Degrees()
{
	Vector<ColorModifiablePixel> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[(height - 1 - y) * width + (width - 1 - x)] = data[y * width + x];
		}
	}
	data = newData;
}


void PPMImage::loadData()
{
	ImageDataLoader::loadPPMData(*this);
	isLoaded = true;
}

void PPMImage::saveData()
{
	confirmChanges();
	ImageDataSaver::savePPMData(*this);
}

void PPMImage::clearData()
{
	data = Vector<ColorModifiablePixel>();
	width = 0;
	height = 0;
	isLoaded = false;
}

const Vector<ColorModifiablePixel>& PPMImage::getData() const
{
	return data;
}

uint8_t PPMImage::getMaxNumber() const
{
	return maxNumber;
}

PPMImage* PPMImage::clone() const
{
	return new PPMImage(*this);
}

PPMImage::PPMImage(String name)
	: TransformableImage(name) {}

PPMImage::PPMImage(Vector<ColorModifiablePixel> data, String name, unsigned width, unsigned height)
	: TransformableImage(name, width, height), data(data) {}
