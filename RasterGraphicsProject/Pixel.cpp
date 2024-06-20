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

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	os << static_cast<int>(pixel.R) << " "
		<< static_cast<int>(pixel.G) << " "
		<< static_cast<int>(pixel.B);
	return os;
}
