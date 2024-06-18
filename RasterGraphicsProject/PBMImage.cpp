#include "PBMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

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


