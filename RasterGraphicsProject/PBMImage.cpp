#include "PBMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

void PBMImage::applyNegative()
{
	if (!isNegative) return;

	for (unsigned i = 0; i < width * height; i++)
	{
		data.getBit(i) ? data.turnOffBit(i) : data.turnOnBit(i);
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

PolymorphicPtr<TransformableImage> PBMImage::collageHorizontalWith(TransformableImage* image, String collageName)
{
	return image->collageHorizontalWithPBM(this, collageName);
}

PolymorphicPtr<TransformableImage> PBMImage::collageHorizontalWithPBM(PBMImage* image, String collageName)
{
	if (this->getHeight() != image->getHeight())
	{
		throw std::runtime_error("Collage error! Image heights don't match!");
	}

	unsigned collageWidth = width + image->width;

	BitSet collageData(height * collageWidth);

	for (size_t row = 0; row < height; ++row)
	{
		for (size_t col = 0; col < width; ++col)
		{
			if (data.getBit(row * width + col))
			{
				collageData.turnOnBit(row * collageWidth + col);
			}
		}
		for (size_t col = 0; col < image->width; ++col)
		{
			if (image->data.getBit(row * image->width + col))
			{
				collageData.turnOnBit(row * collageWidth + (width + col));
			}
		}
	}

	return PolymorphicPtr<TransformableImage>(
		new PBMImage(collageData, collageName, collageWidth, height)
		);
}


PolymorphicPtr<TransformableImage> PBMImage::collageHorizontalWithPGM(PGMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PBMImage::collageHorizontalWithPPM(PPMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PBMImage::collageVerticalWith(TransformableImage* image, String collageName)
{
	return image->collageVerticalWithPBM(this, collageName);
}

PolymorphicPtr<TransformableImage> PBMImage::collageVerticalWithPBM(PBMImage* image, String collageName)
{
	if (this->getWidth() != image->getWidth())
	{
		throw std::runtime_error("Collage error! Image widths don't match!");
	}

	unsigned collageHeight = height + image->height;

	BitSet collageData(collageHeight * width);

	for (size_t row = 0; row < height; ++row)
	{
		for (size_t col = 0; col < width; ++col)
		{
			if (data.getBit(row * width + col))
			{
				collageData.turnOnBit(row * width + col);
			}
		}
	}

	for (size_t row = 0; row < image->height; ++row)
	{
		for (size_t col = 0; col < width; ++col)
		{
			if (image->data.getBit(row * width + col))
			{
				collageData.turnOnBit((row + height) * width + col);
			}
		}
	}

	return PolymorphicPtr<TransformableImage>(
		new PBMImage(collageData, collageName, width, collageHeight)
		);
}


PolymorphicPtr<TransformableImage> PBMImage::collageVerticalWithPGM(PGMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PBMImage::collageVerticalWithPPM(PPMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}
