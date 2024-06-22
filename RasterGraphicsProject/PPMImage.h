#pragma once
#include "Image.h"
#include "TransformableImage.h"
#include "Vector.hpp"
#include "ColorModifiablePixel.h"

class PPMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
	// Inherited via LoadableObject
	void loadData() override;
	void saveData() override;
	void clearData() override;

	// Inherited via CollageVisitor
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWith(TransformableImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPBM(PBMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPGM(PGMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPPM(PPMImage* image, String collageName) override;

	virtual PolymorphicPtr<TransformableImage> collageVerticalWith(TransformableImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPBM(PBMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPGM(PGMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPPM(PPMImage* image, String collageName) override;

	const Vector<ColorModifiablePixel>& getData() const;
	uint8_t getMaxNumber() const;

	PPMImage* clone() const override;
	PPMImage(String name);
	PPMImage(Vector<ColorModifiablePixel> data, String name, unsigned width, unsigned height, uint8_t maxNumber);

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	uint8_t maxNumber = 0;
	Vector<ColorModifiablePixel> data;

	void rotate90Degrees();
	void rotate180Degrees();
	void rotate270Degrees();
};

