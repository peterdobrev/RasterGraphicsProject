#include "PBMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

void PBMImage::applyNegative()
{
	if (isNegative)
	{
		for (unsigned i = 0; i < width * height; i++)
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

void PBMImage::applyRotation() {
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

void PBMImage::rotate90Degrees()
{
	BitSet newBitSet(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (data.getBit(y * width + x)) {
				newBitSet.turnOnBit((width - 1 - x) * height + y);
			}
		}
	}
	std::swap(width, height);
	data = newBitSet;
}

void PBMImage::rotate270Degrees()
{
	BitSet newBitSet(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (data.getBit(y * width + x)) {
				newBitSet.turnOnBit(x * height + (height - 1 - y));
			}
		}
	}
	std::swap(width, height);
	data = newBitSet;
}

void PBMImage::rotate180Degrees()
{
	BitSet newBitSet(width * height);
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			if (data.getBit(y * width + x)) {
				newBitSet.turnOnBit((height - 1 - y) * width + (width - 1 - x));
			}
		}
	}
	data = newBitSet;
}


PBMImage::PBMImage(BitSet data, String name, unsigned width, unsigned height)
	: TransformableImage(name, width, height), data(data) {}

TransformableImage* PBMImage::clone() const
{
	return new PBMImage(*this);
}

const BitSet& PBMImage::getData() const
{
	return data;
}

void PBMImage::loadData()
{
	ImageDataLoader::loadPBMData(*this);
}

void PBMImage::saveData()
{
	confirmChanges();
	ImageDataSaver::savePBMData(*this);
}

void PBMImage::clearData()
{
	data = BitSet();
	width = 0;
	height = 0;
}

PBMImage::PBMImage(String name)
	: TransformableImage(name) {}

