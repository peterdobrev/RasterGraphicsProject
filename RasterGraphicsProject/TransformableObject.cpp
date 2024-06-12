#include "TransformableObject.h"

void TransformableObject::confirmChanges()
{
	applyRotation();
	applyMonochrome();
	applyGreyscale();
	applyRotation();
}
