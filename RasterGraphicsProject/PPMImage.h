#pragma once
#include "Image.h"
#include "TransformableImage.h"
#include "Vector.hpp"
class PPMImage : public Image, TransformableImage
{
public:
	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	void rotateLeft() override;
	void rotateRight() override;
protected:
	struct Pixel
	{
		int8_t R, G, B;
	};
private:
	Vector<Pixel> data;
};

