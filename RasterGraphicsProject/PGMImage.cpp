#include "PGMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

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
			data[i] = maxNumber - data[i];
		}
	}
}
void PGMImage::applyRotation() {
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

void PGMImage::rotate90Degrees()
{
	Vector<uint8_t> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[(width - 1 - x) * height + y] = data[y * width + x];
		}
	}
	std::swap(width, height);
	data = newData;
}

void PGMImage::rotate270Degrees()
{
	Vector<uint8_t> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[x * height + (height - 1 - y)] = data[y * width + x];
		}
	}
	std::swap(width, height);
	data = newData;
}

void PGMImage::rotate180Degrees()
{
	Vector<uint8_t> newData(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[(height - 1 - y) * width + (width - 1 - x)] = data[y * width + x];
		}
	}
	data = newData;
}


void PGMImage::loadData()
{
	ImageDataLoader::loadPGMData(*this);
}

void PGMImage::saveData()
{
	confirmChanges();
	ImageDataSaver::savePGMData(*this);
}

void PGMImage::clearData()
{
	data = Vector<uint8_t>();
	width = 0;
	height = 0;
}

const Vector<uint8_t>& PGMImage::getData() const
{
	return data;
}

uint8_t PGMImage::getMaxNumber() const
{
	return maxNumber;
}

PGMImage* PGMImage::clone() const
{
	return new PGMImage(*this);
}

PGMImage::PGMImage(String name)
	: TransformableImage(name) {}

PGMImage::PGMImage(Vector<uint8_t> data, String name, unsigned width, unsigned height, uint8_t maxNumber)
	: TransformableImage(name, width, height), data(data), maxNumber(maxNumber) {}
