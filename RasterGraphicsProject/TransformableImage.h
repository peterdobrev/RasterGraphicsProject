#pragma once
#include "TransformableObject.h"
#include "Image.h"
#include "LoadableObject.h"
class TransformableImage : public Image, public TransformableObject, public LoadableObject
{
public:
	TransformableImage(String name) : Image(name) {}
	TransformableImage(String name, unsigned width, unsigned height) : Image(name, width, height) {}
	virtual TransformableImage* clone() const override = 0;
};

