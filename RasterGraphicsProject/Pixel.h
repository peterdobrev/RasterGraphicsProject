#pragma once
#include <cstdint>
#include "ColorModifiableObject.h"
#include <fstream>

class Pixel : public ColorModifiableObject
{
public:
	Pixel();
	Pixel(uint8_t R, uint8_t G, uint8_t B);
	// Inherited via ColorModifiableObject
	void makeGreyscale() override;
	void makeMonochrome() override;
	void makeNegative() override;

	uint8_t getR() const;
	uint8_t getG() const;
	uint8_t getB() const;

	virtual ColorModifiableObject* clone() const override;

	friend std::ofstream& operator<<(std::ofstream& os, const Pixel& pixel);
private:
	uint8_t R, G, B;
};

