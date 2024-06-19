#include "Session.h"
#include <iostream>
#include "Transformation.h"

int Session::getId() const
{
	return id;
}

void Session::execute()
{
	size_t length = transformations.getSize();
	for (size_t i = 0; i < length; i++)
	{
		transformations[i].get()->execute();
	}
}

void Session::printFeedback() const
{
	size_t imagesLength = images.getSize();
	size_t transformationsLength = transformations.getSize();

	std::cout << "Name of images in the session: ";
	for (size_t i = 0; i < imagesLength; i++)
	{
		std::cout << images[i]->getName() << " ";
	}
	std::cout << std::endl;
	std::cout << "Pending transformations: ";
	for (size_t i = 0; i < transformationsLength; i++)
	{
		transformations[i].get()->printInfo();
		
		if(i != transformationsLength - 1)
			std::cout << ", ";
	}
}

void Session::popBackImage()
{
	images.popBack();
}

void Session::popBackTransformation()
{
	transformations.popBack();
}

void Session::addImage(const PolymorphicPtr<TransformableImage>& image)
{
	images.pushBack(image);
}

void Session::addTransformation(const PolymorphicPtr<Transformation>& transformation)
{
	transformations.pushBack(transformation);
}

void Session::addImage(PolymorphicPtr<TransformableImage>&& image)
{
	images.pushBack(std::move(image));
}

void Session::addTransformation(PolymorphicPtr<Transformation>&& transformation)
{
	transformations.pushBack(std::move(transformation));
}

PolymorphicPtr<TransformableImage>& Session::getImageAtIndex(size_t index)
{
	return images[index];
}

const PolymorphicPtr<TransformableImage>& Session::getImageAtIndex(size_t index) const
{
	return images[index];
}

PolymorphicPtr<Transformation>& Session::getTransformationAtIndex(size_t index)
{
	return transformations[index];
}

const PolymorphicPtr<Transformation>& Session::getTransformationAtIndex(size_t index) const
{
	return transformations[index];
}

void Session::clearImages()
{
	images.clear();
}

void Session::clearTransformations()
{
	Vector<PolymorphicPtr<Transformation>> newTransformations;
	transformations = newTransformations;
}

size_t Session::getImagesCount() const
{
	return images.getSize();
}

size_t Session::getTransformationsCount() const
{
	return transformations.getSize();
}

Session::Session(Vector<PolymorphicPtr<TransformableImage>> images, Vector<PolymorphicPtr<Transformation>> transformations)
	: images(images), transformations(transformations) {}

Session::Session(int id) : id(id) {}