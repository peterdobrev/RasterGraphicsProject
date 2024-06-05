#pragma once
#include "Vector.hpp"
#include "Image.h"
#include "TransformableImage.h"
class PGMImage : public Image, TransformableImage
{
	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	void rotateLeft() override;
	void rotateRight() override;
private:
	 Vector<uint8_t> data;
};

