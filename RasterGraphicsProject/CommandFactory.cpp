#include "CommandFactory.h"
#include "MonochromeCommand.h"
#include "GreyscaleCommand.h"
#include "NegativeCommand.h"
#include "RotateCommand.h"
#include "AddCommand.h"
#include "CollageCommand.h"
#include "String.h"

PolymorphicPtr<Command> CommandFactory::createCommand(String commandType)
{
    if (commandType == "monochrome")
    {
        return createMonochromeCommand();
    }
    if (commandType == "greyscale")
    {
        return createGreyscaleCommand();
    }
    if (commandType == "negative")
    {
        return createNegativeCommand();
    }
    if (commandType == "rotate")
    {
        return createRotateCommand();
    }
    if (commandType == "add")
    {
        return createAddCommand();
    }
    if (commandType == "collage")
    {
        return createCollageCommand();
    }
}

PolymorphicPtr<Command> CommandFactory::createMonochromeCommand()
{
    MonochromeCommand* command = new MonochromeCommand();
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createGreyscaleCommand()
{
    GreyscaleCommand* command = new GreyscaleCommand();
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createNegativeCommand()
{
    NegativeCommand* command = new NegativeCommand();
    return PolymorphicPtr<Command>(command);
}

PolymorphicPtr<Command> CommandFactory::createRotateCommand()
{
    String direction;
    std::cin >> direction;

    if (direction == "left")
    {
        RotateCommand* command = new RotateCommand(RotateCommand::Direction::left);
        return PolymorphicPtr<Command>(command);
    }
    if (direction == "right")
    {
        RotateCommand* command = new RotateCommand(RotateCommand::Direction::right);
        return PolymorphicPtr<Command>(command);
    }

    return PolymorphicPtr<Command>();
}

PolymorphicPtr<Command> CommandFactory::createAddCommand()
{
    String fileName;
    std::cin >> fileName;
    AddCommand* command = new AddCommand(fileName);
}

PolymorphicPtr<Command> CommandFactory::createCollageCommand()
{
    String imageName1, imageName2, directionString;
    CollageCommand::Direction direction;

    std::cin >> directionString >> imageName1 >> imageName2;

    if (directionString == "horizontal")
    {
        direction = CollageCommand::Direction::horizontal;
    }
    else if(directionString == "vertical")
    {
        direction = CollageCommand::Direction::vertical;
    }

    CollageCommand* command = new CollageCommand(direction, imageName1, imageName2);

    return PolymorphicPtr<Command>(command);
}

