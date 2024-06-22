#include "PGMImage.h"
#include "ImageDataLoader.h"
#include "ImageDataSaver.h"

void PGMImage::applyMonochrome()
{
	if (!isMonochrome) return;

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
	if (!isNegative) return;
	
	size_t length = data.getSize();
	for (size_t i = 0; i < length; i++)
	{
		data[i] = maxNumber - data[i];
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
	Vector<uint8_t> newData = data;
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[(width - 1 - x) * (height - 1) + y] = data[y * (width - 1) + x];
		}
	}
	std::swap(width, height);
	data = newData;
}

void PGMImage::rotate270Degrees()
{
	Vector<uint8_t> newData = data;
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[x * (height-1) + (height - 1 - y)] = data[y * (width-1) + x];
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
			newData[(height - 1 - y) * (width - 1) + (width - 1 - x)] = data[y * (width - 1) + x];
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

PolymorphicPtr<TransformableImage> PGMImage::collageHorizontalWith(TransformableImage* image, String collageName)
{
	return image->collageHorizontalWithPGM(this, collageName);
}

PolymorphicPtr<TransformableImage> PGMImage::collageHorizontalWithPBM(PBMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PGMImage::collageHorizontalWithPGM(PGMImage* image, String collageName)
{
	if (this->getHeight() != image->getHeight())
	{
		const char* errorMessage = "Collage error! Image heights don't match!";
		throw std::exception(errorMessage);
	}

	uint8_t collageMaxNumber = std::max(maxNumber, image->maxNumber);

	Vector<uint8_t> collageData(height * (width + image->width));
	for (size_t row = 0; row < height; ++row)
	{
		for (size_t col = 0; col < width; ++col)
		{
			collageData.pushBack(data[row * width + col]);
		}
		for (size_t col = 0; col < image->width; ++col)
		{
			collageData.pushBack(image->data[row * image->width + col]);
		}
	}

	return PolymorphicPtr<TransformableImage>
		(new PGMImage(collageData, collageName, width + image->width, height, collageMaxNumber));
}

PolymorphicPtr<TransformableImage> PGMImage::collageHorizontalWithPPM(PPMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PGMImage::collageVerticalWith(TransformableImage* image, String collageName)
{
	return image->collageVerticalWithPGM(this, collageName);
}

PolymorphicPtr<TransformableImage> PGMImage::collageVerticalWithPBM(PBMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
}

PolymorphicPtr<TransformableImage> PGMImage::collageVerticalWithPGM(PGMImage* image, String collageName)
{
	if (this->getWidth() != image->getWidth())
	{
		const char* errorMessage = "Collage error! Image heights don't match!";
		throw std::exception(errorMessage);
	}

	uint8_t collageMaxNumber = std::max(maxNumber, image->maxNumber);

	Vector<uint8_t> collageData((height + image->height) * width);
	for (size_t i = 0; i < height * width; i++)
	{
		collageData.pushBack(data[i]);
	}

	for (size_t i = 0; i < image->height * width; i++)
	{
		collageData.pushBack(image->data[i]);
	}

	return PolymorphicPtr<TransformableImage>
		(new PGMImage(std::move(collageData), collageName, width, height + image->height, collageMaxNumber));
}

PolymorphicPtr<TransformableImage> PGMImage::collageVerticalWithPPM(PPMImage* image, String collageName)
{
	const char* message = "Error!Images are different types!";
	throw std::runtime_error(message);
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
