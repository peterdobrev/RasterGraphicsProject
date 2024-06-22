#include "TransformableObject.h"

void TransformableObject::confirmChanges()
{
	applyRotation();
	applyMonochrome();
	applyGreyscale();
	applyNegative();

	direction = top;
	isMonochrome = false;
	isGreyscale = false;
	isNegative = false;
}
