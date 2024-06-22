#pragma once
#include "Image.h"
#include "Bitset.h"
#include "TransformableImage.h"
class PBMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
	// Inherited via CollageVisitor
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWith(TransformableImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPBM(PBMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPGM(PGMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageHorizontalWithPPM(PPMImage* image, String collageName) override;

	virtual PolymorphicPtr<TransformableImage> collageVerticalWith(TransformableImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPBM(PBMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPGM(PGMImage* image, String collageName) override;
	virtual PolymorphicPtr<TransformableImage> collageVerticalWithPPM(PPMImage* image, String collageName) override;

	PBMImage(String name);
	PBMImage(BitSet data, String name, unsigned width, unsigned height);
	TransformableImage* clone() const override;
	
	const BitSet& getData() const;

protected:
	void loadData() override;
	void saveData() override;
	void clearData() override;

	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	BitSet data;

	void rotate90Degrees();
	void rotate180Degrees();
	void rotate270Degrees();

};

