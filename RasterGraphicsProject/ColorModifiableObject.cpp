#include "ColorModifiableObject.h"

void ColorModifiableObject::undoMonochrome()
{
	isMonochrome = false;
}

void ColorModifiableObject::undoGreyscale()
{
	isGreyscale = false;
}

void ColorModifiableObject::makeGreyscale()
{
	isGreyscale = true;
}

void ColorModifiableObject::makeMonochrome()
{
	isMonochrome = true;
}

void ColorModifiableObject::makeNegative()
{
	isNegative = !isNegative;
}
