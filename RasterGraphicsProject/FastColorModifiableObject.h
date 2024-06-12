#pragma once
#include "ColorModifiableObject.h"
class FastColorModifiableObject : public ColorModifiableObject
{
public:
	virtual void undoMonochrome();
	virtual void undoGreyscale();

	virtual void makeGreyscale() override;
	virtual void makeMonochrome() override;
	virtual void makeNegative() override;

protected:
	virtual void applyNegative() = 0;
	virtual void applyGreyscale() = 0;
	virtual void applyMonochrome() = 0;

	bool isNegative = false;
	bool isGreyscale = false;
	bool isMonochrome = false;
};

