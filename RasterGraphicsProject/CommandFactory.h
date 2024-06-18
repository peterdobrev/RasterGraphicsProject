#pragma once
#include <fstream>
#include "Command.h"
#include "PolymorphicPtr.hpp"
#include "String.h"
class CommandFactory
{
public:
	static PolymorphicPtr<Command> createCommand(String commandType, Session* sessionPtr);
private:
	static PolymorphicPtr<Command> createMonochromeCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createGreyscaleCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createNegativeCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createRotateCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createAddCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createCollageCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createSaveCommand(Session* sessionPtr);
	static PolymorphicPtr<Command> createSaveAsCommand(Session* sessionPtr);

};

