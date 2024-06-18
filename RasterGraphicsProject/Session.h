#pragma once
#include "PolymorphicPtr.hpp"
#include "Vector.hpp"
#include "TransformableImage.h"

class Transformation;

class Session
{
public:
	int getId() const;

	void execute();
	void print() const;

	void popBackImage();
	void popBackTransformation();

	void addImage(const PolymorphicPtr<TransformableImage>& image);
	void addTransformation(const PolymorphicPtr<Transformation>& transformation);

	void addImage(PolymorphicPtr<TransformableImage>&& image);
	void addTransformation(PolymorphicPtr<Transformation>&& transformation);

	PolymorphicPtr<TransformableImage>& getImageAtIndex(size_t index);
	const PolymorphicPtr<TransformableImage>& getImageAtIndex(size_t index) const;

	PolymorphicPtr<Transformation>& getTransformationAtIndex(size_t index);
	const PolymorphicPtr<Transformation>& getTransformationAtIndex(size_t index) const;

	void clearImages();
	void clearTransformations();

	size_t getImagesCount() const;
	size_t getTransformationsCount() const;

	Session(int id);

	Session(Vector<PolymorphicPtr<TransformableImage>> images, Vector<PolymorphicPtr<Transformation>> transformations);
	
private:
	int id = 0;
	Vector<PolymorphicPtr<TransformableImage>> images;
	Vector<PolymorphicPtr<Transformation>> transformations;
};

