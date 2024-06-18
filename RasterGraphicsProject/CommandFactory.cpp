#include "CommandFactory.h"
#include "MonochromeCommand.h"
#include "GreyscaleCommand.h"
#include "NegativeCommand.h"
#include "RotateCommand.h"
#include "AddCommand.h"
#include "CollageCommand.h"
#include "String.h"
#include "SaveAsCommand.h"

PolymorphicPtr<Command> CommandFactory::createCommand(String commandType, Session* sessionPtr)
{
    if (commandType == "monochrome")
    {
        auto command = createMonochromeCommand(sessionPtr);
        return command;
    }
    if (commandType == "greyscale")
    {
        auto command = createGreyscaleCommand(sessionPtr);
        return command;
    }
    if (commandType == "negative")
    {
        auto command = createNegativeCommand(sessionPtr);
        return command;
    }
    if (commandType == "rotate")
    {
        auto command = createRotateCommand(sessionPtr);
        return command;
    }
    if (commandType == "add")
    {
        auto command = createAddCommand(sessionPtr);
        return command;
    }
    if (commandType == "collage")
    {
        auto command = createCollageCommand(sessionPtr);
        return command;
    }
    if (commandType == "save")
    {
        auto command = createSaveCommand(sessionPtr);
        return command;
    }
    if (commandType == "saveas")
    {
        auto command = createSaveAsCommand(sessionPtr);
        return command;
    }
}

PolymorphicPtr<Command> CommandFactory::createMonochromeCommand(Session* sessionPtr)
{
    MonochromeCommand* command = new MonochromeCommand(sessionPtr);
    sessionPtr->addTransformation(PolymorphicPtr<Transformation>(command));
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createGreyscaleCommand(Session* sessionPtr)
{
    GreyscaleCommand* command = new GreyscaleCommand(sessionPtr);
    sessionPtr->addTransformation(PolymorphicPtr<Transformation>(command));
    return PolymorphicPtr<Command>(command);;
}

PolymorphicPtr<Command> CommandFactory::createNegativeCommand(Session* sessionPtr)
{
    NegativeCommand* command = new NegativeCommand(sessionPtr);
    sessionPtr->addTransformation(PolymorphicPtr<Transformation>(command));
    return PolymorphicPtr<Command>(command);;
}

PolymorphicPtr<Command> CommandFactory::createRotateCommand(Session* sessionPtr)
{
    String direction;
    std::cin >> direction;

    RotateCommand* rotateCommand = nullptr;

    if (direction == "left")
    {
        rotateCommand = new RotateCommand(sessionPtr, RotateCommand::Direction::left);
    }
    if (direction == "right")
    {
        rotateCommand = new RotateCommand(sessionPtr, RotateCommand::Direction::right);
    }

    sessionPtr->addTransformation(PolymorphicPtr<Transformation>(rotateCommand));
    return PolymorphicPtr<Command>(rotateCommand);
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

