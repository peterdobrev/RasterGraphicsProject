#include <iostream>
#include "Application.h"
#include "String.h"
#include "CommandFactory.h"

void Application::printSession() const
{
    activeSession->print();
}

void Application::addCommand(PolymorphicPtr<Command>& command)
{
    activeSession->commands.pushBack(command);
}

void Application::popBackCommand()
{
    activeSession->commands.popBack();
}

PolymorphicPtr<Command> Application::parseCommand()
{
    PolymorphicPtr<Command> command;

    String commandType;
    std::cin >> commandType;

    if (commandType == "undo")
    {
        popBackCommand();
    }
    else if (commandType == "session")// "session info"
    {
        printSession();
    }
    else if (commandType == "switch")
    {
        handleSwitchSession();
    }
    else
    {
        command = CommandFactory::createCommand(commandType);
    }

    return command;
}

void Application::readCommand()
{
    PolymorphicPtr<Command> command = parseCommand();
    if (command.get() != nullptr)
    {
        addCommand(command);
    }
}

const Session& Application::getSession() const
{
    return *activeSession;
}
