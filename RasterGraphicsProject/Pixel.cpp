#include "Pixel.h"

Pixel::Pixel()
{
	R = G = B = 0;
}

Pixel::Pixel(uint8_t R, uint8_t G, uint8_t B)
{
	this->R = R;
	this->G = G;
	this->B = B;
}

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

uint8_t Pixel::getR() const
{
	return R;
}

uint8_t Pixel::getG() const
{
	return G;
}

uint8_t Pixel::getB() const
{
	return B;
}

ColorModifiableObject* Pixel::clone() const
{
	return new Pixel(*this);
}

std::ofstream& operator<<(std::ofstream& os, const Pixel& pixel)
{
	os << static_cast<int>(pixel.R) << " "
		<< static_cast<int>(pixel.G) << " "
		<< static_cast<int>(pixel.B);
	return os;
}
