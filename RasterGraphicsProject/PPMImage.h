#pragma once
#include "Image.h"
#include "TransformableObject.h"
#include "Vector.hpp"
#include "Pixel.h"

class PPMImage : public Image, TransformableObject
{
public:
	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	// rotateLeft are inherited
	// rotateRight are inherited

protected:
	void applyRotation() override;
private:
	Vector<Pixel> data;
};

