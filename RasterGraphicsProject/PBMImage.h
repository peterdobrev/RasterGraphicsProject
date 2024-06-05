#pragma once
#include "Image.h"
#include "Bitset.h"
#include "TransformableImage.h"
class PBMImage : public Image, TransformableImage
{

	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	void rotateLeft() override;
	void rotateRight() override;
private:
	Bitset data;
};

