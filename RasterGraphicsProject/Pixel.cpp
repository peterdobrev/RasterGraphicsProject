#include "Pixel.h"

void Pixel::makeGreyscale()
{
	R = G = B = (R + G + B) / 3;
}

void Pixel::makeMonochrome()
{
	R = G = B = ((R + G + B) / 3) > -(UINT8_MAX / 2) ? UINT8_MAX : 0;
}

void Pixel::makeNegative()
{
	R = UINT8_MAX - R;
	G = UINT8_MAX - G;
	B = UINT8_MAX - B;
}
