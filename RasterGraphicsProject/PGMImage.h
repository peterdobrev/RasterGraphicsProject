#pragma once
#include "Image.h"
class PGMImage : public Image
{
private:
	int8_t* data = nullptr;
};

