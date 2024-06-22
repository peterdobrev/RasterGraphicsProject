#pragma once
#include "Vector.hpp"
#include "Image.h"
#include "TransformableImage.h"

class PGMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
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

	const Vector<uint8_t>& getData() const;
	uint8_t getMaxNumber() const;

	PGMImage* clone() const override;
	PGMImage(String name);
	PGMImage(Vector<uint8_t> data, String name, unsigned width, unsigned height, uint8_t maxNumber);

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	uint8_t maxNumber = UINT8_MAX;
	Vector<uint8_t> data;

	void rotate90Degrees();
	void rotate180Degrees();
	void rotate270Degrees();
};

