#pragma once

#include <fstream>

#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

class ImageDataLoader
{
public:
	static void loadPBMData(PBMImage& image);
	static void loadPGMData(PGMImage& image);
	static void loadPPMData(PPMImage& image);
private:
	static void loadPBMDataASCII(PBMImage& image, std::ifstream& file);
	static void loadPBMDataBinary(PBMImage& image, std::ifstream& file);
	static void loadPGMDataASCII(PGMImage& image, std::ifstream& file);
	static void loadPGMDataBinary(PGMImage& image, std::ifstream& file);
	static void loadPPMDataASCII(PPMImage& image, std::ifstream& file);
	static void loadPPMDataBinary(PPMImage& image, std::ifstream& file);
	ImageDataLoader() = delete;
};

