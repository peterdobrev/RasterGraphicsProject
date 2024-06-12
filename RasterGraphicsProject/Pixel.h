#pragma once
#include <cstdint>
#include "ColorModifiableObject.h"

class Pixel : public ColorModifiableObject
{
public:
	Pixel();
	Pixel(uint8_t R, uint8_t G, uint8_t B);
	// Inherited via ColorModifiableObject
	void makeGreyscale() override;
	void makeMonochrome() override;
	void makeNegative() override;
	virtual ColorModifiableObject* clone() const override;
private:
	uint8_t R, G, B;

	// Inherited via ColorModifiableObject
};

