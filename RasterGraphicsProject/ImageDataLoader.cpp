#include "ImageDataLoader.h"
#include <fstream>

void ImageDataLoader::loadPBMData(PBMImage& image)
{
	std::ifstream file(image.getName().c_str(), std::ios::in);

	if (!file.is_open())
	{
		const char* message = "Can't load PBM Data";
		throw std::exception(message);
	}


	String magicNumber;
	file >> magicNumber;

	if (magicNumber == "P1")
	{
		loadPBMDataASCII(image, file);
	}
	else if (magicNumber == "P4")
	{
		loadPBMDataBinary(image, file);
	}
}

void ImageDataLoader::loadPGMData(PGMImage& image)
{
	std::ifstream file(image.getName().c_str(), std::ios::in);

	if (!file.is_open())
	{
		const char* message = "Can't load PGM Data";
		throw std::exception(message);
	}

	String magicNumber;
	file >> magicNumber;

	if (magicNumber == "P2")
	{
		loadPGMDataASCII(image, file);
	}
	else if (magicNumber == "P5")
	{
		loadPGMDataBinary(image, file);
	}
}

void ImageDataLoader::loadPPMData(PPMImage& image)
{
	std::ifstream file(image.getName().c_str(), std::ios::in);

	if (!file.is_open())
	{
		const char* message = "Can't load PPM Data";
		throw std::exception(message);
	}


	String magicNumber;
	file >> magicNumber;

	if (magicNumber == "P3")
	{
		loadPPMDataASCII(image, file);
	}
	else if (magicNumber == "P6")
	{
		loadPPMDataBinary(image, file);
	}
}

void ImageDataLoader::loadPBMDataASCII(PBMImage& image, std::ifstream& file)
{
	unsigned width, height;
	file >> width >> height;

	BitSet data(width * height);
	for (unsigned i = 0; i < width * height; i++)
	{
		char bit;
		file >> bit;
		if (bit == '1')
		{
			data.turnOnBit(i);
		}
	}

	image.data = data;
	image.width = width;
	image.height = height;
}

void ImageDataLoader::loadPBMDataBinary(PBMImage& image, std::ifstream& file)
{
	throw std::exception("Not implemented");
}

void ImageDataLoader::loadPGMDataASCII(PGMImage& image, std::ifstream& file)
{
	unsigned width, height, maxNumber;
	file >> width >> height >> maxNumber;

	Vector<uint8_t> data(width * height);
	for (unsigned i = 0; i < width * height; i++)
	{
		unsigned value;
		file >> value;
		if (value > maxNumber)
		{
			throw std::invalid_argument("Value is bigger than allowed!");
		}
		data.pushBack(value);
	}

	image.data = data;
	image.width = width;
	image.height = height;
	image.maxNumber = maxNumber;
}

void ImageDataLoader::loadPGMDataBinary(PGMImage& image, std::ifstream& file)
{
	throw std::exception("Not implemented");
}

void ImageDataLoader::loadPPMDataASCII(PPMImage& image, std::ifstream& file)
{
	unsigned width, height, maxNumber;
	file >> width >> height >> maxNumber;

	Vector<ColorModifiablePixel> data(width * height);
	for (unsigned i = 0; i < width * height; i++)
	{
		unsigned R, G, B;
		file >> R >> G >> B;
		if (R > maxNumber || G > maxNumber || B > maxNumber)
		{
			throw std::invalid_argument("Value is bigger than allowed!");
		}

		ColorModifiablePixel pixel(R, G, B);
		data.pushBack(pixel);
	}

	image.data = data;
	image.width = width;
	image.height = height;
	image.maxNumber = maxNumber;
}

void ImageDataLoader::loadPPMDataBinary(PPMImage& image, std::ifstream& file)
{
	throw std::exception("Not implemented");
}