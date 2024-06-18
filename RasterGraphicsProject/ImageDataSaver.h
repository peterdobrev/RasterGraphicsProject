#pragma once

#include <fstream>

#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

class ImageDataSaver
{
public:
	static void savePBMData(const PBMImage& image);
	static void savePGMData(const PGMImage& image);
	static void savePPMData(const PPMImage& image);
private:
	ImageDataSaver() = delete;
};

