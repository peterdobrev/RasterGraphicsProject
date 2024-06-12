#pragma once
#include "PolymorphicPtr.hpp"
#include "Vector.hpp"
#include "TransformableImage.h"

class Command;

class Session
{
	friend class Application;

	// Malko e izguzica mai
	friend class GreyscaleCommand;
	friend class NegativeCommand;
	friend class MonochromeCommand;
	friend class RotateCommand;
	friend class CollageCommand;
	friend class AddCommand;

public:
	void execute();
	void print() const;

private:
	size_t id = 0;
	Vector<PolymorphicPtr<TransformableImage>> images;
	Vector<PolymorphicPtr<Command>> commands;

	Session(Vector<PolymorphicPtr<TransformableImage>> images, Vector<PolymorphicPtr<Command>> commands);
};

