#include "ColorModifiablePixel.h"

ColorModifiablePixel::ColorModifiablePixel() = default;

ColorModifiablePixel::ColorModifiablePixel(uint8_t R, uint8_t G, uint8_t B)
	: Pixel(R, G, B)
{
}

void ColorModifiablePixel::makeGreyscale()
{
	R = G = B = (R + G + B) / 3;
}

void ColorModifiablePixel::makeMonochrome(uint8_t maxNumber)
{
	R = G = B = ((R + G + B) / 3) > (maxNumber / 2) ? maxNumber : 0;
}

void ColorModifiablePixel::makeNegative(uint8_t maxNumber)
{
	R = maxNumber - R;
	G = maxNumber - G;
	B = maxNumber - B;
}