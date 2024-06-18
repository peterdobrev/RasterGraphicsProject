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

	const Vector<uint8_t>& getData() const;

	PGMImage* clone() const override;
	PGMImage(String name);
	PGMImage(Vector<uint8_t> data, String name, unsigned width, unsigned height);

protected:
	void applyNegative() override;
	void applyMonochrome() override;
	void applyGreyscale() override;
	void applyRotation() override;

private:
	 Vector<uint8_t> data;
};

