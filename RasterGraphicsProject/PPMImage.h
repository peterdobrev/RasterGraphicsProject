#pragma once
#include "Image.h"
class PPMImage : public Image
{
protected:
	struct Pixel
	{
		int8_t R, G, B;
	};
private:
	Pixel* data;
};

