#pragma once
#include "Image.h"
#include "TransformableImage.h"
#include "Vector.hpp"
#include "Pixel.h"

class PPMImage : public TransformableImage
{
	friend class ImageDataLoader;

public:
	void loadData() override;
	void saveData() override;
	void clearData() override;

	const Vector<Pixel>& getData() const;

	PPMImage* clone() const override;
	PPMImage(String name);
	PPMImage(Vector<Pixel> data, String name, unsigned width, unsigned height);

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	Vector<Pixel> data;
};

