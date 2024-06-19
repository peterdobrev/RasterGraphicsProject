#include "CommandFactory.h"
#include "MonochromeCommand.h"
#include "GreyscaleCommand.h"
#include "NegativeCommand.h"
#include "RotateCommand.h"
#include "AddCommand.h"
#include "CollageCommand.h"
#include "String.h"
#include "SaveAsCommand.h"
#include "PrintCommand.h"

PolymorphicPtr<Command> CommandFactory::createCommand(String commandType, Session* sessionPtr)
{
    PolymorphicPtr<Command> command;
    if (commandType == "monochrome")
    {
        return createMonochromeCommand(sessionPtr);
    }
    else if (commandType == "greyscale")
    {
        return createGreyscaleCommand(sessionPtr);
    }
    else if (commandType == "negative")
    {
        return createNegativeCommand(sessionPtr);
    }
    else if (commandType == "rotate")
    {
        return createRotateCommand(sessionPtr);
    }
    else if (commandType == "add")
    {
        return createAddCommand(sessionPtr);
    }
    else if (commandType == "collage")
    {
        return createCollageCommand(sessionPtr);
    }
    else if (commandType == "save")
    {
        return createSaveCommand(sessionPtr);
    }
    else if (commandType == "saveas")
    {
        return createSaveAsCommand(sessionPtr);
    }
    else if (commandType == "print")
    {
        return createPrintCommand(sessionPtr);
    }

    return command;
}

PolymorphicPtr<Command> CommandFactory::createMonochromeCommand(Session* sessionPtr)
{
    MonochromeCommand* command = new MonochromeCommand(sessionPtr);
    PolymorphicPtr<Transformation> transformation(command->clone());
    sessionPtr->addTransformation(std::move(transformation));
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createGreyscaleCommand(Session* sessionPtr)
{
    GreyscaleCommand* command = new GreyscaleCommand(sessionPtr);
    PolymorphicPtr<Transformation> transformation(command->clone());
    sessionPtr->addTransformation(std::move(transformation));
    return PolymorphicPtr<Command>(command);;
}

PolymorphicPtr<Command> CommandFactory::createNegativeCommand(Session* sessionPtr)
{
    NegativeCommand* command = new NegativeCommand(sessionPtr);
    PolymorphicPtr<Transformation> transformation(command->clone());
    sessionPtr->addTransformation(std::move(transformation));
    return PolymorphicPtr<Command>(command);;
}

PolymorphicPtr<Command> CommandFactory::createRotateCommand(Session* sessionPtr)
{
    String direction;
    std::cin >> direction;

    RotateCommand* command = nullptr;

    if (direction == "left")
    {
        command = new RotateCommand(sessionPtr, RotateCommand::Direction::left);
    }
    else if (direction == "right")
    {
        command = new RotateCommand(sessionPtr, RotateCommand::Direction::right);
    }

    if (command)
    {
        PolymorphicPtr<Transformation> transformation(command->clone());
        sessionPtr->addTransformation(std::move(transformation));
    }

    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createAddCommand(Session* sessionPtr)
{
    String fileName;
    std::cin >> fileName;
    return new AddCommand(sessionPtr, fileName);
}

PolymorphicPtr<Command> CommandFactory::createCollageCommand(Session* sessionPtr)
{
    String imageName1, imageName2, outImageName, directionString;
    CollageCommand::Direction direction = CollageCommand::Direction::horizontal;

    std::cin >> directionString >> imageName1 >> imageName2 >> outImageName;

    if (directionString == "horizontal")
    {
        direction = CollageCommand::Direction::horizontal;
    }
    else if(directionString == "vertical")
    {
        direction = CollageCommand::Direction::vertical;
    }

    return new CollageCommand(sessionPtr, direction, imageName1, imageName2, outImageName);
}

PolymorphicPtr<Command> CommandFactory::createSaveCommand(Session* sessionPtr)
{
    SaveCommand* saveCommand = new SaveCommand(sessionPtr);
    return PolymorphicPtr<Command>(saveCommand);
}

PolymorphicPtr<Command> CommandFactory::createSaveAsCommand(Session* sessionPtr)
{
    String newName;
    std::cin >> newName;

    SaveAsCommand* saveCommand = new SaveAsCommand(sessionPtr, newName);
    return PolymorphicPtr<Command>(saveCommand);
}

PolymorphicPtr<Command> CommandFactory::createPrintCommand(Session* sessionPtr)
{
    PrintCommand* command = new PrintCommand(sessionPtr);
    return PolymorphicPtr<Command>(command);
}

