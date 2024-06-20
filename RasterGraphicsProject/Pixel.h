#pragma once
#include <cstdint>
#include <fstream>

class Pixel 
{
public:
	Pixel();
	Pixel(uint8_t R, uint8_t G, uint8_t B);

	uint8_t getR() const;
	uint8_t getG() const;
	uint8_t getB() const;

	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
protected:
	uint8_t R = 0, G = 0, B = 0;
};

