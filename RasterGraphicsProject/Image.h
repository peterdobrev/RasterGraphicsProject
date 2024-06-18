	#pragma once
#include "String.h"

class Image
{
public:
	Image(String name) : name(name) {}
	Image(String name, unsigned width, unsigned height) : name(name), width(width), height(height) {}
	
	
	const String& getName() const;	
	unsigned getWidth() const;
	unsigned getHeight() const;

	void setName(const String& newName);

	virtual ~Image() = default;
protected:
	String name;
	unsigned width = 0;
	unsigned height = 0;
};

