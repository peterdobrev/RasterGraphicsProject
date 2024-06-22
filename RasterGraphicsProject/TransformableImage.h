#pragma once
#include "TransformableObject.h"
#include "Image.h"
#include "LoadableObject.h"
#include "CollageVisitor.h"
class TransformableImage : public Image, public TransformableObject, public LoadableObject, public CollageVisitor
{
public:
	virtual void save() override;
	TransformableImage(String name) : Image(name) {}
	TransformableImage(String name, unsigned width, unsigned height) : Image(name, width, height) 
	{ isLoaded = true; }
	virtual TransformableImage* clone() const override = 0;
};

