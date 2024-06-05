#pragma once

class TransformableImage
{
	virtual void makeGreyscale() = 0;
	virtual void makeMonochrome() = 0;
	virtual void makeNegative() = 0;
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;
};