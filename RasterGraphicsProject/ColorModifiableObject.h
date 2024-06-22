#pragma once
class ColorModifiableObject
{
public:
	virtual void makeGreyscale();
	virtual void makeMonochrome();
	virtual void makeNegative();

	virtual void undoMonochrome();
	virtual void undoGreyscale();

	virtual ColorModifiableObject* clone() const = 0;
	virtual ~ColorModifiableObject() = default;

protected:
	virtual void applyNegative() = 0;
	virtual void applyGreyscale() = 0;
	virtual void applyMonochrome() = 0;

	bool isNegative = false;
	bool isGreyscale = false;
	bool isMonochrome = false;
};

