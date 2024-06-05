#pragma once
#include "Image.h"
#include "Bitset.h"
#include "TransformableObject.h"
class PBMImage : public Image, TransformableObject
{
	// Interface of TransformableImage
	void makeNegative() override;
	void makeMonochrome() override;
	void makeGreyscale() override;
	// rotateLeft are inherited
	// rotateRight are inherited

protected:
	void applyRotation() override;

private:
	BitSet data;
};

