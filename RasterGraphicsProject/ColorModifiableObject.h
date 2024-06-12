#pragma once
class ColorModifiableObject
{
public:
	virtual void makeGreyscale() = 0;
	virtual void makeMonochrome() = 0;
	virtual void makeNegative() = 0;
	virtual ColorModifiableObject* clone() const = 0;
	virtual ~ColorModifiableObject() = default;
};

