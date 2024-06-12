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

	PGMImage* clone() const override;

	PGMImage(String name) : TransformableImage(name) {}

	PGMImage(Vector<uint8_t> data, String name, unsigned width, unsigned height)
		: TransformableImage(name, width, height), data(data) {}

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	 Vector<uint8_t> data;
};

