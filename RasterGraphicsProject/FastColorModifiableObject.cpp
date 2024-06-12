#include "FastColorModifiableObject.h"

void FastColorModifiableObject::undoMonochrome()
{
	isMonochrome = false;
}

void FastColorModifiableObject::undoGreyscale()
{
	isGreyscale = false;
}

void FastColorModifiableObject::makeGreyscale()
{
	isGreyscale = true;
}

void FastColorModifiableObject::makeMonochrome()
{
	isMonochrome = true;
}

void FastColorModifiableObject::makeNegative()
{
	isNegative = !isNegative;
}
