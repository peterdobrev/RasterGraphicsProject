#pragma once
#include "Image.h"
#include "TransformableImage.h"
#include "Vector.hpp"
#include "ColorModifiablePixel.h"

class PPMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
	void loadData() override;
	void saveData() override;
	void clearData() override;

	const Vector<ColorModifiablePixel>& getData() const;
	uint8_t getMaxNumber() const;

	PPMImage* clone() const override;
	PPMImage(String name);
	PPMImage(Vector<ColorModifiablePixel> data, String name, unsigned width, unsigned height);

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

