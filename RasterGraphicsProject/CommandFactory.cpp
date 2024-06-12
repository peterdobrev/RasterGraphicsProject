#include "CommandFactory.h"
#include "MonochromeCommand.h"
#include "GreyscaleCommand.h"
#include "NegativeCommand.h"
#include "RotateCommand.h"
#include "AddCommand.h"
#include "CollageCommand.h"
#include "String.h"

PolymorphicPtr<Command> CommandFactory::createCommand(String commandType, Session* sessionPtr)
{
    if (commandType == "monochrome")
    {
        return createMonochromeCommand(sessionPtr);
    }
    if (commandType == "greyscale")
    {
        return createGreyscaleCommand(sessionPtr);
    }
    if (commandType == "negative")
    {
        return createNegativeCommand(sessionPtr);
    }
    if (commandType == "rotate")
    {
        return createRotateCommand(sessionPtr);
    }
    if (commandType == "add")
    {
        return createAddCommand(sessionPtr);
    }
    if (commandType == "collage")
    {
        return createCollageCommand(sessionPtr);
    }
}

PolymorphicPtr<Command> CommandFactory::createMonochromeCommand(Session* sessionPtr)
{
    MonochromeCommand* command = new MonochromeCommand(sessionPtr);
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createGreyscaleCommand(Session* sessionPtr)
{
    GreyscaleCommand* command = new GreyscaleCommand(sessionPtr);
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createNegativeCommand(Session* sessionPtr)
{
    NegativeCommand* command = new NegativeCommand(sessionPtr);
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createRotateCommand(Session* sessionPtr)
{
    String direction;
    std::cin >> direction;

    if (direction == "left")
    {
        RotateCommand* command = new RotateCommand(sessionPtr, RotateCommand::Direction::left);
        return PolymorphicPtr<Command>(command);
    }
    if (direction == "right")
    {
        RotateCommand* command = new RotateCommand(sessionPtr, RotateCommand::Direction::right);
        return PolymorphicPtr<Command>(command);
    }

    return PolymorphicPtr<Command>();
}

PolymorphicPtr<Command> CommandFactory::createAddCommand(Session* sessionPtr)
{
    String fileName;
    std::cin >> fileName;
    AddCommand* addCommand = new AddCommand(sessionPtr, fileName);
    PolymorphicPtr<Command> command(addCommand);
    return command;
}

PolymorphicPtr<Command> CommandFactory::createCollageCommand(Session* sessionPtr)
{
    String imageName1, imageName2, outImageName, directionString;
    CollageCommand::Direction direction;

    std::cin >> directionString >> imageName1 >> imageName2 >> outImageName;

    if (directionString == "horizontal")
    {
        direction = CollageCommand::Direction::horizontal;
    }
    else if(directionString == "vertical")
    {
        direction = CollageCommand::Direction::vertical;
    }

    CollageCommand* command = new CollageCommand(sessionPtr, direction, imageName1, imageName2, outImageName);

    return PolymorphicPtr<Command>(command);
}

