#pragma once
#include <fstream>
#include "Command.h"
#include "PolymorphicPtr.hpp"
#include "String.h"
class CommandFactory
{
public:
	static PolymorphicPtr<Command> createCommand(String commandType);
private:
	static PolymorphicPtr<Command> createMonochromeCommand();
	static PolymorphicPtr<Command> createGreyscaleCommand();
	static PolymorphicPtr<Command> createNegativeCommand();
	static PolymorphicPtr<Command> createRotateCommand();
	static PolymorphicPtr<Command> createAddCommand();
	static PolymorphicPtr<Command> createCollageCommand();

};

