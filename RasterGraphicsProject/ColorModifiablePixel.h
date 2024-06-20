#pragma once
#include "Pixel.h"
class ColorModifiablePixel : public Pixel
{
public:
	ColorModifiablePixel();
	ColorModifiablePixel(uint8_t R, uint8_t G, uint8_t B);

	void makeGreyscale();
	void makeMonochrome(uint8_t maxNumber = 255);
	void makeNegative(uint8_t maxNumber = 255);
};

