#pragma once
#include "FastColorModifiableObject.h"
#include "RotatableObject.h"

class TransformableObject : public FastColorModifiableObject, public RotatableObject
{
public:
	virtual void confirmChanges();
	TransformableObject* clone() const override = 0;
};