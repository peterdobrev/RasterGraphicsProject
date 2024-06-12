#pragma once
#include "TransformableImage.h"
#include "Vector.hpp"
#include "PolymorphicPtr.hpp"
#include <sstream>

class TransformableImageFactory
{
public:
	static Vector<PolymorphicPtr<TransformableImage>> createImagesFromStringstream(std::stringstream& ss);
	static PolymorphicPtr<TransformableImage> createImageFromFile(String fileName);	
	TransformableImageFactory() = delete;
};

