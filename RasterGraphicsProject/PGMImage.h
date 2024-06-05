#pragma once
#include "Vector.hpp"
#include "Image.h"
#include "TransformableObject.h"

class PGMImage : public Image, TransformableObject
{
	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	// rotateLeft are inherited
	// rotateRight are inherited

protected:
	void applyRotation() override;
private:
	 Vector<uint8_t> data;
};

