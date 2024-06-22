#include "TransformableImage.h"

void TransformableImage::save()
{
	if ((isMonochrome || isNegative || isGreyscale || direction != top))
	{
		LoadableObject::save();
	}
}
