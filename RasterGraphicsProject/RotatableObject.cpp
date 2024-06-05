#include "RotatableObject.h"
void RotatableObject::rotateLeft()
{
	direction = static_cast<Direction>((static_cast<int>(direction) + 1) % 4);
}

void RotatableObject::rotateRight()
{
	direction = static_cast<Direction>((static_cast<int>(direction) + 3) % 4);
}
