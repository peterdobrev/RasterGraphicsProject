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
	Vector<ColorModifiablePixel> newData = data;
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[(width - 1 - x) * height + y] = data[y * width + x];
		}
	}
	std::swap(width, height);
	data = newData;
}

void PPMImage::rotate270Degrees()
{
	Vector<ColorModifiablePixel> newData = data;
	for (unsigned y = 0; y < height; ++y) {
		for (unsigned x = 0; x < width; ++x) {
			newData[x * height + (height - 1 - y)] = data[y * width + x];
		}
	}
	std::swap(width, height);
	data = newData;
}

PolymorphicPtr<TransformableImage> PPMImage::collageHorizontalWith(TransformableImage* image, String collageName)
{
	return image->collageHorizontalWithPPM(this, collageName);
}

PolymorphicPtr<TransformableImage> PPMImage::collageHorizontalWithPBM(PBMImage* image, String collageName)
{
	const char* errorMessage = "Collage error! Can't make collage from different image types (.ppm, .pbm)!";
	throw std::exception(errorMessage);
}

PolymorphicPtr<TransformableImage> PPMImage::collageHorizontalWithPGM(PGMImage* image, String collageName)
{
	const char* errorMessage = "Collage error! Can't make collage from different image types (.ppm, .pgm)!";
	throw std::exception(errorMessage);
}

PolymorphicPtr<TransformableImage> PPMImage::collageHorizontalWithPPM(PPMImage* image, String collageName)
{
	if (this->getHeight() != image->getHeight())
	{
		const char* errorMessage = "Collage error! Image heights don't match!";
		throw std::exception(errorMessage);
	}

	uint8_t collageMaxNumber = std::max(maxNumber, image->maxNumber);

	Vector<ColorModifiablePixel> collageData(height * (width + image->width));
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
		(new PPMImage(collageData, collageName, width + image->width, height, collageMaxNumber));
}

PolymorphicPtr<TransformableImage> PPMImage::collageVerticalWith(TransformableImage* image, String collageName)
{
	return image->collageVerticalWithPPM(this, collageName);
}

PolymorphicPtr<TransformableImage> PPMImage::collageVerticalWithPBM(PBMImage* image, String collageName)
{
	const char* errorMessage = "Collage error! Can't make collage from different image types (.ppm, .pbm)!";
	throw std::exception(errorMessage);
}

PolymorphicPtr<TransformableImage> PPMImage::collageVerticalWithPGM(PGMImage* image, String collageName)
{
	const char* errorMessage = "Collage error! Can't make collage from different image types (.ppm, .pgm)!";
	throw std::exception(errorMessage);
}

PolymorphicPtr<TransformableImage> PPMImage::collageVerticalWithPPM(PPMImage* image, String collageName)
{
	if (this->getWidth() != image->getWidth())
	{
		const char* errorMessage = "Collage error! Image heights don't match!";
		throw std::exception(errorMessage);
	}

	uint8_t collageMaxNumber = std::max(maxNumber, image->maxNumber);

	Vector<ColorModifiablePixel> collageData((height + image->height) * width);
	for (size_t i = 0; i < height * width; i++)
	{
		collageData.pushBack(data[i]);
	}

	for (size_t i = 0; i < image->height * width; i++)
	{
		collageData.pushBack(image->data[i]);
	}

	return PolymorphicPtr<TransformableImage>
		(new PPMImage(std::move(collageData), collageName, width, height + image->height, collageMaxNumber));
}


void PPMImage::rotate180Degrees()
{
	Vector<ColorModifiablePixel> newData = data;
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

PPMImage::PPMImage(Vector<ColorModifiablePixel> data, String name, unsigned width, unsigned height, uint8_t maxNumber)
	: TransformableImage(name, width, height), data(data), maxNumber(maxNumber) {
}
