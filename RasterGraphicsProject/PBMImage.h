#pragma once
#include "Image.h"
#include "Bitset.h"
#include "TransformableImage.h"
class PBMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
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

};

