#pragma once
#include "ColorModifiableObject.h"
#include "RotatableObject.h"

class TransformableObject : public ColorModifiableObject, public RotatableObject
{
public:
	virtual void confirmChanges();
	TransformableObject* clone() const override = 0;
};