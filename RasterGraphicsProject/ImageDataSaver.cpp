#include "ImageDataSaver.h"

#include <fstream>

namespace ImageDataSaverHelper{

	void openFile(std::ofstream& file, const String& name) {
		file.open(name.c_str());
		if (!file.is_open()) {
			throw std::runtime_error("File for saving image is not open!");
		}
	}

	void writeHeader(std::ofstream& file, const String& format, unsigned width, unsigned height, int maxNumber = -1) {
		file << format << std::endl;
		file << width << " " << height << std::endl;
		if(maxNumber >= 0)
			file << maxNumber << std::endl;
	}

	template <typename T>
	void writeData(std::ofstream& file, const T& data, unsigned width, size_t length) {
		for (unsigned i = 0; i < length; i++) {
			file << data[i] << " ";
			if (i % width == width - 1) {
				file << std::endl;
			}
		}
	}
}

void ImageDataSaver::savePBMData(const PBMImage& image)
{
	std::ofstream file;
	ImageDataSaverHelper::openFile(file, image.getName());
	ImageDataSaverHelper::writeHeader(file, "P1", image.getWidth(), image.getHeight());
	ImageDataSaverHelper::writeData(file, image.getData(), image.getWidth(), image.getData().getN());
}

void ImageDataSaver::savePGMData(const PGMImage& image)
{
	std::ofstream file;
	ImageDataSaverHelper::openFile(file, image.getName());
	ImageDataSaverHelper::writeHeader(file, "P2", image.getWidth(), image.getHeight(), static_cast<int>(image.getMaxNumber()));
	ImageDataSaverHelper::writeData(file, image.getData(), image.getWidth(), image.getData().getSize());
}

void ImageDataSaver::savePPMData(const PPMImage& image)
{
	std::ofstream file;
	ImageDataSaverHelper::openFile(file, image.getName());
	ImageDataSaverHelper::writeHeader(file, "P3", image.getWidth(), image.getHeight(), static_cast<int>(image.getMaxNumber()));
	ImageDataSaverHelper::writeData(file, image.getData(), image.getWidth(), image.getData().getSize());
}

