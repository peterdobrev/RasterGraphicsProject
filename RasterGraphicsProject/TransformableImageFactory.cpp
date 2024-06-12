#include "TransformableImageFactory.h"
#include <fstream>
#include "Bitset.h"
#include "Pixel.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

Vector<PolymorphicPtr<TransformableImage>> TransformableImageFactory::createImagesFromStringstream(std::stringstream& ss)
{
	Vector<PolymorphicPtr<TransformableImage>> images;
	while (true)
	{
		String imagePath;
		if (!(ss >> imagePath)) break;
		if (imagePath == "load") continue;
		images.pushBack(createImageFromFile(imagePath));
	}

	return images;
}

PolymorphicPtr<TransformableImage> TransformableImageFactory::createImageFromFile(String fileName)
{
	std::ifstream ifs;
	ifs.open(fileName.c_str(), std::ios::_Nocreate);

	if (!ifs.is_open())
	{
		throw std::exception("File is not opened!");
	}

    String magicNumber;
    ifs >> magicNumber;

	if (magicNumber == "P1")
	{
		return new PBMImage(fileName);
	}
	else if (magicNumber == "P2")
	{
		return new PGMImage(fileName);
	}
	else if (magicNumber == "P3")
	{
		return new PPMImage(fileName);
	}
	else if (magicNumber == "P4")
	{
		return new PBMImage(fileName);
	}
	else if (magicNumber == "P5")
	{
		return new PGMImage(fileName);
	}
	else if (magicNumber == "P6")
	{
		return new PPMImage(fileName);
	}
    else
    {
        throw std::runtime_error("Unsupported file format!");
    }
}
