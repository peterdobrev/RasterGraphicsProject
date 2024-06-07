	#pragma once
#include "String.h"

class Image
{
public:
	const String& getName() const;
protected:
	String name;
	unsigned width;
	unsigned height;
};

