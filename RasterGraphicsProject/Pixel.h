#pragma once
#include <cstdint>
#include "ColorModifiableObject.h"

class Pixel : public ColorModifiableObject
{
	uint8_t R, G, B;

public:
	// Inherited via ColorModifiableObject
	void makeGreyscale() override;
	void makeMonochrome() override;
	void makeNegative() override;

};

