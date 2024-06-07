#pragma once
class ColorModifiableObject
{
public:
	virtual void makeGreyscale() = 0;
	virtual void makeMonochrome() = 0;
	virtual void makeNegative() = 0;
protected:
	bool isGreyscale;
	bool isMonochrome;
	bool isNegative;
};

