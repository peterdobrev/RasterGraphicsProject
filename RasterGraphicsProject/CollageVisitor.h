#pragma once
#include "PolymorphicPtr.hpp"
#include "String.h"


class TransformableImage;
class PBMImage;
class PGMImage;
class PPMImage;

class CollageVisitor
{
public:
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWith(TransformableImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPBM(PBMImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPGM(PGMImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPPM(PPMImage* image, String collageName) = 0;

	virtual PolymorphicPtr<TransformableImage> collageVerticalWith(TransformableImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPBM(PBMImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPGM(PGMImage* image, String collageName) = 0;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPPM(PPMImage* image, String collageName) = 0;

	virtual ~CollageVisitor() = default;
};

