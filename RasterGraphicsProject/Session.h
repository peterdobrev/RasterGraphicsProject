#pragma once
#include "PolymorphicPtr.hpp"
#include "Vector.hpp"
#include "Image.h"
#include "Command.h"

class Session
{
	friend class Application;

public:
	void execute();
	void print() const;

private:
	size_t id;
	Vector<PolymorphicPtr<Image>> images;
	Vector<PolymorphicPtr<Command>> commands;
};

