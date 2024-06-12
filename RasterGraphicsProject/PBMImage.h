#pragma once
#include "Image.h"
#include "Bitset.h"
#include "TransformableImage.h"
class PBMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
	void loadData() override;
	void saveData() override;
	void clearData() override;
	
	PBMImage(String name) : TransformableImage(name) {}

	PBMImage(BitSet data, String name, unsigned width, unsigned height)
		: TransformableImage(name, width, height), data(data) {}

	TransformableImage* clone() const override;

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	BitSet data;

};

