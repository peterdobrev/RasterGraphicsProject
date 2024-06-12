#include "ImageDataLoader.h"
#include <fstream>

void ImageDataLoader::loadPBMData(PBMImage& image)
{
	std::ifstream file;
	file.open(image.getName().c_str());

	if (!file.is_open())
	{
		std::exception("Can't load PBM Data");
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
	std::ifstream file;
	file.open(image.getName().c_str());

	if (!file.is_open())
	{
		std::exception("Can't load PGM Data");
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
	std::ifstream file;
	file.open(image.getName().c_str());

	if (!file.is_open())
	{
		std::exception("Can't load PPM Data");
	}


	String magicNumber;
	file >> magicNumber;

	if (magicNumber == "P1")
	{
		loadPPMDataASCII(image, file);
	}
	else if (magicNumber == "P4")
	{
		loadPPMDataBinary(image, file);
	}
}

void ImageDataLoader::loadPBMDataASCII(PBMImage& image, std::ifstream& file)
{
	unsigned width, height;
	file >> height >> width;

	BitSet data(width * height);
	for (size_t i = 0; i < width * height; i++)
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
	unsigned width, height, maxValue;
	file >> height >> width >> maxValue;

	Vector<uint8_t> data(width * height);
	for (size_t i = 0; i < width * height; i++)
	{
		unsigned value;
		file >> value;
		if (value > maxValue)
		{
			throw std::invalid_argument("Value is bigger than allowed!");
		}

		data[i] = value;
	}

	image.data = data;
	image.width = width;
	image.height = height;
}

void ImageDataLoader::loadPGMDataBinary(PGMImage& image, std::ifstream& file)
{
	throw std::exception("Not implemented");
}

void ImageDataLoader::loadPPMDataASCII(PPMImage& image, std::ifstream& file)
{
	unsigned width, height, maxValue;
	file >> height >> width >> maxValue;

	Vector<Pixel> data(width * height);
	for (size_t i = 0; i < width * height; i++)
	{
		unsigned R, G, B;
		file >> R >> G >> B;
		if (R > maxValue || G > maxValue || B > maxValue)
		{
			throw std::invalid_argument("Value is bigger than allowed!");
		}

		Pixel pixel(R, G, B);
		data.pushBack(pixel);
	}

	image.data = data;
	image.width = width;
	image.height = height;
}

void ImageDataLoader::loadPPMDataBinary(PPMImage& image, std::ifstream& file)
{
	throw std::exception("Not implemented");
}
